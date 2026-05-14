// Address: 0x1400f4310
// Ghidra name: FUN_1400f4310
// ============ 0x1400f4310 FUN_1400f4310 (size=591) ============


undefined8

FUN_1400f4310(longlong param_1,uint param_2,longlong param_3,int param_4,int param_5,int param_6)



{

  uint uVar1;

  int iVar2;

  ulonglong uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  int iVar9;

  uint uVar10;

  

  lVar8 = (ulonglong)param_2 + param_1;

  iVar4 = 0;

  iVar9 = (uint)*(byte *)(lVar8 + 3) + (uint)*(byte *)(lVar8 + 2) * 0x100;

  iVar7 = (uint)*(byte *)(lVar8 + 5) + (uint)*(byte *)(lVar8 + 4) * 0x100 + param_2;

  if (iVar9 != 0) {

LAB_1400f4370:

    do {

      uVar1 = iVar4 * 0xc + 6 + param_2;

      uVar3 = (ulonglong)uVar1;

      if ((uint)*(byte *)((ulonglong)uVar1 + 6 + param_1) * 0x100 +

          (uint)*(byte *)(uVar3 + 7 + param_1) == param_5) {

        uVar1 = (uint)*(byte *)(uVar3 + 3 + param_1);

        uVar10 = (uint)*(byte *)(uVar3 + 2 + param_1);

        iVar5 = (uint)*(byte *)(uVar3 + 1 + param_1) + (uint)*(byte *)(uVar3 + param_1) * 0x100;

        if ((iVar5 == 0) ||

           ((iVar2 = uVar10 * 0x100, iVar5 == 3 && ((uVar1 + iVar2 == 1 || (iVar2 + uVar1 == 10)))))

           ) {

          iVar2 = FUN_1400f39f0(param_3,param_4,

                                (ulonglong)*(byte *)(uVar3 + 0xb + param_1) +

                                (ulonglong)*(byte *)(uVar3 + 10 + param_1) * 0x100 + (longlong)iVar7

                                + param_1,

                                (uint)*(byte *)(uVar3 + 8 + param_1) * 0x100 +

                                (uint)*(byte *)(uVar3 + 9 + param_1));

          if (-1 < iVar2) {

            if ((((iVar4 + 1 < iVar9) &&

                 ((uint)*(byte *)(uVar3 + 0x13 + param_1) +

                  (uint)*(byte *)(uVar3 + 0x12 + param_1) * 0x100 == param_6)) &&

                ((uint)*(byte *)(uVar3 + 0xc + param_1) * 0x100 +

                 (uint)*(byte *)(uVar3 + 0xd + param_1) == iVar5)) &&

               (((uint)*(byte *)(uVar3 + 0xe + param_1) * 0x100 +

                 (uint)*(byte *)(uVar3 + 0xf + param_1) == uVar10 * 0x100 + uVar1 &&

                ((uint)*(byte *)(uVar3 + 0x10 + param_1) * 0x100 +

                 (uint)*(byte *)(uVar3 + 0x11 + param_1) ==

                 (uint)*(byte *)(uVar3 + 4 + param_1) * 0x100 + (uint)*(byte *)(uVar3 + 5 + param_1)

                )))) {

              if ((uint)*(byte *)(uVar3 + 0x14 + param_1) * 0x100 +

                  (uint)*(byte *)(uVar3 + 0x15 + param_1) == 0) {

                if (iVar2 == param_4) {

                  return 1;

                }

              }

              else if (((iVar2 < param_4) && (*(char *)(iVar2 + param_3) == ' ')) &&

                      (iVar6 = param_4 - (iVar2 + 1),

                      iVar5 = FUN_1400f39f0((iVar2 + 1) + param_3,iVar6,

                                            (ulonglong)*(byte *)(uVar3 + 0x16 + param_1) * 0x100 +

                                            (ulonglong)*(byte *)(uVar3 + 0x17 + param_1) +

                                            (longlong)iVar7 + param_1), iVar6 == iVar5)) {

                return 1;

              }

              iVar4 = iVar4 + 1;

              goto LAB_1400f4370;

            }

            if (iVar2 == param_4) {

              return 1;

            }

          }

        }

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < iVar9);

  }

  return 0;

}




