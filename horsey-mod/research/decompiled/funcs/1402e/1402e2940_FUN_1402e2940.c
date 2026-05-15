// Address: 0x1402e2940
// Ghidra name: FUN_1402e2940
// ============ 0x1402e2940 FUN_1402e2940 (size=556) ============


double FUN_1402e2940(double param_1)



{

  double dVar1;

  double dVar2;

  bool bVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  

  dVar2 = ABS(param_1);

  bVar3 = param_1 != dVar2;

  if (bVar3) {

    param_1 = (double)CONCAT44((uint)((ulonglong)param_1 >> 0x20) ^ DAT_140305470._4_4_,

                               SUB84(param_1,0) ^ (uint)DAT_140305470);

  }

  if ((ulonglong)dVar2 < 0x4003800000000001) {

    if ((ulonglong)dVar2 < 0x3ff3000000000001) {

      if ((ulonglong)dVar2 < 0x3fe6000000000001) {

        if ((ulonglong)dVar2 < 0x3fdc000000000001) {

          dVar2 = 0.0;

          uVar4 = 0;

          uVar5 = 0;

        }

        else {

          uVar4 = (undefined4)DAT_14038ac80;

          uVar5 = (undefined4)((ulonglong)DAT_14038ac80 >> 0x20);

          param_1 = ((param_1 + param_1) - DAT_140304b90) / (param_1 + DAT_14030ec18);

          dVar2 = DAT_14038acd0;

        }

      }

      else {

        uVar4 = (undefined4)DAT_14038ac88;

        uVar5 = (undefined4)((ulonglong)DAT_14038ac88 >> 0x20);

        param_1 = (param_1 - DAT_140304b90) / (param_1 + DAT_140304b90);

        dVar2 = DAT_14038ac58;

      }

    }

    else {

      uVar4 = (undefined4)DAT_14038ac78;

      uVar5 = (undefined4)((ulonglong)DAT_14038ac78 >> 0x20);

      param_1 = (param_1 - DAT_140304b98) / (param_1 * DAT_140304b98 + DAT_140304b90);

      dVar2 = DAT_14038ace0;

    }

  }

  else {

    if (0x7ff0000000000000 < (ulonglong)dVar2) {

      dVar2 = (double)FUN_1402e9080();

      return dVar2;

    }

    if (DAT_14038acf8 < param_1) {

      if (bVar3) {

        FUN_1402e8cc0(0x20);

        return DAT_14038ac60;

      }

      FUN_1402e8cc0(0x20);

      return DAT_140388af0;

    }

    uVar4 = (undefined4)DAT_14038ac90;

    uVar5 = (undefined4)((ulonglong)DAT_14038ac90 >> 0x20);

    param_1 = DAT_140388e08 / param_1;

    dVar2 = DAT_140388af0;

  }

  dVar1 = param_1 * param_1;

  dVar2 = dVar2 - (((((((dVar1 * DAT_14038ac98 + DAT_14038aca0) * dVar1 + DAT_14038acb0) * dVar1 +

                      DAT_14038acc8) * dVar1 + DAT_14038acb8) * dVar1 * param_1) /

                    ((((dVar1 * DAT_14038aca8 + DAT_14038acc0) * dVar1 + DAT_14038ace8) * dVar1 +

                     DAT_14038acf0) * dVar1 + DAT_14038acd8) - (double)CONCAT44(uVar5,uVar4)) -

                  param_1);

  if (bVar3) {

    dVar2 = (double)CONCAT44((uint)((ulonglong)dVar2 >> 0x20) ^ DAT_140305470._4_4_,

                             SUB84(dVar2,0) ^ (uint)DAT_140305470);

  }

  return dVar2;

}




