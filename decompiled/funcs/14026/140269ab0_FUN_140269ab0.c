// Address: 0x140269ab0
// Ghidra name: FUN_140269ab0
// ============ 0x140269ab0 FUN_140269ab0 (size=15) ============


char FUN_140269ab0(longlong param_1)



{

  char cVar1;

  

  cVar1 = *(char *)(param_1 + 0x24);

  if ((cVar1 == '\0') || (cVar1 == '?')) {

    cVar1 = '0';

  }

  return cVar1;

}




