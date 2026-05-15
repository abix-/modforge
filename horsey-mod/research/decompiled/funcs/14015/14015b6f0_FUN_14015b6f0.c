// Address: 0x14015b6f0
// Ghidra name: FUN_14015b6f0
// ============ 0x14015b6f0 FUN_14015b6f0 (size=163) ============


ulonglong FUN_14015b6f0(longlong param_1,undefined4 param_2,undefined2 param_3)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  

  FUN_140159d30();

  if (param_1 == 0) {

LAB_14015b769:

    FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_14015b769;

    }

    if (*(char *)(param_1 + 0x41) != '\0') {

      bVar2 = FUN_14020cda0(param_1,param_2,param_3);

      FUN_14015bb10();

      return (ulonglong)bVar2;

    }

    FUN_14012e850("joystick isn\'t virtual");

  }

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




