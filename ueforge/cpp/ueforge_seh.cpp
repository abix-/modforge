// ueforge_seh.cpp
//
// Structured Exception Handling wrappers for risky cross-FFI calls
// into the game engine. Rust's `catch_unwind` only catches Rust
// panics; it does NOT catch Windows SEH access violations. A bad
// pointer chain inside a UE engine function (e.g. `AppendString`
// dereferencing a corrupt FName index) would otherwise terminate
// the host process.
//
// These helpers wrap a single engine call in MSVC `__try`/`__except`
// and translate any access violation / other recoverable SEH
// exception into a clean failure return. Rust callers see Option /
// Result instead of a dead process.
//
// SEH is independent of `/EHsc` -- the `__try`/`__except` construct
// works regardless of which C++ exception model is selected.

#include <cstddef>
#include <cstdint>

extern "C" {

// ---- Generic memory probes -----------------------------------------------

// Read 8 bytes at `addr` into `out`. Returns 1 on success, 0 on AV.
// Cheap leaf-level guard for "is this pointer chain valid".
int ueforge_seh_try_read_u64(const std::uint64_t* addr, std::uint64_t* out) {
    __try {
        *out = *addr;
        return 1;
    } __except (1 /* EXCEPTION_EXECUTE_HANDLER */) {
        return 0;
    }
}

int ueforge_seh_try_read_u32(const std::uint32_t* addr, std::uint32_t* out) {
    __try {
        *out = *addr;
        return 1;
    } __except (1) {
        return 0;
    }
}

int ueforge_seh_try_read_ptr(void* const* addr, void** out) {
    __try {
        *out = *addr;
        return 1;
    } __except (1) {
        return 0;
    }
}

// ---- AppendString wrapper -------------------------------------------------
//
// FName::ToString takes a pointer to an FName (8 bytes) and writes
// an FString into the out parameter. `fn` is the game's AppendString
// export address; the FName layout matches FName in Rust.
//
// Returns 1 on success, 0 if AppendString AV'd. On failure the out
// FString is left untouched (Rust caller initialized it to default).

using AppendStringFn = void (*)(const void* name, void* out_fstring);

int ueforge_seh_call_append_string(
    AppendStringFn fn,
    const void* name,
    void* out_fstring
) {
    __try {
        fn(name, out_fstring);
        return 1;
    } __except (1) {
        return 0;
    }
}

} // extern "C"
