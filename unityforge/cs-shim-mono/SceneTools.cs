// SceneTools.cs. Scene calls the bridge cannot make itself: Scene is a
// struct, and invoke_method needs a live object handle, so a method on a
// Scene value (GetRootGameObjects) is out of reach from Rust. Static
// methods here take the scene by name; Rust calls them with
// invoke_static("Unityforge.Shim.SceneTools", ...).
//
// First user: obenseuer-mod's kept_loaded (areas kept loaded, only the
// one the player is in switched on).

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
