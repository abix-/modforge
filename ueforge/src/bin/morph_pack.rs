//! Offline check of a cooked skeletal mesh's morph data
//! (`ueforge::morph_pack`): finds every LOD's data in a legacy .uexp,
//! and re-encodes each LOD from its own decoded deltas to prove the
//! encoder writes what the engine's cook wrote.
//!
//! ```sh
//! k3sc cargo-lock build --release -p ueforge --bin morph-pack
//! target/x86_64-pc-windows-msvc/release/morph-pack.exe check <uexp>
//! target/x86_64-pc-windows-msvc/release/morph-pack.exe show <uexp> <lod> <morph index>
//! ```

use std::process::ExitCode;

use ueforge::morph_pack::Buffers;

fn run(args: &[String]) -> Result<(), String> {
    let path = args
        .get(1)
        .ok_or("usage: morph-pack check|show <uexp> ...")?;
    let file = std::fs::read(path).map_err(|e| format!("read {path}: {e}"))?;
    let lods = Buffers::find_all(&file);
    match args[0].as_str() {
        "check" => {
            println!("{} LODs of morph data in {} bytes", lods.len(), file.len());
            for (i, b) in lods.iter().enumerate() {
                let morphs = b.decode_all();
                let deltas: usize = morphs.iter().map(Vec::len).sum();
                let again = b.encode(&morphs);
                let same = again.to_bytes() == file[b.at..b.at + b.len];
                println!(
                    "lod {i}: at {} len {} morphs {} batches {} deltas {deltas} precision {} tangent {} re-encoded identical: {same}",
                    b.at,
                    b.len,
                    b.batches.len(),
                    b.total_batches,
                    b.position_precision,
                    b.tangent_precision,
                );
            }
        }
        "show" => {
            let lod: usize = args.get(2).and_then(|a| a.parse().ok()).ok_or("lod")?;
            let m: usize = args
                .get(3)
                .and_then(|a| a.parse().ok())
                .ok_or("morph index")?;
            let b = lods.get(lod).ok_or("no such lod")?;
            let d = b.decode(m);
            let p = b.position_precision;
            let most = d
                .iter()
                .map(|e| {
                    let v = e.position.map(|c| c as f32 * p);
                    (v[0] * v[0] + v[1] * v[1] + v[2] * v[2]).sqrt()
                })
                .fold(0.0f32, f32::max);
            println!(
                "lod {lod} morph {m}: {} deltas, most moved {most} cm, min {:?} max {:?}",
                d.len(),
                b.minimum[m],
                b.maximum[m]
            );
            for e in d.iter().take(5) {
                println!("  {} {:?}", e.index, e.position.map(|c| c as f32 * p));
            }
        }
        other => return Err(format!("unknown command {other}")),
    }
    Ok(())
}

fn main() -> ExitCode {
    let args: Vec<String> = std::env::args().skip(1).collect();
    if args.is_empty() {
        eprintln!("usage: morph-pack check|show <uexp> ...");
        return ExitCode::FAILURE;
    }
    match run(&args) {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("{e}");
            ExitCode::FAILURE
        }
    }
}
