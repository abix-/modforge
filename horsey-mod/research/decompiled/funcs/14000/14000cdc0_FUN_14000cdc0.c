// Address: 0x14000cdc0
// Ghidra name: FUN_14000cdc0
// ============ 0x14000cdc0 FUN_14000cdc0 (size=53) ============


void FUN_14000cdc0(undefined8 *param_1)



{

  *param_1 = b2ChainShape::vftable;

  thunk_FUN_1402e9a80(param_1[2]);

  param_1[2] = 0;

  *(undefined4 *)(param_1 + 3) = 0;

  *param_1 = b2Shape::vftable;

  return;

}




