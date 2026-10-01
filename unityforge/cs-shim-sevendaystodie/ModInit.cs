// ModInit.cs. 7 Days To Die official-loader host.
//
// The game's Mod.LoadAssemblies() Assembly.LoadFrom's every *.dll
// at the TOP of the mod folder (SdDirectory.GetFiles, not
// recursive), and one that fails to load fails the whole mod. Then
// Mod.InitModCode() creates every IModApi type it finds and calls
// InitMod(Mod) once, on the Unity main thread.
//
// So the Rust cdylib (*.unityforge.dll) sits in the native/
// subfolder, out of the loader's reach.
//
// Harmony is the HarmonyX the game loads from Mods/0_TFP_Harmony,
// which sorts and loads before this mod.

using System.IO;
using UnityEngine;
using Unityforge.Shim;

public class UnityforgeModInit : IModApi
{
    private static GenerationLoader _loader;

    public void InitMod(Mod _modInstance)
    {
        ShimLogger.Sink = (level, msg) =>
        {
            switch (level)
            {
                case 3: Debug.LogWarning("[Unityforge] " + msg); break;
                case 4: Debug.LogError("[Unityforge] " + msg); break;
                default: Debug.Log("[Unityforge] " + msg); break;
            }
        };

        ShimLogger.Info("Unityforge.Shim: InitMod (7 Days To Die official loader)");

        var nativeDir = Path.Combine(_modInstance.Path, "native");
        var dllPath = GenerationLoader.LocateRustDll(nativeDir);
        if (dllPath == null)
        {
            ShimLogger.Error("Unityforge.Shim: no Rust target DLL found. Set "
                + GenerationLoader.TargetEnv
                + " or drop exactly one *.unityforge.dll in: " + nativeDir);
            return;
        }

        HarmonyBridge.AcquireHandle = MonoBridge.Acquire;
        HarmonyBridge.LookupHandle = MonoBridge.Lookup;
        HarmonyBridge.EnsureHarmony("abix.unityforge.shim.sevendaystodie");

        var loader = new GenerationLoader(new MonoBackendBridge(), MonoBridge.ClearHandles);
        if (!loader.LoadInitial(dllPath))
        {
            ShimLogger.Error("Unityforge.Shim: initial generation failed to load");
            return;
        }
        _loader = loader;
        // Process teardown: run the active generation's undos (its
        // listener releases the port, threads join).
        Application.quitting += () => _loader?.ShutdownFinal();

        var driverGo = new GameObject("Unityforge.SevenDaysToDieDriver");
        Object.DontDestroyOnLoad(driverGo);
        driverGo.AddComponent<SevenDaysToDieDriver>();
        ShimLogger.Info("Unityforge.Shim: ready (generation 0)");
    }

    internal static void DriverUpdate()
    {
        var loader = _loader;
        if (loader == null || !loader.Active) return;
        InputBridge.PollAll();
        loader.Tick(Time.realtimeSinceStartup);
    }
}

/// <summary>
/// Persistent MonoBehaviour that drives the per-frame tick
/// (input poll + hot-reload check + unityforge_tick). Created once
/// by UnityforgeModInit.InitMod.
/// </summary>
public class SevenDaysToDieDriver : MonoBehaviour
{
    private void Update()
    {
        UnityforgeModInit.DriverUpdate();
    }
}
