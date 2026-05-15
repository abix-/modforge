// Address: 0x14016dec0
// Ghidra name: FUN_14016dec0
// ============ 0x14016dec0 FUN_14016dec0 (size=153) ============


undefined8 FUN_14016dec0(longlong param_1,undefined4 *param_2,undefined4 *param_3)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016df3b;

    }

    if (param_2 != (undefined4 *)0x0) {

      *param_2 = *(undefined4 *)(param_1 + 0x38);

    }

    if (param_3 != (undefined4 *)0x0) {

      *param_3 = *(undefined4 *)(param_1 + 0x3c);

    }

    return 1;

  }

LAB_14016df3b:

  FUN_14012e850("Invalid window");

  return 0;

}




