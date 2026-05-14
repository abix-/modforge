// Address: 0x1400c3550
// Ghidra name: FUN_1400c3550
// ============ 0x1400c3550 FUN_1400c3550 (size=70) ============


undefined8 * FUN_1400c3550(undefined8 *param_1,ulonglong param_2)



{

  *param_1 = &PTR_LAB_14030dc10;

  if ((*(byte *)(param_1 + 1) & 1) != 0) {

    SteamAPI_UnregisterCallback();

  }

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x10);

  }

  return param_1;

}




