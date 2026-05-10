//! Built-in ImGui browser tab for every discovered `UClass`.
//! Same shape as `ui_data_table_browser` -- reads from
//! `ueforge::discovery::cached()`, filters by substring,
//! click-to-expand shows the native property list.
//!
//! ```ignore
//! tabs: &[
//!     ueforge::TabDef { name: "Classes",
//!                       render: ueforge::ui_class_browser::render },
//! ],
//! ```

use std::sync::OnceLock;

use parking_lot::Mutex;

use crate::ui;

struct ClassBrowserUi {
    selected: Option<String>,
    filter: [u8; 128],
}

impl ClassBrowserUi {
    fn new() -> Self {
        Self {
            selected: None,
            filter: [0u8; 128],
        }
    }
}

static BROWSER: OnceLock<Mutex<ClassBrowserUi>> = OnceLock::new();

fn state() -> &'static Mutex<ClassBrowserUi> {
    BROWSER.get_or_init(|| Mutex::new(ClassBrowserUi::new()))
}

pub fn render() {
    let mut s = state().lock();

    ui::text("Classes");
    ui::text_disabled(
        "Every UClass ueforge::discovery found. Click Open to see \
         the native property list (name, FProperty class, offset, \
         element size).",
    );
    ui::spacing();

    if ui::button("Refresh discovery##classes") {
        let _ = crate::discovery::refresh();
    }
    ui::same_line();
    ui::input_text("filter##class_browser", &mut s.filter);
    let filter_owned = ui::cstr_view(&s.filter).to_ascii_lowercase();
    let filter = filter_owned.as_str();

    let Some(snap) = crate::discovery::cached() else {
        ui::text_disabled("Discovery has not run yet.");
        return;
    };

    let classes_found = snap
        .classes
        .get("classes_found")
        .and_then(|v| v.as_u64())
        .unwrap_or(0);
    ui::text(&format!("Discovered: {classes_found} classes"));
    ui::separator();
    ui::spacing();

    let empty = Vec::new();
    let classes = snap
        .classes
        .get("classes")
        .and_then(|v| v.as_array())
        .unwrap_or(&empty);

    let mut shown_count = 0usize;
    for c in classes {
        let name = c.get("name").and_then(|v| v.as_str()).unwrap_or("?");
        if !filter.is_empty() && !name.to_ascii_lowercase().contains(filter) {
            continue;
        }
        shown_count += 1;
        if shown_count > 500 && s.selected.as_deref() != Some(name) {
            // Rendering thousands of buttons per frame is a tax.
            // Filter further to bring the working set down.
            continue;
        }
        let selected = s.selected.as_deref() == Some(name);
        let label = if selected {
            format!("[Close]##cls_{name}")
        } else {
            format!("Open##cls_{name}")
        };
        if ui::small_button(&label) {
            s.selected = if selected { None } else { Some(name.to_string()) };
        }
        ui::same_line();
        let super_name = c.get("super").and_then(|v| v.as_str()).unwrap_or("<root>");
        let fields_n = c
            .get("fields")
            .and_then(|v| v.as_array())
            .map(|a| a.len())
            .unwrap_or(0);
        let psize = c
            .get("properties_size")
            .and_then(|v| v.as_u64())
            .unwrap_or(0);
        ui::text(&format!(
            "{name}  :  {super_name}  ({fields_n} fields, +0x{psize:x})"
        ));

        if selected {
            render_field_list(c);
        }
    }
    if shown_count > 500 {
        ui::text_disabled(&format!(
            "{} matches; showing first 500. Tighten the filter.",
            shown_count
        ));
    } else if !filter.is_empty() {
        ui::text_disabled(&format!("filtered: {shown_count} matching '{filter}'"));
    }
}

fn render_field_list(c: &serde_json::Value) {
    ui::indent();
    let empty = Vec::new();
    let fields = c.get("fields").and_then(|v| v.as_array()).unwrap_or(&empty);
    if ui::tree_node("fields") {
        for f in fields {
            let n = f.get("name").and_then(|v| v.as_str()).unwrap_or("?");
            let off = f.get("offset").and_then(|v| v.as_i64()).unwrap_or(0);
            let sz = f.get("element_size").and_then(|v| v.as_i64()).unwrap_or(0);
            ui::text(&format!("  {n}  @+0x{off:x}  size={sz}"));
        }
        if fields.is_empty() {
            ui::text_disabled("  (no native properties)");
        }
        ui::tree_pop();
    }

    let functions = c
        .get("functions")
        .and_then(|v| v.as_array())
        .unwrap_or(&empty);
    if ui::tree_node("functions") {
        for f in functions {
            let n = f.get("name").and_then(|v| v.as_str()).unwrap_or("?");
            let flags = f
                .get("function_flags")
                .and_then(|v| v.as_str())
                .unwrap_or("0x");
            ui::text(&format!("  {n}  flags={flags}"));
        }
        if functions.is_empty() {
            ui::text_disabled("  (no functions)");
        }
        ui::tree_pop();
    }
    ui::unindent();
}
