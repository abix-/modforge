// morphadd: new morph targets added to a cooked skeletal mesh package
// (the legacy .uasset/.uexp retoc to-legacy extracts), each a copy of an
// existing morph target under a new name, appended to the mesh's
// MorphTargets. Their deltas go into the mesh's GPU morph data after,
// with ueforge's morph-pack. Asked 2026-11-23: "add 10 new morphs based
// on the penis for the scne". Uses UAssetAPI (the library UAssetGUI uses),
// master cloned to C:\tools\UAssetAPI with one local change: Usmap.cs
// reads usmap version EngineVersioning (an FEngineVersion after the
// versioning flag, as CUE4Parse's UsmapParser reads it), which the
// game's type map uses and UAssetAPI does not know yet.
// Proven 2026-11-23: the woman's mesh writes back byte-identical (same).
//
// morphadd show <uasset> <usmap>
// morphadd add <uasset> <usmap> <out uasset> <template morph> <new name>...

using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.PropertyTypes.Objects;
using UAssetAPI.UnrealTypes;
using UAssetAPI.Unversioned;

if (args.Length < 3)
{
    Console.Error.WriteLine("morphadd show <uasset> <usmap> | add <uasset> <usmap> <out uasset> <template morph> <new name>...");
    return 2;
}
var asset = new UAsset(args[1], EngineVersion.VER_UE5_6, new Usmap(args[2]));
string Name(Export e) => e.ObjectName.ToString();
string Class(Export e) => e.GetExportClassType().ToString();
var mesh = asset.Exports.FirstOrDefault(e => Class(e) == "SkeletalMesh") as NormalExport
    ?? throw new Exception("no SkeletalMesh export that UAssetAPI could read as properties");
var list = mesh.Data.OfType<ArrayPropertyData>().FirstOrDefault(p => p.Name.ToString() == "MorphTargets")
    ?? throw new Exception("the mesh has no MorphTargets");

if (args[0] == "show")
{
    var kinds = asset.Exports.GroupBy(e => (Class(e), e.GetType().Name)).Select(g => $"{g.Key.Item1} as {g.Key.Item2}: {g.Count()}");
    Console.WriteLine($"{asset.Exports.Count} exports; {string.Join(", ", kinds)}");
    Console.WriteLine($"mesh '{Name(mesh)}': {mesh.Data.Count} properties, MorphTargets {list.Value.Length}, extra bytes {mesh.Extras?.Length}");
    var first = asset.Exports.First(e => Class(e) == "MorphTarget");
    Console.WriteLine($"first morph '{Name(first)}' as {first.GetType().Name}: extra bytes {(first as NormalExport)?.Extras?.Length}");
    return 0;
}

if (args[0] == "same" && args.Length > 3)
{
    // Written back unchanged, to compare with the input.
    asset.Write(args[3]);
    Console.WriteLine($"wrote {args[3]} unchanged");
    return 0;
}

if (args[0] != "add" || args.Length < 6)
{
    Console.Error.WriteLine("add <uasset> <usmap> <out uasset> <template morph> <new name>...");
    return 2;
}
var template = asset.Exports.OfType<NormalExport>().FirstOrDefault(e => Class(e) == "MorphTarget" && Name(e) == args[4])
    ?? throw new Exception($"no morph target named {args[4]}");
var added = new List<PropertyData>(list.Value);
foreach (var name in args[5..])
{
    if (asset.Exports.Any(e => Name(e) == name))
        throw new Exception($"an export is already named {name}");
    var copy = new NormalExport(asset, template.Extras.ToArray())
    {
        ObjectName = FName.FromString(asset, name),
        ClassIndex = template.ClassIndex,
        SuperIndex = template.SuperIndex,
        TemplateIndex = template.TemplateIndex,
        OuterIndex = template.OuterIndex,
        ObjectFlags = template.ObjectFlags,
        bForcedExport = template.bForcedExport,
        bNotForClient = template.bNotForClient,
        bNotForServer = template.bNotForServer,
        bNotAlwaysLoadedForEditorGame = template.bNotAlwaysLoadedForEditorGame,
        bIsAsset = template.bIsAsset,
        PackageFlags = template.PackageFlags,
        SerializationBeforeSerializationDependencies = [.. template.SerializationBeforeSerializationDependencies],
        CreateBeforeSerializationDependencies = [.. template.CreateBeforeSerializationDependencies],
        SerializationBeforeCreateDependencies = [.. template.SerializationBeforeCreateDependencies],
        CreateBeforeCreateDependencies = [.. template.CreateBeforeCreateDependencies],
        Data = template.Data.Select(p => (PropertyData)p.Clone()).ToList(),
    };
    asset.Exports.Add(copy);
    var index = FPackageIndex.FromExport(asset.Exports.Count - 1);
    added.Add(new ObjectPropertyData(list.Value.Length > 0 ? list.Value[0].Name : FName.FromString(asset, "MorphTargets")) { Value = index });
    // The mesh waits on each new morph as it waits on the template.
    var templateIndex = FPackageIndex.FromExport(asset.Exports.IndexOf(template));
    foreach (var deps in new[] {
        mesh.SerializationBeforeSerializationDependencies, mesh.CreateBeforeSerializationDependencies,
        mesh.SerializationBeforeCreateDependencies, mesh.CreateBeforeCreateDependencies })
    {
        if (deps.Any(d => d.Index == templateIndex.Index))
            deps.Add(index);
    }
    Console.WriteLine($"added {name} as export {asset.Exports.Count}");
}
list.Value = [.. added];
asset.Write(args[3]);
Console.WriteLine($"wrote {args[3]}: MorphTargets {list.Value.Length}");
return 0;
