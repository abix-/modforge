// modforge_ui_native.cpp
//
// Phase A standalone-window ImGui backend for native-PE mods.
//
// Owns its own top-level Win32 window + D3D11 device + ImGui context,
// driven by a background render thread spawned inside the injected
// DLL. The host game knows nothing about this window; it lives beside
// the game window and is alt-tabbable.
//
// Surface exported to Rust:
//   modforge_native_ui_spawn(title, title_len)      -> bool
//   modforge_native_ui_shutdown()                   -> void
//   modforge_native_ui_is_visible()                 -> bool
//   modforge_native_ui_register_tabs(tabs, count)   -> void  (TabDef abi)
//   modforge_native_ui_frame_count()                -> uint64_t
//
// Plus the modforge_ui_* ImGui-primitive exports that mirror the
// ueforge_ui_* shapes one-for-one. Those are only valid during a
// tab `render_fn` callback running on the render thread.
//
// Threading: spawn() creates the render thread which owns the window
// + device. All ImGui calls happen on that thread inside the render
// loop. Spawn / shutdown synchronize via a Win32 event so callers
// see deterministic post-conditions.

#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <tchar.h>

#include <atomic>
#include <cstdint>
#include <mutex>
#include <thread>

#include "imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_dx11.h"

extern IMGUI_IMPL_API LRESULT
ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace {

constexpr wchar_t kWindowClass[] = L"ModforgeNativeImGuiWnd";

struct TabAbi {
    const char* name_ptr;
    size_t      name_len;
    void (*render_fn)();
};

struct State {
    std::atomic<bool> running{false};
    std::atomic<bool> visible{false};
    std::atomic<uint64_t> frames{0};
    std::thread thread;
    HWND hwnd{nullptr};
    ID3D11Device* device{nullptr};
    ID3D11DeviceContext* ctx{nullptr};
    IDXGISwapChain* swap{nullptr};
    ID3D11RenderTargetView* rtv{nullptr};
    HANDLE ready_event{nullptr};
    HANDLE quit_event{nullptr};

    // Tabs registered from Rust. Pointer ownership stays with Rust;
    // we treat the slice as borrowed and only read it on the render
    // thread.
    std::mutex tabs_mu;
    const TabAbi* tabs{nullptr};
    size_t tabs_len{0};
};

State g_state;

// Wraps a render-fn call in SEH. Lives in its own function because
// MSVC forbids __try inside any function that has C++ unwinding
// (destructors / catch / try-blocks). This function has none.
static void call_render_safe(void (*fn)()) {
    if (!fn) return;
    __try {
        fn();
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        // Swallow render-fn crashes; the game must not die because
        // a tab callback panicked.
    }
}

bool create_device(HWND hwnd) {
    DXGI_SWAP_CHAIN_DESC sd{};
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hwnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT flags = 0;
    D3D_FEATURE_LEVEL fl;
    const D3D_FEATURE_LEVEL levels[] = {D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0};
    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, levels, 2,
        D3D11_SDK_VERSION, &sd, &g_state.swap, &g_state.device, &fl, &g_state.ctx);
    if (FAILED(hr)) return false;

    ID3D11Texture2D* back = nullptr;
    if (FAILED(g_state.swap->GetBuffer(0, IID_PPV_ARGS(&back)))) return false;
    g_state.device->CreateRenderTargetView(back, nullptr, &g_state.rtv);
    back->Release();
    return true;
}

void destroy_device() {
    if (g_state.rtv)    { g_state.rtv->Release();    g_state.rtv    = nullptr; }
    if (g_state.swap)   { g_state.swap->Release();   g_state.swap   = nullptr; }
    if (g_state.ctx)    { g_state.ctx->Release();    g_state.ctx    = nullptr; }
    if (g_state.device) { g_state.device->Release(); g_state.device = nullptr; }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM w, LPARAM l) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, w, l)) return 1;
    switch (msg) {
        case WM_CLOSE:
            // User closed our window. Hide it; the host's
            // modforge_native_ui_shutdown() is the canonical
            // teardown path. Don't tear down here on the wrong thread.
            ShowWindow(hWnd, SW_HIDE);
            g_state.visible.store(false);
            return 0;
        case WM_DESTROY:
            return 0;
    }
    return DefWindowProcW(hWnd, msg, w, l);
}

