// Address: 0x140212660
// Ghidra name: FUN_140212660
// ============ 0x140212660 FUN_140212660 (size=559) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140212660(ushort *param_1,longlong param_2,int param_3)



{

  ushort uVar1;

  undefined1 auVar2 [16];

  int iVar3;

  undefined1 (*pauVar4) [16];

  ushort *puVar5;

  uint uVar6;

  longlong lVar7;

  int iVar8;

  uint uVar9;

  longlong lVar10;

  undefined1 auVar11 [16];

  undefined1 auVar12 [16];

  

  auVar2 = _DAT_140353900;

  iVar3 = 0;

  if (0xf < param_3) {

    lVar10 = param_2 - (longlong)param_1;

    puVar5 = param_1;

    if (((ulonglong)param_1 & 0xf) == 0) {

      iVar8 = 0x10;

      iVar3 = 0;

    }

    else {

      do {

        iVar8 = iVar3;

        iVar3 = iVar8 + 1;

        *puVar5 = *(ushort *)((longlong)puVar5 + lVar10) >> 8 |

                  *(ushort *)((longlong)puVar5 + lVar10) << 8;

        puVar5 = puVar5 + 1;

      } while (((char)iVar3 * '\x02' + (char)param_1 & 0xfU) != 0);

      iVar8 = iVar8 + 0x11;

      if (param_3 < iVar8) goto LAB_140212711;

    }

    pauVar4 = (undefined1 (*) [16])(param_1 + (longlong)iVar3 + 8);

    do {

      iVar3 = iVar3 + 0x10;

      iVar8 = iVar8 + 0x10;

      auVar11 = pshufb(*(undefined1 (*) [16])((longlong)pauVar4 + lVar10 + -0x10),auVar2);

      auVar12 = pshufb(*(undefined1 (*) [16])((longlong)pauVar4 + lVar10),auVar2);

      pauVar4[-1] = auVar11;

      *pauVar4 = auVar12;

      pauVar4 = pauVar4 + 2;

    } while (iVar8 <= param_3);

  }

LAB_140212711:

  uVar9 = param_3 - iVar3;

  if (((iVar3 < param_3) && (3 < uVar9)) && (1 < DAT_1403e8ad0)) {

    lVar10 = (longlong)iVar3;

    if (((ushort *)(param_2 + (longlong)(param_3 + -1) * 2) < param_1 + lVar10) ||

       (param_1 + (param_3 + -1) < (ushort *)(param_2 + lVar10 * 2))) {

      if (0x1f < uVar9) {

        uVar6 = uVar9 & 0x8000001f;

        if ((int)uVar6 < 0) {

          uVar6 = (uVar6 - 1 | 0xffffffe0) + 1;

        }

        lVar7 = param_2 - (longlong)param_1;

        pauVar4 = (undefined1 (*) [16])(param_1 + lVar10 + 8);

        do {

          iVar3 = iVar3 + 0x20;

          lVar10 = lVar10 + 0x20;

          auVar11 = pshufb(*(undefined1 (*) [16])((longlong)pauVar4 + lVar7 + -0x10),auVar2);

          auVar12 = pshufb(*(undefined1 (*) [16])((longlong)pauVar4 + lVar7),auVar2);

          pauVar4[-1] = auVar11;

          auVar11 = *(undefined1 (*) [16])((longlong)pauVar4 + lVar7 + 0x10);

          *pauVar4 = auVar12;

          auVar11 = pshufb(auVar11,auVar2);

          auVar12 = pshufb(*(undefined1 (*) [16])((longlong)pauVar4 + lVar7 + 0x20),auVar2);

          pauVar4[1] = auVar11;

          pauVar4[2] = auVar12;

          pauVar4 = pauVar4 + 4;

        } while (lVar10 < (int)(param_3 - uVar6));

        if (((byte)uVar9 & 0x1f) < 4) goto LAB_140212859;

      }

      lVar10 = (longlong)iVar3;

      uVar9 = uVar9 & 0x80000003;

      if ((int)uVar9 < 0) {

        uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;

      }

      puVar5 = param_1 + lVar10;

      do {

        auVar11._8_8_ = 0;

        auVar11._0_8_ = *(ulonglong *)((param_2 - (longlong)param_1) + (longlong)puVar5);

        auVar11 = pshufb(auVar11,auVar2);

        iVar3 = iVar3 + 4;

        lVar10 = lVar10 + 4;

        *(longlong *)puVar5 = auVar11._0_8_;

        puVar5 = puVar5 + 4;

      } while (lVar10 < (int)(param_3 - uVar9));

    }

  }

LAB_140212859:

  lVar10 = (longlong)iVar3;

  if (lVar10 < param_3) {

    lVar7 = param_3 - lVar10;

    puVar5 = param_1 + lVar10;

    do {

      uVar1 = *(ushort *)((param_2 - (longlong)param_1) + (longlong)puVar5);

      *puVar5 = uVar1 >> 8 | uVar1 << 8;

      lVar7 = lVar7 + -1;

      puVar5 = puVar5 + 1;

    } while (lVar7 != 0);

  }

  return;

}




