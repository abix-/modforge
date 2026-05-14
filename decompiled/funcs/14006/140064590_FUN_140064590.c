// Address: 0x140064590
// Ghidra name: FUN_140064590
// ============ 0x140064590 FUN_140064590 (size=306) ============


undefined8 * FUN_140064590(undefined8 *param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  

  FUN_1400c9420();

  *param_1 = &PTR_FUN_140307bf0;

  uVar2 = 1;

  _eh_vector_constructor_iterator_(param_1 + 0x4b,0x20,4,FUN_140027b00,FUN_140027900);

  param_1[0x5b] = 0;

  param_1[0x5c] = 0;

  param_1[0x5d] = 0;

  param_1[0x5e] = 0xf;

  *(undefined1 *)(param_1 + 0x5b) = 0;

  param_1[0x60] = 0;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0xf;

  *(undefined1 *)(param_1 + 0x60) = 0;

  FUN_1400278e0(param_1 + 3,"Bubber\'s Hutch");

  FUN_1400278e0(param_1 + 7,"Hutch");

  FUN_1400c9f10(param_1);

  uVar1 = DAT_140303398;

  FUN_1400cf540(param_1,1,0,DAT_140303398,CONCAT44(uVar2,DAT_140303398),DAT_140303398);

  FUN_1400cf540(param_1,3,uVar1,DAT_14030374c,DAT_140303750,DAT_140303390);

  *(undefined1 *)(param_1 + 0x5f) = 0;

  *(undefined4 *)(param_1 + 100) = 0xffffffff;

  return param_1;

}




