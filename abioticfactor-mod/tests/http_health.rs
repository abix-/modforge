//! User-requested freeze diagnostics: HTTP status and external read-only stack/state capture.
#[path = "common/spawn_trace.rs"]
mod spawn_trace;

#[test]
#[ignore = "read-only normal client respawn function discovery"]
fn respawn_functions_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug");
    let widgets = api.op("walk_class_chain", serde_json::json!({"needle":"Respawn","max":64}));
    assert!(widgets.ok, "respawn widgets: {:?}", widgets.error);
    let mut classes = std::collections::BTreeSet::from(["Abiotic_PlayerCharacter_C".to_owned(), "Abiotic_PlayerController_C".to_owned()]);
    for widget in widgets.result["instances"].as_array().expect("widgets") {
        classes.insert(widget["full_name"].as_str().expect("widget name").split_whitespace().next().unwrap().to_owned());
    }
    for class in classes {
        let reply = api.op("class_functions_by_name", serde_json::json!({"class":class}));
        assert!(reply.ok, "{class}: {:?}", reply.error);
        for function in reply.result["functions"].as_array().expect("functions") {
            let name = function["name"].as_str().unwrap_or("");
            if class.contains("Respawn") || ["Respawn", "Revive", "Resurrect", "Death"].iter().any(|part| name.contains(part)) {
                println!("{class}: {function}");
            }
        }
    }
    for (class, function) in [("Abiotic_PlayerCharacter_C", "Request_RespawnPlayerCharacter"), ("Abiotic_PlayerCharacter_C", "RespawnPlayerCharacter"), ("W_RespawnOptions_C", "RequestRespawn")] {
        let reply = api.op("function_parameters", serde_json::json!({"class":class,"function":function}));
        assert!(reply.ok, "{function}: {:?}", reply.error);
        println!("{function} parameters: {}", reply.result);
    }
}

#[test]
#[ignore = "read-only parameters for the normal saved-world hosting functions"]
fn saved_world_host_parameters() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug");
    for function in ["HostMultiplayerGame", "SetMapToHost", "HostGame"] {
        let class = if function == "HostMultiplayerGame" { "W_HostMenu_Parent_C" } else { "W_MainMenu_ContinueGame_C" };
        let reply = api.op("function_parameters", serde_json::json!({"class":class,"function":function}));
        assert!(reply.ok, "{function}: {:?}", reply.error);
        println!("{function}: {}", reply.result);
    }
    let reply = api.op("walk_class", serde_json::json!({"class":"W_MainMenu_ContinueGame_C"}));
    assert!(reply.ok, "host menu fields: {:?}", reply.error);
    println!("Host menu fields: {}", reply.result);
}

#[test]
#[ignore = "read-only game instance save/session fields and functions behind the Continue menu's host path"]
fn saved_world_game_instance_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    let instances = api.op("walk_class_chain", serde_json::json!({"needle":"GameInstance","max":64}));
    assert!(instances.ok, "game instances: {:?}", instances.error);
    let mut classes = std::collections::BTreeSet::new();
    for instance in instances.result["instances"].as_array().expect("instances") {
        if instance["is_cdo"] == false {
            classes.insert(instance["full_name"].as_str().expect("name").split_whitespace().next().unwrap().to_owned());
        }
    }
    for class in classes {
        let functions = api.op("class_functions_by_name", serde_json::json!({"class":class}));
        assert!(functions.ok, "{class} functions: {:?}", functions.error);
        for function in functions.result["functions"].as_array().expect("functions") {
            let name = function["name"].as_str().unwrap_or("");
            if ["World", "Save", "Session", "Host", "Lan", "LAN"].iter().any(|part| name.contains(part)) {
                println!("{class}: {function}");
            }
        }
        let fields = api.op("walk_class", serde_json::json!({"class":class}));
        assert!(fields.ok, "{class} fields: {:?}", fields.error);
        println!("{class} walk: {}", fields.result);
    }
    let widget = api.op("walk_class", serde_json::json!({"class":"W_MainMenu_ContinueGame_C"}));
    assert!(widget.ok, "continue widget: {:?}", widget.error);
    println!("W_MainMenu_ContinueGame_C walk: {}", widget.result);
    // HostMultiplayerGame gates on IsLoggedIn(GetPlayerController(0)); the host op must check the same.
    for (class, function) in [("KismetSystemLibrary", "IsLoggedIn"), ("GameplayStatics", "GetPlayerController")] {
        let reply = api.op("function_parameters", serde_json::json!({"class":class,"function":function}));
        assert!(reply.ok, "{class}::{function}: {:?}", reply.error);
        println!("{function} parameters: {}", reply.result);
    }
}

