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

        // Scenes to switch off the moment they finish loading, and what was
        // switched off in each.
        private static readonly HashSet<string> Quiet = new HashSet<string>();
        private static readonly Dictionary<string, List<GameObject>> SwitchedOff = new Dictionary<string, List<GameObject>>();
        private static bool _hooked;

        /// <summary>
        /// Call before loading a scene alongside: when it has loaded, its
        /// top objects that are on are switched off in Unity's sceneLoaded,
        /// which runs after Awake and OnEnable and before any Start, so
        /// nothing in the scene starts (no Start, no coroutines, no start
        /// events) until it is switched on.
        /// </summary>
        public static void LoadQuietly(string sceneName)
        {
            if (!_hooked)
            {
                SceneManager.sceneLoaded += OnSceneLoaded;
                _hooked = true;
            }
            Quiet.Add(sceneName);
            NeverEntered.Add(sceneName);
        }

        // Scenes loaded quietly and not switched on since: their objects
        // woke (Awake, OnEnable) but never started.
        private static readonly HashSet<string> NeverEntered = new HashSet<string>();

        /// <summary>The player entered a scene loaded quietly: its objects start.</summary>
        public static void Entered(string sceneName)
        {
            NeverEntered.Remove(sceneName);
        }

        /// <summary>
        /// True when the component's object is in a scene loaded quietly and
        /// never entered, so its Start never ran.
        /// </summary>
        public static bool InAreaNeverEntered(object me)
        {
            return me is Component c && c != null && NeverEntered.Contains(c.gameObject.scene.name);
        }

        private static void OnSceneLoaded(Scene scene, LoadSceneMode mode)
        {
            if (!Quiet.Remove(scene.name)) return;
            var off = new List<GameObject>();
            foreach (var top in scene.GetRootGameObjects())
            {
                if (!top.activeSelf) continue;
                top.SetActive(false);
                off.Add(top);
            }
            SwitchedOff[scene.name] = off;
        }

        /// <summary>
        /// The top objects LoadQuietly switched off in a scene, once; empty
        /// when none.
        /// </summary>
        public static GameObject[] TakeSwitchedOff(string sceneName)
        {
            if (!SwitchedOff.TryGetValue(sceneName, out var off)) return new GameObject[0];
            SwitchedOff.Remove(sceneName);
            return off.ToArray();
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
