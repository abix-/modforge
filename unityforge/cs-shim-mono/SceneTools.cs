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

        /// <summary>
        /// `me` is in an area the mod is loading alongside or loaded
        /// alongside and never entered. Its Awake runs before sceneLoaded,
        /// so the area is still only in the quiet list then.
        /// </summary>
        public static bool InQuietArea(object me)
        {
            return me is Component c && c != null && (Quiet.Contains(c.gameObject.scene.name) || NeverEntered.Contains(c.gameObject.scene.handle));
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
            // rule 1, which copy). Each sits alone on its own object. The
            // others are already the area's content and stay put
            // (SkyCamera is placed relative to its parent).
            foreach (var top in scene.GetRootGameObjects())
            {
                if (top.name != "Game_Logic") continue;
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
        /// Runs a method again on every switched-on object of a class (its
        /// subclasses too) in a loaded scene: a Start (Unity runs it once
        /// per object, the game on every load of the area), or a coroutine
        /// method, which is started (Unity stops coroutines when an object
        /// switches off and does not restart them). Returns how many.
        /// </summary>
        public static int RunAgain(string sceneName, string assemblyOfType, string className, string method)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            var anchor = System.Type.GetType(assemblyOfType);
            var type = anchor?.Assembly.GetType(className);
            var m = type?.GetMethod(method, System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.NonPublic, null, System.Type.EmptyTypes, null);
            if (!scene.IsValid() || m == null) return 0;
            int n = 0;
            foreach (var o in Resources.FindObjectsOfTypeAll(type))
            {
                if (!(o is MonoBehaviour b) || b == null || b.gameObject.scene.handle != scene.handle || !b.isActiveAndEnabled) continue;
                try
                {
                    if (m.Invoke(b, null) is System.Collections.IEnumerator routine) b.StartCoroutine(routine);
                    n++;
                }
                catch (System.Exception e)
                {
                    Debug.LogException(e);
                }
            }
            return n;
        }

        /// <summary>
        /// Every running Animator in a loaded scene as "path | parameters |
        /// state": its object's path, its bool, int and float parameters
        /// (floats to 2 decimals; triggers left out) and the short name hash
        /// of each layer's current state. For comparing an area after a
        /// kept door with the game's load of it.
        /// </summary>
        public static string[] AnimatorStates(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            var found = new List<string>();
            if (!scene.IsValid()) return found.ToArray();
            foreach (var top in scene.GetRootGameObjects())
            {
                foreach (var a in top.GetComponentsInChildren<Animator>(false))
                {
                    if (a == null || !a.isActiveAndEnabled || a.runtimeAnimatorController == null) continue;
                    var path = new List<string>();
                    for (var t = a.transform; t != null; t = t.parent) path.Insert(0, t.name);
                    var values = new List<string>();
                    foreach (var p in a.parameters)
                    {
                        var kind = p.type.ToString();
                        if (kind == "Bool") values.Add(p.name + "=" + a.GetBool(p.nameHash));
                        else if (kind == "Int") values.Add(p.name + "=" + a.GetInteger(p.nameHash));
                        else if (kind == "Float") values.Add(p.name + "=" + a.GetFloat(p.nameHash).ToString("0.00"));
                    }
                    var states = new List<string>();
                    for (int l = 0; l < a.layerCount; l++) states.Add(a.GetCurrentAnimatorStateInfo(l).shortNameHash.ToString());
                    found.Add(string.Join(" / ", path) + " | " + string.Join(",", values) + " | " + string.Join(",", states));
                }
            }
            return found.ToArray();
        }

        // Per load of a scene: the AudioSources that were playing when it was
        // switched off (RememberPlaying), started again on switch-on.
        private static readonly Dictionary<int, List<AudioSource>> Playing = new Dictionary<int, List<AudioSource>>();

        /// <summary>
        /// Before an area is switched off: remembers its playing
        /// AudioSources, but not those under a soundscape (`ownerClass`,
        /// named by `assemblyOfType`; the game's soundscape code starts
        /// those). A sound a script started in Start stops when its object is
        /// switched off and nothing starts it again; in the game the fresh
        /// object's Start does (a machine's hum, a fan). Returns how many.
        /// </summary>
        public static int RememberPlaying(string sceneName, string assemblyOfType, string ownerClass)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid()) return 0;
            var owner = System.Type.GetType(assemblyOfType)?.Assembly.GetType(ownerClass);
            var list = new List<AudioSource>();
            foreach (var top in scene.GetRootGameObjects())
            {
                foreach (var s in top.GetComponentsInChildren<AudioSource>(false))
                {
                    if (s == null || !s.isActiveAndEnabled || !s.isPlaying) continue;
                    if (owner != null && s.GetComponentInParent(owner) != null) continue;
                    list.Add(s);
                }
            }
            Playing[scene.handle] = list;
            return list.Count;
        }

        /// <summary>
        /// After an area is switched on: starts again the sounds
        /// RememberPlaying recorded, those still there and not playing.
        /// Returns how many.
        /// </summary>
        public static int ResumePlaying(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            if (!scene.IsValid() || !Playing.TryGetValue(scene.handle, out var list)) return 0;
            Playing.Remove(scene.handle);
            int n = 0;
            foreach (var s in list)
            {
                if (s == null || !s.isActiveAndEnabled || s.isPlaying) continue;
                s.Play();
                n++;
            }
            return n;
        }

        /// <summary>
        /// Every AudioSource playing in a loaded scene as "path | clip": for
        /// comparing an area after a kept door with the game's load of it
        /// (a sound a script started stops when its object is switched off
        /// and does not start again when it is switched on).
        /// </summary>
        public static string[] PlayingSounds(string sceneName)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            var found = new List<string>();
            if (!scene.IsValid()) return found.ToArray();
            foreach (var top in scene.GetRootGameObjects())
            {
                foreach (var s in top.GetComponentsInChildren<AudioSource>(false))
                {
                    if (s == null || !s.isActiveAndEnabled || !s.isPlaying) continue;
                    var path = new List<string>();
                    for (var t = s.transform; t != null; t = t.parent) path.Insert(0, t.name);
                    found.Add(string.Join(" / ", path) + " | " + (s.clip != null ? s.clip.name : ""));
                }
            }
            return found.ToArray();
        }

        /// <summary>
        /// Every switched-on object of a class (its subclasses too) in a
        /// loaded scene.
        /// </summary>
        public static Component[] ComponentsIn(string sceneName, string assemblyOfType, string className)
        {
            var scene = SceneManager.GetSceneByName(sceneName);
            var type = System.Type.GetType(assemblyOfType)?.Assembly.GetType(className);
            var found = new List<Component>();
            if (!scene.IsValid() || type == null) return found.ToArray();
            foreach (var o in Resources.FindObjectsOfTypeAll(type))
            {
                if (o is Component c && c != null && c.gameObject.scene.handle == scene.handle && c.gameObject.activeInHierarchy) found.Add(c);
            }
            return found.ToArray();
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
