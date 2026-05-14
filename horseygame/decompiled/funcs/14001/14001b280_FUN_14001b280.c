// Address: 0x14001b280
// Ghidra name: FUN_14001b280
// ============ 0x14001b280 FUN_14001b280 (size=962) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_14001b280(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined4 uVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  longlong lVar9;

  bool bVar10;

  longlong lVar11;

  longlong lVar12;

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

  

  if (*(float *)(param_1 + 0x80) <= 0.0) {

    lVar11 = (longlong)*(int *)(param_1 + 0xa8);

    lVar9 = *(longlong *)(param_2 + 0x18);

    lVar12 = (longlong)*(int *)(param_1 + 0xac);

    fVar1 = *(float *)(lVar9 + lVar12 * 0xc);

    fVar2 = *(float *)(lVar9 + 8 + lVar11 * 0xc);

    fVar3 = *(float *)(lVar9 + lVar11 * 0xc);

    fVar4 = *(float *)(lVar9 + 4 + lVar11 * 0xc);

    uVar5 = *(undefined4 *)(lVar9 + 8 + lVar12 * 0xc);

    fVar6 = *(float *)(lVar9 + 4 + lVar12 * 0xc);

    fVar13 = (float)FUN_1402cdc50(fVar2);

    fVar14 = (float)FUN_1402cfda0(fVar2);

    fVar15 = (float)FUN_1402cdc50(uVar5);

    fVar16 = (float)FUN_1402cfda0(uVar5);

    fVar18 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 200);

    fVar22 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xd4);

    fVar21 = *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0xcc);

    fVar23 = fVar18 * fVar14 - fVar21 * fVar13;

    fVar17 = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0xd0);

    fVar18 = fVar21 * fVar14 + fVar18 * fVar13;

    fVar21 = fVar22 * fVar16 + fVar17 * fVar15;

    fVar16 = fVar17 * fVar16 - fVar22 * fVar15;

    fVar15 = ((fVar21 + fVar6) - fVar4) - fVar18;

    fVar14 = ((fVar16 + fVar1) - fVar3) - fVar23;

    fVar13 = fVar15 * fVar15 + fVar14 * fVar14;

    if (fVar13 < 0.0) {

      fVar13 = (float)FUN_1402cdfa0(fVar13);

    }

    else {

      fVar13 = SQRT(fVar13);

    }

    fVar17 = 0.0;

    if (DAT_14039c9f0 <= fVar13) {

      fVar15 = (DAT_14039ca44 / fVar13) * fVar15;

      fVar14 = (DAT_14039ca44 / fVar13) * fVar14;

      fVar17 = fVar13;

    }

    fVar17 = fVar17 - *(float *)(param_1 + 0xa4);

    fVar13 = *(float *)(param_1 + 0xd8);

    fVar22 = *(float *)(param_1 + 0xdc);

    if (DAT_14039ca2c <= fVar17) {

      fVar17 = DAT_14039ca2c;

    }

    fVar20 = DAT_14039ca7c;

    if (DAT_14039ca7c <= fVar17) {

      fVar20 = fVar17;

    }

    fVar19 = (float)(*(uint *)(param_1 + 0xe8) ^ DAT_14039cac0) * fVar20;

    fVar20 = (float)((uint)fVar20 & _DAT_14039cab0);

    fVar15 = fVar19 * fVar15;

    fVar19 = fVar19 * fVar14;

    fVar14 = *(float *)(param_1 + 0xe0);

    fVar17 = *(float *)(param_1 + 0xe4);

    fVar7 = *(float *)(lVar9 + 8 + lVar12 * 0xc);

    *(float *)(lVar9 + lVar11 * 0xc) = fVar3 - fVar13 * fVar19;

    *(float *)(lVar9 + 4 + lVar11 * 0xc) = fVar4 - fVar13 * fVar15;

    *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xa8) * 0xc) =

         fVar2 - (fVar15 * fVar23 - fVar19 * fVar18) * fVar14;

    iVar8 = *(int *)(param_1 + 0xac);

    lVar9 = *(longlong *)(param_2 + 0x18);

    *(float *)(lVar9 + (longlong)iVar8 * 0xc) = fVar22 * fVar19 + fVar1;

    fVar1 = DAT_14039ca08;

    *(float *)(lVar9 + 4 + (longlong)iVar8 * 0xc) = fVar22 * fVar15 + fVar6;

    *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xac) * 0xc) =

         (fVar15 * fVar16 - fVar19 * fVar21) * fVar17 + fVar7;

    bVar10 = fVar20 < fVar1;

  }

  else {

    bVar10 = true;

  }

  return bVar10;

}




