// Address: 0x140162e10
// Ghidra name: FUN_140162e10
// ============ 0x140162e10 FUN_140162e10 (size=73) ============


undefined1 FUN_140162e10(undefined8 param_1,undefined8 param_2)



{

  undefined1 uVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401611a0();

  if (*(char *)(lVar2 + 0xc1) != '\0') {

    uVar1 = FUN_14012e850("Can\'t set mouse transform while relative mode is active");

    return uVar1;

  }

  *(undefined8 *)(lVar2 + 0x70) = param_2;

  *(undefined8 *)(lVar2 + 0x68) = param_1;

  return 1;

}




