// Address: 0x1401617f0
// Ghidra name: FUN_1401617f0
// ============ 0x1401617f0 FUN_1401617f0 (size=57) ============


void FUN_1401617f0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  

  cVar1 = FUN_1401429e0(param_4,1);

  *(char *)(param_1 + 0xc5) = cVar1;

  if ((cVar1 == '\0') && (*(char *)(param_1 + 0xc6) != '\0')) {

    FUN_140162d10(0);

    *(undefined1 *)(param_1 + 0xc6) = 0;

  }

  return;

}




