// Address: 0x1400e83f0
// Ghidra name: FUN_1400e83f0
// ============ 0x1400e83f0 FUN_1400e83f0 (size=867) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_1400e83f0(longlong param_1,undefined8 *param_2,longlong param_3,longlong param_4,int param_5)



{

  uint *puVar1;

  int *piVar2;

  byte bVar3;

  uint uVar4;

  sbyte sVar5;

  byte bVar6;

  ulonglong uVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  uint uVar11;

  longlong lVar12;

  int iVar13;

  

  if (*(int *)(param_1 + 0x36c4) < 0x10) {

    FUN_1400e8fa0();

  }

  uVar11 = *(uint *)(param_1 + 0x36c0);

  bVar6 = *(byte *)((ulonglong)(uVar11 >> 0x17) + param_3);

  if (bVar6 == 0xff) {

    puVar1 = (uint *)(param_3 + 0x62c);

    iVar9 = 10;

    uVar4 = *puVar1;

    while (uVar4 <= uVar11 >> 0x10) {

      iVar9 = iVar9 + 1;

      puVar1 = puVar1 + 1;

      uVar4 = *puVar1;

    }

    iVar13 = *(int *)(param_1 + 0x36c4);

    if (iVar9 == 0x11) {

LAB_1400e871e:

      *(int *)(param_1 + 0x36c4) = iVar13 + -0x10;

    }

    else if (iVar9 <= iVar13) {

      uVar4 = *(uint *)(&DAT_1403dae10 + (longlong)iVar9 * 4);

      iVar10 = *(int *)(param_3 + 0x64c + (longlong)iVar9 * 4);

      *(int *)(param_1 + 0x36c4) = iVar13 - iVar9;

      *(uint *)(param_1 + 0x36c0) = uVar11 << ((byte)iVar9 & 0x1f);

      bVar6 = *(byte *)((longlong)(int)(iVar10 + (uVar11 >> (0x20 - (byte)iVar9 & 0x1f) & uVar4)) +

                        0x400 + param_3);

      goto LAB_1400e8500;

    }

  }

  else {

    bVar3 = *(byte *)((ulonglong)bVar6 + 0x500 + param_3);

    if ((int)(uint)bVar3 <= *(int *)(param_1 + 0x36c4)) {

      *(uint *)(param_1 + 0x36c0) = uVar11 << (bVar3 & 0x1f);

      *(uint *)(param_1 + 0x36c4) = *(int *)(param_1 + 0x36c4) - (uint)bVar3;

      bVar6 = *(byte *)((ulonglong)bVar6 + 0x400 + param_3);

LAB_1400e8500:

      *param_2 = 0;

      param_2[1] = 0;

      param_2[2] = 0;

      param_2[3] = 0;

      param_2[4] = 0;

      param_2[5] = 0;

      param_2[6] = 0;

      param_2[7] = 0;

      param_2[8] = 0;

      param_2[9] = 0;

      param_2[10] = 0;

      param_2[0xb] = 0;

      param_2[0xc] = 0;

      param_2[0xd] = 0;

      param_2[0xe] = 0;

      param_2[0xf] = 0;

      if (bVar6 == 0) {

        uVar11 = 0;

      }

      else {

        if (*(int *)(param_1 + 0x36c4) < (int)(uint)bVar6) {

          FUN_1400e8fa0(param_1);

        }

        uVar4 = *(uint *)(&DAT_1403dae10 + (ulonglong)bVar6 * 4);

        *(int *)(param_1 + 0x36c4) = *(int *)(param_1 + 0x36c4) - (uint)bVar6;

        uVar8 = *(uint *)(param_1 + 0x36c0) << (bVar6 & 0x1f) |

                *(uint *)(param_1 + 0x36c0) >> 0x20 - (bVar6 & 0x1f);

        uVar11 = uVar4 & uVar8;

        *(uint *)(param_1 + 0x36c0) = ~uVar4 & uVar8;

        if (uVar11 < (uint)(1 << (bVar6 - 1 & 0x1f))) {

          uVar11 = (uVar11 - (1 << (bVar6 & 0x1f))) + 1;

        }

      }

      iVar9 = 1;

      piVar2 = (int *)(param_1 + ((longlong)param_5 + 0xbf) * 0x48);

      *piVar2 = *piVar2 + uVar11;

      *(short *)param_2 = (short)*(undefined4 *)(param_1 + ((longlong)param_5 + 0xbf) * 0x48);

      do {

        if (*(int *)(param_1 + 0x36c4) < 0x10) {

          FUN_1400e8fa0(param_1);

        }

        uVar11 = *(uint *)(param_1 + 0x36c0);

        bVar6 = *(byte *)((ulonglong)(uVar11 >> 0x17) + param_4);

        uVar7 = (ulonglong)bVar6;

        if (bVar6 == 0xff) {

          puVar1 = (uint *)(param_4 + 0x62c);

          iVar10 = 10;

          lVar12 = 10;

          uVar4 = *puVar1;

          while (uVar4 <= uVar11 >> 0x10) {

            iVar10 = iVar10 + 1;

            puVar1 = puVar1 + 1;

            lVar12 = lVar12 + 1;

            uVar4 = *puVar1;

          }

          iVar13 = *(int *)(param_1 + 0x36c4);

          if (iVar10 == 0x11) goto LAB_1400e871e;

          if (iVar13 < iVar10) break;

          iVar13 = iVar13 - iVar10;

          bVar6 = (byte)iVar10;

          uVar7 = (ulonglong)

                  (int)(*(int *)(param_4 + 0x64c + lVar12 * 4) +

                       (uVar11 >> (0x20 - bVar6 & 0x1f) & *(uint *)(&DAT_1403dae10 + lVar12 * 4)));

        }

        else {

          bVar6 = *(byte *)(uVar7 + 0x500 + param_4);

          if (*(int *)(param_1 + 0x36c4) < (int)(uint)bVar6) break;

          iVar13 = *(int *)(param_1 + 0x36c4) - (uint)bVar6;

        }

        *(int *)(param_1 + 0x36c4) = iVar13;

        *(uint *)(param_1 + 0x36c0) = uVar11 << (bVar6 & 0x1f);

        bVar6 = *(byte *)(uVar7 + 0x400 + param_4);

        uVar11 = bVar6 & 0xf;

        if ((bVar6 & 0xf) == 0) {

          if (bVar6 != 0xf0) {

            return 1;

          }

          iVar9 = iVar9 + 0x10;

        }

        else {

          sVar5 = (sbyte)uVar11;

          iVar10 = iVar9 + (uint)(bVar6 >> 4);

          if (iVar13 < (int)uVar11) {

            FUN_1400e8fa0(param_1);

          }

          uVar4 = *(uint *)(&DAT_1403dae10 + (ulonglong)uVar11 * 4);

          *(int *)(param_1 + 0x36c4) = *(int *)(param_1 + 0x36c4) - uVar11;

          uVar11 = *(uint *)(param_1 + 0x36c0) << sVar5 |

                   *(uint *)(param_1 + 0x36c0) >> 0x20 - sVar5;

          uVar8 = uVar11 & uVar4;

          *(uint *)(param_1 + 0x36c0) = ~uVar4 & uVar11;

          if (uVar8 < (uint)(1 << (sVar5 - 1U & 0x1f))) {

            uVar8 = (uVar8 - (1 << sVar5)) + 1;

          }

          iVar9 = iVar10 + 1;

          *(short *)((longlong)param_2 + (ulonglong)(byte)(&DAT_1403dae60)[iVar10] * 2) =

               (short)uVar8;

        }

        if (0x3f < iVar9) {

          return 1;

        }

      } while( true );

    }

  }

  _DAT_1403f4c40 = "bad huffman code";

  return 0;

}




