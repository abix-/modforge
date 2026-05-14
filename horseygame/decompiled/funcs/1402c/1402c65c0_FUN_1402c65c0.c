// Address: 0x1402c65c0
// Ghidra name: FUN_1402c65c0
// ============ 0x1402c65c0 FUN_1402c65c0 (size=413) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402c65c0(undefined1 (*param_1) [32],undefined1 (*param_2) [32])



{

  undefined1 auVar1 [32];

  undefined1 auVar2 [32];

  undefined1 *puVar3;

  ulonglong uVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined1 auVar8 [16];

  undefined1 auVar9 [16];

  undefined1 auVar10 [32];

  

  uVar6 = (longlong)param_2 - (longlong)param_1;

  puVar3 = *param_1;

  auVar2 = vpsubq_avx2(*param_1,_DAT_140386100);

  auVar10 = auVar2;

  while (param_1 = param_1 + 1,

        param_1 != (undefined1 (*) [32])(puVar3 + (uVar6 & 0xffffffffffffffe0))) {

    auVar2 = vpsubq_avx2(*param_1,_DAT_140386100);

    auVar1 = vpcmpgtq_avx2(auVar10,auVar2);

    auVar10 = vpblendvb_avx2(auVar10,auVar2,auVar1);

  }

  uVar5 = (uint)uVar6 & 0x1c;

  if ((uVar6 & 0x1c) != 0) {

    auVar1 = vpmaskmovd_avx2(*(undefined1 (*) [32])(&DAT_1403860c0 + -(ulonglong)uVar5),*param_1);

    auVar1 = vpsubq_avx2(auVar1,_DAT_140386100);

    auVar2 = vpblendvb_avx2(auVar2,auVar1,*(undefined1 (*) [32])(&DAT_1403860c0 + -(ulonglong)uVar5)

                           );

    auVar1 = vpcmpgtq_avx2(auVar10,auVar2);

    auVar10 = vpblendvb_avx2(auVar10,auVar2,auVar1);

    param_1 = (undefined1 (*) [32])(*param_1 + uVar5);

  }

  auVar9 = vpsrldq_avx(auVar10._0_16_,8);

  uVar6 = auVar9._0_8_;

  if ((longlong)auVar10._0_8_ <= (longlong)auVar9._0_8_) {

    uVar6 = auVar10._0_8_;

  }

  auVar9 = vpsrldq_avx(auVar10._16_16_,8);

  uVar4 = auVar10._16_8_;

  if ((longlong)uVar6 <= (longlong)auVar10._16_8_) {

    uVar4 = uVar6;

  }

  uVar6 = auVar9._0_8_;

  if ((longlong)uVar4 <= (longlong)auVar9._0_8_) {

    uVar6 = uVar4;

  }

  auVar9._8_8_ = 0;

  auVar9._0_8_ = uVar6;

  auVar9 = vpunpcklqdq_avx(auVar9,auVar9);

  uVar6 = auVar9._0_8_ + 0x8000000000000000;

  uVar4 = 0;

  uVar7 = (ulonglong)((longlong)param_2 + (7 - (longlong)param_1)) >> 3;

  if (param_2 < param_1) {

    uVar7 = 0;

  }

  if (((uVar7 != 0) && (3 < uVar7)) && (5 < DAT_1403e8ad0)) {

    auVar8._8_8_ = uVar6;

    auVar8._0_8_ = uVar6;

    auVar9 = auVar8;

    do {

      uVar4 = uVar4 + 4;

      auVar8 = vpminuq_avx512vl(auVar8,*(undefined1 (*) [16])*param_1);

      puVar3 = *param_1;

      param_1 = param_1 + 1;

      auVar9 = vpminuq_avx512vl(auVar9,*(undefined1 (*) [16])(puVar3 + 0x10));

    } while (uVar4 != (uVar7 & 0xfffffffffffffffc));

    auVar9 = vpminuq_avx512vl(auVar8,auVar9);

    auVar9 = vpminuq_avx512vl(auVar9,auVar9 >> 0x40);

    uVar6 = auVar9._0_8_;

  }

  for (; param_1 != param_2; param_1 = (undefined1 (*) [32])(*param_1 + 8)) {

    uVar4 = *(ulonglong *)*param_1;

    if (uVar6 <= *(ulonglong *)*param_1) {

      uVar4 = uVar6;

    }

    uVar6 = uVar4;

  }

  return;

}




