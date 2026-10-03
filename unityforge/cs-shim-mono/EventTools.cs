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

        // Takes out of one event the handlers of switched-off objects in the
        // scene; returns how many. On a kept event ("Class.Field", the game's
        // clock: an area left keeps time) only area-owned managers' handlers
        // are taken out.
        private static int TakeOut(object owner, FieldInfo field, int scene, List<Taken> kept, HashSet<string> keep)
        {
            var all = field.GetValue(owner) as Delegate;
            if (all == null) return 0;
            bool kepth = keep.Contains(field.DeclaringType.Name + "." + field.Name);
            var left = all;
            int n = 0;
            foreach (var d in all.GetInvocationList())
            {
                if (d.Target is Component c && c != null && c.gameObject.scene.handle == scene && !c.gameObject.activeInHierarchy
                    && (!kepth || FirstCopyGuard.IsAreaOwned(c.GetType())))
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
        /// stay). `keepCsv` names events ("Class.Field") on which only
        /// area-owned managers' handlers are taken out. Returns how many.
        /// </summary>
        public static int LeaveArea(string assemblyOfType, string sceneName, string keepCsv)
        {
            var keep = new HashSet<string>(keepCsv.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries));
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return 0;
            if (!_hooked)
            {
                SceneManager.sceneUnloaded += s => Kept.Remove(s.handle);
                _hooked = true;
            }
            if (!Kept.TryGetValue(scene.handle, out var kept))
            {
                kept = new List<Taken>();
                Kept[scene.handle] = kept;
            }
            int n = 0;
            foreach (var f in Statics(assemblyOfType)) n += TakeOut(null, f, scene.handle, kept, keep);
            foreach (var copy in FirstCopyGuard.LiveCopies())
            {
                foreach (var f in InstanceEvents(copy.GetType())) n += TakeOut(copy, f, scene.handle, kept, keep);
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
    }
}
