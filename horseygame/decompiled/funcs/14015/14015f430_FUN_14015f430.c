// Address: 0x14015f430
// Ghidra name: FUN_14015f430
// ============ 0x14015f430 FUN_14015f430 (size=105) ============


void FUN_14015f430(longlong param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  uVar1 = *(uint *)(param_1 + 0x6c);

  uVar4 = (*(uint *)(param_1 + 0x60) >> 3 & 0x1f) * *(int *)(param_1 + 100);

  iVar2 = FUN_140138fe0(param_1 + 0x90,(ulonglong)uVar1 % (ulonglong)uVar4);

  if (iVar2 == 0) {

    iVar3 = (uVar1 / uVar4) * 1000;

    iVar2 = (iVar3 / *(int *)(param_1 + 0x68)) * 2;

    if (100 < iVar2) {

      iVar2 = 100;

    }

    FUN_1401492f0(iVar2,(longlong)iVar3 % (longlong)*(int *)(param_1 + 0x68) & 0xffffffff);

  }

                    /* WARNING: Could not recover jumptable at 0x00014015f492. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*DAT_1403fc0c8)(param_1);

  return;

}




