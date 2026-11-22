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
    let t = m.thickness(&chain, 0.5).unwrap();
    println!(
        "samples {} reach past last bone {:.2}",
        t.len(),
        m.reach(&chain, 0.5).unwrap()
    );
    let line: Vec<String> = t.iter().map(|r| format!("{r:.1}")).collect();
    println!("radius every 0.5 cm: {}", line.join(" "));
}

/// The drawn canal against its two points: MESH_JSON, MESH_CANAL=
/// bone,from,to (the canal's bone, then two bones or sockets). Each 1 cm
/// along the from-to line: the vertices weighted at least half to the
/// bone there, their centre's distance from the line and their mean
/// distance from that centre.
#[test]
#[ignore]
fn research_mesh_canal() {
    use glam::DVec3;
    let path = std::env::var("MESH_JSON").expect("MESH_JSON");
    let canal = std::env::var("MESH_CANAL").expect("MESH_CANAL");
    let c: Vec<&str> = canal.split(',').collect();
    let m: ueforge::mesh_file::Mesh =
        serde_json::from_str(&std::fs::read_to_string(&path).unwrap()).unwrap();
    let pose = m.ref_pose();
    let bone = m.bone(c[0]).unwrap() as u16;
    let (a, b) = (m.point(&pose, c[1]).unwrap(), m.point(&pose, c[2]).unwrap());
    let walls: Vec<&str> = c[3..].to_vec();
    if !walls.is_empty() {
        let (fa, fb) = m.canal(&walls, c[1], c[2]).unwrap();
        let (d0, d1) = ((b - a).normalize(), (fb - fa).normalize());
        println!(
            "fitted on {walls:?}: entrance {fa:.2?} ({:.2} cm from {}), turned {:.1} deg",
            (fa - a).length(),
            c[1],
            d0.angle_between(d1).to_degrees()
        );
    }
    // MESH_FIT=1: measure along the fitted line instead.
    let (a, b) = if std::env::var("MESH_FIT").is_ok() && !walls.is_empty() {
        m.canal(&walls, c[1], c[2]).unwrap()
    } else {
        (a, b)
    };
    let d = (b - a).normalize();
    println!(
        "{} {a:.2?} -> {} {b:.2?}, {:.2} cm",
        c[1],
        c[2],
        (b - a).length()
    );
    let mut bins: std::collections::BTreeMap<i64, Vec<DVec3>> = Default::default();
    for v in &m.verts {
        let w: f64 = v.w.iter().filter(|(k, _)| *k == bone).map(|(_, w)| w).sum();
        if w < 0.5 {
            continue;
        }
        let p = DVec3::from_array(v.p);
        bins.entry((p - a).dot(d).floor() as i64)
            .or_default()
            .push(p);
    }
    for (s, ps) in &bins {
        let mid = ps.iter().sum::<DVec3>() / ps.len() as f64;
        let on = a + d * (mid - a).dot(d);
        let ring = ps
            .iter()
            .map(|p| (*p - mid).reject_from(d).length())
            .sum::<f64>()
            / ps.len() as f64;
        println!(
            "{s:>3} cm: {:>5} verts, centre off the line {:.2} cm {:.2?}, ring {ring:.2}",
            ps.len(),
            (mid - on).length(),
            mid - on
        );
    }
}
