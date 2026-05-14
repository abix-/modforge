// Address: 0x140050a30
// Ghidra name: FUN_140050a30
// ============ 0x140050a30 FUN_140050a30 (size=57) ============


longlong FUN_140050a30(longlong param_1,int param_2)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  

  uVar3 = param_2 + 7U & 0xfffffff8;

  if (*(longlong *)(param_1 + 0x80) == 0) {

    lVar2 = _malloc_base((longlong)(int)uVar3);

    return lVar2;

  }

  iVar1 = *(int *)(param_1 + 0x94) - uVar3;

  if (iVar1 < *(int *)(param_1 + 0x90)) {

    return 0;

  }

  *(int *)(param_1 + 0x94) = iVar1;

  return (longlong)iVar1 + *(longlong *)(param_1 + 0x80);

}




