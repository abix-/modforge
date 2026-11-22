//! A skeletal mesh as drawn, read from the game's cooked files: its bones
//! (reference pose) and its LOD 0 vertices with their bone weights. The
//! game keeps no copy of the mesh points it can read (bAllowCPUAccess is
//! off), so they come from the package on disk, read by the meshdump
//! tool (ueforge/tools/meshdump, CUE4Parse, the library FModel uses).
//! Asked 2026-11-22: "it needs to match the actual mesh thickness".
//!
//! The mod sets the tool's paths once ([`setup`]). [`get`] reads a mesh
//! on a worker thread the first time it is asked for, writing the
//! tool's output to the cache folder, so later runs only parse the file;
//! until then it answers `Ok(None)`.

use std::collections::HashMap;
use std::path::PathBuf;
use std::sync::{Arc, OnceLock};

use glam::{DQuat, DVec3};
use parking_lot::Mutex;
use serde::Deserialize;

use crate::anim_data::Xform;
use crate::ue::UObject;

/// Where the tool and the game's files are.
#[derive(Clone, Debug)]
pub struct Setup {
    /// The meshdump program (meshdump.exe).
    pub tool: PathBuf,
    /// The .NET install it runs on (DOTNET_ROOT), when not the system's.
    pub dotnet_root: Option<PathBuf>,
    /// The game's Paks folder.
    pub paks: PathBuf,
    /// CUE4Parse's name for the engine, e.g. GAME_UE5_6.
    pub engine: String,
    /// The project folder name: "/Game/X" is "<project>/Content/X".
    pub project: String,
    /// The game's type map (UsmapGen from the game's exe).
    pub usmap: PathBuf,
    /// Where the tool's output is kept.
    pub cache: PathBuf,
}

static SETUP: OnceLock<Setup> = OnceLock::new();

/// Set the tool's paths. Only the first call counts.
pub fn setup(s: Setup) {
    let _ = SETUP.set(s);
}

#[derive(Clone, Debug, Deserialize)]
pub struct Bone {
    pub name: String,
    pub parent: i32,
    pub pos: [f64; 3],
    /// Quaternion x, y, z, w.
    pub rot: [f64; 4],
    pub scale: [f64; 3],
}

#[derive(Clone, Debug, Deserialize)]
pub struct Vert {
    /// Component space, reference pose, cm.
    pub p: [f64; 3],
    /// (mesh bone index, weight), weights above 0.
    pub w: Vec<(u16, f64)>,
}

/// A socket on the mesh or its skeleton.
#[derive(Clone, Debug, Deserialize)]
pub struct Socket {
    pub name: String,
    pub bone: String,
    /// Relative to the bone, cm.
    pub pos: [f64; 3],
}

#[derive(Clone, Debug, Deserialize)]
pub struct Mesh {
    pub bones: Vec<Bone>,
    /// Mesh sockets first, then the skeleton's.
    #[serde(default)]
    pub sockets: Vec<Socket>,
    pub verts: Vec<Vert>,
}

enum State {
    Reading,
    Ready(Arc<Mesh>),
    Failed(String),
}

static MESHES: Mutex<Option<HashMap<String, State>>> = Mutex::new(None);

/// The mesh in package `package` ("/Game/..."): Ok(None) while it is
/// being read.
pub fn get(package: &str) -> Result<Option<Arc<Mesh>>, String> {
    let mut all = MESHES.lock();
    let all = all.get_or_insert_with(HashMap::new);
    match all.get(package) {
        Some(State::Ready(m)) => return Ok(Some(m.clone())),
        Some(State::Failed(e)) => return Err(e.clone()),
        Some(State::Reading) => return Ok(None),
        None => {}
    }
    let s = SETUP.get().ok_or("mesh_file: no setup")?.clone();
    all.insert(package.to_owned(), State::Reading);
    let p = package.to_owned();
    std::thread::Builder::new()
        .name("ueforge-mesh-file".into())
        .spawn(move || {
            let r = read(&s, &p);
            match &r {
                Ok(m) => crate::log!(
                    "mesh_file: {p}: {} bones, {} vertices",
                    m.bones.len(),
                    m.verts.len()
                ),
                Err(e) => crate::log!("mesh_file: {p}: {e}"),
            }
            let st = match r {
                Ok(m) => State::Ready(Arc::new(m)),
                Err(e) => State::Failed(e),
            };
            if let Some(all) = MESHES.lock().as_mut() {
                all.insert(p, st);
            }
        })
        .map_err(|e| format!("mesh_file: no thread: {e}"))?;
    Ok(None)
}

