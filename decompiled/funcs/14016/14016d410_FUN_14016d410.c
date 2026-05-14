// Address: 0x14016d410
// Ghidra name: FUN_14016d410
// ============ 0x14016d410 FUN_14016d410 (size=57) ============


undefined8 FUN_14016d410(undefined4 *param_1)



{

  undefined8 uVar1;

  

  if (param_1 == (undefined4 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030db68);

    return 0;

  }

  uVar1 = FUN_140169d40(*param_1,param_1[1],param_1[2],param_1[3]);

  return uVar1;

}




