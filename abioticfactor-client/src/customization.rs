//! Sophia's character choices from the shipped customization tables.
use crate::bits::Writer;

fn name(writer: &mut Writer, value: &str) {
    writer.put(0, 1);
    writer.string(value);
    writer.put(0, 32);
}

pub(crate) fn female() -> Writer {
    let mut args = Writer::default();
    args.put(1, 1); // SoftObjectProperty: female voice asset path.
    name(&mut args, "/Game/Blueprints/DataAssets/PlayerCharacterVoices/PlayerCharacterVoice_FemaleA");
    name(&mut args, "PlayerCharacterVoice_FemaleA");
    args.string(""); // no subobject path
    // Server_ApplyAllCustomizationData's cooked parameter order.
    for row in ["Head_F01a", "Hair_Ponytail", "HairColor_Brown", "Glasses_None",
        "UpperBody_F_Default", "Skirt_Default", "ShirtColor_White", "Belt_Default",
        "Shoes_Black", "Tie_Default", "Beard_None_A", "Watch_Black", "id_science"] {
        args.put(1, 1);
        name(&mut args, row);
    }
    args.put(1, 1);
    args.put(0.5f64.to_bits(), 64); // skin tone
    args
}
