# `FUN_1401cbbf0` @ 0x1401cbbf0

**Size**: 116 bytes
**Domain**: `world_event` - world location / event / action
**Pattern**: `plays_sound_or_event` - Triggers a named sound/event
**Evidence**: trigger='DXGIGetDebugInterface'

**Strings referenced**:
- `'dxgidebug.dll'`
- `'DXGIGetDebugInterface'`

**Game callers** (2): [`FUN_1401c10d0`](1401c10d0_FUN_1401c10d0.md), [`FUN_1401cbbf0`](1401cbbf0_FUN_1401cbbf0.md)

**Game callees** (3): [`FUN_140188550`](140188550_FUN_140188550.md), [`FUN_1401885b0`](1401885b0_FUN_1401885b0.md), [`FUN_1401cbbf0`](1401cbbf0_FUN_1401cbbf0.md)

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
bool FUN_1401cbbf0(longlong param_1)

{

  int iVar1;

  longlong lVar2;

  code *pcVar3;

  lVar2 = FUN_1401885b0("dxgidebug.dll");

  *(longlong *)(param_1 + 0x30) = lVar2;

  if (lVar2 != 0) {

    pcVar3 = (code *)FUN_140188550(lVar2,"DXGIGetDebugInterface");

    if (pcVar3 != (code *)0x0) {

      iVar1 = (*pcVar3)(&DAT_140349298,param_1 + 8);

      if (-1 < iVar1) {

        iVar1 = (*pcVar3)(&DAT_1403492a8,param_1 + 0x18);

        return -1 < iVar1;

      }

    }

  }

  return false;

}
```