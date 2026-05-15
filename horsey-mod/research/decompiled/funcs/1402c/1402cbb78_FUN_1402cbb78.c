// Address: 0x1402cbb78
// Ghidra name: FUN_1402cbb78
// ============ 0x1402cbb78 FUN_1402cbb78 (size=60) ============


undefined8 * FUN_1402cbb78(undefined8 *param_1,longlong param_2)



{

  *param_1 = std::exception::vftable;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_1402c8190(param_2 + 8);

  *param_1 = std::bad_exception::vftable;

  return param_1;

}




