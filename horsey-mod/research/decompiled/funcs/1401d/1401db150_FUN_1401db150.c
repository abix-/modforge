// Address: 0x1401db150
// Ghidra name: FUN_1401db150
// ============ 0x1401db150 FUN_1401db150 (size=513) ============


undefined8

FUN_1401db150(uint param_1,ulonglong param_2,ulonglong param_3,int param_4,undefined8 param_5,

             longlong param_6,undefined4 param_7,uint param_8,int param_9,undefined8 param_10,

             longlong param_11,undefined4 param_12)



{

  char cVar1;

  char cVar2;

  char cVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined8 in_stack_ffffffffffffffe0;

  undefined4 uVar8;

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);

  param_2 = param_2 & 0xffffffff;

  uVar7 = (ulonglong)param_1;

  if (param_4 != param_9) {

    uVar4 = FUN_14012e850("SDL_ConvertPixels_YUV_to_YUV: colorspace conversion not supported");

    return uVar4;

  }

  uVar6 = (ulonglong)param_8;

  if ((uint)param_3 == param_8) {

    if (param_6 == param_11) {

      return 1;

    }

    uVar4 = FUN_1401db360(uVar7,param_2,param_3,param_6,param_7,param_11,param_12);

    return uVar4;

  }

  cVar1 = FUN_1401d47c0(param_3 & 0xffffffff);

  if (cVar1 != '\0') {

    cVar2 = FUN_1401d47c0(uVar6 & 0xffffffff);

    if (cVar2 != '\0') {

      uVar4 = FUN_1401d5690(uVar7 & 0xffffffff,param_2 & 0xffffffff,param_3 & 0xffffffff,param_6,

                            param_7,CONCAT44(uVar8,(int)uVar6),param_11,param_12);

      return uVar4;

    }

  }

  cVar2 = FUN_1401d47a0(param_3 & 0xffffffff);

  if (cVar2 != '\0') {

    cVar3 = FUN_1401d47a0(uVar6 & 0xffffffff);

    if (cVar3 != '\0') {

      uVar4 = FUN_1401d4d80(uVar7 & 0xffffffff,param_2 & 0xffffffff,param_3 & 0xffffffff,param_6,

                            param_7,CONCAT44(uVar8,(int)uVar6),param_11,param_12);

      return uVar4;

    }

  }

  if (cVar1 != '\0') {

    cVar1 = FUN_1401d47a0(uVar6 & 0xffffffff);

    if (cVar1 != '\0') {

      uVar4 = FUN_1401d52e0(uVar7 & 0xffffffff,param_2 & 0xffffffff,param_3 & 0xffffffff,param_6,

                            param_7,CONCAT44(uVar8,(int)uVar6),param_11,param_12);

      return uVar4;

    }

  }

  if (cVar2 != '\0') {

    cVar1 = FUN_1401d47c0(uVar6 & 0xffffffff);

    if (cVar1 != '\0') {

      uVar4 = FUN_1401d4f10(uVar7 & 0xffffffff,param_2 & 0xffffffff,param_3 & 0xffffffff,param_6,

                            param_7,CONCAT44(uVar8,(int)uVar6),param_11,param_12);

      return uVar4;

    }

  }

  uVar4 = FUN_14017af90(uVar6 & 0xffffffff);

  uVar5 = FUN_14017af90(param_3 & 0xffffffff);

  uVar4 = FUN_14012e850("SDL_ConvertPixels_YUV_to_YUV: Unsupported YUV conversion: %s -> %s",uVar5,

                        uVar4);

  return uVar4;

}




