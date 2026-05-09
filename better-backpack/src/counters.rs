// Hot-path performance counters.
//
// Every counter is an `AtomicU64` bumped at a specific call site
// in the mod. Snapshot endpoint exposes them. To find the
// runaway: snapshot at T0, play for N seconds, snapshot at T1,
// diff. Whichever counter has the largest delta is the cycle
// thief.
//
// Counters are write-mostly; no contention with reads. Each
// bump is a single relaxed atomic add.

use std::sync::atomic::{AtomicU64, AtomicUsize, Ordering};

macro_rules! counter {
    ($name:ident) => {
        pub static $name: AtomicU64 = AtomicU64::new(0);
    };
}

// kill_hook (UHealthComponent vtable)
counter!(KILL_HOOK_FIRES);
counter!(KILL_HOOK_PLAYER_FIRES);
counter!(KILL_HOOK_OWNER_FULLNAME_ALLOCS);
counter!(KILL_HOOK_LOG_LINES);
counter!(KILL_HOOK_DAMAGETYPE_NAME_ALLOCS);

// fall_hook (player BP class vtable)
counter!(FALL_HOOK_FIRES);
counter!(FALL_HOOK_FNNAME_ALLOCS);

// PE-queue drain
counter!(DRAIN_PENDING_CALLS);
counter!(DRAIN_PENDING_DRAINED_CMDS);

// debug damage_ring
counter!(DAMAGE_RING_PUSHES);

// world_loader poller
counter!(WORLD_LOADER_POLLS);
counter!(WORLD_LOADER_GOBJECTS_WALKS);

// ImGui RPG tab render path (FFI hits)
counter!(IMGUI_TAB_RENDERS);
counter!(IMGUI_FORMAT_CALLS);

// File logging
counter!(BBP_LOG_LINES);
counter!(BBP_LOG_FSYNCS);

// HTTP endpoint
counter!(HTTP_REQUESTS);

// Peak high-water marks (size_t).
pub static DAMAGE_RING_PEAK: AtomicUsize = AtomicUsize::new(0);
pub static PE_QUEUE_PEAK: AtomicUsize = AtomicUsize::new(0);

// CPU time accumulators (nanoseconds spent inside our hot-path
// functions). Diff over a window = total wall time our code
// stole from the game thread. Compare to the process's total
// CPU time delta (process_cpu_user_ns + process_cpu_kernel_ns)
// to compute our fraction of total CPU load.
counter!(TIME_NS_KILL_HOOK);
counter!(TIME_NS_FALL_HOOK);
counter!(TIME_NS_DRAIN_PENDING);
counter!(TIME_NS_BBP_LOG);
counter!(TIME_NS_IMGUI_GET_XP);
counter!(TIME_NS_FORMAT_SKILL_EFFECT);
counter!(TIME_NS_HTTP_HANDLE);

/// Drop-guard that adds elapsed time to a counter when scope
/// exits. Use at the start of any function we want to measure:
/// `let _g = crate::counters::time_scope(&crate::counters::TIME_NS_FALL_HOOK);`
pub struct TimeScope<'a> {
    counter: &'a AtomicU64,
    start: std::time::Instant,
}

impl Drop for TimeScope<'_> {
    fn drop(&mut self) {
        let ns = self.start.elapsed().as_nanos() as u64;
        self.counter.fetch_add(ns, Ordering::Relaxed);
    }
}

#[inline(always)]
pub fn time_scope(counter: &AtomicU64) -> TimeScope<'_> {
    TimeScope {
        counter,
        start: std::time::Instant::now(),
    }
}

#[inline(always)]
pub fn bump(c: &AtomicU64) {
    c.fetch_add(1, Ordering::Relaxed);
}

#[inline(always)]
pub fn observe_peak(p: &AtomicUsize, value: usize) {
    let mut cur = p.load(Ordering::Relaxed);
    while value > cur {
        match p.compare_exchange_weak(cur, value, Ordering::Relaxed, Ordering::Relaxed) {
            Ok(_) => break,
            Err(c) => cur = c,
        }
    }
}

