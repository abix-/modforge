// Address: 0x1400509e0
// Ghidra name: FUN_1400509e0
// ============ 0x1400509e0 FUN_1400509e0 (size=67) ============


longlong FUN_1400509e0(longlong param_1,int param_2)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  int iVar4;

  

  uVar3 = param_2 + 7U & 0xfffffff8;

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar3;

  if (*(longlong *)(param_1 + 0x80) == 0) {

    if (uVar3 != 0) {

      lVar2 = _malloc_base((longlong)(int)uVar3);

      return lVar2;

    }

  }

  else {

    iVar1 = *(int *)(param_1 + 0x90);

    iVar4 = iVar1 + uVar3;

    if (iVar4 <= *(int *)(param_1 + 0x94)) {

      *(int *)(param_1 + 0x90) = iVar4;

      return (longlong)iVar1 + *(longlong *)(param_1 + 0x80);

    }

  }

  return 0;

}




