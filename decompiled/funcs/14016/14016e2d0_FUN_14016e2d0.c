// Address: 0x14016e2d0
// Ghidra name: FUN_14016e2d0
// ============ 0x14016e2d0 FUN_14016e2d0 (size=88) ============


undefined4 FUN_14016e2d0(undefined4 *param_1)



{

  char cVar1;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (param_1 != (undefined4 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,1);

      if (cVar1 == '\0') goto LAB_14016e314;

    }

    return *param_1;

  }

LAB_14016e314:

  FUN_14012e850("Invalid window");

  return 0;

}




