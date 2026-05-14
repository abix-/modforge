# `FUN_1402eaf4c` @ 0x1402eaf4c

**Size**: 175 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `helper` - General helper (calls other funcs, no idiom matched)
**Evidence**: calls 3 other funcs

**Game callers** (3): [`FUN_1402eada0`](1402eada0_FUN_1402eada0.md), [`FUN_1402eaf4c`](1402eaf4c_FUN_1402eaf4c.md), [`FUN_1402eb16c`](1402eb16c_FUN_1402eb16c.md)

**Game callees** (3): [`FUN_1402e6868`](1402e6868_FUN_1402e6868.md), [`FUN_1402eaf4c`](1402eaf4c_FUN_1402eaf4c.md), [`FUN_1402f4f90`](1402f4f90_FUN_1402f4f90.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
longlong FUN_1402eaf4c(uint param_1,LARGE_INTEGER param_2,DWORD param_3,longlong param_4)

{

  byte *pbVar1;

  BOOL BVar2;

  DWORD DVar3;

  HANDLE hFile;

  LARGE_INTEGER local_18 [2];

  hFile = (HANDLE)FUN_1402f4f90(param_1);

  if (hFile == (HANDLE)0xffffffffffffffff) {

    *(undefined1 *)(param_4 + 0x30) = 1;

    *(undefined4 *)(param_4 + 0x2c) = 9;

  }

  else {

    local_18[0].QuadPart = 0;

    BVar2 = SetFilePointerEx(hFile,param_2,local_18,param_3);

    if (BVar2 == 0) {

      DVar3 = GetLastError();

      FUN_1402e6868(DVar3,param_4);

    }

    else if (local_18[0].QuadPart != -1) {

      pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + 0x38 +

                       (ulonglong)(param_1 & 0x3f) * 0x48);

      *pbVar1 = *pbVar1 & 0xfd;

      return (longlong)local_18[0].s;

    }

  }

  return -1;

}
```