// Address: 0x1400461e0
// Ghidra name: FUN_1400461e0
// ============ 0x1400461e0 FUN_1400461e0 (size=161) ============


void FUN_1400461e0(undefined8 param_1,undefined1 param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  int local_res18 [4];

  undefined1 local_38 [32];

  

  local_res18[0] = 0;

  uVar1 = FUN_140047420(&DAT_1403ea2b0,param_1);

  uVar1 = FUN_1400279c0(local_38,uVar1);

  lVar2 = FUN_1400c4a10(uVar1,local_res18);

  if (lVar2 == 0) {

    DAT_1403ea294 = 0;

  }

  else {

    DAT_1403ea288 = FUN_1400449e0(lVar2,(longlong)local_res18[0],0);

    FUN_1400c4de0(lVar2);

    if (DAT_1403ea288 != 0) {

      DAT_1403ea294 = 2;

      DAT_1403ea291 = param_2;

    }

  }

  FUN_140027900(param_1);

  return;

}




