// Address: 0x140192f70
// Ghidra name: FUN_140192f70
// ============ 0x140192f70 FUN_140192f70 (size=97) ============


undefined8 FUN_140192f70(undefined8 *param_1)



{

  char cVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,8);

      if (cVar1 == '\0') goto LAB_140192fba;

    }

    (**(code **)(param_1[1] + 0x38))(*param_1);

    FUN_1401747e0(*(undefined4 *)(param_1 + 0xc));

    FUN_140192260(param_1);

    return 0;

  }

LAB_140192fba:

  FUN_14012e850("Invalid device");

  return 0xffffffff;

}




