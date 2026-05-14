// Address: 0x140050920
// Ghidra name: FUN_140050920
// ============ 0x140050920 FUN_140050920 (size=182) ============


undefined8 FUN_140050920(longlong param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  ulonglong uVar3;

  

  if (*(char *)(param_1 + 0x5c) != '\0') {

    return 0;

  }

  *(undefined4 *)(param_1 + 0x98) = 0;

  if (*(longlong *)(param_1 + 0x40) == 0) {

    uVar2 = *(int *)(param_1 + 0x38) + param_2;

    if ((uVar2 < param_2) || (0x7fffffff < param_2)) {

      uVar2 = 0x7fffffff;

      *(undefined4 *)(param_1 + 0x98) = 1;

    }

    iVar1 = FUN_1402cea4c(*(undefined8 *)(param_1 + 0x30),uVar2,0);

    if (iVar1 != 0) {

      *(undefined4 *)(param_1 + 0x98) = 1;

      FUN_1402cea4c(*(undefined8 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x38),2);

      return 0;

    }

  }

  else {

    uVar3 = (ulonglong)param_2 + *(ulonglong *)(param_1 + 0x48);

    if ((*(ulonglong *)(param_1 + 0x50) <= uVar3) || (uVar3 < *(ulonglong *)(param_1 + 0x48))) {

      *(ulonglong *)(param_1 + 0x40) = *(ulonglong *)(param_1 + 0x50);

      *(undefined4 *)(param_1 + 0x98) = 1;

      return 0;

    }

    *(ulonglong *)(param_1 + 0x40) = uVar3;

  }

  return 1;

}




