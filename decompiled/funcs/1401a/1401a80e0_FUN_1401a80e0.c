// Address: 0x1401a80e0
// Ghidra name: FUN_1401a80e0
// ============ 0x1401a80e0 FUN_1401a80e0 (size=45) ============


void FUN_1401a80e0(undefined8 param_1,undefined4 *param_2,undefined8 param_3)



{

  if (*(char *)(param_2 + 0x14) != '\0') {

    *(undefined1 *)(param_2 + 0x14) = 0;

    return;

  }

  if (-1 < (int)param_2[0x13]) {

    FUN_1401a8b60(param_1,*param_2,param_3,1,1);

  }

  return;

}




