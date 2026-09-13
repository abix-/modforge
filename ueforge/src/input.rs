//! Unreal connection for Modforge player input and player observation.

use std::ffi::c_void;
use std::sync::OnceLock;
use std::time::Duration;

use crate::ue::UObject;
use crate::ue::actor::LiveActor;
use crate::ue::uobject::NativeProperty;
use modforge::input::{Axis, Button, InputSurface, Key, PlayerCommand};
use modforge::route::{PlayerObservation, Position};

const INPUT_TIMEOUT: Duration = Duration::from_secs(3);
static PAWN_CONTROLLER_OFFSET: OnceLock<Result<usize, String>> = OnceLock::new();
static CONTROL_ROTATION_OFFSET: OnceLock<Result<usize, String>> = OnceLock::new();

/// Maps a virtual-key code to the name of the Enhanced Input action
/// it drives, plus the two look actions. Game-specific (the action
/// names come from the game's InputMappingContext), so the consumer
/// supplies it; the injection mechanism below is UE-generic.
pub struct ActionBindings {
    /// (VK code, Enhanced Input action name) for held movement /
    /// interaction keys.
    pub keys: &'static [(u16, &'static str)],
    /// Action driven by relative mouse X (yaw / turn).
    pub yaw: &'static str,
    /// Action driven by relative mouse Y (pitch / look up-down).
    pub pitch: &'static str,
}

/// Games on the legacy `PlayerInput` path, with no Enhanced Input
/// actions to inject into (Abiotic Factor). The bot calls
/// `APlayerController::InputKey(const FInputKeyParams&)`, the same
/// function the viewport calls for a physical key, at the
/// image-relative address the game's shipped PDB names
/// (`crate::symbols::functions`). Keys are the engine's FKey names.
pub struct LegacyBindings {
    /// Image-relative address of
    /// `APlayerController::InputKey(const FInputKeyParams&)`.
    pub input_key_rva: u32,
    /// (VK code, FKey name) for held keys, e.g. `(0x57, "W")`.
    pub keys: &'static [(u16, &'static str)],
    /// FKey name carrying relative mouse X, normally "MouseX".
    pub yaw: &'static str,
    /// FKey name carrying relative mouse Y, normally "MouseY".
    pub pitch: &'static str,
}

enum Mechanism {
    Enhanced(ActionBindings),
    Legacy(LegacyBindings),
}

/// `FInputKeyParams` as UE 5.4 lays it out, 72 bytes. Read from
/// Abiotic Factor's shipped PDB (abioticfactor-mod/docs/character.md, player
/// input); the unit test below pins every offset to those numbers.
#[repr(C)]
pub struct FInputKeyParams {
    /// FKey: FName KeyName (8) + TSharedPtr<FKeyDetails> (16). A null
    /// KeyDetails is fine; the engine fills it lazily from KeyName.
    pub key_fname_ci: i32,
    pub key_fname_num: u32,
    pub key_details_ptr: usize,
    pub key_details_ref: usize,
    /// FInputDeviceId. 0 is the default keyboard and mouse device.
    pub input_device: i32,
    /// EInputEvent: 0 pressed, 1 released, 4 axis (from the PDB).
    pub event: i32,
    pub num_samples: i32,
    pub delta_time: f32,
    /// FVector Delta. X carries the key amount (1 pressed, 0 released)
    /// or the axis value; the engine leaves Y and Z at zero.
    pub delta_x: f64,
    pub delta_y: f64,
    pub delta_z: f64,
    pub is_gamepad: u8,
    pub _pad: [u8; 7],
}

const IE_PRESSED: i32 = 0;
const IE_RELEASED: i32 = 1;
const IE_AXIS: i32 = 4;

impl FInputKeyParams {
    fn with_key(key_name: &str, event: i32, delta_x: f64) -> Result<Self, String> {
        let fname = crate::ue::fname::from_str(key_name, crate::ue::fname::FindName::Find)
            .ok_or_else(|| format!("the engine has no FKey named '{key_name}'"))?;
        Ok(Self {
            key_fname_ci: fname.comparison_index,
            key_fname_num: fname.number,
            key_details_ptr: 0,
            key_details_ref: 0,
            input_device: 0,
            event,
            num_samples: 1,
            delta_time: 1.0 / 60.0,
            delta_x,
            delta_y: 0.0,
            delta_z: 0.0,
            is_gamepad: 0,
            _pad: [0; 7],
        })
    }

    /// A key going down or up, as the viewport reports a physical key.
    pub fn key(key_name: &str, pressed: bool) -> Result<Self, String> {
        let (event, amount) = if pressed { (IE_PRESSED, 1.0) } else { (IE_RELEASED, 0.0) };
        Self::with_key(key_name, event, amount)
    }

