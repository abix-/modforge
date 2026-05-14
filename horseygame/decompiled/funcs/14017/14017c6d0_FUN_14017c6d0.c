// Address: 0x14017c6d0
// Ghidra name: FUN_14017c6d0
// ============ 0x14017c6d0 FUN_14017c6d0 (size=192) ============


undefined8 FUN_14017c6d0(longlong param_1,undefined8 *param_2,undefined4 *param_3)



{

  longlong lVar1;

  undefined8 uVar2;

  

  if (param_2 != (undefined8 *)0x0) {

    *param_2 = 0;

  }

  if (param_3 != (undefined4 *)0x0) {

    *param_3 = 0xffffffff;

  }

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","process");

    return 0;

  }

  lVar1 = FUN_140174d30(*(undefined4 *)(param_1 + 8),"SDL.process.stdout",0);

  if (lVar1 == 0) {

    FUN_14012e850("Process not created with I/O enabled");

    return 0;

  }

  uVar2 = FUN_14012c500(lVar1,param_2,0);

  FUN_14017c790(param_1,1,param_3);

  return uVar2;

}




