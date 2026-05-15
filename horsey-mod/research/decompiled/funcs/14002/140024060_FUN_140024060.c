// Address: 0x140024060
// Ghidra name: FUN_140024060
// ============ 0x140024060 FUN_140024060 (size=33) ============


undefined8 * FUN_140024060(undefined8 *param_1)



{

  param_1[2] = 0;

  param_1[1] = "bad array new length";

  *param_1 = std::bad_array_new_length::vftable;

  return param_1;

}




