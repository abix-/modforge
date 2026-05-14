// Address: 0x1402c6a20
// Ghidra name: thunk_FUN_1402c63c0
// ============ 0x1402c6a20 thunk_FUN_1402c63c0 (size=5) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong thunk_FUN_1402c63c0(undefined1 (*param_1) [16],undefined1 (*param_2) [16])



{

  ulonglong uVar1;

  undefined1 (*pauVar2) [16];

  ulonglong uVar3;

  longlong lVar4;

  undefined1 (*pauVar5) [16];

  ulonglong uVar6;

  undefined1 auVar7 [16];

  longlong lVar8;

  undefined1 auVar9 [16];

  undefined1 auVar10 [16];

  undefined1 auVar11 [16];

  undefined1 auVar12 [64];

  undefined1 auVar13 [64];

  undefined1 in_ZMM1 [64];

  undefined1 auVar14 [16];

  undefined1 auVar15 [64];

  undefined1 auVar16 [64];

  undefined1 in_ZMM2 [64];

  

  uVar3 = (longlong)param_2 - (longlong)param_1;

  auVar15._16_48_ = in_ZMM2._16_48_;

  if (uVar3 < 0x20) {

    if (uVar3 < 0x10) goto LAB_1402c651a;

  }

  else if ((DAT_1403e8ad4 >> 5 & 1) != 0) {

    uVar3 = FUN_1402c65c0(param_1,param_2);

    return uVar3;

  }

  if ((DAT_1403e8ad4 >> 2 & 1) != 0) {

    auVar14._0_8_ = *(longlong *)*param_1 - _DAT_1403860e0;

    auVar14._8_8_ = *(longlong *)(*param_1 + 8) - _UNK_1403860e8;

    pauVar5 = param_1;

    while( true ) {

      pauVar2 = pauVar5 + 1;

      lVar8 = auVar14._0_8_;

      lVar4 = auVar14._8_8_;

      if (pauVar2 == (undefined1 (*) [16])(*param_1 + (uVar3 & 0xfffffffffffffff0))) break;

      auVar10._0_8_ = *(longlong *)*pauVar2 - _DAT_1403860e0;

      auVar10._8_8_ = *(longlong *)(pauVar5[1] + 8) - _UNK_1403860e8;

      in_ZMM1._0_16_ = auVar10;

      auVar9._0_8_ = -(ulonglong)(auVar10._0_8_ < lVar8);

      auVar9._8_8_ = -(ulonglong)(auVar10._8_8_ < lVar4);

      auVar14 = pblendvb(auVar14,auVar10,auVar9);

      pauVar5 = pauVar2;

    }

    if (lVar8 <= lVar4) {

      lVar4 = lVar8;

    }

    uVar1 = 0;

    uVar6 = lVar4 + 0x8000000000000000;

    uVar3 = (ulonglong)((longlong)param_2 + (7 - (longlong)pauVar2)) >> 3;

    if (param_2 < pauVar2) {

      uVar3 = uVar1;

    }

    if (((uVar3 != 0) && (3 < uVar3)) && (5 < DAT_1403e8ad0)) {

      auVar7._8_8_ = uVar6;

      auVar7._0_8_ = uVar6;

      auVar12._16_48_ = in_ZMM1._16_48_;

      auVar12._0_16_ = auVar7;

      auVar15._0_16_ = auVar7;

      do {

        uVar1 = uVar1 + 4;

        auVar14 = vpminuq_avx512vl(auVar12._0_16_,*pauVar2);

        auVar12 = ZEXT1664(auVar14);

        pauVar5 = pauVar2 + 1;

        pauVar2 = pauVar2 + 2;

        auVar7 = vpminuq_avx512vl(auVar15._0_16_,*pauVar5);

        auVar15 = ZEXT1664(auVar7);

      } while (uVar1 != (uVar3 & 0xfffffffffffffffc));

      auVar14 = vpminuq_avx512vl(auVar14,auVar7);

      auVar14 = vpminuq_avx512vl(auVar14,auVar14 >> 0x40);

      uVar6 = auVar14._0_8_;

    }

    if (pauVar2 == param_2) {

      return uVar6;

    }

    do {

      uVar3 = *(ulonglong *)*pauVar2;

      if (uVar6 <= *(ulonglong *)*pauVar2) {

        uVar3 = uVar6;

      }

      pauVar2 = (undefined1 (*) [16])(*pauVar2 + 8);

      uVar6 = uVar3;

    } while (pauVar2 != param_2);

    return uVar3;

  }

LAB_1402c651a:

  uVar3 = *(ulonglong *)*param_1;

  pauVar5 = (undefined1 (*) [16])(*param_1 + 8);

  uVar1 = 0;

  uVar6 = (ulonglong)((longlong)param_2 + (7 - (longlong)pauVar5)) >> 3;

  if (param_2 < pauVar5) {

    uVar6 = uVar1;

  }

  if (((uVar6 != 0) && (3 < uVar6)) && (5 < DAT_1403e8ad0)) {

    auVar13._16_48_ = in_ZMM1._16_48_;

    auVar11._8_8_ = uVar3;

    auVar11._0_8_ = uVar3;

    auVar13._0_16_ = auVar11;

    auVar16._16_48_ = auVar15._16_48_;

    auVar16._0_16_ = auVar11;

    do {

      uVar1 = uVar1 + 4;

      auVar14 = vpminuq_avx512vl(auVar13._0_16_,*pauVar5);

      auVar13 = ZEXT1664(auVar14);

      pauVar2 = pauVar5 + 1;

      pauVar5 = pauVar5 + 2;

      auVar7 = vpminuq_avx512vl(auVar16._0_16_,*pauVar2);

      auVar16 = ZEXT1664(auVar7);

    } while (uVar1 != (uVar6 & 0xfffffffffffffffc));

    auVar14 = vpminuq_avx512vl(auVar14,auVar7);

    auVar14 = vpminuq_avx512vl(auVar14,auVar14 >> 0x40);

    uVar3 = auVar14._0_8_;

  }

  for (; pauVar5 != param_2; pauVar5 = (undefined1 (*) [16])(*pauVar5 + 8)) {

    uVar6 = *(ulonglong *)*pauVar5;

    if (uVar3 <= *(ulonglong *)*pauVar5) {

      uVar6 = uVar3;

    }

    uVar3 = uVar6;

  }

  return uVar3;

}




