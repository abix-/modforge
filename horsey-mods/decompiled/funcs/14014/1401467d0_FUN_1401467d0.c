// Address: 0x1401467d0
// Ghidra name: FUN_1401467d0
// ============ 0x1401467d0 FUN_1401467d0 (size=151) ============


undefined8

FUN_1401467d0(longlong param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    if (param_2 != (undefined1 *)0x0) {

      *param_2 = 0xff;

    }

    if (param_3 != (undefined1 *)0x0) {

      *param_3 = 0xff;

    }

    if (param_4 != (undefined1 *)0x0) {

      *param_4 = 0xff;

    }

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

  }

  else {

    if (param_2 != (undefined1 *)0x0) {

      *param_2 = *(undefined1 *)(param_1 + 0x110);

    }

    if (param_3 != (undefined1 *)0x0) {

      *param_3 = *(undefined1 *)(param_1 + 0x111);

    }

    if (param_4 != (undefined1 *)0x0) {

      *param_4 = *(undefined1 *)(param_1 + 0x112);

    }

    uVar2 = 1;

  }

  return uVar2;

}




