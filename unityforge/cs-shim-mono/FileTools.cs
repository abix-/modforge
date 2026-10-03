// FileTools.cs. Writing large text a game method produces: the bridge hands
// results back through a fixed buffer (8 KB, unityforge/src/mono.rs
// invoke), so a mod cannot fetch a save file's serialized text and write it
// itself. Here the text goes from the game's own serializer straight to the
// file.
//
// First user: obenseuer-mod's kept_loaded, writing the save files of areas
// kept loaded with the game's SaveController.Serialize.

using System;
using System.IO;
using System.Reflection;
using System.Text;

namespace Unityforge.Shim
{
    public static class FileTools
    {
        /// <summary>
        /// A file's bytes as a byte array object, for a method that takes
        /// them (a large file does not fit the bridge's JSON). Null when the
        /// file does not exist.
        /// </summary>
        public static byte[] ReadBytes(string path) => File.Exists(path) ? File.ReadAllBytes(path) : null;

        /// <summary>
        /// Calls the static method `className.method(Type type, object
        /// value)` that returns a string and writes the result to `path` as
        /// UTF-8 with a byte order mark (what File.WriteAllText with
        /// Encoding.UTF8 writes, as the game's own save writer does). True
        /// when written.
        /// </summary>
        public static bool SerializeToFile(string className, string method, Type type, object value, string path)
        {
            var owner = TypeCache.Resolve(className);
            if (owner == null) throw new ArgumentException("type '" + className + "' not found");
            const BindingFlags flags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static;
            var m = owner.GetMethod(method, flags, null, new[] { typeof(Type), typeof(object) }, null);
            if (m == null) throw new ArgumentException(className + "." + method + "(Type, object) not found");
            var text = m.Invoke(null, new[] { type, value }) as string;
            if (text == null) return false;
            File.WriteAllText(path, text, Encoding.UTF8);
            return true;
        }
    }
}
