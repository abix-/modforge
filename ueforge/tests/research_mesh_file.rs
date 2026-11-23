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

/// The penis's cross-section every cm along MESH_CHAIN: how far its
/// centre is off the bone line, its widest distance from the line (what
/// thickness reports) and its widest and mean distance from its centre.
#[test]
#[ignore]
fn research_mesh_section() {
    use glam::DVec3;
    let path = std::env::var("MESH_JSON").expect("MESH_JSON");
    let chain = std::env::var("MESH_CHAIN").expect("MESH_CHAIN");
    let chain: Vec<&str> = chain.split(',').collect();
    let m: ueforge::mesh_file::Mesh =
        serde_json::from_str(&std::fs::read_to_string(&path).unwrap()).unwrap();
    let mut bins: std::collections::BTreeMap<i64, Vec<DVec3>> = Default::default();
    for (_, s, off) in m.on_chain(&chain).unwrap() {
        bins.entry(s.floor() as i64).or_default().push(off);
    }
    for (s, offs) in &bins {
        let c = offs.iter().sum::<DVec3>() / offs.len() as f64;
        let from_line = offs.iter().map(|o| o.length()).fold(0.0, f64::max);
        let about: Vec<f64> = offs.iter().map(|o| (*o - c).length()).collect();
        let max = about.iter().cloned().fold(0.0, f64::max);
        let mean = about.iter().sum::<f64>() / about.len() as f64;
        println!(
            "{s:>3} cm: {:>4} verts, centre off line {:.2}, widest from line {from_line:.2}, from centre widest {max:.2} mean {mean:.2}",
            offs.len(),
            c.length()
        );
    }
}

/// What widening bone MESH_BONE across its Z axis by MESH_K does to the
/// canal (MESH_CANAL=from,to,walls...): the bone's children, then every
/// cm along the canal (from 5 cm outside) for the vertices with any
/// weight on the bone: how many, how many of them are walls (weight at
/// least half), their mean weight, and the narrowest wall point from the
/// canal line closed and widened. Asked 2026-11-22: "we need to fix the
/// morp so the opening AND the inside is accurate for the changed size".
#[test]
#[ignore]
fn research_mesh_bone_width() {
    use glam::DVec3;
    let path = std::env::var("MESH_JSON").expect("MESH_JSON");
    let bone = std::env::var("MESH_BONE").expect("MESH_BONE");
    let k: f64 = std::env::var("MESH_K").expect("MESH_K").parse().unwrap();
    let canal = std::env::var("MESH_CANAL").expect("MESH_CANAL");
    let c: Vec<&str> = canal.split(',').collect();
    let m: ueforge::mesh_file::Mesh =
        serde_json::from_str(&std::fs::read_to_string(&path).unwrap()).unwrap();
    let pose = m.ref_pose();
    let bi = m.bone(&bone).unwrap();
    let kids: Vec<&str> = m
        .bones
        .iter()
        .filter(|b| b.parent == bi as i32)
        .map(|b| b.name.as_str())
        .collect();
    println!("{bone} children: {kids:?}");
    let (a, b) = m.canal(&c[2..], c[0], c[1]).unwrap();
    let d = (b - a).normalize();
    println!(
        "canal line in {bone} space: {:.2?} along {:.2?}",
        pose[bi].inverse_point(a),
        (pose[bi].inverse_point(b) - pose[bi].inverse_point(a)).normalize()
    );
    // (count, walls, weight sum, narrowest wall closed, widened)
    let mut bins: std::collections::BTreeMap<i64, (usize, usize, f64, f64, f64)> =
        Default::default();
    for v in &m.verts {
        let w: f64 =
            v.w.iter()
                .filter(|(x, _)| *x as usize == bi)
                .map(|(_, w)| w)
                .sum();
        if w <= 0.0 {
            continue;
        }
        let p = DVec3::from_array(v.p);
        let l = pose[bi].inverse_point(p);
        let wide = pose[bi].point(DVec3::new(l.x * k, l.y * k, l.z));
        let q = p + (wide - p) * w;
        let s = (p - a).dot(d).floor() as i64;
        if !(-5..=12).contains(&s) {
            continue;
        }
        let e = bins.entry(s).or_insert((0, 0, 0.0, f64::MAX, f64::MAX));
        e.0 += 1;
        e.2 += w;
        if w >= 0.5 {
            e.1 += 1;
            e.3 = e.3.min((p - a).reject_from(d).length());
            e.4 = e.4.min((q - a).reject_from(d).length());
        }
    }
    for (s, (n, walls, ws, r0, r1)) in &bins {
        println!(
            "{s:>3} cm: {n:>5} verts, {walls:>5} walls, mean weight {:.2}, narrowest wall {} -> {}",
            ws / *n as f64,
            if *walls > 0 {
                format!("{r0:.2}")
            } else {
                "-".into()
            },
            if *walls > 0 {
                format!("{r1:.2}")
            } else {
                "-".into()
            },
        );
    }
}

/// How far each opening morph opens the drawn canal: MESH_JSON,
/// MESH_CANAL=from,to,walls... , MESH_MORPHS=a|b|c (each alone). Every cm
/// in: the narrowest wall point closed, and opened by the morph at 1.
#[test]
#[ignore]
fn research_mesh_canal_width() {
    let path = std::env::var("MESH_JSON").expect("MESH_JSON");
    let canal = std::env::var("MESH_CANAL").expect("MESH_CANAL");
    let morphs = std::env::var("MESH_MORPHS").expect("MESH_MORPHS");
    let c: Vec<&str> = canal.split(',').collect();
    let m: ueforge::mesh_file::Mesh =
        serde_json::from_str(&std::fs::read_to_string(&path).unwrap()).unwrap();
    println!(
        "{} morphs, {} offsets",
        m.morphs.len(),
        m.morphs.iter().map(|x| x.d.len()).sum::<usize>()
    );
    for n in morphs.split('|') {
        let w = m.canal_width(&c[2..], c[0], c[1], &[n]);
        let Some(w) = w else {
            println!("{n}: none");
            continue;
        };
        let line: Vec<String> = w
            .iter()
            .enumerate()
            .map(|(k, r)| match r {
                Some((a, b)) => format!("{k}:{a:.2}->{b:.2}"),
                None => format!("{k}:-"),
            })
            .collect();
        println!("{n}: {}", line.join(" "));
    }
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
