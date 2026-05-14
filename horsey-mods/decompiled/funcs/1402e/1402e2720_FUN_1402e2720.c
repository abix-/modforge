// Address: 0x1402e2720
// Ghidra name: FUN_1402e2720
// ============ 0x1402e2720 FUN_1402e2720 (size=507) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402e2720(ulonglong param_1)



{

  uint uVar1;

  float fVar2;

  ulonglong uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  uint uVar8;

  

  uVar8 = (uint)(param_1 >> 0x20);

  fVar2 = (float)param_1;

  fVar5 = 0.0;

  uVar1 = (uint)fVar2 >> 0x17 & 0xff;

  if (0x7f800000 < (uint)ABS(fVar2)) {

    uVar3 = FUN_1402e90a0();

    return uVar3;

  }

  if (uVar1 < 0x71) {

    FUN_1402e8cc0(0x20);

    return param_1;

  }

  if (uVar1 < 0x7f) {

    fVar7 = fVar2;

    if ((int)fVar2 < 0) {

      fVar7 = (float)((uint)fVar2 ^ DAT_14039cac0);

      uVar8 = uVar8 ^ _UNK_14039cac4;

    }

    if (uVar1 < 0x7e) {

      fVar4 = fVar7 * fVar7;

    }

    else {

      fVar4 = (DAT_14039ca44 - fVar7) * DAT_14039ca34;

      fVar5 = SQRT(fVar4);

      uVar8 = 0;

      fVar7 = fVar5;

    }

    fVar6 = ((((DAT_14038ac4c - fVar4 * DAT_14038ac38) * fVar4 - DAT_14038ac3c) * fVar4 +

             DAT_14038ac40) * fVar4) / (DAT_14038ac48 - fVar4 * DAT_14038ac44);

    if (uVar1 < 0x7e) {

      fVar7 = fVar7 * fVar6 + fVar7;

    }

    else {

      fVar7 = (float)((uint)fVar5 & 0xffff0000);

      fVar4 = (fVar4 - fVar7 * fVar7) / (fVar7 + fVar5);

      uVar8 = 0;

      fVar7 = DAT_14038ac74 -

              (((fVar5 + fVar5) * fVar6 - (DAT_14038ac70 - (fVar4 + fVar4))) -

              (DAT_14038ac74 - (fVar7 + fVar7)));

    }

    if ((int)fVar2 < 0) {

      fVar7 = (float)((uint)fVar7 ^ DAT_14039cac0);

      uVar8 = uVar8 ^ _UNK_14039cac4;

    }

    return CONCAT44(uVar8,fVar7);

  }

  if (fVar2 != DAT_14039ca44) {

    if (fVar2 != DAT_14039ca80) {

      uVar3 = FUN_1402e8f40("asinf",0xe,0xffc00000,1,8,0x21,fVar2,0,1);

      return uVar3;

    }

    FUN_1402e8cc0(0x20);

    return (ulonglong)DAT_14030d9f8;

  }

  FUN_1402e8cc0(0x20);

  return (ulonglong)DAT_14039ca48;

}




