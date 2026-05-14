// Address: 0x140146bc0
// Ghidra name: FUN_140146bc0
// ============ 0x140146bc0 FUN_140146bc0 (size=66) ============


ulonglong FUN_140146bc0(longlong param_1)



{

  char cVar1;

  ulonglong uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return 0;

  }

  uVar2 = (ulonglong)*(uint *)(param_1 + 0x34);

  if (*(uint *)(param_1 + 0x34) == 0) {

    uVar2 = FUN_1401746e0();

    *(int *)(param_1 + 0x34) = (int)uVar2;

  }

  return uVar2;

}