void render_loop(std::wstring title) {
    WNDCLASSEXW wc{};
    wc.cbSize = sizeof(wc);
    wc.style = CS_CLASSDC;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = kWindowClass;
    RegisterClassExW(&wc);

    g_state.hwnd = CreateWindowExW(
        0, kWindowClass, title.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr, nullptr, wc.hInstance, nullptr);
    if (!g_state.hwnd) {
        UnregisterClassW(kWindowClass, wc.hInstance);
        SetEvent(g_state.ready_event);
        g_state.running.store(false);
        return;
    }

    if (!create_device(g_state.hwnd)) {
        DestroyWindow(g_state.hwnd);
        UnregisterClassW(kWindowClass, wc.hInstance);
        SetEvent(g_state.ready_event);
        g_state.running.store(false);
        return;
    }

    ShowWindow(g_state.hwnd, SW_SHOWNORMAL);
    UpdateWindow(g_state.hwnd);
    g_state.visible.store(true);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ImGui::StyleColorsDark();
    ImGui_ImplWin32_Init(g_state.hwnd);
    ImGui_ImplDX11_Init(g_state.device, g_state.ctx);

    SetEvent(g_state.ready_event);

    while (g_state.running.load()) {
        if (WaitForSingleObject(g_state.quit_event, 0) == WAIT_OBJECT_0) break;

        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT) g_state.running.store(false);
        }
        if (!g_state.running.load()) break;

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        const TabAbi* tabs;
        size_t tabs_len;
        {
            std::lock_guard<std::mutex> lk(g_state.tabs_mu);
            tabs = g_state.tabs;
            tabs_len = g_state.tabs_len;
        }

        if (ImGui::Begin("modforge", nullptr)) {
            if (tabs_len == 0) {
                ImGui::TextDisabled("(no tabs registered)");
            } else if (ImGui::BeginTabBar("##modforge-tabs")) {
                for (size_t i = 0; i < tabs_len; ++i) {
                    char name_buf[128];
                    size_t n = tabs[i].name_len;
                    if (n >= sizeof(name_buf)) n = sizeof(name_buf) - 1;
                    memcpy(name_buf, tabs[i].name_ptr, n);
                    name_buf[n] = '\0';
                    if (ImGui::BeginTabItem(name_buf)) {
                        call_render_safe(tabs[i].render_fn);
                        ImGui::EndTabItem();
                    }
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::End();

        ImGui::Render();
        const float clear[4] = {0.08f, 0.08f, 0.09f, 1.0f};
        g_state.ctx->OMSetRenderTargets(1, &g_state.rtv, nullptr);
        g_state.ctx->ClearRenderTargetView(g_state.rtv, clear);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        g_state.swap->Present(1, 0);
        g_state.frames.fetch_add(1, std::memory_order_relaxed);
    }

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    destroy_device();
    if (g_state.hwnd) { DestroyWindow(g_state.hwnd); g_state.hwnd = nullptr; }
    UnregisterClassW(kWindowClass, wc.hInstance);
    g_state.visible.store(false);
}

} // namespace

