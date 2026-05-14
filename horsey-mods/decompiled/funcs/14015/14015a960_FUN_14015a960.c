// Address: 0x14015a960
// Ghidra name: FUN_14015a960
// ============ 0x14015a960 FUN_14015a960 (size=336) ============


ulonglong FUN_14015a960(longlong param_1,short param_2,short param_3,uint param_4)



{

  char cVar1;

  byte bVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  FUN_140159d30();

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,4), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","joystick");

    uVar4 = FUN_14015bb10();

    return uVar4 & 0xffffffffffffff00;

  }

  if ((param_2 == *(short *)(param_1 + 0xa0)) && (param_3 == *(short *)(param_1 + 0xa2))) {

    bVar2 = 1;

LAB_14015aa10:

    *(short *)(param_1 + 0xa0) = param_2;

    *(short *)(param_1 + 0xa2) = param_3;

    if (((param_2 != 0) || (param_3 != 0)) && (param_4 != 0)) {

      lVar3 = FUN_140149350();

      uVar4 = 0xffff;

      if (param_4 < 0xffff) {

        uVar4 = (ulonglong)param_4;

      }

      *(ulonglong *)(param_1 + 0xa8) = lVar3 + uVar4;

      if (lVar3 + uVar4 == 0) {

        *(undefined8 *)(param_1 + 0xa8) = 1;

      }

      goto LAB_14015aa67;

    }

    *(undefined8 *)(param_1 + 0xa8) = 0;

  }

  else {

    bVar2 = (**(code **)(*(longlong *)(param_1 + 0x140) + 0x60))(param_1,param_2,param_3);

    if (bVar2 != 0) {

      lVar3 = FUN_140149350();

      *(longlong *)(param_1 + 0xb0) = lVar3 + 2000;

      if (lVar3 + 2000 == 0) {

        *(undefined8 *)(param_1 + 0xb0) = 1;

      }

      goto LAB_14015aa10;

    }

  }

  *(undefined8 *)(param_1 + 0xb0) = 0;

LAB_14015aa67:

  FUN_14015bb10();

  return (ulonglong)bVar2;

}




