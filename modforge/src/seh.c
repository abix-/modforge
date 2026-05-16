/*
 * SEH guard shim. MSVC only.
 *
 * Provides a single C function that runs a Rust thunk inside a
 * __try / __except block. Returns 0 on success, 1 on caught SEH
 * exception, and writes the exception code + fault address to
 * out_code / out_addr.
 *
 * The Rust side passes its closure as (thunk, ctx). On success the
 * thunk writes its result into ctx and we return 0. On any structured
 * exception (access violation, illegal instruction, ...) we catch,
 * record the code + address, and return 1.
 */
#include <windows.h>
#include <stdint.h>

typedef void (*modforge_seh_thunk)(void* ctx);

/* Filter: capture exception info into caller-supplied slots, then
 * tell the runtime to execute the handler block. */
static int modforge_seh_filter(
    EXCEPTION_POINTERS* ep,
    uint32_t* out_code,
    uintptr_t* out_addr
) {
    if (ep && ep->ExceptionRecord) {
        if (out_code) *out_code = (uint32_t)ep->ExceptionRecord->ExceptionCode;
        if (out_addr) *out_addr = (uintptr_t)ep->ExceptionRecord->ExceptionAddress;
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

int modforge_seh_guard(
    modforge_seh_thunk thunk,
    void* ctx,
    uint32_t* out_code,
    uintptr_t* out_addr
) {
    if (!thunk) return 1;
    __try {
        thunk(ctx);
        return 0;
    }
    __except (modforge_seh_filter(GetExceptionInformation(), out_code, out_addr)) {
        return 1;
    }
}
