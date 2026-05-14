// Address: 0x1401465d0
// Ghidra name: FUN_1401465d0
// ============ 0x1401465d0 FUN_1401465d0 (size=256) ============


undefined8 FUN_1401465d0(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  uint uVar2;

  undefined8 uVar3;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0x7fffffff;

  }

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar3;

  }

  if (param_2 == (undefined4 *)0x0) {

    return 1;

  }

  uVar2 = *(uint *)(param_1 + 0x108) & 0x3f0;

  if (uVar2 < 0x81) {

    if (uVar2 == 0x80) {

      *param_2 = 0x20;

      return 1;

    }

    if (uVar2 == 0x10) {

      *param_2 = 1;

      return 1;

    }

    if (uVar2 == 0x20) {

      *param_2 = 0x10;

      return 1;

    }

    if (uVar2 == 0x40) {

      *param_2 = 2;

      return 1;

    }

  }

  else {

    if (uVar2 == 0x100) {

      *param_2 = 4;

      return 1;

    }

    if (uVar2 == 0x200) {

      *param_2 = 8;

      return 0x201;

    }

  }

  *param_2 = 0;

  return 1;

}




