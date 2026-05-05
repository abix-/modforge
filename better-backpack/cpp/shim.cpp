// UE4SS C++ mod entry point. The minimum amount of C++ to satisfy
// UE4SS's CppUserModBase contract while keeping every byte of mod
// logic in Rust.
//
// Why we don't include UE4SS's actual headers:
//
// UE4SS's CppUserModBase.hpp transitively includes GUI/GUITab.hpp ->
// GUI/GUI.hpp -> imgui.h, plus several other deps that only resolve
// when you've fully built UE4SS. We don't want a full UE4SS build
// dependency just to inherit from one class.
//
// Instead we write our own mirror of CppUserModBase here. The layout
// must match UE4SS's exactly (verified against
// `C:\code\RE-UE4SS\UE4SS\include\Mod\CppUserModBase.hpp`):
//
//   protected: std::vector<std::shared_ptr<GUI::GUITab>> GUITabs;
//   public:    StringType ModName, ModVersion, ModDescription,
//              ModAuthors, ModIntendedSDKVersion;
//   public:    constructor + virtual destructor + 15 virtual methods,
//              in the exact declaration order from CppUserModBase.hpp
//              (including 4 deprecated overloads + on_cpp_mods_loaded).
//
// We use the same MSVC + same release CRT as UE4SS itself ships, so
// std::vector / std::shared_ptr / std::wstring are layout-compatible
// across the boundary. The constructor and virtual destructor are
// marked dllimport: they resolve from UE4SS.lib (generated from the
// installed UE4SS.dll) at our link time.
//
// History: an earlier version of this mirror had only 9 virtuals
// (missing on_ui_init, four post-1.0 on_lua_*(Lua*) overloads, and
// on_cpp_mods_loaded). The data layout was correct, but UE4SS would
// dispatch through the missing slots during init and jump past our
// vtable, crashing the game. The light file logging in start_mod()
// is a remnant of that investigation; cheap and useful when porting
// to a future UE4SS version, so kept.

#include <Windows.h>
#include <cstdio>
#include <exception>
#include <memory>
#include <string>
#include <vector>

#define RC_UE4SS_API __declspec(dllimport)

namespace RC {

namespace GUI { class GUITab; }
namespace LuaMadeSimple { class Lua; }

using CharType = wchar_t;
using StringType = std::basic_string<CharType>;
using StringViewType = std::basic_string_view<CharType>;
#define STR(s) L##s

class CppUserModBase {
  protected:
    std::vector<std::shared_ptr<GUI::GUITab>> GUITabs{};

  public:
    StringType ModName{};
    StringType ModVersion{};
    StringType ModDescription{};
    StringType ModAuthors{};
    StringType ModIntendedSDKVersion{};

  public:
    RC_UE4SS_API CppUserModBase();
    RC_UE4SS_API virtual ~CppUserModBase();

  public:
    // ORDER MATTERS. Must match RE-UE4SS/UE4SS/include/Mod/CppUserModBase.hpp
    // exactly, including all deprecated overloads and the trailing post-1.0
    // additions, otherwise UE4SS will dispatch to the wrong slot or jump
    // past the vtable.
    RC_UE4SS_API virtual auto on_update() -> void {}
    RC_UE4SS_API virtual auto on_unreal_init() -> void {}
    RC_UE4SS_API virtual auto on_ui_init() -> void {}
    RC_UE4SS_API virtual auto on_program_start() -> void {}
    RC_UE4SS_API virtual auto on_lua_start(StringViewType,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            std::vector<LuaMadeSimple::Lua*>&) -> void {}
    RC_UE4SS_API virtual auto on_lua_start(LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            std::vector<LuaMadeSimple::Lua*>&) -> void {}
    RC_UE4SS_API virtual auto on_lua_stop(StringViewType,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           std::vector<LuaMadeSimple::Lua*>&) -> void {}
    RC_UE4SS_API virtual auto on_lua_stop(LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           std::vector<LuaMadeSimple::Lua*>&) -> void {}
    RC_UE4SS_API virtual auto on_dll_load(StringViewType dll_name) -> void {}
    RC_UE4SS_API virtual auto render_tab() -> void {}
    RC_UE4SS_API virtual auto on_lua_start(StringViewType,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua*) -> void {}
    RC_UE4SS_API virtual auto on_lua_start(LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua&,
                                            LuaMadeSimple::Lua*) -> void {}
    RC_UE4SS_API virtual auto on_lua_stop(StringViewType,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua*) -> void {}
    RC_UE4SS_API virtual auto on_lua_stop(LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua&,
                                           LuaMadeSimple::Lua*) -> void {}
    // Not dllimport: UE4SS.lib doesn't export this symbol (newer addition,
    // possibly only inlined in the public header). Use our local inline body.
    virtual auto on_cpp_mods_loaded() -> void {}
};

} // namespace RC

