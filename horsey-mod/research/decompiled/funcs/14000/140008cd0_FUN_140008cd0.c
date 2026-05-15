// Address: 0x140008cd0
// Ghidra name: FUN_140008cd0
// ============ 0x140008cd0 FUN_140008cd0 (size=1700) ============


void FUN_140008cd0(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  float *pfVar9;

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

  float local_d8;

  float local_d4;

  uint local_d0;

  float local_c8;

  float local_c4;

  float local_c0;

  undefined8 local_b8;

  

  local_d0 = DAT_14039cac0;

  lVar6 = *(longlong *)(param_2 + 8);

  fVar1 = *(float *)(param_1 + 0xe4);

  lVar7 = (longlong)*(int *)(param_1 + 0xcc);

  fVar2 = *(float *)(param_1 + 0xe8);

  lVar8 = (longlong)*(int *)(param_1 + 0xd0);

  fVar17 = *(float *)(lVar6 + lVar7 * 0xc);

  fVar18 = *(float *)(lVar6 + 4 + lVar7 * 0xc);

  fVar16 = *(float *)(lVar6 + 8 + lVar7 * 0xc);

  fVar20 = *(float *)(lVar6 + lVar8 * 0xc);

  fVar21 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  fVar19 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  fVar3 = *(float *)(param_1 + 0xec);

  fVar4 = *(float *)(param_1 + 0xf0);

  if ((*(char *)(param_1 + 0xc5) != '\0') && (*(int *)(param_1 + 200) != 3)) {

    fVar11 = *(float *)(param_1 + 0xb0);

    fVar12 = *(float *)(param_1 + 0xbc) * *param_2;

    fVar10 = (*(float *)(param_1 + 0xc0) -

             (((fVar21 - fVar18) * *(float *)(param_1 + 0xf8) +

               (fVar20 - fVar17) * *(float *)(param_1 + 0xf4) + *(float *)(param_1 + 0x110) * fVar19

              ) - *(float *)(param_1 + 0x10c) * fVar16)) * *(float *)(param_1 + 0x138) + fVar11;

    if (fVar12 <= fVar10) {

      fVar10 = fVar12;

    }

    fVar15 = (float)((uint)fVar12 ^ DAT_14039cac0);

    if ((float)((uint)fVar12 ^ DAT_14039cac0) <= fVar10) {

      fVar15 = fVar10;

    }

    *(float *)(param_1 + 0xb0) = fVar15;

    fVar15 = fVar15 - fVar11;

    fVar10 = *(float *)(param_1 + 0xf4) * fVar15;

    fVar11 = fVar15 * *(float *)(param_1 + 0xf8);

    fVar17 = fVar17 - fVar10 * fVar1;

    fVar18 = fVar18 - fVar11 * fVar1;

    fVar16 = fVar16 - *(float *)(param_1 + 0x10c) * fVar15 * fVar3;

    fVar20 = fVar20 + fVar10 * fVar2;

    fVar21 = fVar21 + fVar11 * fVar2;

    fVar19 = fVar19 + *(float *)(param_1 + 0x110) * fVar15 * fVar4;

  }

  fVar11 = (*(float *)(param_1 + 0xfc) * (fVar20 - fVar17) +

            (fVar21 - fVar18) * *(float *)(param_1 + 0x100) + *(float *)(param_1 + 0x108) * fVar19)

           - *(float *)(param_1 + 0x104) * fVar16;

  if ((*(char *)(param_1 + 0xc4) == '\0') || (*(int *)(param_1 + 200) == 0)) {

    fVar11 = (float)((uint)fVar11 ^ local_d0);

    fVar12 = (float)((uint)(fVar19 - fVar16) ^ local_d0);

    fVar10 = *(float *)(param_1 + 0x124) * *(float *)(param_1 + 0x114) -

             *(float *)(param_1 + 0x118) * *(float *)(param_1 + 0x120);

    if (fVar10 != 0.0) {

      fVar10 = DAT_14039ca44 / fVar10;

    }

    fVar15 = (fVar11 * *(float *)(param_1 + 0x124) - fVar12 * *(float *)(param_1 + 0x120)) * fVar10;

    fVar10 = (fVar12 * *(float *)(param_1 + 0x114) - fVar11 * *(float *)(param_1 + 0x118)) * fVar10;

    fVar14 = *(float *)(param_1 + 0xfc) * fVar15;

    *(float *)(param_1 + 0xa4) = fVar15 + *(float *)(param_1 + 0xa4);

    fVar11 = *(float *)(param_1 + 0x104) * fVar15 + fVar10;

    fVar12 = *(float *)(param_1 + 0x108) * fVar15 + fVar10;

    *(float *)(param_1 + 0xa8) = fVar10 + *(float *)(param_1 + 0xa8);

    fVar15 = fVar15 * *(float *)(param_1 + 0x100);

    goto LAB_1400092a3;

  }

  pfVar9 = (float *)(param_1 + 0x114);

  fVar10 = *(float *)(param_1 + 0xac);

  local_b8 = *(undefined8 *)(param_1 + 0xa4);

  fVar11 = (float)((uint)fVar11 ^ local_d0);

  fVar12 = (float)((uint)(fVar19 - fVar16) ^ local_d0);

  local_d0 = (uint)(((fVar20 - fVar17) * *(float *)(param_1 + 0xf4) +

                     (fVar21 - fVar18) * *(float *)(param_1 + 0xf8) +

                    fVar19 * *(float *)(param_1 + 0x110)) - fVar16 * *(float *)(param_1 + 0x10c)) ^

             local_d0;

  local_d8 = fVar11;

  local_d4 = fVar12;

  FUN_140007a90(pfVar9,&local_c8,&local_d8);

  local_c0 = local_c0 + *(float *)(param_1 + 0xac);

  *(float *)(param_1 + 0xa4) = local_c8 + *(float *)(param_1 + 0xa4);

  *(float *)(param_1 + 0xa8) = local_c4 + *(float *)(param_1 + 0xa8);

  *(float *)(param_1 + 0xac) = local_c0;

  if (*(int *)(param_1 + 200) == 1) {

    if (local_c0 <= 0.0) {

      local_c0 = 0.0;

    }

LAB_140009045:

    *(float *)(param_1 + 0xac) = local_c0;

  }

  else if (*(int *)(param_1 + 200) == 2) {

    if (0.0 <= local_c0) {

      local_c0 = 0.0;

    }

    goto LAB_140009045;

  }

  local_c0 = local_c0 - fVar10;

  fVar11 = fVar11 - local_c0 * *(float *)(param_1 + 300);

  fVar12 = fVar12 - local_c0 * *(float *)(param_1 + 0x130);

  fVar10 = pfVar9[4] * *pfVar9 - pfVar9[1] * pfVar9[3];

  if (fVar10 != 0.0) {

    fVar10 = DAT_14039ca44 / fVar10;

  }

  fVar13 = (fVar11 * pfVar9[4] - fVar12 * pfVar9[3]) * fVar10 + (float)local_b8;

  fVar10 = (fVar12 * *pfVar9 - fVar11 * pfVar9[1]) * fVar10 + local_b8._4_4_;

  *(float *)(param_1 + 0xa4) = fVar13;

  fVar13 = fVar13 - (float)local_b8;

  *(float *)(param_1 + 0xa8) = fVar10;

  fVar10 = fVar10 - local_b8._4_4_;

  fVar14 = fVar13 * *(float *)(param_1 + 0xfc) + local_c0 * *(float *)(param_1 + 0xf4);

  fVar15 = fVar13 * *(float *)(param_1 + 0x100) + local_c0 * *(float *)(param_1 + 0xf8);

  fVar11 = fVar13 * *(float *)(param_1 + 0x104) + fVar10 + local_c0 * *(float *)(param_1 + 0x10c);

  fVar12 = fVar13 * *(float *)(param_1 + 0x108) + fVar10 + local_c0 * *(float *)(param_1 + 0x110);

LAB_1400092a3:

  iVar5 = *(int *)(param_1 + 0xcc);

  lVar6 = *(longlong *)(param_2 + 8);

  *(float *)(lVar6 + (longlong)iVar5 * 0xc) = fVar17 - fVar1 * fVar14;

  *(float *)(lVar6 + 4 + (longlong)iVar5 * 0xc) = fVar18 - fVar15 * fVar1;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xcc) * 0xc) =

       fVar16 - fVar11 * fVar3;

  iVar5 = *(int *)(param_1 + 0xd0);

  lVar6 = *(longlong *)(param_2 + 8);

  *(float *)(lVar6 + (longlong)iVar5 * 0xc) = fVar14 * fVar2 + fVar20;

  *(float *)(lVar6 + 4 + (longlong)iVar5 * 0xc) = fVar15 * fVar2 + fVar21;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xd0) * 0xc) =

       fVar12 * fVar4 + fVar19;

  return;

}




