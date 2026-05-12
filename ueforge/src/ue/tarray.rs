// TArray<T> = { data: *mut T, num: i32, max: i32 }. 16 bytes.
// Read-only borrowed view. We never construct or grow these from Rust.

use std::slice;

#[repr(C)]
#[derive(Debug)]
pub struct TArray<T> {
    pub data: *mut T,
    pub num: i32,
    pub max: i32,
}

impl<T> Default for TArray<T> {
    fn default() -> Self {
        Self {
            data: std::ptr::null_mut(),
            num: 0,
            max: 0,
        }
    }
}

impl<T> TArray<T> {
    pub fn len(&self) -> i32 {
        self.num
    }

    pub fn is_empty(&self) -> bool {
        self.num <= 0 || self.data.is_null()
    }

    pub unsafe fn as_slice(&self) -> &[T] {
        if self.is_empty() {
            return &[];
        }
        // SAFETY: caller's `unsafe fn` contract: `data` must
        // point at `num` valid `T`s (we don't construct or grow
        // these from Rust; the producer is the engine).
        unsafe { slice::from_raw_parts(self.data, self.num as usize) }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty_default() {
        let a: TArray<i32> = TArray::default();
        assert_eq!(a.len(), 0);
        assert!(a.is_empty());
        // SAFETY: is_empty short-circuits before the slice
        // construction; null data is the documented "no slice"
        // signal.
        let s = unsafe { a.as_slice() };
        assert!(s.is_empty());
    }

    #[test]
    fn negative_num_is_empty() {
        let a: TArray<u8> = TArray {
            data: 1 as *mut u8,
            num: -5,
            max: 0,
        };
        // Negative num: garbage state from engine. Walker MUST
        // NOT slice -5 elements out of any pointer.
        assert!(a.is_empty());
        // SAFETY: see above. is_empty short-circuits.
        let s = unsafe { a.as_slice() };
        assert!(s.is_empty());
    }

    #[test]
    fn null_data_is_empty() {
        let a: TArray<u32> = TArray {
            data: std::ptr::null_mut(),
            num: 7, // non-zero but data is null
            max: 7,
        };
        assert!(a.is_empty());
    }

    #[test]
    fn slice_round_trip() {
        let mut buf: [u32; 4] = [11, 22, 33, 44];
        let a: TArray<u32> = TArray {
            data: buf.as_mut_ptr(),
            num: buf.len() as i32,
            max: buf.len() as i32,
        };
        assert_eq!(a.len(), 4);
        assert!(!a.is_empty());
        // SAFETY: buf lives for the test scope and a borrows
        // its address; slice construction is safe within the
        // same scope.
        let s = unsafe { a.as_slice() };
        assert_eq!(s, &[11, 22, 33, 44]);
    }

    #[test]
    fn repr_c_layout_matches_engine() {
        // The TArray<T> = { data, num, max } layout is 16 bytes
        // on x86-64 with #[repr(C)]; the engine's TArray ABI
        // matches. If a future Rust ABI change shifts this we'd
        // silently mis-decode every data table row.
        assert_eq!(std::mem::size_of::<TArray<u8>>(), 16);
        assert_eq!(std::mem::size_of::<TArray<u64>>(), 16);
        assert_eq!(std::mem::size_of::<TArray<*const u8>>(), 16);
    }
}
