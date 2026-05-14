// Address: 0x14027ce60
// Ghidra name: FUN_14027ce60
// ============ 0x14027ce60 FUN_14027ce60 (size=139) ============


int FUN_14027ce60(undefined1 *param_1,undefined1 *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  *(undefined4 *)(param_1 + 7) = 0;

  *(undefined4 *)(param_1 + 3) = 0;

  iVar1 = FUN_14027b8c0(param_2 + 3,param_3 + -3);

  iVar1 = iVar1 + 3;

  if ((char)param_1[1] < '\0') {

    iVar2 = FUN_14027b8c0(param_2 + iVar1,param_3 - iVar1,param_1 + 7);

    iVar1 = iVar2 + iVar1;

  }

  return iVar1;

}




