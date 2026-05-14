// Address: 0x1402129d0
// Ghidra name: FUN_1402129d0
// ============ 0x1402129d0 FUN_1402129d0 (size=587) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402129d0(uint *param_1,longlong param_2,int param_3)



{

  undefined1 (*pauVar1) [16];

  undefined1 auVar2 [16];

  int iVar3;

  longlong lVar4;

  undefined1 (*pauVar5) [16];

  uint *puVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  longlong lVar10;

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  undefined1 auVar13 [16];

  undefined1 auVar14 [16];

  

  auVar2 = _DAT_140305430;

  iVar3 = 0;

  if (0xf < param_3) {

    if (((ulonglong)param_1 & 0xf) != 0) {

      puVar6 = param_1;

      do {

        uVar9 = *(uint *)((longlong)puVar6 + (param_2 - (longlong)param_1));

        *puVar6 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;

        iVar3 = iVar3 + 1;

        puVar6 = puVar6 + 1;

      } while (((char)iVar3 * '\x04' + (char)param_1 & 0xfU) != 0);

    }

    iVar8 = iVar3 + 0x10;

    if (iVar8 <= param_3) {

      lVar4 = (longlong)param_1 - param_2;

      pauVar5 = (undefined1 (*) [16])(param_2 + ((longlong)iVar3 + 8) * 4);

      do {

        iVar3 = iVar3 + 0x10;

        iVar8 = iVar8 + 0x10;

        auVar12 = *pauVar5;

        auVar13 = pauVar5[1];

        auVar11 = pshufb(pauVar5[-2],auVar2);

        auVar14 = pshufb(pauVar5[-1],auVar2);

        *(undefined1 (*) [16])((longlong)pauVar5 + lVar4 + -0x20) = auVar11;

        *(undefined1 (*) [16])((longlong)pauVar5 + lVar4 + -0x10) = auVar14;

        auVar11 = pshufb(auVar12,auVar2);

        auVar12 = pshufb(auVar13,auVar2);

        *(undefined1 (*) [16])((longlong)pauVar5 + lVar4) = auVar11;

        *(undefined1 (*) [16])((longlong)pauVar5 + lVar4 + 0x10) = auVar12;

        pauVar5 = pauVar5 + 4;

      } while (iVar8 <= param_3);

    }

  }

  uVar9 = param_3 - iVar3;

  if (((iVar3 < param_3) && (1 < uVar9)) && (1 < DAT_1403e8ad0)) {

    lVar4 = (longlong)iVar3;

    if (((uint *)(param_2 + (longlong)(param_3 + -1) * 4) < param_1 + lVar4) ||

       (param_1 + (param_3 + -1) < (uint *)(param_2 + lVar4 * 4))) {

      if (uVar9 < 0x10) {

        lVar10 = param_2 - (longlong)param_1;

      }

      else {

        uVar7 = uVar9 & 0x8000000f;

        if ((int)uVar7 < 0) {

          uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;

        }

        lVar10 = param_2 - (longlong)param_1;

        pauVar5 = (undefined1 (*) [16])(param_1 + lVar4 + 4);

        do {

          iVar3 = iVar3 + 0x10;

          lVar4 = lVar4 + 0x10;

          pauVar1 = pauVar5 + 4;

          auVar12 = pshufb(*(undefined1 (*) [16])(lVar10 + -0x10 + (longlong)pauVar5),auVar2);

          auVar13 = pshufb(*(undefined1 (*) [16])(lVar10 + (longlong)pauVar5),auVar2);

          pauVar5[-1] = auVar12;

          auVar12 = *(undefined1 (*) [16])(lVar10 + -0x30 + (longlong)pauVar1);

          *pauVar5 = auVar13;

          auVar12 = pshufb(auVar12,auVar2);

          auVar13 = pshufb(*(undefined1 (*) [16])(lVar10 + -0x20 + (longlong)pauVar1),auVar2);

          pauVar5[1] = auVar12;

          pauVar5[2] = auVar13;

          pauVar5 = pauVar1;

        } while (lVar4 < (int)(param_3 - uVar7));

        if (((byte)uVar9 & 0xf) < 2) goto LAB_140212be9;

      }

      lVar4 = (longlong)iVar3;

      uVar9 = uVar9 & 0x80000001;

      if ((int)uVar9 < 0) {

        uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;

      }

      puVar6 = param_1 + lVar4;

      do {

        auVar12._8_8_ = 0;

        auVar12._0_8_ = *(ulonglong *)(lVar10 + (longlong)puVar6);

        auVar12 = pshufb(auVar12,auVar2);

        iVar3 = iVar3 + 2;

        lVar4 = lVar4 + 2;

        *(longlong *)puVar6 = auVar12._0_8_;

        puVar6 = puVar6 + 2;

      } while (lVar4 < (int)(param_3 - uVar9));

    }

  }

LAB_140212be9:

  lVar4 = (longlong)iVar3;

  if (lVar4 < param_3) {

    lVar10 = param_3 - lVar4;

    puVar6 = param_1 + lVar4;

    do {

      uVar9 = *(uint *)((param_2 - (longlong)param_1) + (longlong)puVar6);

      *puVar6 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;

      lVar10 = lVar10 + -1;

      puVar6 = puVar6 + 1;

    } while (lVar10 != 0);

  }

  return;

}




