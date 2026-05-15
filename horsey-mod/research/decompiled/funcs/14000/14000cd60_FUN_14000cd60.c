// Address: 0x14000cd60
// Ghidra name: FUN_14000cd60
// ============ 0x14000cd60 FUN_14000cd60 (size=85) ============


undefined8 * FUN_14000cd60(undefined8 *param_1,ulonglong param_2)



{

  *param_1 = b2ChainShape::vftable;

  thunk_FUN_1402e9a80(param_1[2]);

  param_1[2] = 0;

  *(undefined4 *)(param_1 + 3) = 0;

  *param_1 = b2Shape::vftable;

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x30);

  }

  return param_1;

}