#[test]
#[ignore = "read-only menu classes for the normal saved-world hosting flow"]
fn saved_world_menu_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    let reply = api.op("walk_class_chain", serde_json::json!({"needle":"UserWidget","max":4096}));
    assert!(reply.ok, "menu instances: {:?}", reply.error);
    let mut classes = std::collections::BTreeSet::new();
    for instance in reply.result["instances"].as_array().expect("widget instances") {
        let class = instance["full_name"].as_str().expect("widget name").split_whitespace().next().unwrap();
        if ["Menu", "Save", "Host", "Load", "World"].iter().any(|part| class.contains(part)) {
            classes.insert(class.to_owned());
        }
    }
    for class in classes {
        let functions = api.op("class_functions_by_name", serde_json::json!({"class":class}));
        assert!(functions.ok, "menu functions: {:?}", functions.error);
        println!("{class}: {}", functions.result);
    }
}

#[test]
#[ignore = "read-only game instance function catalog for hosting an existing save"]
fn saved_world_launch_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    let instances = api.op("walk_class_chain", serde_json::json!({"needle":"AbioticGameInstance","max":8}));
    assert!(instances.ok, "game instances: {:?}", instances.error);
    let instance = instances.result["instances"].as_array().expect("instances").iter()
        .find(|i| i["is_cdo"] == false).expect("live game instance");
    let class = instance["full_name"].as_str().expect("instance full name").split_whitespace().next().expect("class name");
    println!("Game instance class: {class}");
    let reply = api.op("class_functions_by_name", serde_json::json!({"class":class}));
    assert!(reply.ok, "game instance functions: {:?}", reply.error);
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    std::fs::write(root.join("saved-world-launch-functions.json"), serde_json::to_vec_pretty(&reply.result).unwrap()).unwrap();
    for function in reply.result["functions"].as_array().expect("functions") {
        let name = function["name"].as_str().unwrap_or("");
        if ["Save", "Load", "Host", "Session", "World", "Start", "Command"].iter().any(|part| name.contains(part)) {
            println!("{function}");
        }
    }
}

#[test]
#[ignore = "read-only current navigation generation settings"]
fn navigation_generation_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::navigation_generation(&api).expect("navigation generation settings");
}

#[test]
#[ignore = "read-only movement state of the player named Sophia"]
fn sophia_movement_state_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug");
    spawn_trace::sophia_movement_state(&api).expect("Sophia movement state");
}

#[test]
#[ignore = "read-only export of the game's level-to-sector table"]
fn sector_table_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::sector_table(&api).expect("current-schema level table");
}

#[test]
#[ignore = "read-only observation of the normal client's selected level and sector"]
fn sector_client_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::sector_client_snapshot(&api).expect("client sector observation");
}

#[test]
#[ignore = "read-only level-manager inputs and actor-overlap queries"]
fn sector_level_selection_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::sector_level_selection(&api).expect("level selection inputs");
}

#[test]
#[ignore = "read-only character capture; requires read_snapshot in the loaded mod"]
fn sector_pose_snapshot_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(15));
    spawn_trace::sector_pose_snapshot(&api).expect("same-update character pose");
}

