// HarmonyBridge.cs. Exposes Harmony patch operations to Rust as
// function pointers.
//
// Rust passes an unmanaged `extern "C" fn` pointer for the
// prefix/postfix body. We wrap it in a managed delegate via
// Marshal.GetDelegateForFunctionPointer and route each call
// through a PRE-COMPILED STATIC SLOT METHOD (one slot per live
// patch).
//
// Why slots (iteration history, all live-verified 2026-07-04 on
// Survivalist: Invisible Strain, Unity 6000 Mono + official
// pardeike Harmony 2.0.4):
//   1. `new Action(() => del(...)).Method` as the Harmony target
//      is an instance method on a closure class; HarmonyLib
//      rejects it. Every Rust patch silently failed.
//   2. One shared static dispatcher routed by `MethodBase
//      __originalMethod` compiles, but Harmony 2.0.4 emits
//      `Ldtoken original` + `Call MethodBase.GetMethodFromHandle`
//      for that parameter (MethodPatcher.cs at tag v2.0.4.0), and
//      the game's Mono cannot resolve that call token inside the
//      dynamic wrapper: "Invalid IL code in (wrapper
//      dynamic-method) ... IL_001e: call 0x00000005".
//   3. `object[] __args` does not exist in 2.0.4 at all (parses
//      as an invalid indexed parameter).
// The slot signatures below use ONLY parameter emissions that are
// plain `ldarg` loads with zero metadata tokens (verified against
// MethodPatcher.cs v2.0.4.0): no parameters, `object __instance`,
// or `object __0`. That is the same shape the game's working mods
// (DisableHUD, SISLootRespawn) use.
//
// Patch kinds:
//   - prefix:  Rust int(IntPtr). Non-zero return = skip the
//     original (matches unityforge/src/hook.rs). ctx = 0.
//   - postfix: Rust void(IntPtr). ctx = 0.
//   - prefix_ctx (bridge v5): Rust int(IntPtr) where the pointer
//     carries a FRESH object handle: ctxKind 0 = __instance
//     (instance methods only), ctxKind 1 = args[0]
//     (REFERENCE-type first argument only; indexed args are
//     loaded as-is with no boxing, so a value-type first arg
//     would produce invalid IL). The Rust callback OWNS the
//     handle and must release it (MonoObject::from_handle +
//     Drop). Zero when the context object is null. One Rust
//     callback patched onto many methods shares one slot.
//   - postfix_float_result (bridge v8): Rust float(IntPtr, IntPtr,
//     float) on a method returning float. Receives a FRESH
//     __instance handle (0 for static methods), the arguments as
//     JSON (same convention as prefix_instance_args; handles in it
//     are owned by the callback too), and the original result, and
//     returns the result the caller sees. Slot signature
//     `object __instance, object[] __args, ref float __result`.
//   - postfix_int_result (bridge v9): the same for a method
//     returning int, plus an argument filter checked here before
//     anything crosses to Rust: JSON {"<arg index>": value}, value a
//     number (enum or integer argument) or bool. The Rust callback
//     runs only when every listed argument matches, so a patch on a
//     hot method costs a few comparisons on the calls it skips.
//   - postfix_result (bridge v10): the same for a method of ANY
//     return type. Slot signature `object __instance, object[]
//     __args, ref object __result` (Harmony boxes a value-type
//     result). The result crosses as JSON in the ArgToJson
//     convention; the Rust callback writes a replacement into the
//     output buffer (JSON; {"$handle": N} for a live object) and
//     returns its length, or -1 to keep the original. Same argument
//     filter as postfix_int_result.

using System;
using System.Collections.Generic;
using System.Reflection;
using System.Runtime.InteropServices;
using HarmonyLib;

namespace Unityforge.Shim
{
    public static class HarmonyBridge
    {
        private const int SlotsPerKind = 16;

        private static readonly object _lock = new object();
        private static readonly Dictionary<int, PatchEntry> _patches = new Dictionary<int, PatchEntry>();
        private static int _next = 1;
        // Fully qualified: MelonLoader's 0Harmony also exports a
        // legacy `Harmony` NAMESPACE, so the bare name resolves to
        // the namespace there (CS0118).
        private static HarmonyLib.Harmony _harmony;

        // delegate signatures matching the Rust extern "C" fns
        private delegate int RustPrefixDelegate(IntPtr ctx);
        private delegate void RustPostfixDelegate(IntPtr ctx);
        private delegate int RustPrefixInstanceArgsDelegate(IntPtr instance, IntPtr argsJsonUtf8);
        private delegate float RustPostfixFloatResultDelegate(IntPtr instance, IntPtr argsJsonUtf8, float result);
        private delegate int RustPostfixIntResultDelegate(IntPtr instance, IntPtr argsJsonUtf8, int result);
        private delegate int RustPostfixResultDelegate(IntPtr instance, IntPtr argsJsonUtf8, IntPtr resultJsonUtf8, IntPtr outUtf8, int outCap);

