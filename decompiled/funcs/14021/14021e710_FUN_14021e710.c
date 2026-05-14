// Address: 0x14021e710
// Ghidra name: FUN_14021e710
// ============ 0x14021e710 FUN_14021e710 (size=134) ============


undefined8 FUN_14021e710(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  undefined4 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_14012c1b0(param_2,param_3,1);

  if (lVar2 == 0) {

    return 0;

  }

  uVar1 = FUN_14012be20(lVar2);

  FUN_1401753d0(uVar1,"SDL.internal.process",param_1,&LAB_14021dac0,param_4);

  FUN_140175480(*(undefined4 *)(param_1 + 8),param_4,lVar2);

  return 1;

}




