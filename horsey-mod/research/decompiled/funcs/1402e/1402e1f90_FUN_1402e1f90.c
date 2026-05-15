// Address: 0x1402e1f90
// Ghidra name: FUN_1402e1f90
// ============ 0x1402e1f90 FUN_1402e1f90 (size=671) ============


double FUN_1402e1f90(double param_1)



{

  double dVar1;

  double dVar2;

  uint uVar3;

  uint uVar5;

  double dVar4;

  double dVar6;

  double dVar7;

  

  uVar5 = (uint)((ulonglong)param_1 >> 0x20);

  dVar4 = 0.0;

  uVar3 = uVar5 >> 0x14 & 0x7ff;

  if (0x7ff0000000000000 < (ulonglong)ABS(param_1)) {

    dVar4 = (double)FUN_1402e9080();

    return dVar4;

  }

  if (uVar3 < 0x3c7) {

    FUN_1402e8cc0(0x20);

    return DAT_140388af0;

  }

  if (uVar3 < 0x3ff) {

    dVar6 = param_1;

    if ((longlong)param_1 < 0) {

      dVar6 = (double)CONCAT44(uVar5 ^ DAT_140305470._4_4_,SUB84(param_1,0) ^ (uint)DAT_140305470);

    }

    if (uVar3 < 0x3fe) {

      dVar7 = dVar6 * dVar6;

    }

    else {

      dVar7 = (DAT_140304b90 - dVar6) * DAT_140304b70;

      dVar6 = SQRT(dVar7);

      dVar4 = dVar6;

    }

    dVar1 = ((((((dVar7 * DAT_14038abd8 + DAT_14038abe0) * dVar7 - DAT_14038abe8) * dVar7 +

               DAT_14038ac00) * dVar7 - DAT_14038ac08) * dVar7 + DAT_14038abf8) * dVar7) /

            ((((dVar7 * DAT_14038abf0 - DAT_14038ac10) * dVar7 + DAT_14038ac20) * dVar7 -

             DAT_14038ac28) * dVar7 + DAT_14038ac18);

    if (uVar3 < 0x3fe) {

      return DAT_140388af0 - (param_1 - (DAT_14038abd0 - dVar1 * param_1));

    }

    if (-1 < (longlong)param_1) {

      dVar2 = (double)((ulonglong)dVar4 & 0xffffffff00000000);

      dVar4 = (dVar7 - dVar2 * dVar2) / ((double)((ulonglong)dVar4 & 0xffffffff00000000) + dVar4);

      return (dVar6 + dVar6) * dVar1 + dVar4 + dVar4 + dVar2 + dVar2;

    }

    dVar4 = (dVar6 * dVar1 - DAT_14038abd0) + dVar4;

    return DAT_140333080 - (dVar4 + dVar4);

  }

  if (param_1 == DAT_140304b90) {

    return 0.0;

  }

  if (param_1 != DAT_140388e08) {

    dVar4 = (double)FUN_1402e8e00(&DAT_14038abc8,0xd,0xfff8000000000000,1,8,0x21,param_1,0,1);

    return dVar4;

  }

  FUN_1402e8cc0(0x20);

  return DAT_140333080;

}




