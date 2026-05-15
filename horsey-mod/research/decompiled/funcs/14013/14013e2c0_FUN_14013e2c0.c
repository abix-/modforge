// Address: 0x14013e2c0
// Ghidra name: FUN_14013e2c0
// ============ 0x14013e2c0 FUN_14013e2c0 (size=382) ============


ulonglong FUN_14013e2c0(undefined8 *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  char cVar4;

  byte bVar5;

  short sVar6;

  int iVar7;

  ulonglong uVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  bool bVar12;

  bool bVar13;

  

  bVar13 = false;

  FUN_140159d30();

  if ((param_1 == (undefined8 *)0x0) ||

     (((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(param_1,5), cVar4 == '\0')) ||

      (cVar4 = FUN_1401596f0(*param_1), cVar4 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

    uVar8 = FUN_14015bb10();

    return uVar8 & 0xffffffffffffff00;

  }

  iVar9 = 0;

  if (0 < *(int *)(param_1 + 5)) {

    lVar11 = 0;

    do {

      lVar3 = param_1[6];

      if ((*(int *)(lVar3 + 0x10 + lVar11) == 1) && (*(int *)(lVar3 + 0x14 + lVar11) == param_2)) {

        iVar1 = *(int *)(lVar3 + lVar11);

        if (iVar1 == 2) {

          sVar6 = FUN_140157ea0(*param_1,*(undefined4 *)(lVar3 + 4 + lVar11));

          iVar1 = *(int *)(lVar3 + 8 + lVar11);

          iVar2 = *(int *)(lVar3 + 0xc + lVar11);

          iVar10 = (int)sVar6;

          iVar7 = (iVar2 - iVar1) / 2 + iVar1;

          if (iVar1 < iVar2) {

            if ((iVar1 <= iVar10) && (iVar10 <= iVar2)) {

              bVar12 = iVar7 <= iVar10;

LAB_14013e3e1:

              bVar13 = !bVar12 && bVar13 == false;

              goto LAB_14013e3e7;

            }

          }

          else if ((iVar2 <= iVar10) && (iVar10 <= iVar1)) {

            bVar12 = iVar10 <= iVar7;

            goto LAB_14013e3e1;

          }

        }

        else if (iVar1 == 1) {

          cVar4 = FUN_140158030(*param_1,*(undefined4 *)(lVar3 + 4 + lVar11));

          bVar13 = cVar4 == '\0' && bVar13 == false;

LAB_14013e3e7:

          bVar13 = !bVar13;

        }

        else if (iVar1 == 3) {

          bVar5 = FUN_140158660(*param_1,*(undefined4 *)(lVar3 + 4 + lVar11));

          bVar12 = (*(uint *)(lVar3 + 8 + lVar11) & (uint)bVar5) != 0;

          goto LAB_14013e3e1;

        }

      }

      iVar9 = iVar9 + 1;

      lVar11 = lVar11 + 0x20;

    } while (iVar9 < *(int *)(param_1 + 5));

  }

  FUN_14015bb10();

  return (ulonglong)bVar13;

}




