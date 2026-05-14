// Address: 0x1402e9170
// Ghidra name: __remainder_piby2d2f_forC
// ============ 0x1402e9170 __remainder_piby2d2f_forC (size=387) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Library Function - Single Match

    __remainder_piby2d2f_forC

   

   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */



void __remainder_piby2d2f_forC(ulonglong param_1,double *param_2,uint *param_3)



{

  bool bVar1;

  bool bVar2;

  undefined1 auVar3 [16];

  undefined1 auVar4 [16];

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  undefined1 auVar7 [16];

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  ulonglong uVar10;

  ulonglong uVar11;

  sbyte sVar12;

  byte bVar13;

  ulonglong uVar14;

  longlong lVar15;

  longlong lVar16;

  ulonglong uVar17;

  longlong lVar18;

  ulonglong uVar19;

  ulonglong uVar20;

  

  uVar20 = (param_1 >> 0x34) - 0x3ff;

  lVar18 = -((uVar20 >> 3) - 0x86);

  uVar14 = param_1 & 0xfffffffffffff | 0x10000000000000;

  auVar3._8_8_ = 0;

  auVar3._0_8_ = *(ulonglong *)(&DAT_14038e0b0 + lVar18);

  auVar6._8_8_ = 0;

  auVar6._0_8_ = uVar14;

  auVar9._8_8_ = 0;

  auVar9._0_8_ = SUB168(auVar3 * auVar6,8);

  uVar10 = SUB168(auVar3 * auVar6,0);

  auVar4._8_8_ = 0;

  auVar4._0_8_ = *(ulonglong *)(&UNK_14038e0b8 + lVar18);

  auVar7._8_8_ = 0;

  auVar7._0_8_ = uVar14;

  uVar20 = uVar20 & 7;

  auVar9 = auVar4 * auVar7 + auVar9;

  uVar11 = auVar9._0_8_;

  auVar5._8_8_ = 0;

  auVar5._0_8_ = *(ulonglong *)(&UNK_14038e0c0 + lVar18);

  auVar8._8_8_ = 0;

  auVar8._0_8_ = uVar14;

  uVar19 = auVar9._8_8_ + SUB168(auVar5 * auVar8,0);

  uVar17 = 0;

  bVar13 = (byte)(0x36 - uVar20) & 0x3f;

  uVar14 = uVar19 >> bVar13;

  bVar1 = (0x36 - uVar20 & 0x3f) != 0;

  bVar2 = (uVar19 >> bVar13 - 1 & 1) != 0;

  if (bVar1 && bVar2) {

    uVar19 = ~uVar19;

    uVar11 = ~uVar11;

    uVar10 = ~uVar10;

    uVar17 = 0x8000000000000000;

  }

  *param_3 = (int)uVar14 + (uint)(bVar1 && bVar2) & 3;

  sVar12 = (char)uVar20 + 10;

  uVar14 = (uVar19 << sVar12) >> sVar12;

  lVar15 = uVar20 - 0x36;

  lVar18 = 0x3f;

  if (uVar14 != 0) {

    for (; uVar14 >> lVar18 == 0; lVar18 = lVar18 + -1) {

    }

  }

  uVar19 = uVar11;

  if (uVar14 == 0) {

    lVar18 = 0x3f;

    if (uVar11 != 0) {

      for (; uVar11 >> lVar18 == 0; lVar18 = lVar18 + -1) {

      }

    }

    lVar15 = uVar20 - 0x76;

    uVar19 = uVar10;

    uVar14 = uVar11;

  }

  lVar16 = lVar18 + -0x34;

  if (lVar16 < 0) {

    bVar13 = -(byte)lVar16;

    uVar14 = uVar14 << (bVar13 & 0x3f) | uVar19 >> (-(bVar13 - 0x40) & 0x3f);

  }

  else if (lVar16 != 0) {

    uVar14 = uVar14 >> ((byte)lVar16 & 0x3f);

  }

  *param_2 = (double)(uVar14 & 0xffefffffffffffff | uVar17 | lVar15 + lVar18 + 0x3ff << 0x34) *

             _DAT_14038e0a0;

  return;

}




