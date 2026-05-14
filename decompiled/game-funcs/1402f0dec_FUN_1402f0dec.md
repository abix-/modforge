# `FUN_1402f0dec` @ 0x1402f0dec

**Size**: 25 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Game callers** (2): [`FUN_1402da06c`](1402da06c_FUN_1402da06c.md), [`FUN_1402f0dec`](1402f0dec_FUN_1402f0dec.md)

**Game callees** (1): [`FUN_1402f0dec`](1402f0dec_FUN_1402f0dec.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
uint FUN_1402f0dec(void)

{

  return *(uint *)(*(longlong *)((longlong)Self + 0x60) + 0xbc) >> 8 & 0xffffff01;

}
```