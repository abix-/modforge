// Address: 0x140212c20
// Ghidra name: FUN_140212c20
// ============ 0x140212c20 FUN_140212c20 (size=312) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140212c20(ulonglong param_1,ulonglong param_2,uint param_3)



{

  undefined1 (*pauVar1) [16];

  undefined1 auVar2 [16];

  undefined1 (*pauVar3) [16];

  undefined8 *puVar4;

  uint *puVar5;

  ulonglong uVar6;

  longlong lVar7;

  longlong lVar8;

  uint uVar9;

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  ulonglong uVar10;

  

  auVar2 = _DAT_140305430;

  uVar6 = 0;

  uVar9 = 0;

  if ((((0 < (int)param_3) && (1 < param_3)) && (1 < DAT_1403e8ad0)) &&

     ((param_2 + ((longlong)(int)param_3 + -1) * 4 < param_1 ||

      (param_1 + ((longlong)(int)param_3 + -1) * 4 < param_2)))) {

    if (param_3 < 0x10) {

      lVar8 = param_2 - param_1;

      uVar10 = uVar6;

    }

    else {

      lVar8 = param_2 - param_1;

      pauVar3 = (undefined1 (*) [16])(param_1 + 0x10);

      uVar10 = uVar6;

      do {

        uVar9 = (int)uVar10 + 0x10;

        uVar10 = (ulonglong)uVar9;

        uVar6 = uVar6 + 0x10;

        pauVar1 = pauVar3 + 4;

        auVar11 = pshufb(*(undefined1 (*) [16])(lVar8 + -0x10 + (longlong)pauVar3),auVar2);

        auVar12 = pshufb(*(undefined1 (*) [16])(lVar8 + (longlong)pauVar3),auVar2);

        pauVar3[-1] = auVar11;

        auVar11 = *(undefined1 (*) [16])(lVar8 + -0x30 + (longlong)pauVar1);

        *pauVar3 = auVar12;

        auVar11 = pshufb(auVar11,auVar2);

        auVar12 = pshufb(*(undefined1 (*) [16])(lVar8 + -0x20 + (longlong)pauVar1),auVar2);

        pauVar3[1] = auVar11;

        pauVar3[2] = auVar12;

        pauVar3 = pauVar1;

      } while ((longlong)uVar6 < (longlong)((longlong)(int)param_3 & 0xfffffffffffffff0U));

      if (((byte)param_3 & 0xf) < 2) goto LAB_140212d24;

    }

    lVar7 = (longlong)(int)uVar10;

    puVar4 = (undefined8 *)(param_1 + lVar7 * 4);

    do {

      auVar11._8_8_ = 0;

      auVar11._0_8_ = *(ulonglong *)(lVar8 + (longlong)puVar4);

      auVar11 = pshufb(auVar11,auVar2);

      uVar9 = (int)uVar10 + 2;

      uVar10 = (ulonglong)uVar9;

      lVar7 = lVar7 + 2;

      *puVar4 = auVar11._0_8_;

      puVar4 = puVar4 + 1;

    } while (lVar7 < (longlong)((longlong)(int)param_3 & 0xfffffffffffffffeU));

  }

LAB_140212d24:

  lVar8 = (longlong)(int)uVar9;

  if (lVar8 < (int)param_3) {

    lVar7 = (int)param_3 - lVar8;

    puVar5 = (uint *)(param_1 + lVar8 * 4);

    do {

      uVar9 = *(uint *)((param_2 - param_1) + (longlong)puVar5);

      *puVar5 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;

      lVar7 = lVar7 + -1;

      puVar5 = puVar5 + 1;

    } while (lVar7 != 0);

  }

  return;

}




