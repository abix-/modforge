// Shared client for integration tests against the mod's debug HTTP
// endpoint.
//
// Tests need a live, modded Grounded 2 instance. Set BBP_DEBUG_PORT
// to enable; if unset, tests skip with a clear message instead of
// failing CI. Default port matches `settings.example.json`.
//
// Run pattern (from a terminal, after launching Grounded 2 + loading a save):
//
//     set BBP_DEBUG_PORT=17171
//     cargo test --test bandage_regression -- --test-threads=1 --nocapture
//
// Tests share a single global game-state, so always pass
// `--test-threads=1` -- otherwise concurrent ops will race.

#![allow(dead_code)]

use serde::Deserialize;
use serde_json::{Value, json};

const DEFAULT_PORT: u16 = 17171;

pub struct Api {
    port: u16,
    agent: ureq::Agent,
}

impl Api {
    /// Connect to the running mod. If the env var `BBP_DEBUG_PORT`
    /// is unset, returns None so the test can skip instead of fail.
    pub fn try_connect() -> Option<Self> {
        let port = std::env::var("BBP_DEBUG_PORT")
            .ok()
            .and_then(|s| s.parse::<u16>().ok())
            .or_else(|| {
                // Allow tests to opt in without the env var by setting
                // this fallback in the test. Returning None here would
                // skip; returning Some(DEFAULT_PORT) means "try the
                // default, fail loudly if nothing is listening".
                std::env::var("BBP_DEBUG_PORT_DEFAULT").ok().map(|_| DEFAULT_PORT)
            })?;
        let agent = ureq::AgentBuilder::new()
            .timeout(std::time::Duration::from_secs(5))
            .build();
        Some(Self { port, agent })
    }

    /// Same as try_connect but skips the test (panics with a marker
    /// the test can `#[should_panic]` on if BBP_DEBUG_PORT is set).
    /// Use when the test absolutely requires the endpoint and you
    /// want a clear "not enabled" message.
    pub fn require() -> Self {
        Self::try_connect().expect(
            "BBP_DEBUG_PORT not set. Launch Grounded 2 with the mod's \
             debug.http_port enabled in settings.json, then set \
             BBP_DEBUG_PORT to the same value before running tests.",
        )
    }

    pub fn op(&self, op: &str, args: Value) -> OpResponse {
        let body = json!({ "op": op, "args": args });
        let url = format!("http://127.0.0.1:{}/debug", self.port);
        let res = self
            .agent
            .post(&url)
            .send_json(body)
            .unwrap_or_else(|e| panic!("debug-http POST failed: {e}"));
        res.into_json::<OpResponse>()
            .expect("debug-http response was not valid JSON")
    }

    pub fn snapshot(&self) -> Snapshot {
        self.op("snapshot", Value::Null).state
    }

    /// Returns the post-op state, asserting `ok=true`. Use when the
    /// op is expected to succeed and you don't care about the
    /// `result` payload, only the resulting state.
    pub fn op_ok(&self, op: &str, args: Value) -> Snapshot {
        let r = self.op(op, args);
        assert!(r.ok, "op {op} failed: {:?}", r.error);
        r.state
    }

    /// Convenience: spend N points on a skill (after a previous
    /// refund / reset). Asserts the op succeeded.
    pub fn skill_spend(&self, id: &str, count: u32) -> Snapshot {
        self.op_ok("skill_spend", json!({"id": id, "count": count}))
    }

    /// Convenience: refund N points on a skill.
    pub fn skill_refund(&self, id: &str, count: u32) -> Snapshot {
        self.op_ok("skill_refund", json!({"id": id, "count": count}))
    }

    /// Convenience: toggle a skill on/off.
    pub fn skill_toggle(&self, id: &str, enabled: bool) -> Snapshot {
        self.op_ok("skill_toggle", json!({"id": id, "enabled": enabled}))
    }

    /// Convenience: simulate a heal event.
    pub fn simulate_heal(&self, amount: f32) -> Snapshot {
        self.op_ok("simulate_heal", json!({"amount": amount}))
    }

    /// Generic UFunction call. The endpoint exposes one `call` op;
    /// every UE-side experiment goes through it. Tests build the
    /// parm bytes from `#[repr(C)]` structs that mirror the SDK,
    /// hex-encode, send, decode the post-call buffer.
    ///
    /// Selectors today: `"live_player_hc"`, `"live_player"`,
    /// `"first_class:<ClassName>"`. Add more in the mod's
    /// `resolve_instance` if needed.
    pub fn call_ufunction(
        &self,
        class: &str,
        function: &str,
        instance_selector: &str,
        parms_bytes: &[u8],
    ) -> Result<(Vec<u8>, Snapshot), String> {
        let parms_hex = hex_encode(parms_bytes);
        let r = self.op(
            "call",
            json!({
                "class": class,
                "function": function,
                "instance_selector": instance_selector,
                "parms_hex": parms_hex,
            }),
        );
        if !r.ok {
            return Err(r.error.unwrap_or_else(|| "<no error>".into()));
        }
        let after_hex = r
            .result
            .get("parms_hex_after")
            .and_then(|v| v.as_str())
            .ok_or_else(|| "no parms_hex_after in result".to_string())?;
        let after = hex_decode(after_hex).map_err(|e| format!("bad hex: {e}"))?;
        Ok((after, r.state))
    }
}

