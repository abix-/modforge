// Address: 0x1400245e0
// Ghidra name: FUN_1400245e0
// ============ 0x1400245e0 FUN_1400245e0 (size=77) ============


undefined8 * FUN_1400245e0(undefined8 *param_1,longlong param_2)



{

  undefined8 uVar1;

  

  *param_1 = std::exception::vftable;

  param_1[1] = 0;

  param_1[2] = 0;

  FUN_1402c8190(param_2 + 8);

  *param_1 = std::_System_error::vftable;

  uVar1 = *(undefined8 *)(param_2 + 0x20);

  param_1[3] = *(undefined8 *)(param_2 + 0x18);

  param_1[4] = uVar1;

  return param_1;

}




