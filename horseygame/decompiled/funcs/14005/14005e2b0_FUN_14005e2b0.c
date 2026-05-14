// Address: 0x14005e2b0
// Ghidra name: FUN_14005e2b0
// ============ 0x14005e2b0 FUN_14005e2b0 (size=85) ============


undefined8 * FUN_14005e2b0(undefined8 *param_1,uint param_2)



{

  *param_1 = &PTR_FUN_1403068e0;

  if (param_1[0xf] != 0) {

    FUN_1402c7088(param_1[0xf],0x1e0);

  }

  FUN_1400a8730(param_1);

  if ((param_2 & 1) != 0) {

    FUN_1402c7088(param_1,0x80);

  }

  return param_1;

}




