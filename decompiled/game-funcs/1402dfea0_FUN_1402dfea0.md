# `FUN_1402dfea0` @ 0x1402dfea0

**Size**: 83 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Game callers** (2): [`FUN_1402dfea0`](1402dfea0_FUN_1402dfea0.md), [`FUN_1402e0598`](1402e0598_FUN_1402e0598.md)

**Game callees** (2): [`FUN_1402d8964`](1402d8964_FUN_1402d8964.md), [`FUN_1402dfea0`](1402dfea0_FUN_1402dfea0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
ulonglong FUN_1402dfea0(longlong param_1,undefined8 param_2)

{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  do {

    pbVar2 = *(byte **)(param_1 + 0x10);

    if (pbVar2 == *(byte **)(param_1 + 8)) {

      return 0xffffffff;

    }

    bVar1 = *pbVar2;

    *(byte **)(param_1 + 0x10) = pbVar2 + 1;

    iVar3 = FUN_1402d8964((ulonglong)bVar1,8,param_2);

  } while (iVar3 != 0);

  return (ulonglong)bVar1;

}
```