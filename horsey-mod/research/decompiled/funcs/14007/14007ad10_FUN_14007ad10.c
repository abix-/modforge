// Address: 0x14007ad10
// Ghidra name: FUN_14007ad10
// ============ 0x14007ad10 FUN_14007ad10 (size=231) ============


undefined8 * FUN_14007ad10(undefined8 *param_1)



{

  FUN_1400c9420();

  *param_1 = &PTR_FUN_14030a658;

  FUN_1400278e0(param_1 + 3,"Sumo Ring");

  FUN_1400278e0(param_1 + 7,&DAT_14030a744);

  *(undefined4 *)(param_1 + 0xb) = DAT_1403eae00;

  FUN_1400cf540(param_1,3,0,DAT_14030374c,DAT_140303398,DAT_140303394);

  FUN_1400c9f10(param_1);

  param_1[0x4f] = 200;

  *(undefined4 *)((longlong)param_1 + 0x274) = 1;

  param_1[0x4d] = 0;

  *(undefined1 *)(param_1 + 0x55) = 0;

  *(undefined4 *)((longlong)param_1 + 0x2ac) = 0;

  FUN_1400c9c30(param_1,7,0x19,0x71,0x46,0x36,1);

  return param_1;

}




