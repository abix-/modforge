// Address: 0x1402c86d4
// Ghidra name: FUN_1402c86d4
// ============ 0x1402c86d4 FUN_1402c86d4 (size=33) ============


longlong * FUN_1402c86d4(longlong *param_1,undefined8 param_2,byte *param_3,longlong *param_4)



{

  *param_4 = *param_1;

  if ((*param_3 & 1) != 0) {

    *param_4 = *(longlong *)((ulonglong)*(uint *)(param_3 + 0x14) + *param_1);

  }

  return param_4;

}




