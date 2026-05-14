// Address: 0x1401a6e50
// Ghidra name: FUN_1401a6e50
// ============ 0x1401a6e50 FUN_1401a6e50 (size=710) ============


void FUN_1401a6e50(longlong param_1,int param_2,uint param_3,int param_4,int param_5)



{

  ushort *puVar1;

  byte bVar2;

  ushort uVar3;

  int iVar4;

  uint uVar5;

  ushort *puVar6;

  ulonglong uVar7;

  uint uVar8;

  byte *pbVar9;

  short *psVar10;

  ushort *puVar11;

  ulonglong uVar12;

  uint uVar13;

  uint uVar14;

  longlong lVar15;

  uint *puVar16;

  longlong lVar17;

  undefined2 *puVar18;

  uint local_9b8 [36];

  undefined4 local_928;

  undefined4 local_924;

  int aiStack_920 [286];

  undefined1 local_4a8 [1152];

  

  iVar4 = 0;

  uVar12 = (ulonglong)param_3;

  lVar15 = (longlong)param_2;

  local_9b8[0x20] = 0;

  local_9b8[0] = 0;

  local_9b8[1] = 0;

  local_9b8[2] = 0;

  local_9b8[3] = 0;

  local_9b8[4] = 0;

  local_9b8[5] = 0;

  local_9b8[6] = 0;

  local_9b8[7] = 0;

  local_9b8[8] = 0;

  local_9b8[9] = 0;

  local_9b8[10] = 0;

  local_9b8[0xb] = 0;

  local_9b8[0xc] = 0;

  local_9b8[0xd] = 0;

  local_9b8[0xe] = 0;

  local_9b8[0xf] = 0;

  local_9b8[0x10] = 0;

  local_9b8[0x11] = 0;

  local_9b8[0x12] = 0;

  local_9b8[0x13] = 0;

  local_9b8[0x14] = 0;

  local_9b8[0x15] = 0;

  local_9b8[0x16] = 0;

  local_9b8[0x17] = 0;

  local_9b8[0x18] = 0;

  local_9b8[0x19] = 0;

  local_9b8[0x1a] = 0;

  local_9b8[0x1b] = 0;

  local_9b8[0x1c] = 0;

  local_9b8[0x1d] = 0;

  local_9b8[0x1e] = 0;

  local_9b8[0x1f] = 0;

  if (param_5 == 0) {

    uVar5 = 0;

    psVar10 = (short *)(param_1 + 0x81ca + lVar15 * 0x240);

    if (0 < (int)param_3) {

      puVar18 = (undefined2 *)((longlong)&local_928 + 2);

      do {

        if (*psVar10 != 0) {

          uVar5 = uVar5 + 1;

          puVar18[-1] = *psVar10;

          *puVar18 = (short)iVar4;

          puVar18 = puVar18 + 2;

        }

        iVar4 = iVar4 + 1;

        psVar10 = psVar10 + 1;

      } while (iVar4 < (int)param_3);

    }

    puVar6 = (ushort *)FUN_1401a71d0(uVar5,&local_928,local_4a8);

    FUN_1401a53c0(puVar6,uVar5);

    if (0 < (int)uVar5) {

      uVar7 = (ulonglong)uVar5;

      puVar11 = puVar6;

      do {

        uVar3 = *puVar11;

        puVar11 = puVar11 + 2;

        local_9b8[uVar3] = local_9b8[uVar3] + 1;

        uVar7 = uVar7 - 1;

      } while (uVar7 != 0);

    }

    FUN_1401a6be0(local_9b8,uVar5,param_4);

    FUN_1402f94c0(param_1 + 0x8f4a + lVar15 * 0x120,0,0x120);

    FUN_1402f94c0(param_1 + 0x888a + lVar15 * 0x240,0,0x240);

    iVar4 = 1;

    if (0 < param_4) {

      lVar17 = (longlong)(int)uVar5;

      puVar16 = local_9b8;

      do {

        puVar16 = puVar16 + 1;

        uVar7 = (ulonglong)*puVar16;

        if (0 < (int)*puVar16) {

          puVar11 = puVar6 + lVar17 * 2 + 1;

          lVar17 = lVar17 - uVar7;

          do {

            puVar1 = puVar11 + -2;

            puVar11 = puVar11 + -2;

            uVar5 = (int)uVar7 - 1;

            uVar7 = (ulonglong)uVar5;

            *(char *)((ulonglong)*puVar1 + lVar15 * 0x120 + 0x8f4a + param_1) = (char)iVar4;

          } while (0 < (int)uVar5);

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 <= param_4);

    }

  }

  else if (0 < (int)param_3) {

    pbVar9 = (byte *)(lVar15 * 0x120 + 0x8f4a + param_1);

    uVar7 = uVar12;

    do {

      bVar2 = *pbVar9;

      pbVar9 = pbVar9 + 1;

      local_9b8[bVar2] = local_9b8[bVar2] + 1;

      uVar7 = uVar7 - 1;

    } while (uVar7 != 0);

  }

  iVar4 = 0;

  local_924 = 0;

  if (1 < param_4) {

    uVar7 = (ulonglong)(param_4 - 1);

    lVar15 = 0;

    do {

      iVar4 = (iVar4 + *(int *)((longlong)local_9b8 + lVar15 + 4)) * 2;

      *(int *)((longlong)aiStack_920 + lVar15) = iVar4;

      uVar7 = uVar7 - 1;

      lVar15 = lVar15 + 4;

    } while (uVar7 != 0);

  }

  if (0 < (int)param_3) {

    pbVar9 = (byte *)((longlong)param_2 * 0x120 + 0x8f4a + param_1);

    puVar18 = (undefined2 *)((longlong)param_2 * 0x240 + param_1 + 0x888a);

    do {

      uVar7 = (ulonglong)*pbVar9;

      uVar5 = 0;

      if (*pbVar9 != 0) {

        uVar14 = (&local_928)[uVar7];

        (&local_928)[uVar7] = uVar14 + 1;

        do {

          uVar8 = uVar14 & 1;

          uVar14 = uVar14 >> 1;

          uVar13 = (int)uVar7 - 1;

          uVar7 = (ulonglong)uVar13;

          uVar5 = uVar8 | uVar5 * 2;

        } while (0 < (int)uVar13);

        *puVar18 = (short)uVar5;

      }

      puVar18 = puVar18 + 1;

      pbVar9 = pbVar9 + 1;

      uVar12 = uVar12 - 1;

    } while (uVar12 != 0);

  }

  return;

}




