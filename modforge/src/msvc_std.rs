//! Reading MSVC C++ standard containers out of another process, read
//! only, through [`ProcessMemory`]. Layouts and sanity limits copy
//! GameHelper2 (GameOffsets/Natives and Utils/SafeMemoryHandle.cs),
//! which reads Path of Exile 2 this way; they are the 64-bit MSVC
//! release layouts any MSVC-built game uses.
//!
//! Every reader takes the address of the container itself (where the
//! game keeps it inside its own object) and returns owned data or the
//! addresses of the elements, never pointers into our memory.

use crate::process_memory::ProcessMemory;
use anyhow::{Context, Result, bail, ensure};
use std::collections::HashSet;

/// GameHelper2 ReadStdVector: a vector bigger than this is torn or not
/// a vector.
pub const MAX_VECTOR_BYTES: u64 = 50_000_000;
/// GameHelper2 ReadStdString / ReadStdWString: longer is not text.
pub const MAX_STRING_LEN: i32 = 1000;
/// GameHelper2 ReadStdList: stop after this many nodes.
pub const MAX_LIST_NODES: usize = 100_000;

/// std::vector: First, Last, End pointers.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
#[repr(C)]
pub struct Vector {
    pub first: u64,
    pub last: u64,
    pub end: u64,
}

impl Vector {
    /// How many `elem_size` elements it holds, after GameHelper2's checks:
    /// none when empty, not a whole number of elements, or too big.
    pub fn len(&self, elem_size: u64) -> usize {
        let bytes = self.last.wrapping_sub(self.first);
        if self.last <= self.first
            || elem_size == 0
            || !bytes.is_multiple_of(elem_size)
            || bytes > MAX_VECTOR_BYTES
        {
            return 0;
        }
        (bytes / elem_size) as usize
    }

    /// Address of element `i`.
    pub fn at(&self, i: usize, elem_size: u64) -> u64 {
        self.first + i as u64 * elem_size
    }
}

pub fn read_vector_header(mem: &ProcessMemory, addr: u64) -> Result<Vector> {
    mem.read_value(addr)
        .with_context(|| format!("read vector at {addr:#x}"))
}

/// The elements of the std::vector at `addr`.
pub fn read_vector<T: Copy + Default>(mem: &ProcessMemory, addr: u64) -> Result<Vec<T>> {
    let v = read_vector_header(mem, addr)?;
    let n = v.len(size_of::<T>() as u64);
    if n == 0 {
        return Ok(Vec::new());
    }
    mem.read_array(v.first, n)
        .with_context(|| format!("read {n} vector elements at {:#x}", v.first))
}

/// The game's bucket (GameHelper2 StdBucket): a vector, a pointer, then
/// a capacity int at 0x20; empty when the vector has no storage or the
/// capacity is not positive.
pub fn read_bucket<T: Copy + Default>(mem: &ProcessMemory, addr: u64) -> Result<Vec<T>> {
    let v = read_vector_header(mem, addr)?;
    let capacity: i32 = mem
        .read_value(addr + 0x20)
        .with_context(|| format!("read bucket capacity at {:#x}", addr + 0x20))?;
    if v.first == 0 || capacity <= 0 {
        return Ok(Vec::new());
    }
    read_vector(mem, addr)
}

/// std::string and std::wstring: a 16-byte inline buffer or a pointer,
/// then Length and Capacity in characters.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct StringHeader {
    buffer: [u8; 16],
    length: i32,
    _pad_14: i32,
    capacity: i32,
    _pad_1c: i32,
}

