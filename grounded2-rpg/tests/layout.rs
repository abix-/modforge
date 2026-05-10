// Layout assertions cross-checked against Dumper-7 SDK headers
// (`C:\Tools\work\sdk\SDK\Basic.hpp` and `CoreUObject_classes.hpp`).
// These run on host, not in-game, so they verify only sizes/offsets of our
// own #[repr(C)] mirrors -- not the live game layout. The live layout is
// validated implicitly the first time we read fields successfully.

use main::sdk::{FName, FString, TArray};
use std::mem::size_of;

#[test]
fn fname_is_8_bytes() {
    assert_eq!(size_of::<FName>(), 8);
}

#[test]
fn fstring_is_16_bytes() {
    assert_eq!(size_of::<FString>(), 16);
}

#[test]
fn tarray_ptr_is_16_bytes() {
    assert_eq!(size_of::<TArray<*mut u8>>(), 16);
}