// ---------------------------------------------------------------------
// Debug logging. Writes to <module-dir>/cpp_shim.log so we can see what
// the C++ side did before the Rust side gets a chance to log anything.
// Cheap, fopen-fclose-per-line, line-buffered. Heavy use during the
// load-crash investigation; can be quieted later.
// ---------------------------------------------------------------------

static HMODULE g_self_module = nullptr;

static void shim_log(const char* msg) {
    OutputDebugStringA("[bbp shim] ");
    OutputDebugStringA(msg);
    OutputDebugStringA("\r\n");

    wchar_t module_path[MAX_PATH];
    DWORD n = GetModuleFileNameW(g_self_module, module_path, MAX_PATH);
    if (n == 0 || n >= MAX_PATH) return;
    // Strip filename to get directory.
    for (DWORD i = n; i > 0; --i) {
        if (module_path[i - 1] == L'\\' || module_path[i - 1] == L'/') {
            module_path[i] = 0;
            break;
        }
    }
    wchar_t log_path[MAX_PATH];
    swprintf_s(log_path, MAX_PATH, L"%scpp_shim.log", module_path);

    FILE* f = nullptr;
    if (_wfopen_s(&f, log_path, L"a") == 0 && f) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        fprintf(f, "[%02d:%02d:%02d.%03d] %s\n",
                st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, msg);
        fclose(f);
    }
}

static void shim_logf(const char* fmt, ...) {
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    shim_log(buf);
}

// Resolve our own HMODULE from any code address inside the DLL.
// Called lazily on first log so we don't fight rustc for DllMain.
static void ensure_module_handle() {
    if (g_self_module) return;
    GetModuleHandleExW(
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCWSTR)&ensure_module_handle,
        &g_self_module);
}

// ---------------------------------------------------------------------
// Rust entry points. Implemented in better-backpack/src/lib.rs.
// ---------------------------------------------------------------------

extern "C" void better_backpack_start();
extern "C" void better_backpack_stop();

class BetterBackpackMod : public RC::CppUserModBase {
  public:
    BetterBackpackMod() {
        ModName = STR("BetterBackpack");
        ModVersion = STR("0.1.0");
        ModDescription = STR("Bigger backpack + survival rate tweaks");
        ModAuthors = STR("abix");
    }

    auto on_unreal_init() -> void override {
        shim_log("on_unreal_init: calling better_backpack_start()");
        better_backpack_start();
        shim_log("on_unreal_init: better_backpack_start() returned");
    }

    ~BetterBackpackMod() override {
        shim_log("~BetterBackpackMod: calling better_backpack_stop()");
        better_backpack_stop();
    }
};

extern "C" __declspec(dllexport) RC::CppUserModBase* start_mod() {
    ensure_module_handle();
    shim_log("start_mod: enter");
    shim_logf("start_mod: sizeof(RC::CppUserModBase) = %zu",
              sizeof(RC::CppUserModBase));
    shim_logf("start_mod: sizeof(BetterBackpackMod) = %zu",
              sizeof(BetterBackpackMod));
    try {
        BetterBackpackMod* m = new BetterBackpackMod();
        shim_logf("start_mod: returning instance %p", (void*)m);
        return m;
    } catch (const std::exception& e) {
        shim_logf("start_mod: caught std::exception: %s", e.what());
        return nullptr;
    } catch (...) {
        shim_log("start_mod: caught unknown exception");
        return nullptr;
    }
}

extern "C" __declspec(dllexport) void uninstall_mod(RC::CppUserModBase* mod) {
    shim_logf("uninstall_mod: deleting %p", (void*)mod);
    delete mod;
    shim_log("uninstall_mod: done");
}