    /// One sample of a relative axis such as MouseX.
    pub fn axis(key_name: &str, delta: f64) -> Result<Self, String> {
        Self::with_key(key_name, IE_AXIS, delta)
    }
}

/// Call `APlayerController::InputKey(const FInputKeyParams&)` on one
/// controller. Game thread only. A structured exception inside the
/// engine comes back as an error instead of taking the game down.
///
/// # Safety
/// `input_key_rva` must be the address of that function in the loaded
/// game image, and `controller` must be a live APlayerController.
unsafe fn call_input_key(
    input_key_rva: u32,
    controller: &UObject,
    params: &FInputKeyParams,
) -> Result<bool, String> {
    let rt = crate::ue::try_runtime().ok_or("ueforge: ue runtime not initialized")?;
    let address = rt.image_base + input_key_rva as usize;
    type InputKeyFn = unsafe extern "system" fn(*const c_void, *const c_void) -> bool;
    // SAFETY: the caller guarantees the address is InputKey in the
    // loaded image; the signature is the engine's (this, const& params).
    let input_key: InputKeyFn = unsafe { std::mem::transmute(address) };
    modforge::seh::guard(|| {
        // SAFETY: controller is live per the caller; params outlives the call.
        unsafe {
            input_key(
                controller as *const UObject as *const c_void,
                params as *const FInputKeyParams as *const c_void,
            )
        }
    })
    .map_err(|error| format!("InputKey at +0x{input_key_rva:X} raised {error}"))
}

pub struct UnrealInputSurface {
    name: &'static str,
    player: &'static LiveActor,
    mechanism: Mechanism,
}

impl UnrealInputSurface {
    pub fn new(name: &'static str, player: &'static LiveActor, bindings: ActionBindings) -> Self {
        Self {
            name,
            player,
            mechanism: Mechanism::Enhanced(bindings),
        }
    }

    pub fn new_legacy(
        name: &'static str,
        player: &'static LiveActor,
        bindings: LegacyBindings,
    ) -> Self {
        Self {
            name,
            player,
            mechanism: Mechanism::Legacy(bindings),
        }
    }

    /// The local player's pawn. Game thread only: falls back to the
    /// GObjects search when nothing has retained it yet.
    fn player(&self) -> Result<&'static UObject, String> {
        self.player
            .retained()
            .or_else(|| self.player.get())
            .ok_or_else(|| "Unreal input has no local player".into())
    }

    fn name_for_key(&self, key: Key) -> Result<&'static str, String> {
        let keys = match &self.mechanism {
            Mechanism::Enhanced(bindings) => bindings.keys,
            Mechanism::Legacy(bindings) => bindings.keys,
        };
        keys.iter()
            .find(|(vk, _)| *vk == key.0)
            .map(|(_, name)| *name)
            .ok_or_else(|| format!("no input binding for key 0x{:X}", key.0))
    }
}

