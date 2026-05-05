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
//   public:    constructor + virtual destructor + 14 other virtuals.
//
// We use the same MSVC + same release CRT as UE4SS itself ships, so
// std::vector / std::shared_ptr / std::wstring are layout-compatible
// across the boundary. The constructor and virtual destructor are
// marked dllimport: they resolve from UE4SS.lib (generated from the
// installed UE4SS.dll) at our link time.

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
    RC_UE4SS_API virtual auto on_update() -> void {}
    RC_UE4SS_API virtual auto on_unreal_init() -> void {}
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
    RC_UE4SS_API virtual auto on_dll_load(std::wstring_view dll_name) -> void {}
    RC_UE4SS_API virtual auto render_tab() -> void {}
};

} // namespace RC

// Rust entry points. Implemented in better-backpack/src/lib.rs.
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
        better_backpack_start();
    }

    ~BetterBackpackMod() override {
        better_backpack_stop();
    }
};

extern "C" __declspec(dllexport) RC::CppUserModBase* start_mod() {
    return new BetterBackpackMod();
}

extern "C" __declspec(dllexport) void uninstall_mod(RC::CppUserModBase* mod) {
    delete mod;
}
