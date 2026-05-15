// Address: 0x1401d4490
// Ghidra name: FUN_1401d4490
// ============ 0x1401d4490 FUN_1401d4490 (size=781) ============


undefined8

FUN_1401d4490(int param_1,int param_2,int param_3,longlong param_4,int param_5,longlong *param_6,

             longlong *param_7,longlong *param_8,int *param_9,int *param_10)



{

  int iVar1;

  undefined8 uVar2;

  longlong lVar3;

  longlong lVar4;

  

  lVar4 = 0;

  if (param_3 < 0x3259555a) {

    if (param_3 == 0x32595559) {

LAB_1401d4689:

      *param_6 = param_4;

      *param_9 = param_5;

      *param_8 = *param_6 + 3;

      lVar4 = *param_6 + 1;

      param_8 = param_7;

      iVar1 = param_5;

    }

    else {

      if (param_3 == 0x30313050) {

        iVar1 = (param_1 + 1) / 2 << 2;

        if (iVar1 < param_5) {

          iVar1 = param_5;

        }

        lVar3 = param_2 * param_5 + param_4;

      }

      else {

        if ((param_3 != 0x3132564e) && (param_3 != 0x3231564e)) {

          if (param_3 != 0x32315659) goto LAB_1401d4616;

          goto LAB_1401d44f2;

        }

        iVar1 = ((param_5 + 1) / 2) * 2;

        lVar3 = param_2 * param_5 + param_4;

LAB_1401d4533:

        if (param_3 != 0x30313050) {

          if (param_3 == 0x3132564e) {

            lVar4 = lVar3 + 1;

            *param_6 = param_4;

            *param_9 = param_5;

            *param_8 = lVar3;

            param_8 = param_7;

          }

          else {

            if (param_3 != 0x3231564e) {

              if (param_3 != 0x32315659) {

LAB_1401d46d5:

                uVar2 = FUN_14017af90(param_3);

                uVar2 = FUN_14012e850("GetYUVPlanes[2]: Unsupported YUV format: %s",uVar2);

                return uVar2;

              }

              *param_6 = param_4;

              *param_9 = param_5;

              *param_8 = lVar3;

              *param_7 = lVar4;

              goto LAB_1401d4780;

            }

            lVar4 = lVar3 + 1;

            *param_6 = param_4;

            *param_9 = param_5;

            *param_7 = lVar3;

          }

          goto LAB_1401d477d;

        }

      }

      lVar4 = lVar3 + 2;

      *param_6 = param_4;

      *param_9 = param_5;

      *param_7 = lVar3;

    }

  }

  else if (param_3 == 0x55595659) {

LAB_1401d474d:

    *param_6 = param_4;

    *param_9 = param_5;

    *param_8 = *param_6 + 1;

    lVar4 = *param_6 + 3;

    param_8 = param_7;

    iVar1 = param_5;

  }

  else {

    if (param_3 == 0x56555949) {

LAB_1401d44f2:

      iVar1 = (param_5 + 1) / 2;

      lVar3 = param_2 * param_5 + param_4;

      lVar4 = (longlong)(((param_2 + 1) / 2) * iVar1) + (longlong)(param_2 * param_5) + param_4;

      if (param_3 < 0x3259555a) {

        if (param_3 != 0x32595559) goto LAB_1401d4533;

        goto LAB_1401d4689;

      }

      if (param_3 == 0x55595659) goto LAB_1401d474d;

      if (param_3 == 0x56555949) {

        *param_6 = param_4;

        *param_9 = param_5;

        *param_8 = lVar4;

        *param_7 = lVar3;

        goto LAB_1401d4780;

      }

      if (param_3 != 0x59565955) goto LAB_1401d46d5;

    }

    else if (param_3 != 0x59565955) {

LAB_1401d4616:

      uVar2 = FUN_14017af90(param_3);

      uVar2 = FUN_14012e850("GetYUVPlanes(): Unsupported YUV format: %s",uVar2);

      return uVar2;

    }

    *param_6 = param_4 + 1;

    *param_9 = param_5;

    *param_8 = *param_6 + 1;

    lVar4 = *param_6 + -1;

    param_8 = param_7;

    iVar1 = param_5;

  }

LAB_1401d477d:

  *param_8 = lVar4;

LAB_1401d4780:

  *param_10 = iVar1;

  return 1;

}




