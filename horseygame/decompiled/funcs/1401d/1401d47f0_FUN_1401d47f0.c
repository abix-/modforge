// Address: 0x1401d47f0
// Ghidra name: FUN_1401d47f0
// ============ 0x1401d47f0 FUN_1401d47f0 (size=549) ============


undefined8 FUN_1401d47f0(int param_1,int param_2,int param_3,longlong *param_4,ulonglong *param_5)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  char cVar6;

  undefined8 uVar7;

  char *pcVar8;

  int iVar9;

  int iVar10;

  ulonglong uVar11;

  int iVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  

  uVar14 = (ulonglong)param_3;

  iVar10 = 0;

  uVar13 = (ulonglong)param_2;

  iVar12 = 0;

  cVar6 = FUN_1401d47c0();

  if (cVar6 == '\x01') {

    if ((param_2 == 0) ||

       (auVar1._8_8_ = 0, auVar1._0_8_ = uVar13,

       uVar14 <= SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar1,0))) {

      iVar10 = (int)uVar13 * param_3;

      if (uVar13 == 0xffffffffffffffff) goto LAB_1401d49ee;

      uVar11 = uVar13 + 1 >> 1;

      if (uVar14 == 0xffffffffffffffff) {

        pcVar8 = "height + 1 would overflow";

        goto LAB_1401d49f5;

      }

      uVar14 = uVar14 + 1 >> 1;

      if ((uVar11 == 0) ||

         (auVar2._8_8_ = 0, auVar2._0_8_ = uVar11,

         uVar14 <= SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0))) {

        iVar9 = (int)uVar14 * (int)uVar11;

        goto LAB_1401d48d9;

      }

    }

  }

  else {

    if (uVar13 == 0xffffffffffffffff) {

LAB_1401d49ee:

      pcVar8 = "width + 1 would overflow";

      goto LAB_1401d49f5;

    }

    uVar11 = uVar13 + 1 >> 1;

    if ((uVar11 == 0) ||

       (auVar3._8_8_ = 0, auVar3._0_8_ = uVar11,

       uVar14 <= SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar3,0))) {

      iVar12 = param_3 * (int)uVar11;

      iVar9 = iVar10;

LAB_1401d48d9:

      if (param_1 < 0x3259555a) {

        if (param_1 != 0x32595559) {

          if (((param_1 != 0x3132564e) && (param_1 != 0x3231564e)) && (param_1 != 0x32315659)) {

LAB_1401d4972:

            pcVar8 = "That operation is not supported";

            goto LAB_1401d49f5;

          }

LAB_1401d48fc:

          if (param_5 != (ulonglong *)0x0) {

            *param_5 = uVar13;

          }

          if (param_4 == (longlong *)0x0) {

            return 1;

          }

          uVar13 = (ulonglong)iVar9;

          if ((ulonglong)~(longlong)iVar10 < uVar13) {

            pcVar8 = "Y + U would overflow";

          }

          else {

            uVar14 = (longlong)iVar10 + uVar13;

            if (uVar13 <= ~uVar14) {

              *param_4 = (longlong)(iVar9 + (int)uVar14);

              return 1;

            }

            pcVar8 = "Y + U + V would overflow";

          }

          goto LAB_1401d49f5;

        }

      }

      else if (param_1 != 0x55595659) {

        if (param_1 == 0x56555949) goto LAB_1401d48fc;

        if (param_1 != 0x59565955) goto LAB_1401d4972;

      }

      if (param_5 != (ulonglong *)0x0) {

        if (uVar13 == 0xffffffffffffffff) goto LAB_1401d49ee;

        uVar13 = uVar13 + 1 >> 1;

        if ((uVar13 != 0) &&

           (auVar4._8_8_ = 0, auVar4._0_8_ = uVar13,

           SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar4,0) < 4)) {

          pcVar8 = "width * 4 would overflow";

          goto LAB_1401d49f5;

        }

        *param_5 = uVar13 * 4;

      }

      if (param_4 == (longlong *)0x0) {

        return 1;

      }

      if ((iVar12 == 0) ||

         (auVar5._8_8_ = 0, auVar5._0_8_ = (longlong)iVar12,

         3 < SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar5,0))) {

        *param_4 = (longlong)(iVar12 * 4);

        return 1;

      }

      pcVar8 = "plane * 4 would overflow";

      goto LAB_1401d49f5;

    }

  }

  pcVar8 = "width * height would overflow";

LAB_1401d49f5:

  uVar7 = FUN_14012e850(pcVar8);

  return uVar7;

}