#[test]
#[ignore = "read-only movement RPC metadata from the running host"]
fn movement_rpc_schema() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::movement_rpc_schema(&api).expect("movement schema");
}

#[test]
#[ignore = "read-only character camera/crouch function catalog"]
fn character_pose_functions_research() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug");
    let reply = api.try_op("class_functions_by_name", serde_json::json!({"class":"Abiotic_PlayerCharacter_C"})).expect("function catalog HTTP");
    assert!(reply.ok, "{:?}", reply.error);
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client");
    std::fs::write(root.join("character-pose-functions.json"), serde_json::to_vec_pretty(&reply.result).unwrap()).unwrap();
    for function in reply.result["functions"].as_array().expect("functions") {
        let name = function["name"].as_str().expect("function name");
        if ["camera", "crouch", "head", "view"].iter().any(|word| name.to_lowercase().contains(word)) { println!("{function}"); }
    }
}

#[test]
fn save_key_converts_network_identity_to_decimal() {
    let path = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.exe");
    let lines = modforge::patterns::sleuth::inspect_file_function(path, 0x46a8970).expect("save ID helper");
    for line in &lines { println!("{line}"); }
    assert!(lines.iter().any(|line| line.contains("!_wtoi64")), "save key conversion changed");
}

#[test]
fn controller_readiness_symbols() {
    let path = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.pdb");
    let class = std::env::var("ABIOTIC_SYMBOL_CLASS").unwrap_or_else(|_| "AAbioticPlayerController".into());
    let symbols = if let Ok(query) = std::env::var("ABIOTIC_SYMBOL_QUERY") {
        ueforge::symbols::procedures(path, &query)
    } else if let Ok(method) = std::env::var("ABIOTIC_SYMBOL_METHOD") {
        ueforge::symbols::functions(path, &class, &method)
    } else { ueforge::symbols::procedures(path, &format!("{class}::")) }.expect("game symbols");
    assert!(!symbols.is_empty());
    for symbol in symbols {
        println!("0x{:X} {}", symbol.rva, symbol.decorated);
    }
}

#[test]
#[ignore = "requires the running Abiotic Factor mod for read-only Blueprint research"]
fn class_blueprint_research() {
    assert!(std::env::var_os("ABIOTIC_TRACE_CLASS").is_some(), "set ABIOTIC_TRACE_CLASS");
    assert!(std::env::var_os("ABIOTIC_TRACE_PAWN").is_none() && std::env::var_os("ABIOTIC_TRACE_OBJECT_FIELD").is_none(), "class research does not use an instance path");
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::readiness(&api, std::ptr::null_mut(), 0).expect("class Blueprint trace");
}

#[test]
fn loading_and_creation_native_code() {
    let directory = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64");
    let pdb = directory.join("AbioticFactor-Win64-Shipping.pdb");
    let exe = directory.join("AbioticFactor-Win64-Shipping.exe");
    if let Ok(rva) = std::env::var("ABIOTIC_NATIVE_RVA") {
        let rva = u32::from_str_radix(rva.trim_start_matches("0x"), 16).expect("hex RVA");
        for line in modforge::patterns::sleuth::inspect_file_function(&exe, rva).expect("native call target") { println!("{line}"); }
        return;
    }
    let query = std::env::var("ABIOTIC_NATIVE_QUERY").unwrap_or_else(|_| "ULevelManagerSubsystem::IsLevelLoaded".into());
    let symbols = ueforge::symbols::procedures(&pdb, &query).expect("native research symbols");
    assert!(!symbols.is_empty(), "no native function matches {query}");
    for symbol in symbols {
        println!("native research 0x{:X} {}", symbol.rva, symbol.decorated);
        for line in modforge::patterns::sleuth::inspect_file_function(&exe, symbol.rva).expect("native function disassembly") {
            println!("{line}");
        }
    }
}