// ---- hex helpers (mirror the mod-side encoding so test-side
// parm buffers round-trip cleanly) ----

pub fn hex_encode(bytes: &[u8]) -> String {
    const HEX: &[u8; 16] = b"0123456789abcdef";
    let mut s = String::with_capacity(bytes.len() * 2);
    for b in bytes {
        s.push(HEX[(b >> 4) as usize] as char);
        s.push(HEX[(b & 0xF) as usize] as char);
    }
    s
}

pub fn hex_decode(s: &str) -> Result<Vec<u8>, String> {
    if s.len() % 2 != 0 {
        return Err(format!("odd hex length: {}", s.len()));
    }
    let mut out = Vec::with_capacity(s.len() / 2);
    let bytes = s.as_bytes();
    fn nib(b: u8) -> Result<u8, String> {
        match b {
            b'0'..=b'9' => Ok(b - b'0'),
            b'a'..=b'f' => Ok(b - b'a' + 10),
            b'A'..=b'F' => Ok(b - b'A' + 10),
            _ => Err(format!("bad hex char: 0x{b:02x}")),
        }
    }
    for i in (0..bytes.len()).step_by(2) {
        out.push((nib(bytes[i])? << 4) | nib(bytes[i + 1])?);
    }
    Ok(out)
}

/// Helper: encode a `#[repr(C)]` parm struct as bytes for `call_ufunction`.
/// Caller is responsible for the struct exactly matching the
/// game's UFunction parm layout (per the SDK headers).
///
/// # Safety
/// `T` must be a plain-old-data struct with no padding traps. Use
/// `#[repr(C)]` and explicit pad fields. Caller must NOT pass a
/// type containing references / pointers it doesn't own.
pub unsafe fn parms_as_bytes<T: Sized>(parms: &T) -> &[u8] {
    unsafe {
        std::slice::from_raw_parts(
            parms as *const T as *const u8,
            std::mem::size_of::<T>(),
        )
    }
}

/// Helper: decode raw bytes back into a `#[repr(C)]` parm struct
/// (e.g. to read OUT-parameters the engine wrote during the call).
///
/// # Safety
/// Same constraints as `parms_as_bytes`. `bytes.len()` must equal
/// `size_of::<T>()`.
pub unsafe fn bytes_as_parms<T: Sized + Copy>(bytes: &[u8]) -> Result<T, String> {
    if bytes.len() != std::mem::size_of::<T>() {
        return Err(format!(
            "parm size mismatch: bytes={} expected={}",
            bytes.len(),
            std::mem::size_of::<T>()
        ));
    }
    let mut t = std::mem::MaybeUninit::<T>::uninit();
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), t.as_mut_ptr() as *mut u8, bytes.len());
        Ok(t.assume_init())
    }
}

impl Snapshot {
    pub fn skill_level(&self, id: &str) -> u32 {
        self.player_state
            .as_ref()
            .and_then(|ps| ps.skill_levels.get(id))
            .and_then(Value::as_u64)
            .unwrap_or(0) as u32
    }

    pub fn is_disabled(&self, id: &str) -> bool {
        self.disabled_skills.iter().any(|s| s == id)
    }

    pub fn live_hc(&self) -> &HcFields {
        self.live_player
            .as_ref()
            .expect("no live player")
            .hc
            .as_ref()
            .expect("no live HC")
    }

    pub fn hp(&self) -> f32 {
        let hc = self.live_hc();
        // CurrentDamage on UHealthComponent is "damage taken so far",
        // so HP = MaxHealth - CurrentDamage.
        hc.max_health - hc.current_damage
    }
}

#[derive(Debug, Deserialize)]
pub struct OpResponse {
    pub ok: bool,
    pub op: String,
    pub error: Option<String>,
    #[serde(default)]
    pub result: Value,
    pub state: Snapshot,
}

