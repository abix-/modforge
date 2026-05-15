// Address: 0x1402c6cd8
// Ghidra name: FUN_1402c6cd8
// ============ 0x1402c6cd8 FUN_1402c6cd8 (size=73) ============


undefined8 * FUN_1402c6cd8(undefined8 param_1,undefined8 *param_2,undefined4 param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_1402c6d34(param_3);

  lVar2 = -1;

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  param_2[3] = 0;

  do {

    lVar2 = lVar2 + 1;

  } while (*(char *)(lVar1 + lVar2) != '\0');

  FUN_140027e30(param_2,lVar1);

  return param_2;

}




