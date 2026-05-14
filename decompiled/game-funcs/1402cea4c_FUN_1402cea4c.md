# `FUN_1402cea4c` @ 0x1402cea4c

**Size**: 155 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 3 other funcs

**Game callers** (5): [`FUN_140026080`](140026080_FUN_140026080.md), [`FUN_140050a70`](140050a70_FUN_140050a70.md), [`FUN_140050ad0`](140050ad0_FUN_140050ad0.md), [`FUN_1400753f0`](1400753f0_FUN_1400753f0.md), [`FUN_1402cea4c`](1402cea4c_FUN_1402cea4c.md)

**Game callees** (3): [`FUN_1402cd068`](1402cd068_FUN_1402cd068.md), [`FUN_1402ce7c8`](1402ce7c8_FUN_1402ce7c8.md), [`FUN_1402cea4c`](1402cea4c_FUN_1402cea4c.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
undefined4 FUN_1402cea4c(undefined4 param_1,int param_2,undefined8 param_3)

{

  undefined4 uVar1;

  longlong lVar2;

  longlong local_48 [2];

  undefined1 local_38;

  undefined4 local_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined4 uStack_24;

  char local_20;

  undefined4 local_1c;

  char local_18;

  undefined4 local_14;

  char local_10;

  local_48[0] = 0;

  local_20 = DAT_1403ff13c == 0;

  local_38 = 0;

  local_18 = '\0';

  local_10 = '\0';

  if ((bool)local_20) {

    local_30 = PTR_PTR_1403e8e88._0_4_;

    uStack_2c = PTR_PTR_1403e8e88._4_4_;

    uStack_28 = PTR_DAT_1403e8e90._0_4_;

    uStack_24 = PTR_DAT_1403e8e90._4_4_;

    param_1 = PTR_PTR_1403e8e88._0_4_;

  }

  uVar1 = FUN_1402ce7c8(param_1,(longlong)param_2,param_3,local_48);

  if (local_20 == '\x02') {

    *(uint *)(local_48[0] + 0x3a8) = *(uint *)(local_48[0] + 0x3a8) & 0xfffffffd;

  }

  if (local_18 != '\0') {

    lVar2 = FUN_1402cd068(local_48);

    *(undefined4 *)(lVar2 + 0x20) = local_1c;

  }

  if (local_10 != '\0') {

    lVar2 = FUN_1402cd068(local_48);

    *(undefined4 *)(lVar2 + 0x24) = local_14;

  }

  return uVar1;

}
```