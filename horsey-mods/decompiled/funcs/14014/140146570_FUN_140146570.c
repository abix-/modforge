// Address: 0x140146570
// Ghidra name: FUN_140146570
// ============ 0x140146570 FUN_140146570 (size=89) ============


undefined8 FUN_140146570(longlong param_1,undefined1 *param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    if (param_2 != (undefined1 *)0x0) {

      *param_2 = 0xff;

    }

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar2;

  }

  if (param_2 != (undefined1 *)0x0) {

    *param_2 = *(undefined1 *)(param_1 + 0x113);

  }

  return 1;

}




