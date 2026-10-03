// EventTools.cs. Game-wide (static) events and areas kept loaded
// (obenseuer-mod docs/kept-areas.md, rule 1, game-wide events): an area
// left is switched off, not destroyed, so its objects keep the handlers
// they added in Start and would remove only in OnDestroy. In the game the
// area is destroyed and they stop reacting. Leaving takes those handlers
// out and keeps them for that load of the area; entering puts them back.

using System;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace Unityforge.Shim
{
    public static class EventTools
    {
        // The static event (delegate) fields of the assembly, found once.
        private static List<FieldInfo> _events;
        // Per load of a scene (Scene.handle): the handlers taken out.
        private static readonly Dictionary<int, List<KeyValuePair<FieldInfo, Delegate>>> Kept = new Dictionary<int, List<KeyValuePair<FieldInfo, Delegate>>>();
        private static bool _hooked;

        private static List<FieldInfo> Events(string assemblyOfType)
        {
            if (_events != null) return _events;
            _events = new List<FieldInfo>();
            var anchor = Type.GetType(assemblyOfType);
            if (anchor == null) return _events;
            Type[] types;
            try { types = anchor.Assembly.GetTypes(); }
            catch (ReflectionTypeLoadException e) { types = e.Types; }
            const BindingFlags flags = BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.DeclaredOnly;
            foreach (var t in types)
            {
                if (t == null || t.ContainsGenericParameters) continue;
                foreach (var f in t.GetFields(flags))
                {
                    if (!f.IsLiteral && typeof(Delegate).IsAssignableFrom(f.FieldType)) _events.Add(f);
                }
            }
            return _events;
        }

        /// <summary>
        /// After an area was switched off on leaving: takes out of every
        /// static event of the assembly the handlers whose object is in
        /// that area and switched off (the live player and managers stay
        /// on, so theirs stay). Returns how many.
        /// </summary>
        public static int LeaveArea(string assemblyOfType, string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return 0;
            if (!_hooked)
            {
                SceneManager.sceneUnloaded += s => Kept.Remove(s.handle);
                _hooked = true;
            }
            if (!Kept.TryGetValue(scene.handle, out var kept))
            {
                kept = new List<KeyValuePair<FieldInfo, Delegate>>();
                Kept[scene.handle] = kept;
            }
            int n = 0;
            foreach (var f in Events(assemblyOfType))
            {
                var all = f.GetValue(null) as Delegate;
                if (all == null) continue;
                var left = all;
                foreach (var d in all.GetInvocationList())
                {
                    if (d.Target is Component c && c != null && c.gameObject.scene.handle == scene.handle && !c.gameObject.activeInHierarchy)
                    {
                        left = Delegate.Remove(left, d);
                        kept.Add(new KeyValuePair<FieldInfo, Delegate>(f, d));
                        n++;
                    }
                }
                if (!ReferenceEquals(left, all)) f.SetValue(null, left);
            }
            return n;
        }

        /// <summary>
        /// On entering an area: puts back the handlers taken out when it was
        /// left, each only when the event does not hold it already (a Start
        /// run again subscribes again), and not for destroyed objects.
        /// Returns how many.
        /// </summary>
        public static int EnterArea(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid() || !Kept.TryGetValue(scene.handle, out var kept)) return 0;
            Kept.Remove(scene.handle);
            int n = 0;
            foreach (var pair in kept)
            {
                if (pair.Value.Target is UnityEngine.Object o && o == null) continue;
                var all = pair.Key.GetValue(null) as Delegate;
                if (all != null && Array.IndexOf(all.GetInvocationList(), pair.Value) >= 0) continue;
                pair.Key.SetValue(null, Delegate.Combine(all, pair.Value));
                n++;
            }
            return n;
        }
    }
}
