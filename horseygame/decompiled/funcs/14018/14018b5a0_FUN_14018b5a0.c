// Address: 0x14018b5a0
// Ghidra name: FUN_14018b5a0
// ============ 0x14018b5a0 FUN_14018b5a0 (size=101) ============


void FUN_14018b5a0(undefined4 param_1,longlong *param_2,int *param_3)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  iVar2 = *param_3;

  lVar1 = (longlong)iVar2 * 4;

  lVar3 = FUN_140184230(*param_2,lVar1 + 4);

  if (lVar3 != 0) {

    *(undefined4 *)(lVar1 + lVar3) = param_1;

    *param_3 = iVar2 + 1;

    *param_2 = lVar3;

  }

  return;

}




