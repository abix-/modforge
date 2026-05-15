// Address: 0x140018e70
// Ghidra name: FUN_140018e70
// ============ 0x140018e70 FUN_140018e70 (size=1745) ============


void FUN_140018e70(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

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

  float fVar24;

  float fVar25;

  float fVar26;

  float fVar27;

  float fVar28;

  float fVar29;

  float fVar30;

  

  lVar6 = *(longlong *)(param_1 + 0x60);

  lVar8 = (longlong)*(int *)(lVar6 + 8);

  *(int *)(param_1 + 0xc0) = *(int *)(lVar6 + 8);

  lVar7 = *(longlong *)(param_1 + 0x68);

  lVar9 = (longlong)*(int *)(lVar7 + 8);

  *(int *)(param_1 + 0xc4) = *(int *)(lVar7 + 8);

  *(undefined8 *)(param_1 + 200) = *(undefined8 *)(lVar6 + 0x1c);

  *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(lVar7 + 0x1c);

  fVar18 = *(float *)(lVar6 + 0x94);

  *(float *)(param_1 + 0xd8) = fVar18;

  fVar14 = *(float *)(lVar7 + 0x94);

  *(float *)(param_1 + 0xdc) = fVar14;

  fVar1 = *(float *)(lVar6 + 0x9c);

  *(float *)(param_1 + 0xe0) = fVar1;

  fVar2 = *(float *)(lVar7 + 0x9c);

  *(float *)(param_1 + 0xe4) = fVar2;

  lVar6 = *(longlong *)(param_2 + 8);

  lVar7 = *(longlong *)(param_2 + 6);

  fVar25 = *(float *)(lVar6 + lVar8 * 0xc);

  uVar3 = *(undefined4 *)(lVar7 + 8 + lVar8 * 0xc);

  fVar26 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  fVar27 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  uVar4 = *(undefined4 *)(lVar7 + 8 + lVar9 * 0xc);

  fVar28 = *(float *)(lVar6 + lVar9 * 0xc);

  fVar29 = *(float *)(lVar6 + 4 + lVar9 * 0xc);

  fVar30 = *(float *)(lVar6 + 8 + lVar9 * 0xc);

  fVar10 = (float)FUN_1402cdc50(uVar3);

  fVar11 = (float)FUN_1402cfda0(uVar3);

  fVar12 = (float)FUN_1402cdc50(uVar4);

  fVar13 = (float)FUN_1402cfda0(uVar4);

  fVar15 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 200);

  fVar20 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xcc);

  fVar21 = fVar20 * fVar11 + fVar15 * fVar10;

  fVar16 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd4);

  fVar15 = fVar15 * fVar11 - fVar20 * fVar10;

  fVar20 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xd0);

  fVar24 = fVar20 * fVar13 - fVar16 * fVar12;

  fVar20 = fVar16 * fVar13 + fVar20 * fVar12;

  fVar13 = ((fVar24 + *(float *)(lVar7 + lVar9 * 0xc)) - *(float *)(lVar7 + lVar8 * 0xc)) - fVar15;

  fVar17 = ((fVar20 + *(float *)(lVar7 + 4 + lVar9 * 0xc)) - *(float *)(lVar7 + 4 + lVar8 * 0xc)) -

           fVar21;

  fVar23 = *(float *)(param_1 + 0xa0) * fVar11 - *(float *)(param_1 + 0xa4) * fVar10;

  fVar15 = fVar13 + fVar15;

  fVar16 = *(float *)(param_1 + 0xa0) * fVar10 + *(float *)(param_1 + 0xa4) * fVar11;

  fVar21 = fVar17 + fVar21;

  *(float *)(param_1 + 0xf4) = fVar16;

  fVar22 = fVar16 * fVar15 - fVar23 * fVar21;

  *(float *)(param_1 + 0xf0) = fVar23;

  fVar12 = DAT_14039ca44;

  fVar16 = fVar24 * fVar16 - fVar23 * fVar20;

  fVar14 = fVar14 + fVar18;

  *(float *)(param_1 + 0x100) = fVar22;

  *(float *)(param_1 + 0x104) = fVar16;

  fVar18 = fVar22 * fVar1 * fVar22 + fVar14 + fVar16 * fVar2 * fVar16;

  *(float *)(param_1 + 0x108) = fVar18;

  if (0.0 < fVar18) {

    *(float *)(param_1 + 0x108) = fVar12 / fVar18;

  }

  *(undefined8 *)(param_1 + 0x110) = 0;

  *(undefined4 *)(param_1 + 0x118) = 0;

  if (*(float *)(param_1 + 0x80) <= 0.0) {

    *(undefined4 *)(param_1 + 0xb0) = 0;

  }

  else {

    fVar19 = *(float *)(param_1 + 0x98) * fVar11 - *(float *)(param_1 + 0x9c) * fVar10;

    fVar10 = *(float *)(param_1 + 0x9c) * fVar11 + *(float *)(param_1 + 0x98) * fVar10;

    *(float *)(param_1 + 0xe8) = fVar19;

    *(float *)(param_1 + 0xec) = fVar10;

    fVar18 = fVar10 * fVar15 - fVar19 * fVar21;

    fVar11 = fVar24 * fVar10 - fVar19 * fVar20;

    *(float *)(param_1 + 0xf8) = fVar18;

    *(float *)(param_1 + 0xfc) = fVar11;

    fVar18 = fVar1 * fVar18 * fVar18 + fVar14 + fVar2 * fVar11 * fVar11;

    if (0.0 < fVar18) {

      fVar20 = *(float *)(param_1 + 0x80) * DAT_14039ca54;

      fVar11 = fVar12 / fVar18;

      *(float *)(param_1 + 0x110) = fVar11;

      fVar14 = *param_2;

      fVar15 = fVar20 * fVar11 * fVar20;

      fVar11 = ((fVar11 + fVar11) * *(float *)(param_1 + 0x84) * fVar20 + fVar14 * fVar15) * fVar14;

      *(float *)(param_1 + 0x118) = fVar11;

      if (0.0 < fVar11) {

        fVar11 = fVar12 / fVar11;

        *(float *)(param_1 + 0x118) = fVar11;

      }

      fVar18 = fVar11 + fVar18;

      *(float *)(param_1 + 0x114) = (fVar17 * fVar10 + fVar19 * fVar13) * fVar14 * fVar15 * fVar11;

      *(float *)(param_1 + 0x110) = fVar18;

      if (0.0 < fVar18) {

        *(float *)(param_1 + 0x110) = fVar12 / fVar18;

      }

    }

  }

  if (*(char *)(param_1 + 0xbc) == '\0') {

    *(undefined4 *)(param_1 + 0x10c) = 0;

    *(undefined4 *)(param_1 + 0xac) = 0;

  }

  else {

    fVar18 = fVar2 + fVar1;

    *(float *)(param_1 + 0x10c) = fVar18;

    if (0.0 < fVar18) {

      *(float *)(param_1 + 0x10c) = fVar12 / fVar18;

    }

  }

  if (*(char *)(param_2 + 5) == '\0') {

    *(undefined8 *)(param_1 + 0xa8) = 0;

    *(undefined4 *)(param_1 + 0xb0) = 0;

  }

  else {

    fVar10 = *(float *)(param_1 + 0xa8) * param_2[2];

    *(float *)(param_1 + 0xa8) = fVar10;

    fVar11 = param_2[2] * *(float *)(param_1 + 0xb0);

    *(float *)(param_1 + 0xb0) = fVar11;

    fVar12 = *(float *)(param_1 + 0xac) * param_2[2];

    *(float *)(param_1 + 0xac) = fVar12;

    fVar14 = fVar11 * *(float *)(param_1 + 0xe8) + fVar23 * fVar10;

    fVar18 = fVar11 * *(float *)(param_1 + 0xec) + fVar10 * *(float *)(param_1 + 0xf4);

    fVar25 = fVar25 - *(float *)(param_1 + 0xd8) * fVar14;

    fVar26 = fVar26 - *(float *)(param_1 + 0xd8) * fVar18;

    fVar28 = fVar28 + *(float *)(param_1 + 0xdc) * fVar14;

    fVar29 = fVar29 + *(float *)(param_1 + 0xdc) * fVar18;

    fVar30 = fVar30 + (fVar11 * *(float *)(param_1 + 0xfc) + fVar10 * fVar16 + fVar12) * fVar2;

    fVar27 = fVar27 - (fVar10 * fVar22 + fVar11 * *(float *)(param_1 + 0xf8) + fVar12) * fVar1;

  }

  lVar6 = *(longlong *)(param_2 + 8);

  *(float *)(lVar6 + lVar8 * 0xc) = fVar25;

  *(float *)(lVar6 + 4 + lVar8 * 0xc) = fVar26;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xc0) * 0xc) = fVar27;

  iVar5 = *(int *)(param_1 + 0xc4);

  lVar6 = *(longlong *)(param_2 + 8);

  *(float *)(lVar6 + (longlong)iVar5 * 0xc) = fVar28;

  *(float *)(lVar6 + 4 + (longlong)iVar5 * 0xc) = fVar29;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xc4) * 0xc) = fVar30;

  return;

}




