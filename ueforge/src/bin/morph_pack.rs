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
        "scale" => {
            // scale <uexp> <uasset> <out dir> <morph index> <factor>: the
            // package with one morph's deltas scaled on every LOD.
            let uasset_path = args.get(2).ok_or("uasset")?;
            let out_dir = std::path::Path::new(args.get(3).ok_or("out dir")?);
            let m: usize = args
                .get(4)
                .and_then(|a| a.parse().ok())
                .ok_or("morph index")?;
            let k: f64 = args.get(5).and_then(|a| a.parse().ok()).ok_or("factor")?;
            let uasset =
                std::fs::read(uasset_path).map_err(|e| format!("read {uasset_path}: {e}"))?;
            let new: Vec<Buffers> = lods
                .iter()
                .map(|b| {
                    let mut morphs = b.decode_all();
                    for d in &mut morphs[m] {
                        d.position = d.position.map(|c| (c as f64 * k).round() as i32);
                    }
                    let mut n = b.encode(&morphs);
                    n.minimum[m] = b.minimum[m].map(|c| c * k as f32);
                    n.maximum[m] = b.maximum[m].map(|c| c * k as f32);
                    n
                })
                .collect();
            let (uexp, changes) = ueforge::morph_pack::replace(&file, &new);
            let header = ueforge::morph_pack::fix_package(&uasset, file.len(), &changes)?;
            std::fs::create_dir_all(out_dir).map_err(|e| e.to_string())?;
            let name = |p: &str| std::path::Path::new(p).file_name().unwrap().to_owned();
            std::fs::write(out_dir.join(name(path)), &uexp).map_err(|e| e.to_string())?;
            std::fs::write(out_dir.join(name(uasset_path)), &header).map_err(|e| e.to_string())?;
            println!("morph {m} scaled {k}: size changes {changes:?}");
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
