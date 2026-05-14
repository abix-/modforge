// Address: 0x14019a120
// Ghidra name: FUN_14019a120
// ============ 0x14019a120 FUN_14019a120 (size=1250) ============


undefined8

FUN_14019a120(longlong param_1,int param_2,int param_3,int param_4,undefined1 *param_5,int param_6,

             int param_7,int param_8)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  byte bVar7;

  byte bVar8;

  byte bVar9;

  byte bVar10;

  byte bVar11;

  byte bVar12;

  bool bVar13;

  undefined1 *puVar14;

  int iVar15;

  int iVar16;

  uint uVar17;

  longlong lVar18;

  byte *pbVar19;

  byte *pbVar20;

  byte *pbVar21;

  byte *pbVar22;

  longlong lVar23;

  int iVar24;

  uint uVar25;

  int iVar26;

  int iVar27;

  int local_a8 [2];

  int local_a0;

  int local_9c;

  int local_98;

  int local_94;

  longlong local_90;

  longlong local_88;

  int local_80;

  int local_7c [17];

  

  lVar18 = (longlong)param_2;

  FUN_14019a0a0(param_3,param_7,&local_90,local_7c,&local_98,&local_80);

  FUN_14019a0a0(param_2,param_6,&local_88,&local_a0,&local_94,local_a8);

  local_9c = 0;

  iVar24 = (param_6 - local_94) - local_a8[0];

  puVar14 = (undefined1 *)(ulonglong)(uint)(param_6 * 4);

  if (0 < param_7) {

    do {

      if ((local_9c < local_98) || ((param_7 - local_80) + -1 < local_9c)) {

        bVar13 = false;

        if (local_9c < local_98) {

          uVar17 = 0;

        }

        else {

          uVar17 = param_3 - 1;

        }

      }

      else {

        uVar17 = (uint)((ulonglong)local_90 >> 0x10) & 0xffff;

        bVar13 = true;

      }

      uVar25 = 0;

      if (bVar13) {

        uVar25 = (uint)(local_90 >> 9) & 0x7f;

      }

      pbVar19 = (byte *)((longlong)(int)uVar17 * (longlong)param_4 + param_1);

      iVar15 = 0;

      if (bVar13) {

        iVar15 = param_4;

      }

      iVar26 = 0x80 - uVar25;

      pbVar21 = pbVar19 + iVar15;

      local_90 = local_90 + local_7c[0];

      for (iVar15 = local_94; iVar15 != 0; iVar15 = iVar15 + -1) {

        bVar1 = pbVar21[2];

        bVar2 = pbVar19[3];

        bVar3 = *pbVar19;

        bVar4 = pbVar19[2];

        bVar5 = pbVar21[3];

        bVar6 = *pbVar21;

        param_5[1] = (char)(pbVar21[1] * uVar25 + (uint)pbVar19[1] * iVar26 >> 7);

        param_5[2] = (char)(bVar1 * uVar25 + (uint)bVar4 * iVar26 >> 7);

        param_5[3] = (char)((uint)bVar2 * iVar26 + bVar5 * uVar25 >> 7);

        *param_5 = (char)((uint)bVar3 * iVar26 + bVar6 * uVar25 >> 7);

        param_5 = param_5 + 4;

      }

      iVar15 = local_a8[0];

      if (iVar24 != 0) {

        lVar23 = local_a0 * local_94 + local_88;

        iVar16 = iVar24;

        do {

          iVar16 = iVar16 + -1;

          uVar17 = ((uint)((ulonglong)lVar23 >> 0x10) & 0xffff) << 2;

          pbVar20 = pbVar19 + uVar17;

          pbVar22 = pbVar21 + uVar17;

          uVar17 = (uint)(lVar23 >> 9) & 0x7f;

          iVar27 = 0x80 - uVar17;

          bVar1 = pbVar20[2];

          bVar2 = pbVar22[2];

          bVar3 = pbVar20[3];

          bVar4 = pbVar22[3];

          bVar5 = pbVar20[6];

          bVar6 = pbVar22[6];

          bVar7 = pbVar20[7];

          bVar8 = pbVar22[7];

          bVar9 = pbVar20[4];

          bVar10 = pbVar22[4];

          bVar11 = *pbVar22;

          bVar12 = *pbVar20;

          param_5[1] = (char)((pbVar22[1] * uVar25 + (uint)pbVar20[1] * iVar26 >> 7 & 0xff) * iVar27

                              + (pbVar22[5] * uVar25 + (uint)pbVar20[5] * iVar26 >> 7 & 0xff) *

                                uVar17 >> 7);

          *param_5 = (char)((bVar10 * uVar25 + (uint)bVar9 * iVar26 >> 7 & 0xff) * uVar17 +

                            ((uint)bVar12 * iVar26 + bVar11 * uVar25 >> 7 & 0xff) * iVar27 >> 7);

          param_5[3] = (char)((bVar4 * uVar25 + (uint)bVar3 * iVar26 >> 7 & 0xff) * iVar27 +

                              (bVar8 * uVar25 + (uint)bVar7 * iVar26 >> 7 & 0xff) * uVar17 >> 7);

          param_5[2] = (char)((bVar2 * uVar25 + (uint)bVar1 * iVar26 >> 7 & 0xff) * iVar27 +

                              (bVar6 * uVar25 + (uint)bVar5 * iVar26 >> 7 & 0xff) * uVar17 >> 7);

          param_5 = param_5 + 4;

          lVar23 = lVar23 + local_a0;

        } while (iVar16 != 0);

      }

      for (; iVar15 != 0; iVar15 = iVar15 + -1) {

        bVar1 = pbVar21[lVar18 * 4 + -2];

        bVar2 = pbVar21[lVar18 * 4 + -1];

        bVar3 = pbVar21[lVar18 * 4 + -4];

        bVar4 = pbVar19[lVar18 * 4 + -2];

        bVar5 = pbVar19[lVar18 * 4 + -1];

        bVar6 = pbVar19[lVar18 * 4 + -4];

        param_5[1] = (char)(pbVar21[lVar18 * 4 + -3] * uVar25 +

                            (uint)pbVar19[lVar18 * 4 + -3] * iVar26 >> 7);

        param_5[2] = (char)(bVar1 * uVar25 + (uint)bVar4 * iVar26 >> 7);

        param_5[3] = (char)(bVar2 * uVar25 + (uint)bVar5 * iVar26 >> 7);

        *param_5 = (char)(bVar3 * uVar25 + (uint)bVar6 * iVar26 >> 7);

        param_5 = param_5 + 4;

      }

      param_5 = param_5 + (param_8 + param_6 * -4);

      local_9c = local_9c + 1;

      puVar14 = param_5;

    } while (local_9c < param_7);

  }

  return CONCAT71((int7)((ulonglong)puVar14 >> 8),1);

}




