#![allow(clippy::missing_safety_doc)]

static MOD_INFO: ueforge::ModDef = ueforge::ModDef {
    name: "HumanitZMod",
    version: "0.1.0",
    log_file: "humanitz_mod.log",
    console_title: "HumanitZ Mod",
    console: cfg!(feature = "console"),
    on_unreal_init: on_unreal_init,
    on_shutdown: on_shutdown,
    tabs: &[
        ueforge::TabDef {
            name: "Tables",
            render: ueforge::ui_data_table_browser::render,
        },
        ueforge::TabDef {
            name: "Classes",
            render: ueforge::ui_class_browser::render,
        },
        ueforge::TabDef {
            name: "Structs",
            render: ueforge::ui_struct_browser::render,
        },
    ],
};

ueforge::ue4ss_mod!(MOD_INFO);

fn on_unreal_init() {
    ueforge::worker::spawn("humanitz_mod/init", || unsafe { worker() });
}

unsafe fn worker() {
    ueforge::log!("humanitz_mod init");
}

fn on_shutdown() {
    ueforge::log!("humanitz_mod shutdown");
}
