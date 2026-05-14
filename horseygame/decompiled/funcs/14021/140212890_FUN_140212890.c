// Address: 0x140212890
// Ghidra name: FUN_140212890
// ============ 0x140212890 FUN_140212890 (size=316) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140212890(ulonglong param_1,ulonglong param_2,uint param_3)



{

  undefined1 (*pauVar1) [16];

  ushort uVar2;

  undefined1 auVar3 [16];

  undefined1 (*pauVar4) [16];

  undefined8 *puVar5;

  ushort *puVar6;

  ulonglong uVar7;

  longlong lVar8;

  longlong lVar9;

  uint uVar10;

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  ulonglong uVar11;

  

  auVar3 = _DAT_140353900;

  uVar7 = 0;

  uVar10 = 0;

  if ((((0 < (int)param_3) && (3 < param_3)) && (1 < DAT_1403e8ad0)) &&

     ((param_2 + ((longlong)(int)param_3 + -1) * 2 < param_1 ||

      (param_1 + ((longlong)(int)param_3 + -1) * 2 < param_2)))) {

    if (param_3 < 0x20) {

      lVar9 = param_2 - param_1;

      uVar11 = uVar7;

    }

    else {

      lVar9 = param_2 - param_1;

      pauVar4 = (undefined1 (*) [16])(param_1 + 0x10);

      uVar11 = uVar7;

      do {

        uVar10 = (int)uVar11 + 0x20;

        uVar11 = (ulonglong)uVar10;

        uVar7 = uVar7 + 0x20;

        pauVar1 = pauVar4 + 4;

        auVar12 = pshufb(*(undefined1 (*) [16])(lVar9 + -0x10 + (longlong)pauVar4),auVar3);

        auVar13 = pshufb(*(undefined1 (*) [16])(lVar9 + (longlong)pauVar4),auVar3);

        pauVar4[-1] = auVar12;

        auVar12 = *(undefined1 (*) [16])(lVar9 + -0x30 + (longlong)pauVar1);

        *pauVar4 = auVar13;

        auVar12 = pshufb(auVar12,auVar3);

        auVar13 = pshufb(*(undefined1 (*) [16])(lVar9 + -0x20 + (longlong)pauVar1),auVar3);

        pauVar4[1] = auVar12;

        pauVar4[2] = auVar13;

        pauVar4 = pauVar1;

      } while ((longlong)uVar7 < (longlong)((longlong)(int)param_3 & 0xffffffffffffffe0U));

      if (((byte)param_3 & 0x1f) < 4) goto LAB_140212994;

    }

    lVar8 = (longlong)(int)uVar11;

    puVar5 = (undefined8 *)(param_1 + lVar8 * 2);

    do {

      auVar12._8_8_ = 0;

      auVar12._0_8_ = *(ulonglong *)(lVar9 + (longlong)puVar5);

      auVar12 = pshufb(auVar12,auVar3);

      uVar10 = (int)uVar11 + 4;

      uVar11 = (ulonglong)uVar10;

      lVar8 = lVar8 + 4;

      *puVar5 = auVar12._0_8_;

      puVar5 = puVar5 + 1;

    } while (lVar8 < (longlong)((longlong)(int)param_3 & 0xfffffffffffffffcU));

  }

LAB_140212994:

  lVar9 = (longlong)(int)uVar10;

  if (lVar9 < (int)param_3) {

    lVar8 = (int)param_3 - lVar9;

    puVar6 = (ushort *)(param_1 + lVar9 * 2);

    do {

      uVar2 = *(ushort *)((param_2 - param_1) + (longlong)puVar6);

      *puVar6 = uVar2 >> 8 | uVar2 << 8;

      lVar8 = lVar8 + -1;

      puVar6 = puVar6 + 1;

    } while (lVar8 != 0);

  }

  return;

}




