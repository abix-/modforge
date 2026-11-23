//! Research: a meshdump file's thickness along a bone chain.
//! MESH_JSON=<meshdump output> MESH_CHAIN=a,b,c cargo test --release
//! --test research_mesh_file -- --ignored --nocapture

#[test]
#[ignore]
fn research_mesh_thickness() {
    let path = std::env::var("MESH_JSON").expect("MESH_JSON");
    let chain = std::env::var("MESH_CHAIN").expect("MESH_CHAIN");
    let chain: Vec<&str> = chain.split(',').collect();
    let m: ueforge::mesh_file::Mesh =
        serde_json::from_str(&std::fs::read_to_string(&path).unwrap()).unwrap();
    let pose = m.ref_pose();
    for n in &chain {
        let i = m.bone(n).unwrap();
        println!("{n}: {:.2?}", pose[i].pos);
    }
    // MESH_LEAST: the least weight on the chain a vertex counts with.
    let least = std::env::var("MESH_LEAST")
        .ok()
        .and_then(|v| v.parse().ok())
        .unwrap_or(ueforge::mesh_file::OWN);
    let t = m.thickness_least(&chain, 0.5, least).unwrap();
    println!(
        "samples {} reach past last bone {:.2}",
        t.len(),
        m.reach(&chain, 0.5).unwrap()
    );
    let line: Vec<String> = t.iter().map(|r| format!("{r:.1}")).collect();
    println!("radius every 0.5 cm: {}", line.join(" "));
}