/// Enumerate all threads in the current process, capturing
/// thread name + accumulated user/kernel CPU time. Diff between
/// two snapshots = per-thread CPU consumed in the window.
/// Whichever thread name has the biggest delta is the cycle
/// thief (UE5 names its threads: `GameThread`, `RenderThread`,
/// `RHIThread`, `TaskGraphThreadHP*`, etc.).
pub fn process_threads_json() -> serde_json::Value {
    use windows_sys::Win32::Foundation::{CloseHandle, FILETIME, INVALID_HANDLE_VALUE};
    use windows_sys::Win32::System::Diagnostics::ToolHelp::{
        CreateToolhelp32Snapshot, TH32CS_SNAPTHREAD, THREADENTRY32, Thread32First, Thread32Next,
    };
    use windows_sys::Win32::System::Threading::{
        GetCurrentProcessId, GetThreadDescription, GetThreadTimes, OpenThread,
        THREAD_QUERY_LIMITED_INFORMATION,
    };

    let pid = unsafe { GetCurrentProcessId() };
    let snap = unsafe { CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0) };
    if snap == INVALID_HANDLE_VALUE || snap.is_null() {
        return serde_json::json!({"error": "CreateToolhelp32Snapshot failed"});
    }

    let mut entries: Vec<serde_json::Value> = Vec::new();
    let mut te: THREADENTRY32 = unsafe { std::mem::zeroed() };
    te.dwSize = std::mem::size_of::<THREADENTRY32>() as u32;

    let to_ns = |ft: FILETIME| -> u64 {
        let combined = ((ft.dwHighDateTime as u64) << 32) | (ft.dwLowDateTime as u64);
        combined.saturating_mul(100)
    };

    if unsafe { Thread32First(snap, &mut te) } != 0 {
        loop {
            if te.th32OwnerProcessID == pid {
                let h = unsafe {
                    OpenThread(THREAD_QUERY_LIMITED_INFORMATION, 0, te.th32ThreadID)
                };
                if !h.is_null() {
                    let mut creation = FILETIME {
                        dwLowDateTime: 0,
                        dwHighDateTime: 0,
                    };
                    let mut exit = FILETIME {
                        dwLowDateTime: 0,
                        dwHighDateTime: 0,
                    };
                    let mut kernel = FILETIME {
                        dwLowDateTime: 0,
                        dwHighDateTime: 0,
                    };
                    let mut user = FILETIME {
                        dwLowDateTime: 0,
                        dwHighDateTime: 0,
                    };
                    let ok = unsafe {
                        GetThreadTimes(h, &mut creation, &mut exit, &mut kernel, &mut user)
                    };

                    // GetThreadDescription returns a wide-char
                    // string allocated via LocalAlloc; we must
                    // LocalFree it.
                    // GetThreadDescription returns a buffer that
                    // must be freed with LocalFree. windows-sys's
                    // re-export path varies; declare directly.
                    unsafe extern "system" {
                        fn LocalFree(hMem: *mut std::ffi::c_void) -> *mut std::ffi::c_void;
                    }
                    let mut name_ptr: *mut u16 = std::ptr::null_mut();
                    let name = unsafe {
                        let _ = GetThreadDescription(h, &mut name_ptr);
                        if !name_ptr.is_null() {
                            let mut len = 0usize;
                            while *name_ptr.add(len) != 0 {
                                len += 1;
                            }
                            let slice = std::slice::from_raw_parts(name_ptr, len);
                            let s = String::from_utf16_lossy(slice);
                            LocalFree(name_ptr as *mut _);
                            s
                        } else {
                            format!("tid_{}", te.th32ThreadID)
                        }
                    };

                    if ok != 0 {
                        let user_ns = to_ns(user);
                        let kernel_ns = to_ns(kernel);
                        entries.push(serde_json::json!({
                            "tid": te.th32ThreadID,
                            "name": name,
                            "cpu_user_ns": user_ns,
                            "cpu_kernel_ns": kernel_ns,
                            "cpu_total_ns": user_ns + kernel_ns,
                        }));
                    }
                    unsafe { CloseHandle(h) };
                }
            }
            if unsafe { Thread32Next(snap, &mut te) } == 0 {
                break;
            }
        }
    }
    unsafe { CloseHandle(snap) };

    entries.sort_by_key(|v| {
        std::cmp::Reverse(v.get("cpu_total_ns").and_then(|x| x.as_u64()).unwrap_or(0))
    });
    serde_json::json!({"threads": entries})
}

