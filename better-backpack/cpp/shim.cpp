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

// Vendored ImGui (better-backpack/cpp/imgui/) at the same v1.92.1 UE4SS
// uses. Included before the UE4SS forward decls because some of those
// reference ImGuiContext / ImGuiMemAllocFunc.
#include "imgui.h"

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

  protected:
    // Adds an ImGui tab to UE4SS's debug overlay, owned by this mod.
    // Tab is auto-cleaned up on mod destruct. Symbol mangling depends
    // on access specifier so this MUST stay protected to match the
    // real UE4SS header (CppUserModBase.hpp:212).
    using RenderFunctionType = void (*)(CppUserModBase*);
    RC_UE4SS_API auto register_tab(StringViewType tab_name,
                                    RenderFunctionType render) -> void;
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

// FFI surface from rpg/ffi.rs. C-friendly accessors for the ImGui tab.
extern "C" int      bbp_rpg_has_active_slot();
extern "C" uint32_t bbp_rpg_get_level();
extern "C" uint64_t bbp_rpg_get_xp();
extern "C" uint64_t bbp_rpg_get_xp_for_current_level();
extern "C" uint64_t bbp_rpg_get_xp_for_next_level();
extern "C" uint32_t bbp_rpg_get_skill_points();
extern "C" uint32_t bbp_rpg_get_skill_count();
extern "C" int      bbp_rpg_get_skill(uint32_t index,
                                       char*    id_buf,
                                       size_t   id_buf_len,
                                       char*    name_buf,
                                       size_t   name_buf_len,
                                       uint32_t* out_level,
                                       uint32_t* out_max);
extern "C" int      bbp_rpg_spend(const char* skill_id);
extern "C" int      bbp_rpg_debug_grant_skill_points(uint32_t count);
extern "C" int      bbp_rpg_format_skill_effect(const char* skill_id,
                                                  uint32_t    level,
                                                  char*       out_buf,
                                                  size_t      out_buf_len);

// ---------------------------------------------------------------------
// UE4SS ImGui glue.
//
// UE4SS exposes its current ImGui context + allocator through two
// static methods on UE4SSProgram. They're declared inline in the
// header but exported via RC_UE4SS_API (dllimport here resolves to
// UE4SS.lib). When called from our TU the linker routes to UE4SS.dll's
// copy, which queries UE4SS's own ImGui state and returns it. We then
// point our locally-linked ImGui at that context, and drawing into it
// from our render lambda lands in UE4SS's ImGui draw list as expected.
//
// We skip the spinwait piece of the official UE4SS_ENABLE_IMGUI macro:
// our render lambda is called by UE4SS from its render thread when our
// tab is being drawn, so a context is guaranteed to exist.
// ---------------------------------------------------------------------

namespace RC {
class UE4SSProgram {
  public:
    RC_UE4SS_API static auto get_current_imgui_context() -> ImGuiContext*;
    RC_UE4SS_API static auto get_current_imgui_allocator_functions(
        ImGuiMemAllocFunc* alloc_func,
        ImGuiMemFreeFunc*  free_func,
        void**             user_data) -> void;
};
} // namespace RC

static void rpg_enable_imgui() {
    ImGui::SetCurrentContext(RC::UE4SSProgram::get_current_imgui_context());
    ImGuiMemAllocFunc alloc_func{};
    ImGuiMemFreeFunc  free_func{};
    void* user_data{};
    RC::UE4SSProgram::get_current_imgui_allocator_functions(
        &alloc_func, &free_func, &user_data);
    ImGui::SetAllocatorFunctions(alloc_func, free_func, user_data);
}

// ---------------------------------------------------------------------
// RPG render lambda. Called by UE4SS each frame the RPG tab is open.
// Reads PlayerState through the FFI surface, renders rows of skills
// with a +1 button each, and a header showing level / XP progress.
// ---------------------------------------------------------------------

