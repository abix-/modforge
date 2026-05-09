//! Research starter: read raw bytes of an item DataTable's first
//! row, sweep offsets, find the field whose value matches a known
//! in-game stack max. Then `write_bytes` to mutate it.
//!
//! Status: pre-offsets. Skips until OWS PlatformOffsets land.
//! Once they do: pick a candidate from
//! `explore_datatables::find_likely_item_tables` (e.g. an addr
//! like `addr:0x...`), edit the const below, and uncomment the
//! body.

mod common;

const _CANDIDATE_DT_ADDR: &str = "addr:0x0000000000000000"; // FIXME: paste from explore_datatables

#[test]
fn dump_first_row_bytes() {
    let Some(_api) = common::try_api() else { return };
    eprintln!(
        "TODO: once a candidate DT addr is known, read the RowMap \
         (offset 0x30 on UE 5.x) bytes via uespy::ops::read_bytes \
         and parse the TMap header. Then walk slots via \
         uespy::ue::tmap::slots()."
    );
}

#[test]
fn sweep_for_stack_offset() {
    let Some(_api) = common::try_api() else { return };
    eprintln!(
        "TODO: pick a row whose stack max we know in-game (e.g. \
         Pebbles at 50). Read 256 bytes from the row pointer. The \
         offset whose 4-byte u32 reads as 50 is the stack-max \
         field. Confirm by reading the same offset on a second row \
         with a different known stack value."
    );
}

#[test]
fn mutate_one_row() {
    let Some(_api) = common::try_api() else { return };
    eprintln!(
        "TODO: write u32 200 to (row_addr, stack_offset). Read \
         back to verify. Then pick up the item in-game and confirm \
         the new stack ceiling."
    );
}