/// Walk GObjects once and return a population summary:
///   - total entries / valid UObjects
///   - top N classes by instance count
///   - top N root-packages by hosted-object count (tells us
///     WHICH content path holds the leaking objects, not just
///     what class they are)
///   - loaded levels (Level / LevelStreaming) with name +
///     outer chain
///
/// Cost: O(N) over GObjects + O(D) outer-chain walk per obj
/// (D ~= 3-5). One pass; no extra walks.
pub fn game_population_json(top_n: usize) -> serde_json::Value {
    use std::collections::HashMap;
    let Some(rt) = crate::sdk::try_runtime() else {
        return serde_json::json!({"error": "sdk runtime unavailable"});
    };
    let view = unsafe {
        crate::sdk::GObjectsView::from_image(rt.image_base, rt.platform_offsets)
    };
    if !view.is_valid() {
        return serde_json::json!({"error": "gobjects view invalid"});
    }

    let mut total = 0usize;
    let mut valid = 0usize;
    let mut by_class: HashMap<String, usize> = HashMap::new();
    let mut by_package: HashMap<String, usize> = HashMap::new();
    let mut levels: Vec<serde_json::Value> = Vec::new();

    for obj in view.iter() {
        total += 1;
        valid += 1;
        let class_name = if let Some(class) = obj.class() {
            class.as_object().name()
        } else {
            String::from("<no-class>")
        };
        *by_class.entry(class_name.clone()).or_insert(0) += 1;

        // Walk Outer chain to the root. The topmost Outer is
        // typically a UPackage whose name is the asset path
        // (e.g. "/Game/Maps/AugustaWP"). Group objects by that
        // root.
        let mut root: Option<String> = None;
        let mut cur = obj.outer();
        let mut depth = 0;
        while let Some(o) = cur {
            if depth > 16 {
                break;
            }
            let next = o.outer();
            if next.is_none() {
                root = Some(o.name());
                break;
            }
            cur = next;
            depth += 1;
        }
        let root_name = root.unwrap_or_else(|| String::from("<no-package>"));
        *by_package.entry(root_name.clone()).or_insert(0) += 1;

        // Capture loaded levels and streaming markers. Cap at
        // 200 so a pathological case can't blow the response.
        if (class_name == "Level"
            || class_name == "LevelStreaming"
            || class_name == "LevelStreamingDynamic"
            || class_name == "LevelStreamingAlwaysLoaded"
            || class_name == "WorldPartitionRuntimeLevelStreamingCell"
            || class_name == "WorldPartitionRuntimeSpatialHashCell"
            || class_name.starts_with("LevelStreaming")
            || class_name.starts_with("WorldPartitionRuntime"))
            && levels.len() < 200
        {
            levels.push(serde_json::json!({
                "class": class_name,
                "name": obj.name(),
                "package": root_name,
            }));
        }
    }

    let mut classes_sorted: Vec<(String, usize)> = by_class.into_iter().collect();
    classes_sorted.sort_by(|a, b| b.1.cmp(&a.1));
    let top_classes: Vec<serde_json::Value> = classes_sorted
        .into_iter()
        .take(top_n)
        .map(|(name, count)| serde_json::json!({"class": name, "count": count}))
        .collect();

    let mut packages_sorted: Vec<(String, usize)> = by_package.into_iter().collect();
    packages_sorted.sort_by(|a, b| b.1.cmp(&a.1));
    let top_packages: Vec<serde_json::Value> = packages_sorted
        .into_iter()
        .take(top_n)
        .map(|(name, count)| serde_json::json!({"package": name, "hosted_count": count}))
        .collect();

    serde_json::json!({
        "gobjects_total": total,
        "gobjects_valid": valid,
        "top_classes": top_classes,
        "top_packages": top_packages,
        "loaded_levels": levels,
    })
}

