// Address: 0x1402e3e30
// Ghidra name: FUN_1402e3e30
// ============ 0x1402e3e30 FUN_1402e3e30 (size=651) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402e3e30(void)



{

  ulonglong uVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ushort in_FPUStatusWord;

  undefined1 in_XMM0 [16];

  ulonglong uVar5;

  undefined1 in_XMM1 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  double dVar9;

  

  uVar1 = in_XMM0._0_8_;

  uVar2 = uVar1 & DAT_14038bf00;

  uVar4 = in_XMM1._0_8_ & DAT_14038bf00;

  if ((longlong)DAT_14038bec0 < (longlong)uVar4) {

    return;

  }

  if ((longlong)DAT_14038bec0 < (longlong)uVar2) {

    return;

  }

  if (uVar2 != DAT_14038bec0) {

    uVar5 = _DAT_14038bf10;

    if (uVar4 == 0) goto LAB_1402e406c;

    if (uVar2 == uVar4) {

      return;

    }

    auVar7._8_8_ = 0;

    auVar7._0_8_ = DAT_14038bf00;

    auVar8 = in_XMM0 & auVar7;

    dVar9 = SUB168(in_XMM1 & auVar7,0);

    if (auVar8._0_8_ <= dVar9) {

      return;

    }

    uVar4 = in_XMM1._0_8_ & DAT_14038bec0;

    uVar2 = (uVar1 & DAT_14038bec0) >> 0x34 | (uVar1 & DAT_14038bec0) << 0xc;

    uVar4 = uVar4 >> 0x34 | uVar4 << 0xc;

    if (((uVar2 == 0) || (uVar4 == 0)) || (lVar3 = uVar2 - uVar4, 0x33 < lVar3)) {

LAB_1402e3ff0:

      do {

      } while ((in_FPUStatusWord >> 8 & 4) == 4);

      return;

    }

    if (lVar3 != 0x7ff) {

      auVar6._0_8_ = (double)(longlong)(auVar8._0_8_ / dVar9);

      auVar6._8_8_ = auVar8._8_8_;

      if (DAT_1403ff158 != 0) {

        vfmadd231sd_fma(auVar8,auVar6 | _DAT_14038beb0,in_XMM1 & auVar7);

        return;

      }

      if ((longlong)

          ((((ulonglong)auVar6._0_8_ & DAT_14038bec0) >> 0x34 |

           ((ulonglong)auVar6._0_8_ & DAT_14038bec0) << 0xc) + (uVar4 - 0x7fe)) < 0x3ff) {

        return;

      }

      goto LAB_1402e3ff0;

    }

  }

  uVar5 = uVar1 | (ulonglong)DAT_14038bef0;

LAB_1402e406c:

  FUN_1402e8e00(&DAT_14038bea0,0x16,uVar5,1,8,0x21);

  return;

}




