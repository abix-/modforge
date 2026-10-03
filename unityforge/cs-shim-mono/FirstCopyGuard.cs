// FirstCopyGuard.cs. The check behind obenseuer-mod's first_copy_wins
// prefix, done here in one call: from Rust it took about eight reflection
// calls across the bridge per Awake/OnDestroy, each marshalled as JSON,
// and made up 40 to 70% of the longest frame while an area loaded
// alongside (obenseuer-mod docs/loading-research.md). Here the static
// field is found once per class and kept.

using System;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;

namespace Unityforge.Shim
{
    public static class FirstCopyGuard
    {
        // Class -> reads its one-copy static field or property ("instance",
        // AstarPath's "active" field, RVOSimulator's "active" property);
        // null when it has none.
        private static readonly Dictionary<Type, Func<object>> Fields = new Dictionary<Type, Func<object>>();

        /// <summary>
        /// The class's full name when `me` is a new copy and a different,
        /// live copy already holds the class's one-copy field, which is
        /// not one the game keeps through scene changes (those destroy
        /// their own new copies). Empty when the original should run.
        /// </summary>
        public static string Newcomer(object me)
        {
            if (!(me is Component)) return "";
            var type = me.GetType();
            if (!Fields.TryGetValue(type, out var read))
            {
                read = FindOneCopy(type);
                Fields[type] = read;
            }
            if (read == null) return "";
            // Unity's == treats a destroyed object as null.
            var current = read() as UnityEngine.Object;
            if (current == null || ReferenceEquals(current, me)) return "";
            if (current is Component kept && kept.gameObject.scene.name == "DontDestroyOnLoad") return "";
            return type.FullName;
        }

        /// <summary>
        /// Why an OnDestroy should not run, or empty when it should: a new
        /// copy of a one-copy class (Newcomer: its OnDestroy would empty the
        /// field), or an object that never started (in a scene loaded
        /// quietly and never entered: its OnDestroy undoes what its Start
        /// never did; LavaLamp destroyed the shared material).
        /// </summary>
        public static string SkipOnDestroy(object me)
        {
            var newcomer = Newcomer(me);
            if (newcomer.Length > 0) return newcomer;
            // Only when its OnDestroy can only undo Start (StartWithoutAwakeClasses).
            return !HasAwake(me.GetType()) && SceneTools.InAreaNeverEntered(me) ? me.GetType().FullName + " (never started)" : "";
        }

        /// <summary>
        /// Every MonoBehaviour class in an assembly that declares OnDestroy
        /// and has a Start but no Awake: its OnDestroy can only undo what
        /// Start did. A class with an Awake is left out: Awake runs in an
        /// area loaded quietly, and its OnDestroy must undo it
        /// (InteractableChair subscribes to SaveController.PlayerWillChangeLevel
        /// in Awake; skipped, destroyed chairs stayed subscribed and threw).
        /// </summary>
        public static string[] StartWithoutAwakeClasses(string assemblyOfType)
        {
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return new string[0];
            const BindingFlags any = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;
            var found = new List<string>();
            Type[] types;
            try { types = anchor.Assembly.GetTypes(); }
            catch (ReflectionTypeLoadException e) { types = e.Types; }
            foreach (var t in types)
            {
                if (t == null || !typeof(MonoBehaviour).IsAssignableFrom(t)) continue;
                if (t.GetMethod("OnDestroy", any | BindingFlags.DeclaredOnly, null, Type.EmptyTypes, null) == null) continue;
                if (t.GetMethod("Start", any, null, Type.EmptyTypes, null) == null) continue;
                if (HasAwake(t)) continue;
                found.Add(t.FullName);
            }
            return found.ToArray();
        }

        /// <summary>OnDisable exceptions swallowed by NeverStartedFinalizer.</summary>
        public static int SwallowedOnDisable { get; private set; }

        private static bool _onDisablePatched;

