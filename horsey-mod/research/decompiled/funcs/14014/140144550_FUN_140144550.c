// Address: 0x140144550
// Ghidra name: FUN_140144550
// ============ 0x140144550 FUN_140144550 (size=298) ============


undefined8

FUN_140144550(uint param_1,ulonglong param_2,ulonglong param_3,longlong *param_4,ulonglong *param_5,

             char param_6)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  ulonglong uVar4;

  ulonglong uVar5;

  byte bVar6;

  undefined8 uVar7;

  uint uVar8;

  

  uVar8 = param_1 >> 0x1c;

  if ((param_1 == 0) || (uVar8 == 1)) {

    bVar6 = (byte)(param_1 >> 8);

    if (bVar6 < 8) {

      if ((param_1 != 0) && (uVar8 != 1)) goto LAB_1401445e2;

      uVar8 = (uint)bVar6;

      goto LAB_1401445e9;

    }

    if ((param_1 == 0) || (uVar8 == 1)) {

      uVar4 = (ulonglong)(param_1 & 0xff);

    }

    else if ((((param_1 == 0x32595559) || (param_1 == 0x59565955)) || (param_1 == 0x55595659)) ||

            (param_1 == 0x30313050)) {

      uVar4 = 2;

    }

    else {

      uVar4 = 1;

    }

    uVar5 = uVar4;

    if (param_2 != 0) {

      auVar1._8_8_ = 0;

      auVar1._0_8_ = param_2;

      auVar3 = ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff);

      uVar5 = SUB168(auVar3 / auVar1,0);

      uVar7 = SUB168(auVar3 % auVar1,0);

      if (uVar5 < uVar4) goto LAB_1401445c1;

    }

    uVar4 = uVar4 * param_2;

  }

  else {

LAB_1401445e2:

    uVar8 = 0;

LAB_1401445e9:

    if ((param_2 != 0) &&

       (auVar3._8_8_ = 0, auVar3._0_8_ = param_2,

       auVar1 = ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff), uVar7 = SUB168(auVar1 % auVar3,0),

       SUB168(auVar1 / auVar3,0) < (ulonglong)uVar8)) {

LAB_1401445c1:

      uVar7 = FUN_14012e850("width * bpp would overflow",uVar7);

      return uVar7;

    }

    param_2 = uVar8 * param_2;

    *param_5 = param_2;

    uVar5 = ~param_2;

    if (uVar5 < 7) goto LAB_14014466e;

    uVar4 = param_2 + 7 >> 3;

  }

  *param_5 = uVar4;

  if (param_6 == '\0') {

    uVar5 = ~uVar4;

    if (uVar5 < 3) {

LAB_14014466e:

      uVar7 = FUN_14012e850("aligning pitch would overflow");

      return uVar7;

    }

    uVar4 = uVar4 + 3 & 0xfffffffffffffffc;

    *param_5 = uVar4;

  }

  if (param_3 != 0) {

    auVar2._8_8_ = 0;

    auVar2._0_8_ = param_3;

    auVar3 = ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff);

    uVar5 = SUB168(auVar3 / auVar2,0);

    if (uVar5 < uVar4) {

      uVar7 = FUN_14012e850("height * pitch would overflow",SUB168(auVar3 % auVar2,0));

      return uVar7;

    }

  }

  *param_4 = uVar4 * param_3;

  return CONCAT71((int7)(uVar5 >> 8),1);

}