/// Read the cached file, or run the tool to make it.
fn read(s: &Setup, package: &str) -> Result<Mesh, String> {
    let rest = package
        .strip_prefix("/Game/")
        .ok_or_else(|| format!("not a /Game/ package: {package}"))?;
    let file: String = rest
        .chars()
        .map(|c| if c.is_ascii_alphanumeric() { c } else { '_' })
        .collect();
    let out = s.cache.join(format!("{file}.json"));
    if !out.exists() {
        std::fs::create_dir_all(&s.cache).map_err(|e| format!("cache folder: {e}"))?;
        let name = rest.rsplit('/').next().unwrap_or(rest);
        let path = format!("{}/Content/{rest}.{name}", s.project);
        let tmp = out.with_extension("part");
        let mut cmd = std::process::Command::new(&s.tool);
        cmd.arg(&s.paks)
            .arg(&s.engine)
            .arg(&path)
            .arg(&tmp)
            .arg(&s.usmap);
        if let Some(d) = &s.dotnet_root {
            cmd.env("DOTNET_ROOT", d);
        }
        {
            use std::os::windows::process::CommandExt;
            // CREATE_NO_WINDOW: no console window over the game.
            cmd.creation_flags(0x0800_0000);
        }
        let o = cmd
            .output()
            .map_err(|e| format!("{}: {e}", s.tool.display()))?;
        if !o.status.success() {
            let err = String::from_utf8_lossy(&o.stderr);
            let line = err
                .lines()
                .find(|l| l.contains("Exception") || l.contains("ERR"))
                .unwrap_or("no message");
            return Err(format!("meshdump failed ({}): {line}", o.status));
        }
        std::fs::rename(&tmp, &out).map_err(|e| format!("cache file: {e}"))?;
    }
    let text = std::fs::read_to_string(&out).map_err(|e| format!("{}: {e}", out.display()))?;
    serde_json::from_str(&text).map_err(|e| format!("{}: {e}", out.display()))
}

/// The package of skinned mesh component `c`'s mesh ("/Game/...").
///
/// # Safety
/// Game thread, `c` a live skinned mesh.
pub unsafe fn package_of(c: &UObject) -> Option<String> {
    // SAFETY: the caller's.
    let v = unsafe { crate::reflect::get_fields(c, &["SkinnedAsset".into()]) }.ok()?;
    let mesh =
        crate::selector::resolve(&format!("addr:{}", v["SkinnedAsset"]["addr"].as_str()?)).ok()?;
    let mut top = mesh;
    while let Some(o) = top.outer() {
        top = o;
    }
    Some(top.name())
}

impl Mesh {
    pub fn bone(&self, n: &str) -> Option<usize> {
        self.bones.iter().position(|b| b.name == n)
    }

    /// Bone or socket `n`'s position, component space, reference pose.
    pub fn point(&self, pose: &[Xform], n: &str) -> Option<DVec3> {
        if let Some(i) = self.bone(n) {
            return Some(pose.get(i)?.pos);
        }
        let s = self.sockets.iter().find(|s| s.name == n)?;
        Some(
            pose.get(self.bone(&s.bone)?)?
                .point(DVec3::from_array(s.pos)),
        )
    }

    /// Each bone's transform in component space, reference pose.
    pub fn ref_pose(&self) -> Vec<Xform> {
        let mut out: Vec<Xform> = Vec::with_capacity(self.bones.len());
        for b in &self.bones {
            let local = Xform {
                rot: DQuat::from_xyzw(b.rot[0], b.rot[1], b.rot[2], b.rot[3]).normalize(),
                pos: DVec3::from_array(b.pos),
                scale: DVec3::from_array(b.scale),
            };
            // Parents come before children in a reference skeleton.
            let x = match usize::try_from(b.parent).ok().and_then(|p| out.get(p)) {
                Some(p) => local.under(p),
                None => local,
            };
            out.push(x);
        }
        out
    }

