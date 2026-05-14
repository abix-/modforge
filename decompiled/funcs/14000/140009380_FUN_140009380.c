// Address: 0x140009380
// Ghidra name: FUN_140009380
// ============ 0x140009380 FUN_140009380 (size=2027) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



longlong FUN_140009380(longlong param_1,longlong param_2)



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

  int iVar11;

  bool bVar12;

  uint uVar13;

  longlong lVar14;

  longlong lVar15;

  undefined8 *puVar16;

  uint7 uVar18;

  longlong lVar17;

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

  float fVar34;

  float fVar35;

  float fVar36;

  float fVar37;

  uint uVar38;

  float fVar39;

  float fVar40;

  float fVar41;

  float local_e8;

  uint uStack_e4;

  uint local_e0;

  undefined1 local_d8 [16];

  undefined1 local_c8 [176];

  

  lVar17 = *(longlong *)(param_2 + 0x18);

  lVar14 = (longlong)*(int *)(param_1 + 0xcc);

  lVar15 = (longlong)*(int *)(param_1 + 0xd0);

  fVar1 = *(float *)(lVar17 + 8 + lVar14 * 0xc);

  fVar2 = *(float *)(lVar17 + lVar14 * 0xc);

  fVar3 = *(float *)(lVar17 + 4 + lVar14 * 0xc);

  fVar4 = *(float *)(lVar17 + lVar15 * 0xc);

  fVar5 = *(float *)(lVar17 + 4 + lVar15 * 0xc);

  fVar6 = *(float *)(lVar17 + 8 + lVar15 * 0xc);

  fVar19 = (float)FUN_1402cdc50(fVar1);

  fVar20 = (float)FUN_1402cfda0(fVar1);

  fVar21 = (float)FUN_1402cdc50(fVar6);

  fVar22 = (float)FUN_1402cfda0(fVar6);

  fVar40 = DAT_14039ca44;

  fVar24 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xd4);

  fVar33 = *(float *)(param_1 + 0x8c) - *(float *)(param_1 + 0xe0);

  fVar7 = *(float *)(param_1 + 0xe8);

  fVar29 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xd8);

  fVar8 = *(float *)(param_1 + 0xe4);

  fVar9 = *(float *)(param_1 + 0xec);

  fVar10 = *(float *)(param_1 + 0xf0);

  fVar30 = fVar29 * fVar20 + fVar24 * fVar19;

  fVar25 = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0xdc);

  fVar24 = fVar24 * fVar20 - fVar29 * fVar19;

  fVar34 = fVar33 * fVar22 + fVar25 * fVar21;

  fVar32 = fVar25 * fVar22 - fVar33 * fVar21;

  fVar31 = ((fVar32 + fVar4) - fVar2) - fVar24;

  fVar22 = ((fVar34 + fVar5) - fVar3) - fVar30;

  bVar12 = false;

  fVar24 = fVar31 + fVar24;

  fVar41 = *(float *)(param_1 + 0x90) * fVar20 - *(float *)(param_1 + 0x94) * fVar19;

  fVar30 = fVar22 + fVar30;

  fVar39 = *(float *)(param_1 + 0x90) * fVar19 + *(float *)(param_1 + 0x94) * fVar20;

  fVar21 = 0.0;

  fVar33 = *(float *)(param_1 + 0x98) * fVar20 - *(float *)(param_1 + 0x9c) * fVar19;

  fVar25 = *(float *)(param_1 + 0x98) * fVar19 + *(float *)(param_1 + 0x9c) * fVar20;

  fVar29 = (fVar6 - fVar1) - *(float *)(param_1 + 0xa0);

  fVar19 = 0.0;

  fVar37 = fVar25 * fVar22 + fVar33 * fVar31;

  local_d8 = ZEXT416((uint)fVar29 & _DAT_14039cab0);

  fVar20 = (float)((uint)fVar37 & _DAT_14039cab0);

  if (*(char *)(param_1 + 0xc4) == '\0') goto LAB_140009753;

  fVar26 = *(float *)(param_1 + 0xb8);

  fVar27 = *(float *)(param_1 + 0xb4);

  fVar22 = fVar41 * fVar31 + fVar39 * fVar22;

  if (DAT_14039ca0c <= (float)((uint)(fVar26 - fVar27) & _DAT_14039cab0)) {

    if (fVar27 < fVar22) {

      if (fVar22 < fVar26) goto LAB_140009753;

      fVar26 = fVar22 - fVar26;

      fVar22 = fVar26 - DAT_14039ca08;

      goto LAB_140009741;

    }

    fVar31 = (fVar22 - fVar27) + DAT_14039ca08;

    if (fVar20 <= fVar27 - fVar22) {

      fVar20 = fVar27 - fVar22;

    }

    fVar19 = DAT_14039ca7c;

    if (0.0 <= fVar31) {

      fVar31 = 0.0;

    }

  }

  else {

    fVar26 = (float)((uint)fVar22 & _DAT_14039cab0);

    fVar19 = DAT_14039ca7c;

LAB_140009741:

    fVar31 = fVar22;

    if (DAT_14039ca2c <= fVar22) {

      fVar31 = DAT_14039ca2c;

    }

    if (fVar20 <= fVar26) {

      fVar20 = fVar26;

    }

  }

  if (fVar19 <= fVar31) {

    fVar19 = fVar31;

  }

  bVar12 = true;