        /// <summary>
        /// Patches OnDisable of every MonoBehaviour class in an assembly
        /// that declares OnDisable and has a Start, once. The area loaded
        /// quietly is switched off before any Start, so OnDisable runs on
        /// objects that never started: it still runs (SMVHierarchy and
        /// InteractableListItem unsubscribe there what OnEnable subscribed),
        /// and only the exception it throws reaching what Start would have
        /// set is swallowed (MoneyPanel's OSMoneyTextList, filled in Start).
        /// Returns the count patched.
        /// </summary>
        public static int FinishOnDisableOfNeverStarted(string assemblyOfType)
        {
            if (_onDisablePatched) return 0;
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return 0;
            const BindingFlags any = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;
            var finalizer = typeof(FirstCopyGuard).GetMethod(nameof(NeverStartedFinalizer), BindingFlags.NonPublic | BindingFlags.Static);
            Type[] types;
            try { types = anchor.Assembly.GetTypes(); }
            catch (ReflectionTypeLoadException e) { types = e.Types; }
            int n = 0;
            foreach (var t in types)
            {
                if (t == null || !typeof(MonoBehaviour).IsAssignableFrom(t)) continue;
                var onDisable = t.GetMethod("OnDisable", any | BindingFlags.DeclaredOnly, null, Type.EmptyTypes, null);
                if (onDisable == null || onDisable.IsAbstract) continue;
                if (t.GetMethod("Start", any, null, Type.EmptyTypes, null) == null) continue;
                if (HarmonyBridge.PatchFinalizer(onDisable, finalizer)) n++;
            }
            _onDisablePatched = true;
            return n;
        }

        // Harmony finalizer: returning null swallows the exception.
        private static Exception NeverStartedFinalizer(Exception __exception, object __instance)
        {
            if (__exception == null) return null;
            if (!SceneTools.InAreaNeverEntered(__instance)) return __exception;
            SwallowedOnDisable++;
            return null;
        }

        /// <summary>
        /// True when the class or a game class it derives from declares
        /// Awake (a private Awake of a base class is not found by
        /// GetMethod on the derived class, so each class is asked).
        /// </summary>
        private static bool HasAwake(Type t)
        {
            const BindingFlags declared = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly;
            for (; t != null && t != typeof(MonoBehaviour); t = t.BaseType)
            {
                if (t.GetMethod("Awake", declared, null, Type.EmptyTypes, null) != null) return true;
            }
            return false;
        }

        /// <summary>
        /// Reads a class's one copy: a public static field or property of
        /// the class's own type, whatever its name ("instance", AstarPath's
        /// "active" field, PlayerIdentity's "identity", RVOSimulator's
        /// "active" property: missed as a field only, a kept area's copy
        /// took it over and NPCs entering found none, RemoveAgent threw).
        /// Null when it has none.
        /// </summary>
        private static Func<object> FindOneCopy(Type type)
        {
            const BindingFlags flags = BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly;
            foreach (var f in type.GetFields(flags))
            {
                if (f.FieldType == type) return () => f.GetValue(null);
            }
            foreach (var p in type.GetProperties(flags))
            {
                if (p.PropertyType == type && p.CanRead && p.GetIndexParameters().Length == 0) return () => p.GetValue(null, null);
            }
            return null;
        }

        /// <summary>
        /// Every MonoBehaviour class in an assembly with a one-copy field
        /// or property (FindOneCopy): the classes obenseuer-mod's
        /// first_copy_wins guards.
        /// The assembly is named by one of its types ("Inventory,
        /// Assembly-CSharp").
        /// </summary>
        public static string[] OneCopyClasses(string assemblyOfType)
        {
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return new string[0];
            var found = new List<string>();
            Type[] types;
            try { types = anchor.Assembly.GetTypes(); }
            catch (ReflectionTypeLoadException e) { types = e.Types; }
            foreach (var t in types)
            {
                if (t == null || !typeof(MonoBehaviour).IsAssignableFrom(t)) continue;
                var read = FindOneCopy(t);
                Fields[t] = read;
                if (read != null) found.Add(t.FullName);
            }
            return found.ToArray();
        }
    }
}