/// The characters of a string header, inline or behind its pointer.
/// `inline_capacity` is how many characters fit in the 16 bytes less
/// the terminator (15 for string, 7 for wstring); GameHelper2's limits
/// apply (empty for length 0, an error past [`MAX_STRING_LEN`]).
fn string_bytes(
    mem: &ProcessMemory,
    addr: u64,
    char_size: usize,
    inline_capacity: i32,
) -> Result<Vec<u8>> {
    let h: StringHeader = mem
        .read_value(addr)
        .with_context(|| format!("read string at {addr:#x}"))?;
    if h.length == 0 {
        return Ok(Vec::new());
    }
    ensure!(
        h.length > 0
            && h.length <= MAX_STRING_LEN
            && h.capacity >= h.length
            && h.capacity <= MAX_STRING_LEN,
        "not a string at {addr:#x}: length {}, capacity {}",
        h.length,
        h.capacity
    );
    let bytes = h.length as usize * char_size;
    if h.capacity <= inline_capacity {
        return Ok(h.buffer[..bytes].to_vec());
    }
    let ptr = u64::from_le_bytes(h.buffer[..8].try_into().unwrap_or_default());
    mem.read_vec(ptr, bytes)
        .with_context(|| format!("read string text at {ptr:#x}"))
}

/// The std::wstring at `addr`, UTF-16 as the game keeps it.
pub fn read_wstring(mem: &ProcessMemory, addr: u64) -> Result<String> {
    let bytes = string_bytes(mem, addr, 2, 7)?;
    let units: Vec<u16> = bytes
        .as_chunks::<2>()
        .0
        .iter()
        .map(|c| u16::from_le_bytes(*c))
        .collect();
    Ok(String::from_utf16_lossy(&units))
}

/// The std::string at `addr`. GameHelper2 reads these as ASCII; bytes
/// that are not UTF-8 are replaced.
pub fn read_string(mem: &ProcessMemory, addr: u64) -> Result<String> {
    let bytes = string_bytes(mem, addr, 1, 15)?;
    Ok(String::from_utf8_lossy(&bytes).into_owned())
}

/// std::map and std::set: the head (nil) node and the size.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct MapHeader {
    head: u64,
    size: i32,
    _pad: i32,
}

/// A red-black tree node; the key and value start at 0x20.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct MapNode {
    left: u64,
    parent: u64,
    right: u64,
    color: u8,
    is_nil: u8,
    _pad: [u8; 6],
}

/// Where a map node's key and value start.
pub const MAP_NODE_DATA: u64 = 0x20;

/// The address of each entry's key and value in the std::map at `addr`
/// (each node plus [`MAP_NODE_DATA`]). Walks from the root, the head's
/// parent, like GameHelper2 ReadStdMap: a child that is nil or whose
/// color is not 0 or 1 is not followed, so a torn tree gives fewer
/// entries, not garbage. Empty when the size is 0 or over `max`.
pub fn map_entries(mem: &ProcessMemory, addr: u64, max: usize) -> Result<Vec<u64>> {
    let h: MapHeader = mem
        .read_value(addr)
        .with_context(|| format!("read map at {addr:#x}"))?;
    if h.size <= 0 || h.size as usize > max {
        return Ok(Vec::new());
    }
    let head: MapNode = mem
        .read_value(h.head)
        .with_context(|| format!("read map head at {:#x}", h.head))?;
    let mut out = Vec::with_capacity(h.size as usize);
    let mut seen = HashSet::new();
    let mut todo = vec![head.parent];
    while let Some(at) = todo.pop() {
        if at == 0 || at == h.head || !seen.insert(at) || out.len() >= max {
            continue;
        }
        let Ok(node) = mem.read_value::<MapNode>(at) else {
            continue;
        };
        if node.is_nil != 0 || node.color > 1 {
            continue;
        }
        out.push(at + MAP_NODE_DATA);
        todo.push(node.right);
        todo.push(node.left);
    }
    Ok(out)
}

/// std::list: the head (sentinel) node and the size.
#[derive(Clone, Copy, Debug, Default)]
#[repr(C)]
struct ListHeader {
    head: u64,
    size: i32,
    _pad: i32,
}

/// Where a list node's value starts, after Next and Prev.
pub const LIST_NODE_DATA: u64 = 0x10;

