// Address: 0x140158d50
// Ghidra name: FUN_140158d50
// ============ 0x140158d50 FUN_140158d50 (size=157) ============


int FUN_140158d50(undefined4 *param_1)



{

  char cVar1;

  int iVar2;

  undefined4 *puVar3;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  puVar3 = (undefined4 *)FUN_1401585d0(&local_18,param_1);

  local_18 = *puVar3;

  uStack_14 = puVar3[1];

  uStack_10 = puVar3[2];

  uStack_c = puVar3[3];

  iVar2 = FUN_140158360(&local_18);

  if (iVar2 == 0) {

    FUN_140159d30();

    if (param_1 == (undefined4 *)0x0) {

LAB_140158dc8:

      FUN_14012e850("Parameter \'%s\' is invalid","joystick");

      FUN_14015bb10();

      return 0;

    }

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_140158dc8;

    }

    cVar1 = FUN_14013f5e0(*param_1);

    if (cVar1 != '\0') {

      iVar2 = 1;

    }

    FUN_14015bb10();

  }

  return iVar2;

}




