// Address: 0x140067e60
// Ghidra name: FUN_140067e60
// ============ 0x140067e60 FUN_140067e60 (size=155) ============


undefined8 * FUN_140067e60(undefined8 *param_1)



{

  FUN_1400c9420();

  *param_1 = &PTR_FUN_140309998;

  FUN_1400278e0(param_1 + 3,"Power Plant");

  FUN_1400278e0(param_1 + 7,"PowerPlant");

  FUN_1400cf540(param_1,1,0,DAT_140303398,DAT_140303398,DAT_140303398);

  FUN_1400c9f10(param_1);

  *(undefined1 *)(param_1 + 0x4e) = 0;

  *(undefined4 *)((longlong)param_1 + 0x274) = 0;

  *(undefined4 *)(param_1 + 0x4d) = 0;

  *(undefined4 *)(param_1 + 0x4f) = 0xffffffff;

  *(undefined4 *)((longlong)param_1 + 0x284) = 0xffffffff;

  return param_1;

}




