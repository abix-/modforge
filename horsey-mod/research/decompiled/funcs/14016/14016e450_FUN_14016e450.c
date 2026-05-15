// Address: 0x14016e450
// Ghidra name: FUN_14016e450
// ============ 0x14016e450 FUN_14016e450 (size=153) ============


undefined8 FUN_14016e450(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e4cb;

    }

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0x28);

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(param_1 + 0x2c);

    }

    return 1;

  }

LAB_14016e4cb:

  FUN_14012e850("Invalid window");

  return 0;

}




