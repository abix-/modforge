// HandleArg.cs. Shared resolution of the {"$handle": N} argument
// form: an invoke_method / write_field arg that references a LIVE
// object from the bridge's handle table instead of JSON data.
//
// This is the input half of generic op chaining (the output half
// is complex values carrying a "handle" in their JSON). Both
// backends support it via this one helper; each passes its own
// handle-table lookup.

using System;
using System.Collections.Generic;
using Newtonsoft.Json.Linq;

namespace Unityforge.Shim
{
    public static class HandleArg
    {
        public const string Key = "$handle";

        /// <summary>
        /// True when tok is {"$handle": N}; value is then the live
        /// object from the backend's handle table (null if the
        /// handle is stale, which the caller surfaces as a normal
        /// conversion failure).
        /// </summary>
        public static bool TryResolve(JToken tok, Func<int, object> lookup, out object value)
        {
            value = null;
            if (tok is JObject o
                && o.TryGetValue(Key, out var h)
                && (h.Type == JTokenType.Integer))
            {
                value = lookup((int)h);
                return true;
            }
            return false;
        }
    }

    /// <summary>
    /// Handles that survive a hot reload. Both backends keep the
    /// same handle table shape (Dictionary + next id); this is the
    /// one implementation of marking a handle and of the clear that
    /// spares the marked ones, so the next generation can take the
    /// object over by the same id. Callers hold their table lock.
    /// </summary>
    public static class HandleKeep
    {
        public static void Mark(HashSet<int> kept, int handle, int keep)
        {
            if (handle == 0) return;
            if (keep != 0) kept.Add(handle);
            else kept.Remove(handle);
        }

        /// <summary>
        /// Empty the table except marked handles; the marks stay so
        /// they survive later reloads until released or unmarked.
        /// </summary>
        public static void Clear(Dictionary<int, object> handles, HashSet<int> kept, ref int next)
        {
            var survivors = new Dictionary<int, object>();
            foreach (var h in kept)
            {
                if (handles.TryGetValue(h, out var v)) survivors[h] = v;
            }
            handles.Clear();
            kept.Clear();
            next = 1;
            foreach (var kv in survivors)
            {
                handles[kv.Key] = kv.Value;
                kept.Add(kv.Key);
                if (kv.Key >= next) next = kv.Key + 1;
            }
        }
    }
}