impl InputSurface for &'static UnrealInputSurface {
    fn name(&self) -> &'static str {
        self.name
    }

    fn click(&self, _button: Button, _x: i32, _y: i32) -> Result<(), String> {
        Err("absolute UI clicks are not implemented by Unreal input".into())
    }

    fn move_abs(&self, _x: i32, _y: i32) -> Result<(), String> {
        Err("absolute cursor movement is not implemented by Unreal input".into())
    }

    fn move_rel(&self, dx: i32, dy: i32) -> Result<(), String> {
        let surface: &'static UnrealInputSurface = *self;
        match &surface.mechanism {
            Mechanism::Enhanced(bindings) => {
                let (yaw, pitch) = (bindings.yaw, bindings.pitch);
                crate::game_thread::run(
                    move || {
                        let subsystem = enhanced::subsystem()?;
                        if dx != 0 {
                            enhanced::inject_once(subsystem, enhanced::action(yaw)?, dx as f64)?;
                        }
                        if dy != 0 {
                            enhanced::inject_once(subsystem, enhanced::action(pitch)?, dy as f64)?;
                        }
                        Ok(serde_json::Value::Null)
                    },
                    INPUT_TIMEOUT,
                )
                .map(|_| ())
            }
            Mechanism::Legacy(bindings) => {
                let (yaw, pitch, rva) = (bindings.yaw, bindings.pitch, bindings.input_key_rva);
                crate::game_thread::run(
                    move || {
                        // SAFETY: the player's controller is read on the game thread.
                        let controller = unsafe { pawn_controller(surface.player()?)? };
                        for (key_name, delta) in [(yaw, dx), (pitch, dy)] {
                            if delta == 0 {
                                continue;
                            }
                            let params = FInputKeyParams::axis(key_name, delta as f64)?;
                            // SAFETY: rva names InputKey in this image (from the
                            // game's PDB) and the controller is the live player's.
                            unsafe { call_input_key(rva, controller, &params)? };
                        }
                        Ok(serde_json::Value::Null)
                    },
                    INPUT_TIMEOUT,
                )
                .map(|_| ())
            }
        }
    }

    fn key(&self, key: Key, down: bool) -> Result<(), String> {
        let surface: &'static UnrealInputSurface = *self;
        let name = surface.name_for_key(key)?;
        match &surface.mechanism {
            Mechanism::Enhanced(_) => crate::game_thread::run(
                move || {
                    let subsystem = enhanced::subsystem()?;
                    let action_ptr = enhanced::action(name)?;
                    if down {
                        enhanced::start_continuous(subsystem, action_ptr, 1.0)?;
                    } else {
                        enhanced::stop_continuous(subsystem, action_ptr)?;
                    }
                    Ok(serde_json::Value::Null)
                },
                INPUT_TIMEOUT,
            )
            .map(|_| ()),
            Mechanism::Legacy(bindings) => {
                let rva = bindings.input_key_rva;
                crate::game_thread::run(
                    move || {
                        // SAFETY: the player's controller is read on the game thread.
                        let controller = unsafe { pawn_controller(surface.player()?)? };
                        let params = FInputKeyParams::key(name, down)?;
                        // SAFETY: rva names InputKey in this image (from the
                        // game's PDB) and the controller is the live player's.
                        unsafe { call_input_key(rva, controller, &params)? };
                        Ok(serde_json::Value::Null)
                    },
                    INPUT_TIMEOUT,
                )
                .map(|_| ())
            }
        }
    }

    fn axis(&self, axis: Axis, value: f32, _delta_time: f32) -> Result<(), String> {
        match axis {
            Axis::MouseX => self.move_rel(value.round() as i32, 0),
            Axis::MouseY => self.move_rel(0, value.round() as i32),
            Axis::MoveForward | Axis::MoveRight => Err(format!(
                "Unreal bot movement uses held keys (key op), not axis {axis:?}"
            )),
        }
    }

    fn observe_player(&self) -> Result<PlayerObservation, String> {
        let surface = *self;
        let value = crate::game_thread::run(
            move || {
                let player = surface.player()?;
                let position =
                    // SAFETY: the retained player is live for this game-thread job.
                    unsafe { crate::ue::transform::world_location(player.as_ptr() as *const u8) }
                        .ok_or("could not read the retained player's world location")?;
                // SAFETY: the retained player and reflected fields are read on the game thread.
                let (pitch_deg, yaw_deg) = unsafe { read_control_rotation(player)? };
                serde_json::to_value(PlayerObservation {
                    position: Position::new(position.0, position.1, position.2),
                    yaw_deg,
                    pitch_deg,
                })
                .map_err(|error| format!("serialize player observation: {error}"))
            },
            INPUT_TIMEOUT,
        )?;
        serde_json::from_value(value).map_err(|error| format!("decode player observation: {error}"))
    }

    fn commands(&self, commands: &[PlayerCommand]) -> Result<(), String> {
        for command in commands {
            match *command {
                PlayerCommand::Key { key, down } => self.key(key, down)?,
                PlayerCommand::MouseDelta { dx, dy } => self.move_rel(dx, dy)?,
            }
        }
        Ok(())
    }
}

pub fn register(name: &'static str, player: &'static LiveActor, bindings: ActionBindings) {
    let surface: &'static UnrealInputSurface =
        Box::leak(Box::new(UnrealInputSurface::new(name, player, bindings)));
    modforge::input::set_input_surface(surface);
}

/// The same surface for a legacy `PlayerInput` game. `bindings.input_key_rva`
/// comes from the game's PDB through `crate::symbols::functions`.
pub fn register_legacy(name: &'static str, player: &'static LiveActor, bindings: LegacyBindings) {
    let surface: &'static UnrealInputSurface =
        Box::leak(Box::new(UnrealInputSurface::new_legacy(name, player, bindings)));
    modforge::input::set_input_surface(surface);
}

/// UE-generic Enhanced Input action injection. The action objects and
/// the subsystem are resolved by reflection (class chain + object
/// name), so nothing here is game-specific; the caller supplies action
/// names. The two BlueprintCallable UFunctions
/// (`Start`/`StopContinuousInputInjectionForAction`) hold and release
/// an action across frames; `InjectInputForAction` fires it for one
/// tick (used for mouse deltas). Verified live: injecting ForwardInput
/// walked the character. See misery research.md section 31.
mod enhanced {
    use super::UObject;
    use parking_lot::Mutex;
    use std::collections::HashMap;