extern "C" {

__declspec(dllexport) bool
modforge_native_ui_spawn(const char* title_ptr, size_t title_len) {
    bool expected = false;
    if (!g_state.running.compare_exchange_strong(expected, true)) {
        // Already running: idempotent success.
        return true;
    }
    g_state.ready_event = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    g_state.quit_event  = CreateEventW(nullptr, TRUE, FALSE, nullptr);

    std::wstring title;
    if (title_ptr && title_len) {
        int wlen = MultiByteToWideChar(CP_UTF8, 0, title_ptr,
                                       (int)title_len, nullptr, 0);
        title.resize((size_t)wlen);
        MultiByteToWideChar(CP_UTF8, 0, title_ptr, (int)title_len,
                            title.data(), wlen);
    } else {
        title = L"modforge";
    }

    g_state.thread = std::thread(render_loop, std::move(title));
    WaitForSingleObject(g_state.ready_event, 5000);
    return g_state.hwnd != nullptr;
}

__declspec(dllexport) void
modforge_native_ui_shutdown() {
    if (!g_state.running.load()) return;
    g_state.running.store(false);
    if (g_state.quit_event) SetEvent(g_state.quit_event);
    if (g_state.hwnd) PostMessageW(g_state.hwnd, WM_NULL, 0, 0);
    if (g_state.thread.joinable()) g_state.thread.join();
    if (g_state.ready_event) { CloseHandle(g_state.ready_event); g_state.ready_event = nullptr; }
    if (g_state.quit_event)  { CloseHandle(g_state.quit_event);  g_state.quit_event  = nullptr; }
}

__declspec(dllexport) bool
modforge_native_ui_is_visible() {
    if (!g_state.visible.load()) return false;
    HWND found = FindWindowW(kWindowClass, nullptr);
    return found != nullptr;
}

__declspec(dllexport) void
modforge_native_ui_register_tabs(const TabAbi* tabs, size_t count) {
    std::lock_guard<std::mutex> lk(g_state.tabs_mu);
    g_state.tabs = tabs;
    g_state.tabs_len = count;
}

__declspec(dllexport) uint64_t
modforge_native_ui_frame_count() {
    return g_state.frames.load(std::memory_order_relaxed);
}

// ===== ImGui primitive wrappers (mirror ueforge_ui_*) =====
//
// Valid only during a tab render_fn callback. ImGui state is owned
// by the render thread.

__declspec(dllexport) void modforge_ui_text(const char* s, size_t n) {
    ImGui::TextUnformatted(s, s + n);
}
__declspec(dllexport) void modforge_ui_text_disabled(const char* s, size_t n) {
    ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
    ImGui::TextUnformatted(s, s + n);
    ImGui::PopStyleColor();
}
__declspec(dllexport) bool modforge_ui_button(const char* s, size_t n, float w, float h) {
    char buf[256]; size_t k = n < sizeof(buf)-1 ? n : sizeof(buf)-1;
    memcpy(buf, s, k); buf[k] = '\0';
    return ImGui::Button(buf, ImVec2(w, h));
}
__declspec(dllexport) bool modforge_ui_checkbox(const char* s, size_t n, bool* v) {
    char buf[256]; size_t k = n < sizeof(buf)-1 ? n : sizeof(buf)-1;
    memcpy(buf, s, k); buf[k] = '\0';
    return ImGui::Checkbox(buf, v);
}
__declspec(dllexport) bool modforge_ui_slider_float(const char* s, size_t n, float* v, float lo, float hi) {
    char buf[256]; size_t k = n < sizeof(buf)-1 ? n : sizeof(buf)-1;
    memcpy(buf, s, k); buf[k] = '\0';
    return ImGui::SliderFloat(buf, v, lo, hi);
}
__declspec(dllexport) bool modforge_ui_slider_int(const char* s, size_t n, int* v, int lo, int hi) {
    char buf[256]; size_t k = n < sizeof(buf)-1 ? n : sizeof(buf)-1;
    memcpy(buf, s, k); buf[k] = '\0';
    return ImGui::SliderInt(buf, v, lo, hi);
}
__declspec(dllexport) void modforge_ui_separator() { ImGui::Separator(); }
__declspec(dllexport) void modforge_ui_spacing()   { ImGui::Spacing(); }
__declspec(dllexport) void modforge_ui_same_line(float x) { ImGui::SameLine(x); }

} // extern "C"
