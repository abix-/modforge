// Address: 0x140264a10
// Ghidra name: FUN_140264a10
// ============ 0x140264a10 FUN_140264a10 (size=160) ============


void FUN_140264a10(undefined8 param_1,undefined8 param_2,ushort param_3,ushort param_4)



{

  longlong lVar1;

  int iVar2;

  

  lVar1 = FUN_140268130();

  if (lVar1 == 0) {

    FUN_14012e850("Invalid joystick");

    return;

  }

  if ((*(byte *)(lVar1 + 0x14c) & 0x20) == 0) {

    FUN_14012e850("That operation is not supported");

    return;

  }

  *(undefined1 *)(lVar1 + 0xf0) = 1;

  iVar2 = (int)((ulonglong)param_3 * 0x903847eb >> 0x20);

  *(char *)(lVar1 + 0xf3) = (char)(((uint)param_3 - iVar2 >> 1) + iVar2 >> 9);

  iVar2 = (int)((ulonglong)param_4 * 0x903847eb >> 0x20);

  *(char *)(lVar1 + 0xf4) = (char)(((uint)param_4 - iVar2 >> 1) + iVar2 >> 9);

  FUN_1402681b0(lVar1);

  return;

}




