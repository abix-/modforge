// Address: 0x140149a70
// Ghidra name: FUN_140149a70
// ============ 0x140149a70 FUN_140149a70 (size=402) ============


bool FUN_140149a70(longlong param_1)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  int *piVar4;

  int iVar5;

  byte *pbVar6;

  longlong lVar7;

  int iVar8;

  int iVar9;

  longlong lVar10;

  byte *pbVar11;

  

  lVar3 = FUN_140145e60(0x8c,0x8c,0x16462004);

  if (lVar3 != 0) {

    iVar1 = *(int *)(lVar3 + 0x10);

    FUN_1402f94c0(*(undefined8 *)(lVar3 + 0x18),0);

    iVar8 = 0;

    pbVar11 = &DAT_140331fe0;

    lVar7 = 0xbe;

    iVar9 = 0;

    do {

      lVar10 = 8;

      piVar4 = (int *)((longlong)((iVar9 * 10 + 1) * iVar1) + (longlong)(iVar8 * 10 + 1) * 4 +

                      *(longlong *)(lVar3 + 0x18));

      pbVar6 = pbVar11;

      do {

        *piVar4 = -(uint)((*pbVar6 & 1) != 0);

        piVar4[1] = -(uint)((*pbVar6 & 2) != 0);

        piVar4[2] = -(uint)((*pbVar6 & 4) != 0);

        piVar4[3] = -(uint)((*pbVar6 & 8) != 0);

        piVar4[4] = -(uint)((*pbVar6 & 0x10) != 0);

        piVar4[5] = -(uint)((*pbVar6 & 0x20) != 0);

        piVar4[6] = -(uint)((*pbVar6 & 0x40) != 0);

        piVar4[7] = -(uint)((*pbVar6 & 0x80) != 0);

        piVar4 = (int *)((longlong)piVar4 + (longlong)iVar1);

        lVar10 = lVar10 + -1;

        pbVar6 = pbVar6 + 1;

      } while (lVar10 != 0);

      iVar5 = iVar8 + 1;

      pbVar11 = pbVar11 + 8;

      iVar2 = iVar9 + 1;

      iVar8 = 0;

      if (iVar5 < 0xe) {

        iVar2 = iVar9;

        iVar8 = iVar5;

      }

      lVar7 = lVar7 + -1;

      iVar9 = iVar2;

    } while (lVar7 != 0);

    lVar7 = FUN_14014c790(param_1,lVar3);

    if (lVar7 != 0) {

      FUN_1401553b0(lVar7,2);

      *(longlong *)(param_1 + 0x2d0) = lVar7;

    }

    FUN_140146010(lVar3);

    return lVar7 != 0;

  }

  return false;

}