/// For up to `k` instances of the named class, walk the Outer
/// chain and return the chain as a "root.outer.outer.name"
/// string. Used to find WHICH SoundWave / WHICH Package is
/// growing -- "SoundWave +144" is a class delta; this turns
/// it into specific asset paths.
///
/// `class_name` matches the short class name (e.g. "SoundWave").
/// Cost: O(N) over GObjects worst case until we find K matches.
pub fn game_class_outer_samples_json(class_name: &str, k: usize) -> serde_json::Value {
    let Some(rt) = crate::sdk::try_runtime() else {
        return serde_json::json!({"error": "sdk runtime unavailable"});
    };
    let view = unsafe {
        crate::sdk::GObjectsView::from_image(rt.image_base, rt.platform_offsets)
    };
    if !view.is_valid() {
        return serde_json::json!({"error": "gobjects view invalid"});
    }

    let mut samples: Vec<serde_json::Value> = Vec::new();
    let mut scanned = 0usize;
    let mut matched = 0usize;
    for obj in view.iter() {
        scanned += 1;
        let cls = match obj.class() {
            Some(c) => c.as_object().name(),
            None => continue,
        };
        if cls != class_name {
            continue;
        }
        matched += 1;
        if samples.len() >= k {
            // Keep counting matches even after we have enough
            // samples -- the count is data too.
            continue;
        }
        // Build "Root.Outer.Outer.Self" path. Cap depth.
        let mut parts: Vec<String> = Vec::new();
        parts.push(obj.name());
        let mut cur = obj.outer();
        let mut depth = 0;
        while let Some(o) = cur {
            if depth > 16 {
                break;
            }
            parts.push(o.name());
            cur = o.outer();
            depth += 1;
        }
        parts.reverse();
        samples.push(serde_json::json!({
            "full_path": parts.join("."),
            "name": obj.name(),
            "depth": depth + 1,
        }));
    }

    serde_json::json!({
        "class": class_name,
        "scanned_objects": scanned,
        "matched_count": matched,
        "samples_returned": samples.len(),
        "samples": samples,
    })
}

/// Process CPU time readings (user + kernel, in nanoseconds).
/// `GetProcessTimes` returns FILETIME (100-ns ticks); we
/// convert to nanoseconds. Diff over a window gives the
/// process's total CPU consumption. Compare against our
/// `TIME_NS_*` counters to compute our fractional load.
pub fn process_cpu_json() -> serde_json::Value {
    use windows_sys::Win32::Foundation::FILETIME;
    use windows_sys::Win32::System::Threading::{GetCurrentProcess, GetProcessTimes};

    let mut creation = FILETIME { dwLowDateTime: 0, dwHighDateTime: 0 };
    let mut exit = FILETIME { dwLowDateTime: 0, dwHighDateTime: 0 };
    let mut kernel = FILETIME { dwLowDateTime: 0, dwHighDateTime: 0 };
    let mut user = FILETIME { dwLowDateTime: 0, dwHighDateTime: 0 };
    let ok = unsafe {
        GetProcessTimes(
            GetCurrentProcess(),
            &mut creation,
            &mut exit,
            &mut kernel,
            &mut user,
        )
    };
    if ok == 0 {
        return serde_json::json!({"error": "GetProcessTimes failed"});
    }
    let to_ns = |ft: FILETIME| -> u64 {
        let combined = ((ft.dwHighDateTime as u64) << 32) | (ft.dwLowDateTime as u64);
        // FILETIME is 100-ns intervals.
        combined.saturating_mul(100)
    };
    serde_json::json!({
        "process_cpu_user_ns":   to_ns(user),
        "process_cpu_kernel_ns": to_ns(kernel),
        "process_cpu_total_ns":  to_ns(user) + to_ns(kernel),
    })
}

