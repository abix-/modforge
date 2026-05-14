// Address: 0x1402f1f20
// Ghidra name: FUN_1402f1f20
// ============ 0x1402f1f20 FUN_1402f1f20 (size=508) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402f1f20(float param_1)



{

  double dVar1;

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  float fVar4;

  uint uVar5;

  ulonglong uVar6;

  float fVar7;

  float fVar8;

  undefined1 auVar9 [16];

  float fVar10;

  

  uVar5 = (uint)param_1 >> 0x17 & 0xff;

  fVar7 = 0.0;

  if (0x7f800000 < (uint)ABS(param_1)) {

    uVar6 = FUN_1402f5700();

    return uVar6;

  }

  if (uVar5 < 0x65) {

    FUN_1402e8cc0(0x20);

    return (ulonglong)DAT_14039ca48;

  }

  if (uVar5 < 0x7f) {

    fVar8 = param_1;

    if ((int)param_1 < 0) {

      fVar8 = (float)((uint)param_1 ^ DAT_14039cac0);

    }

    if (uVar5 < 0x7e) {

      fVar10 = fVar8 * fVar8;

    }

    else {

      fVar10 = (DAT_14039ca44 - fVar8) * DAT_14039ca34;

      auVar2 = vsqrtss_avx(ZEXT416((uint)fVar10),ZEXT416((uint)fVar10));

      fVar7 = auVar2._0_4_;

      fVar8 = fVar7;

    }

    auVar2 = vfnmadd213ss_fma(ZEXT416(DAT_14038ac38),ZEXT416((uint)fVar10),ZEXT416(DAT_14038ac4c));

    auVar2 = vfmsub213ss_fma(auVar2,ZEXT416((uint)fVar10),ZEXT416(DAT_14038ac3c));

    auVar9 = ZEXT416((uint)fVar10);

    auVar2 = vfmadd213ss_fma(auVar2,auVar9,ZEXT416(DAT_14038ac40));

    auVar3 = vfnmadd213ss_fma(ZEXT416(DAT_14038ac44),auVar9,ZEXT416(DAT_14038ac48));

    fVar10 = (auVar2._0_4_ * fVar10) / auVar3._0_4_;

    if (uVar5 >= 0x7e) {

      if ((int)param_1 < 0) {

        dVar1 = ((double)(fVar8 * fVar10) - DAT_14038abd0) + (double)fVar7;

        dVar1 = DAT_140333080 - (dVar1 + dVar1);

        return CONCAT44((int)((ulonglong)dVar1 >> 0x20),(float)dVar1);

      }

      fVar4 = (float)((uint)fVar7 & 0xffff0000);

      auVar2 = vfnmadd231ss_fma(auVar9,ZEXT416((uint)fVar4),ZEXT416((uint)fVar4));

      fVar7 = auVar2._0_4_ / (fVar4 + fVar7);

      auVar2 = vfmadd231ss_fma(ZEXT416((uint)(fVar7 + fVar7)),ZEXT416((uint)fVar10),

                               ZEXT416((uint)(fVar8 + fVar8)));

      return (ulonglong)(uint)(auVar2._0_4_ + fVar4 + fVar4);

    }

    dVar1 = DAT_140388af0 - ((double)param_1 - (DAT_14038abd0 - (double)(fVar10 * param_1)));

    return CONCAT44((int)((ulonglong)dVar1 >> 0x20),(float)dVar1);

  }

  if (param_1 == DAT_14039ca44) {

    return 0;

  }

  if (param_1 == DAT_14039ca80) {

    FUN_1402e8cc0(0x20);

    return (ulonglong)DAT_14039ca50;

  }

  uVar6 = FUN_1402e8f40("acosf",0xd,0xffc00000,1,8,0x21);

  return uVar6;

}




