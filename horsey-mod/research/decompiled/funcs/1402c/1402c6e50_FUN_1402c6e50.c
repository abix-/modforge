// Address: 0x1402c6e50
// Ghidra name: FUN_1402c6e50
// ============ 0x1402c6e50 FUN_1402c6e50 (size=34) ============


undefined8 FUN_1402c6e50(longlong param_1)



{

  int *piVar1;

  

  piVar1 = (int *)(param_1 + 0x4c);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 == 0) {

    *(undefined4 *)(param_1 + 0x48) = 0xffffffff;

    ReleaseSRWLockExclusive((PSRWLOCK)(param_1 + 0x10));

  }

  return 0;

}




