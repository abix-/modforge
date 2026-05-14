// Address: 0x1401860a0
// Ghidra name: FUN_1401860a0
// ============ 0x1401860a0 FUN_1401860a0 (size=100) ============


void FUN_1401860a0(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = FUN_140186200();

  if (-1 < iVar3) {

    iVar4 = *(int *)(param_1 + 0xc) + -1;

    *(int *)(param_1 + 0xc) = iVar4;

    if (iVar3 < iVar4) {

      lVar1 = *(longlong *)(param_1 + 0x18);

      uVar2 = *(undefined8 *)(lVar1 + (longlong)iVar3 * 8);

      FUN_1402f8e20(lVar1 + (longlong)iVar3 * 8,lVar1 + (longlong)(iVar3 + 1) * 8,

                    (longlong)(iVar4 - iVar3) << 3);

      *(undefined8 *)(*(longlong *)(param_1 + 0x18) + (longlong)*(int *)(param_1 + 0xc) * 8) = uVar2

      ;

    }

  }

  return;

}




