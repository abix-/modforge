// SceneTools.cs. Scene calls the bridge cannot make itself: Scene is a
// struct, and invoke_method needs a live object handle, so a method on a
// Scene value (GetRootGameObjects) is out of reach from Rust. Static
// methods here take the scene by name; Rust calls them with
// invoke_static("Unityforge.Shim.SceneTools", ...).
//
// First user: obenseuer-mod's kept_loaded (areas kept loaded, only the
// one the player is in switched on).

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace Unityforge.Shim
{
    public static class SceneTools
    {
        /// <summary>
        /// The top objects of a loaded scene, switched on or off. Empty
        /// when no loaded scene has that name. Objects kept through scene
        /// changes (DontDestroyOnLoad) are not in any named scene.
        /// </summary>
        public static GameObject[] RootsOf(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            return scene.IsValid() && scene.isLoaded ? scene.GetRootGameObjects() : new GameObject[0];
        }

        // Scene names to load quietly, waiting for their load alongside to
        // finish. A name, because the scene does not exist yet.
        private static readonly HashSet<string> Quiet = new HashSet<string>();
        // Per load of a scene (Scene.handle, new on every load; the game
        // never has two loads of one area, so a name is not a load: kept by
        // name, a later normal load of an area loaded quietly once counted
        // as never entered and its Spawners' OnDestroy was skipped).
        // Loads loaded quietly and not switched on since: their objects
        // woke (Awake, OnEnable) but never started.
        private static readonly HashSet<int> NeverEntered = new HashSet<int>();
        // The top objects switched off in each load loaded quietly.
        private static readonly Dictionary<int, List<GameObject>> SwitchedOff = new Dictionary<int, List<GameObject>>();
        private static bool _hooked;

        /// <summary>
        /// Call before loading a scene alongside (LoadSceneMode.Additive):
        /// when it has loaded, its top objects that are on are switched off
        /// in Unity's sceneLoaded, which runs after Awake and OnEnable and
        /// before any Start, so nothing in the scene starts (no Start, no
        /// coroutines, no start events) until it is switched on. The game's
        /// own loads (single mode) are never taken.
        /// </summary>
        public static void LoadQuietly(string sceneName)
        {
            if (!_hooked)
            {
                SceneManager.sceneLoaded += OnSceneLoaded;
                SceneManager.sceneUnloaded += OnSceneUnloaded;
                _hooked = true;
            }
            Quiet.Add(sceneName);
        }

        /// <summary>The player entered a scene loaded quietly: its objects start.</summary>
        public static void Entered(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (scene.IsValid()) NeverEntered.Remove(scene.handle);
        }

        /// <summary>
        /// True when the component's object is in a load loaded quietly and
        /// never entered, so its Start never ran.
        /// </summary>
        public static bool InAreaNeverEntered(object me)
        {
            return me is Component c && c != null && NeverEntered.Contains(c.gameObject.scene.handle);
        }

        private static void OnSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            if (mode != LoadSceneMode.Additive || !Quiet.Remove(scene.name)) return;
            // Before switching off: OnDisable on objects never started is
            // told apart by this (FirstCopyGuard.NeverStartedFinalizer).
            NeverEntered.Add(scene.handle);
            // Area-owned managers out of the area's copy of the player setup
            // (Game_Logic, kept off) to the top of the area: its content, on
            // and off with it, saved and loaded with it (docs/kept-areas.md,
            // rule 1, which copy). Each sits alone on its own object.
            foreach (var top in scene.GetRootGameObjects())
            {
                foreach (var m in top.GetComponentsInChildren<MonoBehaviour>(true))
                {
                    if (m != null && m.transform.parent != null && FirstCopyGuard.IsAreaOwned(m.GetType())) m.transform.SetParent(null, true);
                }
            }
            var off = new List<GameObject>();
            foreach (var top in scene.GetRootGameObjects())
            {
                if (!top.activeSelf) continue;
                top.SetActive(false);
                off.Add(top);
            }
            SwitchedOff[scene.handle] = off;
        }

        // A load is gone: what was kept about it goes with it.
        private static void OnSceneUnloaded(Scene scene)
        {
            NeverEntered.Remove(scene.handle);
            SwitchedOff.Remove(scene.handle);
        }

        /// <summary>
        /// The top objects LoadQuietly switched off in the loaded scene of
        /// that name, once; empty when none.
        /// </summary>
        public static GameObject[] TakeSwitchedOff(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid() || !SwitchedOff.TryGetValue(scene.handle, out var off)) return new GameObject[0];
            SwitchedOff.Remove(scene.handle);
            return off.ToArray();
        }

        /// <summary>
        /// The name of the scene a component or game object is in; empty
        /// when it is destroyed or not one.
        /// </summary>
        public static string SceneOf(object o)
        {
            if (o is Component c && c != null) return c.gameObject.scene.name;
            if (o is GameObject g && g != null) return g.scene.name;
            return "";
        }

        /// <summary>
        /// Makes a loaded scene the active one: objects created while the
        /// game runs go into the active scene. False when no loaded scene
        /// has that name.
        /// </summary>
        public static bool SetActive(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            return scene.IsValid() && scene.isLoaded && SceneManager.SetActiveScene(scene);
        }
    }
}