#[test]
fn level_streaming_layouts() {
    let pdb = std::path::Path::new("C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64/AbioticFactor-Win64-Shipping.pdb");
    let classes = std::env::var("ABIOTIC_LAYOUT_CLASSES").unwrap_or_else(|_| "AAbioticLevelStreamingVolume,ULevelManagerInstance,ULevelStreaming".into());
    for name in classes.split(',') {
        let layout = ueforge::symbols::layout(pdb, name).expect("streaming type layout");
        println!("{name}: {} bytes", layout.size);
        for field in layout.fields { println!("+0x{:X} {} {}", field.offset, field.name, field.type_name); }
    }
    println!("streaming states: {:?}", ueforge::symbols::enumeration(pdb, "ELevelStreamingState").expect("streaming state enum"));
}

#[test]
#[ignore = "requires installed Abiotic Factor assets and the retoc Rust tool"]
fn streaming_asset_catalog() {
    let container = "C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Content/Paks/pakchunk0-Windows.utoc";
    let output = std::process::Command::new("retoc").args(["list", "--path", container]).output().expect("run retoc list");
    assert!(output.status.success(), "retoc: {}", String::from_utf8_lossy(&output.stderr));
    let listing = String::from_utf8(output.stdout).expect("asset path text");
    let paths: Vec<_> = listing.lines().filter(|line| line.contains("/Maps/") || line.contains("LevelStreaming") || line.contains("LevelManager")).collect();
    assert!(!paths.is_empty(), "no streaming/map assets found");
    let artifact = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/streaming-asset-paths.json");
    std::fs::write(artifact, serde_json::to_vec_pretty(&paths).expect("serialize paths")).expect("write asset catalog");
    println!("{} streaming/map asset paths", paths.len());
    for path in paths.iter().filter(|path| path.contains("LevelStreaming") || path.contains("LevelManager")) { println!("{path}"); }
}

#[test]
#[ignore = "requires the Abiotic Factor mod for read-only streaming metadata"]
fn streaming_property_metadata() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::streaming_properties(&api).expect("streaming property metadata");
}

#[test]
#[ignore = "requires a healthy hosted Abiotic Factor world for read-only volume research"]
fn live_streaming_volumes() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::streaming_world_snapshot(&api).expect("live streaming volumes");
}

