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

        private static FieldInfo FindField(Type type)
        {
            const BindingFlags flags = BindingFlags.Public | BindingFlags.Static | BindingFlags.DeclaredOnly;
            foreach (var name in new[] { "instance", "active" })
            {
                var f = type.GetField(name, flags);
                if (f != null && type.IsAssignableFrom(f.FieldType)) return f;
            }
            return null;
        }
    }
}
