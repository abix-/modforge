// Address: 0x1400a3610
// Ghidra name: FUN_1400a3610
// ============ 0x1400a3610 FUN_1400a3610 (size=28) ============


undefined8 * FUN_1400a3610(int param_1)



{

  undefined8 *puVar1;

  

  puVar1 = &DAT_1403f11a0 + (longlong)param_1 * 4;

  if (0xf < (ulonglong)(&DAT_1403f11b8)[(longlong)param_1 * 4]) {

    puVar1 = (undefined8 *)*puVar1;

  }

  return puVar1;

}