/// The address of each value in the std::list at `addr`, in list order
/// (each node plus [`LIST_NODE_DATA`]), following Next from the head
/// like GameHelper2 ReadStdList. A null Next is an error; a loop that
/// does not return to the head stops at [`MAX_LIST_NODES`].
pub fn list_entries(mem: &ProcessMemory, addr: u64) -> Result<Vec<u64>> {
    let h: ListHeader = mem
        .read_value(addr)
        .with_context(|| format!("read list at {addr:#x}"))?;
    let mut out = Vec::new();
    let mut at: u64 = mem
        .read_value(h.head)
        .with_context(|| format!("read list head at {:#x}", h.head))?;
    while at != h.head {
        if at == 0 {
            bail!("list at {addr:#x} breaks after {} nodes", out.len());
        }
        if out.len() >= MAX_LIST_NODES {
            break;
        }
        out.push(at + LIST_NODE_DATA);
        at = mem
            .read_value(at)
            .with_context(|| format!("read list node at {at:#x}"))?;
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn own() -> ProcessMemory {
        ProcessMemory::open(std::process::id()).expect("open own pid read-only")
    }

    fn addr<T>(x: &T) -> u64 {
        x as *const T as u64
    }

    fn vector_of<T>(items: &[T]) -> Vector {
        let first = items.as_ptr() as u64;
        let last = first + size_of_val(items) as u64;
        Vector {
            first,
            last,
            end: last,
        }
    }

    #[test]
    fn vector_reads_elements_and_rejects_torn() {
        let mem = own();
        let items = [7u32, 8, 9];
        let v = vector_of(&items);
        assert_eq!(read_vector::<u32>(&mem, addr(&v)).unwrap(), items);
        let empty = Vector::default();
        assert!(read_vector::<u32>(&mem, addr(&empty)).unwrap().is_empty());
        let odd = Vector {
            last: v.last - 1,
            ..v
        };
        assert!(read_vector::<u32>(&mem, addr(&odd)).unwrap().is_empty());
        let backwards = Vector {
            first: v.last,
            last: v.first,
            end: v.first,
        };
        assert!(
            read_vector::<u32>(&mem, addr(&backwards))
                .unwrap()
                .is_empty()
        );
    }

    #[test]
    fn bucket_needs_storage_and_capacity() {
        #[repr(C)]
        struct Bucket {
            data: Vector,
            unknown: u64,
            capacity: i32,
            _rest: [i32; 7],
        }
        let mem = own();
        let items = [1u64, 2];
        let mut b = Bucket {
            data: vector_of(&items),
            unknown: 0,
            capacity: 1,
            _rest: [0; 7],
        };
        assert_eq!(read_bucket::<u64>(&mem, addr(&b)).unwrap(), items);
        b.capacity = 0;
        assert!(read_bucket::<u64>(&mem, addr(&b)).unwrap().is_empty());
    }

    fn header(buffer: [u8; 16], length: i32, capacity: i32) -> StringHeader {
        StringHeader {
            buffer,
            length,
            _pad_14: 0,
            capacity,
            _pad_1c: 0,
        }
    }

    fn pointer_buffer(ptr: u64) -> [u8; 16] {
        let mut b = [0u8; 16];
        b[..8].copy_from_slice(&ptr.to_le_bytes());
        b
    }

    #[test]
    fn wstring_inline_and_on_heap() {
        let mem = own();
        let mut inline = [0u8; 16];
        for (i, u) in "Life".encode_utf16().enumerate() {
            inline[i * 2..i * 2 + 2].copy_from_slice(&u.to_le_bytes());
        }
        assert_eq!(
            read_wstring(&mem, addr(&header(inline, 4, 7))).unwrap(),
            "Life"
        );

        let long: Vec<u16> = "Metadata/Monsters/Exile".encode_utf16().collect();
        let h = header(pointer_buffer(long.as_ptr() as u64), long.len() as i32, 31);
        assert_eq!(
            read_wstring(&mem, addr(&h)).unwrap(),
            "Metadata/Monsters/Exile"
        );

        assert_eq!(
            read_wstring(&mem, addr(&header([0; 16], 0, 7))).unwrap(),
            ""
        );
        assert!(read_wstring(&mem, addr(&header([0; 16], 5000, 5000))).is_err());
        assert!(read_wstring(&mem, addr(&header([0; 16], 9, 3))).is_err());
    }

    #[test]
    fn string_inline_and_on_heap() {
        let mem = own();
        let mut inline = [0u8; 16];
        inline[..5].copy_from_slice(b"Act 1");
        assert_eq!(
            read_string(&mem, addr(&header(inline, 5, 15))).unwrap(),
            "Act 1"
        );
        let long = b"The Grelwood, a long zone name";
        let h = header(pointer_buffer(long.as_ptr() as u64), long.len() as i32, 31);
        assert_eq!(
            read_string(&mem, addr(&h)).unwrap(),
            "The Grelwood, a long zone name"
        );
    }

    #[repr(C)]
    #[derive(Clone, Copy, Default)]
    struct TestMapNode {
        node: MapNode,
        key: u32,
        value: u32,
    }

    #[test]
    fn map_walks_every_node_and_stops_at_bad_ones() {
        let mem = own();
        // nodes[0] is the head; 1 is the root with children 2 and 3.
        let mut nodes = Box::new([TestMapNode::default(); 5]);
        let at = |i: usize, nodes: &[TestMapNode; 5]| addr(&nodes[i]);
        let head = at(0, &nodes);
        let (n1, n2, n3, n4) = (at(1, &nodes), at(2, &nodes), at(3, &nodes), at(4, &nodes));
        nodes[0].node = MapNode {
            left: n2,
            parent: n1,
            right: n3,
            color: 1,
            is_nil: 1,
            _pad: [0; 6],
        };
        nodes[1].node = MapNode {
            left: n2,
            parent: head,
            right: n3,
            color: 1,
            is_nil: 0,
            _pad: [0; 6],
        };
        nodes[2].node = MapNode {
            left: head,
            parent: n1,
            right: head,
            color: 0,
            is_nil: 0,
            _pad: [0; 6],
        };
        nodes[3].node = MapNode {
            left: n4,
            parent: n1,
            right: head,
            color: 0,
            is_nil: 0,
            _pad: [0; 6],
        };
        // A torn child: color 7 is no red-black color.
        nodes[4].node = MapNode {
            left: head,
            parent: n3,
            right: head,
            color: 7,
            is_nil: 0,
            _pad: [0; 6],
        };
        for (i, n) in nodes.iter_mut().enumerate() {
            n.key = i as u32;
            n.value = i as u32 * 10;
        }
        let map = MapHeader {
            head,
            size: 4,
            _pad: 0,
        };
        let mut keys: Vec<(u32, u32)> = map_entries(&mem, addr(&map), 100)
            .unwrap()
            .into_iter()
            .map(|a| mem.read_value::<[u32; 2]>(a).unwrap().into())
            .collect();
        keys.sort();
        assert_eq!(keys, [(1, 10), (2, 20), (3, 30)]);
        let too_big = MapHeader {
            head,
            size: 4,
            _pad: 0,
        };
        assert!(map_entries(&mem, addr(&too_big), 2).unwrap().is_empty());
    }

    #[repr(C)]
    #[derive(Clone, Copy, Default)]
    struct TestListNode {
        next: u64,
        prev: u64,
        value: u64,
    }

    #[test]
    fn list_follows_next_back_to_head() {
        let mem = own();
        let mut nodes = Box::new([TestListNode::default(); 3]);
        let a: Vec<u64> = nodes.iter().map(addr).collect();
        nodes[0].next = a[1];
        nodes[1].next = a[2];
        nodes[2].next = a[0];
        nodes[1].value = 11;
        nodes[2].value = 22;
        let list = ListHeader {
            head: a[0],
            size: 2,
            _pad: 0,
        };
        let values: Vec<u64> = list_entries(&mem, addr(&list))
            .unwrap()
            .into_iter()
            .map(|v| mem.read_value(v).unwrap())
            .collect();
        assert_eq!(values, [11, 22]);
        nodes[2].next = 0;
        assert!(list_entries(&mem, addr(&list)).is_err());
    }
}
