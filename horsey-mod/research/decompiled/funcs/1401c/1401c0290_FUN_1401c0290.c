// Address: 0x1401c0290
// Ghidra name: FUN_1401c0290
// ============ 0x1401c0290 FUN_1401c0290 (size=46) ============


undefined8 FUN_1401c0290(longlong param_1)



{

  char cVar1;

  

  *(undefined1 *)(param_1 + 0xa98) = 0;

  cVar1 = FUN_1401bfd60();

  if (cVar1 == '\0') {

    return 0;

  }

  return *(undefined8 *)(param_1 + 0xa90);

}




