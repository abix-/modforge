# `FUN_1401aafa0` @ 0x1401aafa0

**Size**: 54 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 4 other funcs

**Game callers** (3): [`FUN_140174920`](140174920_FUN_140174920.md), [`FUN_1401aaee0`](1401aaee0_FUN_1401aaee0.md), [`FUN_1401aafa0`](1401aafa0_FUN_1401aafa0.md)

**Game callees** (4): [`FUN_14017ca90`](14017ca90_FUN_14017ca90.md), [`FUN_1401841e0`](1401841e0_FUN_1401841e0.md), [`FUN_1401aafa0`](1401aafa0_FUN_1401aafa0.md), [`FUN_1401ab4c0`](1401ab4c0_FUN_1401ab4c0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1401aafa0(longlong *param_1)

{

  if (param_1 != (longlong *)0x0) {

    FUN_1401ab4c0();

    if (*param_1 != 0) {

      FUN_14017ca90();

    }

    FUN_1401841e0(param_1[1]);

    FUN_1401841e0(param_1);

  }

  return;

}
```