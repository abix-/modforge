//! Network object identities exported by the server, independent of host memory.
use crate::bits::{Reader, Writer, invalid};
use std::collections::BTreeMap;
use std::io;

#[derive(Default)]
pub(crate) struct Objects {
    names: BTreeMap<u32, (u32, String)>,
}

#[derive(Default)]
pub(crate) struct Controller {
    pub channel: Option<u32>,
    pub player_state: u32,
    pub pawn: u32,
    pub initialized: bool,
    pub trait_selection_requested: bool,
    pub traits_sent: bool,
    pub skills_ready: bool,
    pub spawn_after_traits: bool,
    pub loading_requested: bool,
    pub position: Option<[f64; 3]>,
    pub position_source: &'static str,
}

impl Controller {
    pub fn receive_pawn(&mut self, reader: &mut Reader<'_>) -> io::Result<()> {
        while reader.remaining() > 0 {
            let properties = reader.get(1)? != 0;
            if reader.get(1)? == 0 { return Ok(()); }
            let size = reader.packed()? as usize;
            let mut block = reader.take(size)?;
            if properties { continue; }
            while block.remaining() > 0 {
                let field = block.bounded(310)?;
                let size = block.packed()? as usize;
                let mut args = block.take(size)?;
                if field == 31 {
                    if let Some(position) = movement_response(&mut args)? {
                        self.position = Some(position);
                        self.position_source = "server movement correction";
                        eprintln!("[abiotic-client] UDP position {position:?} ({})", self.position_source);
                    }
                }
                // Abiotic_PlayerCharacter: Client_EvaluateLoadingScreen and
                // Client_SetupCharacter. Reply only on our possessed pawn.
                if matches!(field, 205 | 217) {
                    self.loading_requested = true;
                    eprintln!("[abiotic-client] server requested character loading setup");
                }
            }
        }
        Ok(())
    }

    pub fn receive_state(&mut self, reader: &mut Reader<'_>) -> io::Result<()> {
        while reader.remaining() > 0 {
            let properties = reader.get(1)? != 0;
            if reader.get(1)? == 0 { return Ok(()); }
            let size = reader.packed()? as usize;
            let mut block = reader.take(size)?;
            if !properties { continue; }
            if block.get(1)? != 0 { return Err(invalid("player-state property checksums unsupported")); }
            loop {
                match block.packed()? {
                    0 => break,
                    1..=4 | 19..=23 | 32 | 34 => { block.get(1)?; }
                    5 | 14 => { block.get(3)?; }
                    13 | 15 | 28 => { block.packed()?; }
                    16 | 17 | 24 => { block.get(32)?; }
                    18 => { block.get(8)?; }
                    29 => {
                        if block.get(1)? != 0 { block.packed()?; }
                        else { block.string()?; block.get(32)?; }
                    }
                    30 => {
                        self.skills_ready = block.get(1)? != 0;
                        eprintln!("[abiotic-client] server skills ready: {}", self.skills_ready);
                    }
                    handle => return Err(invalid(&format!("unsupported player-state update handle {handle}"))),
                }
            }
        }
        Ok(())
    }

    pub fn receive(&mut self, reader: &mut Reader<'_>) -> io::Result<()> {
        while reader.remaining() > 0 {
            let properties = reader.get(1)? != 0;
            let is_actor = reader.get(1)? != 0;
            if !is_actor { return Ok(()); } // subobjects are not player-controller state
            let bits = reader.packed()? as usize;
            let mut block = reader.take(bits)?;
            if !properties {
                while block.remaining() != 0 {
                    let field = block.bounded(169)?;
                    let size = block.packed()? as usize;
                    block.take(size)?;
                    if field == 118 {
                        self.trait_selection_requested = true;
                        eprintln!("[abiotic-client] server requested character trait selection");
                    }
                }
                continue;
            }
            if block.get(1)? != 0 { return Err(invalid("controller property checksums unsupported")); }
            loop {
                let handle = block.packed()?;
                match handle {
                    0 => break,
                    1..=4 | 21..=23 => { block.get(1)?; }
                    // FByteProperty includes ROLE_MAX when choosing its bit width.
                    5 | 14 => { block.get(3)?; }
                    6 | 11 | 13 | 15 | 19 | 25 => { block.packed()?; }
                    16 => {
                        self.player_state = block.packed()?;
                        eprintln!("[abiotic-client] controller player state {}", self.player_state);
                    }
                    17 => {
                        self.pawn = block.packed()?;
                        eprintln!("[abiotic-client] controller pawn {}", self.pawn);
                    }
                    7 | 8 => { Objects::quantized_vector(&mut block)?; }
                    9 | 18 => {
                        for _ in 0..3 { if block.get(1)? != 0 { block.get(16)?; } }
                    }
                    10 | 24 => {
                        if block.get(1)? != 0 { block.packed()?; }
                        else { block.string()?; block.get(32)?; }
                    }
                    20 => { for _ in 0..3 { block.get(64)?; } }
                    _ => return Err(invalid(&format!("unsupported controller property handle {handle}"))),
                }
            }
        }
        Ok(())
    }
}

