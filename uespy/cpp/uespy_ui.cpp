// uespy_ui.cpp
//
// extern "C" bridge from uespy::ui (Rust) to vendored ImGui. Every
// function takes UTF-8 byte ranges (ptr+len) so Rust strings round-
// trip without null-termination, and copies to a temp buffer
// internally for the ImGui calls that need a null-terminated label.
//
// Compiled into the cdylib by uespy-build alongside the rest of
// the shim. Game crates don't reference this file directly — they
// call into uespy::ui from Rust and the linker resolves to these
// wrappers.

#include <cstddef>
#include <cstring>
#include <string>

#include "imgui.h"
// Intentionally NOT including uespy_imgui_bridge.hpp here.
// The UE4SS context bridge (`uespy_ui_enable_imgui`) lives in
// uespy_shim.cpp instead so this file has no UE4SS.lib dep.
// That keeps test binaries and build-script binaries linkable
// without pulling UE4SS.dll into their import tables.

// ImGui labels are null-terminated; for short Rust &str inputs we
// stack-copy + nul-terminate. For text-only paths (TextUnformatted)
// we use the begin/end overload that takes a byte range and
// avoids the copy.
//
// The 1024-byte cap covers every label any UI realistically uses;
// pathological long labels fall back to a heap allocation.
namespace {
struct CStr {
    char  stack[1024];
    char* ptr;
    bool  heap;
    CStr(const char* s, std::size_t n) : ptr(stack), heap(false) {
        if (n + 1 <= sizeof(stack)) {
            std::memcpy(stack, s, n);
            stack[n] = 0;
        } else {
            heap = true;
            ptr = static_cast<char*>(std::malloc(n + 1));
            std::memcpy(ptr, s, n);
            ptr[n] = 0;
        }
    }
    ~CStr() { if (heap) std::free(ptr); }
    const char* c_str() const { return heap ? ptr : stack; }
};
} // namespace

extern "C" {

// ---- text ----

void uespy_ui_text(const char* s, std::size_t n) {
    ImGui::TextUnformatted(s, s + n);
}

void uespy_ui_text_disabled(const char* s, std::size_t n) {
    CStr c(s, n);
    ImGui::TextDisabled("%s", c.c_str());
}

void uespy_ui_text_colored(const char* s, std::size_t n,
                           float r, float g, float b, float a) {
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(r, g, b, a));
    ImGui::TextUnformatted(s, s + n);
    ImGui::PopStyleColor();
}

// ---- buttons / interactive ----

bool uespy_ui_button(const char* s, std::size_t n, float w, float h) {
    CStr c(s, n);
    return ImGui::Button(c.c_str(), ImVec2(w, h));
}

bool uespy_ui_small_button(const char* s, std::size_t n) {
    CStr c(s, n);
    return ImGui::SmallButton(c.c_str());
}

bool uespy_ui_checkbox(const char* s, std::size_t n, bool* v) {
    CStr c(s, n);
    return ImGui::Checkbox(c.c_str(), v);
}

bool uespy_ui_slider_float(const char* s, std::size_t n,
                           float* v, float lo, float hi) {
    CStr c(s, n);
    return ImGui::SliderFloat(c.c_str(), v, lo, hi);
}

bool uespy_ui_slider_int(const char* s, std::size_t n,
                         int* v, int lo, int hi) {
    CStr c(s, n);
    return ImGui::SliderInt(c.c_str(), v, lo, hi);
}

bool uespy_ui_input_int(const char* s, std::size_t n, int* v) {
    CStr c(s, n);
    return ImGui::InputInt(c.c_str(), v);
}

bool uespy_ui_collapsing_header(const char* s, std::size_t n) {
    CStr c(s, n);
    return ImGui::CollapsingHeader(c.c_str());
}

// ---- progress / layout ----

void uespy_ui_progress_bar(float fraction,
                           const char* overlay, std::size_t overlay_n) {
    if (overlay && overlay_n > 0) {
        CStr c(overlay, overlay_n);
        ImGui::ProgressBar(fraction, ImVec2(-1.0f, 0.0f), c.c_str());
    } else {
        ImGui::ProgressBar(fraction, ImVec2(-1.0f, 0.0f));
    }
}

void uespy_ui_separator()        { ImGui::Separator(); }
void uespy_ui_spacing()          { ImGui::Spacing(); }
void uespy_ui_same_line(float x) { ImGui::SameLine(x); }
void uespy_ui_new_line()         { ImGui::NewLine(); }
void uespy_ui_indent(float w)    { ImGui::Indent(w); }
void uespy_ui_unindent(float w)  { ImGui::Unindent(w); }
void uespy_ui_dummy(float w, float h)   { ImGui::Dummy(ImVec2(w, h)); }
void uespy_ui_set_next_item_width(float w) { ImGui::SetNextItemWidth(w); }

// ---- enable/disable groups ----

void uespy_ui_begin_disabled(bool disabled) { ImGui::BeginDisabled(disabled); }
void uespy_ui_end_disabled()                { ImGui::EndDisabled(); }

// ---- groups + trees ----

bool uespy_ui_tree_node(const char* s, std::size_t n) {
    CStr c(s, n);
    return ImGui::TreeNode(c.c_str());
}
void uespy_ui_tree_pop() { ImGui::TreePop(); }

void uespy_ui_begin_group() { ImGui::BeginGroup(); }
void uespy_ui_end_group()   { ImGui::EndGroup(); }

// uespy_ui_enable_imgui lives in uespy_shim.cpp; mods that want
// it call uespy::build::CppShim's compile() (which compiles
// uespy_shim.cpp and links UE4SS.lib for the cdylib).

} // extern "C"
