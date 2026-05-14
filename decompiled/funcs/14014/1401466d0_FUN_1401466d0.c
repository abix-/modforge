// Address: 0x1401466d0
// Ghidra name: FUN_1401466d0
// ============ 0x1401466d0 FUN_1401466d0 (size=119) ============


undefined1 FUN_1401466d0(longlong param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  char cVar2;

  undefined1 uVar3;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    if (param_2 != (undefined8 *)0x0) {

      *param_2 = 0;

      param_2[1] = 0;

    }

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return uVar3;

  }

  if (param_2 == (undefined8 *)0x0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030db68);

    return uVar3;

  }

  uVar1 = *(undefined8 *)(param_1 + 0x6c);

  *param_2 = *(undefined8 *)(param_1 + 100);

  param_2[1] = uVar1;

  return 1;

}




