// Address: 0x1401db360
// Ghidra name: FUN_1401db360
// ============ 0x1401db360 FUN_1401db360 (size=704) ============


undefined8

FUN_1401db360(uint param_1,int param_2,int param_3,longlong param_4,int param_5,longlong param_6,

             int param_7)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  int iVar5;

  

  uVar4 = (ulonglong)(int)param_1;

  cVar1 = FUN_1401d47c0(param_3,uVar4);

  if (cVar1 == '\0') {

    cVar1 = FUN_1401d47a0();

    if (cVar1 == '\0') {

      uVar3 = FUN_14017af90();

      uVar3 = FUN_14012e850("SDL_ConvertPixels_YUV_to_YUV_Copy: Unsupported YUV format: %s",uVar3);

      return uVar3;

    }

    if (param_2 != 0) {

      do {

        FUN_1402f8e20(param_6,param_4,(longlong)(((int)uVar4 + 1) / 2 << 2));

        param_4 = param_4 + param_5;

        param_6 = param_6 + param_7;

        param_2 = param_2 + -1;

      } while (param_2 != 0);

    }

  }

  else {

    if (param_2 != 0) {

      iVar5 = param_2;

      do {

        FUN_1402f8e20(param_6,param_4,uVar4);

        param_4 = param_4 + param_5;

        param_6 = param_6 + param_7;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

      uVar4 = (ulonglong)param_1;

    }

    iVar5 = (int)uVar4;

    if ((param_3 == 0x32315659) || (param_3 == 0x56555949)) {

      iVar2 = ((param_2 + 1) / 2) * 2;

      if (iVar2 != 0) {

        do {

          FUN_1402f8e20(param_6,param_4,(longlong)((iVar5 + 1) / 2));

          param_4 = param_4 + (param_5 + 1) / 2;

          param_6 = param_6 + (param_7 + 1) / 2;

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

        return 1;

      }

    }

    else if ((param_3 == 0x3231564e) || (param_3 == 0x3132564e)) {

      iVar2 = (param_2 + 1) / 2;

      if (iVar2 != 0) {

        do {

          FUN_1402f8e20(param_6,param_4,(longlong)(((iVar5 + 1) / 2) * 2));

          param_4 = param_4 + ((param_5 + 1) / 2) * 2;

          param_6 = param_6 + ((param_7 + 1) / 2) * 2;

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

        return 1;

      }

    }

    else if (param_3 == 0x30313050) {

      iVar2 = (param_2 + 1) / 2;

      if (iVar2 != 0) {

        do {

          FUN_1402f8e20(param_6,param_4,(longlong)(((iVar5 + 1) / 2) * 2) * 2);

          param_4 = param_4 + ((param_5 + 1) / 2) * 2;

          param_6 = param_6 + ((param_7 + 1) / 2) * 2;

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

        return 1;

      }

    }

  }

  return 1;

}




