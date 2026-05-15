// Address: 0x14013de30
// Ghidra name: FUN_14013de30
// ============ 0x14013de30 FUN_14013de30 (size=478) ============


ulonglong FUN_14013de30(undefined8 *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  char cVar5;

  byte bVar6;

  short sVar7;

  uint uVar8;

  uint uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  uint uVar12;

  ulonglong uVar13;

  bool bVar14;

  

  uVar10 = 0;

  FUN_140159d30();

  if ((param_1 == (undefined8 *)0x0) ||

     (((DAT_1403e3d60 != '\0' && (cVar5 = FUN_1401aa7c0(param_1,5), cVar5 == '\0')) ||

      (cVar5 = FUN_1401596f0(*param_1), cVar5 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

    FUN_14015bb10();

    return 0;

  }

  uVar9 = 0;

  uVar11 = uVar10;

  uVar13 = uVar10;

  if (0 < *(int *)(param_1 + 5)) {

    do {

      lVar4 = param_1[6];

      if ((*(int *)(lVar4 + 0x10 + uVar11) == 2) && (*(int *)(lVar4 + 0x14 + uVar11) == param_2)) {

        iVar1 = *(int *)(lVar4 + uVar11);

        uVar12 = uVar9;

        if (iVar1 == 2) {

          sVar7 = FUN_140157ea0(*param_1,*(undefined4 *)(lVar4 + 4 + uVar11));

          iVar1 = *(int *)(lVar4 + 0xc + uVar11);

          iVar2 = *(int *)(lVar4 + 8 + uVar11);

          uVar8 = (uint)sVar7;

          if (iVar2 < iVar1) {

            iVar3 = iVar1;

            if ((int)uVar8 < iVar2) goto LAB_14013df04;

LAB_14013defd:

            bVar14 = true;

            if (iVar3 < (int)uVar8) goto LAB_14013df04;

          }

          else {

            iVar3 = iVar2;

            if (iVar1 <= (int)uVar8) goto LAB_14013defd;

LAB_14013df04:

            bVar14 = false;

          }

          if ((bVar14) &&

             ((iVar3 = *(int *)(lVar4 + 0x18 + uVar11), iVar2 != iVar3 ||

              (uVar12 = uVar8, iVar1 != *(int *)(lVar4 + 0x1c + uVar11))))) {

            uVar12 = (int)(((float)(int)(uVar8 - iVar2) / (float)(iVar1 - iVar2)) *

                          (float)(*(int *)(lVar4 + 0x1c + uVar11) - iVar3)) + iVar3;

          }

        }

        else if (iVar1 == 1) {

          cVar5 = FUN_140158030(*param_1,*(undefined4 *)(lVar4 + 4 + uVar11));

          bVar14 = cVar5 == '\0';

LAB_14013df7c:

          if (!bVar14) {

            uVar12 = *(uint *)(lVar4 + 0x1c + uVar11);

          }

        }

        else if (iVar1 == 3) {

          bVar6 = FUN_140158660(*param_1,*(undefined4 *)(lVar4 + 4 + uVar11));

          bVar14 = (*(uint *)(lVar4 + 8 + uVar11) & (uint)bVar6) == 0;

          goto LAB_14013df7c;

        }

        iVar1 = *(int *)(lVar4 + 0x1c + uVar11);

        iVar2 = *(int *)(lVar4 + 0x18 + uVar11);

        if (iVar2 < iVar1) {

          if ((int)uVar12 < iVar2) goto LAB_14013dfa3;

LAB_14013df9c:

          bVar14 = true;

          if (iVar1 < (int)uVar12) goto LAB_14013dfa3;

        }

        else {

          bVar14 = iVar1 <= (int)uVar12;

          iVar1 = iVar2;

          if (bVar14) goto LAB_14013df9c;

LAB_14013dfa3:

          bVar14 = false;

        }

        if ((uVar12 != 0) && (bVar14)) {

          uVar10 = (ulonglong)(uVar12 & 0xffff);

          break;

        }

      }

      uVar12 = (int)uVar13 + 1;

      uVar11 = uVar11 + 0x20;

      uVar13 = (ulonglong)uVar12;

    } while ((int)uVar12 < *(int *)(param_1 + 5));

  }

  FUN_14015bb10();

  return uVar10;

}




