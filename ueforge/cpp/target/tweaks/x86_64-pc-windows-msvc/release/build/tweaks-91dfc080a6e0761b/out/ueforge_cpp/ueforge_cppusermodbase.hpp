// ueforge_cppusermodbase.hpp
//
// Vendored mirror of UE4SS's `RC::CppUserModBase` class. Every UE4SS
// C++ mod inherits from this. We mirror it instead of including
// UE4SS's own header because that header transitively includes a
// large portion of UE4SS's GUI / Lua plumbing that only resolves
// when you've fully built UE4SS.
//
// The layout MUST match exactly. In particular:
//   - The vtable order is the order virtuals are declared.
//   - The `GUITabs` member is `protected` and the constructor /
//     destructor are `RC_UE4SS_API` (dllimport — they resolve from
//     UE4SS.lib at link time).
//   - All 19 virtuals are present, including the 4 deprecated
//     `on_lua_start`/`on_lua_stop` overloads taking a `Lua*` and
//     `on_cpp_mods_loaded` (which is NOT dllimport — it's only
//     inlined in newer headers, so we provide a local empty body).
//
// Verified against
// `RE-UE4SS/UE4SS/include/Mod/CppUserModBase.hpp` (UE4SS v3.0.1).
//
// Earlier versions of this mirror missing slots crashed the host
// because UE4SS dispatched through unmapped vtable indices.
//
// Usage in a game's shim.cpp:
//
//   #include "ueforge_cppusermodbase.hpp"
//
//   class MyMod : public RC::CppUserModBase {
//     public:
//       MyMod() : CppUserModBase() {
//           ModName        = STR("MyMod");
//           ModVersion     = STR("1.0");
//           // ...
//       }
//       auto on_unreal_init() -> void override {
//           extern "C" void mymod_start();
//           mymod_start();
//       }
//   };

#pragma once

#include <memory>
#include <string>
#include <string_view>
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
    // Not dllimport: UE4SS.lib doesn't export this symbol (newer
    // addition, possibly only inlined in the public header). Use a
    // local inline body.
    virtual auto on_cpp_mods_loaded() -> void {}

  protected:
    // Adds an ImGui tab to UE4SS's debug overlay, owned by this mod.
    // Tab is auto-cleaned up on mod destruct. Symbol mangling
    // depends on access specifier — must stay protected to match
    // the real UE4SS header (CppUserModBase.hpp:212).
    using RenderFunctionType = void (*)(CppUserModBase*);
    RC_UE4SS_API auto register_tab(StringViewType tab_name,
                                    RenderFunctionType render) -> void;
};

} // namespace RC

// UE4SS's ImGui context bridge lives in ueforge_imgui_bridge.hpp
// (requires imgui.h to be included first).
