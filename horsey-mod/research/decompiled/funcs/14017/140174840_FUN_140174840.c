// Address: 0x140174840
// Ghidra name: FUN_140174840
// ============ 0x140174840 FUN_140174840 (size=221) ============


undefined1 FUN_140174840(int param_1,longlong param_2,undefined8 param_3)



{

  undefined1 uVar1;

  undefined8 *local_res20;

  longlong local_28;

  undefined8 local_20;

  int local_18;

  

  local_res20 = (undefined8 *)0x0;

  if (param_1 != 0) {

    if (param_2 == 0) {

      uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","callback");

      return uVar1;

    }

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res20);

    if (local_res20 != (undefined8 *)0x0) {

      FUN_140179b40(local_res20[1]);

      local_28 = param_2;

      local_20 = param_3;

      local_18 = param_1;

      FUN_1401ab210(*local_res20,FUN_140174590,&local_28);

      FUN_140179b60(local_res20[1]);

      return 1;

    }

  }

  uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","props");

  return uVar1;

}




