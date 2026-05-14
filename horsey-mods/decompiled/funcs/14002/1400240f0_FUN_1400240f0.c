// Address: 0x1400240f0
// Ghidra name: FUN_1400240f0
// ============ 0x1400240f0 FUN_1400240f0 (size=60) ============


undefined8 * FUN_1400240f0(undefined8 *param_1,longlong param_2)



{

  *param_1 = std::exception::vftable;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_1402c8190(param_2 + 8);

  *param_1 = std::bad_alloc::vftable;

  return param_1;

}




