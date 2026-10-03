// EventTools.cs. Game-wide events and areas kept loaded (obenseuer-mod
// docs/kept-areas.md, rule 1, game-wide events): an area left is switched
// off, not destroyed, so its objects keep the handlers they added and would
// remove only in OnDestroy. In the game the area is destroyed and they stop
// reacting. Leaving takes those handlers out of the game's static events
// and of the events on the managers' live copies, and keeps them for that
// load of the area; entering puts them back.

using System;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace Unityforge.Shim
{
    public static class EventTools
    {
        // A handler taken out: the event's owner (null for a static event),
        // its field, the handler.
        private sealed class Taken
        {
            public object Owner;
            public FieldInfo Field;
            public Delegate Handler;
        }

        // The static event (delegate) fields of the assembly, found once.
        private static List<FieldInfo> _statics;
        // Instance event (delegate) fields per class, found once each.
        private static readonly Dictionary<Type, List<FieldInfo>> Instance = new Dictionary<Type, List<FieldInfo>>();
        // Per load of a scene (Scene.handle): the handlers taken out.
        private static readonly Dictionary<int, List<Taken>> Kept = new Dictionary<int, List<Taken>>();
        private static bool _hooked;

        // What is kept about a load of a scene goes when it unloads.
        private static void Hook()
        {
            if (_hooked) return;
            SceneManager.sceneUnloaded += s =>
            {
                Kept.Remove(s.handle);
                KeptEntries.Remove(s.handle);
            };
            _hooked = true;
        }

        private static List<FieldInfo> Statics(string assemblyOfType)
        {
            if (_statics != null) return _statics;
            _statics = new List<FieldInfo>();
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return _statics;
            Type[] types;
            try { types = anchor.Assembly.GetTypes(); }
            catch (ReflectionTypeLoadException e) { types = e.Types; }
            const BindingFlags flags = BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.DeclaredOnly;
            foreach (var t in types)
            {
                if (t == null || t.ContainsGenericParameters) continue;
                foreach (var f in t.GetFields(flags))
                {
                    if (!f.IsLiteral && typeof(Delegate).IsAssignableFrom(f.FieldType)) _statics.Add(f);
                }
            }
            return _statics;
        }

        private static List<FieldInfo> InstanceEvents(Type type)
        {
            if (Instance.TryGetValue(type, out var found)) return found;
            found = new List<FieldInfo>();
            const BindingFlags flags = BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.DeclaredOnly;
            for (var t = type; t != null && t != typeof(MonoBehaviour); t = t.BaseType)
            {
                foreach (var f in t.GetFields(flags))
                {
                    if (typeof(Delegate).IsAssignableFrom(f.FieldType)) found.Add(f);
                }
            }
            Instance[type] = found;
            return found;
        }

        // Classes marked: their class has the marker field, or holds a plain
        // object (not a Unity object) whose type has it.
        private static readonly Dictionary<Type, bool> Marked = new Dictionary<Type, bool>();

        private static bool HasMark(Type t, string field)
        {
            if (string.IsNullOrEmpty(field)) return false;
            if (Marked.TryGetValue(t, out var marked)) return marked;
            const BindingFlags any = BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic;
            marked = false;
            for (var c = t; c != null && c != typeof(MonoBehaviour) && !marked; c = c.BaseType)
            {
                foreach (var f in c.GetFields(any | BindingFlags.DeclaredOnly))
                {
                    if (f.Name == field || (!f.FieldType.IsPrimitive && f.FieldType != typeof(string) && !typeof(UnityEngine.Object).IsAssignableFrom(f.FieldType) && f.FieldType.GetField(field, any) != null))
                    {
                        marked = true;
                        break;
                    }
                }
            }
            Marked[t] = marked;
            return marked;
        }

        // Takes out of one event the handlers of switched-off objects in the
        // scene; returns how many. On a kept event ("Class.Field": the game's
        // clock, an area left keeps time) the handlers of marked classes
        // (the game catches them up on load) stay.
        private static int TakeOut(object owner, FieldInfo field, int scene, List<Taken> kept, HashSet<string> keep, string mark)
        {
            var all = field.GetValue(owner) as Delegate;
            if (all == null) return 0;
            bool kepth = keep.Contains(field.DeclaringType.Name + "." + field.Name);
            var left = all;
            int n = 0;
            foreach (var d in all.GetInvocationList())
            {
                if (d.Target is Component c && c != null && c.gameObject.scene.handle == scene && !c.gameObject.activeInHierarchy
                    && !(kepth && HasMark(c.GetType(), mark)))
                {
                    left = Delegate.Remove(left, d);
                    kept.Add(new Taken { Owner = owner, Field = field, Handler = d });
                    n++;
                }
            }
            if (!ReferenceEquals(left, all)) field.SetValue(owner, left);
            return n;
        }

        /// <summary>
        /// After an area was switched off on leaving: takes out of every
        /// static event of the assembly, and every event on the managers'
        /// live copies, the handlers whose object is in that area and
        /// switched off (the live player and managers stay on, so theirs
        /// stay). `keepCsv` names events ("Class.Field") on which the
        /// handlers of classes marked by the field `mark` stay. Returns how
        /// many.
        /// </summary>
        public static int LeaveArea(string assemblyOfType, string sceneName, string keepCsv, string mark)
        {
            var keep = new HashSet<string>(keepCsv.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries));
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return 0;
            Hook();
            if (!Kept.TryGetValue(scene.handle, out var kept))
            {
                kept = new List<Taken>();
                Kept[scene.handle] = kept;
            }
            int n = 0;
            foreach (var f in Statics(assemblyOfType)) n += TakeOut(null, f, scene.handle, kept, keep, mark);
            foreach (var copy in FirstCopyGuard.LiveCopies())
            {
                foreach (var f in InstanceEvents(copy.GetType())) n += TakeOut(copy, f, scene.handle, kept, keep, mark);
            }
            return n;
        }

        /// <summary>
        /// On entering an area: puts back the handlers taken out when it was
        /// left, each only when the event does not hold it already (a Start
        /// run again subscribes again), and not for destroyed objects or
        /// owners. Returns how many.
        /// </summary>
        public static int EnterArea(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid() || !Kept.TryGetValue(scene.handle, out var kept)) return 0;
            Kept.Remove(scene.handle);
            int n = 0;
            foreach (var t in kept)
            {
                if (t.Handler.Target is UnityEngine.Object o && o == null) continue;
                if (t.Owner is UnityEngine.Object owner && owner == null) continue;
                var all = t.Field.GetValue(t.Owner) as Delegate;
                if (all != null && Array.IndexOf(all.GetInvocationList(), t.Handler) >= 0) continue;
                t.Field.SetValue(t.Owner, Delegate.Combine(all, t.Handler));
                n++;
            }
            return n;
        }

        // ---- Game-wide lists (docs/kept-areas.md, rule 1, game-wide lists).
        // In the game an area's objects leave the game-wide lists when the
        // area is destroyed (their OnDestroy, or the list's owner rebuilt by
        // the load). An area left is switched off, not destroyed: leaving
        // takes its objects out of the lists, entering puts them back.

        // An entry taken out: the list's owner (null for a static list), its
        // field, the entry (for a dictionary, the key and the value).
        private sealed class TakenEntry
        {
            public object Owner;
            public FieldInfo Field;
            public object Key;
            public object Value;
        }

        private static List<FieldInfo> _staticLists;
        private static readonly Dictionary<Type, List<FieldInfo>> InstanceLists = new Dictionary<Type, List<FieldInfo>>();
        private static readonly Dictionary<int, List<TakenEntry>> KeptEntries = new Dictionary<int, List<TakenEntry>>();
        private static readonly Dictionary<Type, FieldInfo[]> DelegateFields = new Dictionary<Type, FieldInfo[]>();

        // A list, dictionary or set (not an array: arrays are fixed data).
        private static bool IsList(Type t)
        {
            if (t.IsArray) return false;
            if (typeof(System.Collections.IList).IsAssignableFrom(t) || typeof(System.Collections.IDictionary).IsAssignableFrom(t)) return true;
            return t.IsGenericType && t.GetGenericTypeDefinition() == typeof(HashSet<>);
        }

        private static List<FieldInfo> StaticLists(string assemblyOfType)
        {
            if (_staticLists != null) return _staticLists;
            _staticLists = new List<FieldInfo>();
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return _staticLists;
            Type[] types;
            try { types = anchor.Assembly.GetTypes(); }
            catch (ReflectionTypeLoadException e) { types = e.Types; }
            const BindingFlags flags = BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.DeclaredOnly;
            foreach (var t in types)
            {
                if (t == null || t.ContainsGenericParameters) continue;
                foreach (var f in t.GetFields(flags))
                {
                    if (!f.IsLiteral && IsList(f.FieldType)) _staticLists.Add(f);
                }
            }
            return _staticLists;
        }

        private static List<FieldInfo> ListsOf(Type type)
        {
            if (InstanceLists.TryGetValue(type, out var found)) return found;
            found = new List<FieldInfo>();
            const BindingFlags flags = BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.DeclaredOnly;
            for (var t = type; t != null && t != typeof(MonoBehaviour); t = t.BaseType)
            {
                foreach (var f in t.GetFields(flags))
                {
                    if (IsList(f.FieldType)) found.Add(f);
                }
            }
            InstanceLists[type] = found;
            return found;
        }

        // Belongs to the scene's switched-off objects: one of them, or a
        // plain object whose callbacks (delegate fields) point at one (the
        // game's timers, TimeOfDayAzure.Timer).
        private static bool Belongs(object o, int scene)
        {
            if (o is Component c) return c != null && c.gameObject.scene.handle == scene && !c.gameObject.activeInHierarchy;
            if (o == null || o is UnityEngine.Object || o is string || o.GetType().IsPrimitive) return false;
            var type = o.GetType();
            if (!DelegateFields.TryGetValue(type, out var fields))
            {
                var list = new List<FieldInfo>();
                foreach (var f in type.GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic))
                {
                    if (typeof(Delegate).IsAssignableFrom(f.FieldType)) list.Add(f);
                }
                fields = list.ToArray();
                DelegateFields[type] = fields;
            }
            foreach (var f in fields)
            {
                if (f.GetValue(o) is Delegate d && d.Target is Component t && t != null && t.gameObject.scene.handle == scene && !t.gameObject.activeInHierarchy) return true;
            }
            return false;
        }

        private static int TakeEntries(object owner, FieldInfo field, int scene, List<TakenEntry> kept)
        {
            var value = field.GetValue(owner);
            if (value == null) return 0;
            int n = 0;
            if (value is System.Collections.IDictionary dict)
            {
                var keys = new List<object>();
                foreach (System.Collections.DictionaryEntry e in dict)
                {
                    if (Belongs(e.Key, scene) || Belongs(e.Value, scene)) keys.Add(e.Key);
                }
                foreach (var k in keys)
                {
                    kept.Add(new TakenEntry { Owner = owner, Field = field, Key = k, Value = dict[k] });
                    dict.Remove(k);
                    n++;
                }
            }
            else if (value is System.Collections.IList list)
            {
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    if (!Belongs(list[i], scene)) continue;
                    kept.Add(new TakenEntry { Owner = owner, Field = field, Value = list[i] });
                    list.RemoveAt(i);
                    n++;
                }
            }
            else if (value is System.Collections.IEnumerable set)
            {
                var remove = value.GetType().GetMethod("Remove");
                var items = new List<object>();
                foreach (var item in set)
                {
                    if (Belongs(item, scene)) items.Add(item);
                }
                foreach (var item in items)
                {
                    kept.Add(new TakenEntry { Owner = owner, Field = field, Value = item });
                    remove.Invoke(value, new[] { item });
                    n++;
                }
            }
            return n;
        }

        /// <summary>
        /// After an area was switched off on leaving: takes its switched-off
        /// objects (and timers calling back into them) out of every static
        /// list, dictionary and set of the assembly and of those on the
        /// managers' live copies, as the area's destruction would; kept for
        /// that load of the area. Returns how many.
        /// </summary>
        public static int LeaveAreaLists(string assemblyOfType, string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return 0;
            Hook();
            if (!KeptEntries.TryGetValue(scene.handle, out var kept))
            {
                kept = new List<TakenEntry>();
                KeptEntries[scene.handle] = kept;
            }
            int n = 0;
            foreach (var f in StaticLists(assemblyOfType)) n += TakeEntries(null, f, scene.handle, kept);
            foreach (var copy in FirstCopyGuard.LiveCopies())
            {
                // The area's own managers (area-owned, in the area left):
                // their lists are the area's own data (its arrival points,
                // its NPCs), destroyed with it in the game, not taken from.
                if (copy is Component own && own != null && own.gameObject.scene.handle == scene.handle) continue;
                foreach (var f in ListsOf(copy.GetType())) n += TakeEntries(copy, f, scene.handle, kept);
            }
            return n;
        }

        /// <summary>
        /// On entering an area, after its load steps ran (they put some
        /// entries back themselves: a timer's OnLoading): puts back the
        /// entries taken out when it was left, each only when its list does
        /// not hold it already. Returns how many.
        /// </summary>
        public static int EnterAreaLists(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid() || !KeptEntries.TryGetValue(scene.handle, out var kept)) return 0;
            KeptEntries.Remove(scene.handle);
            int n = 0;
            foreach (var t in kept)
            {
                if (t.Owner is UnityEngine.Object owner && owner == null) continue;
                if (t.Value is UnityEngine.Object v && v == null) continue;
                var value = t.Field.GetValue(t.Owner);
                if (value is System.Collections.IDictionary dict)
                {
                    if (dict.Contains(t.Key)) continue;
                    dict.Add(t.Key, t.Value);
                }
                else if (value is System.Collections.IList list)
                {
                    if (list.Contains(t.Value)) continue;
                    list.Add(t.Value);
                }
                else if (value != null)
                {
                    value.GetType().GetMethod("Add").Invoke(value, new[] { t.Value });
                }
                else continue;
                n++;
            }
            return n;
        }

        // ---- Load steps on an area entered again (docs/kept-areas.md, rule 2).

        /// <summary>
        /// One of the game's save or load steps (a SavableScript method, by
        /// name) on a scene's top objects, as SaveController
        /// .ExecuteSaveLoadFunctions does (SaveController.cs:1113-1198):
        /// every SavableScript under them, in hierarchy order, whose object
        /// is on. Skips classes marked by the field `mark` (they kept the
        /// game's clock while away: their catch-up already ran) and classes
        /// named in `skipCsv` or deriving from one (their step creates
        /// objects that still exist). `skipLiveSet`: also skips the top
        /// objects holding the managers' live copies (the live player and
        /// game-wide managers, in the area the save loaded): on a later
        /// visit they are not the area's content (re-running
        /// TenementController's load rebuilt another area's doors). Returns
        /// how many ran.
        /// </summary>
        public static int RunStep(string assemblyOfType, string sceneName, string step, string mark, string skipCsv, bool skipLiveSet)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            var savable = Type.GetType(assemblyOfType)?.Assembly.GetType("SavableScript");
            var method = savable?.GetMethod(step, BindingFlags.Instance | BindingFlags.Public);
            if (!scene.IsValid() || !scene.isLoaded || method == null) return 0;
            var skip = new HashSet<string>(skipCsv.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries));
            var liveTops = new HashSet<GameObject>();
            if (skipLiveSet)
            {
                foreach (var copy in FirstCopyGuard.LiveCopies())
                {
                    if (copy is Component c && c != null) liveTops.Add(c.transform.root.gameObject);
                }
            }
            int n = 0;
            foreach (var top in scene.GetRootGameObjects())
            {
                if (top == null || top.transform.parent != null || liveTops.Contains(top)) continue;
                foreach (var c in top.GetComponentsInChildren(savable, false))
                {
                    if (c == null || !c.gameObject.activeInHierarchy) continue;
                    if (HasMark(c.GetType(), mark) || Named(c.GetType(), skip)) continue;
                    try
                    {
                        method.Invoke(c, null);
                        n++;
                    }
                    catch (Exception e)
                    {
                        Debug.LogException(e.InnerException ?? e);
                    }
                }
            }
            return n;
        }

        private static bool Named(Type t, HashSet<string> names)
        {
            for (var c = t; c != null && c != typeof(MonoBehaviour); c = c.BaseType)
            {
                if (names.Contains(c.Name)) return true;
            }
            return false;
        }
    }
}
