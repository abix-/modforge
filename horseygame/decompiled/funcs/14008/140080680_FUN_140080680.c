// Address: 0x140080680
// Ghidra name: FUN_140080680
// ============ 0x140080680 FUN_140080680 (size=99) ============


undefined8 * FUN_140080680(undefined8 *param_1)



{

  FUN_1400a8610(param_1,0);

  *(undefined4 *)(param_1 + 6) = 0x41c00000;

  *param_1 = &PTR_FUN_14030ac90;

  param_1[0x10] = 0;

  param_1[0xe] = 0;

  *(undefined4 *)(param_1 + 3) = 0;

  param_1[0xf] = 0;

  *(undefined4 *)((longlong)param_1 + 0xb4) = 0;

  param_1[10] = 0;

  *(undefined1 *)(param_1 + 0x17) = 0;

  *(undefined8 *)((longlong)param_1 + 0xbc) = 0;

  *(undefined4 *)((longlong)param_1 + 0x34) = 0x41800000;

  *(undefined1 *)((longlong)param_1 + 0xc4) = 1;

  return param_1;

}




