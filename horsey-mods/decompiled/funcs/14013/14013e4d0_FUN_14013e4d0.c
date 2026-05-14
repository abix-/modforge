// Address: 0x14013e4d0
// Ghidra name: FUN_14013e4d0
// ============ 0x14013e4d0 FUN_14013e4d0 (size=131) ============


undefined8 FUN_14013e4d0(char *param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = strcmp(param_1,"abxy");

  if (iVar1 == 0) {

    return 1;

  }

  iVar1 = strcmp(param_1,"axby");

  if (iVar1 == 0) {

    return 2;

  }

  iVar1 = strcmp(param_1,"bayx");

  if (iVar1 == 0) {

    return 3;

  }

  iVar1 = strcmp(param_1,"sony");

  uVar2 = 0;

  if (iVar1 == 0) {

    uVar2 = 4;

  }

  return uVar2;

}




