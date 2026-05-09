// uespy_imgui_bridge.hpp
//
// UE4SS's ImGui context bridge. Forward-decls the two static
// `RC::UE4SSProgram` methods that UE4SS uses to expose its current
// ImGui context + allocator functions to mods. Calls to these
// resolve through UE4SS.lib at link time and end up in UE4SS.dll's
// copies, so the mod's locally-linked ImGui draws into the same
// context UE4SS uses.
//
// Requires `imgui.h` to be included BEFORE this header (we use
// `ImGuiContext`, `ImGuiMemAllocFunc`, `ImGuiMemFreeFunc` from
// vendored ImGui — typically v1.92.1 to match UE4SS).
//
// Usage in a render lambda:
//
//   #include "imgui.h"
//   #include "uespy_imgui_bridge.hpp"
//   ...
//   ImGui::SetCurrentContext(RC::UE4SSProgram::get_current_imgui_context());
//   ImGuiMemAllocFunc alloc{}; ImGuiMemFreeFunc free{}; void* ud{};
//   RC::UE4SSProgram::get_current_imgui_allocator_functions(&alloc, &free, &ud);
//   ImGui::SetAllocatorFunctions(alloc, free, ud);

#pragma once

#ifndef RC_UE4SS_API
#define RC_UE4SS_API __declspec(dllimport)
#endif

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
