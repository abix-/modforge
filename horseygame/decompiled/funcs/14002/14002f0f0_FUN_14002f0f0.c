// Address: 0x14002f0f0
// Ghidra name: FUN_14002f0f0
// ============ 0x14002f0f0 FUN_14002f0f0 (size=225) ============


undefined8 * FUN_14002f0f0(undefined8 *param_1)



{

  undefined4 uVar1;

  

  FUN_1400c9420();

  *param_1 = &PTR_FUN_140303430;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  param_1[0x4e] = 0;

  FUN_1400278e0(param_1 + 3,"O\'er Yonder Acres");

  FUN_1400278e0(param_1 + 7,"Acres");

  uVar1 = DAT_140303398;

  FUN_1400cf540(param_1,1,0,DAT_140303398,DAT_140303398,DAT_140303398);

  FUN_1400cf540(param_1,3,uVar1,DAT_14030374c,DAT_140303750,DAT_140303390);

  FUN_1400c9f10(param_1);

  *(undefined1 *)((longlong)param_1 + 0x25c) = 0;

  *(undefined4 *)(param_1 + 0x4b) = 0;

  return param_1;

}




