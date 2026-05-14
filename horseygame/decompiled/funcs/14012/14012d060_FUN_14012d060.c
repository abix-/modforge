// Address: 0x14012d060
// Ghidra name: FUN_14012d060
// ============ 0x14012d060 FUN_14012d060 (size=69) ============


ulonglong FUN_14012d060(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)



{

  ulonglong uVar1;

  

  uVar1 = *(longlong *)(param_1 + 0x10) - *(longlong *)(param_1 + 8);

  if (uVar1 < param_4) {

    param_4 = uVar1;

  }

  FUN_1402f8e20(param_2,param_3,param_4);

  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + param_4;

  return param_4;

}




