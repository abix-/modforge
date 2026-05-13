// Bridge.cs. The function-pointer table passed to Rust at init.
//
// Layout MUST match unityforge/src/bridge.rs `BridgeTable`
// exactly. Add fields at the END only; never reorder. Bump
// BRIDGE_VERSION on the Rust side AND here in lockstep.

using System;
using System.Runtime.InteropServices;

namespace Unityforge.Shim
{
    public static class BridgeConstants
    {
        public const uint Magic = 0x52424655u; // "UFBR"
        public const uint Version = 1u;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct BridgeTable
    {
        public uint Magic;
        public uint Version;

        // logging
        public IntPtr LogEmit;

        // mono reflection
        public IntPtr MonoFindType;
        public IntPtr MonoSingletonInstance;
        public IntPtr MonoStaticInstance;
        public IntPtr MonoWalkClass;
        public IntPtr MonoInspectObject;
        public IntPtr MonoReadField;
        public IntPtr MonoWriteField;
        public IntPtr MonoInvokeMethod;
        public IntPtr MonoReleaseHandle;

        // harmony
        public IntPtr HarmonyPatchPrefix;
        public IntPtr HarmonyPatchPostfix;
        public IntPtr HarmonyUnpatch;
    }

    /// <summary>
    /// Builds the bridge struct from the static methods in
    /// MonoBridge + HarmonyBridge + Logger. Called once at init.
    /// The returned BridgeTable contains delegate pointers that
    /// must remain rooted for the lifetime of the plugin (the
    /// static class fields keep them alive).
    /// </summary>
    public static class Bridge
    {
        public static BridgeTable Build()
        {
            return new BridgeTable
            {
                Magic = BridgeConstants.Magic,
                Version = BridgeConstants.Version,

                LogEmit = Marshal.GetFunctionPointerForDelegate(Logger.EmitDelegate),

                MonoFindType = Marshal.GetFunctionPointerForDelegate(MonoBridge.FindTypeDelegate),
                MonoSingletonInstance = Marshal.GetFunctionPointerForDelegate(MonoBridge.SingletonInstanceDelegate),
                MonoStaticInstance = Marshal.GetFunctionPointerForDelegate(MonoBridge.StaticInstanceDelegate),
                MonoWalkClass = Marshal.GetFunctionPointerForDelegate(MonoBridge.WalkClassDelegate),
                MonoInspectObject = Marshal.GetFunctionPointerForDelegate(MonoBridge.InspectObjectDelegate),
                MonoReadField = Marshal.GetFunctionPointerForDelegate(MonoBridge.ReadFieldDelegate),
                MonoWriteField = Marshal.GetFunctionPointerForDelegate(MonoBridge.WriteFieldDelegate),
                MonoInvokeMethod = Marshal.GetFunctionPointerForDelegate(MonoBridge.InvokeMethodDelegate),
                MonoReleaseHandle = Marshal.GetFunctionPointerForDelegate(MonoBridge.ReleaseHandleDelegate),

                HarmonyPatchPrefix = Marshal.GetFunctionPointerForDelegate(HarmonyBridge.PatchPrefixDelegate),
                HarmonyPatchPostfix = Marshal.GetFunctionPointerForDelegate(HarmonyBridge.PatchPostfixDelegate),
                HarmonyUnpatch = Marshal.GetFunctionPointerForDelegate(HarmonyBridge.UnpatchDelegate),
            };
        }
    }
}
