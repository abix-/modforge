// Address: 0x14015b540
// Ghidra name: FUN_14015b540
// ============ 0x14015b540 FUN_14015b540 (size=297) ============


ulonglong FUN_14015b540(longlong param_1,char param_2,char param_3,char param_4)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  longlong lVar4;

  

  FUN_140159d30();

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,4), cVar1 != '\0')))) {

    if ((((param_2 == *(char *)(param_1 + 0xd0)) && (param_3 == *(char *)(param_1 + 0xd1))) &&

        (param_4 == *(char *)(param_1 + 0xd2))) &&

       (uVar3 = FUN_140149350(), uVar3 < *(ulonglong *)(param_1 + 0xd8))) {

      bVar2 = 1;

    }

    else {

      bVar2 = (**(code **)(*(longlong *)(param_1 + 0x140) + 0x70))(param_1,param_2,param_3,param_4);

      lVar4 = FUN_140149350();

      *(longlong *)(param_1 + 0xd8) = lVar4 + 5000;

    }

    *(char *)(param_1 + 0xd0) = param_2;

    *(char *)(param_1 + 0xd1) = param_3;

    *(char *)(param_1 + 0xd2) = param_4;

    FUN_14015bb10();

    return (ulonglong)bVar2;

  }

  FUN_14012e850("Parameter \'%s\' is invalid","joystick");

  uVar3 = FUN_14015bb10();

  return uVar3 & 0xffffffffffffff00;

}