    const IFACE: &str = "EnhancedInputSubsystemInterface";

    static SUBSYSTEM: Mutex<Option<u64>> = Mutex::new(None);
    static ACTIONS: Mutex<Option<HashMap<String, u64>>> = Mutex::new(None);

    fn readable(addr: u64) -> bool {
        addr > 0x1_0000 && modforge::winproc::is_addr_readable(addr as usize)
    }

    /// The live `EnhancedInputLocalPlayerSubsystem`, cached and
    /// re-resolved if the cached pointer goes stale (level reload).
    pub fn subsystem() -> Result<&'static UObject, String> {
        let mut cache = SUBSYSTEM.lock();
        if let Some(addr) = *cache {
            if readable(addr) {
                // SAFETY: the address is a live UObject we found before
                // and just confirmed readable.
                return Ok(unsafe { &*(addr as *const UObject) });
            }
        }
        let addr = crate::ue::actor::find_objects_by_chain("EnhancedInputLocalPlayerSubsystem")
            .first()
            .map(|p| *p as u64)
            .ok_or("EnhancedInputLocalPlayerSubsystem not found")?;
        *cache = Some(addr);
        // SAFETY: address came from the GObjects walk.
        Ok(unsafe { &*(addr as *const UObject) })
    }

    /// The `UInputAction` object pointer for `name`. A cache miss does
    /// ONE object-list walk and caches EVERY InputAction by name, so a
    /// bot resolving W/A/S/D/E/look pays one search total, then never
    /// searches again while travelling (performance.md: searches are
    /// the cost; the travel loop must do none). Re-resolved only if a
    /// cached pointer goes stale on a world change.
    pub fn action(name: &str) -> Result<u64, String> {
        let mut cache = ACTIONS.lock();
        let map = cache.get_or_insert_with(HashMap::new);
        if let Some(&addr) = map.get(name) {
            if readable(addr) {
                return Ok(addr);
            }
        }
        map.clear();
        for p in crate::ue::actor::find_objects_by_chain("InputAction") {
            // SAFETY: p came from the GObjects walk.
            let obj = unsafe { &*(p as *const UObject) };
            map.insert(obj.name(), p as u64);
        }
        map.get(name)
            .copied()
            .ok_or_else(|| format!("UInputAction '{name}' not found"))
    }

    // Parm block (72 bytes) shared by Start / Inject: Action ptr at
    // +0x00; FInputActionValue at +0x08 (FVector Value; Value.X carries
    // the magnitude; ValueType at +0x18 = Axis1D(1)); empty Modifiers
    // TArray at +0x28 and Triggers TArray at +0x38.
    fn value_parms(action_ptr: u64, value: f64) -> Vec<u8> {
        let mut p = vec![0u8; 72];
        p[0..8].copy_from_slice(&action_ptr.to_le_bytes());
        p[8..16].copy_from_slice(&value.to_le_bytes());
        p[32] = 1;
        p
    }

    fn call(subsystem: &UObject, function: &str, parms: Vec<u8>) -> Result<(), String> {
        crate::ops::exec_call(subsystem, IFACE, function, parms).map(|_| ())
    }

    pub fn start_continuous(subsystem: &UObject, action_ptr: u64, value: f64) -> Result<(), String> {
        call(
            subsystem,
            "StartContinuousInputInjectionForAction",
            value_parms(action_ptr, value),
        )
    }

    pub fn stop_continuous(subsystem: &UObject, action_ptr: u64) -> Result<(), String> {
        call(
            subsystem,
            "StopContinuousInputInjectionForAction",
            action_ptr.to_le_bytes().to_vec(),
        )
    }

    pub fn inject_once(subsystem: &UObject, action_ptr: u64, value: f64) -> Result<(), String> {
        call(
            subsystem,
            "InjectInputForAction",
            value_parms(action_ptr, value),
        )
    }
}

unsafe fn pawn_controller(player: &UObject) -> Result<&'static UObject, String> {
    let offset = match PAWN_CONTROLLER_OFFSET
        .get_or_init(|| class_property_offset(player, "Controller", 8))
    {
        Ok(offset) => *offset,
        Err(error) => return Err(error.clone()),
    };
    // SAFETY: the reflected property is at least pointer-sized and belongs to the live player.
    let address = unsafe { (player.field_ptr(offset) as *const usize).read_unaligned() };
    if address == 0 {
        return Err("local player has no controller".into());
    }
    // SAFETY: Unreal owns the non-null controller pointer for the retained player.
    Ok(unsafe { &*(address as *const UObject) })
}

