// Plugin.cs. BepInEx entry. Loads the Rust cdylib next to this
// DLL, calls unityforge_init with a function-pointer bridge,
// then drives unityforge_tick from a MonoBehaviour's Update.
//
// Hot reload: generation-versioned. Each iteration drops a
// `*.gen<N>.dll` next to the canonical DLL. The shim's
// per-second watcher picks it up, calls `unityforge_shutdown`
// on the active generation (which runs the modforge shutdown
// registry. HTTP server unblock + slot poller wake + thread
// joins. So all background threads exit before we proceed),
// then `LoadLibrary`s the new generation, calls its
// `unityforge_init`, and switches active. The OLD module is
// never FreeLibrary'd; the OS unmaps it on its own schedule
// once nothing references it.
//
// See docs/unityforge-plan.md section 6.5 "Hot reload" for the
// full design + rationale.

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;
using BepInEx;
using UnityEngine;

namespace Unityforge.Shim
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public class UnityforgeShimPlugin : BaseUnityPlugin
    {
        public const string PluginGuid = "abix.unityforge.shim";
        public const string PluginName = "Unityforge.Shim";
        public const string PluginVersion = "0.1.0";

        private const string TargetEnv = "UNITYFORGE_TARGET";

        // P/Invoke targets resolved by GetProcAddress at runtime.
        private delegate int UnityforgeInitFn(IntPtr bridge);
        private delegate void UnityforgeTickFn(float now);
        private delegate void UnityforgeShutdownFn();

        /// <summary>
        /// One loaded image of the Rust cdylib. The shim
        /// holds at most one active generation at a time; old
        /// generations are dropped from `_quiesced` once their
        /// background threads have been signaled to stop and
        /// joined (by `_shutdown()`). We never FreeLibrary.
        /// the OS unmaps the image once nothing references
        /// its code segment.
        /// </summary>
        private class Generation
        {
            public int N;                                 // 0 = initial, then 1, 2, ...
            public string Path;
            public IntPtr Module;
            public UnityforgeInitFn Init;
            public UnityforgeTickFn Tick;
            public UnityforgeShutdownFn Shutdown;
            public BridgeTable Bridge;
            public GCHandle BridgeHandle;                 // pinned pointer passed to Rust
        }

        private Generation _active;
        private readonly List<Generation> _quiesced = new List<Generation>();
        private string _canonicalDir;
        private string _canonicalDllPath;
        private float _lastReloadCheck;
        private const float ReloadCheckIntervalSec = 1.0f;
        private static readonly Regex GenFilenameRe = new Regex(
            @"\.gen(\d+)\.dll$", RegexOptions.IgnoreCase);

        private void Awake()
        {
            ShimLogger.Source = base.Logger;
            ShimLogger.Source.LogInfo("Unityforge.Shim: Awake");

            var dllPath = LocateRustDll();
            if (dllPath == null)
            {
                ShimLogger.Source.LogError("Unityforge.Shim: no Rust target DLL found. Set " + TargetEnv + " or drop a *.unityforge.dll next to this plugin.");
                return;
            }
            _canonicalDllPath = dllPath;
            _canonicalDir = Path.GetDirectoryName(dllPath);
            ShimLogger.Source.LogInfo("Unityforge.Shim: loading " + dllPath);

            HarmonyBridge.EnsureHarmony(PluginGuid);

            // WWM-specific: block the demo-end panel by patching
            // DemoCompleteScreenUI.Show with a static prefix that
            // returns false. The Rust-side patch path uses an
            // instance-method bridge which HarmonyX rejects; until
            // that lands, this direct shim-side patch unblocks
            // gameplay so the demo screen never opens.
            InstallDemoCompleteBlock();

            _active = LoadGeneration(dllPath, generationNumber: 0);
            if (_active == null)
            {
                ShimLogger.Source.LogError("Unityforge.Shim: initial generation failed to load");
                return;
            }
            ShimLogger.Source.LogInfo("Unityforge.Shim: ready (generation 0)");
        }

        private static void InstallDemoCompleteBlock()
        {
            try
            {
                // The trigger that opens the demo-end panel is a
                // Unity-asset-level event call to
                // `DemoCompleteScreen.SetActive(true)` (no managed
                // code on the controller is involved). Patching
                // GameObject.SetActive itself, with a cheap name
                // check, is the only sound interception point.
                if (_wwmHarmony == null)
                    _wwmHarmony = new HarmonyLib.Harmony("abix.unityforge.shim.wwmblock");
                var setActive = HarmonyLib.AccessTools.Method(
                    typeof(UnityEngine.GameObject), "SetActive",
                    new Type[] { typeof(bool) });
                if (setActive == null)
                {
                    ShimLogger.Source?.LogError("WWM block: GameObject.SetActive not found");
                    return;
                }
                _wwmHarmony.Patch(setActive, prefix: new HarmonyLib.HarmonyMethod(
                    typeof(UnityforgeShimPlugin),
                    nameof(BlockDemoComplete_SetActivePrefix)));
                ShimLogger.Source?.LogInfo("WWM block: patched GameObject.SetActive (filter name==DemoCompleteScreen)");
            }
            catch (Exception e)
            {
                ShimLogger.Source?.LogError("WWM block: install threw: " + e);
            }
        }

        // Filters on name to keep the per-frame overhead at a
        // ~50ns string compare. Returns true (run original) for
        // every call except activating DemoCompleteScreen.
        public static bool BlockDemoComplete_SetActivePrefix(
            UnityEngine.GameObject __instance, bool value)
        {
            if (value && __instance != null && __instance.name == "DemoCompleteScreen")
            {
                ShimLogger.Source?.LogInfo(
                    "WWM block: blocked SetActive(true) on DemoCompleteScreen");
                return false;
            }
            return true;
        }

        private static bool _demoBlockInstalled;
        private static void OnSceneLoadedTryBlock(
            UnityEngine.SceneManagement.Scene scene,
            UnityEngine.SceneManagement.LoadSceneMode mode)
        {
            if (_demoBlockInstalled) return;
            try
            {
                var t = TypeCache.Resolve("DemoCompleteScreenUI");
                if (t == null) return;
                DoPatch(t);
                _demoBlockInstalled = true;
                UnityEngine.SceneManagement.SceneManager.sceneLoaded -= OnSceneLoadedTryBlock;
            }
            catch (Exception e)
            {
                ShimLogger.Source?.LogError("WWM block: scene-load retry threw: " + e);
            }
        }

        private static HarmonyLib.Harmony _wwmHarmony;
        private static readonly string[] _wwmTargetMethods = new[]
        {
            "Update", "Show", "FocusCoroutine",
            "GetEscapeButtonName", "UpdateEscape",
        };

        private static void DoPatch(Type t)
        {
            if (_wwmHarmony == null)
                _wwmHarmony = new HarmonyLib.Harmony("abix.unityforge.shim.wwmblock");
            int patched = 0;
            foreach (var name in _wwmTargetMethods)
            {
                try
                {
                    var m = HarmonyLib.AccessTools.Method(t, name);
                    if (m == null)
                    {
                        ShimLogger.Source?.LogWarning($"WWM block: method {name} not found");
                        continue;
                    }
                    _wwmHarmony.Patch(m, prefix: new HarmonyLib.HarmonyMethod(
                        typeof(UnityforgeShimPlugin), nameof(BlockDemoComplete_UpdatePrefix)));
                    ShimLogger.Source?.LogInfo($"WWM block: patched {name}");
                    patched++;
                }
                catch (Exception e)
                {
                    ShimLogger.Source?.LogError($"WWM block: patch {name} threw: " + e);
                }
            }
            _demoBlockInstalled = patched > 0;
            ShimLogger.Source?.LogInfo($"WWM block: total patched = {patched}");
        }

        // Universal prefix used for every patched method on
        // DemoCompleteScreenUI. Whichever method fires first
        // deactivates the panel GameObject and stops the original
        // from running. The first log line tells us which method
        // Unity actually invokes; that diagnostic is the point.
        public static bool BlockDemoComplete_UpdatePrefix(
            UnityEngine.MonoBehaviour __instance,
            System.Reflection.MethodBase __originalMethod)
        {
            try
            {
                string mname = __originalMethod != null ? __originalMethod.Name : "<unknown>";
                ShimLogger.Source?.LogInfo($"WWM block: intercepted {mname}() on DemoCompleteScreenUI");
                if (__instance != null && __instance.gameObject != null
                    && __instance.gameObject.activeSelf)
                {
                    __instance.gameObject.SetActive(false);
                    ShimLogger.Source?.LogInfo("WWM block: deactivated DemoCompleteScreen GameObject");
                }
            }
            catch (Exception e)
            {
                ShimLogger.Source?.LogError("WWM block: prefix threw: " + e);
            }
            return false; // skip original
        }

        private void Update()
        {
            if (_active == null) return;
            InputBridge.PollAll();
            CheckHotReload();
            if (_active == null) return; // reload may have left us unactive
            try { _active.Tick(Time.realtimeSinceStartup); }
            catch (Exception e) { ShimLogger.Source.LogError("Unityforge.Shim: tick threw: " + e); }
        }

        private void OnDestroy()
        {
            if (_active != null)
            {
                try { _active.Shutdown(); }
                catch (Exception e) { ShimLogger.Source.LogError("Unityforge.Shim: shutdown threw: " + e); }
                if (_active.BridgeHandle.IsAllocated) _active.BridgeHandle.Free();
                _active = null;
            }
            foreach (var g in _quiesced)
            {
                if (g.BridgeHandle.IsAllocated) g.BridgeHandle.Free();
            }
            _quiesced.Clear();
            // Intentionally NO FreeLibrary calls. Process exit
            // unmaps everything; before that, old generations'
            // threads may still be exiting on stop signals.
        }

        // ---- hot reload --------------------------------------------------

        private void CheckHotReload()
        {
            var now = Time.realtimeSinceStartup;
            if (now - _lastReloadCheck < ReloadCheckIntervalSec) return;
            _lastReloadCheck = now;
            if (string.IsNullOrEmpty(_canonicalDir)) return;

            // Find the highest .gen<N>.dll in the plugin dir.
            // We swap to whichever generation is newest on disk
            // higher than the active one. Lower-numbered files
            // are ignored (stale staging from a prior run).
            string[] candidates;
            try { candidates = Directory.GetFiles(_canonicalDir, "*.gen*.dll"); }
            catch { return; }

            int bestN = _active.N;
            string bestPath = null;
            foreach (var c in candidates)
            {
                var m = GenFilenameRe.Match(c);
                if (!m.Success) continue;
                if (!int.TryParse(m.Groups[1].Value, out var n)) continue;
                if (n > bestN) { bestN = n; bestPath = c; }
            }
            if (bestPath == null) return;

            ShimLogger.Source.LogInfo(
                $"Unityforge.Shim: hot reload generation {_active.N} -> {bestN}");
            HotSwap(bestN, bestPath);
        }

        private void HotSwap(int newGen, string newPath)
        {
            var old = _active;

            // Step 1: stop ticking the old generation. We do
            // this BEFORE touching the new image so a long shim
            // shutdown doesn't double-fire ops while new is
            // half-init.
            _active = null;

            // Step 2: graceful shutdown on the old generation.
            // This runs the Rust SHUTDOWN_REGISTRY which:
            //  - server::shutdown_all unblocks tiny_http and
            //    joins the listener thread
            //  - rpg::poller::shutdown_all wakes the poller's
            //    condvar and joins
            //  - HOOK_REGISTRY.shutdown_all unpatches Harmony
            // After this call returns, no Rust thread from the
            // old generation should be executing in its code
            // segment.
            try { old.Shutdown(); }
            catch (Exception e)
            {
                ShimLogger.Source.LogError(
                    $"Unityforge.Shim: old gen {old.N} shutdown threw: " + e);
                // Continue anyway. Threads MAY still be
                // exiting; we just don't FreeLibrary so the
                // worst case is they finish executing into a
                // still-mapped image.
            }

            // Step 3: clear input bindings + handle table.
            // Harmony patches were already unpatched per-handle
            // by Rust's HOOK_REGISTRY.shutdown_all (which calls
            // back into HarmonyBridge.Unpatch for each one).
            // Calling _harmony.UnpatchSelf() here in addition
            // tries to detour-back already-cleaned methods and
            // hits "IL Compile Error" inside HarmonyX. Skip it;
            // the per-handle path is sufficient and the
            // _patches dictionary is already empty.
            InputBridge.Clear();
            MonoBridge.ClearHandles();

            // Step 4: park the old generation in `_quiesced`.
            // We keep its module mapped (no FreeLibrary) so any
            // stray thread that didn't quite finish exiting can
            // still run its last instructions safely.
            _quiesced.Add(old);

            // Step 5: load the new image.
            var fresh = LoadGeneration(newPath, newGen);
            if (fresh == null)
            {
                ShimLogger.Source.LogError(
                    $"Unityforge.Shim: gen {newGen} failed to load; rolling back");
                // Re-arm the old generation. Its threads are
                // gone but the code is still mapped; we can
                // call init again.
                _quiesced.Remove(old);
                try
                {
                    int rc = old.Init(old.BridgeHandle.AddrOfPinnedObject());
                    if (rc == 0)
                    {
                        _active = old;
                        return;
                    }
                }
                catch (Exception e)
                {
                    ShimLogger.Source.LogError(
                        $"Unityforge.Shim: rollback re-init threw: " + e);
                }
                return;
            }

            _active = fresh;
            ShimLogger.Source.LogInfo(
                $"Unityforge.Shim: hot reload complete (now generation {newGen}; {_quiesced.Count} draining)");
        }

        private Generation LoadGeneration(string path, int generationNumber)
        {
            var module = NativeLibrary.Load(path);
            if (module == IntPtr.Zero)
            {
                ShimLogger.Source.LogError(
                    $"Unityforge.Shim: LoadLibrary failed for {path}: " + Marshal.GetLastWin32Error());
                return null;
            }
            var gen = new Generation { N = generationNumber, Path = path, Module = module };
            gen.Init = ResolveSymbol<UnityforgeInitFn>(module, "unityforge_init");
            gen.Tick = ResolveSymbol<UnityforgeTickFn>(module, "unityforge_tick");
            gen.Shutdown = ResolveSymbol<UnityforgeShutdownFn>(module, "unityforge_shutdown");
            if (gen.Init == null || gen.Tick == null || gen.Shutdown == null)
            {
                ShimLogger.Source.LogError(
                    $"Unityforge.Shim: gen {generationNumber} DLL is missing one of unityforge_init / unityforge_tick / unityforge_shutdown");
                return null;
            }

            // Each generation gets its own pinned BridgeTable
            // instance. The function pointers inside point at
            // the same shared C# delegates; the struct itself
            // lives separately so the Rust side's pointer
            // stays valid for the lifetime of that generation.
            gen.Bridge = Bridge.Build(new MonoBackendBridge());
            gen.BridgeHandle = GCHandle.Alloc(gen.Bridge, GCHandleType.Pinned);

            try
            {
                int rc = gen.Init(gen.BridgeHandle.AddrOfPinnedObject());
                if (rc != 0)
                {
                    ShimLogger.Source.LogError(
                        $"Unityforge.Shim: gen {generationNumber} unityforge_init returned " + rc);
                    if (gen.BridgeHandle.IsAllocated) gen.BridgeHandle.Free();
                    return null;
                }
            }
            catch (Exception e)
            {
                ShimLogger.Source.LogError(
                    $"Unityforge.Shim: gen {generationNumber} unityforge_init threw: " + e);
                if (gen.BridgeHandle.IsAllocated) gen.BridgeHandle.Free();
                return null;
            }
            return gen;
        }

        private string LocateRustDll()
        {
            var explicitTarget = Environment.GetEnvironmentVariable(TargetEnv);
            if (!string.IsNullOrEmpty(explicitTarget) && File.Exists(explicitTarget))
                return explicitTarget;
            var dir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            if (string.IsNullOrEmpty(dir)) return null;
            // Canonical name is `*.unityforge.dll` (not
            // `*.unityforge.gen<N>.dll`). The generation files
            // are picked up by the hot-reload watcher, not at
            // initial load.
            var candidates = Directory.GetFiles(dir, "*.unityforge.dll")
                .Where(f => !GenFilenameRe.IsMatch(f))
                .ToArray();
            if (candidates.Length == 1) return candidates[0];
            return null;
        }

        private T ResolveSymbol<T>(IntPtr module, string name) where T : class
        {
            if (!NativeLibrary.TryGetExport(module, name, out var addr) || addr == IntPtr.Zero)
                return null;
            return Marshal.GetDelegateForFunctionPointer(addr, typeof(T)) as T;
        }
    }

    internal static class NativeLibrary
    {
        [DllImport("kernel32", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern IntPtr LoadLibraryW(string path);
        [DllImport("kernel32", SetLastError = true, CharSet = CharSet.Ansi)]
        private static extern IntPtr GetProcAddress(IntPtr module, string name);

        public static IntPtr Load(string path) => LoadLibraryW(path);
        public static bool TryGetExport(IntPtr module, string name, out IntPtr addr)
        {
            addr = GetProcAddress(module, name);
            return addr != IntPtr.Zero;
        }
        // No Free(): generation-versioned loading never
        // FreeLibrary's an old image.
    }
}