#[derive(Debug, Deserialize)]
pub struct Snapshot {
    pub slot: Option<String>,
    pub player_state: Option<PlayerStateView>,
    #[serde(default)]
    pub disabled_skills: Vec<String>,
    pub vanilla: VanillaView,
    pub live_player: Option<LivePlayerView>,
    pub cdo: CdoView,
    pub inventory: InventoryView,
    #[serde(default)]
    pub status_effects: Option<Vec<StatusEffectView>>,
    #[serde(default)]
    pub catalog: Vec<CatalogEntry>,
    pub settings: SettingsView,
    #[serde(default)]
    pub damage_ring: Vec<DamageEvent>,
    #[serde(default)]
    pub counters: Value,
    #[serde(default)]
    pub process_memory: Value,
    #[serde(default)]
    pub process_cpu: Value,
    #[serde(default)]
    pub process_threads: Value,
    #[serde(default)]
    pub game_population: Value,
}

#[derive(Debug, Deserialize, Clone)]
pub struct DamageEvent {
    pub at_secs: u64,
    pub function: String,
    pub damage: f32,
    pub damage_flags: i32,
    pub type_flags: u32,
    pub current_damage_before: Option<f32>,
    pub current_damage_after: Option<f32>,
}

#[derive(Debug, Deserialize)]
pub struct StatusEffectView {
    pub row: String,
    pub table: String,
    pub stat_type: Option<u8>,
    pub value: Option<f32>,
}

#[derive(Debug, Deserialize)]
pub struct CatalogEntry {
    pub id: String,
    pub display_name: String,
    pub max_level: u32,
    pub effect_kind: String,
}

#[derive(Debug, Deserialize)]
pub struct SettingsView {
    pub inventory_slot_count: i32,
    pub thirst_multiplier: f32,
    pub hunger_multiplier: f32,
    pub buggy_kill_xp_multiplier: f32,
    pub debug_http_port: Option<u16>,
}

#[derive(Debug, Deserialize)]
pub struct InventoryView {
    pub current_slot_count: i32,
}

#[derive(Debug, Deserialize)]
pub struct PlayerStateView {
    pub xp: u64,
    pub level: u32,
    pub skill_points: u32,
    #[serde(default)]
    pub skill_levels: serde_json::Map<String, Value>,
    pub kill_count: u64,
    pub last_killed: String,
}

#[derive(Debug, Deserialize)]
pub struct VanillaView {
    pub hunger: Option<f32>,
    pub thirst: Option<f32>,
    pub fall_damage_ratio: Option<f32>,
    pub max_health: Option<f32>,
    #[serde(default)]
    pub hc_u32_masks: Vec<HcMaskView>,
}

#[derive(Debug, Deserialize)]
pub struct HcMaskView {
    pub offset: String,
    pub value: String,
}

#[derive(Debug, Deserialize)]
pub struct LivePlayerView {
    pub instance_count: usize,
    pub hc: Option<HcFields>,
    pub cmc: Option<CmcFields>,
    pub asc: Option<AscFields>,
}

#[derive(Debug, Deserialize)]
pub struct HcFields {
    pub required_damage_type_flags: String,
    pub immunity_flags: String,
    pub base_damage_reduction: f32,
    pub max_health: f32,
    pub current_damage: f32,
}

#[derive(Debug, Deserialize, Clone)]
pub struct CmcFields {
    pub max_walk_speed: f32,
    pub max_sprint_speed: f32,
    pub max_swim_speed: f32,
    pub max_swim_sprint_speed: f32,
    pub max_fly_speed: f32,
    pub jump_z_velocity: f32,
    pub air_control: f32,
    pub air_control_boost_multiplier: f32,
    pub air_control_boost_velocity_threshold: f32,
    pub custom_ground_speed_multiplier: f32,
    pub custom_fly_speed_multiplier: f32,
    pub custom_swim_speed_multiplier: f32,
}

#[derive(Debug, Deserialize)]
pub struct AscFields {
    pub custom_damage_multiplier: f32,
    pub take_fall_damage: bool,
    pub minimum_fall_damage_velocity: f32,
    pub fall_damage_ratio: f32,
}

#[derive(Debug, Deserialize)]
pub struct CdoView {
    pub survival: Option<SurvivalCdoFields>,
    pub global_combat_data: Option<GlobalCombatDataFields>,
    pub game_mode_settings: Option<GmsFields>,
    pub survival_mode_manager: Option<SmmcFields>,
}

#[derive(Debug, Deserialize)]
pub struct SurvivalCdoFields {
    pub hunger_adjustment_per_second: f32,
    pub thirst_adjustment_per_second: f32,
}

#[derive(Debug, Deserialize)]
pub struct GlobalCombatDataFields {
    pub combat_regen_delay: f32,
    pub combat_regen_tick_percentage: f32,
    pub combat_regen_tick_rate: f32,
}

#[derive(Debug, Deserialize)]
pub struct GmsFields {
    pub fall_damage_multiplier: f32,
}

#[derive(Debug, Deserialize)]
pub struct SmmcFields {
    pub custom_fall_damage_multiplier: f32,
}
