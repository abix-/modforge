// Address: 0x14016dc00
// Ghidra name: FUN_14016dc00
// ============ 0x14016dc00 FUN_14016dc00 (size=161) ============


undefined8 FUN_14016dc00(longlong param_1,undefined8 *param_2,undefined4 *param_3)



{

  undefined8 uVar1;

  char cVar2;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,1);

      if (cVar2 == '\0') goto LAB_14016dc83;

    }

    if (param_2 != (undefined8 *)0x0) {

      uVar1 = *(undefined8 *)(param_1 + 0x144);

      *param_2 = *(undefined8 *)(param_1 + 0x13c);

      param_2[1] = uVar1;

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(param_1 + 0x14c);

    }

    return 1;

  }

LAB_14016dc83:

  FUN_14012e850("Invalid window");

  return 0;

}




