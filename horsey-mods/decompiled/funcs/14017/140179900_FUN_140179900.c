// Address: 0x140179900
// Ghidra name: FUN_140179900
// ============ 0x140179900 FUN_140179900 (size=91) ============


undefined4 FUN_140179900(longlong param_1)



{

  char cVar1;

  DWORD DVar2;

  

  DVar2 = GetCurrentThreadId();

  if (*(DWORD *)(param_1 + 0xc) == DVar2) {

    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

    return 1;

  }

  cVar1 = (*DAT_1403fc548)(param_1);

  if (cVar1 != '\0') {

    *(DWORD *)(param_1 + 0xc) = DVar2;

    *(undefined4 *)(param_1 + 8) = 1;

    return 1;

  }

  return 0;

}




