// Address: 0x140135d10
// Ghidra name: FUN_140135d10
// ============ 0x140135d10 FUN_140135d10 (size=134) ============


undefined8 FUN_140135d10(longlong param_1,undefined4 *param_2)



{

  undefined8 uVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

    return 0;

  }

  if (param_2 == (undefined4 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","createinfo");

    return 0;

  }

  uVar1 = FUN_140174e70(param_2[2],"SDL.gpu.transferbuffer.create.name",0);

                    /* WARNING: Could not recover jumptable at 0x000140135d93. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar1 = (**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x298),*param_2,param_2[1],uVar1);

  return uVar1;

}




