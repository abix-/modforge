// Address: 0x1401d5690
// Ghidra name: FUN_1401d5690
// ============ 0x1401d5690 FUN_1401d5690 (size=666) ============


void FUN_1401d5690(int param_1,int param_2,int param_3,longlong param_4,ulonglong param_5,

                  int param_6,longlong param_7,int param_8)



{

  undefined8 uVar1;

  undefined8 uVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  ulonglong uVar6;

  bool bVar7;

  undefined1 uVar8;

  

  uVar6 = (ulonglong)(int)param_5;

  if ((param_4 != param_7) && (lVar4 = param_4, lVar5 = param_7, iVar3 = param_2, param_2 != 0)) {

    do {

      FUN_1402f8e20(lVar5,lVar4,(longlong)param_1);

      iVar3 = iVar3 + -1;

      lVar4 = lVar4 + uVar6;

      lVar5 = lVar5 + param_8;

    } while (iVar3 != 0);

    uVar6 = param_5 & 0xffffffff;

  }

  if (param_3 == 0x3132564e) {

    if (param_6 == 0x3231564e) {

LAB_1401d58ff:

      FUN_1401d5f60(param_1,param_2,param_4,uVar6 & 0xffffffff);

      return;

    }

    if (param_6 != 0x32315659) {

      if (param_6 == 0x56555949) {

        FUN_1401d5bf0(param_1,param_2,param_4,uVar6 & 0xffffffff);

        return;

      }

      goto LAB_1401d589a;

    }

  }

  else {

    if (param_3 != 0x3231564e) {

      if (param_3 == 0x32315659) {

        if (param_6 == 0x3132564e) {

LAB_1401d5802:

          FUN_1401d4a20(param_1,param_2,param_4,uVar6 & 0xffffffff);

          return;

        }

        if (param_6 == 0x3231564e) goto LAB_1401d57cf;

        bVar7 = param_6 == 0x56555949;

      }

      else {

        if (param_3 != 0x56555949) goto LAB_1401d589a;

        if (param_6 == 0x3132564e) {

LAB_1401d57cf:

          FUN_1401d4a20(param_1,param_2,param_4,uVar6 & 0xffffffff);

          return;

        }

        if (param_6 == 0x3231564e) goto LAB_1401d5802;

        bVar7 = param_6 == 0x32315659;

      }

      if (bVar7) {

        FUN_1401d6200(param_1,param_2,param_4,uVar6 & 0xffffffff);

        return;

      }

LAB_1401d589a:

      uVar1 = FUN_14017af90();

      uVar2 = FUN_14017af90(param_3);

      FUN_14012e850("SDL_ConvertPixels_Planar2x2_to_Planar2x2: Unsupported YUV conversion: %s -> %s"

                    ,uVar2,uVar1);

      return;

    }

    if (param_6 == 0x3132564e) goto LAB_1401d58ff;

    if (param_6 == 0x32315659) {

      uVar8 = 1;

      goto LAB_1401d5856;

    }

    if (param_6 != 0x56555949) goto LAB_1401d589a;

  }

  uVar8 = 0;

LAB_1401d5856:

  FUN_1401d5bf0(param_1,param_2,param_4,uVar6 & 0xffffffff,param_7,param_8,uVar8);

  return;

}




