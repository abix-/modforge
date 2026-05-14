// Address: 0x1402ecb70
// Ghidra name: FUN_1402ecb70
// ============ 0x1402ecb70 FUN_1402ecb70 (size=483) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_1402ecb70(ulonglong param_1)



{

  undefined1 auVar1 [16];

  undefined1 auVar2 [16];

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  bool bVar5;

  bool bVar6;

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  undefined1 auVar10 [16];

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  ulonglong uVar13;

  ulonglong uVar14;

  sbyte sVar15;

  byte bVar16;

  ulonglong uVar17;

  longlong lVar18;

  longlong lVar19;

  ulonglong uVar20;

  ulonglong uVar21;

  ulonglong uVar22;

  longlong lVar23;

  ulonglong uVar24;

  double dVar25;

  ulonglong uVar26;

  undefined1 auVar27 [16];

  undefined1 auVar28 [16];

  undefined1 auVar29 [16];

  undefined1 auVar30 [16];

  undefined1 auVar31 [16];

  

  uVar26 = (param_1 >> 0x34) - 0x3ff;

  lVar23 = -((uVar26 >> 3) - 0x86);

  uVar17 = param_1 & 0xfffffffffffff | 0x10000000000000;

  auVar27._8_8_ = 0;

  auVar27._0_8_ = *(ulonglong *)(&DAT_14038e000 + lVar23);

  auVar9._8_8_ = 0;

  auVar9._0_8_ = uVar17;

  auVar12._8_8_ = 0;

  auVar12._0_8_ = SUB168(auVar27 * auVar9,8);

  uVar13 = SUB168(auVar27 * auVar9,0);

  auVar7._8_8_ = 0;

  auVar7._0_8_ = SUB168(*(undefined1 (*) [16])(&UNK_14038e008 + lVar23),0);

  auVar10._8_8_ = 0;

  auVar10._0_8_ = uVar17;

  uVar26 = uVar26 & 7;

  auVar27 = vpsrldq_avx(*(undefined1 (*) [16])(&UNK_14038e008 + lVar23),8);

  auVar12 = auVar7 * auVar10 + auVar12;

  uVar14 = auVar12._0_8_;

  auVar8._8_8_ = 0;

  auVar8._0_8_ = auVar27._0_8_;

  auVar11._8_8_ = 0;

  auVar11._0_8_ = uVar17;

  uVar24 = auVar12._8_8_ + SUB168(auVar8 * auVar11,0);

  uVar20 = 0;

  bVar16 = (byte)(0x36 - uVar26) & 0x3f;

  uVar17 = uVar24 >> bVar16;

  bVar5 = (0x36 - uVar26 & 0x3f) != 0;

  bVar6 = (uVar24 >> bVar16 - 1 & 1) != 0;

  if (bVar5 && bVar6) {

    uVar24 = ~uVar24;

    uVar14 = ~uVar14;

    uVar13 = ~uVar13;

    uVar20 = 0x8000000000000000;

  }

  sVar15 = (char)uVar26 + 10;

  uVar24 = (uVar24 << sVar15) >> sVar15;

  lVar18 = uVar26 - 0x36;

  lVar23 = 0x3f;

  if (uVar24 != 0) {

    for (; uVar24 >> lVar23 == 0; lVar23 = lVar23 + -1) {

    }

  }

  uVar21 = uVar13;

  uVar22 = uVar14;

  if (uVar24 == 0) {

    uVar21 = 0;

    lVar23 = 0x3f;

    if (uVar14 != 0) {

      for (; uVar14 >> lVar23 == 0; lVar23 = lVar23 + -1) {

      }

    }

    lVar18 = uVar26 - 0x76;

    uVar22 = uVar13;

    uVar24 = uVar14;

  }

  lVar19 = lVar23 + -0x34;

  bVar16 = (byte)lVar19;

  if (lVar19 < 0) {

    bVar16 = -bVar16;

    uVar13 = uVar24 << (bVar16 & 0x3f) | uVar22 >> (-(bVar16 - 0x40) & 0x3f);

    uVar22 = uVar22 << (bVar16 & 0x3f) | uVar21 >> (-(bVar16 - 0x40) & 0x3f);

  }

  else {

    uVar13 = uVar24;

    if (lVar19 != 0) {

      uVar13 = uVar24 >> (bVar16 & 0x3f);

      uVar22 = uVar22 >> (bVar16 & 0x3f) | uVar24 << (-(bVar16 - 0x40) & 0x3f);

    }

  }

  lVar18 = lVar18 + lVar23 + 0x3ff;

  dVar25 = (double)(uVar13 & 0xffefffffffffffff | uVar20 | lVar18 << 0x34);

  lVar23 = 0x3f;

  if (uVar22 != 0) {

    for (; uVar22 >> lVar23 == 0; lVar23 = lVar23 + -1) {

    }

  }

  auVar29._8_8_ = 0;

  auVar29._0_8_ = dVar25;

  auVar27 = vandpd_avx(auVar29,_DAT_14038ebe0);

  auVar1._8_8_ = 0;

  auVar1._0_8_ = DAT_14038ebf0;

  auVar28._8_8_ = 0;

  auVar28._0_8_ = dVar25 - auVar27._0_8_;

  auVar30._8_8_ = 0;

  auVar30._0_8_ = auVar27._0_8_ * DAT_14038ebf0 - dVar25 * DAT_14038ebd0;

  auVar7 = vfmadd231sd_fma(auVar30,auVar28,auVar1);

  auVar2._8_8_ = 0;

  auVar2._0_8_ = DAT_14038ec00;

  auVar27 = vfmadd231sd_fma(auVar7,auVar27,auVar2);

  auVar3._8_8_ = 0;

  auVar3._0_8_ = DAT_14038ec00;

  vfmadd231sd_fma(auVar27,auVar28,auVar3);

  auVar4._8_8_ = 0;

  auVar4._0_8_ = DAT_14038ec10;

  auVar31._8_8_ = 0;

  auVar31._0_8_ =

       (double)((uVar22 << ((byte)-(lVar23 + -0x40) & 0x3f)) >> 0xc | uVar20 |

               lVar18 - (-(lVar23 + -0x40) + 0x34) << 0x34) * DAT_14038ebd0;

  vfmadd231sd_fma(auVar31,auVar29,auVar4);

  return uVar17 + (bVar5 && bVar6) & 3;

}