pub(crate) struct Bunch {
    pub payload: Writer,
    pub open: bool,
    pub must_map: bool,
    pub partial: bool,
    pub initial: bool,
    pub final_part: bool,
}

/// Prefix established from this build's FCharacterMoveResponseDataContainer::Serialize.
/// A base-relative correction is not a world coordinate without that base's transform.
fn movement_response(args: &mut Reader<'_>) -> io::Result<Option<[f64; 3]>> {
    if args.get(1)? == 0 { return Ok(None); }
    let length = args.packed()? as usize;
    let mut data = args.take(length)?;
    let good_move = data.get(1)? != 0;
    let timestamp = f32::from_bits(data.get(32)? as u32);
    if !timestamp.is_finite() { return Err(invalid("non-finite correction timestamp")); }
    if good_move { return Ok(None); }
    data.get(1)?; // bHasBase
    let rotation = data.get(1)? != 0;
    let montage = data.get(1)? != 0;
    let root_motion = data.get(1)? != 0;
    let position = Objects::raw_vector(&mut data)?;
    Objects::raw_vector(&mut data)?; // velocity
    if data.get(1)? != 0 { Objects::raw_vector(&mut data)?; } // gravity
    if rotation {
        for _ in 0..3 { if data.get(1)? != 0 { data.get(16)?; } }
    }
    if data.get(1)? != 0 { data.packed()?; } // base object
    if data.get(1)? != 0 { // base bone name
        if data.get(1)? != 0 { data.packed()?; }
        else { data.string()?; data.get(32)?; }
    }
    if data.get(1)? != 0 { data.get(8)?; } // movement mode, default walking
    let relative_position = data.get(1)? != 0;
    data.get(1)?; // relative velocity
    if relative_position || montage || root_motion {
        eprintln!("[abiotic-client] correction requires base/root-motion decoding; position not updated");
        return Ok(None);
    }
    if data.remaining() != 0 || args.remaining() != 0 { return Err(invalid("unexpected movement correction tail")); }
    Ok(Some(position))
}

pub(crate) struct Channel {
    pub sequence: u16,
    pub waiting: BTreeMap<u16, Bunch>,
    partial: Option<Bunch>,
}

impl Channel {
    pub fn new(sequence: u16) -> Self {
        Self { sequence, waiting: BTreeMap::new(), partial: None }
    }

    pub fn assemble(&mut self, mut bunch: Bunch) -> io::Result<Option<Bunch>> {
        if !bunch.partial { return Ok(Some(bunch)); }
        if bunch.initial {
            if self.partial.is_some() { return Err(invalid("overlapping actor fragments")); }
            self.partial = Some(bunch);
        } else {
            let pending = self.partial.as_mut().ok_or_else(|| invalid("actor fragment missing initial"))?;
            if pending.payload.len() + bunch.payload.len() > 8 * 1024 * 1024 {
                return Err(invalid("actor fragments exceed size limit"));
            }
            pending.payload.append(&bunch.payload);
            pending.must_map = bunch.must_map;
            pending.final_part = bunch.final_part;
        }
        if self.partial.as_ref().is_some_and(|pending| pending.final_part) {
            bunch = self.partial.take().unwrap();
            bunch.partial = false;
            return Ok(Some(bunch));
        }
        Ok(None)
    }
}

