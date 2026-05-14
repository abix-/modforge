// Address: 0x1402c6ddc
// Ghidra name: FUN_1402c6ddc
// ============ 0x1402c6ddc FUN_1402c6ddc (size=59) ============


void FUN_1402c6ddc(ulonglong *param_1)



{

  ulonglong uVar1;

  

  uVar1 = _Xtime_get_ticks();

  *param_1 = uVar1 / 10000000;

  *(int *)(param_1 + 1) = ((int)uVar1 + (int)(uVar1 / 10000000) * -10000000) * 100;

  return;

}




