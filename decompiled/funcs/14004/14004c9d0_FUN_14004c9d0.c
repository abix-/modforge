// Address: 0x14004c9d0
// Ghidra name: FUN_14004c9d0
// ============ 0x14004c9d0 FUN_14004c9d0 (size=137) ============


int FUN_14004c9d0(longlong param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = FUN_14004cab0();

  *(undefined4 *)(param_1 + 0x6f8) = 0;

  iVar2 = FUN_14004cab0(param_1);

  *(undefined4 *)(param_1 + 0x6f8) = 0;

  iVar3 = FUN_14004cab0(param_1);

  *(undefined4 *)(param_1 + 0x6f8) = 0;

  iVar4 = FUN_14004cab0(param_1);

  *(undefined4 *)(param_1 + 0x6f8) = 0;

  return ((iVar4 * 0x100 + iVar3) * 0x100 + iVar2) * 0x100 + iVar1;

}




