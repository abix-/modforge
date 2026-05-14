// Address: 0x140024150
// Ghidra name: FUN_140024150
// ============ 0x140024150 FUN_140024150 (size=60) ============


undefined8 * FUN_140024150(undefined8 *param_1,longlong param_2)



{

  *param_1 = std::exception::vftable;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_1402c8190(param_2 + 8);

  *param_1 = std::runtime_error::vftable;

  return param_1;

}




