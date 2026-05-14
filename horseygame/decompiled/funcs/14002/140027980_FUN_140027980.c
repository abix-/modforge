// Address: 0x140027980
// Ghidra name: FUN_140027980
// ============ 0x140027980 FUN_140027980 (size=55) ============


undefined8 * FUN_140027980(undefined8 *param_1,longlong param_2)



{

  longlong lVar1;

  

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  lVar1 = -1;

  do {

    lVar1 = lVar1 + 1;

  } while (*(char *)(param_2 + lVar1) != '\0');

  FUN_140027e30();

  return param_1;

}




