// Address: 0x140159890
// Ghidra name: FUN_140159890
// ============ 0x140159890 FUN_140159890 (size=98) ============


ulonglong FUN_140159890(longlong param_1)



{

  byte bVar1;

  char cVar2;

  ulonglong uVar3;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,4);

      if (cVar2 == '\0') goto LAB_1401598d2;

    }

    bVar1 = *(byte *)(param_1 + 0xe0);

    FUN_14015bb10();

    return (ulonglong)bVar1;

  }

LAB_1401598d2:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