impl Objects {
    fn raw_vector(reader: &mut Reader<'_>) -> io::Result<[f64; 3]> {
        let mut vector = [0.0; 3];
        for value in &mut vector { *value = f64::from_bits(reader.get(64)?); }
        if vector.iter().any(|v| !v.is_finite()) { return Err(invalid("non-finite raw vector")); }
        Ok(vector)
    }
    pub fn spawn_body(reader: &mut Reader<'_>) -> io::Result<[f64; 3]> {
        reader.packed()?; // level
        let position = Self::spawn_vector(reader, [0.0; 3])?;
        if reader.get(1)? != 0 {
            for _ in 0..3 { if reader.get(1)? != 0 { reader.get(16)?; } }
        }
        Self::spawn_vector(reader, [1.0; 3])?;
        Self::spawn_vector(reader, [0.0; 3])?;
        Ok(position)
    }

    fn spawn_vector(reader: &mut Reader<'_>, default: [f64; 3]) -> io::Result<[f64; 3]> {
        if reader.get(1)? == 0 { return Ok(default); }
        if reader.get(1)? != 0 {
            Self::read_vector(reader, 10.0)
        } else {
            let mut value = [0.0; 3];
            for component in &mut value { *component = f64::from_bits(reader.get(64)?); }
            if value.iter().any(|v| !v.is_finite()) { return Err(invalid("non-finite spawn vector")); }
            Ok(value)
        }
    }

    pub(crate) fn read_vector(reader: &mut Reader<'_>, scale: f64) -> io::Result<[f64; 3]> {
        let header = reader.get(7)?;
        let width = (header & 63) as usize;
        let scaled = header & 64 != 0;
        let mut value = [0.0; 3];
        for component in &mut value {
            *component = if width == 0 {
                if scaled { f64::from_bits(reader.get(64)?) } else { f64::from(f32::from_bits(reader.get(32)? as u32)) }
            } else {
                let bits = reader.get(width)?;
                let signed = ((bits << (64 - width)) as i64) >> (64 - width);
                signed as f64 / if scaled { scale } else { 1.0 }
            };
        }
        if value.iter().any(|v| !v.is_finite()) { return Err(invalid("non-finite network vector")); }
        Ok(value)
    }

    fn quantized_vector(reader: &mut Reader<'_>) -> io::Result<()> {
        let header = reader.get(7)?;
        let width = match header & 63 {
            0 => if header & 64 != 0 { 64 } else { 32 },
            width => width as usize,
        };
        for _ in 0..3 { reader.get(width)?; }
        Ok(())
    }

    pub fn exports(&mut self, reader: &mut Reader<'_>) -> io::Result<()> {
        if reader.get(1)? != 0 {
            return Err(invalid("replication layout exports are not supported yet"));
        }
        let count = reader.get(32)?;
        if count > 2048 { return Err(invalid("too many exported objects")); }
        for _ in 0..count { self.object(reader, true, 0)?; }
        Ok(())
    }

    fn object(&mut self, reader: &mut Reader<'_>, export: bool, depth: usize) -> io::Result<u32> {
        if depth > 16 { return Err(invalid("network object nesting exceeds limit")); }
        let guid = reader.packed()?;
        if guid != 0 && (export || guid == 1) {
            let flags = reader.get(8)?;
            if flags & 1 != 0 {
                let outer = self.object(reader, export, depth + 1)?;
                let name = reader.string()?;
                if flags & 4 != 0 { reader.get(32)?; }
                if self.names.len() >= 65536 && !self.names.contains_key(&guid) {
                    return Err(invalid("network object cache exceeds limit"));
                }
                self.names.insert(guid, (outer, name));
            }
        }
        Ok(guid)
    }

