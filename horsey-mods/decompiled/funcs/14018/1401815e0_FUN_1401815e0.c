// Address: 0x1401815e0
// Ghidra name: FUN_1401815e0
// ============ 0x1401815e0 FUN_1401815e0 (size=59) ============


undefined4 FUN_1401815e0(longlong param_1)



{

  EXECUTION_STATE EVar1;

  

  EVar1 = 0x80000002;

  if (*(char *)(param_1 + 0x31a) == '\0') {

    EVar1 = 0x80000000;

  }

  EVar1 = SetThreadExecutionState(EVar1);

  if (EVar1 == 0) {

    FUN_14012e850("SetThreadExecutionState() failed");

    return 0;

  }

  return 1;

}




