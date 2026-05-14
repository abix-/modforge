// Address: 0x14004b750
// Ghidra name: FUN_14004b750
// ============ 0x14004b750 FUN_14004b750 (size=526) ============


void FUN_14004b750(ulonglong *param_1)



{

  longlong lVar1;

  ulonglong uVar2;

  longlong lVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined8 uVar6;

  longlong lVar7;

  int iVar8;

  longlong lVar9;

  longlong lVar10;

  ulonglong uVar11;

  uint uVar12;

  uint uVar13;

  

  param_1[4] = 0;

  *(undefined1 *)((longlong)param_1 + 9) = 0;

  uVar2 = param_1[5];

  if (uVar2 != 0) {

    iVar8 = 1;

    if (*(char *)(DAT_1403ea2a8 + 0xd0) == '\0') {

      iVar8 = *(int *)(uVar2 + 0xc);

    }

    *(int *)(uVar2 + 0xc) = *(int *)(uVar2 + 0xc) - iVar8;

  }

  if (param_1[7] == 0) {

    *(ulonglong *)(DAT_1403ea2a8 + 0xa0) = param_1[6];

  }

  else {

    *(ulonglong *)(param_1[7] + 0x30) = param_1[6];

  }

  if (param_1[6] != 0) {

    *(ulonglong *)(param_1[6] + 0x38) = param_1[7];

  }

  param_1[6] = *(ulonglong *)(DAT_1403ea2a8 + 0xa8);

  param_1[7] = 0;

  if (*(longlong *)(DAT_1403ea2a8 + 0xa8) != 0) {

    *(ulonglong **)(*(longlong *)(DAT_1403ea2a8 + 0xa8) + 0x38) = param_1;

  }

  *(ulonglong **)(DAT_1403ea2a8 + 0xa8) = param_1;

  lVar7 = DAT_1403ea2a8;

  uVar2 = *param_1;

  lVar1 = DAT_1403ea2a8 + 0x80;

  if (uVar2 != 0) {

    uVar11 = uVar2 * 0x40000 + ~uVar2;

    uVar13 = *(int *)(DAT_1403ea2a8 + 0x90) - 1;

    lVar3 = *(longlong *)(DAT_1403ea2a8 + 0x88);

    uVar11 = (uVar11 >> 0x1f ^ uVar11) * 0x15;

    uVar11 = (uVar11 >> 0xb ^ uVar11) * 0x41;

    uVar12 = ((uint)(uVar11 >> 0x16) ^ (uint)uVar11) & uVar13;

    lVar10 = (longlong)(int)uVar12;

    lVar9 = lVar10 * 0x10;

    lVar4 = *(longlong *)(lVar3 + lVar9);

    while (lVar4 != 0) {

      uVar12 = uVar12 + 1 & uVar13;

      if (*(ulonglong *)(lVar3 + lVar9) == uVar2) {

        *(undefined8 *)(lVar3 + lVar10 * 0x10) = 0;

        *(undefined8 *)(*(longlong *)(lVar7 + 0x88) + 8 + lVar10 * 0x10) = 0;

        lVar3 = *(longlong *)(lVar7 + 0x88);

        *(int *)(lVar7 + 0x94) = *(int *)(lVar7 + 0x94) + -1;

        lVar10 = (longlong)(int)uVar12 * 0x10;

        lVar4 = *(longlong *)(lVar10 + lVar3);

        while (lVar4 != 0) {

          uVar5 = *(undefined8 *)(lVar10 + lVar3);

          uVar6 = ((undefined8 *)(lVar10 + lVar3))[1];

          *(undefined8 *)(lVar10 + lVar3) = 0;

          *(undefined8 *)(lVar10 + 8 + *(longlong *)(lVar7 + 0x88)) = 0;

          *(int *)(lVar7 + 0x94) = *(int *)(lVar7 + 0x94) + -1;

          FUN_14004a250(lVar1,uVar5,uVar6);

          lVar3 = *(longlong *)(lVar7 + 0x88);

          uVar12 = uVar12 + 1 & uVar13;

          lVar10 = (longlong)(int)uVar12 * 0x10;

          lVar4 = *(longlong *)(lVar3 + lVar10);

        }

        break;

      }

      lVar10 = (longlong)(int)uVar12;

      lVar9 = lVar10 * 0x10;

      lVar4 = *(longlong *)(lVar9 + lVar3);

    }

  }

  if ((*(code **)(DAT_1403ea2a8 + 0x18) != (code *)0x0) && ((char)param_1[1] == '\0')) {

                    /* WARNING: Could not recover jumptable at 0x00014004b93a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(DAT_1403ea2a8 + 0x18))(*param_1,*(undefined8 *)(DAT_1403ea2a8 + 0x20));

    return;

  }

  if ((*(code **)(DAT_1403ea2a8 + 0x28) != (code *)0x0) && ((char)param_1[1] != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x00014004b955. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(DAT_1403ea2a8 + 0x28))(*(undefined8 *)(DAT_1403ea2a8 + 0x30));

    return;

  }

  return;

}




