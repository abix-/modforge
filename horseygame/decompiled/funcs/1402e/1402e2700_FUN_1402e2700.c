// Address: 0x1402e2700
// Ghidra name: FUN_1402e2700
// ============ 0x1402e2700 FUN_1402e2700 (size=22) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402e2700(void)



{

  undefined1 auVar1 [16];

  float fVar2;

  uint uVar3;

  float fVar4;

  ulonglong uVar5;

  undefined1 auVar6 [16];

  undefined1 in_ZMM0 [64];

  float fVar7;

  undefined1 auVar8 [16];

  undefined1 auVar9 [64];

  float fVar10;

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  

  if (((byte)DAT_1403ff158 & 3) != 3) {

    uVar5 = FUN_1402e2720();

    return uVar5;

  }

  fVar4 = in_ZMM0._0_4_;

  uVar3 = (uint)fVar4 >> 0x17 & 0xff;

  auVar6 = in_ZMM0._0_16_;

  auVar9 = ZEXT1664(auVar6);

  auVar11._0_12_ = ZEXT812(0);

  auVar11._12_4_ = 0;

  if (0x7f800000 < (uint)ABS(fVar4)) {

    uVar5 = FUN_1402f5700();

    return uVar5;

  }

  if (uVar3 < 0x71) {

    FUN_1402e8cc0(0x20);

    return auVar9._0_8_;

  }

  if (0x7e < uVar3) {

    if (fVar4 == DAT_14039ca44) {

      FUN_1402e8cc0(0x20);

      return (ulonglong)DAT_14039ca48;

    }

    if (fVar4 != DAT_14039ca80) {

      uVar5 = FUN_1402e8f40("asinf",0xe,0xffc00000,1,8,0x21);

      return uVar5;

    }

    FUN_1402e8cc0(0x20);

    return (ulonglong)DAT_14030d9f8;

  }

  if ((int)fVar4 < 0) {

    auVar6._0_4_ = (uint)fVar4 ^ DAT_14039cac0;

    auVar6._4_4_ = in_ZMM0._4_4_ ^ _UNK_14039cac4;

    auVar6._8_4_ = in_ZMM0._8_4_ ^ _UNK_14039cac8;

    auVar6._12_4_ = in_ZMM0._12_4_ ^ _UNK_14039cacc;

  }

  fVar2 = auVar6._0_4_;

  if (uVar3 < 0x7e) {

    fVar2 = fVar2 * fVar2;

  }

  else {

    fVar2 = (DAT_14039ca44 - fVar2) * DAT_14039ca34;

    auVar11 = vsqrtss_avx(ZEXT416((uint)fVar2),ZEXT416((uint)fVar2));

    auVar6 = auVar11;

  }

  auVar12 = vfnmadd213ss_fma(ZEXT416(DAT_14038ac38),ZEXT416((uint)fVar2),ZEXT416(DAT_14038ac4c));

  auVar12 = vfmsub213ss_fma(auVar12,ZEXT416((uint)fVar2),ZEXT416(DAT_14038ac3c));

  auVar8 = ZEXT416((uint)fVar2);

  auVar12 = vfmadd213ss_fma(auVar12,auVar8,ZEXT416(DAT_14038ac40));

  auVar1 = vfnmadd213ss_fma(ZEXT416(DAT_14038ac44),auVar8,ZEXT416(DAT_14038ac48));

  auVar12 = ZEXT416((uint)((auVar12._0_4_ * fVar2) / auVar1._0_4_));

  if (uVar3 < 0x7e) {

    auVar11 = vfmadd231ss_fma(auVar6,auVar12,auVar6);

    uVar5 = auVar11._0_8_;

  }

  else {

    fVar10 = auVar11._0_4_;

    fVar2 = (float)((uint)fVar10 & 0xffff0000);

    auVar11 = vfnmadd231ss_fma(auVar8,ZEXT416((uint)fVar2),ZEXT416((uint)fVar2));

    fVar7 = auVar11._0_4_ / (fVar2 + fVar10);

    auVar11 = vfmsub231ss_fma(ZEXT416((uint)(DAT_14038ac70 - (fVar7 + fVar7))),auVar12,

                              ZEXT416((uint)(fVar10 + fVar10)));

    uVar5 = (ulonglong)(uint)(DAT_14038ac74 - (auVar11._0_4_ - (DAT_14038ac74 - (fVar2 + fVar2))));

  }

  if ((int)fVar4 < 0) {

    uVar5 = CONCAT44((uint)(uVar5 >> 0x20) ^ _UNK_14039cac4,(uint)uVar5 ^ DAT_14039cac0);

  }

  return uVar5;

}