    pub fn spawn(&mut self, reader: &mut Reader<'_>, must_map: bool) -> io::Result<(u32, String)> {
        if must_map {
            let count = reader.get(16)?;
            if count > 2048 { return Err(invalid("too many required objects")); }
            for _ in 0..count { reader.packed()?; }
        }
        let actor = self.object(reader, false, 0)?;
        let archetype = if actor != 0 && actor & 1 == 0 {
            self.object(reader, false, 0)?
        } else { actor };
        let name = self.names.get(&archetype).map(|(_, name)| name.clone()).unwrap_or_default();
        Ok((actor, name))
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::bits::Writer;

    #[test]
    fn packed_vectors_decode_signed_scaled_and_full_precision_coordinates() {
        let mut wire = Writer::default();
        wire.put(64 | 12, 7);
        for value in [-1234i64, 567, -1] { wire.put(value as u64, 12); }
        let bytes = wire.finish();
        assert_eq!(Objects::read_vector(&mut Reader::packet(&bytes).unwrap(), 100.0).unwrap(), [-12.34, 5.67, -0.01]);
        let mut wire = Writer::default();
        wire.put(64, 7);
        for value in [-12018.5f64, 16077.1, 21655.3] { wire.put(value.to_bits(), 64); }
        let bytes = wire.finish();
        assert_eq!(Objects::read_vector(&mut Reader::packet(&bytes).unwrap(), 100.0).unwrap(), [-12018.5, 16077.1, 21655.3]);
        assert!(Objects::read_vector(&mut Reader::packet(&bytes[..10]).unwrap(), 100.0).is_err());
    }

    #[test]
    fn correction_does_not_treat_relative_coordinates_as_world_position() {
        for relative in [false, true] {
            let mut data = Writer::default();
            data.put(0, 1); // correction, not good-move acknowledgement
            data.put(u64::from(1.0f32.to_bits()), 32);
            data.put(0, 4); // base, rotation and root-motion flags
            for value in [100.0f64, 200.0, 300.0, 0.0, 0.0, 0.0] { data.put(value.to_bits(), 64); }
            data.put(0, 4); // gravity, base, bone, nondefault movement mode
            data.put(u64::from(relative), 1);
            data.put(0, 1); // relative velocity
            let mut args = Writer::default();
            args.put(1, 1);
            args.packed(data.len() as u32);
            args.append(&data);
            let bytes = args.finish();
            let result = movement_response(&mut Reader::packet(&bytes).unwrap()).unwrap();
            assert_eq!(result, if relative { None } else { Some([100.0, 200.0, 300.0]) });
            let truncated = &bytes[..bytes.len() - 1];
            assert!(Reader::packet(truncated).and_then(|mut reader| movement_response(&mut reader)).is_err());
        }
    }

    #[test]
    fn controller_references_come_from_replication() {
        let mut props = Writer::default();
        props.put(0, 1);
        props.packed(5);
        props.put(3, 3);
        props.packed(14);
        props.put(2, 3);
        props.packed(16);
        props.packed(442);
        props.packed(17);
        props.packed(444);
        props.packed(0);
        let mut block = Writer::default();
        block.put(1, 1);
        block.put(1, 1);
        block.packed(props.len() as u32);
        block.append(&props);
        let bytes = block.finish();
        let mut controller = Controller::default();
        controller.receive(&mut Reader::packet(&bytes).unwrap()).unwrap();
        assert_eq!((controller.player_state, controller.pawn), (442, 444));
    }

    #[test]
    fn fragments_preserve_open_and_final_mapping_flags() {
        let mut channel = Channel::new(1023);
        let mut first = Writer::default();
        first.put(19, 8);
        assert!(channel.assemble(Bunch { payload: first, open: true, must_map: false,
            partial: true, initial: true, final_part: false }).unwrap().is_none());
        let mut last = Writer::default();
        last.put(3, 2);
        let assembled = channel.assemble(Bunch { payload: last, open: false, must_map: true,
            partial: true, initial: false, final_part: true }).unwrap().unwrap();
        assert!(assembled.open && assembled.must_map);
        assert_eq!(assembled.payload.len(), 10);
        let bytes = assembled.payload.finish();
        assert_eq!(Reader::packet(&bytes).unwrap().get(10).unwrap(), 19 | (3 << 8));
    }

    #[test]
    fn exported_archetype_identifies_spawned_actor() {
        let mut wire = Writer::default();
        wire.put(0, 1);
        wire.put(1, 32);
        wire.packed(3);
        wire.put(5, 8);
        wire.packed(0);
        wire.string("Default__Abiotic_PlayerController_C");
        wire.put(123, 32);
        let bytes = wire.finish();
        let mut objects = Objects::default();
        objects.exports(&mut Reader::packet(&bytes).unwrap()).unwrap();
        let mut spawn = Writer::default();
        spawn.packed(2);
        spawn.packed(3);
        let bytes = spawn.finish();
        assert_eq!(objects.spawn(&mut Reader::packet(&bytes).unwrap(), false).unwrap(),
            (2, "Default__Abiotic_PlayerController_C".into()));
    }
}
