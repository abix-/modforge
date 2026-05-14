// Address: 0x1400d6560
// Ghidra name: FUN_1400d6560
// ============ 0x1400d6560 FUN_1400d6560 (size=1240) ============


void FUN_1400d6560(undefined8 param_1,longlong param_2,uint param_3,undefined8 param_4,int param_5)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  float fVar4;

  int *piVar5;

  undefined4 *puVar6;

  int iVar7;

  int iVar8;

  uint uVar9;

  longlong lVar10;

  int iVar11;

  int iVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float local_res18;

  undefined1 local_e0 [4];

  undefined1 local_dc [164];

  

  fVar4 = DAT_140303394;

  if (param_3 < 0x14) {

    iVar7 = 0;

    lVar10 = 0;

    piVar5 = (int *)(&DAT_14030e194 + (longlong)(int)param_3 * 0x44);

    do {

      if (piVar5[-1] == -1) break;

      if (*piVar5 == -1) {

        iVar7 = iVar7 + 1;

        break;

      }

      if (piVar5[1] == -1) {

        iVar7 = iVar7 + 2;

        break;

      }

      if (piVar5[2] == -1) {

        iVar7 = iVar7 + 3;

        break;

      }

      lVar10 = lVar10 + 4;

      piVar5 = piVar5 + 4;

      iVar7 = iVar7 + 4;

    } while (lVar10 < 0x10);

    iVar11 = 0;

    fVar19 = (float)(iVar7 * -2 + 1) * DAT_14030338c;

    fVar15 = DAT_14039ca50;

    fVar16 = DAT_140304c34;

    fVar18 = local_res18;

    fVar21 = local_res18;

    fVar13 = local_res18;

    do {

      uVar9 = 0;

      iVar12 = iVar7 * 2 - (uint)(iVar11 != 1);

      if (0 < iVar12) {

        iVar8 = (int)((param_5 >> 0x1f & 3U) + param_5) >> 2;

        fVar20 = fVar18;

        fVar23 = fVar13;

        do {

          fVar13 = (float)FUN_1402cdc50(((float)iVar8 * fVar15) / fVar16);

          fVar13 = fVar13 * DAT_1403033a8;

          fVar18 = (float)(int)uVar9 * DAT_14030338c + fVar19;

          fVar14 = (float)FUN_1402cdc50(((float)(iVar8 + 0x87) * fVar15) / fVar16);

          fVar14 = fVar14 * DAT_1403033a8;

          if (uVar9 != 0) {

            if (iVar11 == 1) {

              if ((uVar9 & 1) == 0) {

                fVar16 = fVar20 + DAT_140303374;

                fVar17 = (fVar23 + local_res18) * DAT_14039ca34;

                fVar20 = (fVar20 + fVar4) - DAT_140303374;

                fVar22 = fVar21 + DAT_140303374;

                fVar15 = (fVar21 + fVar4) - DAT_140303374;

                iVar2 = *(int *)(&DAT_14030e190 +

                                ((longlong)((int)(uVar9 - 1) / 2) + (longlong)(int)param_3 * 0x11) *

                                4);

                cVar1 = *(char *)((longlong)iVar2 + 0xf0 + param_2);

                puVar6 = (undefined4 *)FUN_1400a53d0(local_e0,iVar2,(int)*(char *)(iVar2 + param_2))

                ;

                FUN_140072040(fVar23,fVar22,fVar23,fVar15,fVar17,fVar20,fVar17,fVar16,*puVar6);

                puVar6 = (undefined4 *)FUN_1400a53d0(local_dc,iVar2,(int)cVar1);

                FUN_140072040(fVar17,fVar22,fVar17,fVar15,local_res18,fVar20,local_res18,fVar16,

                              *puVar6);

                fVar15 = DAT_14039ca50;

                fVar16 = DAT_140304c34;

              }

            }

            else {

              if (iVar8 % 0x168 - 0x5bU < 0xb3 == (iVar11 == 0)) {

                uVar3 = DAT_1403da850;

                if (iVar11 == 0) {

                  uVar3 = DAT_1403da7f4;

                }

                FUN_140072040(fVar23,fVar21,fVar23,fVar21 + fVar4,fVar13,fVar18 + fVar4,fVar13,

                              fVar18,uVar3);

              }

              if ((iVar8 + 0x87) % 0x168 - 0x5bU < 0xb3 == (iVar11 == 0)) {

                uVar3 = DAT_1403da840;

                if (iVar11 == 0) {

                  uVar3 = DAT_1403da7f4;

                }

                FUN_140072040(local_res18,fVar20,local_res18,fVar20 + fVar4,fVar14,fVar18 + fVar4,

                              fVar14,fVar18,uVar3);

              }

            }

          }

          uVar9 = uVar9 + 1;

          iVar8 = iVar8 + 0x18;

          fVar20 = fVar18;

          fVar21 = fVar18;

          fVar23 = fVar13;

          local_res18 = fVar14;

        } while ((int)uVar9 < iVar12);

      }

      iVar11 = iVar11 + 1;

    } while (iVar11 < 3);

  }

  return;

}




