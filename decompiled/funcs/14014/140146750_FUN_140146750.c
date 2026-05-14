// Address: 0x140146750
// Ghidra name: FUN_140146750
// ============ 0x140146750 FUN_140146750 (size=125) ============


undefined8 FUN_140146750(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar2;

  }

  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {

    uVar2 = FUN_14012e850("Surface doesn\'t have a colorkey");

    return uVar2;

  }

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = *(undefined4 *)(param_1 + 0x10c);

  }

  return 1;

}




