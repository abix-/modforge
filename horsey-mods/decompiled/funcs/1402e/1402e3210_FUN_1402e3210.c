// Address: 0x1402e3210
// Ghidra name: FUN_1402e3210
// ============ 0x1402e3210 FUN_1402e3210 (size=473) ============


ulonglong FUN_1402e3210(float param_1)



{

  double dVar1;

  ulonglong uVar2;

  double dVar3;

  double dVar4;

  double dVar5;

  

  dVar4 = (double)param_1;

  dVar1 = ABS(dVar4);

  dVar5 = dVar4;

  if ((longlong)dVar4 < 0) {

    dVar5 = (double)CONCAT44((uint)((ulonglong)dVar4 >> 0x20) ^ DAT_140305470._4_4_,

                             SUB84(dVar4,0) ^ (uint)DAT_140305470);

  }

  if ((ulonglong)dVar1 < 0x3fdc000000000000) {

    dVar1 = 0.0;

  }

  else if ((ulonglong)dVar1 < 0x3fe6000000000000) {

    dVar5 = ((dVar5 + dVar5) - DAT_140304b90) / (dVar5 + DAT_14030ec18);

    dVar1 = DAT_14038acd0;

  }

  else if ((ulonglong)dVar1 < 0x3ff3000000000000) {

    dVar5 = (dVar5 - DAT_140304b90) / (dVar5 + DAT_140304b90);

    dVar1 = DAT_14038ac58;

  }

  else if ((ulonglong)dVar1 < 0x4003800000000000) {

    dVar5 = (dVar5 - DAT_140304b98) / (dVar5 * DAT_140304b98 + DAT_140304b90);

    dVar1 = DAT_14038ace0;

  }

  else {

    if (0x7ff0000000000000 < (ulonglong)dVar1) {

      uVar2 = FUN_1402e90a0(param_1);

      return uVar2;

    }

    if (DAT_14038bcb8 < dVar5) {

      if ((longlong)dVar4 < 0) {

        FUN_1402e8cc0(0x20);

        return (ulonglong)DAT_14030d9f8;

      }

      FUN_1402e8cc0(0x20);

      return (ulonglong)DAT_14039ca48;

    }

    dVar5 = DAT_140388e08 / dVar5;

    dVar1 = DAT_140388af0;

  }

  dVar3 = dVar5 * dVar5;

  dVar1 = dVar1 - ((((dVar3 * DAT_14038bc88 + DAT_14038bc90) * dVar3 + DAT_14038bc98) *

                   dVar5 * dVar3) /

                   ((dVar3 * DAT_14038bca0 + DAT_14038bcb0) * dVar3 + DAT_14038bca8) - dVar5);

  if ((longlong)dVar4 < 0) {

    dVar1 = (double)CONCAT44((uint)((ulonglong)dVar1 >> 0x20) ^ DAT_140305470._4_4_,

                             SUB84(dVar1,0) ^ (uint)DAT_140305470);

  }

  return (ulonglong)(uint)(float)dVar1;

}