/// Process memory readings (Windows). Captured in the snapshot
/// so the perf test can compute deltas and detect leaks beyond
/// what our hot-path counters measure.
pub fn process_memory_json() -> serde_json::Value {
    use windows_sys::Win32::System::ProcessStatus::{
        GetProcessMemoryInfo, PROCESS_MEMORY_COUNTERS_EX,
    };
    use windows_sys::Win32::System::Threading::GetCurrentProcess;

    let mut info = std::mem::MaybeUninit::<PROCESS_MEMORY_COUNTERS_EX>::zeroed();
    let size = std::mem::size_of::<PROCESS_MEMORY_COUNTERS_EX>() as u32;
    let ok = unsafe {
        GetProcessMemoryInfo(
            GetCurrentProcess(),
            info.as_mut_ptr() as *mut _,
            size,
        )
    };
    if ok == 0 {
        return serde_json::json!({"error": "GetProcessMemoryInfo failed"});
    }
    let info = unsafe { info.assume_init() };
    serde_json::json!({
        "working_set_size":              info.WorkingSetSize          as u64,
        "peak_working_set_size":         info.PeakWorkingSetSize      as u64,
        "private_usage":                 info.PrivateUsage            as u64,
        "pagefile_usage":                info.PagefileUsage           as u64,
        "peak_pagefile_usage":           info.PeakPagefileUsage       as u64,
        "page_fault_count":              info.PageFaultCount          as u64,
        "quota_paged_pool_usage":        info.QuotaPagedPoolUsage     as u64,
        "quota_peak_paged_pool_usage":   info.QuotaPeakPagedPoolUsage as u64,
        "quota_non_paged_pool_usage":    info.QuotaNonPagedPoolUsage  as u64,
        "quota_peak_non_paged_pool_usage": info.QuotaPeakNonPagedPoolUsage as u64,
    })
}

/// Snapshot all counters as a JSON object. Called by debug::snapshot.
pub fn snapshot_json() -> serde_json::Value {
    serde_json::json!({
        "kill_hook_fires":                  KILL_HOOK_FIRES.load(Ordering::Relaxed),
        "kill_hook_player_fires":           KILL_HOOK_PLAYER_FIRES.load(Ordering::Relaxed),
        "kill_hook_owner_fullname_allocs":  KILL_HOOK_OWNER_FULLNAME_ALLOCS.load(Ordering::Relaxed),
        "kill_hook_log_lines":              KILL_HOOK_LOG_LINES.load(Ordering::Relaxed),
        "kill_hook_damagetype_name_allocs": KILL_HOOK_DAMAGETYPE_NAME_ALLOCS.load(Ordering::Relaxed),
        "fall_hook_fires":                  FALL_HOOK_FIRES.load(Ordering::Relaxed),
        "fall_hook_fnname_allocs":          FALL_HOOK_FNNAME_ALLOCS.load(Ordering::Relaxed),
        "drain_pending_calls":              DRAIN_PENDING_CALLS.load(Ordering::Relaxed),
        "drain_pending_drained_cmds":       DRAIN_PENDING_DRAINED_CMDS.load(Ordering::Relaxed),
        "damage_ring_pushes":               DAMAGE_RING_PUSHES.load(Ordering::Relaxed),
        "world_loader_polls":               WORLD_LOADER_POLLS.load(Ordering::Relaxed),
        "world_loader_gobjects_walks":      WORLD_LOADER_GOBJECTS_WALKS.load(Ordering::Relaxed),
        "imgui_tab_renders":                IMGUI_TAB_RENDERS.load(Ordering::Relaxed),
        "imgui_format_calls":               IMGUI_FORMAT_CALLS.load(Ordering::Relaxed),
        "bbp_log_lines":                    BBP_LOG_LINES.load(Ordering::Relaxed),
        "bbp_log_fsyncs":                   BBP_LOG_FSYNCS.load(Ordering::Relaxed),
        "http_requests":                    HTTP_REQUESTS.load(Ordering::Relaxed),
        "damage_ring_peak":                 DAMAGE_RING_PEAK.load(Ordering::Relaxed),
        "pe_queue_peak":                    PE_QUEUE_PEAK.load(Ordering::Relaxed),
        // CPU time spent in our hot paths (cumulative ns).
        "time_ns_kill_hook":                TIME_NS_KILL_HOOK.load(Ordering::Relaxed),
        "time_ns_fall_hook":                TIME_NS_FALL_HOOK.load(Ordering::Relaxed),
        "time_ns_drain_pending":            TIME_NS_DRAIN_PENDING.load(Ordering::Relaxed),
        "time_ns_bbp_log":                  TIME_NS_BBP_LOG.load(Ordering::Relaxed),
        "time_ns_imgui_get_xp":             TIME_NS_IMGUI_GET_XP.load(Ordering::Relaxed),
        "time_ns_format_skill_effect":      TIME_NS_FORMAT_SKILL_EFFECT.load(Ordering::Relaxed),
        "time_ns_http_handle":              TIME_NS_HTTP_HANDLE.load(Ordering::Relaxed),
    })
}
