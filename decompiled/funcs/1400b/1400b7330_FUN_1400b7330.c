// Address: 0x1400b7330
// Ghidra name: FUN_1400b7330
// ============ 0x1400b7330 FUN_1400b7330 (size=779) ============


undefined8 FUN_1400b7330(longlong param_1,float param_2,float param_3)



{

  longlong *plVar1;

  float fVar2;

  char cVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  uint uVar7;

  ulonglong uVar8;

  longlong lVar9;

  float *pfVar10;

  int iVar11;

  int iVar12;

  longlong lVar13;

  undefined4 uVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98 [5];

  float local_84;

  float local_80;

  float local_7c;

  

  lVar9 = *(longlong *)(param_1 + 0x40);

  local_98[0] = param_2 + DAT_140303358;

  iVar12 = 0;

  lVar4 = *(longlong *)(param_1 + 0x48) - lVar9;

  local_98[2] = param_2 - DAT_140303358;

  local_84 = param_3 + DAT_140303358;

  local_7c = param_3 - DAT_140303358;

  lVar4 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar4),8) + lVar4;

  if (lVar4 >> 7 != lVar4 >> 0x3f) {

    lVar4 = 0;

    local_98[1] = param_3;

    local_98[3] = param_3;

    local_98[4] = param_2;

    local_80 = param_2;

    do {

      uVar14 = FUN_1400c5f10(*(undefined4 *)(lVar4 + 0x58 + lVar9));

      fVar19 = *(float *)(lVar4 + 0x50 + lVar9);

      fVar20 = *(float *)(lVar4 + 0x54 + lVar9);

      local_a8 = fVar19;

      local_a4 = fVar20;

      fVar15 = (float)FUN_1402cdc50();

      local_a0 = fVar15;

      fVar16 = (float)FUN_1402cfda0(uVar14);

      lVar6 = *(longlong *)(lVar4 + 0x18 + lVar9);

      iVar11 = 0;

      lVar5 = *(longlong *)(lVar4 + 0x20 + lVar9) - lVar6;

      lVar13 = lVar5 >> 0x3f;

      local_9c = fVar16;

      if (lVar5 / 0x168 + lVar13 != lVar13) {

        lVar13 = 0;

        do {

          plVar1 = (longlong *)(lVar13 + lVar6);

          if ((((char)plVar1[0x2c] != '\0') && ((int)plVar1[0x2a] != 0xd)) &&

             (*(float *)((longlong)plVar1 + 0x154) != 0.0)) {

            uVar8 = 0;

            pfVar10 = local_98 + 1;

            do {

              fVar2 = *(float *)(plVar1 + 0x29);

              if (fVar2 <= 0.0) {

                cVar3 = (**(code **)(*plVar1 + 0x18))(plVar1,&local_a8,local_98 + uVar8 * 2);

                fVar16 = local_9c;

                fVar15 = local_a0;

                fVar19 = local_a8;

                fVar20 = local_a4;

                if (cVar3 != '\0') {

                  return 1;

                }

              }

              else {

                fVar18 = pfVar10[-1] -

                         ((*(float *)(plVar1 + 0x28) * fVar16 -

                          *(float *)((longlong)plVar1 + 0x144) * fVar15) + fVar19);

                fVar17 = *pfVar10 -

                         (*(float *)(plVar1 + 0x28) * fVar15 +

                          *(float *)((longlong)plVar1 + 0x144) * fVar16 + fVar20);

                if (fVar18 * fVar18 + fVar17 * fVar17 < fVar2 * fVar2) {

                  return 1;

                }

              }

              uVar7 = (int)uVar8 + 1;

              uVar8 = (ulonglong)uVar7;

              pfVar10 = pfVar10 + 2;

            } while ((int)uVar7 < 4);

          }

          lVar6 = *(longlong *)(lVar4 + 0x18 + lVar9);

          iVar11 = iVar11 + 1;

          lVar13 = lVar13 + 0x168;

        } while ((ulonglong)(longlong)iVar11 <

                 (ulonglong)((*(longlong *)(lVar4 + 0x20 + lVar9) - lVar6) / 0x168));

      }

      lVar9 = *(longlong *)(param_1 + 0x40);

      iVar12 = iVar12 + 1;

      lVar6 = *(longlong *)(param_1 + 0x48) - lVar9;

      lVar4 = lVar4 + 0xb8;

      lVar6 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar6),8) + lVar6;

    } while ((ulonglong)(longlong)iVar12 < (ulonglong)((lVar6 >> 7) - (lVar6 >> 0x3f)));

  }

  return 0;

}