#[test]
#[ignore = "requires the Abiotic Factor mod for current map property declarations"]
fn map_property_schema() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    spawn_trace::map_property_schema(&api).expect("map property schema");
}
#[test]
#[ignore = "requires user-requested diagnosis of the currently stalled game"]
fn frozen_game_call_stack() {
    use windows_sys::Win32::Foundation::{CloseHandle, HANDLE};
    use windows_sys::Win32::System::Diagnostics::Debug::*;
    use windows_sys::Win32::System::Threading::*;

    struct Handle(HANDLE);
    impl Drop for Handle { fn drop(&mut self) { unsafe { CloseHandle(self.0); } } }
    struct Suspended(HANDLE);
    impl Drop for Suspended { fn drop(&mut self) { unsafe { ResumeThread(self.0); } } }
    #[repr(align(16))]
    struct AlignedContext(CONTEXT);

    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    let stats = api.try_op("pe_stats", serde_json::json!({})).expect("HTTP stats");
    let tid = stats.result["game_thread"]["thread"].as_u64().expect("game thread") as u32;
    // The remote process is opened for queries and reads only. No code injection,
    // memory writes, or raw stack contents are emitted. Resume is guaranteed by Drop.
    unsafe {
        let thread = Handle(OpenThread(THREAD_GET_CONTEXT | THREAD_SUSPEND_RESUME | THREAD_QUERY_INFORMATION, 0, tid));
        assert!(!thread.0.is_null(), "OpenThread: {}", std::io::Error::last_os_error());
        let pid = GetProcessIdOfThread(thread.0);
        let process = Handle(OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 0, pid));
        assert!(!process.0.is_null(), "OpenProcess: {}", std::io::Error::last_os_error());
        let path: Vec<u16> = "C:/Games/Steam/steamapps/common/AbioticFactor/AbioticFactor/Binaries/Win64\0".encode_utf16().collect();
        SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_UNDNAME | SYMOPT_FAIL_CRITICAL_ERRORS | SYMOPT_NO_PROMPTS);
        assert_ne!(SymInitializeW(process.0, path.as_ptr(), 1), 0, "SymInitialize: {}", std::io::Error::last_os_error());
        let mut addresses = Vec::new();
        let mut rpc = None;
        let mut script_frames = Vec::new();
        {
            assert_ne!(SuspendThread(thread.0), u32::MAX, "SuspendThread");
            let _resume = Suspended(thread.0);
            let mut storage = AlignedContext(std::mem::zeroed());
            let context = &mut storage.0;
            context.ContextFlags = CONTEXT_FULL_AMD64;
            assert_ne!(GetThreadContext(thread.0, context), 0, "GetThreadContext: {}", std::io::Error::last_os_error());
            addresses.push(context.Rip);
            let mut frame: STACKFRAME64 = std::mem::zeroed();
            frame.AddrPC.Offset = context.Rip;
            frame.AddrFrame.Offset = context.Rbp;
            frame.AddrStack.Offset = context.Rsp;
            frame.AddrPC.Mode = AddrModeFlat;
            frame.AddrFrame.Mode = AddrModeFlat;
            frame.AddrStack.Mode = AddrModeFlat;
            for _ in 0..96 {
                if StackWalk64(0x8664, process.0, thread.0, &mut frame, (context as *mut CONTEXT).cast(), None, Some(SymFunctionTableAccess64), Some(SymGetModuleBase64), None) == 0 || frame.AddrPC.Offset == 0 { break; }
                if addresses.last() != Some(&frame.AddrPC.Offset) { addresses.push(frame.AddrPC.Offset); }
                let base = SymGetModuleBase64(process.0, frame.AddrPC.Offset);
                if frame.AddrPC.Offset - base == 0x35ff413 { rpc = Some((context.R15, context.Rsi)); }
                if frame.AddrPC.Offset - base == 0x12b2268 {
                    let mut data = [0u64; 6];
                    let mut read = 0;
                    if ReadProcessMemory(process.0, context.Rbx as *const _, data.as_mut_ptr().cast(), 48, &mut read) != 0 {
                        script_frames.push((data[2], data[3], data[4], data[5]));
                    }
                }
            }
        }
        println!("GameThread {tid}, process {pid}, {} unwound frames", addresses.len());
        if std::env::var_os("ABIOTIC_TRACE_RANGES").is_some() {
            assert!(rpc.is_some() && !script_frames.is_empty(), "research bootstrap requires the captured spawn RPC; use healthy-host class discovery after restart");
        }
        for (function, object, code, locals) in script_frames {
            let mut name = [0u8; 8];
            let mut script = [0u8; 8];
            let mut read = 0;
            assert_ne!(ReadProcessMemory(process.0, (function + 24) as *const _, name.as_mut_ptr().cast(), 8, &mut read), 0);
            assert_ne!(ReadProcessMemory(process.0, (function + 96) as *const _, script.as_mut_ptr().cast(), 8, &mut read), 0);
            let reply = api.try_op("fname_to_string", serde_json::json!({"fname":u64::from_le_bytes(name)})).expect("script name");
            println!("Blueprint {} code offset {} function 0x{function:X} object 0x{object:X}", reply.result, code.saturating_sub(u64::from_le_bytes(script)));
            if reply.result["string"] == "ExecuteUbergraph_Abiotic_PlayerController" {
                if std::env::var_os("ABIOTIC_TRACE_RANGES").is_some() {
                    spawn_trace::readiness(&api, process.0, object).expect("HTTP readiness trace");
                } else if let Err(error) = spawn_trace::trace(&api, process.0, function, object, locals) { println!("spawn trace stopped: {error}"); }
            }
        }
        if let Some((function, object)) = rpc {
            for (label, address) in [("RPC function", function), ("RPC object", object)] {
                let mut bytes = [0u8; 8];
                let mut read = 0;
                assert_ne!(ReadProcessMemory(process.0, (address + 24) as *const _, bytes.as_mut_ptr().cast(), 8, &mut read), 0);
                let reply = api.try_op("fname_to_string", serde_json::json!({"fname":u64::from_le_bytes(bytes)})).expect("name lookup");
                println!("{label}: {}", reply.result);
            }
        }
        for address in addresses {
            let base = SymGetModuleBase64(process.0, address);
            let mut symbol: SYMBOL_INFO_PACKAGE = std::mem::zeroed();
            symbol.si.SizeOfStruct = std::mem::size_of::<SYMBOL_INFO>() as u32;
            symbol.si.MaxNameLen = 2000;
            let mut displacement = 0;
            if SymFromAddr(process.0, address, &mut displacement, &mut symbol.si) != 0 {
                let name = std::slice::from_raw_parts(symbol.si.Name.as_ptr().cast::<u8>(), symbol.si.NameLen as usize);
                println!("0x{address:X} module+0x{:X} {}+0x{displacement:X}", address - base, String::from_utf8_lossy(name));
            } else { println!("0x{address:X} module 0x{base:X}+0x{:X}", address - base); }
        }
        SymCleanup(process.0);
    }
}

