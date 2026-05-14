# `FUN_1401cbac0` @ 0x1401cbac0

**Size**: 101 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 1 other funcs

**Game callers** (2): [`FUN_1401c10d0`](1401c10d0_FUN_1401c10d0.md), [`FUN_1401cbac0`](1401cbac0_FUN_1401cbac0.md)

**Game callees** (1): [`FUN_1401cbac0`](1401cbac0_FUN_1401cbac0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
void FUN_1401cbac0(longlong param_1)

{

  int iVar1;

  longlong *local_res8 [4];

  local_res8[0] = (longlong *)0x0;

  iVar1 = (**(code **)**(undefined8 **)(param_1 + 0x70))

                    (*(undefined8 **)(param_1 + 0x70),&DAT_140349398,local_res8);

  if (-1 < iVar1) {

    (**(code **)(*local_res8[0] + 0x130))(local_res8[0],FUN_1401ca4f0,0,0,0);

    (**(code **)(*local_res8[0] + 0x10))();

  }

  return;

}
```