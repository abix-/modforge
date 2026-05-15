// Address: 0x1402cbbb4
// Ghidra name: FUN_1402cbbb4
// ============ 0x1402cbbb4 FUN_1402cbbb4 (size=33) ============


undefined8 * FUN_1402cbbb4(undefined8 *param_1)



{

  param_1[2] = 0;

  param_1[1] = "bad exception";

  *param_1 = std::bad_exception::vftable;

  return param_1;

}




