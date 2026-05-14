// Address: 0x140279690
// Ghidra name: FUN_140279690
// ============ 0x140279690 FUN_140279690 (size=27) ============


bool FUN_140279690(longlong param_1,char param_2)



{

  if (*(int *)(param_1 + 0x1c) == 0x83) {

    return false;

  }

  if (*(char *)(param_1 + 0x2a) != '\0') {

    return param_2 != '\0';

  }

  return true;

}




