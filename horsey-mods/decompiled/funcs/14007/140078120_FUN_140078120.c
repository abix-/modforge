// Address: 0x140078120
// Ghidra name: FUN_140078120
// ============ 0x140078120 FUN_140078120 (size=1087) ============


void FUN_140078120(undefined8 *param_1,uint param_2,int param_3,undefined1 *param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  char cVar3;

  ulonglong uVar4;

  undefined1 uVar5;

  longlong lVar6;

  char *pcVar7;

  undefined1 uVar8;

  int iVar9;

  uint uVar10;

  longlong lVar11;

  uint uVar12;

  undefined1 *puVar13;

  ulonglong uVar14;

  undefined1 uVar15;

  undefined1 *puVar16;

  int iVar17;

  double dVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  uint local_res10 [2];

  char local_d8 [8];

  undefined8 local_d0;

  undefined1 local_c8 [8];

  undefined2 local_c0;

  undefined1 local_be;

  undefined1 local_bd;

  longlong local_b8;

  longlong local_b0;

  ulonglong local_a8;

  

  fVar2 = DAT_14030a5d0;

  fVar1 = DAT_14030a5cc;

  uVar14 = (ulonglong)param_2;

  local_be = (undefined1)(param_2 >> 8);

  lVar11 = (longlong)param_3;

  local_c0 = 0x202;

  local_bd = (undefined1)param_2;

  local_res10[0] = param_2;

  if (param_2 - 8 < 0x7ff8) {

    local_b0 = (longlong)(int)param_2;

    if (0 < (int)param_2) {

      lVar6 = (longlong)(int)(param_2 * 2);

      local_b8 = lVar11 * 4;

      uVar4 = local_b0 - lVar6;

      puVar13 = param_4 + lVar6;

      puVar16 = param_4;

      local_d0 = uVar4;

      local_a8 = uVar14;

      do {

        if ((param_3 == 3) || (param_3 == 4)) {

          fVar20 = param_5[2];

          fVar22 = param_5[1];

          fVar21 = *param_5;

        }

        else {

          fVar20 = *param_5;

          fVar21 = fVar20;

          fVar22 = fVar20;

        }

        fVar19 = fVar22;

        if (fVar22 <= fVar20) {

          fVar19 = fVar20;

        }

        if (fVar19 < fVar21) {

          fVar19 = fVar21;

        }

        if (fVar1 <= fVar19) {

          dVar18 = (double)FUN_1402d81b0((double)fVar19,&local_b8);

          cVar3 = (char)local_b8 + -0x80;

          fVar19 = ((float)dVar18 * fVar2) / fVar19;

          uVar5 = (undefined1)(int)(fVar19 * fVar21);

          uVar15 = (undefined1)(int)(fVar19 * fVar20);

          uVar8 = (undefined1)(int)(fVar19 * fVar22);

          local_d0._0_2_ = CONCAT11(uVar8,uVar5);

          local_d0 = CONCAT62(CONCAT51(CONCAT41(local_d0._4_4_,cVar3),uVar15),(undefined2)local_d0);

        }

        else {

          cVar3 = '\0';

          local_d0 = local_d0 & 0xffffffff00000000;

          uVar15 = 0;

          uVar8 = 0;

          uVar5 = 0;

        }

        *puVar16 = uVar5;

        param_5 = param_5 + lVar11;

        puVar13[uVar4] = uVar8;

        puVar16 = puVar16 + 1;

        *puVar13 = uVar15;

        puVar13[(int)(param_2 * 3) - lVar6] = cVar3;

        puVar13 = puVar13 + 1;

        local_a8 = local_a8 - 1;

      } while (local_a8 != 0);

      uVar14 = (ulonglong)local_res10[0];

      local_a8 = 0;

    }

    lVar6 = 4;

    (*(code *)*param_1)(param_1[1],&local_c0,4);

    lVar11 = local_b0;

    do {

      uVar10 = 0;

      if (0 < (int)uVar14) {

        do {

          iVar9 = uVar10 + 2;

          iVar17 = (int)uVar14;

          uVar12 = uVar10;

          if (iVar9 < iVar17) {

            pcVar7 = param_4 + (longlong)(int)uVar10 + 2;

            do {

              if ((pcVar7[-2] == pcVar7[-1]) && (pcVar7[-2] == *pcVar7)) break;

              uVar12 = uVar12 + 1;

              iVar9 = iVar9 + 1;

              pcVar7 = pcVar7 + 1;

            } while (iVar9 < iVar17);

          }

          uVar4 = (ulonglong)uVar12;

          if (iVar17 <= (int)(uVar12 + 2)) {

            uVar4 = uVar14;

          }

          uVar12 = (uint)uVar4;

          if ((int)uVar10 < (int)uVar12) {

            do {

              iVar9 = uVar12 - uVar10;

              if (0x80 < iVar9) {

                iVar9 = 0x80;

              }

              local_d8[0] = (char)iVar9;

              (*(code *)*param_1)(param_1[1],local_d8,1);

              (*(code *)*param_1)(param_1[1],param_4 + (int)uVar10,iVar9);

              uVar10 = uVar10 + iVar9;

            } while ((int)uVar10 < (int)uVar12);

            uVar14 = (ulonglong)local_res10[0];

          }

          iVar9 = (int)uVar14;

          if ((int)(uVar12 + 2) < iVar9) {

            if ((int)uVar12 < iVar9) {

              pcVar7 = param_4 + (int)uVar12;

              do {

                uVar12 = (uint)uVar4;

                if (*pcVar7 != param_4[(int)uVar10]) break;

                uVar12 = uVar12 + 1;

                uVar4 = (ulonglong)uVar12;

                pcVar7 = pcVar7 + 1;

              } while ((int)uVar12 < iVar9);

            }

            if ((int)uVar10 < (int)uVar12) {

              do {

                local_c8[0] = param_4[(int)uVar10];

                iVar9 = uVar12 - uVar10;

                if (0x7f < (int)(uVar12 - uVar10)) {

                  iVar9 = 0x7f;

                }

                local_d8[0] = (char)iVar9 + -0x80;

                (*(code *)*param_1)(param_1[1],local_d8,1);

                (*(code *)*param_1)(param_1[1],local_c8,1);

                uVar10 = uVar10 + iVar9;

              } while ((int)uVar10 < (int)uVar12);

              uVar14 = (ulonglong)local_res10[0];

            }

          }

          lVar11 = local_b0;

        } while ((int)uVar10 < (int)uVar14);

      }

      param_4 = param_4 + lVar11;

      lVar6 = lVar6 + -1;

    } while (lVar6 != 0);

  }

  else if (0 < (int)param_2) {

    do {

      if ((param_3 == 3) || (param_3 == 4)) {

        fVar20 = param_5[2];

        fVar22 = param_5[1];

        fVar21 = *param_5;

      }

      else {

        fVar20 = *param_5;

        fVar21 = fVar20;

        fVar22 = fVar20;

      }

      fVar19 = fVar22;

      if (fVar22 <= fVar20) {

        fVar19 = fVar20;

      }

      if (fVar19 < fVar21) {

        fVar19 = fVar21;

      }

      if (fVar1 <= fVar19) {

        dVar18 = (double)FUN_1402d81b0((double)fVar19,local_res10);

        uVar4 = local_d0;

        fVar19 = ((float)dVar18 * fVar2) / fVar19;

        local_d0._0_2_ = CONCAT11((char)(int)(fVar19 * fVar22),(char)(int)(fVar19 * fVar21));

        local_d0._4_4_ = SUB84(uVar4,4);

        local_d0._0_4_ =

             CONCAT13((char)local_res10[0] + -0x80,

                      CONCAT12((char)(int)(fVar19 * fVar20),(undefined2)local_d0));

      }

      else {

        local_d0 = local_d0 & 0xffffffff00000000;

      }

      (*(code *)*param_1)(param_1[1],&local_d0,4);

      param_5 = param_5 + lVar11;

      uVar14 = uVar14 - 1;

    } while (uVar14 != 0);

  }

  return;

}




