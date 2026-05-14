// Address: 0x1400ecc50
// Ghidra name: FUN_1400ecc50
// ============ 0x1400ecc50 FUN_1400ecc50 (size=1045) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_1400ecc50(longlong *param_1,int param_2)



{

  byte bVar1;

  undefined1 *puVar2;

  longlong lVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  byte *pbVar7;

  undefined1 uVar8;

  uint uVar9;

  uint uVar10;

  longlong lVar11;

  ulonglong uVar12;

  uint *puVar13;

  ulonglong uVar14;

  uint uVar15;

  uint uVar16;

  bool bVar17;

  uint local_68 [16];

  

  if (param_2 == 0xc2) {

    _DAT_1403f4c40 = "progressive jpeg";

    return false;

  }

  if (param_2 == 0xc4) {

    iVar4 = FUN_1400e8ad0(*param_1);

    for (iVar4 = iVar4 + -2; 0 < iVar4; iVar4 = (iVar4 + -0x11) - uVar16) {

      lVar11 = *param_1;

      uVar9 = 0;

      pbVar7 = *(byte **)(lVar11 + 0xb8);

      if (pbVar7 < *(byte **)(lVar11 + 0xc0)) {

LAB_1400ece8c:

        bVar1 = *pbVar7;

        *(byte **)(lVar11 + 0xb8) = pbVar7 + 1;

        uVar15 = (uint)(bVar1 >> 4);

        uVar10 = bVar1 & 0xf;

        if ((1 < uVar15) || (3 < uVar10)) {

          _DAT_1403f4c40 = "bad DHT header";

          return false;

        }

      }

      else {

        uVar15 = uVar9;

        uVar10 = uVar9;

        if (*(int *)(lVar11 + 0x30) != 0) {

          FUN_1400ed820(lVar11);

          pbVar7 = *(byte **)(lVar11 + 0xb8);

          goto LAB_1400ece8c;

        }

      }

      puVar13 = local_68;

      lVar11 = 0x10;

      uVar14 = 0;

      do {

        lVar3 = *param_1;

        pbVar7 = *(byte **)(lVar3 + 0xb8);

        if (pbVar7 < *(byte **)(lVar3 + 0xc0)) {

          bVar1 = *pbVar7;

          *(byte **)(lVar3 + 0xb8) = pbVar7 + 1;

          uVar16 = (uint)bVar1;

        }

        else {

          uVar16 = uVar9;

          if (*(int *)(lVar3 + 0x30) != 0) {

            FUN_1400ed820(lVar3);

            bVar1 = **(byte **)(lVar3 + 0xb8);

            *(byte **)(lVar3 + 0xb8) = *(byte **)(lVar3 + 0xb8) + 1;

            uVar16 = (uint)bVar1;

          }

        }

        *puVar13 = uVar16;

        uVar16 = (int)uVar14 + uVar16;

        uVar14 = (ulonglong)uVar16;

        puVar13 = puVar13 + 1;

        lVar11 = lVar11 + -1;

      } while (lVar11 != 0);

      uVar14 = (ulonglong)uVar10;

      if (uVar15 == 0) {

        iVar6 = FUN_1400e64a0(param_1 + uVar14 * 0xd2 + 1,local_68);

        if (iVar6 == 0) {

          return false;

        }

        lVar11 = uVar14 * 0xd2 + 0x81;

      }

      else {

        iVar6 = FUN_1400e64a0(param_1 + uVar14 * 0xd2 + 0x349,local_68);

        if (iVar6 == 0) {

          return false;

        }

        lVar11 = uVar14 * 0xd2 + 0x3c9;

      }

      uVar14 = 0;

      if (0 < (int)uVar16) {

        do {

          lVar3 = *param_1;

          puVar2 = *(undefined1 **)(lVar3 + 0xb8);

          if (puVar2 < *(undefined1 **)(lVar3 + 0xc0)) {

            uVar8 = *puVar2;

            *(undefined1 **)(lVar3 + 0xb8) = puVar2 + 1;

          }

          else if (*(int *)(lVar3 + 0x30) == 0) {

            uVar8 = 0;

          }

          else {

            FUN_1400ed820(lVar3);

            uVar8 = **(undefined1 **)(lVar3 + 0xb8);

            *(undefined1 **)(lVar3 + 0xb8) = *(undefined1 **)(lVar3 + 0xb8) + 1;

          }

          *(undefined1 *)((longlong)(param_1 + lVar11) + uVar14) = uVar8;

          uVar14 = uVar14 + 1;

        } while ((longlong)uVar14 < (longlong)(int)uVar16);

      }

    }

    bVar17 = iVar4 == 0;

  }

  else if (param_2 == 0xdb) {

    iVar4 = FUN_1400e8ad0(*param_1);

    for (iVar4 = iVar4 + -2; 0 < iVar4; iVar4 = iVar4 + -0x41) {

      lVar11 = *param_1;

      pbVar7 = *(byte **)(lVar11 + 0xb8);

      if (pbVar7 < *(byte **)(lVar11 + 0xc0)) {

LAB_1400ecd6a:

        bVar1 = *pbVar7;

        *(byte **)(lVar11 + 0xb8) = pbVar7 + 1;

        uVar9 = bVar1 & 0xf;

        if (0xf < bVar1) {

          _DAT_1403f4c40 = "bad DQT type";

          goto LAB_1400ece38;

        }

        uVar14 = (ulonglong)uVar9;

        if (3 < uVar9) {

          _DAT_1403f4c40 = "bad DQT table";

          return false;

        }

      }

      else {

        uVar14 = 0;

        if (*(int *)(lVar11 + 0x30) != 0) {

          FUN_1400ed820(lVar11);

          pbVar7 = *(byte **)(lVar11 + 0xb8);

          goto LAB_1400ecd6a;

        }

      }

      uVar12 = 0;

      do {

        lVar11 = *param_1;

        puVar2 = *(undefined1 **)(lVar11 + 0xb8);

        if (puVar2 < *(undefined1 **)(lVar11 + 0xc0)) {

          uVar8 = *puVar2;

          *(undefined1 **)(lVar11 + 0xb8) = puVar2 + 1;

        }

        else if (*(int *)(lVar11 + 0x30) == 0) {

          uVar8 = 0;

        }

        else {

          FUN_1400ed820(lVar11);

          uVar8 = **(undefined1 **)(lVar11 + 0xb8);

          *(undefined1 **)(lVar11 + 0xb8) = *(undefined1 **)(lVar11 + 0xb8) + 1;

        }

        pbVar7 = &DAT_1403dae60 + uVar12;

        uVar12 = uVar12 + 1;

        *(undefined1 *)((ulonglong)*pbVar7 + uVar14 * 0x40 + 0x3488 + (longlong)param_1) = uVar8;

      } while ((longlong)uVar12 < 0x40);

    }

    bVar17 = iVar4 == 0;

  }

  else if (param_2 == 0xdd) {

    iVar4 = FUN_1400e8ad0(*param_1);

    if (iVar4 == 4) {

      uVar5 = FUN_1400e8ad0(*param_1);

      *(undefined4 *)((longlong)param_1 + 0x36e4) = uVar5;

      bVar17 = true;

    }

    else {

      _DAT_1403f4c40 = "bad DRI len";

      bVar17 = false;

    }

  }

  else if (param_2 == 0xff) {

    _DAT_1403f4c40 = "expected marker";

    bVar17 = false;

  }

  else if ((param_2 - 0xe0U < 0x10) || (param_2 == 0xfe)) {

    iVar4 = FUN_1400e8ad0(*param_1);

    FUN_1400ed890(*param_1,iVar4 + -2);

    bVar17 = true;

  }

  else {

LAB_1400ece38:

    bVar17 = false;

  }

  return bVar17;

}




