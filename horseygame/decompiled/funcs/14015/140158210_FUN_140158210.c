// Address: 0x140158210
// Ghidra name: FUN_140158210
// ============ 0x140158210 FUN_140158210 (size=62) ============


int * FUN_140158210(undefined4 param_1)



{

  int *piVar1;

  int iVar2;

  

  FUN_140159d30();

  iVar2 = FUN_140158700(param_1);

  for (piVar1 = DAT_1403fc070; (piVar1 != (int *)0x0 && (*piVar1 != iVar2));

      piVar1 = *(int **)(piVar1 + 0x56)) {

  }

  FUN_14015bb10();

  return piVar1;

}




