// Address: 0x14013b140
// Ghidra name: FUN_14013b140
// ============ 0x14013b140 FUN_14013b140 (size=88) ============


bool FUN_14013b140(longlong param_1)



{

  undefined8 uVar1;

  char cVar2;

  int iVar3;

  

  if (*(longlong *)(param_1 + 8) == 0) {

    uVar1 = FUN_140149300();

    *(undefined8 *)(param_1 + 8) = uVar1;

  }

  cVar2 = FUN_140139220(param_1);

  if (cVar2 == '\0') {

    FUN_14012e710();

    return false;

  }

  iVar3 = FUN_14013afe0(param_1,1,0,0,0);

  return 0 < iVar3;

}




