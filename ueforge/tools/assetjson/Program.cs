// assetjson: a cooked package (the legacy .uasset/.uexp retoc to-legacy
// extracts) as UAssetAPI's JSON, blueprint function code decoded into
// Kismet expressions: to read what a game blueprint does. Asked
// 2026-11-23: "read the game code go" (what the mouse wheel does in a
// scene).
//
// assetjson <uasset> <usmap> <out.json>
// assetjson <uasset> <usmap> <out.json> <function>: only that function's
//   code, each statement with its byte offset (StatementIndex), names
//   resolved (UAssetAPI KismetSerializer, as kismet-analyzer prints it).

using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.Kismet;
using UAssetAPI.UnrealTypes;
using UAssetAPI.Unversioned;

if (args.Length < 3)
{
    Console.Error.WriteLine("assetjson <uasset> <usmap> <out.json> [function]");
    return 2;
}
var asset = new UAsset(args[0], EngineVersion.VER_UE5_6, new Usmap(args[1]));
if (args.Length > 3)
{
    var f = asset.Exports.OfType<FunctionExport>().FirstOrDefault(e => e.ObjectName.ToString() == args[3])
        ?? throw new Exception($"no function {args[3]}");
    KismetSerializer.asset = asset;
    File.WriteAllText(args[2], KismetSerializer.SerializeScript(f.ScriptBytecode).ToString());
    Console.WriteLine($"{args[3]}: {f.ScriptBytecode.Length} statements -> {args[2]}");
    return 0;
}
File.WriteAllText(args[2], asset.SerializeJson(true));
Console.WriteLine($"{asset.Exports.Count} exports -> {args[2]}");
return 0;
