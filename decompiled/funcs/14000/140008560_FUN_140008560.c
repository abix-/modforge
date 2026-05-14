// Address: 0x140008560
// Ghidra name: FUN_140008560
// ============ 0x140008560 FUN_140008560 (size=1894) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140008560(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  int iVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

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

  

  lVar8 = *(longlong *)(param_1 + 0x68);

  lVar9 = *(longlong *)(param_1 + 0x60);

  lVar10 = (longlong)*(int *)(lVar9 + 8);

  *(int *)(param_1 + 0xcc) = *(int *)(lVar9 + 8);

  lVar11 = (longlong)*(int *)(lVar8 + 8);

  *(int *)(param_1 + 0xd0) = *(int *)(lVar8 + 8);

  *(undefined8 *)(param_1 + 0xd4) = *(undefined8 *)(lVar9 + 0x1c);

  *(undefined8 *)(param_1 + 0xdc) = *(undefined8 *)(lVar8 + 0x1c);

  fVar1 = *(float *)(lVar9 + 0x94);

  *(float *)(param_1 + 0xe4) = fVar1;

  fVar2 = *(float *)(lVar8 + 0x94);

  *(float *)(param_1 + 0xe8) = fVar2;

  fVar3 = *(float *)(lVar9 + 0x9c);

  *(float *)(param_1 + 0xec) = fVar3;

  fVar4 = *(float *)(lVar8 + 0x9c);

  *(float *)(param_1 + 0xf0) = fVar4;

  lVar8 = *(longlong *)(param_2 + 0x20);

  lVar9 = *(longlong *)(param_2 + 0x18);

  fVar16 = *(float *)(lVar8 + 8 + lVar10 * 0xc);

  uVar5 = *(undefined4 *)(lVar9 + 8 + lVar10 * 0xc);

  fVar28 = *(float *)(lVar8 + lVar10 * 0xc);

  fVar29 = *(float *)(lVar8 + 4 + lVar10 * 0xc);

  uVar6 = *(undefined4 *)(lVar9 + 8 + lVar11 * 0xc);

  fVar18 = *(float *)(lVar8 + lVar11 * 0xc);

  fVar20 = *(float *)(lVar8 + 4 + lVar11 * 0xc);

  fVar21 = *(float *)(lVar8 + 8 + lVar11 * 0xc);

  fVar12 = (float)FUN_1402cdc50(uVar5);

  fVar13 = (float)FUN_1402cfda0(uVar5);

  fVar14 = (float)FUN_1402cdc50(uVar6);

  fVar15 = (float)FUN_1402cfda0(uVar6);

  fVar25 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);

  fVar19 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);

  fVar27 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);

  fVar23 = fVar19 * fVar13 - fVar25 * fVar12;

  fVar26 = fVar25 * fVar13 + fVar19 * fVar12;

  fVar17 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);

  fVar19 = *(float *)(lVar9 + 4 + lVar11 * 0xc);

  fVar25 = *(float *)(lVar9 + 4 + lVar10 * 0xc);

  fVar24 = fVar27 * fVar15 - fVar14 * fVar17;

  fVar22 = fVar13 * *(float *)(param_1 + 0x90) - fVar12 * *(float *)(param_1 + 0x94);

  fVar27 = fVar27 * fVar14 + fVar15 * fVar17;

  fVar15 = ((*(float *)(lVar9 + lVar11 * 0xc) - *(float *)(lVar9 + lVar10 * 0xc)) + fVar24) - fVar23

  ;

  *(float *)(param_1 + 0xf4) = fVar22;

  fVar23 = fVar23 + fVar15;

  fVar14 = fVar12 * *(float *)(param_1 + 0x90) + fVar13 * *(float *)(param_1 + 0x94);

  fVar17 = ((fVar19 - fVar25) + fVar27) - fVar26;

  *(float *)(param_1 + 0xf8) = fVar14;

  fVar26 = fVar26 + fVar17;

  fVar19 = fVar23 * fVar14 - fVar26 * fVar22;

  *(float *)(param_1 + 0x10c) = fVar19;

  fVar14 = fVar24 * *(float *)(param_1 + 0xf8) - fVar22 * fVar27;

  *(float *)(param_1 + 0x110) = fVar14;

  fVar25 = fVar3 * fVar19 * fVar19 + fVar2 + fVar1 + fVar4 * fVar14 * fVar14;

  *(float *)(param_1 + 0x138) = fVar25;

  if (0.0 < fVar25) {

    *(float *)(param_1 + 0x138) = DAT_14039ca44 / fVar25;

  }

  fVar22 = fVar13 * *(float *)(param_1 + 0x98) - fVar12 * *(float *)(param_1 + 0x9c);

  fVar12 = fVar12 * *(float *)(param_1 + 0x98) + fVar13 * *(float *)(param_1 + 0x9c);

  fVar27 = fVar24 * fVar12 - fVar27 * fVar22;

  *(float *)(param_1 + 0x100) = fVar12;

  *(float *)(param_1 + 0xfc) = fVar22;

  fVar24 = fVar23 * fVar12 - fVar26 * fVar22;

  *(float *)(param_1 + 0x108) = fVar27;

  fVar13 = fVar27 * fVar4;

  *(float *)(param_1 + 0x104) = fVar24;

  fVar23 = fVar24 * fVar3;

  fVar22 = fVar13 * fVar14 + fVar23 * fVar19;

  fVar12 = fVar4 + fVar3;

  if (fVar4 + fVar3 == 0.0) {

    fVar12 = DAT_14039ca44;

  }

  fVar19 = fVar3 * fVar19 + fVar4 * fVar14;

  *(float *)(param_1 + 0x118) = fVar13 + fVar23;

  *(float *)(param_1 + 0x11c) = fVar22;

  *(float *)(param_1 + 0x120) = fVar13 + fVar23;

  *(float *)(param_1 + 0x124) = fVar12;

  *(float *)(param_1 + 0x128) = fVar19;

  *(float *)(param_1 + 300) = fVar22;

  *(float *)(param_1 + 0x130) = fVar19;

  *(float *)(param_1 + 0x134) = fVar25;

  *(float *)(param_1 + 0x114) = fVar24 * fVar23 + fVar2 + fVar1 + fVar13 * fVar27;

  if (*(char *)(param_1 + 0xc4) == '\0') {

    *(undefined4 *)(param_1 + 200) = 0;

    *(undefined4 *)(param_1 + 0xac) = 0;

  }

  else {

    fVar19 = fVar15 * *(float *)(param_1 + 0xf4) + fVar17 * *(float *)(param_1 + 0xf8);

    if (DAT_14039ca0c <=

        (float)((uint)(*(float *)(param_1 + 0xb8) - *(float *)(param_1 + 0xb4)) & _DAT_14039cab0)) {

      if (*(float *)(param_1 + 0xb4) < fVar19) {

        if (fVar19 < *(float *)(param_1 + 0xb8)) {

          *(undefined4 *)(param_1 + 200) = 0;

          *(undefined4 *)(param_1 + 0xac) = 0;

        }

        else if (*(int *)(param_1 + 200) != 2) {

          *(undefined4 *)(param_1 + 200) = 2;

          *(undefined4 *)(param_1 + 0xac) = 0;

        }

      }

      else if (*(int *)(param_1 + 200) != 1) {

        *(undefined4 *)(param_1 + 200) = 1;

        *(undefined4 *)(param_1 + 0xac) = 0;

      }

    }

    else {

      *(undefined4 *)(param_1 + 200) = 3;

    }

  }

  if (*(char *)(param_1 + 0xc5) == '\0') {

    *(undefined4 *)(param_1 + 0xb0) = 0;

  }

  if (*(char *)(param_2 + 0x14) == '\0') {

    *(undefined8 *)(param_1 + 0xa4) = 0;

    *(undefined8 *)(param_1 + 0xac) = 0;

  }

  else {

    fVar19 = *(float *)(param_2 + 8);

    *(float *)(param_1 + 0xa4) = fVar19 * *(float *)(param_1 + 0xa4);

    fVar25 = *(float *)(param_1 + 0xa4);

    *(float *)(param_1 + 0xac) = fVar19 * *(float *)(param_1 + 0xac);

    *(float *)(param_1 + 0xa8) = fVar19 * *(float *)(param_1 + 0xa8);

    fVar13 = *(float *)(param_2 + 8) * *(float *)(param_1 + 0xb0);

    *(float *)(param_1 + 0xb0) = fVar13;

    fVar13 = fVar13 + *(float *)(param_1 + 0xac);

    fVar12 = fVar25 * *(float *)(param_1 + 0xfc) + fVar13 * *(float *)(param_1 + 0xf4);

    fVar19 = fVar25 * *(float *)(param_1 + 0x100) + fVar13 * *(float *)(param_1 + 0xf8);

    fVar28 = fVar28 - fVar12 * fVar1;

    fVar29 = fVar29 - fVar19 * fVar1;

    fVar18 = fVar18 + fVar12 * fVar2;

    fVar16 = fVar16 - (fVar25 * *(float *)(param_1 + 0x104) + *(float *)(param_1 + 0xa8) +

                      fVar13 * *(float *)(param_1 + 0x10c)) * fVar3;

    fVar20 = fVar20 + fVar19 * fVar2;

    fVar21 = fVar21 + (fVar25 * *(float *)(param_1 + 0x108) + *(float *)(param_1 + 0xa8) +

                      fVar13 * *(float *)(param_1 + 0x110)) * fVar4;

  }

  iVar7 = *(int *)(param_1 + 0xcc);

  lVar8 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar28;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar29;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xcc) * 0xc) = fVar16;

  iVar7 = *(int *)(param_1 + 0xd0);

  lVar8 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar8 + (longlong)iVar7 * 0xc) = fVar18;

  *(float *)(lVar8 + 4 + (longlong)iVar7 * 0xc) = fVar20;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xd0) * 0xc) = fVar21;

  return;

}




