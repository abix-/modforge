# `FUN_1402eeef8` @ 0x1402eeef8

**Size**: 53 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Game callers** (2): [`FUN_1402d74e0`](1402d74e0_FUN_1402d74e0.md), [`FUN_1402eeef8`](1402eeef8_FUN_1402eeef8.md)

**Game callees** (1): [`FUN_1402eeef8`](1402eeef8_FUN_1402eeef8.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1402eeef8(longlong param_1,longlong *param_2,longlong param_3)

{

  longlong lVar1;

  if ((*param_2 != (&DAT_1403ff150)[param_3]) && ((DAT_1403e8ff0 & *(uint *)(param_1 + 0x3a8)) == 0)

     ) {

    lVar1 = __acrt_update_thread_locale_data();

    *param_2 = lVar1;

  }

  return;

}
```