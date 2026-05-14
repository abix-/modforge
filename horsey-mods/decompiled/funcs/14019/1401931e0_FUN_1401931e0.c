// Address: 0x1401931e0
// Ghidra name: FUN_1401931e0
// ============ 0x1401931e0 FUN_1401931e0 (size=97) ============


undefined8 * FUN_1401931e0(undefined8 *param_1)



{

  char cVar1;

  longlong lVar2;

  

  if (param_1 == (undefined8 *)0x0) {

LAB_14019322d:

    FUN_14012e850("Invalid device");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,8);

      if (cVar1 == '\0') goto LAB_14019322d;

    }

    lVar2 = (**(code **)(param_1[1] + 0x60))(*param_1);

    if (lVar2 != 0) {

      FUN_140192130(lVar2,param_1 + 2);

      return param_1 + 2;

    }

  }

  return (undefined8 *)0x0;

}




