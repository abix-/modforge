// Address: 0x14000ace0
// Ghidra name: FUN_14000ace0
// ============ 0x14000ace0 FUN_14000ace0 (size=1367) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_14000ace0(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  bool bVar9;

  float fVar10;

  uint uVar11;

  longlong lVar12;

  longlong lVar13;

  uint7 uVar15;

  longlong lVar14;

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

  

  uVar11 = DAT_14039cac0;

  fVar10 = DAT_14039ca14;

  lVar14 = *(longlong *)(param_2 + 0x18);

  fVar28 = 0.0;

  lVar12 = (longlong)*(int *)(param_1 + 0xbc);

  fVar1 = *(float *)(param_1 + 0xec);

  fVar2 = *(float *)(lVar14 + lVar12 * 0xc);

  lVar13 = (longlong)*(int *)(param_1 + 0xc0);

  fVar29 = *(float *)(lVar14 + 8 + lVar12 * 0xc);

  fVar3 = *(float *)(lVar14 + 4 + lVar12 * 0xc);

  fVar4 = *(float *)(lVar14 + lVar13 * 0xc);

  fVar5 = *(float *)(param_1 + 0xf0);

  fVar30 = *(float *)(lVar14 + 8 + lVar13 * 0xc);

  fVar6 = *(float *)(lVar14 + 4 + lVar13 * 0xc);

  if (((*(char *)(param_1 + 0xac) == '\0') || (iVar8 = *(int *)(param_1 + 0x11c), iVar8 == 0)) ||

     (fVar5 + fVar1 == 0.0)) goto LAB_14000aeb1;

  fVar21 = 0.0;

  fVar19 = (fVar30 - fVar29) - *(float *)(param_1 + 0xb0);

  if (iVar8 == 3) {

    fVar19 = fVar19 - *(float *)(param_1 + 0xb4);

    if (DAT_14039ca28 <= fVar19) {

      fVar19 = DAT_14039ca28;

    }

    fVar28 = DAT_14039ca78;

    if (DAT_14039ca78 <= fVar19) {

      fVar28 = fVar19;

    }

    fVar21 = (float)(*(uint *)(param_1 + 0x118) ^ DAT_14039cac0) * fVar28;

    fVar28 = (float)((uint)fVar28 & _DAT_14039cab0);

  }

  else {

    if (iVar8 == 1) {

      fVar19 = fVar19 - *(float *)(param_1 + 0xb4);

      fVar16 = fVar19 + DAT_14039ca14;

      fVar28 = (float)((uint)fVar19 ^ DAT_14039cac0);

      fVar21 = DAT_14039ca78;

      if (0.0 <= fVar16) {

        fVar16 = 0.0;

      }

    }

    else {

      if (iVar8 != 2) goto LAB_14000ae97;

      fVar28 = fVar19 - *(float *)(param_1 + 0xb8);

      fVar16 = fVar28 - DAT_14039ca14;

      if (DAT_14039ca28 <= fVar28 - DAT_14039ca14) {

        fVar16 = DAT_14039ca28;

      }

    }

    if (fVar21 <= fVar16) {

      fVar21 = fVar16;

    }

    fVar21 = fVar21 * (float)(*(uint *)(param_1 + 0x118) ^ DAT_14039cac0);

  }

LAB_14000ae97:

  fVar29 = fVar29 - fVar1 * fVar21;

  fVar30 = fVar30 + fVar5 * fVar21;

LAB_14000aeb1:

  fVar19 = (float)FUN_1402cdc50(fVar29);

  fVar21 = (float)FUN_1402cfda0(fVar29);

  fVar16 = (float)FUN_1402cdc50(fVar30);

  fVar17 = (float)FUN_1402cfda0(fVar30);

  fVar24 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);

  fVar22 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);

  fVar18 = fVar21 * fVar24 - fVar19 * fVar22;

  fVar23 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);

  fVar24 = fVar21 * fVar22 + fVar19 * fVar24;

  fVar19 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);

  fVar22 = fVar17 * fVar23 - fVar16 * fVar19;

  fVar17 = fVar17 * fVar19 + fVar16 * fVar23;

  fVar16 = ((fVar4 + fVar22) - fVar2) - fVar18;

  fVar19 = ((fVar6 + fVar17) - fVar3) - fVar24;

  fVar21 = fVar19 * fVar19 + fVar16 * fVar16;

  if (fVar21 < 0.0) {

    fVar21 = (float)FUN_1402cdfa0(fVar21);

  }

  else {

    fVar21 = SQRT(fVar21);

  }

  fVar23 = *(float *)(param_1 + 0xe8);

  fVar7 = *(float *)(param_1 + 0xe4);

  fVar25 = fVar1 * fVar24 * fVar24 + fVar23 + fVar7 + fVar5 * fVar17 * fVar17;

  fVar27 = (float)((uint)fVar1 ^ uVar11) * fVar18 * fVar24 - fVar5 * fVar22 * fVar17;

  fVar26 = fVar1 * fVar18 * fVar18 + fVar23 + fVar7 + fVar5 * fVar22 * fVar22;

  fVar20 = fVar26 * fVar25 - fVar27 * fVar27;

  if (fVar20 != 0.0) {

    fVar20 = DAT_14039ca44 / fVar20;

  }

  fVar26 = (float)((uint)((fVar26 * fVar16 - fVar27 * fVar19) * fVar20) ^ uVar11);

  fVar19 = (float)((uint)((fVar25 * fVar19 - fVar27 * fVar16) * fVar20) ^ uVar11);

  *(float *)(lVar14 + lVar12 * 0xc) = fVar2 - fVar26 * fVar7;

  *(float *)(lVar14 + 4 + lVar12 * 0xc) = fVar3 - fVar19 * fVar7;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xbc) * 0xc) =

       fVar29 - (fVar19 * fVar18 - fVar26 * fVar24) * fVar1;

  iVar8 = *(int *)(param_1 + 0xc0);

  lVar14 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar14 + (longlong)iVar8 * 0xc) = fVar26 * fVar23 + fVar4;

  bVar9 = DAT_14039ca08 < fVar21;

  *(float *)(lVar14 + 4 + (longlong)iVar8 * 0xc) = fVar19 * fVar23 + fVar6;

  lVar14 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar14 + 8 + (longlong)*(int *)(param_1 + 0xc0) * 0xc) =

       (fVar19 * fVar22 - fVar26 * fVar17) * fVar5 + fVar30;

  uVar15 = (uint7)((ulonglong)lVar14 >> 8);

  if ((bVar9) || (fVar10 < fVar28)) {

    lVar14 = (ulonglong)uVar15 << 8;

  }

  else {

    lVar14 = CONCAT71(uVar15,1);

  }

  return lVar14;

}




