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
    /// Its reference pose and each bone's inverse rest affine, worked out
    /// on first use and kept (operator 2026-11-23: "we don't need to
    /// recalculate the same mathematical thing over and over again").
    #[serde(skip)]
    pub rest: OnceLock<(Vec<Xform>, Vec<glam::DAffine3>)>,
    /// [`Mesh::verts_weighted`]'s answers, kept the same way.
    #[serde(skip)]
    pub weighted: Kept,
}

/// Vertex lists by the bones and least weight asked, kept in memory with
/// the mesh (never on disk). A clone starts empty.
#[derive(Debug, Default)]
#[allow(clippy::type_complexity)]
pub struct Kept(Mutex<HashMap<(Vec<usize>, u64), Arc<Vec<usize>>>>);

impl Clone for Kept {
    fn clone(&self) -> Self {
        Self::default()
    }
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

/// How much of a vertex's weight must be on the chain for the thickness
/// to count it. Drawn with the chain alone ([`Mesh::on_chain`]), the
/// share on other bones is pulled in; a higher share also leaves out
/// skin the chain shares with its neighbours.
pub const OWN: f64 = 0.5;

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

/// A sample's radius from its vertices `pts` (on the plane across the
/// chain line): the circle fitted to all of them in one step, Kasa 1976
/// ("A circle fitting procedure and its error analysis"): the least
/// squares of x^2 + y^2 + D x + E y + F, a 3 by 3 linear solve, centre
/// (-D/2, -E/2) (Guesses 26 and 44: no outline directions, no rounds).
/// Worked about the points' mean, for float accuracy. None with fewer
/// than three points or all on one line (the solve's pivot within float
/// rounding of 0).
fn girth(pts: &[DVec2]) -> Option<f64> {
    if pts.len() < 3 {
        return None;
    }
    let mean = pts.iter().sum::<DVec2>() / pts.len() as f64;
    let mut m = [[0.0f64; 4]; 3];
    for p in pts {
        let q = *p - mean;
        let row = [q.x, q.y, 1.0];
        let z = -(q.x * q.x + q.y * q.y);
        for i in 0..3 {
            for j in 0..3 {
                m[i][j] += row[i] * row[j];
            }
            m[i][3] += row[i] * z;
        }
    }
    let size = m.iter().flat_map(|r| r[..3].iter()).fold(0.0f64, |a, v| a.max(v.abs()));
    // Gaussian elimination with partial pivoting.
    for k in 0..3 {
        let p = (k..3).max_by(|a, b| m[*a][k].abs().total_cmp(&m[*b][k].abs()))?;
        m.swap(k, p);
        if !(m[k][k].abs() > 3.0 * f64::EPSILON * size) {
            return None;
        }
        for i in k + 1..3 {
            let f = m[i][k] / m[k][k];
            for j in k..4 {
                m[i][j] -= f * m[k][j];
            }
        }
    }
    let mut s = [0.0f64; 3];
    for i in (0..3).rev() {
        let mut v = m[i][3];
        for j in i + 1..3 {
            v -= m[i][j] * s[j];
        }
        s[i] = v / m[i][i];
    }
    let (d, e, f) = (s[0], s[1], s[2]);
    let r2 = (d * d + e * e) / 4.0 - f;
    (r2 > 0.0).then(|| r2.sqrt())
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
        self.rest_once().0.clone()
    }

    /// The vertices weighted at least `least` in all to bones `bones`
    /// (bone indices), in vertex order; worked out once per bones and
    /// weight, then kept.
    pub fn verts_weighted(&self, bones: &[usize], least: f64) -> Arc<Vec<usize>> {
        let key = (bones.to_vec(), least.to_bits());
        if let Some(v) = self.weighted.0.lock().get(&key) {
            return v.clone();
        }
        let v: Arc<Vec<usize>> = Arc::new(
            self.verts
                .iter()
                .enumerate()
                .filter(|(_, v)| {
                    v.w.iter()
                        .filter(|(k, _)| bones.contains(&(*k as usize)))
                        .map(|(_, w)| w)
                        .sum::<f64>()
                        >= least
                })
                .map(|(n, _)| n)
                .collect(),
        );
        self.weighted.0.lock().insert(key, v.clone());
        v
    }

    /// Each bone's rest affine inverted (rest space to bone space), kept.
    pub fn rest_inverse(&self) -> &[glam::DAffine3] {
        &self.rest_once().1
    }

    fn rest_once(&self) -> &(Vec<Xform>, Vec<glam::DAffine3>) {
        self.rest.get_or_init(|| {
            let pose = self.ref_pose_worked();
            let inv = pose
                .iter()
                .map(|r| glam::DAffine3::from_scale_rotation_translation(r.scale, r.rot, r.pos).inverse())
                .collect();
            (pose, inv)
        })
    }

