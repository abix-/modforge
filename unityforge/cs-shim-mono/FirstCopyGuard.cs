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
        // Class -> its one-copy static field ("instance", or "active" as on
        // AstarPath); null when it has none.
        private static readonly Dictionary<Type, FieldInfo> Fields = new Dictionary<Type, FieldInfo>();

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
            if (!Fields.TryGetValue(type, out var field))
            {
                field = FindField(type);
                Fields[type] = field;
            }
            if (field == null) return "";
            // Unity's == treats a destroyed object as null.
            var current = field.GetValue(null) as UnityEngine.Object;
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
            return SceneTools.InAreaNeverEntered(me) ? me.GetType().FullName + " (never started)" : "";
        }

        /// <summary>
        /// Every MonoBehaviour class in an assembly that declares OnDestroy
        /// and has a Start: whose OnDestroy may undo what Start did.
        /// </summary>
        public static string[] StartAndOnDestroyClasses(string assemblyOfType)
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
                found.Add(t.FullName);
            }
            return found.ToArray();
        }

        /// <summary>
        /// A class's one-copy field: a public static field of the class's
        /// own type, whatever its name ("instance", AstarPath's "active",
        /// PlayerIdentity's "identity"). Null when it has none.
        /// </summary>
        private static FieldInfo FindField(Type type)
        {
            const BindingFlags flags = BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly;
            foreach (var f in type.GetFields(flags))
            {
                if (f.FieldType == type) return f;
            }
            return null;
        }

        /// <summary>
        /// Every MonoBehaviour class in an assembly with a one-copy field
        /// (FindField): the classes obenseuer-mod's first_copy_wins guards.
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
                var f = FindField(t);
                Fields[t] = f;
                if (f != null) found.Add(t.FullName);
            }
            return found.ToArray();
        }
    }
}
