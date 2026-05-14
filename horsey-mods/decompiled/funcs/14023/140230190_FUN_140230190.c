// Address: 0x140230190
// Ghidra name: FUN_140230190
// ============ 0x140230190 FUN_140230190 (size=59) ============


void FUN_140230190(longlong param_1)



{

  uint uVar1;

  ulonglong uVar2;

  

  uVar1 = FUN_140138fe0(param_1 + 0x20);

  if (0 < (int)uVar1) {

    uVar2 = (ulonglong)uVar1;

    do {

      SetEvent(*(HANDLE *)(param_1 + 0x10));

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  return;

}