#[test]
#[ignore = "requires the user-requested frozen-game HTTP diagnosis"]
fn frozen_game_thread_sample() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(8));
    let stats = api.try_op("pe_stats", serde_json::json!({})).expect("stats");
    let thread = stats.result["game_thread"]["thread"].as_u64().expect("game thread id");
    let reply = api.try_op("sample_thread_modules", serde_json::json!({"duration_ms":1000,"interval_ms":100})).expect("HTTP sample reply");
    assert!(reply.ok, "thread sampling failed");
    for sample in reply.result["by_thread"].as_array().expect("threads") {
        if sample["tid"].as_u64() == Some(thread) { println!("game thread sample: {sample}"); }
    }
    let ops = api.try_op("list_ops", serde_json::json!({})).expect("operations");
    let output = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../target/abioticfactor-client/http-operations.json");
    std::fs::write(output, serde_json::to_vec_pretty(&ops.result).unwrap()).unwrap();
    let metrics = api.try_op("op_metrics", serde_json::json!({})).expect("metrics");
    println!("HTTP operation metrics: {}", metrics.result);
}

#[test]
#[ignore = "requires the user-requested frozen-game HTTP diagnosis"]
fn frozen_game_http_state() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(6));
    for operation in ["pe_stats", "pe_ping", "pe_stats"] {
        let started = std::time::Instant::now();
        match api.try_op(operation, serde_json::json!({})) {
            Ok(reply) => println!("{operation} {:.2}s ok={}: {}", started.elapsed().as_secs_f64(), reply.ok, reply.result),
            Err(error) => println!("{operation} {:.2}s: {error}", started.elapsed().as_secs_f64()),
        }
    }
}

#[test]
#[ignore = "requires the user-requested live mod HTTP check"]
fn mod_http_responds() {
    let api = modforge::client::Api::<serde_json::Value>::at(31260, "/debug")
        .with_timeout(std::time::Duration::from_secs(5));
    let started = std::time::Instant::now();
    let reply = api.try_op("list_ops", serde_json::json!({}));
    println!("HTTP check elapsed: {:.2}s", started.elapsed().as_secs_f64());
    match reply {
        Ok(reply) => {
            println!("Mod HTTP responded; operation ok: {}", reply.ok);
            assert!(reply.ok, "HTTP responded but list_ops failed");
        }
        Err(error) => panic!("Mod HTTP did not respond successfully: {error}"),
    }
}
