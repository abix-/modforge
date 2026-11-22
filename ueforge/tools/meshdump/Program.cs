// meshdump: a skeletal mesh's bones and LOD 0 vertices (position and bone
// weights, reference pose, component space cm) from a game's cooked
// files, as JSON. The game drops its copy of the mesh points from memory
// (bAllowCPUAccess false), so the drawn mesh is read here with CUE4Parse
// (the library FModel uses). Asked 2026-11-22: "it needs to match the
// actual mesh thickness", "yes install .net 10".
//
// meshdump <paks dir> <engine e.g. GAME_UE5_8> <package path> <out.json> [mappings.usmap]

using System.Text.Json;
using Serilog;
using CUE4Parse.Compression;
using CUE4Parse.Encryption.Aes;
using CUE4Parse.FileProvider;
using CUE4Parse.MappingsProvider.Usmap;
using CUE4Parse.UE4.Assets.Exports.SkeletalMesh;
using CUE4Parse.UE4.Objects.Core.Misc;
using CUE4Parse.UE4.Versions;
using CUE4Parse_Conversion.Dto;
using CUE4Parse_Conversion.Options;

if (args.Length < 4)
{
    Console.Error.WriteLine("meshdump <paks dir> <engine> <package path> <out.json> [mappings.usmap]");
    return 2;
}
var (paks, engine, path, outPath) = (args[0], args[1], args[2], args[3]);
Serilog.Log.Logger = new Serilog.LoggerConfiguration().MinimumLevel.Warning()
    .WriteTo.Console(standardErrorFromLevel: Serilog.Events.LogEventLevel.Verbose).CreateLogger();
CUE4Parse.CUE4ParseLog.UseLogger(Serilog.Log.Logger);
var oodle = Path.Combine(AppContext.BaseDirectory, OodleHelper.OodleFileName);
if (!File.Exists(oodle))
{
    OodleHelper.DownloadOodleDll(ref oodle);
}
OodleHelper.Initialize(oodle);
var provider = new DefaultFileProvider(paks, SearchOption.TopDirectoryOnly, true,
    new VersionContainer(Enum.Parse<EGame>(engine)));
if (args.Length > 4)
{
    provider.MappingsContainer = new FileUsmapTypeMappingsProvider(args[4]);
}
provider.Initialize();
provider.SubmitKey(new FGuid(), new FAesKey(new byte[32]));
var mesh = provider.LoadPackageObject<USkeletalMesh>(path);
var dto = new SkeletalMeshDto(mesh, new ExportOptions());
var lod = dto.LODs[0];
var bones = dto.Bones.Select(b => new
{
    name = b.Name,
    parent = b.ParentIndex,
    pos = new[] { b.Transform.Translation.X, b.Transform.Translation.Y, b.Transform.Translation.Z },
    rot = new[] { b.Transform.Rotation.X, b.Transform.Rotation.Y, b.Transform.Rotation.Z, b.Transform.Rotation.W },
    scale = new[] { b.Transform.Scale3D.X, b.Transform.Scale3D.Y, b.Transform.Scale3D.Z },
});
var verts = lod.Vertices.Select(v => new
{
    p = new[] { v.Position.X, v.Position.Y, v.Position.Z },
    w = v.Influences.Where(i => i.Weight > 0).Select(i => new object[] { i.Bone, i.Weight }),
});
await using var f = File.Create(outPath);
await JsonSerializer.SerializeAsync(f, new { mesh = path, bones, verts });
Console.WriteLine($"{path}: {dto.Bones.Length} bones, {lod.Vertices.Length} vertices -> {outPath}");
return 0;
