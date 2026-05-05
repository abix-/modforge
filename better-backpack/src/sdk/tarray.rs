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
        unsafe { slice::from_raw_parts(self.data, self.num as usize) }
    }
}
