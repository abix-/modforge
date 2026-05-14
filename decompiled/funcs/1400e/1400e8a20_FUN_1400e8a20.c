// Address: 0x1400e8a20
// Ghidra name: FUN_1400e8a20
// ============ 0x1400e8a20 FUN_1400e8a20 (size=170) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400e8a20(longlong param_1,int param_2)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  

  if (*(int *)(param_1 + 0x30) == 0) {

    _DAT_1403f4c40 = "output buffer limit";

    return 0;

  }

  iVar3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x20);

  for (iVar1 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20); iVar1 < iVar3 + param_2;

      iVar1 = iVar1 * 2) {

  }

  lVar2 = _realloc_base(*(undefined8 *)(param_1 + 0x20),(longlong)iVar1);

  if (lVar2 != 0) {

    *(longlong *)(param_1 + 0x18) = iVar3 + lVar2;

    *(longlong *)(param_1 + 0x28) = iVar1 + lVar2;

    *(longlong *)(param_1 + 0x20) = lVar2;

    return 1;

  }

  _DAT_1403f4c40 = "outofmem";

  return 0;

}