LAB_140009753:

  fVar31 = fVar10 + fVar9;

  fVar27 = fVar10 * *(float *)(param_1 + 0x108);

  fVar26 = fVar7 + fVar8;

  fVar22 = *(float *)(param_1 + 0x104);

  fVar28 = fVar9 * fVar22;

  fVar36 = fVar27 * *(float *)(param_1 + 0x108);

  fVar35 = fVar27 + fVar28;

  if (bVar12) {

    fVar21 = *(float *)(param_1 + 0x110);

    fVar40 = *(float *)(param_1 + 0x10c);

    fVar27 = fVar21 * fVar27 + fVar28 * fVar40;

    if (fVar31 == 0.0) {

      fVar31 = DAT_14039ca44;

    }

    fVar23 = fVar21 * fVar10 + fVar40 * fVar9;

    *(float *)(param_1 + 0x118) = fVar35;

    *(float *)(param_1 + 0x11c) = fVar27;

    *(float *)(param_1 + 0x128) = fVar23;

    *(float *)(param_1 + 0x130) = fVar23;

    *(float *)(param_1 + 0x114) = fVar22 * fVar28 + fVar26 + fVar36;

    *(float *)(param_1 + 0x120) = fVar35;

    *(float *)(param_1 + 0x124) = fVar31;

    uVar13 = DAT_14039cac0;

    uVar38 = (uint)fVar37 ^ DAT_14039cac0;

    *(float *)(param_1 + 300) = fVar27;

    local_e0 = (uint)fVar19 ^ uVar13;

    _local_e8 = CONCAT44((uint)fVar29 ^ uVar13,uVar38);

    *(float *)(param_1 + 0x134) = fVar40 * fVar40 * fVar9 + fVar26 + fVar21 * fVar21 * fVar10;

    puVar16 = (undefined8 *)FUN_140007a90((float *)(param_1 + 0x114),local_c8,&local_e8);

    fVar19 = (float)((ulonglong)*puVar16 >> 0x20);

    fVar21 = *(float *)(puVar16 + 1);

    local_e8 = (float)*puVar16;

  }

  else {

    fVar36 = fVar28 * fVar22 + fVar26 + fVar36;

    if (fVar31 == 0.0) {

      fVar31 = DAT_14039ca44;

    }

    fVar37 = (float)((uint)fVar37 ^ DAT_14039cac0);

    fVar29 = (float)((uint)fVar29 ^ DAT_14039cac0);

    *(undefined4 *)(param_1 + 0x11c) = 0;

    *(undefined4 *)(param_1 + 0x128) = 0;

    *(float *)(param_1 + 0x114) = fVar36;

    *(float *)(param_1 + 0x118) = fVar35;

    fVar19 = fVar31 * fVar36 - fVar35 * fVar35;

    *(float *)(param_1 + 0x120) = fVar35;

    *(float *)(param_1 + 0x124) = fVar31;

    if (fVar19 != 0.0) {

      fVar19 = fVar40 / fVar19;

    }

    local_e8 = (fVar37 * fVar31 - fVar29 * fVar35) * fVar19;

    fVar19 = (fVar29 * fVar36 - fVar37 * fVar35) * fVar19;

  }

  iVar11 = *(int *)(param_1 + 0xcc);

  fVar22 = fVar41 * fVar21 + fVar33 * local_e8;

  fVar40 = fVar39 * fVar21 + fVar25 * local_e8;

  *(float *)(lVar17 + (longlong)iVar11 * 0xc) = fVar2 - fVar22 * fVar8;

  *(float *)(lVar17 + 4 + (longlong)iVar11 * 0xc) = fVar3 - fVar40 * fVar8;

  *(float *)(*(longlong *)(param_2 + 0x18) + 8 + (longlong)*(int *)(param_1 + 0xcc) * 0xc) =

       fVar1 - ((fVar25 * fVar24 - fVar33 * fVar30) * local_e8 + fVar19 +

               (fVar24 * fVar39 - fVar30 * fVar41) * fVar21) * fVar9;

  iVar11 = *(int *)(param_1 + 0xd0);

  lVar17 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar17 + (longlong)iVar11 * 0xc) = fVar22 * fVar7 + fVar4;

  *(float *)(lVar17 + 4 + (longlong)iVar11 * 0xc) = fVar40 * fVar7 + fVar5;

  bVar12 = DAT_14039ca08 < fVar20;

  lVar17 = *(longlong *)(param_2 + 0x18);

  *(float *)(lVar17 + 8 + (longlong)*(int *)(param_1 + 0xd0) * 0xc) =

       ((fVar25 * fVar32 - fVar33 * fVar34) * local_e8 + fVar19 +

       (fVar39 * fVar32 - fVar41 * fVar34) * fVar21) * fVar10 + fVar6;

  uVar18 = (uint7)((ulonglong)lVar17 >> 8);

  if ((bVar12) || (DAT_14039ca14 < (float)local_d8._0_4_)) {

    lVar17 = (ulonglong)uVar18 << 8;

  }

  else {

    lVar17 = CONCAT71(uVar18,1);

  }

  return lVar17;

}