        public delegate int PatchPrefixFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr);
        public delegate int PatchPostfixFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr);
        public delegate int PatchPrefixCtxFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, int ctxKind, IntPtr rustFnPtr);
        public delegate int PatchPrefixInstanceArgsFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr);
        public delegate int PatchPostfixFloatResultFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr);
        public delegate int PatchPostfixIntResultFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr filterJsonUtf8, IntPtr rustFnPtr);
        public delegate int PatchPostfixResultFn(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr filterJsonUtf8, IntPtr rustFnPtr);
        public delegate void UnpatchFn(int handle);

        public static readonly PatchPrefixFn PatchPrefixDelegate = PatchPrefix;
        public static readonly PatchPostfixFn PatchPostfixDelegate = PatchPostfix;
        public static readonly PatchPrefixCtxFn PatchPrefixCtxDelegate = PatchPrefixCtx;
        public static readonly PatchPrefixInstanceArgsFn PatchPrefixInstanceArgsDelegate = PatchPrefixInstanceArgs;
        public static readonly PatchPostfixFloatResultFn PatchPostfixFloatResultDelegate = PatchPostfixFloatResult;
        public static readonly PatchPostfixIntResultFn PatchPostfixIntResultDelegate = PatchPostfixIntResult;
        public static readonly PatchPostfixResultFn PatchPostfixResultDelegate = PatchPostfixResult;
        public static readonly UnpatchFn UnpatchDelegate = Unpatch;

        /// <summary>
        /// Backend handle-acquire seam for ctx patches. Each entry
        /// assigns its backend's Acquire (MonoBridge.Acquire or
        /// Il2CppBridge.Acquire) before installing patches. Was a
        /// hard-coded MonoBridge.Acquire call, which broke every
        /// non-Mono build of this shared file (found 2026-08-07
        /// bringing up the MelonLoader shim).
        /// </summary>
        public static Func<object, int> AcquireHandle;

        /// <summary>
        /// Backend handle-lookup seam, the reverse of AcquireHandle:
        /// resolves a {"$handle": N} replacement result to the live
        /// object. Each entry assigns its backend's Lookup.
        /// </summary>
        public static Func<int, object> LookupHandle;

        public static void EnsureHarmony(string instanceId)
        {
            if (_harmony == null) _harmony = new HarmonyLib.Harmony(instanceId);
        }

        /// <summary>
        /// A Harmony finalizer written in C# (no Rust callback), on the
        /// shim's one Harmony instance. Not dropped on hot reload: it
        /// calls nothing in the Rust DLL. False when Harmony is not set up.
        /// </summary>
        public static bool PatchFinalizer(MethodBase target, MethodInfo finalizer)
        {
            if (_harmony == null) return false;
            _harmony.Patch(target, finalizer: new HarmonyMethod(finalizer));
            return true;
        }

        /// <summary>
        /// Drop every active patch. Used during hot reload so
        /// Harmony doesn't dispatch into a freed Rust DLL.
        /// Per-slot unpatch, not UnpatchSelf: UnpatchSelf is
        /// HarmonyX-only (missing in pardeike Harmony 2.0.4).
        /// </summary>
        public static void UnpatchAll()
        {
            lock (_lock)
            {
                foreach (var kv in _patches)
                {
                    ReleaseEntry(kv.Value);
                }
                _patches.Clear();
            }
        }

        private enum PatchKind
        {
            Prefix,
            Postfix,
            PrefixInstanceCtx,
            PrefixArg0Ctx,
            // args[0] via Harmony's __args array: the ONLY variant
            // whose mutations reach a VALUE-TYPE argument. Harmony
            // documents that editing __args elements writes back to
            // the original arguments after the patch; mutating the
            // boxed element's fields therefore lands in the real
            // arg. Requires __args support (Harmony 2.1+; the
            // survivalist shim embeds 2.4.2). Plain Arg0Ctx hands a
            // boxed COPY for value types: writes are silently lost
            // (live-verified 2026-07-04: Injury is a struct, the
            // AddInjury infection zeroing did nothing in play).
            PrefixArgs0Ctx,
            // __instance plus ALL arguments serialized to JSON
            // (bridge v7). Same __args requirement as
            // PrefixArgs0Ctx: Harmony 2.1+ / HarmonyX only.
            // Read-only view of the arguments; use it when a
            // Rust prefix needs the values to reimplement the
            // original, not to mutate them.
            PrefixInstanceArgs,
            // __instance plus the float return value, replaced by
            // what the Rust callback returns (bridge v8).
            PostfixFloatResult,
            // Same for an int return, behind an argument filter
            // (bridge v9).
            PostfixIntResult,
            // Same for any return type, as JSON (bridge v10).
            PostfixResult,
        }

        /// <summary>
        /// Kinds whose slot methods take Harmony's object[] __args,
        /// which Harmony writes back into the arguments afterwards.
        /// </summary>
        private static bool UsesArgsArray(PatchKind kind) =>
            kind == PatchKind.PrefixArgs0Ctx
            || kind == PatchKind.PrefixInstanceArgs
            || kind == PatchKind.PostfixFloatResult
            || kind == PatchKind.PostfixIntResult
            || kind == PatchKind.PostfixResult;

        private class PatchEntry
        {
            public MethodBase Target;
            public PatchKind Kind;
            public int Slot;
            // Set when the slot is shared by every patch of one Rust
            // callback (see ApplySlotPatch); null for a slot of its own.
            public string ShareKey;
        }

        // Shared slots: one Rust callback patched onto many methods
        // takes one slot, not one per method (obenseuer-mod's
        // first_copy_wins puts one prefix on ~370 Awake/OnDestroy
        // methods; SlotsPerKind is 16). Key "kind:fnptr" -> slot, and
        // how many live patches use it. The callback tells the methods
        // apart by its context object.
        private static readonly Dictionary<string, int> _sharedSlot = new Dictionary<string, int>();
        private static readonly Dictionary<string, int> _sharedUsers = new Dictionary<string, int>();

        // ---- slot tables -------------------------------------------------
        // One delegate per live patch. The pre-compiled slot
        // methods below read their table entry and call the Rust
        // fn. A null entry (raced unpatch) is a no-op.

        private static readonly RustPrefixDelegate[] _prefixSlots = new RustPrefixDelegate[SlotsPerKind];
        private static readonly RustPostfixDelegate[] _postfixSlots = new RustPostfixDelegate[SlotsPerKind];
        private static readonly RustPrefixDelegate[] _prefixInstanceSlots = new RustPrefixDelegate[SlotsPerKind];
        private static readonly RustPrefixDelegate[] _prefixArg0Slots = new RustPrefixDelegate[SlotsPerKind];
        private static readonly RustPrefixDelegate[] _prefixArgs0Slots = new RustPrefixDelegate[SlotsPerKind];
        private static readonly RustPrefixInstanceArgsDelegate[] _prefixInstanceArgsSlots = new RustPrefixInstanceArgsDelegate[SlotsPerKind];
        private static readonly RustPostfixFloatResultDelegate[] _postfixFloatResultSlots = new RustPostfixFloatResultDelegate[SlotsPerKind];
        private static readonly RustPostfixIntResultDelegate[] _postfixIntResultSlots = new RustPostfixIntResultDelegate[SlotsPerKind];
        // Per slot: (argument index, required value) pairs.
        private static readonly KeyValuePair<int, long>[][] _postfixIntResultFilters = new KeyValuePair<int, long>[SlotsPerKind][];
        private static readonly RustPostfixResultDelegate[] _postfixResultSlots = new RustPostfixResultDelegate[SlotsPerKind];
        private static readonly KeyValuePair<int, long>[][] _postfixResultFilters = new KeyValuePair<int, long>[SlotsPerKind][];
        // Per slot: the patched method's return type, to convert a
        // JSON replacement back.
        private static readonly Type[] _postfixResultTypes = new Type[SlotsPerKind];
        // Replacement result buffer size handed to Rust.
        private const int ResultOutCap = 16 * 1024;

        private static bool RunPrefixSlot(int i)
        {
            var d = _prefixSlots[i];
            if (d == null) return true;
            try
            {
                // Non-zero from the Rust prefix = skip the original
                // (unityforge/src/hook.rs contract).
                return d(IntPtr.Zero) == 0;
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: prefix slot " + i + " threw: " + e);
                return true;
            }
        }

        private static void RunPostfixSlot(int i)
        {
            var d = _postfixSlots[i];
            if (d == null) return;
            try { d(IntPtr.Zero); }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: postfix slot " + i + " threw: " + e);
            }
        }

        private static bool RunPrefixCtxSlot(RustPrefixDelegate[] table, int i, object ctx)
        {
            var d = table[i];
            if (d == null) return true;
            // A FRESH handle per call: the Rust side owns it and
            // releases it (MonoObject Drop).
            var handle = (ctx != null && AcquireHandle != null) ? AcquireHandle(ctx) : 0;
            try
            {
                return d(new IntPtr(handle)) == 0;
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: prefix_ctx slot " + i + " threw: " + e);
                return true;
            }
        }

        // ---- pre-compiled slot methods ------------------------------------
        // These are the methods Harmony targets. Signatures use
        // ONLY token-free parameter emissions (see header).

        private static bool PrefixSlot0() => RunPrefixSlot(0);
        private static bool PrefixSlot1() => RunPrefixSlot(1);
        private static bool PrefixSlot2() => RunPrefixSlot(2);
        private static bool PrefixSlot3() => RunPrefixSlot(3);
        private static bool PrefixSlot4() => RunPrefixSlot(4);
        private static bool PrefixSlot5() => RunPrefixSlot(5);
        private static bool PrefixSlot6() => RunPrefixSlot(6);
        private static bool PrefixSlot7() => RunPrefixSlot(7);
        private static bool PrefixSlot8() => RunPrefixSlot(8);
        private static bool PrefixSlot9() => RunPrefixSlot(9);
        private static bool PrefixSlot10() => RunPrefixSlot(10);
        private static bool PrefixSlot11() => RunPrefixSlot(11);
        private static bool PrefixSlot12() => RunPrefixSlot(12);
        private static bool PrefixSlot13() => RunPrefixSlot(13);
        private static bool PrefixSlot14() => RunPrefixSlot(14);
        private static bool PrefixSlot15() => RunPrefixSlot(15);

        private static void PostfixSlot0() => RunPostfixSlot(0);
        private static void PostfixSlot1() => RunPostfixSlot(1);
        private static void PostfixSlot2() => RunPostfixSlot(2);
        private static void PostfixSlot3() => RunPostfixSlot(3);
        private static void PostfixSlot4() => RunPostfixSlot(4);
        private static void PostfixSlot5() => RunPostfixSlot(5);
        private static void PostfixSlot6() => RunPostfixSlot(6);
        private static void PostfixSlot7() => RunPostfixSlot(7);
        private static void PostfixSlot8() => RunPostfixSlot(8);
        private static void PostfixSlot9() => RunPostfixSlot(9);
        private static void PostfixSlot10() => RunPostfixSlot(10);
        private static void PostfixSlot11() => RunPostfixSlot(11);
        private static void PostfixSlot12() => RunPostfixSlot(12);
        private static void PostfixSlot13() => RunPostfixSlot(13);
        private static void PostfixSlot14() => RunPostfixSlot(14);
        private static void PostfixSlot15() => RunPostfixSlot(15);

        private static bool PrefixInstanceSlot0(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 0, __instance);
        private static bool PrefixInstanceSlot1(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 1, __instance);
        private static bool PrefixInstanceSlot2(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 2, __instance);
        private static bool PrefixInstanceSlot3(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 3, __instance);
        private static bool PrefixInstanceSlot4(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 4, __instance);
        private static bool PrefixInstanceSlot5(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 5, __instance);
        private static bool PrefixInstanceSlot6(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 6, __instance);
        private static bool PrefixInstanceSlot7(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 7, __instance);
        private static bool PrefixInstanceSlot8(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 8, __instance);
        private static bool PrefixInstanceSlot9(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 9, __instance);
        private static bool PrefixInstanceSlot10(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 10, __instance);
        private static bool PrefixInstanceSlot11(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 11, __instance);
        private static bool PrefixInstanceSlot12(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 12, __instance);
        private static bool PrefixInstanceSlot13(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 13, __instance);
        private static bool PrefixInstanceSlot14(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 14, __instance);
        private static bool PrefixInstanceSlot15(object __instance) => RunPrefixCtxSlot(_prefixInstanceSlots, 15, __instance);

        private static object Args0(object[] __args)
            => (__args != null && __args.Length > 0) ? __args[0] : null;

        /// <summary>
        /// One argument to a JSON token, matching the bridge's
        /// value convention: primitives, enums (as numbers), and
        /// strings by value; null as null; anything else as
        /// {"handle": n} the Rust callback owns and releases.
        /// </summary>
        private static Newtonsoft.Json.Linq.JToken ArgToJson(object arg)
        {
            if (arg == null) return Newtonsoft.Json.Linq.JValue.CreateNull();
            var t = arg.GetType();
            if (t.IsEnum) return new Newtonsoft.Json.Linq.JValue(Convert.ToInt64(arg));
            if (arg is bool || arg is string
                || arg is sbyte || arg is byte || arg is short || arg is ushort
                || arg is int || arg is uint || arg is long || arg is ulong
                || arg is float || arg is double || arg is decimal)
            {
                return new Newtonsoft.Json.Linq.JValue(arg);
            }
            var handle = (AcquireHandle != null) ? AcquireHandle(arg) : 0;
            return new Newtonsoft.Json.Linq.JObject { ["handle"] = handle };
        }

        /// <summary>
        /// All arguments as NUL-terminated UTF-8 JSON, per ArgToJson.
        /// </summary>
        private static byte[] ArgsToJsonBytes(object[] args)
        {
            var json = new Newtonsoft.Json.Linq.JArray();
            if (args != null)
            {
                foreach (var a in args) json.Add(ArgToJson(a));
            }
            return System.Text.Encoding.UTF8.GetBytes(json.ToString(Newtonsoft.Json.Formatting.None) + "\0");
        }

        private static bool RunPrefixInstanceArgsSlot(int i, object instance, object[] args)
        {
            var d = _prefixInstanceArgsSlots[i];
            if (d == null) return true;
            var instanceHandle = (instance != null && AcquireHandle != null) ? AcquireHandle(instance) : 0;
            var bytes = ArgsToJsonBytes(args);
            var pin = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            try
            {
                return d(new IntPtr(instanceHandle), pin.AddrOfPinnedObject()) == 0;
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: prefix_instance_args slot " + i + " threw: " + e);
                return true;
            }
            finally
            {
                pin.Free();
            }
        }

        private static bool PrefixInstanceArgsSlot0(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(0, __instance, __args);
        private static bool PrefixInstanceArgsSlot1(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(1, __instance, __args);
        private static bool PrefixInstanceArgsSlot2(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(2, __instance, __args);
        private static bool PrefixInstanceArgsSlot3(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(3, __instance, __args);
        private static bool PrefixInstanceArgsSlot4(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(4, __instance, __args);
        private static bool PrefixInstanceArgsSlot5(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(5, __instance, __args);
        private static bool PrefixInstanceArgsSlot6(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(6, __instance, __args);
        private static bool PrefixInstanceArgsSlot7(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(7, __instance, __args);
        private static bool PrefixInstanceArgsSlot8(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(8, __instance, __args);
        private static bool PrefixInstanceArgsSlot9(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(9, __instance, __args);
        private static bool PrefixInstanceArgsSlot10(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(10, __instance, __args);
        private static bool PrefixInstanceArgsSlot11(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(11, __instance, __args);
        private static bool PrefixInstanceArgsSlot12(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(12, __instance, __args);
        private static bool PrefixInstanceArgsSlot13(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(13, __instance, __args);
        private static bool PrefixInstanceArgsSlot14(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(14, __instance, __args);
        private static bool PrefixInstanceArgsSlot15(object __instance, object[] __args) => RunPrefixInstanceArgsSlot(15, __instance, __args);

        private static void RunPostfixFloatResultSlot(int i, object instance, object[] args, ref float result)
        {
            var d = _postfixFloatResultSlots[i];
            if (d == null) return;
            var instanceHandle = (instance != null && AcquireHandle != null) ? AcquireHandle(instance) : 0;
            var bytes = ArgsToJsonBytes(args);
            var pin = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            try
            {
                result = d(new IntPtr(instanceHandle), pin.AddrOfPinnedObject(), result);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: postfix_float_result slot " + i + " threw: " + e);
            }
            finally
            {
                pin.Free();
            }
        }

        private static void PostfixFloatResultSlot0(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(0, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot1(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(1, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot2(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(2, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot3(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(3, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot4(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(4, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot5(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(5, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot6(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(6, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot7(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(7, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot8(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(8, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot9(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(9, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot10(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(10, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot11(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(11, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot12(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(12, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot13(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(13, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot14(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(14, __instance, __args, ref __result);
        private static void PostfixFloatResultSlot15(object __instance, object[] __args, ref float __result) => RunPostfixFloatResultSlot(15, __instance, __args, ref __result);

        private static bool ArgsMatch(KeyValuePair<int, long>[] filter, object[] args)
        {
            if (filter == null) return true;
            foreach (var kv in filter)
            {
                if (args == null || kv.Key >= args.Length) return false;
                var a = args[kv.Key];
                long v;
                if (a is bool b) v = b ? 1 : 0;
                else if (a != null && (a.GetType().IsEnum || a is int || a is long || a is short || a is byte || a is uint)) v = Convert.ToInt64(a);
                else return false;
                if (v != kv.Value) return false;
            }
            return true;
        }

        private static void RunPostfixIntResultSlot(int i, object instance, object[] args, ref int result)
        {
            var d = _postfixIntResultSlots[i];
            if (d == null || !ArgsMatch(_postfixIntResultFilters[i], args)) return;
            var instanceHandle = (instance != null && AcquireHandle != null) ? AcquireHandle(instance) : 0;
            var bytes = ArgsToJsonBytes(args);
            var pin = GCHandle.Alloc(bytes, GCHandleType.Pinned);
            try
            {
                result = d(new IntPtr(instanceHandle), pin.AddrOfPinnedObject(), result);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: postfix_int_result slot " + i + " threw: " + e);
            }
            finally
            {
                pin.Free();
            }
        }

        private static void PostfixIntResultSlot0(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(0, __instance, __args, ref __result);
        private static void PostfixIntResultSlot1(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(1, __instance, __args, ref __result);
        private static void PostfixIntResultSlot2(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(2, __instance, __args, ref __result);
        private static void PostfixIntResultSlot3(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(3, __instance, __args, ref __result);
        private static void PostfixIntResultSlot4(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(4, __instance, __args, ref __result);
        private static void PostfixIntResultSlot5(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(5, __instance, __args, ref __result);
        private static void PostfixIntResultSlot6(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(6, __instance, __args, ref __result);
        private static void PostfixIntResultSlot7(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(7, __instance, __args, ref __result);
        private static void PostfixIntResultSlot8(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(8, __instance, __args, ref __result);
        private static void PostfixIntResultSlot9(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(9, __instance, __args, ref __result);
        private static void PostfixIntResultSlot10(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(10, __instance, __args, ref __result);
        private static void PostfixIntResultSlot11(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(11, __instance, __args, ref __result);
        private static void PostfixIntResultSlot12(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(12, __instance, __args, ref __result);
        private static void PostfixIntResultSlot13(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(13, __instance, __args, ref __result);
        private static void PostfixIntResultSlot14(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(14, __instance, __args, ref __result);
        private static void PostfixIntResultSlot15(object __instance, object[] __args, ref int __result) => RunPostfixIntResultSlot(15, __instance, __args, ref __result);

        private static void RunPostfixResultSlot(int i, object instance, object[] args, ref object result)
        {
            var d = _postfixResultSlots[i];
            if (d == null || !ArgsMatch(_postfixResultFilters[i], args)) return;
            var instanceHandle = (instance != null && AcquireHandle != null) ? AcquireHandle(instance) : 0;
            var argBytes = ArgsToJsonBytes(args);
            var resultBytes = System.Text.Encoding.UTF8.GetBytes(ArgToJson(result).ToString(Newtonsoft.Json.Formatting.None) + "\0");
            var outBytes = new byte[ResultOutCap];
            var argPin = GCHandle.Alloc(argBytes, GCHandleType.Pinned);
            var resultPin = GCHandle.Alloc(resultBytes, GCHandleType.Pinned);
            var outPin = GCHandle.Alloc(outBytes, GCHandleType.Pinned);
            try
            {
                int n = d(new IntPtr(instanceHandle), argPin.AddrOfPinnedObject(), resultPin.AddrOfPinnedObject(), outPin.AddrOfPinnedObject(), ResultOutCap);
                if (n < 0) return;
                if (n > ResultOutCap)
                {
                    ShimLogger.Error("HarmonyBridge: postfix_result slot " + i + " replacement is " + n + " bytes, cap " + ResultOutCap);
                    return;
                }
                var tok = Newtonsoft.Json.Linq.JToken.Parse(System.Text.Encoding.UTF8.GetString(outBytes, 0, n));
                if (HandleArg.TryResolve(tok, h => LookupHandle != null ? LookupHandle(h) : null, out var live))
                    result = live;
                else
                    result = tok.ToObject(_postfixResultTypes[i]);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge: postfix_result slot " + i + " threw: " + e);
            }
            finally
            {
                argPin.Free();
                resultPin.Free();
                outPin.Free();
            }
        }

        private static void PostfixResultSlot0(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(0, __instance, __args, ref __result);
        private static void PostfixResultSlot1(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(1, __instance, __args, ref __result);
        private static void PostfixResultSlot2(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(2, __instance, __args, ref __result);
        private static void PostfixResultSlot3(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(3, __instance, __args, ref __result);
        private static void PostfixResultSlot4(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(4, __instance, __args, ref __result);
        private static void PostfixResultSlot5(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(5, __instance, __args, ref __result);
        private static void PostfixResultSlot6(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(6, __instance, __args, ref __result);
        private static void PostfixResultSlot7(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(7, __instance, __args, ref __result);
        private static void PostfixResultSlot8(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(8, __instance, __args, ref __result);
        private static void PostfixResultSlot9(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(9, __instance, __args, ref __result);
        private static void PostfixResultSlot10(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(10, __instance, __args, ref __result);
        private static void PostfixResultSlot11(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(11, __instance, __args, ref __result);
        private static void PostfixResultSlot12(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(12, __instance, __args, ref __result);
        private static void PostfixResultSlot13(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(13, __instance, __args, ref __result);
        private static void PostfixResultSlot14(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(14, __instance, __args, ref __result);
        private static void PostfixResultSlot15(object __instance, object[] __args, ref object __result) => RunPostfixResultSlot(15, __instance, __args, ref __result);

        private static bool PrefixArgs0Slot0(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 0, Args0(__args));
        private static bool PrefixArgs0Slot1(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 1, Args0(__args));
        private static bool PrefixArgs0Slot2(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 2, Args0(__args));
        private static bool PrefixArgs0Slot3(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 3, Args0(__args));
        private static bool PrefixArgs0Slot4(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 4, Args0(__args));
        private static bool PrefixArgs0Slot5(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 5, Args0(__args));
        private static bool PrefixArgs0Slot6(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 6, Args0(__args));
        private static bool PrefixArgs0Slot7(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 7, Args0(__args));
        private static bool PrefixArgs0Slot8(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 8, Args0(__args));
        private static bool PrefixArgs0Slot9(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 9, Args0(__args));
        private static bool PrefixArgs0Slot10(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 10, Args0(__args));
        private static bool PrefixArgs0Slot11(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 11, Args0(__args));
        private static bool PrefixArgs0Slot12(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 12, Args0(__args));
        private static bool PrefixArgs0Slot13(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 13, Args0(__args));
        private static bool PrefixArgs0Slot14(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 14, Args0(__args));
        private static bool PrefixArgs0Slot15(object[] __args) => RunPrefixCtxSlot(_prefixArgs0Slots, 15, Args0(__args));

        private static bool PrefixArg0Slot0(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 0, __0);
        private static bool PrefixArg0Slot1(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 1, __0);
        private static bool PrefixArg0Slot2(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 2, __0);
        private static bool PrefixArg0Slot3(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 3, __0);
        private static bool PrefixArg0Slot4(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 4, __0);
        private static bool PrefixArg0Slot5(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 5, __0);
        private static bool PrefixArg0Slot6(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 6, __0);
        private static bool PrefixArg0Slot7(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 7, __0);
        private static bool PrefixArg0Slot8(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 8, __0);
        private static bool PrefixArg0Slot9(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 9, __0);
        private static bool PrefixArg0Slot10(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 10, __0);
        private static bool PrefixArg0Slot11(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 11, __0);
        private static bool PrefixArg0Slot12(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 12, __0);
        private static bool PrefixArg0Slot13(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 13, __0);
        private static bool PrefixArg0Slot14(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 14, __0);
        private static bool PrefixArg0Slot15(object __0) => RunPrefixCtxSlot(_prefixArg0Slots, 15, __0);

        private static MethodInfo SlotMi(string prefix, int i)
        {
            return typeof(HarmonyBridge).GetMethod(prefix + i, BindingFlags.NonPublic | BindingFlags.Static);
        }

        // ---- Rust-facing entry points -----------------------------------

        private static int PatchPrefix(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                var del = (RustPrefixDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPrefixDelegate));
                return ApplySlotPatch(target, PatchKind.Prefix, del, null);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPrefix: " + e);
                return 0;
            }
        }

        private static int PatchPostfix(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                var del = (RustPostfixDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPostfixDelegate));
                return ApplySlotPatch(target, PatchKind.Postfix, null, del);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPostfix: " + e);
                return 0;
            }
        }

        private static int PatchPrefixCtx(IntPtr typeNameUtf8, IntPtr methodNameUtf8, int ctxKind, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                if (ctxKind != 0 && ctxKind != 1 && ctxKind != 2) return 0;
                if (AcquireHandle == null)
                {
                    // Loud: a null seam would hand every callback
                    // handle 0 and look like a null context object.
                    ShimLogger.Error("HarmonyBridge.PatchPrefixCtx: AcquireHandle not set by the shim entry; refusing ctx patch");
                    return 0;
                }
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                if (ctxKind == 0 && target.IsStatic)
                {
                    ShimLogger.Error("HarmonyBridge.PatchPrefixCtx: __instance ctx on static method " + target.Name);
                    return 0;
                }
                if (ctxKind != 0 && target.GetParameters().Length == 0)
                {
                    ShimLogger.Error("HarmonyBridge.PatchPrefixCtx: arg ctx on parameterless method " + target.Name);
                    return 0;
                }
                if (ctxKind == 1 && target.GetParameters()[0].ParameterType.IsValueType)
                {
                    // A boxed COPY would be handed to the callback and
                    // every mutation silently lost. Force the caller to
                    // the __args write-back variant.
                    ShimLogger.Error("HarmonyBridge.PatchPrefixCtx: arg0 ctx on VALUE-TYPE first arg of " + target.Name + "; use ctx kind 2 (args0 write-back)");
                    return 0;
                }
                var del = (RustPrefixDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPrefixDelegate));
                var kind = (ctxKind == 0) ? PatchKind.PrefixInstanceCtx
                    : (ctxKind == 1) ? PatchKind.PrefixArg0Ctx
                    : PatchKind.PrefixArgs0Ctx;
                return ApplySlotPatch(target, kind, del, null, shareKey: kind + ":" + rustFnPtr.ToInt64());
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPrefixCtx: " + e);
                return 0;
            }
        }

        private static int PatchPrefixInstanceArgs(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                if (AcquireHandle == null)
                {
                    ShimLogger.Error("HarmonyBridge.PatchPrefixInstanceArgs: AcquireHandle not set by the shim entry; refusing patch");
                    return 0;
                }
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                var del = (RustPrefixInstanceArgsDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPrefixInstanceArgsDelegate));
                return ApplySlotPatch(target, PatchKind.PrefixInstanceArgs, null, null, del);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPrefixInstanceArgs: " + e);
                return 0;
            }
        }

        private static int PatchPostfixFloatResult(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                if (AcquireHandle == null)
                {
                    ShimLogger.Error("HarmonyBridge.PatchPostfixFloatResult: AcquireHandle not set by the shim entry; refusing patch");
                    return 0;
                }
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                if (!(target is MethodInfo mi) || mi.ReturnType != typeof(float))
                {
                    // `ref float __result` on any other return type is
                    // rejected by Harmony or reads the wrong bytes.
                    ShimLogger.Error("HarmonyBridge.PatchPostfixFloatResult: " + target.Name + " does not return float");
                    return 0;
                }
                var del = (RustPostfixFloatResultDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPostfixFloatResultDelegate));
                return ApplySlotPatch(target, PatchKind.PostfixFloatResult, null, null, null, del);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPostfixFloatResult: " + e);
                return 0;
            }
        }

        private static int PatchPostfixIntResult(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr filterJsonUtf8, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                if (AcquireHandle == null)
                {
                    ShimLogger.Error("HarmonyBridge.PatchPostfixIntResult: AcquireHandle not set by the shim entry; refusing patch");
                    return 0;
                }
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                if (!(target is MethodInfo mi) || mi.ReturnType != typeof(int))
                {
                    ShimLogger.Error("HarmonyBridge.PatchPostfixIntResult: " + target.Name + " does not return int");
                    return 0;
                }
                var del = (RustPostfixIntResultDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPostfixIntResultDelegate));
                return ApplySlotPatch(target, PatchKind.PostfixIntResult, null, null, null, null, del, ParseArgFilter(filterJsonUtf8));
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPostfixIntResult: " + e);
                return 0;
            }
        }

        private static int PatchPostfixResult(IntPtr typeNameUtf8, IntPtr methodNameUtf8, IntPtr filterJsonUtf8, IntPtr rustFnPtr)
        {
            try
            {
                if (_harmony == null || rustFnPtr == IntPtr.Zero) return 0;
                if (AcquireHandle == null || LookupHandle == null)
                {
                    ShimLogger.Error("HarmonyBridge.PatchPostfixResult: AcquireHandle/LookupHandle not set by the shim entry; refusing patch");
                    return 0;
                }
                var target = ResolveTarget(typeNameUtf8, methodNameUtf8);
                if (target == null) return 0;
                if (!(target is MethodInfo mi) || mi.ReturnType == typeof(void))
                {
                    ShimLogger.Error("HarmonyBridge.PatchPostfixResult: " + target.Name + " returns nothing");
                    return 0;
                }
                var del = (RustPostfixResultDelegate)Marshal.GetDelegateForFunctionPointer(rustFnPtr, typeof(RustPostfixResultDelegate));
                return ApplySlotPatch(target, PatchKind.PostfixResult, null, null, null, null, null, ParseArgFilter(filterJsonUtf8), del, mi.ReturnType);
            }
            catch (Exception e)
            {
                ShimLogger.Error("HarmonyBridge.PatchPostfixResult: " + e);
                return 0;
            }
        }

        /// <summary>
        /// Argument filter JSON {"<arg index>": value}, value a number
        /// (enum or integer argument) or bool. Null for none.
        /// </summary>
        private static KeyValuePair<int, long>[] ParseArgFilter(IntPtr filterJsonUtf8)
        {
            var filterText = filterJsonUtf8 == IntPtr.Zero ? null : Marshal.PtrToStringAnsi(filterJsonUtf8);
            if (string.IsNullOrEmpty(filterText)) return null;
            var filter = new List<KeyValuePair<int, long>>();
            foreach (var p in Newtonsoft.Json.Linq.JObject.Parse(filterText).Properties())
            {
                long v = p.Value.Type == Newtonsoft.Json.Linq.JTokenType.Boolean
                    ? ((bool)p.Value ? 1 : 0)
                    : (long)p.Value;
                filter.Add(new KeyValuePair<int, long>(int.Parse(p.Name), v));
            }
            return filter.Count > 0 ? filter.ToArray() : null;
        }

        private static int ApplySlotPatch(MethodBase target, PatchKind kind, RustPrefixDelegate prefixDel, RustPostfixDelegate postfixDel, RustPrefixInstanceArgsDelegate instanceArgsDel = null, RustPostfixFloatResultDelegate floatResultDel = null, RustPostfixIntResultDelegate intResultDel = null, KeyValuePair<int, long>[] argFilter = null, RustPostfixResultDelegate resultDel = null, Type resultType = null, string shareKey = null)
        {
            lock (_lock)
            {
                string namePrefix = SlotNamePrefix(kind);

                // Harmony copies __args back into the arguments after
                // the patch. On a ref/out parameter that overwrites
                // what the method wrote with the value from its start:
                // The Walking Trade 2026-09-30, a PostfixResult on
                // TrySelectShelf(..., out Vector3 position) handed the
                // caller (0,0,0) and cleaners walked to the world origin.
                if (UsesArgsArray(kind))
                {
                    foreach (var p in target.GetParameters())
                    {
                        if (p.ParameterType.IsByRef)
                        {
                            ShimLogger.Error($"HarmonyBridge: refusing {kind} on {target.DeclaringType?.FullName}.{target.Name}: parameter '{p.Name}' is ref/out and Harmony's __args write-back would overwrite it; use a patch kind without __args, or read the result from the caller");
                            return 0;
                        }
                    }
                }

                // The same callback already holds a slot: patch this
                // method onto it too.
                bool reuse = shareKey != null && _sharedSlot.ContainsKey(shareKey);
                int slot = reuse ? _sharedSlot[shareKey] : FindFreeSlot(kind);
                if (slot < 0)
                {
                    ShimLogger.Error($"HarmonyBridge: no free {namePrefix} (cap {SlotsPerKind}); unpatch something or raise SlotsPerKind");
                    return 0;
                }

                var mi = SlotMi(namePrefix, slot);
                var hm = new HarmonyMethod(mi);
                // Assign the delegate BEFORE patching so the slot
                // is live the instant the patch applies; clear on
                // failure.
                if (!reuse) SetSlot(kind, slot, prefixDel, postfixDel, instanceArgsDel, floatResultDel, intResultDel, argFilter, resultDel, resultType);
                try
                {
                    if (kind == PatchKind.Postfix || kind == PatchKind.PostfixFloatResult || kind == PatchKind.PostfixIntResult || kind == PatchKind.PostfixResult) _harmony.Patch(target, postfix: hm);
                    else _harmony.Patch(target, prefix: hm);
                }
                catch
                {
                    if (!reuse) SetSlot(kind, slot, null, null);
                    throw;
                }

                if (shareKey != null)
                {
                    _sharedSlot[shareKey] = slot;
                    _sharedUsers[shareKey] = (reuse ? _sharedUsers[shareKey] : 0) + 1;
                }
                int handle = _next++;
                _patches[handle] = new PatchEntry { Target = target, Kind = kind, Slot = slot, ShareKey = shareKey };
                _everPatched.Add(target);
                return handle;
            }
        }

        /// <summary>
        /// Every method patched since the game started. On IL2CPP a
        /// patched method keeps a generated wrapper after its last
        /// patch is removed (Il2CppInterop's DetourTo re-detours
        /// instead of restoring the native code), so a hot reload
        /// that drops a hook does not give the game its method back.
        /// </summary>
        private static readonly HashSet<MethodBase> _everPatched = new HashSet<MethodBase>();

        /// <summary>
        /// Methods patched earlier this game session that no patch
        /// covers now. Called after a hot swap; each one needs a game
        /// restart to be the game's own code again.
        /// </summary>
        public static List<string> WrappedButUnpatched()
        {
            lock (_lock)
            {
                var live = new HashSet<MethodBase>();
                foreach (var kv in _patches) live.Add(kv.Value.Target);
                var dropped = new List<string>();
                foreach (var m in _everPatched)
                {
                    if (!live.Contains(m)) dropped.Add(m.DeclaringType?.FullName + "." + m.Name);
                }
                return dropped;
            }
        }

        private static string SlotNamePrefix(PatchKind kind)
        {
            switch (kind)
            {
                case PatchKind.Prefix: return "PrefixSlot";
                case PatchKind.Postfix: return "PostfixSlot";
                case PatchKind.PrefixInstanceCtx: return "PrefixInstanceSlot";
                case PatchKind.PrefixArg0Ctx: return "PrefixArg0Slot";
                case PatchKind.PrefixInstanceArgs: return "PrefixInstanceArgsSlot";
                case PatchKind.PostfixFloatResult: return "PostfixFloatResultSlot";
                case PatchKind.PostfixIntResult: return "PostfixIntResultSlot";
                case PatchKind.PostfixResult: return "PostfixResultSlot";
                default: return "PrefixArgs0Slot";
            }
        }

        private static int FindFreeSlot(PatchKind kind)
        {
            for (int i = 0; i < SlotsPerKind; i++)
            {
                bool free;
                switch (kind)
                {
                    case PatchKind.Prefix: free = _prefixSlots[i] == null; break;
                    case PatchKind.Postfix: free = _postfixSlots[i] == null; break;
                    case PatchKind.PrefixInstanceCtx: free = _prefixInstanceSlots[i] == null; break;
                    case PatchKind.PrefixArg0Ctx: free = _prefixArg0Slots[i] == null; break;
                    case PatchKind.PrefixInstanceArgs: free = _prefixInstanceArgsSlots[i] == null; break;
                    case PatchKind.PostfixFloatResult: free = _postfixFloatResultSlots[i] == null; break;
                    case PatchKind.PostfixIntResult: free = _postfixIntResultSlots[i] == null; break;
                    case PatchKind.PostfixResult: free = _postfixResultSlots[i] == null; break;
                    default: free = _prefixArgs0Slots[i] == null; break;
                }
                if (free) return i;
            }
            return -1;
        }

        private static void SetSlot(PatchKind kind, int slot, RustPrefixDelegate prefixDel, RustPostfixDelegate postfixDel, RustPrefixInstanceArgsDelegate instanceArgsDel = null, RustPostfixFloatResultDelegate floatResultDel = null, RustPostfixIntResultDelegate intResultDel = null, KeyValuePair<int, long>[] argFilter = null, RustPostfixResultDelegate resultDel = null, Type resultType = null)
        {
            switch (kind)
            {
                case PatchKind.PostfixResult:
                    // Filter and type first: a live slot must never run
                    // unfiltered or without its return type.
                    _postfixResultFilters[slot] = argFilter;
                    _postfixResultTypes[slot] = resultType;
                    _postfixResultSlots[slot] = resultDel;
                    break;
                case PatchKind.Prefix: _prefixSlots[slot] = prefixDel; break;
                case PatchKind.Postfix: _postfixSlots[slot] = postfixDel; break;
                case PatchKind.PrefixInstanceCtx: _prefixInstanceSlots[slot] = prefixDel; break;
                case PatchKind.PrefixArg0Ctx: _prefixArg0Slots[slot] = prefixDel; break;
                case PatchKind.PrefixInstanceArgs: _prefixInstanceArgsSlots[slot] = instanceArgsDel; break;
                case PatchKind.PostfixFloatResult: _postfixFloatResultSlots[slot] = floatResultDel; break;
                case PatchKind.PostfixIntResult:
                    // Filter first: a live slot must never run unfiltered.
                    _postfixIntResultFilters[slot] = argFilter;
                    _postfixIntResultSlots[slot] = intResultDel;
                    break;
                default: _prefixArgs0Slots[slot] = prefixDel; break;
            }
        }

        private static void Unpatch(int handle)
        {
            lock (_lock)
            {
                if (!_patches.TryGetValue(handle, out var entry)) return;
                _patches.Remove(handle);
                ReleaseEntry(entry);
            }
        }

        private static void ReleaseEntry(PatchEntry entry)
        {
            string namePrefix = SlotNamePrefix(entry.Kind);
            try { _harmony?.Unpatch(entry.Target, SlotMi(namePrefix, entry.Slot)); }
            catch (Exception e) { ShimLogger.Error("HarmonyBridge.Unpatch: " + e); }
            if (entry.ShareKey != null && _sharedUsers.TryGetValue(entry.ShareKey, out var users))
            {
                // Other methods still use this callback's slot.
                if (users > 1)
                {
                    _sharedUsers[entry.ShareKey] = users - 1;
                    return;
                }
                _sharedUsers.Remove(entry.ShareKey);
                _sharedSlot.Remove(entry.ShareKey);
            }
            SetSlot(entry.Kind, entry.Slot, null, null);
        }

        private static MethodBase ResolveTarget(IntPtr typeNameUtf8, IntPtr methodNameUtf8)
        {
            var tname = Marshal.PtrToStringAnsi(typeNameUtf8);
            var mname = Marshal.PtrToStringAnsi(methodNameUtf8);
            var t = TypeCache.Resolve(tname);
            if (t == null)
            {
                // Loud on the miss paths: a silent 0 here cost a
                // full game-restart debug cycle (2026-07-04).
                ShimLogger.Error($"HarmonyBridge: type '{tname}' not found");
                return null;
            }
            // "Name(Type1,Type2)" picks one overload; a bare name is
            // ambiguous when the method is overloaded (WgoData.MakeDrop).
            Type[] args = null;
            int paren = mname.IndexOf('(');
            if (paren > 0 && mname.EndsWith(")"))
            {
                var list = mname.Substring(paren + 1, mname.Length - paren - 2);
                mname = mname.Substring(0, paren);
                // char[] binds Split(params char[]); a bare char binds
                // Split(char, StringSplitOptions), which Unity 2020.3's
                // Mono lacks (MissingMethodException in Terra Invicta).
                var names = list.Length == 0 ? new string[0] : list.Split(new[] { ',' });
                args = new Type[names.Length];
                for (int i = 0; i < names.Length; i++)
                {
                    args[i] = TypeCache.Resolve(names[i].Trim());
                    if (args[i] == null)
                    {
                        ShimLogger.Error($"HarmonyBridge: argument type '{names[i].Trim()}' not found for {tname}.{mname}");
                        return null;
                    }
                }
            }
            var m = AccessTools.Method(t, mname, args);
            if (m == null)
            {
                ShimLogger.Error($"HarmonyBridge: method '{mname}' not found on {t.FullName} (assembly {t.Assembly.GetName().Name})");
            }
            return m;
        }
    }
}
