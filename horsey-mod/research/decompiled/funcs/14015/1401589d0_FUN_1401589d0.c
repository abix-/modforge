// Address: 0x1401589d0
// Ghidra name: FUN_1401589d0
// ============ 0x1401589d0 FUN_1401589d0 (size=150) ============


undefined4 FUN_1401589d0(longlong param_1,undefined4 *param_2)



{

  undefined4 uVar1;

  char cVar2;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0xffffffff;

  }

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_140158a3e;

    }

    uVar1 = *(undefined4 *)(param_1 + 0xe8);

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0xec);

    }

    FUN_14015bb10();

    return uVar1;

  }

LAB_140158a3e:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  FUN_14015bb10();

  return 0xffffffff;

}