    /// The drawn thickness along bone chain `chain` (base first): the
    /// radius (cm) every `step` cm from the first bone, along the bones
    /// and on past the last bone in its direction, to the farthest
    /// vertex (the drawn tip). Each vertex weighted at least half to the
    /// chain counts at the nearest point of the chain line, its distance
    /// from the line the radius there; each sample is the widest vertex
    /// in it. Reference pose. None with fewer than two bones or none of
    /// them found, or no vertex on them.
    pub fn thickness(&self, chain: &[&str], step: f64) -> Option<Vec<f64>> {
        if chain.len() < 2 || step <= 0.0 {
            return None;
        }
        let pose = self.ref_pose();
        let idx: Vec<usize> = chain.iter().map(|n| self.bone(n)).collect::<Option<_>>()?;
        let pts: Vec<DVec3> = idx.iter().map(|&i| pose[i].pos).collect();
        let mut starts = vec![0.0];
        for w in pts.windows(2) {
            starts.push(starts.last().copied().unwrap_or(0.0) + (w[1] - w[0]).length());
        }
        let last = pts.len() - 2;
        // A point's (distance along, distance from) the chain line; the
        // last segment goes on past the last bone.
        let place = |p: DVec3| -> (f64, f64) {
            let mut best = (0.0, f64::MAX);
            for j in 0..=last {
                let (a, b) = (pts[j], pts[j + 1]);
                let l = (b - a).length();
                if l < 1e-9 {
                    continue;
                }
                let d = (b - a) / l;
                let u = (p - a).dot(d);
                let u = if j == last {
                    u.max(0.0)
                } else {
                    u.clamp(0.0, l)
                };
                let r = (p - (a + d * u)).length();
                if r < best.1 {
                    best = (starts[j] + u, r);
                }
            }
            best
        };
        let mut bins: Vec<f64> = Vec::new();
        for v in &self.verts {
            let on: f64 =
                v.w.iter()
                    .filter(|(b, _)| idx.contains(&(*b as usize)))
                    .map(|(_, w)| w)
                    .sum();
            if on < 0.5 {
                continue;
            }
            let (s, r) = place(DVec3::from_array(v.p));
            let k = (s / step).floor() as usize;
            if k > 100_000 {
                return None;
            }
            if bins.len() <= k {
                bins.resize(k + 1, -1.0);
            }
            bins[k] = bins[k].max(r);
        }
        if bins.is_empty() {
            return None;
        }
        // A sample no vertex fell in takes its nearer neighbour's.
        for k in 0..bins.len() {
            if bins[k] < 0.0 {
                let before = bins[..k].iter().rev().find(|&&r| r >= 0.0).copied();
                let after = bins[k + 1..].iter().find(|&&r| r >= 0.0).copied();
                bins[k] = before.or(after).unwrap_or(0.0);
            }
        }
        Some(bins)
    }

    /// The drawn canal through bones `bones` (its walls: the vertices
    /// weighted at least half to them), entered at bone or socket
    /// `from` and heading first toward `to`: its entrance (on the canal's
    /// line, nearest `from`) and the point `to`'s distance down the line
    /// from it. Component space, reference pose. The line goes through
    /// the walls' centre every cm from 1 cm in (the surface around the
    /// entrance, in the first cm, left out), fitted again, each time
    /// measured along the last fit, until it moves less than 0.001 cm
    /// (at most 20 fits). Asked 2026-11-22: "canal
    /// alignment is still off". None with fewer than two cm of walls.
    pub fn canal(&self, bones: &[&str], from: &str, to: &str) -> Option<(DVec3, DVec3)> {
        let pose = self.ref_pose();
        let (a, b) = (self.point(&pose, from)?, self.point(&pose, to)?);
        let len = (b - a).length();
        let idx: Vec<usize> = bones.iter().map(|n| self.bone(n)).collect::<Option<_>>()?;
        let walls: Vec<DVec3> = self
            .verts
            .iter()
            .filter(|v| {
                v.w.iter()
                    .filter(|(k, _)| idx.contains(&(*k as usize)))
                    .map(|(_, w)| w)
                    .sum::<f64>()
                    >= 0.5
            })
            .map(|v| DVec3::from_array(v.p))
            .collect();
        let (mut at, mut d) = (a, (b - a).normalize_or_zero());
        if d == DVec3::ZERO {
            return None;
        }
        for _ in 0..20 {
            let (was_at, was_d) = (at, d);
            let mut bins: HashMap<i64, (DVec3, f64)> = HashMap::new();
            for p in &walls {
                let s = (*p - at).dot(d).floor() as i64;
                if s >= 1 {
                    let e = bins.entry(s).or_insert((DVec3::ZERO, 0.0));
                    e.0 += *p;
                    e.1 += 1.0;
                }
            }
            if bins.len() < 2 {
                return None;
            }
            let centres: Vec<(DVec3, f64)> = bins.values().map(|(s, n)| (*s / *n, *n)).collect();
            let total: f64 = centres.iter().map(|(_, n)| n).sum();
            let mid = centres.iter().map(|(c, n)| *c * *n).sum::<DVec3>() / total;
            // The centres' main direction: power iteration on their
            // spread, from the last direction.
            let mut dir = d;
            for _ in 0..50 {
                let next = centres
                    .iter()
                    .map(|(c, n)| (*c - mid) * ((*c - mid).dot(dir) * *n))
                    .sum::<DVec3>()
                    .normalize_or_zero();
                if next == DVec3::ZERO {
                    break;
                }
                dir = next;
            }
            if dir.dot(d) < 0.0 {
                dir = -dir;
            }
            d = dir;
            at = mid + d * (a - mid).dot(d);
            if at.distance(was_at) < 1e-3 && (d - was_d).length() * len < 1e-3 {
                break;
            }
        }
        Some((at, at + d * len))
    }

