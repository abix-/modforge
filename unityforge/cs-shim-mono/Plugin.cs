// Plugin.cs. BepInEx entry. Loads the Rust cdylib next to this
// DLL, calls unityforge_init with a function-pointer bridge,
// then drives unityforge_tick from a MonoBehaviour's Update.

using System;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
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

        /// <summary>
        /// Name of the Rust cdylib to load. Override by setting
        /// the UNITYFORGE_TARGET env var before launching the
        /// game, otherwise we autodetect a single *.unityforge.dll
        /// next to this plugin.
        /// </summary>
        private const string TargetEnv = "UNITYFORGE_TARGET";

        // P/Invoke targets resolved by GetProcAddress at runtime.
        private delegate int UnityforgeInitFn(IntPtr bridge);
        private delegate void UnityforgeTickFn(float now);
        private delegate void UnityforgeShutdownFn();

        private IntPtr _rustModule;
        private UnityforgeInitFn _init;
        private UnityforgeTickFn _tick;
        private UnityforgeShutdownFn _shutdown;
        private BridgeTable _bridge;
        private GCHandle _bridgeHandle;
        private bool _started;

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
            ShimLogger.Source.LogInfo("Unityforge.Shim: loading " + dllPath);

            _rustModule = NativeLibrary.Load(dllPath);
            if (_rustModule == IntPtr.Zero)
            {
                ShimLogger.Source.LogError("Unityforge.Shim: LoadLibrary failed: " + Marshal.GetLastWin32Error());
                return;
            }
            _init = ResolveSymbol<UnityforgeInitFn>("unityforge_init");
            _tick = ResolveSymbol<UnityforgeTickFn>("unityforge_tick");
            _shutdown = ResolveSymbol<UnityforgeShutdownFn>("unityforge_shutdown");
            if (_init == null || _tick == null || _shutdown == null)
            {
                ShimLogger.Source.LogError("Unityforge.Shim: target DLL is missing one of unityforge_init / unityforge_tick / unityforge_shutdown");
                return;
            }

            HarmonyBridge.EnsureHarmony(PluginGuid);

            _bridge = Bridge.Build(new MonoBackendBridge());
            _bridgeHandle = GCHandle.Alloc(_bridge, GCHandleType.Pinned);
            try
            {
                int rc = _init(_bridgeHandle.AddrOfPinnedObject());
                if (rc != 0)
                {
                    ShimLogger.Source.LogError("Unityforge.Shim: unityforge_init returned " + rc);
                    return;
                }
            }
            catch (Exception e)
            {
                ShimLogger.Source.LogError("Unityforge.Shim: unityforge_init threw: " + e);
                return;
            }
            _started = true;
            ShimLogger.Source.LogInfo("Unityforge.Shim: ready");
        }

        private void Update()
        {
            if (!_started) return;
            try { _tick(Time.realtimeSinceStartup); }
            catch (Exception e) { ShimLogger.Source.LogError("Unityforge.Shim: tick threw: " + e); }
        }

        private void OnDestroy()
        {
            if (!_started) return;
            try { _shutdown(); }
            catch (Exception e) { ShimLogger.Source.LogError("Unityforge.Shim: shutdown threw: " + e); }
            if (_bridgeHandle.IsAllocated) _bridgeHandle.Free();
            if (_rustModule != IntPtr.Zero) NativeLibrary.Free(_rustModule);
            _started = false;
        }

        private string LocateRustDll()
        {
            var explicitTarget = Environment.GetEnvironmentVariable(TargetEnv);
            if (!string.IsNullOrEmpty(explicitTarget) && File.Exists(explicitTarget))
                return explicitTarget;
            var dir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            if (string.IsNullOrEmpty(dir)) return null;
            // Convention: <mod>.unityforge.dll next to the shim.
            var candidates = Directory.GetFiles(dir, "*.unityforge.dll");
            if (candidates.Length == 1) return candidates[0];
            return null;
        }

        private T ResolveSymbol<T>(string name) where T : class
        {
            if (!NativeLibrary.TryGetExport(_rustModule, name, out var addr) || addr == IntPtr.Zero)
                return null;
            return Marshal.GetDelegateForFunctionPointer(addr, typeof(T)) as T;
        }
    }

    // NativeLibrary is .NET 5+; netstandard2.1 doesn't have it.
    // Provide a tiny shim against the Win32 LoadLibrary entrypoints.
    internal static class NativeLibrary
    {
        [DllImport("kernel32", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern IntPtr LoadLibraryW(string path);
        [DllImport("kernel32", SetLastError = true, CharSet = CharSet.Ansi)]
        private static extern IntPtr GetProcAddress(IntPtr module, string name);
        [DllImport("kernel32", SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool FreeLibrary(IntPtr module);

        public static IntPtr Load(string path) => LoadLibraryW(path);
        public static void Free(IntPtr module) { if (module != IntPtr.Zero) FreeLibrary(module); }
        public static bool TryGetExport(IntPtr module, string name, out IntPtr addr)
        {
            addr = GetProcAddress(module, name);
            return addr != IntPtr.Zero;
        }
    }
}
