// Address: 0x14012bf10
// Ghidra name: FUN_14012bf10
// ============ 0x14012bf10 FUN_14012bf10 (size=46) ============


undefined4 FUN_14012bf10(longlong param_1)



{

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","context");

    return 1;

  }

  return *(undefined4 *)(param_1 + 0x40);

}




