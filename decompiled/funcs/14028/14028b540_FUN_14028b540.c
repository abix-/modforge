// Address: 0x14028b540
// Ghidra name: FUN_14028b540
// ============ 0x14028b540 FUN_14028b540 (size=1149) ============


int FUN_14028b540(longlong param_1)



{

  ushort *puVar1;

  undefined8 *puVar2;

  ushort uVar3;

  char cVar4;

  int iVar5;

  ulonglong uVar6;

  longlong lVar7;

  int iVar8;

  ushort *puVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  int iVar14;

  longlong lVar15;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  

  uVar6 = FUN_140149350();

  puVar9 = (ushort *)(param_1 + 8);

  iVar13 = *(int *)(param_1 + 0xa48);

  iVar14 = 0;

  local_98 = 0;

  uStack_90 = 0;

  local_98._0_4_ = 0;

  lVar15 = 0;

  local_88 = 0;

  uStack_80 = 0;

  local_78 = 0;

  uStack_70 = 0;

  local_68 = 0;

  uStack_60 = 0;

  uVar10 = (uint)(*(int *)(param_1 + 0xa50) * *(int *)(param_1 + 0xa4c)) / 0xffff;

  local_58 = 0;

  uStack_50 = 0;

  local_48 = 0;

  uStack_40 = 0;

  iVar8 = (int)local_98;

  do {

    if (iVar13 == 0) break;

    if ((*(uint *)(puVar9 + 0x30) & 1) != 0) {

      iVar13 = iVar13 + -1;

      if ((*(uint *)(puVar9 + 0x30) & 2) != 0) {

        iVar5 = FUN_14028af90(puVar9);

        if ((iVar5 != 0) && (*(ulonglong *)(puVar9 + 0x2c) <= uVar6)) {

          puVar1 = puVar9 + 0x40;

          *(int *)puVar1 = *(int *)puVar1 + -1;

          puVar9[0x30] = 0;

          puVar9[0x31] = 0;

          if (*(int *)puVar1 == 0) {

            *(int *)(param_1 + 0xa48) = *(int *)(param_1 + 0xa48) + -1;

            goto LAB_14028b6a8;

          }

          puVar9[0x30] = 1;

          puVar9[0x31] = 0;

          *(ulonglong *)(puVar9 + 0x24) = *(ulonglong *)(puVar9 + 0x2c);

        }

      }

      FUN_14028bcf0(puVar9,uVar6);

      if ((puVar9[0x30] & 4) != 0) {

        uVar3 = *puVar9;

        if ((uVar3 == 2) ||

           ((uVar3 < 0x21 && ((0x100010110U >> ((ulonglong)uVar3 & 0x3f) & 1) != 0)))) {

          iVar5 = FUN_14028b0a0(puVar9);

        }

        else if (uVar3 == 1) {

          iVar5 = FUN_14028b000(puVar9);

        }

        else {

          if (uVar3 != 0x40) {

            if (uVar3 == 0x80) {

              FUN_14028b330(puVar9,&uStack_80);

              iVar8 = (int)local_98;

            }

            else if (uVar3 == 0x100) {

              FUN_14028b310(puVar9,&local_68);

              iVar8 = (int)local_98;

            }

            else if (uVar3 == 0x400) {

              FUN_14028b310(puVar9,&uStack_50);

              iVar8 = (int)local_98;

            }

            goto LAB_14028b6a8;

          }

          iVar5 = FUN_14028b250(puVar9);

        }

        iVar8 = iVar8 + iVar5;

        local_98 = CONCAT44(local_98._4_4_,iVar8);

      }

    }

LAB_14028b6a8:

    lVar15 = lVar15 + 1;

    puVar9 = puVar9 + 0x4c;

  } while (lVar15 < 0x10);

  uVar6 = (ulonglong)(uVar10 & 0xffff);

  uVar10 = uVar10 & 0xffff;

  lVar15 = (longlong)iVar8 * uVar6 +

           SUB168(SEXT816(-0x7fff7fff7fff7fff) * SEXT816((longlong)((longlong)iVar8 * uVar6)),8);

  iVar8 = (int)(lVar15 >> 0xf) - (int)(lVar15 >> 0x3f);

  local_98 = CONCAT44(local_98._4_4_,iVar8);

  lVar15 = SUB168(SEXT816(-0x7fff7fff7fff7fff) *

                  SEXT816((longlong)((longlong)local_78._4_4_ * uVar6)),8) +

           (longlong)local_78._4_4_ * uVar6;

  local_78 = CONCAT44((int)(lVar15 >> 0xf) - (int)(lVar15 >> 0x3f),(undefined4)local_78);

  lVar15 = SUB168(SEXT816(-0x7fff7fff7fff7fff) *

                  SEXT816((longlong)((longlong)(int)uStack_70 * uVar6)),8) +

           (longlong)(int)uStack_70 * uVar6;

  uVar12 = (((uint)(uStack_70._4_4_ * *(int *)(param_1 + 0xa54)) / 100) * uVar10) / 0xffff;

  lVar7 = SUB168(SEXT816(-0x7fff7fff7fff7fff) *

                 SEXT816((longlong)((longlong)uStack_60._4_4_ * uVar6)),8) +

          (longlong)uStack_60._4_4_ * uVar6;

  uStack_70 = CONCAT44(uVar12,(int)(lVar15 >> 0xf) - (int)(lVar15 >> 0x3f));

  uStack_60 = CONCAT44((int)(lVar7 >> 0xf) - (int)(lVar7 >> 0x3f),(undefined4)uStack_60);

  lVar15 = SUB168(SEXT816(-0x7fff7fff7fff7fff) *

                  SEXT816((longlong)((longlong)(int)local_58 * uVar6)),8) +

           (longlong)(int)local_58 * uVar6;

  uVar11 = (((uint)(local_58._4_4_ * *(int *)(param_1 + 0xa58)) / 100) * uVar10) / 0xffff;

  local_58 = CONCAT44(uVar11,(int)(lVar15 >> 0xf) - (int)(lVar15 >> 0x3f));

  lVar15 = SUB168(SEXT816(-0x7fff7fff7fff7fff) *

                  SEXT816((longlong)((longlong)local_48._4_4_ * uVar6)),8) +

           (longlong)local_48._4_4_ * uVar6;

  local_48 = CONCAT44((int)(lVar15 >> 0xf) - (int)(lVar15 >> 0x3f),(undefined4)local_48);

  lVar15 = SUB168(SEXT816(-0x7fff7fff7fff7fff) *

                  SEXT816((longlong)((longlong)(int)uStack_40 * uVar6)),8) +

           (longlong)(int)uStack_40 * uVar6;

  uVar10 = (((uint)(uStack_40._4_4_ * *(int *)(param_1 + 0xa5c)) / 100) * uVar10) / 0xffff;

  uStack_40 = CONCAT44(uVar10,(int)(lVar15 >> 0xf) - (int)(lVar15 >> 0x3f));

  iVar13 = -iVar8;

  if (-iVar8 < 0) {

    iVar13 = iVar8;

  }

  iVar13 = iVar13 + (uVar10 * 0x7fff) / 0xffff + (uVar11 * 0x7fff) / 0xffff +

           (uVar12 * 0x7fff) / 0xffff;

  if (*(int *)(param_1 + 0xa60) < iVar13) {

    *(int *)(param_1 + 0xa60) = iVar13;

  }

  FUN_14028b9c0(param_1 + 0x988,&local_98);

  puVar2 = (undefined8 *)(param_1 + 0xa68);

  if (*(char *)(param_1 + 0x9b0) != '\0') {

    cVar4 = FUN_14015adf0(*puVar2,param_1 + 0x9a4,7);

    *(undefined1 *)(param_1 + 0x9b0) = 0;

    iVar14 = (cVar4 != '\0') - 1;

  }

  FUN_14028b9c0(param_1 + 0x9b8,&uStack_80);

  iVar13 = -1;

  if (*(char *)(param_1 + 0x9e0) != '\0') {

    cVar4 = FUN_14015adf0(*puVar2,param_1 + 0x9d4,7);

    *(undefined1 *)(param_1 + 0x9e0) = 0;

    if (cVar4 == '\0') {

      iVar14 = iVar13;

    }

  }

  FUN_14028b9c0(param_1 + 0x9e8,&local_68);

  if (*(char *)(param_1 + 0xa10) != '\0') {

    cVar4 = FUN_14015adf0(*puVar2,param_1 + 0xa04,7);

    if (cVar4 == '\0') {

      iVar14 = iVar13;

    }

    *(undefined1 *)(param_1 + 0xa10) = 0;

  }

  FUN_14028b9c0(param_1 + 0xa18,&uStack_50);

  if (*(char *)(param_1 + 0xa40) != '\0') {

    cVar4 = FUN_14015adf0(*(undefined8 *)(param_1 + 0xa68),param_1 + 0xa34,7);

    *(undefined1 *)(param_1 + 0xa40) = 0;

    if (cVar4 == '\0') {

      iVar14 = iVar13;

    }

  }

  return iVar14;

}




