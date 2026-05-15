// Address: 0x1402178c0
// Ghidra name: FUN_1402178c0
// ============ 0x1402178c0 FUN_1402178c0 (size=146) ============


longlong FUN_1402178c0(longlong *param_1,longlong param_2,ulonglong param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  

  lVar1 = *param_1;

  uVar2 = *(ulonglong *)(lVar1 + 0x40);

  if (param_3 <= uVar2) {

    return (*(longlong *)(lVar1 + 0x38) - param_3) + uVar2;

  }

  param_3 = param_3 - uVar2;

  if ((ulonglong)param_1[3] < param_3) {

    return 0;

  }

  FUN_1402f8e20(param_2,(param_1[2] - param_3) + param_1[3],param_3);

  FUN_1402f8e20(param_3 + param_2,*(undefined8 *)(lVar1 + 0x38),*(undefined8 *)(lVar1 + 0x40));

  return param_2;

}




