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

use glam::{DQuat, DVec2, DVec3};
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

/// A morph target on LOD 0: (vertex index, offset x, y, z in cm at
/// weight 1) for each vertex it moves.
#[derive(Clone, Debug, Deserialize)]
pub struct Morph {
    pub name: String,
    pub d: Vec<(u32, f32, f32, f32)>,
}

#[derive(Clone, Debug, Deserialize)]
pub struct Mesh {
    pub bones: Vec<Bone>,
    /// Mesh sockets first, then the skeleton's.
    #[serde(default)]
    pub sockets: Vec<Socket>,
    pub verts: Vec<Vert>,
    #[serde(default)]
    pub morphs: Vec<Morph>,
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

/// The opening morphs' value and the canal bone's widening that fit
/// something round in a canal, from [`Mesh::canal_width`]: `need[j]` the
/// radius the canal must open to j to j+1 cm in (0: nothing there), each
/// ring (j, closed, opened at 1) the canal's narrowest wall there; a
/// morph opens a wall in proportion to its value, and widening the
/// canal's bone by k puts each wall k times as far out. With `widen`:
/// of the values 0 to `most` (every 0.01), the one with the least gap
/// between the walls and `need`, each given the least widening (1 or
/// more) that leaves no cm narrower than needed. Without: no widening
/// and the value that fits the tightest cm. Returns (value, widening).
/// Asked 2026-11-22: "we need to fix the morp so the opening AND the
/// inside is accurate for the changed size".
pub fn fit_opening(
    need: &[f64],
    rings: &[(usize, f64, f64)],
    widen: bool,
    most: f64,
) -> (f64, f64) {
    let at = |j: usize| need.get(j).copied().unwrap_or(0.0);
    let wall = |w: f64, r0: f64, r1: f64| r0 + w * (r1 - r0);
    if rings.iter().all(|&(j, _, _)| at(j) <= 0.0) {
        return (0.0, 1.0);
    }
    if !widen {
        let w = rings
            .iter()
            .filter(|&&(_, r0, r1)| r1 > r0)
            .map(|&(j, r0, r1)| (at(j) - r0) / (r1 - r0))
            .fold(0.0, f64::max);
        return (w, 1.0);
    }
    let mut best = (f64::MAX, 0.0, 1.0);
    for n in 0..=(most.max(0.0) * 100.0) as usize {
        let w = n as f64 / 100.0;
        let k = rings
            .iter()
            .map(|&(j, r0, r1)| at(j) / wall(w, r0, r1).max(1e-6))
            .fold(1.0, f64::max);
        let gap: f64 = rings
            .iter()
            .filter(|&&(j, _, _)| at(j) > 0.0)
            .map(|&(j, r0, r1)| k * wall(w, r0, r1) - at(j))
            .sum();
        if gap < best.0 {
            best = (gap, w, k);
        }
    }
    (best.1, best.2)
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

/// Directions around the chain line a thickness sample's outline is
/// taken in. Dynamic Penetration for Games takes 64 from a drawn map; a
/// half cm sample of the Ogre's penis holds 10 to 100 vertices, so
/// fewer directions, each still holding one.
const AROUND: usize = 16;

/// How long a slice along the chain each thickness sample is measured
/// from, cm, at least its step. The Ogre's drawn rings are about 1 cm
/// apart, so a shorter slice can fall between them.
const SLICE_CM: f64 = 1.0;

/// The chain line's direction `s` cm along it (points `pts`, their
/// distances `starts`): the segment `s` falls in, past the end the
/// last; zero length segments skipped.
fn dir_at(pts: &[DVec3], starts: &[f64], s: f64) -> DVec3 {
    let segs = (0..pts.len() - 1).filter(|&j| (pts[j + 1] - pts[j]).length() > 1e-9);
    let j = segs
        .clone()
        .rfind(|&j| starts[j] <= s)
        .or_else(|| segs.clone().next())
        .unwrap_or(0);
    (pts[j + 1] - pts[j]).normalize_or(DVec3::X)
}

/// Points `pts`' outline around `mid`: the farthest from it in each of
/// [`AROUND`] directions.
fn outline(pts: &[DVec2], mid: DVec2) -> [Option<DVec2>; AROUND] {
    let mut cells = [None; AROUND];
    for &p in pts {
        let q = p - mid;
        let a = (q.y.atan2(q.x) / std::f64::consts::TAU).rem_euclid(1.0);
        let c: &mut Option<DVec2> = &mut cells[(a * AROUND as f64) as usize % AROUND];
        if c.is_none_or(|o| q.length() > (o - mid).length()) {
            *c = Some(p);
        }
    }
    cells
}

/// A sample's radius from its vertices `pts` (on the plane across the
/// chain line, the line at the origin): the outline's mean distance
/// from its middle. The middle, as GirthFrame.cs: the midpoints of lines
/// through the centre taken lie on the circle through it and the
/// middle, around halfway between, so twice their mean from it; then
/// (mine) the outline taken again around that middle, 10 times, since
/// fixed directions from far off centre leave it off. None with no
/// vertex.
fn girth(pts: &[DVec2]) -> Option<f64> {
    if pts.is_empty() {
        return None;
    }
    let mut mid = DVec2::ZERO;
    for _ in 0..10 {
        let cells = outline(pts, mid);
        let pairs: Vec<DVec2> = (0..AROUND / 2)
            .filter_map(|i| Some((cells[i]? + cells[i + AROUND / 2]?) / 2.0))
            .collect();
        mid = if pairs.is_empty() {
            let out: Vec<DVec2> = cells.iter().flatten().copied().collect();
            out.iter().sum::<DVec2>() / out.len() as f64
        } else {
            mid + (pairs.iter().sum::<DVec2>() / pairs.len() as f64 - mid) * 2.0
        };
    }
    let out: Vec<DVec2> = outline(pts, mid).iter().flatten().copied().collect();
    Some(out.iter().map(|p| p.distance(mid)).sum::<f64>() / out.len() as f64)
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
    /// chain counts at the nearest point of the chain line. As Dynamic
    /// Penetration for Games measures girth (naelstrof, GirthFrame.cs):
    /// each sample's radius is [`girth`]'s, from its vertices laid on
    /// the plane across the line: the outline's mean distance from the
    /// shaft's own middle (the line need not run down it). Vertices
    /// inside the outline never count. Reference pose. None with fewer
    /// than two bones or none of them found, or no vertex on them.
    pub fn thickness(&self, chain: &[&str], step: f64) -> Option<Vec<f64>> {
        if step <= 0.0 {
            return None;
        }
        let (pts, starts) = self.line(chain)?;
        let on: Vec<(f64, DVec2)> = self
            .on_chain(chain)?
            .into_iter()
            .map(|(_, s, off)| {
                let d = dir_at(&pts, &starts, s);
                let up = if d.z.abs() < 0.9 { DVec3::Z } else { DVec3::X }
                    .reject_from(d)
                    .normalize();
                (s, DVec2::new(off.dot(d.cross(up)), off.dot(up)))
            })
            .collect();
        let end = on.iter().map(|(s, _)| *s).fold(-1.0, f64::max);
        if end < 0.0 || end / step > 100_000.0 {
            return None;
        }
        let half = (step.max(SLICE_CM)) / 2.0;
        let slices: Vec<Vec<DVec2>> = (0..=(end / step).floor() as usize)
            .map(|k| {
                let mid = (k as f64 + 0.5) * step;
                on.iter()
                    .filter(|(s, _)| (s - mid).abs() <= half)
                    .map(|(_, q)| *q)
                    .collect()
            })
            .collect();
        let mut bins: Vec<f64> = slices.iter().map(|p| girth(p).unwrap_or(-1.0)).collect();
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

    /// Bone chain `chain`'s points (reference pose) and each one's
    /// distance along the chain. None with fewer than two bones or one
    /// not found.
    fn line(&self, chain: &[&str]) -> Option<(Vec<DVec3>, Vec<f64>)> {
        if chain.len() < 2 {
            return None;
        }
        let pose = self.ref_pose();
        let pts: Vec<DVec3> = chain
            .iter()
            .map(|n| Some(pose[self.bone(n)?].pos))
            .collect::<Option<_>>()?;
        let mut starts = vec![0.0];
        for w in pts.windows(2) {
            starts.push(starts.last().copied().unwrap_or(0.0) + (w[1] - w[0]).length());
        }
        Some((pts, starts))
    }

    /// Each vertex weighted at least half to bone chain `chain`: (its
    /// index, distance along the chain, its offset from the chain line
    /// there), as [`Mesh::thickness`] places them. Reference pose.
    pub fn on_chain(&self, chain: &[&str]) -> Option<Vec<(usize, f64, DVec3)>> {
        let idx: Vec<usize> = chain.iter().map(|n| self.bone(n)).collect::<Option<_>>()?;
        let (pts, starts) = self.line(chain)?;
        let last = pts.len() - 2;
        let mut out = Vec::new();
        for (n, v) in self.verts.iter().enumerate() {
            let on: f64 =
                v.w.iter()
                    .filter(|(b, _)| idx.contains(&(*b as usize)))
                    .map(|(_, w)| w)
                    .sum();
            if on < 0.5 {
                continue;
            }
            let p = DVec3::from_array(v.p);
            let mut best = (0.0, DVec3::ZERO, f64::MAX);
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
                let off = p - (a + d * u);
                if off.length() < best.2 {
                    best = (starts[j] + u, off, off.length());
                }
            }
            out.push((n, best.0, best.1));
        }
        Some(out)
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

    /// The drawn canal's width, closed and opened: along the line
    /// [`Mesh::canal`] fits (`bones`, `from`, `to`), every cm from the
    /// entrance, the nearest wall vertex to the line (the narrowest the
    /// canal is there, cm), at rest and with morphs `morphs` all at
    /// weight 1. Reference pose. Index k is k to k+1 cm in; a cm with no
    /// wall vertex is None. Asked 2026-11-22: "the canal didnt open wide
    /// enough. is are we not redoing the curve/morph properly??".
    #[allow(clippy::type_complexity)]
    pub fn canal_width(
        &self,
        bones: &[&str],
        from: &str,
        to: &str,
        morphs: &[&str],
    ) -> Option<Vec<Option<(f64, f64)>>> {
        let (a, b) = self.canal(bones, from, to)?;
        let d = (b - a).normalize_or_zero();
        let idx: Vec<usize> = bones.iter().map(|n| self.bone(n)).collect::<Option<_>>()?;
        let mut moved = vec![DVec3::ZERO; self.verts.len()];
        for n in morphs {
            let m = self.morphs.iter().find(|m| m.name == *n)?;
            for &(k, x, y, z) in &m.d {
                if let Some(v) = moved.get_mut(k as usize) {
                    *v += DVec3::new(x as f64, y as f64, z as f64);
                }
            }
        }
        let mut out: Vec<Option<(f64, f64)>> = Vec::new();
        for (v, off) in self.verts.iter().zip(&moved) {
            let on: f64 =
                v.w.iter()
                    .filter(|(k, _)| idx.contains(&(*k as usize)))
                    .map(|(_, w)| w)
                    .sum();
            if on < 0.5 {
                continue;
            }
            let p = DVec3::from_array(v.p) - a;
            let s = p.dot(d);
            if s < 0.0 || s > 1000.0 {
                continue;
            }
            let k = s.floor() as usize;
            if out.len() <= k {
                out.resize(k + 1, None);
            }
            let (r0, r1) = (
                p.reject_from(d).length(),
                (p + *off).reject_from(d).length(),
            );
            out[k] = Some(match out[k] {
                Some((a0, a1)) => (a0.min(r0), a1.min(r1)),
                None => (r0, r1),
            });
        }
        Some(out)
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
            morphs: Vec::new(),
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

    /// The player's vagina as measured (research_mesh_canal_width): the
    /// entrance closed 0.02, opened 2.09 at 1; inside 1.15, opened 2.10.
    const RINGS: &[(usize, f64, f64)] = &[(0, 0.02, 2.09), (3, 1.15, 2.10)];

    #[test]
    fn opening_fits_entrance_and_inside_with_widening() {
        let need = [3.3, 3.3, 3.3, 3.3];
        let (w, k) = fit_opening(&need, RINGS, true, 5.0);
        for &(j, r0, r1) in RINGS {
            let r = k * (r0 + w * (r1 - r0));
            assert!(r >= need[j] - 1e-6, "cm {j}: {r} < {}", need[j]);
            assert!(r - need[j] < 0.1, "cm {j}: gap {}", r - need[j]);
        }
    }

    #[test]
    fn opening_without_widening_fits_the_tightest_cm() {
        let (w, k) = fit_opening(&[3.3, 0.0, 0.0, 3.3], RINGS, false, 5.0);
        assert_eq!(k, 1.0);
        assert!((w - (3.3 - 1.15) / 0.95).abs() < 1e-9);
    }

    #[test]
    fn opening_closed_when_nothing_is_in() {
        assert_eq!(fit_opening(&[0.0; 4], RINGS, true, 5.0), (0.0, 1.0));
    }

    #[test]
    fn canal_width_opens_with_the_morph() {
        let mut m = tube();
        for v in &mut m.verts {
            v.p[0] += 0.5;
        }
        // Every tube vertex 1 cm farther out.
        let d = m
            .verts
            .iter()
            .enumerate()
            .filter(|(_, v)| v.p[1].abs() < 10.0)
            .map(|(k, v)| {
                let r = (v.p[1] * v.p[1] + v.p[2] * v.p[2]).sqrt();
                (k as u32, 0.0, (v.p[1] / r) as f32, (v.p[2] / r) as f32)
            })
            .collect();
        m.morphs.push(Morph {
            name: "open".into(),
            d,
        });
        let w = m.canal_width(&["a", "b"], "in", "deep", &["open"]).unwrap();
        let (r0, r1) = w[2].unwrap();
        assert!(
            (r0 - 2.0).abs() < 1e-6 && (r1 - 3.0).abs() < 1e-6,
            "{r0} {r1}"
        );
        let (r0, r1) = w[8].unwrap();
        assert!(
            (r0 - 1.0).abs() < 1e-6 && (r1 - 2.0).abs() < 1e-6,
            "{r0} {r1}"
        );
        assert!(
            m.canal_width(&["a", "b"], "in", "deep", &["nope"])
                .is_none()
        );
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

    /// A 2 cm round shaft 1.5 cm off the chain line, with a vertex inside
    /// it: radius 2, not the 3.5 its far side is from the line.
    #[test]
    fn thickness_measures_around_the_shafts_own_middle() {
        let mut m = tube();
        m.verts.clear();
        for i in 0..=4 {
            for a in 0..64 {
                let t = a as f64 * std::f64::consts::TAU / 64.0;
                m.verts.push(Vert {
                    p: [i as f64 + 0.5, 1.5 + 2.0 * t.cos(), 2.0 * t.sin()],
                    w: vec![(0, 1.0)],
                });
            }
            m.verts.push(Vert {
                p: [i as f64 + 0.5, 1.5, 0.0],
                w: vec![(0, 1.0)],
            });
        }
        let t = m.thickness(&["a", "b"], 1.0).unwrap();
        for r in &t {
            assert!((r - 2.0).abs() < 0.1, "{t:?}");
        }
    }

    #[test]
    fn thickness_needs_a_chain() {
        assert!(tube().thickness(&["a"], 1.0).is_none());
        assert!(tube().thickness(&["a", "nope"], 1.0).is_none());
    }
}
