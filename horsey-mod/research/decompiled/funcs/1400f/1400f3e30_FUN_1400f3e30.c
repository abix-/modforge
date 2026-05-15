// Address: 0x1400f3e30
// Ghidra name: FUN_1400f3e30
// ============ 0x1400f3e30 FUN_1400f3e30 (size=482) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400f3e30(longlong param_1,int param_2,uint *param_3,uint param_4)



{

  undefined4 *puVar1;

  short sVar2;

  short sVar3;

  char cVar4;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  char *pcVar12;

  uint uVar13;

  undefined4 *puVar14;

  longlong lVar15;

  uint uVar16;

  uint uVar17;

  int iVar18;

  int iVar19;

  int iVar20;

  short sVar21;

  uint uVar22;

  uint uVar25;

  uint uVar26;

  uint uVar27;

  char cVar5;

  char cVar6;

  char cVar7;

  undefined4 uVar23;

  undefined6 uVar24;

  

  uVar11 = _UNK_14031028c;

  uVar10 = _UNK_140310288;

  uVar9 = _UNK_140310284;

  uVar8 = _DAT_140310280;

  uVar13 = 0;

  uVar22 = 0;

  for (; param_3 != (uint *)0x0; param_3 = *(uint **)(param_3 + 4)) {

    uVar25 = *param_3;

    uVar17 = param_3[6];

    uVar16 = uVar25;

    if ((uVar22 != 0) && (uVar17 = uVar22 + uVar17, uVar16 = uVar13, uVar17 == 0)) {

      iVar20 = (int)uVar13 >> 10;

      iVar18 = (int)uVar25 >> 10;

      if ((iVar20 < param_2) && (-1 < iVar18)) {

        if (iVar20 == iVar18) {

          *(char *)(iVar20 + param_1) =

               *(char *)(iVar20 + param_1) + (char)((int)((uVar25 - uVar13) * param_4) >> 10);

        }

        else {

          if (iVar20 < 0) {

            iVar20 = -1;

          }

          else {

            *(char *)(iVar20 + param_1) =

                 *(char *)(iVar20 + param_1) +

                 (char)((int)((0x400 - (uVar13 & 0x3ff)) * param_4) >> 10);

          }

          iVar19 = param_2;

          if (iVar18 < param_2) {

            *(char *)(iVar18 + param_1) =

                 *(char *)(iVar18 + param_1) + (char)((int)((uVar25 & 0x3ff) * param_4) >> 10);

            iVar19 = iVar18;

          }

          iVar20 = iVar20 + 1;

          if ((iVar20 < iVar19) && (0xf < (uint)(iVar19 - iVar20))) {

            uVar13 = iVar19 - iVar20 & 0x8000000f;

            if ((int)uVar13 < 0) {

              uVar13 = (uVar13 - 1 | 0xfffffff0) + 1;

            }

            uVar22 = param_4 & uVar8;

            uVar25 = param_4 & uVar9;

            uVar26 = param_4 & uVar10;

            uVar27 = param_4 & uVar11;

            sVar2 = (short)uVar22;

            cVar4 = (0 < sVar2) * (sVar2 < 0x100) * (char)uVar22 - (0xff < sVar2);

            sVar2 = (short)(uVar22 >> 0x10);

            sVar21 = CONCAT11((0 < sVar2) * (sVar2 < 0x100) * (char)(uVar22 >> 0x10) -

                              (0xff < sVar2),cVar4);

            sVar2 = (short)uVar25;

            cVar5 = (0 < sVar2) * (sVar2 < 0x100) * (char)uVar25 - (0xff < sVar2);

            sVar2 = (short)(uVar25 >> 0x10);

            uVar23 = CONCAT13((0 < sVar2) * (sVar2 < 0x100) * (char)(uVar25 >> 0x10) -

                              (0xff < sVar2),CONCAT12(cVar5,sVar21));

            sVar2 = (short)uVar26;

            cVar6 = (0 < sVar2) * (sVar2 < 0x100) * (char)uVar26 - (0xff < sVar2);

            sVar2 = (short)(uVar26 >> 0x10);

            uVar24 = CONCAT15((0 < sVar2) * (sVar2 < 0x100) * (char)(uVar26 >> 0x10) -

                              (0xff < sVar2),CONCAT14(cVar6,uVar23));

            sVar2 = (short)uVar27;

            cVar7 = (0 < sVar2) * (sVar2 < 0x100) * (char)uVar27 - (0xff < sVar2);

            sVar3 = (short)(uVar27 >> 0x10);

            cVar4 = (0 < sVar21) * (sVar21 < 0x100) * cVar4 - (0xff < sVar21);

            sVar2 = (short)((uint)uVar23 >> 0x10);

            cVar5 = (0 < sVar2) * (sVar2 < 0x100) * cVar5 - (0xff < sVar2);

            sVar2 = (short)((uint6)uVar24 >> 0x20);

            cVar6 = (0 < sVar2) * (sVar2 < 0x100) * cVar6 - (0xff < sVar2);

            sVar2 = (short)(CONCAT17((0 < sVar3) * (sVar3 < 0x100) * (char)(uVar27 >> 0x10) -

                                     (0xff < sVar3),CONCAT16(cVar7,uVar24)) >> 0x30);

            cVar7 = (0 < sVar2) * (sVar2 < 0x100) * cVar7 - (0xff < sVar2);

            puVar14 = (undefined4 *)(param_1 + 8 + (longlong)iVar20);

            do {

              uVar23 = puVar14[-2];

              puVar1 = puVar14 + 4;

              puVar14[-2] = CONCAT13(cVar7 + (char)((uint)uVar23 >> 0x18),

                                     CONCAT12(cVar6 + (char)((uint)uVar23 >> 0x10),

                                              CONCAT11(cVar5 + (char)((uint)uVar23 >> 8),

                                                       cVar4 + (char)uVar23)));

              iVar20 = iVar20 + 0x10;

              uVar23 = puVar14[-1];

              puVar14[-1] = CONCAT13((char)((uint)uVar23 >> 0x18) + cVar7,

                                     CONCAT12((char)((uint)uVar23 >> 0x10) + cVar6,

                                              CONCAT11((char)((uint)uVar23 >> 8) + cVar5,

                                                       (char)uVar23 + cVar4)));

              uVar23 = *puVar14;

              *puVar14 = CONCAT13(cVar7 + (char)((uint)uVar23 >> 0x18),

                                  CONCAT12(cVar6 + (char)((uint)uVar23 >> 0x10),

                                           CONCAT11(cVar5 + (char)((uint)uVar23 >> 8),

                                                    cVar4 + (char)uVar23)));

              uVar23 = puVar14[1];

              puVar14[1] = CONCAT13(cVar7 + (char)((uint)uVar23 >> 0x18),

                                    CONCAT12(cVar6 + (char)((uint)uVar23 >> 0x10),

                                             CONCAT11(cVar5 + (char)((uint)uVar23 >> 8),

                                                      cVar4 + (char)uVar23)));

              puVar14 = puVar1;

            } while ((-8 - param_1) + (longlong)puVar1 < (longlong)(int)(iVar19 - uVar13));

          }

          lVar15 = (longlong)iVar20;

          if (lVar15 < iVar19) {

            pcVar12 = (char *)(lVar15 + param_1);

            lVar15 = iVar19 - lVar15;

            do {

              *pcVar12 = *pcVar12 + (char)param_4;

              pcVar12 = pcVar12 + 1;

              lVar15 = lVar15 + -1;

            } while (lVar15 != 0);

          }

        }

      }

    }

    uVar13 = uVar16;

    uVar22 = uVar17;

  }

  return;

}




