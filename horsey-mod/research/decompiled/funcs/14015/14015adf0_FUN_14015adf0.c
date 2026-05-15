// Address: 0x14015adf0
// Ghidra name: FUN_14015adf0
// ============ 0x14015adf0 FUN_14015adf0 (size=152) ============


ulonglong FUN_14015adf0(longlong param_1,undefined8 param_2,undefined4 param_3)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  

  FUN_140159d30();

  if (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar1 = FUN_1401aa7c0(param_1,4);

      if (cVar1 == '\0') goto LAB_14015ae5e;

    }

    bVar2 = (**(code **)(*(longlong *)(param_1 + 0x140) + 0x78))(param_1,param_2,param_3);

    FUN_14015bb10();

    return (ulonglong)bVar2;

  }

LAB_14015ae5e:

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




