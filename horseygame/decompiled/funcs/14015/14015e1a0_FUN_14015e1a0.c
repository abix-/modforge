// Address: 0x14015e1a0
// Ghidra name: FUN_14015e1a0
// ============ 0x14015e1a0 FUN_14015e1a0 (size=156) ============


longlong FUN_14015e1a0(undefined8 param_1,undefined8 param_2)



{

  longlong lVar1;

  undefined8 local_28;

  undefined8 local_20;

  longlong local_18;

  

  lVar1 = FUN_14015e610();

  if (lVar1 == 0) {

    FUN_14012e850("Audio subsystem is not initialized");

    return 0;

  }

  local_18 = 0;

  local_28 = param_1;

  local_20 = param_2;

  FUN_14017caa0(DAT_1403fc128);

  FUN_1401ab210(DAT_1403fc130,FUN_1401309c0,&local_28);

  FUN_14017cae0(DAT_1403fc128);

  if (local_18 == 0) {

    FUN_14012e850("Device not found");

  }

  return local_18;

}




