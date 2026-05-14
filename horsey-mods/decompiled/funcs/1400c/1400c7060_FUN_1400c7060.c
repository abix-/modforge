// Address: 0x1400c7060
// Ghidra name: FUN_1400c7060
// ============ 0x1400c7060 FUN_1400c7060 (size=695) ============


void FUN_1400c7060(void)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  undefined8 *puVar4;

  char *pcVar5;

  uint uVar6;

  int iVar7;

  ulonglong uVar8;

  longlong lVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  longlong lVar13;

  ulonglong uVar14;

  int local_res8 [4];

  char local_58 [8];

  ulonglong uStack_50;

  undefined8 local_48;

  undefined8 local_40;

  ulonglong uVar9;

  

  local_res8[0] = 0;

  local_48 = 9;

  local_40 = 0xf;

  local_58 = (char  [8])s_names_txt_14030e140._0_8_;

  uStack_50 = (ulonglong)(byte)s_names_txt_14030e140[8];

  DAT_1403f34a0 = (char *)FUN_1400c43d0(local_58,local_res8);

  if ((ulonglong)((longlong)DAT_1403f3508 - (longlong)DAT_1403f34f8 >> 3) < 5000) {

    lVar10 = (longlong)DAT_1403f3500 - (longlong)DAT_1403f34f8;

    lVar2 = FUN_1402c704c();

    if (lVar2 == 0) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    uVar8 = lVar2 + 0x27U & 0xffffffffffffffe0;

    *(longlong *)(uVar8 - 8) = lVar2;

    FUN_1402f8e20(uVar8,DAT_1403f34f8,(longlong)DAT_1403f3500 - (longlong)DAT_1403f34f8);

    FUN_140037380(&DAT_1403f34f8,uVar8,lVar10 >> 3,5000);

  }

  uVar8 = 3;

  if (*DAT_1403f34a0 != -0x11) {

    uVar8 = 0;

  }

  pcVar5 = DAT_1403f34a0;

  uVar9 = uVar8;

  uVar11 = uVar8;

  iVar1 = local_res8[0];

  if ((int)uVar8 < local_res8[0]) {

LAB_1400c7174:

    do {

      puVar4 = DAT_1403f3500;

      if (pcVar5[uVar11] != '\r') {

        uVar6 = (int)uVar9 + 1;

        uVar9 = (ulonglong)uVar6;

        uVar11 = uVar11 + 1;

        if ((int)uVar6 < iVar1) goto LAB_1400c7174;

      }

      iVar7 = (int)uVar9;

      if ((int)uVar8 < iVar7) {

        if (DAT_1403f3500 == DAT_1403f3508) {

          lVar2 = (longlong)DAT_1403f3500 - (longlong)DAT_1403f34f8 >> 3;

          if (lVar2 == 0x1fffffffffffffff) {

                    /* WARNING: Subroutine does not return */

            FUN_14002f0d0();

          }

          uVar12 = lVar2 + 1;

          uVar3 = (longlong)DAT_1403f3508 - (longlong)DAT_1403f34f8 >> 3;

          if (0x1fffffffffffffff - (uVar3 >> 1) < uVar3) {

            uVar14 = 0x1fffffffffffffff;

          }

          else {

            uVar3 = (uVar3 >> 1) + uVar3;

            uVar14 = uVar12;

            if (uVar12 <= uVar3) {

              uVar14 = uVar3;

            }

            if (0x1fffffffffffffff < uVar14) {

                    /* WARNING: Subroutine does not return */

              FUN_140024090();

            }

          }

          lVar10 = FUN_1400285e0(uVar14 * 8);

          *(char **)(lVar10 + lVar2 * 8) = pcVar5 + (int)uVar8;

          if (puVar4 == DAT_1403f3500) {

            lVar13 = (longlong)DAT_1403f3500 - (longlong)DAT_1403f34f8;

            lVar2 = lVar10;

            puVar4 = DAT_1403f34f8;

          }

          else {

            FUN_1402f8e20(lVar10,DAT_1403f34f8,(longlong)puVar4 - (longlong)DAT_1403f34f8);

            lVar13 = (longlong)DAT_1403f3500 - (longlong)puVar4;

            lVar2 = lVar10 + (lVar2 + 1) * 8;

          }

          FUN_1402f8e20(lVar2,puVar4,lVar13);

          FUN_140037380(&DAT_1403f34f8,lVar10,uVar12,uVar14);

          pcVar5 = DAT_1403f34a0;

          iVar1 = local_res8[0];

        }

        else {

          *DAT_1403f3500 = pcVar5 + (int)uVar8;

          DAT_1403f3500 = DAT_1403f3500 + 1;

          pcVar5 = DAT_1403f34a0;

          iVar1 = local_res8[0];

        }

      }

      if (pcVar5[uVar11 - 1] == ' ') {

        pcVar5[uVar11 - 1] = '\0';

        pcVar5 = DAT_1403f34a0;

        iVar1 = local_res8[0];

      }

      uVar8 = uVar9;

      uVar12 = uVar11;

      if (iVar7 < iVar1) {

        pcVar5[uVar11] = '\0';

        uVar6 = iVar7 + 1;

        uVar12 = uVar11 + 1;

        if ((int)uVar6 < local_res8[0]) {

          DAT_1403f34a0[uVar12] = '\0';

          uVar6 = iVar7 + 2;

          uVar12 = uVar11 + 2;

        }

        uVar8 = (ulonglong)uVar6;

        pcVar5 = DAT_1403f34a0;

        iVar1 = local_res8[0];

      }

      uVar9 = uVar8;

      uVar11 = uVar12;

    } while ((int)uVar8 < iVar1);

  }

  return;

}




