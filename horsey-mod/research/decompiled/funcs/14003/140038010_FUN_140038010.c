// Address: 0x140038010
// Ghidra name: FUN_140038010
// ============ 0x140038010 FUN_140038010 (size=36) ============


undefined1 FUN_140038010(longlong param_1)



{

  char cVar1;

  

  if (*(int *)(param_1 + 0x25c) == 0) {

    cVar1 = FUN_1400d5250();

    if (cVar1 != '\0') {

      return 1;

    }

  }

  return 0;

}




