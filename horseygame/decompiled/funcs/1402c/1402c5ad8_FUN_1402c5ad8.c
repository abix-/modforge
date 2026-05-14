// Address: 0x1402c5ad8
// Ghidra name: FUN_1402c5ad8
// ============ 0x1402c5ad8 FUN_1402c5ad8 (size=60) ============


undefined8 * FUN_1402c5ad8(undefined8 *param_1,longlong param_2)



{

  *param_1 = std::exception::vftable;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_1402c8190(param_2 + 8);

  *param_1 = std::length_error::vftable;

  return param_1;

}




