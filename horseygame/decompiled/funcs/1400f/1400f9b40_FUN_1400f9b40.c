// Address: 0x1400f9b40
// Ghidra name: FUN_1400f9b40
// ============ 0x1400f9b40 FUN_1400f9b40 (size=129) ============


undefined8 * FUN_1400f9b40(undefined8 *param_1)



{

  FUN_1400c9420();

  *param_1 = &PTR_FUN_140312f40;

  *(undefined4 *)((longlong)param_1 + 0x254) = 0x41200000;

  *(undefined4 *)(param_1 + 0x4b) = 0x40900000;

  FUN_1400cf540(param_1,0,*(float *)(param_1 + 0x23) - DAT_14039ca58,

                *(float *)((longlong)param_1 + 0x11c) - DAT_140304be0,DAT_14039ca58,DAT_140304be0);

  FUN_1400c9f10(param_1);

  return param_1;

}




