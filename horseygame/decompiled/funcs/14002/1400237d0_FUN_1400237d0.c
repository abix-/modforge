// Address: 0x1400237d0
// Ghidra name: FUN_1400237d0
// ============ 0x1400237d0 FUN_1400237d0 (size=1766) ============


void FUN_1400237d0(float *param_1,longlong param_2,float *param_3,longlong param_4,float *param_5)



{

  float fVar1;

  bool bVar2;

  ulonglong uVar3;

  uint uVar4;

  ulonglong uVar5;

  longlong lVar6;

  float fVar7;

  int iVar8;

  int iVar9;

  float fVar10;

  float fVar11;

  float fVar12;

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

  int local_res8 [2];

  int local_res10 [2];

  undefined8 local_120;

  undefined4 uStack_118;

  float fStack_114;

  float local_110;

  undefined4 local_10c;

  float local_108;

  float fStack_104;

  float fStack_100;

  float fStack_fc;

  undefined8 local_f8;

  undefined4 local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  

  fVar7 = 0.0;

  param_1[0xf] = 0.0;

  fVar21 = *(float *)(param_2 + 0xc) + *(float *)(param_4 + 0xc);

  local_res10[0] = 0;

  fVar10 = (float)FUN_140023180(local_res10,param_2,param_3,param_4,param_5);

  if (fVar10 <= fVar21) {

    local_res8[0] = 0;

    fVar11 = (float)FUN_140023180(local_res8,param_4,param_5,param_2,param_3);

    if (fVar11 <= fVar21) {

      fVar10 = fVar10 * DAT_14039ca3c + DAT_14039c9fc;

      if (fVar11 <= fVar10) {

        fVar22 = *param_3;

        fVar12 = param_3[1];

        uStack_118 = param_3[2];

        fStack_114 = param_3[3];

        local_108 = *param_5;

        fStack_104 = param_5[1];

        fStack_100 = param_5[2];

        fStack_fc = param_5[3];

        iVar8 = local_res10[0];

      }

      else {

        fVar22 = *param_5;

        fVar12 = param_5[1];

        uStack_118 = param_5[2];

        fStack_114 = param_5[3];

        local_108 = *param_3;

        fStack_104 = param_3[1];

        fStack_100 = param_3[2];

        fStack_fc = param_3[3];

        iVar8 = local_res8[0];

      }

      lVar6 = param_4;

      if (fVar11 <= fVar10) {

        lVar6 = param_2;

      }

      local_120 = CONCAT44(fVar12,fVar22);

      param_1[0xe] = (float)((fVar10 < fVar11) + 1);

      if (fVar11 <= fVar10) {

        param_2 = param_4;

      }

      FUN_1400234e0(&local_f8,lVar6,&local_120,iVar8,param_2,&local_108);

      iVar9 = iVar8 + 1;

      if (*(int *)(lVar6 + 0x98) <= iVar9) {

        iVar9 = 0;

      }

      fVar22 = *(float *)(lVar6 + 0x18 + (longlong)iVar8 * 8);

      fVar12 = *(float *)(lVar6 + 0x1c + (longlong)iVar8 * 8);

      fVar16 = *(float *)(lVar6 + 0x18 + (longlong)iVar9 * 8);

      fVar1 = *(float *)(lVar6 + 0x1c + (longlong)iVar9 * 8);

      fVar17 = fVar16 - fVar22;

      fVar20 = fVar1 - fVar12;

      fVar13 = fVar20 * fVar20 + fVar17 * fVar17;

      if (fVar13 < 0.0) {

        fVar13 = (float)FUN_1402cdfa0(fVar13);

      }

      else {

        fVar13 = SQRT(fVar13);

      }

      if (DAT_14039c9f0 <= fVar13) {

        fVar17 = fVar17 * (DAT_14039ca44 / fVar13);

        fVar20 = fVar20 * (DAT_14039ca44 / fVar13);

      }

      fVar13 = fVar17 * DAT_14039ca80;

      fVar14 = (fVar16 + fVar22) * DAT_14039ca34;

      fVar23 = fVar17 * fStack_114 - fVar20 * uStack_118;

      fVar18 = fVar17 * uStack_118 + fVar20 * fStack_114;

      fVar19 = fVar23 * DAT_14039ca80;

      fVar17 = (fVar22 * fStack_114 - fVar12 * uStack_118) + (float)local_120;

      fVar22 = fVar22 * uStack_118 + fVar12 * fStack_114 + local_120._4_4_;

      fVar15 = fVar19 * fVar22 + fVar17 * fVar18;

      fVar17 = fVar21 - (fVar22 * fVar18 + fVar17 * fVar23);

      fVar22 = (fVar16 * uStack_118 + fVar1 * fStack_114 + local_120._4_4_) * fVar18 +

               ((fVar16 * fStack_114 - fVar1 * uStack_118) + (float)local_120) * fVar23 + fVar21;

      fVar16 = (local_f8._4_4_ * (float)((uint)fVar18 ^ DAT_14039cac0) +

               (float)local_f8 * (float)((uint)fVar23 ^ DAT_14039cac0)) - fVar17;

      fVar17 = (local_e8 * (float)((uint)fVar18 ^ DAT_14039cac0) +

               local_ec * (float)((uint)fVar23 ^ DAT_14039cac0)) - fVar17;

      if (fVar16 <= 0.0) {

        local_120 = local_f8;

        uStack_118 = local_f0;

      }

      uVar4 = (uint)(fVar16 <= 0.0);

      if (fVar17 <= 0.0) {

        uVar3 = (ulonglong)uVar4;

        uVar4 = uVar4 + 1;

        *(ulonglong *)((longlong)&local_120 + uVar3 * 0xc) = CONCAT44(local_e8,local_ec);

        (&uStack_118)[uVar3 * 3] = local_e4;

      }

      if (fVar17 * fVar16 < 0.0) {

        uVar3 = (ulonglong)uVar4;

        uVar4 = uVar4 + 1;

        *(char *)(&uStack_118 + uVar3 * 3) = (char)iVar8;

        fVar16 = fVar16 / (fVar16 - fVar17);

        *(undefined1 *)((longlong)&uStack_118 + uVar3 * 0xc + 1) = local_f0._1_1_;

        *(undefined2 *)((longlong)&uStack_118 + uVar3 * 0xc + 2) = 0x100;

        *(float *)((longlong)&local_120 + uVar3 * 0xc) =

             (local_ec - (float)local_f8) * fVar16 + (float)local_f8;

        *(float *)((longlong)&local_120 + uVar3 * 0xc + 4) =

             (local_e8 - local_f8._4_4_) * fVar16 + local_f8._4_4_;

      }

      if (1 < uVar4) {

        fVar16 = (fVar18 * local_120._4_4_ + fVar23 * (float)local_120) - fVar22;

        fVar22 = (fVar18 * local_110 + fVar23 * fStack_114) - fVar22;

        bVar2 = fVar16 <= 0.0;

        if (bVar2) {

          local_f8 = local_120;

          local_f0 = uStack_118;

        }

        uVar5 = (ulonglong)bVar2;

        uVar3 = uVar5;

        if (fVar22 <= 0.0) {

          uVar3 = (ulonglong)(bVar2 + 1);

          *(ulonglong *)((longlong)&local_f8 + uVar5 * 0xc) = CONCAT44(local_110,fStack_114);

          (&local_f0)[uVar5 * 3] = local_10c;

        }

        uVar4 = (uint)uVar3;

        if (fVar22 * fVar16 < 0.0) {

          uVar4 = uVar4 + 1;

          *(char *)(&local_f0 + uVar3 * 3) = (char)iVar9;

          fVar16 = fVar16 / (fVar16 - fVar22);

          *(undefined1 *)((longlong)&local_f0 + uVar3 * 0xc + 1) = uStack_118._1_1_;

          *(undefined2 *)((longlong)&local_f0 + uVar3 * 0xc + 2) = 0x100;

          *(float *)((longlong)&local_f8 + uVar3 * 0xc) =

               (fStack_114 - (float)local_120) * fVar16 + (float)local_120;

          *(float *)((longlong)&local_f8 + uVar3 * 0xc + 4) =

               (local_110 - local_120._4_4_) * fVar16 + local_120._4_4_;

        }

        if (1 < uVar4) {

          param_1[0xd] = (fVar1 + fVar12) * DAT_14039ca34;

          param_1[0xb] = fVar13;

          param_1[0xc] = fVar14;

          param_1[10] = fVar20;

          if ((fVar19 * local_f8._4_4_ + (float)local_f8 * fVar18) - fVar15 <= fVar21) {

            param_1[4] = local_f0;

            *param_1 = (local_f8._4_4_ - fStack_104) * fStack_100 +

                       ((float)local_f8 - local_108) * fStack_fc;

            param_1[1] = (local_f8._4_4_ - fStack_104) * fStack_fc -

                         ((float)local_f8 - local_108) * fStack_100;

            if (fVar10 < fVar11) {

              *(char *)((longlong)param_1 + 0x11) = SUB41(local_f0,0);

              *(char *)(param_1 + 4) = (char)((uint)local_f0 >> 8);

              *(char *)((longlong)param_1 + 0x13) = (char)((uint)local_f0 >> 0x10);

              *(char *)((longlong)param_1 + 0x12) = (char)((uint)local_f0 >> 0x18);

            }

            fVar7 = 1.4013e-45;

          }

          if ((fVar19 * local_e8 + local_ec * fVar18) - fVar15 <= fVar21) {

            uVar3 = (ulonglong)(uint)fVar7;

            param_1[uVar3 * 5] =

                 (local_e8 - fStack_104) * fStack_100 + (local_ec - local_108) * fStack_fc;

            param_1[uVar3 * 5 + 1] =

                 (local_e8 - fStack_104) * fStack_fc - (local_ec - local_108) * fStack_100;

            param_1[uVar3 * 5 + 4] = local_e4;

            if (fVar10 < fVar11) {

              *(char *)(param_1 + uVar3 * 5 + 4) = (char)((uint)local_e4 >> 8);

              *(char *)((longlong)param_1 + uVar3 * 0x14 + 0x11) = SUB41(local_e4,0);

              *(char *)((longlong)param_1 + uVar3 * 0x14 + 0x12) = (char)((uint)local_e4 >> 0x18);

              *(char *)((longlong)param_1 + uVar3 * 0x14 + 0x13) = (char)((uint)local_e4 >> 0x10);

            }

            fVar7 = (float)((int)fVar7 + 1);

          }

          param_1[0xf] = fVar7;

        }

      }

    }

  }

  return;

}




