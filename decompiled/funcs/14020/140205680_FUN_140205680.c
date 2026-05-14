// Address: 0x140205680
// Ghidra name: FUN_140205680
// ============ 0x140205680 FUN_140205680 (size=136) ============


undefined1 FUN_140205680(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 local_20;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  

  local_20 = 0;

  local_28 = 1;

  local_24 = param_2;

  lVar1 = FUN_140134590(*(undefined8 *)(param_1 + 8),&local_28);

  *(longlong *)(param_1 + 0x80) = lVar1;

  if (lVar1 != 0) {

    local_10 = 0;

    local_18 = 0;

    local_14 = param_2;

    lVar1 = FUN_140135d10(*(undefined8 *)(param_1 + 8),&local_18);

    *(longlong *)(param_1 + 0x78) = lVar1;

    if (lVar1 != 0) {

      *(undefined4 *)(param_1 + 0x88) = param_2;

      return 1;

    }

  }

  return 0;

}




