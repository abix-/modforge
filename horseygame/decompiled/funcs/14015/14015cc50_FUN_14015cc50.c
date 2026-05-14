// Address: 0x14015cc50
// Ghidra name: FUN_14015cc50
// ============ 0x14015cc50 FUN_14015cc50 (size=175) ============


longlong FUN_14015cc50(undefined4 param_1)



{

  char cVar1;

  longlong lVar2;

  longlong local_res10 [3];

  

  local_res10[0] = 0;

  cVar1 = FUN_14015ec00();

  if (cVar1 != '\0') {

    FUN_14015cb20(param_1,local_res10);

    return local_res10[0];

  }

  lVar2 = FUN_14015e610();

  if (lVar2 == 0) {

    FUN_14012e850("Audio subsystem is not initialized");

    return local_res10[0];

  }

  FUN_14017caa0(DAT_1403fc128);

  FUN_1401aaff0(DAT_1403fc130,param_1,local_res10);

  FUN_14017cae0(DAT_1403fc128);

  if (local_res10[0] == 0) {

    FUN_14012e850("Invalid audio device instance ID");

    return local_res10[0];

  }

  FUN_14015cde0();

  return local_res10[0];

}




