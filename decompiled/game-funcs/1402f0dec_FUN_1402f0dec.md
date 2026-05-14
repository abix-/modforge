# `FUN_1402f0dec` @ 0x1402f0dec

**Size**: 25 bytes
**Role**: stub/thunk/getter (unknown specific role)

**Game callers** (2): `FUN_1402da06c`, `FUN_1402f0dec`

**Game callees** (1): `FUN_1402f0dec`

**Vendor callees** (0) - SDL/CRT/etc.

## Decompiled

```c
uint FUN_1402f0dec(void)

{

  return *(uint *)(*(longlong *)((longlong)Self + 0x60) + 0xbc) >> 8 & 0xffffff01;

}
```