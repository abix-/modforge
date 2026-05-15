// Address: 0x1401745f0
// Ghidra name: FUN_1401745f0
// ============ 0x1401745f0 FUN_1401745f0 (size=240) ============


ulonglong FUN_1401745f0(int param_1,int param_2)



{

  ulonglong uVar1;

  longlong local_res18;

  undefined8 *local_res20;

  longlong local_18;

  byte local_10;

  

  if (param_1 == 0) {

LAB_1401745fc:

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return uVar1;

  }

  if (param_2 != 0) {

    local_res20 = (undefined8 *)0x0;

    local_res18 = 0;

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res20);

    if (local_res20 == (undefined8 *)0x0) goto LAB_1401745fc;

    FUN_1401aaff0(DAT_1403fc450,param_2,&local_res18);

    if (local_res18 != 0) {

      FUN_140179b40(local_res20[1]);

      FUN_140179b40(*(undefined8 *)(local_res18 + 8));

      local_18 = local_res18;

      local_10 = 1;

      FUN_1401ab210(*local_res20,FUN_1401744a0,&local_18);

      FUN_140179b60(*(undefined8 *)(local_res18 + 8));

      FUN_140179b60(local_res20[1]);

      return (ulonglong)local_10;

    }

  }

  uVar1 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331e9c);

  return uVar1;

}




