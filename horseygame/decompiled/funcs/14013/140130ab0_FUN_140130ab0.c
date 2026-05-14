// Address: 0x140130ab0
// Ghidra name: FUN_140130ab0
// ============ 0x140130ab0 FUN_140130ab0 (size=140) ============


longlong FUN_140130ab0(undefined4 param_1)



{

  longlong lVar1;

  longlong local_res10 [3];

  

  lVar1 = FUN_140131d30();

  if (lVar1 == 0) {

    FUN_14012e850("Camera subsystem is not initialized");

    return 0;

  }

  local_res10[0] = 0;

  FUN_14017caa0(DAT_1403fb628);

  FUN_1401aaff0(DAT_1403fb630,param_1,local_res10);

  FUN_14017cae0(DAT_1403fb628);

  if (local_res10[0] == 0) {

    FUN_14012e850("Invalid camera device instance ID");

    return local_res10[0];

  }

  FUN_140130b40();

  return local_res10[0];

}




