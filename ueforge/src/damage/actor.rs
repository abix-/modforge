//! Observe Actor.ReceiveAnyDamage once for point, radial and generic damage.
//! K8s slot: Def=native Actor damage signature, Registry=watched vtables,
//! Instance=ActorDamageTracker, Controller=ProcessEvent callback.
use crate::{hook::ProcessEventHook, reflect, ue::{UObject, uobject::ObjectIdentity}};
use parking_lot::Mutex;
use std::{collections::{BTreeMap, VecDeque}, sync::Arc};

#[derive(Clone)]
pub struct ActorDamageEvent {
    pub sequence: u64,
    pub victim: ObjectIdentity,
    pub causer: Option<ObjectIdentity>,
    pub instigator: Option<ObjectIdentity>,
}

#[derive(Default)]
struct Journal { sequence: u64, events: VecDeque<ActorDamageEvent> }

#[derive(Default)]
pub struct ActorDamageTracker {
    hooks: BTreeMap<usize, ProcessEventHook>,
    journal: Arc<Mutex<Journal>>,
}

impl ActorDamageTracker {
    pub fn sequence(&self) -> u64 { self.journal.lock().sequence }

    /// # Safety
    /// Actor must be live; install on the game thread. Blueprint subclasses can
    /// share a native vtable, so one hook watches all actors sharing that table.
    pub unsafe fn watch(&mut self, actor: &UObject) -> Result<(), String> {
        // SAFETY: every live UObject starts with its native vtable pointer.
        let vtable = unsafe { actor.as_ptr().cast::<usize>().read_unaligned() };
        if self.hooks.contains_key(&vtable) { return Ok(()); }
        // get_function searches the declaring class's children, not inherited
        // functions on the concrete actor's Blueprint class.
        let class = crate::ue::find_class_fast("Actor").ok_or("Actor class unavailable")?;
        let function = class.get_function("Actor", "ReceiveAnyDamage").ok_or("Actor.ReceiveAnyDamage unavailable")?;
        let signature = function.as_object().fname().as_u64();
        let parameters = function.iter_parameters();
        let offset = |name: &str, kind: &str| -> Result<usize, String> {
            let p = parameters.iter().find(|p| p.name == name).ok_or_else(|| format!("damage event lacks {name}"))?;
            if reflect::property_type(p).as_deref() != Some(kind) { return Err(format!("damage event {name} is not {kind}")); }
            if p.offset + p.element_size > u32::from(function.parms_size()) { return Err(format!("damage event {name} exceeds its parameter block")); }
            Ok(p.offset as usize)
        };
        let damage = offset("Damage", "FloatProperty")?;
        let causer = offset("DamageCauser", "ObjectProperty")?;
        let instigator = offset("InstigatedBy", "ObjectProperty")?;
        let journal = self.journal.clone();
        let hook = ProcessEventHook::install_for_object("Actor damage observer", actor, move |this, function, params, original| {
            // Non-damage calls take no lock and allocate nothing.
            if function.as_object().fname().as_u64() == signature && !params.is_null() {
                // SAFETY: offsets were checked against this inherited native
                // signature. Event actor references belong to the current call.
                unsafe {
                    let base = params.cast::<u8>();
                    if base.add(damage).cast::<f32>().read_unaligned() > 0.0 {
                        let identity = |at: usize| {
                            let object = base.add(at).cast::<*const UObject>().read_unaligned();
                            object.as_ref().map(ObjectIdentity::capture)
                        };
                        let mut journal = journal.lock();
                        journal.sequence += 1;
                        let event = ActorDamageEvent { sequence: journal.sequence, victim: ObjectIdentity::capture(this),
                            causer: identity(causer), instigator: identity(instigator) };
                        if journal.events.len() == 256 { journal.events.pop_front(); }
                        journal.events.push_back(event);
                    }
                }
            }
            // SAFETY: forward the engine's original call without mutation.
            unsafe { original.call(this, function, params) };
        }).map_err(str::to_owned)?;
        self.hooks.insert(vtable, hook);
        Ok(())
    }

    /// Each consumer has its own cursor; reading one companion's events cannot
    /// consume another's. Overflow is visible and advances the failed cursor.
    pub fn since(&self, cursor: &mut u64) -> Result<Vec<ActorDamageEvent>, String> {
        let journal = self.journal.lock();
        let previous = *cursor;
        *cursor = journal.sequence;
        if journal.events.front().is_some_and(|event| previous + 1 < event.sequence) {
            return Err("actor damage journal overflowed before the consumer read it".into());
        }
        Ok(journal.events.iter().filter(|event| event.sequence > previous).cloned().collect())
    }
}
