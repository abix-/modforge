//! The name labels of the items on the ground, the thing a click picks
//! up. After ExileCore2's ItemsOnGroundLabelElement.VisibleGroundItemLabels
//! (offsets ship scrambled there); this build's places were found by
//! tests/research_labels.rs (2026-11-07): the element is the UI
//! manager's child 8, child 0; it holds at +0x2F0 a list of 72-byte
//! label groups, each group a list (at +0) of 32-byte records with
//! the label element at +0 and the item's entity id at +8.
//! GameHelper2 has no such reader.

use anyhow::Result;
use modforge::msvc_std::{Vector, read_vector_header};
use modforge::process_memory::ProcessMemory;
use serde::Serialize;

/// Child indexes from the UI manager to the label element.
pub const PATH: [usize; 2] = [8, 0];
/// The list of label groups in the label element.
pub const VISIBLE_GROUPS: u64 = 0x2F0;
/// Most groups and labels read, against a torn list.
const MAX_GROUPS: usize = 256;
const MAX_LABELS: usize = 1024;

/// VisibleItemLabelGroupOffsets: 72 bytes, its labels first.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct Group {
    labels: Vector,
    rest: [u64; 6],
}

/// VisibleItemLabelOffsets: 32 bytes.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct Record {
    element: u64,
    id: u32,
    rest: [u32; 5],
}

/// One label: its UI element and the ground item entity's id.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Serialize)]
pub struct Label {
    pub element: u64,
    pub id: u32,
}

/// Every label in the label element at `at`, group by group.
pub fn read(mem: &ProcessMemory, at: u64) -> Result<Vec<Label>> {
    let groups = read_vector_header(mem, at + VISIBLE_GROUPS)?;
    let n = groups.len(size_of::<Group>() as u64).min(MAX_GROUPS);
    let mut out = Vec::new();
    if n == 0 {
        return Ok(out);
    }
    for g in mem.read_array::<Group>(groups.first, n)? {
        let m = g.labels.len(size_of::<Record>() as u64);
        if m == 0 || out.len() + m > MAX_LABELS {
            continue;
        }
        let records = mem.read_array::<Record>(g.labels.first, m)?;
        out.extend(
            records
                .iter()
                .filter(|r| r.element != 0)
                .map(|r| Label {
                    element: r.element,
                    id: r.id,
                }),
        );
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::entities::tests::put;

    #[test]
    fn reads_every_group_s_labels() {
        assert_eq!(size_of::<Group>(), 72);
        assert_eq!(size_of::<Record>(), 32);
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let mut records = [[0u8; 32]; 3];
        for (i, r) in records.iter_mut().enumerate() {
            put(&mut r[..], 0, 0x1000 + i as u64);
            put(&mut r[..], 8, 0x78 + i as u32);
        }
        // The second record has no element and is skipped.
        put(&mut records[1][..], 0, 0u64);
        let first = records.as_ptr() as u64;
        let mut groups = [[0u8; 72]; 2];
        put(
            &mut groups[0][..],
            0,
            Vector {
                first,
                last: first + 64,
                end: first + 64,
            },
        );
        put(
            &mut groups[1][..],
            0,
            Vector {
                first: first + 64,
                last: first + 96,
                end: first + 96,
            },
        );
        let g = groups.as_ptr() as u64;
        let mut element = [0u8; 0x320];
        put(
            &mut element[..],
            0x2F0,
            Vector {
                first: g,
                last: g + 144,
                end: g + 144,
            },
        );
        let labels = read(&mem, element.as_ptr() as u64).unwrap();
        assert_eq!(
            labels,
            [
                Label { element: 0x1000, id: 0x78 },
                Label { element: 0x1002, id: 0x7a }
            ]
        );
        assert!(read(&mem, [0u8; 0x320].as_ptr() as u64).unwrap().is_empty());
    }
}