static void rpg_render_tab(RC::CppUserModBase* /* mod */) {
    rpg_enable_imgui();

    if (!bbp_rpg_has_active_slot()) {
        ImGui::TextUnformatted("No save loaded.");
        ImGui::TextDisabled("Pick a save from the main menu to begin.");
        return;
    }

    uint32_t level         = bbp_rpg_get_level();
    uint64_t xp            = bbp_rpg_get_xp();
    uint64_t xp_cur_level  = bbp_rpg_get_xp_for_current_level();
    uint64_t xp_next_level = bbp_rpg_get_xp_for_next_level();
    uint32_t skill_points  = bbp_rpg_get_skill_points();

    ImGui::Text("Level %u", static_cast<unsigned>(level));
    if (xp_next_level > xp_cur_level) {
        uint64_t span      = xp_next_level - xp_cur_level;
        uint64_t into_band = (xp >= xp_cur_level) ? (xp - xp_cur_level) : 0;
        float progress     = (span > 0)
                             ? static_cast<float>(into_band) / static_cast<float>(span)
                             : 1.0f;
        char overlay[64];
        snprintf(overlay, sizeof(overlay),
                 "%llu / %llu XP",
                 static_cast<unsigned long long>(xp),
                 static_cast<unsigned long long>(xp_next_level));
        ImGui::ProgressBar(progress, ImVec2(-1.0f, 0.0f), overlay);
    } else {
        ImGui::Text("Max level (%llu XP)",
                    static_cast<unsigned long long>(xp));
    }

    ImGui::Text("Unspent skill points: %u",
                static_cast<unsigned>(skill_points));
    ImGui::Separator();

    uint32_t count = bbp_rpg_get_skill_count();
    for (uint32_t i = 0; i < count; ++i) {
        char     id[32];
        char     name[64];
        uint32_t level = 0;
        uint32_t max  = 0;
        if (!bbp_rpg_get_skill(i, id, sizeof(id),
                                  name, sizeof(name),
                                  &level, &max)) {
            continue;
        }

        ImGui::PushID(static_cast<int>(i));

        // Current effect (always shown).
        char cur_effect[96];
        cur_effect[0] = 0;
        bbp_rpg_format_skill_effect(id, level, cur_effect, sizeof(cur_effect));

        // Preview of NEXT level, only when we can actually spend.
        bool can_spend = (skill_points > 0) && (level < max);
        char next_effect[96];
        next_effect[0] = 0;
        if (level < max) {
            bbp_rpg_format_skill_effect(id, level + 1, next_effect, sizeof(next_effect));
        }

        if (level == 0) {
            ImGui::Text("%-20s level 0 / %u  (next: %s)",
                        name,
                        static_cast<unsigned>(max),
                        next_effect);
        } else if (level >= max) {
            ImGui::Text("%-20s level %u / %u  MAX  %s",
                        name,
                        static_cast<unsigned>(level),
                        static_cast<unsigned>(max),
                        cur_effect);
        } else {
            ImGui::Text("%-20s level %u / %u  %s  (next: %s)",
                        name,
                        static_cast<unsigned>(level),
                        static_cast<unsigned>(max),
                        cur_effect,
                        next_effect);
        }
        ImGui::SameLine();

        ImGui::BeginDisabled(!can_spend);
        if (ImGui::Button("+1")) {
            bbp_rpg_spend(id);
        }
        ImGui::EndDisabled();
        ImGui::PopID();
    }

    // ---- Debug controls (testing-only) -----------------------------
    ImGui::Separator();
    ImGui::TextDisabled("Debug (testing only)");
    if (ImGui::Button("+5 skill points")) {
        bbp_rpg_debug_grant_skill_points(5);
    }
    ImGui::SameLine();
    if (ImGui::Button("+50 skill points")) {
        bbp_rpg_debug_grant_skill_points(50);
    }
}

class BetterBackpackMod : public RC::CppUserModBase {
  public:
    BetterBackpackMod() {
        ModName = STR("BetterBackpack");
        ModVersion = STR("0.1.0");
        ModDescription = STR("Bigger backpack + survival rate tweaks");
        ModAuthors = STR("abix");

        // Register the RPG ImGui tab. Lambda runs on UE4SS's render
        // thread when the tab is open. Auto-cleaned up when this mod
        // is destructed.
        register_tab(STR("RPG"), &rpg_render_tab);
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
