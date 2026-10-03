// FirstCopyGuard.cs. The check behind obenseuer-mod's first_copy_wins
// prefix, done here in one call: from Rust it took about eight reflection
// calls across the bridge per Awake/OnDestroy, each marshalled as JSON,
// and made up 40 to 70% of the longest frame while an area loaded
// alongside (obenseuer-mod docs/performance.md). Here the static
// field is found once per class and kept.

using System;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;

namespace Unityforge.Shim
{
    public static class FirstCopyGuard
    {
        // Class -> its one-copy static field or property ("instance",
        // AstarPath's "active" field, RVOSimulator's "active" property);
        // null when it has none.
        private static readonly Dictionary<Type, MemberInfo> Fields = new Dictionary<Type, MemberInfo>();

        private static object Read(MemberInfo m) => m is FieldInfo f ? f.GetValue(null) : ((PropertyInfo)m).GetValue(null, null);

        private static void Write(MemberInfo m, object value)
        {
            if (m is FieldInfo f) f.SetValue(null, value);
            else ((PropertyInfo)m).SetValue(null, value, null);
        }

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
            if (!Fields.TryGetValue(type, out var member))
            {
                member = FindOneCopy(type);
                Fields[type] = member;
            }
            if (member == null) return "";
            // Unity's == treats a destroyed object as null.
            var current = Read(member) as UnityEngine.Object;
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
        /// A class's one copy (docs/kept-areas.md, rule 1, which copy): a
        /// public static field or property of the class's own type, whatever
        /// its name ("instance", AstarPath's "active" field, PlayerIdentity's
        /// "identity", RVOSimulator's "active" property), that the class's
        /// own Awake or OnEnable writes: the game's way of making a manager
        /// (`instance = this`). A field of its own type nothing writes on
        /// waking is not one: `Storage.active` is the box open now, and
        /// counting it held back every box of an area loaded while one was
        /// open. Null when it has none.
        /// </summary>
        private static MemberInfo FindOneCopy(Type type)
        {
            // Public or not: info_navigation, SkyCamera keep theirs private.
            const BindingFlags flags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.DeclaredOnly;
            foreach (var f in type.GetFields(flags))
            {
                if (f.FieldType == type && WrittenOnWaking(type, f)) return f;
            }
            foreach (var p in type.GetProperties(flags))
            {
                if (p.PropertyType == type && p.CanRead && p.GetIndexParameters().Length == 0 && WrittenOnWaking(type, p.GetSetMethod(true))) return p;
            }
            return null;
        }

        /// <summary>
        /// True when the class's own Awake or OnEnable stores to the field
        /// (stsfld) or calls the property's setter, read with Harmony's IL
        /// reader (PatchProcessor.ReadMethodBody).
        /// </summary>
        private static bool WrittenOnWaking(Type type, MemberInfo target)
        {
            if (target == null) return false;
            const BindingFlags declared = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.DeclaredOnly;
            foreach (var name in new[] { "Awake", "OnEnable" })
            {
                var method = type.GetMethod(name, declared, null, Type.EmptyTypes, null);
                if (method == null) continue;
                foreach (var op in HarmonyLib.PatchProcessor.ReadMethodBody(method))
                {
                    if (op.Value is MemberInfo m && m.MetadataToken == target.MetadataToken && m.Module == target.Module) return true;
                }
            }
            return false;
        }

        // Area-owned managers (docs/kept-areas.md, rule 1, which copy): their
        // full class names, set once by the mod.
        private static readonly HashSet<string> AreaOwnedNames = new HashSet<string>();
        private static readonly List<Type> AreaOwnedTypes = new List<Type>();

        /// <summary>
        /// The area-owned managers, by class name, in the assembly named by
        /// one of its types. Returns how many were found.
        /// </summary>
        public static int SetAreaOwned(string assemblyOfType, string commaNames)
        {
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return 0;
            AreaOwnedNames.Clear();
            AreaOwnedTypes.Clear();
            foreach (var name in commaNames.Split(','))
            {
                var t = anchor.Assembly.GetType(name.Trim());
                if (t == null) continue;
                AreaOwnedNames.Add(t.FullName);
                AreaOwnedTypes.Add(t);
            }
            return AreaOwnedTypes.Count;
        }

        internal static bool IsAreaOwned(Type t) => AreaOwnedNames.Contains(t.FullName);

        /// <summary>The managers' live copies: each one-copy field's value, alive.</summary>
        internal static List<UnityEngine.Object> LiveCopies()
        {
            var live = new List<UnityEngine.Object>();
            foreach (var member in Fields.Values)
            {
                if (member == null) continue;
                object value;
                try { value = Read(member); }
                catch (Exception) { continue; }
                if (value is UnityEngine.Object o && o != null && !live.Contains(o)) live.Add(o);
            }
            return live;
        }

        /// <summary>
        /// An area-owned manager's copy in a loaded scene (by class name, as
        /// given to SetAreaOwned); null when there is none.
        /// </summary>
        public static object AreaCopy(string className, string sceneName)
        {
            var scene = UnityEngine.SceneManagement.SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return null;
            foreach (var t in AreaOwnedTypes)
            {
                if (t.Name != className && t.FullName != className) continue;
                foreach (var o in Resources.FindObjectsOfTypeAll(t))
                {
                    if (o is MonoBehaviour m && m != null && m.gameObject.scene.handle == scene.handle) return m;
                }
            }
            return null;
        }

        /// <summary>
        /// Entering an area (rule 2, step 2): each area-owned manager's one
        /// copy is the area's, switched on, as its own Awake would have set
        /// it on a normal load. Returns how many were set.
        /// </summary>
        public static int EnterArea(string sceneName)
        {
            var scene = UnityEngine.SceneManagement.SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return 0;
            int n = 0;
            foreach (var t in AreaOwnedTypes)
            {
                if (!Fields.TryGetValue(t, out var member))
                {
                    member = FindOneCopy(t);
                    Fields[t] = member;
                }
                if (member == null) continue;
                foreach (var o in Resources.FindObjectsOfTypeAll(t))
                {
                    if (!(o is MonoBehaviour m) || m == null || m.gameObject.scene.handle != scene.handle) continue;
                    Write(member, m);
                    m.enabled = true;
                    n++;
                    break;
                }
            }
            return n;
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
                var member = FindOneCopy(t);
                Fields[t] = member;
                if (member != null) found.Add(t.FullName);
            }
            return found.ToArray();
        }
    }
}
