// Address: 0x14017c8c0
// Ghidra name: FUN_14017c8c0
// ============ 0x14017c8c0 FUN_14017c8c0 (size=44) ============


undefined1 FUN_14017c8c0(longlong param_1)



{

  undefined8 uVar1;

  char cVar2;

  

  cVar2 = (*DAT_1403fc5a0)();

  if (cVar2 != '\0') {

    uVar1 = FUN_14017ffb0();

    *(undefined8 *)(param_1 + 8) = uVar1;

    return 1;

  }

  return 0;

}




