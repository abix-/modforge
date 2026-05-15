// Address: 0x14013e740
// Ghidra name: FUN_14013e740
// ============ 0x14013e740 FUN_14013e740 (size=104) ============


undefined8 FUN_14013e740(undefined4 *param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  FUN_140159d30();

  local_18 = *param_1;

  uStack_14 = param_1[1];

  uStack_10 = param_1[2];

  uStack_c = param_1[3];

  lVar1 = FUN_1401407d0(&local_18,0);

  if (lVar1 != 0) {

    local_18 = *param_1;

    uStack_14 = param_1[1];

    uStack_10 = param_1[2];

    uStack_c = param_1[3];

    uVar2 = FUN_14013c130(lVar1,&local_18);

    FUN_14015bb10();

    return uVar2;

  }

  FUN_14012e850("Mapping not available");

  FUN_14015bb10();

  return 0;

}




