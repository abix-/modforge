// Address: 0x14014c720
// Ghidra name: FUN_14014c720
// ============ 0x14014c720 FUN_14014c720 (size=101) ============


undefined8 FUN_14014c720(longlong param_1)



{

  undefined4 uVar1;

  undefined8 uVar2;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  uVar1 = FUN_1401746e0();

  FUN_140175480(uVar1,"SDL.renderer.create.surface",param_1);

  uVar2 = FUN_14014bff0(uVar1);

  FUN_1401747e0(uVar1);

  return uVar2;

}




