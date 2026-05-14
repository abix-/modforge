# `FUN_1401aaea0` @ 0x1401aaea0

**Size**: 59 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 1 other funcs

**Game callers** (2): [`FUN_1401aaea0`](1401aaea0_FUN_1401aaea0.md), [`FUN_1401aaee0`](1401aaee0_FUN_1401aaee0.md)

**Game callees** (1): [`FUN_1401aaea0`](1401aaea0_FUN_1401aaea0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
uint FUN_1401aaea0(uint param_1)

{

  int iVar1;

  uint uVar2;

  byte bVar3;

  uint uVar4;

  if ((int)param_1 < 1) {

    return 4;

  }

  iVar1 = 0x1f;

  if (param_1 != 0) {

    for (; param_1 >> iVar1 == 0; iVar1 = iVar1 + -1) {

    }

  }

  bVar3 = 0xff;

  if (param_1 != 0) {

    bVar3 = (byte)iVar1;

  }

  uVar4 = 1 << (bVar3 & 0x1f);

  if ((param_1 & param_1 - 1) != 0) {

    uVar4 = 2 << (bVar3 & 0x1f);

  }

  uVar2 = 0x4000000;

  if (uVar4 < 0x4000000) {

    uVar2 = uVar4;

  }

  return uVar2;

}
```