# `FUN_1402ebf8c` @ 0x1402ebf8c

**Size**: 21 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `wrapper` - Tiny wrapper that delegates to one other function
**Evidence**: single delegated call to FUN_1402ebf8c

**Game callers** (2): [`FUN_1402cf520`](1402cf520_FUN_1402cf520.md), [`FUN_1402ebf8c`](1402ebf8c_FUN_1402ebf8c.md)

**Game callees** (1): [`FUN_1402ebf8c`](1402ebf8c_FUN_1402ebf8c.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1402ebf8c(void)

{

  (*(code *)PTR__guard_check_icall_140302c58)();

  return;

}
```