unsafe fn read_control_rotation(player: &UObject) -> Result<(f64, f64), String> {
    // SAFETY: caller provides the retained player on the game thread.
    let controller = unsafe { pawn_controller(player)? };
    let offset = match CONTROL_ROTATION_OFFSET
        .get_or_init(|| class_property_offset(controller, "ControlRotation", 24))
    {
        Ok(offset) => *offset,
        Err(error) => return Err(error.clone()),
    };
    // SAFETY: the reflected rotation field belongs to the live controller.
    let rotation = unsafe { controller.field_ptr(offset) };
    // SAFETY: the reflected rotation field is at least 24 bytes and contains pitch then yaw.
    let pitch = unsafe { (rotation as *const f64).read_unaligned() };
    // SAFETY: the reflected rotation field is at least 24 bytes.
    let yaw = unsafe { (rotation.add(8) as *const f64).read_unaligned() };
    Ok((pitch, yaw))
}

/// Offset of the reflected property `name` on the object's class or any super class.
pub fn class_property_offset(object: &UObject, name: &str, minimum_size: u32) -> Result<usize, String> {
    let mut class = object.class();
    let mut depth = 0;
    while let Some(current) = class {
        if depth >= 64 {
            return Err(format!(
                "class chain exceeded 64 entries while resolving {name}"
            ));
        }
        let properties = current.cached_native_properties();
        if let Some(offset) = reflected_property_offset(&properties, name, minimum_size)? {
            return Ok(offset);
        }
        class = current.super_class();
        depth += 1;
    }
    Err(format!("class chain has no reflected {name} field"))
}

fn reflected_property_offset(
    properties: &[NativeProperty],
    name: &str,
    minimum_size: u32,
) -> Result<Option<usize>, String> {
    let Some(property) = properties.iter().find(|property| property.name == name) else {
        return Ok(None);
    };
    if property.element_size < minimum_size {
        return Err(format!(
            "reflected field {name} is {} bytes, expected at least {minimum_size}",
            property.element_size
        ));
    }
    Ok(Some(property.offset as usize))
}

#[cfg(test)]
mod tests {
    use modforge::input::Key;

    use super::{ActionBindings, FInputKeyParams, reflected_property_offset};
    use crate::ue::uobject::NativeProperty;

    /// The numbers are the ones `ueforge::symbols::layout` read from
    /// Abiotic Factor's PDB (UE 5.4). If this struct drifts from them,
    /// InputKey reads garbage.
    #[test]
    fn input_key_params_matches_the_pdb_layout() {
        use std::mem::{offset_of, size_of};
        assert_eq!(size_of::<FInputKeyParams>(), 72);
        assert_eq!(offset_of!(FInputKeyParams, key_fname_ci), 0);
        assert_eq!(offset_of!(FInputKeyParams, key_details_ptr), 8);
        assert_eq!(offset_of!(FInputKeyParams, input_device), 24);
        assert_eq!(offset_of!(FInputKeyParams, event), 28);
        assert_eq!(offset_of!(FInputKeyParams, num_samples), 32);
        assert_eq!(offset_of!(FInputKeyParams, delta_time), 36);
        assert_eq!(offset_of!(FInputKeyParams, delta_x), 40);
        assert_eq!(offset_of!(FInputKeyParams, is_gamepad), 64);
    }

    const MISERY: ActionBindings = ActionBindings {
        keys: &[
            (0x57, "ForwardInput"),
            (0x53, "BackwardInput"),
            (0x41, "LeftInput"),
            (0x44, "RightInput"),
            (0x45, "InteractInput"),
        ],
        yaw: "TurnInput",
        pitch: "LookupDownInput",
    };

    #[test]
    fn reflected_field_requires_the_expected_size() {
        let properties = [NativeProperty {
            name: "ControlRotation".into(),
            offset: 0x320,
            element_size: 24,
        }];
        assert_eq!(
            reflected_property_offset(&properties, "ControlRotation", 24).unwrap(),
            Some(0x320)
        );
        assert!(reflected_property_offset(&properties, "ControlRotation", 32).is_err());
    }

    #[test]
    fn key_bindings_map_wasde() {
        let action = |vk: u16| MISERY.keys.iter().find(|(k, _)| *k == vk).map(|(_, n)| *n);
        assert_eq!(action(Key(0x57).0), Some("ForwardInput"));
        assert_eq!(action(Key(0x45).0), Some("InteractInput"));
        assert_eq!(action(0x99), None);
    }
}
