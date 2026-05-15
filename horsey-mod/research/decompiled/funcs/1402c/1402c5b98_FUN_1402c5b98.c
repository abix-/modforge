// Address: 0x1402c5b98
// Ghidra name: FUN_1402c5b98
// ============ 0x1402c5b98 FUN_1402c5b98 (size=60) ============


undefined8 * FUN_1402c5b98(undefined8 *param_1,longlong param_2)



{

  *param_1 = std::exception::vftable;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_1402c8190(param_2 + 8);

  *param_1 = std::out_of_range::vftable;

  return param_1;

}




