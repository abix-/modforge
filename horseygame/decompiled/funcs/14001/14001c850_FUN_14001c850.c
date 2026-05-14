// Address: 0x14001c850
// Ghidra name: FUN_14001c850
// ============ 0x14001c850 FUN_14001c850 (size=2266) ============


undefined8 FUN_14001c850(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  int iVar13;

  longlong lVar14;

  longlong lVar15;

  longlong lVar16;

  longlong lVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  undefined4 local_res8;

  undefined4 local_res20;

  undefined4 local_118;

  undefined4 local_114;

  undefined4 local_104;

  undefined4 local_100;

  undefined4 local_fc;

  undefined4 local_f8;

  undefined4 local_dc;

  

  lVar14 = *(longlong *)(param_2 + 0x18);

  lVar15 = (longlong)*(int *)(param_1 + 0xdc);

  lVar16 = (longlong)*(int *)(param_1 + 0xe0);

  fVar1 = *(float *)(lVar14 + 4 + lVar15 * 0xc);

  fVar2 = *(float *)(lVar14 + 8 + lVar15 * 0xc);

  fVar3 = *(float *)(lVar14 + lVar16 * 0xc);

  fVar4 = *(float *)(lVar14 + 8 + lVar16 * 0xc);

  lVar17 = (longlong)*(int *)(param_1 + 0xe4);

  fVar5 = *(float *)(lVar14 + 4 + lVar16 * 0xc);

  fVar6 = *(float *)(lVar14 + lVar17 * 0xc);

  fVar7 = *(float *)(lVar14 + 8 + lVar17 * 0xc);

  lVar16 = (longlong)*(int *)(param_1 + 0xe8);

  fVar8 = *(float *)(lVar14 + 4 + lVar17 * 0xc);

  fVar9 = *(float *)(lVar14 + lVar16 * 0xc);

  fVar10 = *(float *)(lVar14 + 8 + lVar16 * 0xc);

  fVar11 = *(float *)(lVar14 + 4 + lVar16 * 0xc);

  fVar18 = (float)FUN_1402cdc50(fVar2);

  fVar19 = (float)FUN_1402cfda0(fVar2);

  fVar20 = (float)FUN_1402cdc50(fVar4);

  fVar21 = (float)FUN_1402cfda0(fVar4);

  fVar22 = (float)FUN_1402cdc50(fVar7);

  fVar23 = (float)FUN_1402cfda0(fVar7);

  fVar24 = (float)FUN_1402cdc50(fVar10);

  fVar25 = (float)FUN_1402cfda0(fVar10);

  fVar31 = 0.0;

  if (*(int *)(param_1 + 0x80) == 1) {

    local_dc = *(float *)(param_1 + 0x124);

    fVar32 = *(float *)(param_1 + 0x11c);

    local_104 = *(float *)(param_1 + 0x10c);

    local_100 = *(float *)(param_1 + 0x114);

    fVar19 = local_dc + fVar32;

    local_fc = 0.0;

    fVar18 = (fVar2 - fVar7) - *(float *)(param_1 + 200);

    local_f8 = 0.0;

    local_res20 = DAT_14039ca44;

    local_114 = DAT_14039ca44;

  }

  else {

    fVar12 = *(float *)(param_1 + 0xbc);

    fVar26 = *(float *)(param_1 + 0xb8);

    fVar27 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xec);

    fVar29 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xfc);

    fVar28 = *(float *)(param_1 + 0xac) - *(float *)(param_1 + 0x100);

    fVar30 = *(float *)(param_1 + 0x9c) - *(float *)(param_1 + 0xf0);

    local_fc = fVar26 * fVar23 - fVar12 * fVar22;

    fVar33 = fVar27 * fVar18 + fVar19 * fVar30;

    fVar32 = *(float *)(param_1 + 0x11c);

    local_f8 = fVar12 * fVar23 + fVar26 * fVar22;

    fVar18 = fVar27 * fVar19 - fVar18 * fVar30;

    local_dc = *(float *)(param_1 + 0x124);

    local_100 = *(float *)(param_1 + 0x114);

    local_114 = (fVar29 * fVar23 - fVar28 * fVar22) * local_f8 -

                (fVar28 * fVar23 + fVar29 * fVar22) * local_fc;

    local_104 = *(float *)(param_1 + 0x10c);

    local_res20 = local_f8 * fVar18 - local_fc * fVar33;

    fVar18 = (*(float *)(lVar14 + lVar15 * 0xc) - fVar6) + fVar18;

    fVar33 = (fVar1 - fVar8) + fVar33;

    fVar18 = ((fVar23 * fVar33 - fVar22 * fVar18) - fVar28) * fVar12 +

             ((fVar23 * fVar18 + fVar22 * fVar33) - fVar29) * fVar26;

    fVar19 = local_dc * local_114 * local_114 + local_100 + local_104 +

             fVar32 * local_res20 * local_res20;

  }

  if (*(int *)(param_1 + 0x84) == 1) {

    fVar20 = *(float *)(param_1 + 0x128);

    fVar21 = *(float *)(param_1 + 0x120);

    local_res8 = 0.0;

    local_118 = DAT_14039ca44;

    fVar23 = fVar20 + fVar21;

    fVar30 = 0.0;

    fVar22 = (fVar4 - fVar10) - *(float *)(param_1 + 0xcc);

    fVar26 = DAT_14039ca44;

  }

  else {

    fVar22 = *(float *)(param_1 + 0xc4);

    fVar23 = *(float *)(param_1 + 0xc0);

    fVar26 = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xf8);

    fVar12 = *(float *)(param_1 + 0xd4);

    fVar29 = *(float *)(param_1 + 0xb0) - *(float *)(param_1 + 0x104);

    fVar28 = *(float *)(param_1 + 0xb4) - *(float *)(param_1 + 0x108);

    fVar30 = fVar25 * fVar23 - fVar24 * fVar22;

    fVar27 = *(float *)(param_1 + 0xa0) - *(float *)(param_1 + 0xf4);

    local_res8 = fVar25 * fVar22 + fVar24 * fVar23;

    fVar33 = fVar21 * fVar26 + fVar27 * fVar20;

    fVar27 = fVar21 * fVar27 - fVar26 * fVar20;

    fVar21 = *(float *)(param_1 + 0x120);

    local_118 = ((fVar25 * fVar29 - fVar24 * fVar28) * local_res8 -

                (fVar25 * fVar28 + fVar24 * fVar29) * fVar30) * fVar12;

    fVar20 = *(float *)(param_1 + 0x128);

    fVar26 = (fVar27 * local_res8 - fVar33 * fVar30) * fVar12;

    fVar27 = (fVar3 - fVar9) + fVar27;

    fVar33 = (fVar5 - fVar11) + fVar33;

    fVar22 = ((fVar25 * fVar33 - fVar27 * fVar24) - fVar28) * fVar22 +

             ((fVar25 * fVar27 + fVar33 * fVar24) - fVar29) * fVar23;

    fVar30 = fVar12 * fVar30;

    local_res8 = fVar12 * local_res8;

    fVar23 = fVar12 * fVar12 * (*(float *)(param_1 + 0x110) + *(float *)(param_1 + 0x118)) +

             fVar20 * local_118 * local_118 + fVar21 * fVar26 * fVar26;

  }

  fVar23 = fVar23 + fVar19 + 0.0;

  if (0.0 < fVar23) {

    fVar31 = (float)((uint)((fVar22 * *(float *)(param_1 + 0xd4) + fVar18) -

                           *(float *)(param_1 + 0xd0)) ^ DAT_14039cac0) / fVar23;

  }

  fVar18 = fVar31 * *(float *)(param_1 + 0x110);

  fVar19 = fVar31 * *(float *)(param_1 + 0x118);

  *(float *)(lVar14 + lVar15 * 0xc) =

       local_fc * local_104 * fVar31 + *(float *)(lVar14 + lVar15 * 0xc);

  *(float *)(lVar14 + 4 + lVar15 * 0xc) = local_f8 * local_104 * fVar31 + fVar1;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xdc) * 0xc) =

       fVar32 * fVar31 * local_res20 + fVar2;

  iVar13 = *(int *)(param_1 + 0xe0);

  lVar14 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar14 + (longlong)iVar13 * 0xc) = fVar30 * fVar18 + fVar3;

  *(float *)(lVar14 + 4 + (longlong)iVar13 * 0xc) = local_res8 * fVar18 + fVar5;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xe0) * 0xc) =

       fVar21 * fVar31 * fVar26 + fVar4;

  iVar13 = *(int *)(param_1 + 0xe4);

  lVar14 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar14 + (longlong)iVar13 * 0xc) = fVar6 - local_fc * local_100 * fVar31;

  *(float *)(lVar14 + 4 + (longlong)iVar13 * 0xc) = fVar8 - local_f8 * local_100 * fVar31;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xe4) * 0xc) =

       fVar7 - local_dc * fVar31 * local_114;

  iVar13 = *(int *)(param_1 + 0xe8);

  lVar14 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar14 + (longlong)iVar13 * 0xc) = fVar9 - fVar30 * fVar19;

  *(float *)(lVar14 + 4 + (longlong)iVar13 * 0xc) = fVar11 - local_res8 * fVar19;

  lVar14 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar14 + 8 + (longlong)*(int *)(param_1 + 0xe8) * 0xc) =

       fVar10 - fVar20 * fVar31 * local_118;

  return CONCAT71((int7)((ulonglong)lVar14 >> 8),1);

}