    /// How far past bone `tip` the drawn mesh reaches along the chain
    /// line, cm: the thickness's length less the chain's.
    pub fn reach(&self, chain: &[&str], step: f64) -> Option<f64> {
        let t = self.thickness(chain, step)?;
        let pose = self.ref_pose();
        let len: f64 = chain
            .windows(2)
            .map(|w| Some((pose[self.bone(w[1])?].pos - pose[self.bone(w[0])?].pos).length()))
            .sum::<Option<f64>>()?;
        Some(t.len() as f64 * step - len)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// A straight 10 cm chain on X with a 2 cm ring every cm out to 12.
    fn tube() -> Mesh {
        let bone = |name: &str, parent: i32, x: f64| Bone {
            name: name.into(),
            parent,
            pos: [x, 0.0, 0.0],
            rot: [0.0, 0.0, 0.0, 1.0],
            scale: [1.0; 3],
        };
        let mut verts = Vec::new();
        for i in 0..=12 {
            for a in 0..8 {
                let t = a as f64 * std::f64::consts::TAU / 8.0;
                let r = if i > 5 { 1.0 } else { 2.0 };
                verts.push(Vert {
                    p: [i as f64, r * t.cos(), r * t.sin()],
                    w: vec![(if i < 5 { 0 } else { 1 }, 1.0)],
                });
            }
        }
        // Body skin on another bone: never counted.
        verts.push(Vert {
            p: [3.0, 30.0, 0.0],
            w: vec![(2, 1.0)],
        });
        Mesh {
            bones: vec![bone("a", -1, 0.0), bone("b", 0, 5.0), bone("c", 1, 5.0)],
            sockets: vec![
                // 1 cm off the tube's axis and aimed 45 degrees off it.
                Socket {
                    name: "in".into(),
                    bone: "a".into(),
                    pos: [0.0, 1.0, 0.0],
                },
                Socket {
                    name: "deep".into(),
                    bone: "a".into(),
                    pos: [3.0, 4.0, 0.0],
                },
            ],
            verts,
        }
    }

    #[test]
    fn canal_follows_the_walls_not_the_points() {
        let mut m = tube();
        // Rings between the 1 cm steps, as a drawn mesh's are, not on
        // them (a ring split over two steps leans each centre).
        for v in &mut m.verts {
            v.p[0] += 0.5;
        }
        let (a, b) = m.canal(&["a", "b"], "in", "deep").unwrap();
        // On the tube's axis, nearest "in", heading along X, as long as
        // in to deep.
        assert!(a.distance(DVec3::ZERO) < 1e-6, "{a}");
        assert!((b - a).normalize().distance(DVec3::X) < 1e-6, "{b}");
        assert!(((b - a).length() - 18f64.sqrt()).abs() < 1e-9);
    }

    #[test]
    fn thickness_follows_the_vertices_past_the_last_bone() {
        let m = tube();
        let t = m.thickness(&["a", "b", "c"], 1.0).unwrap();
        assert_eq!(t.len(), 13);
        assert!((t[0] - 2.0).abs() < 1e-9);
        assert!((t[5] - 2.0).abs() < 1e-9);
        assert!((t[12] - 1.0).abs() < 1e-9);
        assert!((m.reach(&["a", "b", "c"], 1.0).unwrap() - 3.0).abs() < 1e-9);
    }

    #[test]
    fn thickness_needs_a_chain() {
        assert!(tube().thickness(&["a"], 1.0).is_none());
        assert!(tube().thickness(&["a", "nope"], 1.0).is_none());
    }
}