    /// Bone `b`'s reference transform relative to its parent.
    fn local(&self, b: usize) -> Xform {
        let b = &self.bones[b];
        Xform {
            rot: DQuat::from_xyzw(b.rot[0], b.rot[1], b.rot[2], b.rot[3]).normalize(),
            pos: DVec3::from_array(b.pos),
            scale: DVec3::from_array(b.scale),
        }
    }

    fn ref_pose_worked(&self) -> Vec<Xform> {
        let mut out: Vec<Xform> = Vec::with_capacity(self.bones.len());
        for (n, b) in self.bones.iter().enumerate() {
            let local = self.local(n);
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
    /// vertex (the drawn tip). Each vertex weighted at least [`OWN`] to
    /// the chain counts at the nearest point of the chain line. As Dynamic
    /// Penetration for Games measures girth (naelstrof, GirthFrame.cs):
    /// each sample's radius is [`girth`]'s, from its vertices laid on
    /// the plane across the line: the outline's mean distance from the
    /// tube's own middle (the line need not run down it). Vertices
    /// inside the outline never count. Reference pose. None with fewer
    /// than two bones or none of them found, or no vertex on them.
    pub fn thickness(&self, chain: &[&str], step: f64) -> Option<Vec<f64>> {
        self.thickness_least(chain, step, OWN)
    }

    /// Vertices `which` where the game draws them: each moved by morphs
    /// `morphs` (name, strength) first, then put on bones posed `pose`
    /// (per mesh bone, any one space: component or world) by its bone
    /// weights, linear blend as the engine skins a mesh (each weight's
    /// share of the vertex taken from the bone's reference pose to its
    /// pose). The answer is in `pose`'s space. A bone missing from `pose`
    /// is drawn as the engine draws a bone no animation drives
    /// ([`Mesh::posed`]). Read only. Asked 2026-11-23: "all of
    /// this data should come from actual observation of doing the
    /// things, not from guessing, but from actually how it's drawn".
    pub fn drawn(
        &self,
        pose: &[Option<Xform>],
        morphs: &[(&str, f64)],
        which: &[usize],
    ) -> Vec<DVec3> {
        let (rest, rest_inv) = self.rest_once();
        // Only the vertices asked for are moved by the morphs, and each
        // bone's skinning (rest to pose) is one affine map, made once per
        // call (the same sum as at.point(rest.inverse_point(p)) per
        // weight; the mod's fits call this thousands of times a scene).
        let mut slot: Vec<u32> = vec![u32::MAX; self.verts.len()];
        for (n, &i) in which.iter().enumerate() {
            if let Some(s) = slot.get_mut(i) {
                *s = n as u32;
            }
        }
        let mut moved: Vec<DVec3> = vec![DVec3::ZERO; which.len()];
        for (name, k) in morphs {
            let Some(m) = self.morphs.iter().find(|m| m.name == *name) else {
                continue;
            };
            for (i, x, y, z) in &m.d {
                if let Some(&s) = slot.get(*i as usize)
                    && s != u32::MAX
                {
                    moved[s as usize] += DVec3::new(*x as f64, *y as f64, *z as f64) * *k;
                }
            }
        }
        let affine =
            |x: &Xform| glam::DAffine3::from_scale_rotation_translation(x.scale, x.rot, x.pos);
        let mut skin: Vec<Option<glam::DAffine3>> = vec![None; rest.len()];
        let mut done: Vec<Option<Xform>> = vec![None; rest.len()];
        let mut skin_of = |b: usize| -> glam::DAffine3 {
            *skin[b].get_or_insert_with(|| {
                affine(&self.posed(pose, rest, &mut done, b)) * rest_inv[b]
            })
        };
        which
            .iter()
            .enumerate()
            .filter_map(|(n, &i)| {
                let v = self.verts.get(i)?;
                let p = DVec3::from_array(v.p) + moved[n];
                let total: f64 = v.w.iter().map(|(_, w)| w).sum();
                if total <= 0.0 {
                    return Some(p);
                }
                Some(
                    v.w.iter()
                        .map(|&(b, w)| skin_of(b as usize).transform_point3(p) * (w / total))
                        .sum(),
                )
            })
            .collect()
    }

    /// Bone `b` as posed: from `pose` when it has it, else as the engine
    /// draws a bone no animation drives (its local reference transform
    /// under its parent as posed, so it moves with its parent in
    /// `pose`'s space; a root, its reference place). The reference pose
    /// in component space alone put a missing bone's skin in the wrong
    /// space when `pose` is in world space (the mouth path 41 m long in
    /// the Archdemon scene, 2026-11-24). `rest` is [`Mesh::ref_pose`];
    /// `done` keeps each answer for the call.
    fn posed(
        &self,
        pose: &[Option<Xform>],
        rest: &[Xform],
        done: &mut [Option<Xform>],
        b: usize,
    ) -> Xform {
        if let Some(x) = done[b] {
            return x;
        }
        let x = match pose.get(b).copied().flatten() {
            Some(x) => x,
            None => match usize::try_from(self.bones[b].parent)
                .ok()
                .filter(|&p| p < done.len())
            {
                Some(p) => self.local(b).under(&self.posed(pose, rest, done, p)),
                None => rest[b],
            },
        };
        done[b] = Some(x);
        x
    }

    /// [`Mesh::thickness`] counting each vertex weighted at least `least`
    /// to the chain.
    pub fn thickness_least(&self, chain: &[&str], step: f64, least: f64) -> Option<Vec<f64>> {
        if step <= 0.0 {
            return None;
        }
        let (pts, starts) = self.line(chain)?;
        let on: Vec<(f64, DVec2)> = self
            .on_chain(chain, least)?
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
        // Each slice at least as long as the widest gap between his
        // vertices along the chain, so no slice falls between his rings
        // (Guess 42: measured from his mesh, not a fixed cm).
        let mut along: Vec<f64> = on.iter().map(|(s, _)| *s).collect();
        along.sort_by(f64::total_cmp);
        let widest_gap = along.windows(2).map(|w| w[1] - w[0]).fold(0.0f64, f64::max);
        let half = step.max(widest_gap) / 2.0;
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

    /// Each vertex weighted at least `least` (0 to 1) to bone chain
    /// `chain`: (its index, distance along the chain, its offset from the
    /// chain line there), as [`Mesh::thickness`] places them. Reference
    /// pose, drawn with the chain alone: every other bone shrunk to
    /// nothing at the chain's first bone (as ueforge pose_hide set_to
    /// hides a bone), so each vertex's share on them is drawn there.
    pub fn on_chain(&self, chain: &[&str], least: f64) -> Option<Vec<(usize, f64, DVec3)>> {
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
            if on < least - 1e-6 {
                continue;
            }
            let p = DVec3::from_array(v.p) * on + pts[0] * (1.0 - on);
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

    /// Per cm along bone chain `chain` (as [`Mesh::on_chain`] places the
    /// vertices weighted at least `least` to it): how many vertices, and
    /// each bone's summed weight on them, most first. What a cm of a
    /// thickness is drawn from.
    #[allow(clippy::type_complexity)]
    pub fn bones_along(
        &self,
        chain: &[&str],
        least: f64,
    ) -> Option<Vec<(usize, Vec<(String, f64)>)>> {
        let on = self.on_chain(chain, least)?;
        let mut out: Vec<(usize, std::collections::BTreeMap<String, f64>)> = Vec::new();
        for (k, s, _) in &on {
            let cm = s.max(0.0).floor() as usize;
            if out.len() <= cm {
                out.resize_with(cm + 1, Default::default);
            }
            out[cm].0 += 1;
            for (b, w) in &self.verts[*k].w {
                *out[cm]
                    .1
                    .entry(self.bones[*b as usize].name.clone())
                    .or_default() += *w;
            }
        }
        Some(
            out.into_iter()
                .map(|(n, by)| {
                    let mut by: Vec<(String, f64)> = by.into_iter().collect();
                    by.sort_by(|a, b| b.1.total_cmp(&a.1));
                    (n, by)
                })
                .collect(),
        )
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
            sockets: Vec::new(),
            verts,
            morphs: Vec::new(),
            rest: OnceLock::new(),
            weighted: Kept::default(),
        }
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

    /// drawn: each weight's share taken from the bone's reference pose to
    /// its pose (turned and scaled unevenly), the morph first, and only
    /// the vertices asked for.
    #[test]
    fn drawn_skins_each_weight_from_rest_to_pose() {
        let mut m = tube();
        m.verts[9].w = vec![(0, 0.25), (1, 0.75)];
        m.morphs.push(Morph {
            name: "m".into(),
            d: vec![(9, 0.0, 1.0, 0.0), (3, 5.0, 0.0, 0.0)],
        });
        let rest = m.ref_pose();
        let pose = vec![
            None,
            Some(Xform {
                rot: DQuat::from_rotation_z(0.7),
                pos: DVec3::new(4.0, 1.0, -2.0),
                scale: DVec3::new(1.0, 2.0, 0.5),
            }),
        ];
        let got = m.drawn(&pose, &[("m", 2.0)], &[9, 10]);
        let p = DVec3::from_array(m.verts[9].p) + DVec3::new(0.0, 2.0, 0.0);
        let at = pose[1].unwrap();
        let want = rest[0].point(rest[0].inverse_point(p)) * 0.25
            + at.point(rest[1].inverse_point(p)) * 0.75;
        assert!((got[0] - want).length() < 1e-9, "{got:?} {want}");
        let q = DVec3::from_array(m.verts[10].p);
        assert!((got[1] - q).length() < 1e-9);
    }

    #[test]
    fn thickness_needs_a_chain() {
        assert!(tube().thickness(&["a"], 1.0).is_none());
        assert!(tube().thickness(&["a", "nope"], 1.0).is_none());
    }
}
