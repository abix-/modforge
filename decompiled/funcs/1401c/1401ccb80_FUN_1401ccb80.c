// Address: 0x1401ccb80
// Ghidra name: FUN_1401ccb80
// ============ 0x1401ccb80 FUN_1401ccb80 (size=46) ============


undefined8 FUN_1401ccb80(longlong param_1)



{

  char cVar1;

  

  *(undefined1 *)(param_1 + 0x130) = 0;

  cVar1 = FUN_1401cc650();

  if (cVar1 == '\0') {

    return 0;

  }

  return *(undefined8 *)(param_1 + 0x128);

}




