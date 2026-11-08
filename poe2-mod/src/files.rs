//! The game's loaded files, read the way GameHelper2's LoadedFiles and
//! AreaChangeCounter do (GameOffsets/Objects/LoadedFilesOffset.cs,
//! AreaChangeOffset.cs):
//!
//! - the "AreaChangeCounter" global is an int that goes up on every
//!   area change;
//! - the "File Root" global points at [`ROOT_BUCKETS`] buckets, each of
//!   [`FilePointer`]s, each pointing at a file's info: its name (a
//!   wstring at 0x08) and the area change count it was last used in
//!   (an int at 0x40).

use crate::model::LoadedFile;
use anyhow::{Context, Result};
use modforge::msvc_std::{read_bucket, read_wstring};
use modforge::process_memory::ProcessMemory;

/// GameHelper2 LoadedFilesRootObject.TotalCount.
pub const ROOT_BUCKETS: u64 = 0x10;
/// Size of one root bucket. GameHelper2's StdBucket is 0x40; on the
/// build of 2026-11-06 the next bucket's vector starts 0x38 on
/// (research_offsets loaded_file_records).
pub const BUCKET_SIZE: u64 = 0x38;
/// FileInfoValueStruct.Name.
pub const FILE_NAME: u64 = 0x08;
/// FileInfoValueStruct.AreaChangeCount.
pub const FILE_AREA_CHANGE_COUNT: u64 = 0x40;

/// One bucket entry. GameHelper2's FilesPointerStructure is three words
/// with the file in the middle; on the build of 2026-11-06 it is two, a
/// hash then the file (research_offsets loaded_file_records).
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
pub struct FilePointer {
    _hash: u64,
    pub file: u64,
}

pub fn area_change_counter(mem: &ProcessMemory, global: u64) -> Result<i32> {
    mem.read_value(global)
        .with_context(|| format!("read area change counter at {global:#x}"))
}

/// Every loaded file whose area change count passes `keep`. Names are
/// read only for those, as GameHelper2 does, since there are thousands
/// of files. A file that cannot be read is skipped; the second value
/// counts them.
pub fn loaded_files(
    mem: &ProcessMemory,
    root_global: u64,
    keep: impl Fn(i32) -> bool,
) -> Result<(Vec<LoadedFile>, usize)> {
    let root: u64 = mem
        .read_value(root_global)
        .with_context(|| format!("read file root pointer at {root_global:#x}"))?;
    let mut files = Vec::new();
    let mut unreadable = 0;
    for i in 0..ROOT_BUCKETS {
        let bucket = root + i * BUCKET_SIZE;
        let pointers: Vec<FilePointer> = read_bucket(mem, bucket)
            .with_context(|| format!("read file bucket {i} at {bucket:#x}"))?;
        for p in pointers {
            let Ok(count) = mem.read_value::<i32>(p.file + FILE_AREA_CHANGE_COUNT) else {
                unreadable += 1;
                continue;
            };
            if !keep(count) {
                continue;
            }
            match read_wstring(mem, p.file + FILE_NAME) {
                Ok(path) => files.push(LoadedFile {
                    path,
                    area_change_count: count,
                }),
                Err(_) => unreadable += 1,
            }
        }
    }
    Ok((files, unreadable))
}

#[cfg(test)]
mod tests {
    use super::*;
    use modforge::msvc_std::Vector;

    /// A file info as the game lays it out: a wstring at 0x08 and the
    /// count at 0x40.
    #[repr(C)]
    struct FileInfo {
        _vtable: u64,
        name_ptr: u64,
        _name_rest: u64,
        name_len: i64,
        name_cap: i64,
        _pad: [u64; 3],
        count: i32,
    }

    #[repr(C)]
    #[derive(Default)]
    struct Bucket {
        data: Vector,
        _unknown: u64,
        capacity: i32,
        _rest: [i32; 5],
    }

    fn info(name: &[u16], count: i32) -> FileInfo {
        FileInfo {
            _vtable: 0,
            name_ptr: name.as_ptr() as u64,
            _name_rest: 0,
            name_len: name.len() as i64,
            name_cap: 31,
            _pad: [0; 3],
            count,
        }
    }

    #[test]
    fn layout_matches_the_game() {
        assert_eq!(std::mem::offset_of!(FileInfo, name_ptr) as u64, FILE_NAME);
        assert_eq!(
            std::mem::offset_of!(FileInfo, count) as u64,
            FILE_AREA_CHANGE_COUNT
        );
        assert_eq!(size_of::<Bucket>() as u64, BUCKET_SIZE);
        assert_eq!(size_of::<FilePointer>(), 0x10);
    }

    #[test]
    fn reads_kept_files_from_every_bucket() {
        let mem = ProcessMemory::open(std::process::id()).expect("open own pid read-only");
        let a: Vec<u16> = "Metadata/Monsters/Boss.ao@1".encode_utf16().collect();
        let b: Vec<u16> = "Metadata/Chests/Strongbox.ao".encode_utf16().collect();
        let c: Vec<u16> = "Metadata/Old.ao".encode_utf16().collect();
        let infos = [info(&a, 9), info(&b, 9), info(&c, 4)];
        let ptr = |i: usize| FilePointer {
            _hash: 0,
            file: &infos[i] as *const FileInfo as u64,
        };
        let first = [ptr(0), ptr(2)];
        let last = [ptr(1)];
        let mut buckets: Vec<Bucket> = (0..ROOT_BUCKETS).map(|_| Bucket::default()).collect();
        for (bucket, items) in [(0usize, &first[..]), (15, &last[..])] {
            let start = items.as_ptr() as u64;
            let end = start + size_of_val(items) as u64;
            buckets[bucket].data = Vector {
                first: start,
                last: end,
                end,
            };
            buckets[bucket].capacity = 1;
        }
        let root = buckets.as_ptr() as u64;
        let global = &root as *const u64 as u64;

        let (files, unreadable) = loaded_files(&mem, global, |count| count == 9).unwrap();
        let paths: Vec<_> = files.iter().map(|f| f.path.as_str()).collect();
        assert_eq!(
            paths,
            [
                "Metadata/Monsters/Boss.ao@1",
                "Metadata/Chests/Strongbox.ao"
            ]
        );
        assert_eq!(unreadable, 0);

        let counter = 9i32;
        assert_eq!(
            area_change_counter(&mem, &counter as *const i32 as u64).unwrap(),
            9
        );
    }
}
