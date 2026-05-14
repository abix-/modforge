// Address: 0x14015b9b0
// Ghidra name: FUN_14015b9b0
// ============ 0x14015b9b0 FUN_14015b9b0 (size=204) ============


ulonglong FUN_14015b9b0(longlong param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,

                       undefined4 param_5,undefined4 param_6,undefined4 param_7)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  

  FUN_140159d30();

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,4), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  }

  else {

    if (*(char *)(param_1 + 0x41) != '\0') {

      bVar2 = FUN_14020d040(param_1,param_2,param_3,param_4,param_5,param_6,param_7);

      FUN_14015bb10();

      return (ulonglong)bVar2;

    }

    FUN_14012e850("joystick isn\'t virtual");

  }

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




