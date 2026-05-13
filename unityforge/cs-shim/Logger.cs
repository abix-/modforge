// Logger.cs. Forwards Rust log lines to BepInEx's ManualLogSource.

using System;
using System.Runtime.InteropServices;
using BepInEx.Logging;

namespace Unityforge.Shim
{
    public static class Logger
    {
        public static ManualLogSource Source;

        public delegate void EmitFn(int level, IntPtr msgUtf8);

        // The delegate field must be static so the GC doesn't
        // collect it before Rust calls back.
        public static readonly EmitFn EmitDelegate = Emit;

        private static void Emit(int level, IntPtr msgUtf8)
        {
            if (Source == null) return;
            var msg = Marshal.PtrToStringAnsi(msgUtf8) ?? "<null>";
            switch (level)
            {
                case 0: Source.LogDebug(msg); break;
                case 1: Source.LogDebug(msg); break;
                case 2: Source.LogInfo(msg); break;
                case 3: Source.LogWarning(msg); break;
                case 4: Source.LogError(msg); break;
                default: Source.LogInfo(msg); break;
            }
        }
    }
}
