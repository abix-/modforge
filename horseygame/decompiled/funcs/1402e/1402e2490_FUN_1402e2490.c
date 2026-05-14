// Address: 0x1402e2490
// Ghidra name: FUN_1402e2490
// ============ 0x1402e2490 FUN_1402e2490 (size=621) ============


double FUN_1402e2490(double param_1)



{

  double dVar1;

  uint uVar2;

  double dVar3;

  double dVar4;

  double dVar5;

  uint uVar6;

  uint uVar7;

  

  uVar6 = SUB84(param_1,0);

  uVar7 = (uint)((ulonglong)param_1 >> 0x20);

  dVar3 = 0.0;

  uVar2 = uVar7 >> 0x14 & 0x7ff;

  if (0x7ff0000000000000 < (ulonglong)ABS(param_1)) {

    dVar3 = (double)FUN_1402e9080();

    return dVar3;

  }

  if (uVar2 < 0x3e3) {

    FUN_1402e8cc0(0x20);

    return param_1;

  }

  if (uVar2 < 0x3ff) {

    if ((longlong)param_1 < 0) {

      uVar6 = uVar6 ^ (uint)DAT_140305470;

      uVar7 = uVar7 ^ DAT_140305470._4_4_;

    }

    dVar1 = (double)CONCAT44(uVar7,uVar6);

    if (uVar2 < 0x3fe) {

      dVar4 = (double)CONCAT44(uVar7,uVar6) * (double)CONCAT44(uVar7,uVar6);

    }

    else {

      dVar4 = (DAT_140304b90 - (double)CONCAT44(uVar7,uVar6)) * DAT_140304b70;

      dVar3 = SQRT(dVar4);

      dVar1 = dVar3;

    }

    dVar5 = ((((((dVar4 * DAT_14038abd8 + DAT_14038abe0) * dVar4 - DAT_14038abe8) * dVar4 +

               DAT_14038ac00) * dVar4 - DAT_14038ac08) * dVar4 + DAT_14038abf8) * dVar4) /

            ((((dVar4 * DAT_14038abf0 - DAT_14038ac10) * dVar4 + DAT_14038ac20) * dVar4 -

             DAT_14038ac28) * dVar4 + DAT_14038ac18);

    if (uVar2 < 0x3fe) {

      dVar1 = dVar1 * dVar5 + dVar1;

    }

    else {

      dVar1 = (double)((ulonglong)dVar3 & 0xffffffff00000000);

      dVar4 = (dVar4 - dVar1 * dVar1) / ((double)((ulonglong)dVar3 & 0xffffffff00000000) + dVar3);

      dVar1 = DAT_14038ac58 -

              (((dVar3 + dVar3) * dVar5 - (DAT_14038abd0 - (dVar4 + dVar4))) -

              (DAT_14038ac58 - (dVar1 + dVar1)));

    }

    if ((longlong)param_1 < 0) {

      dVar1 = (double)(ulonglong)(SUB84(dVar1,0) ^ (uint)DAT_140305470);

    }

    return dVar1;

  }

  if (param_1 != DAT_140304b90) {

    if (param_1 != DAT_140388e08) {

      dVar3 = (double)FUN_1402e8e00(&DAT_14038ac50,0xe,0xfff8000000000000,1,8,0x21,param_1,0,1);

      return dVar3;

    }

    FUN_1402e8cc0(0x20);

    return DAT_14038ac60;

  }

  FUN_1402e8cc0(0x20);

  return DAT_140388af0;

}




