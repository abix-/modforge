// Address: 0x1400f0610
// Ghidra name: FUN_1400f0610
// ============ 0x1400f0610 FUN_1400f0610 (size=1001) ============


int FUN_1400f0610(undefined8 param_1,undefined4 param_2,float param_3,longlong param_4,int param_5,

                 int param_6,int param_7,int param_8,longlong param_9)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  longlong lVar11;

  int iVar12;

  int iVar13;

  short *psVar14;

  short sVar15;

  int iVar16;

  int iVar17;

  bool bVar18;

  double dVar19;

  double dVar20;

  double dVar21;

  int local_res18;

  int local_b8;

  int local_b0;

  int local_ac;

  longlong local_a0;

  undefined1 local_98 [8];

  longlong local_90;

  int local_7c;

  int local_74;

  int local_70;

  

  FUN_1400f0ca0(local_98,param_1,param_2);

  FUN_1402f94c0(param_4,0,(longlong)(param_5 * param_6));

  iVar3 = 1;

  iVar4 = 1;

  iVar17 = 0;

  param_3 = param_3 / (float)((uint)*(byte *)((longlong)local_7c + 0x13 + local_90) +

                             (uint)*(byte *)((longlong)local_7c + 0x12 + local_90) * 0x100);

  if (0 < param_8) {

    psVar14 = (short *)(param_9 + 4);

    local_a0 = 0;

    iVar13 = iVar3;

    do {

      lVar1 = local_90;

      iVar5 = FUN_1400f0eb0(local_98,param_7 + iVar17);

      iVar6 = (uint)*(byte *)((longlong)local_74 + 0x22 + lVar1) * 0x100 +

              (uint)*(byte *)((longlong)local_74 + 0x23 + lVar1);

      if (iVar5 < iVar6) {

        lVar11 = iVar5 * 4 + lVar1;

        sVar15 = (ushort)*(byte *)((longlong)local_70 + 1 + lVar11) +

                 (ushort)*(byte *)(local_70 + lVar11) * 0x100;

      }

      else {

        lVar11 = (ulonglong)(uint)(iVar6 * 4) + lVar1;

        sVar15 = (ushort)*(byte *)((longlong)local_70 + -4 + lVar11) * 0x100 +

                 (ushort)*(byte *)((longlong)local_70 + -3 + lVar11);

      }

      iVar6 = FUN_1400f3c70(local_98,iVar5);

      bVar18 = -1 < iVar6;

      if (bVar18) {

        lVar11 = (longlong)iVar6;

        local_b0 = (int)(short)((ushort)*(byte *)(lVar11 + 2 + lVar1) * 0x100 +

                               (ushort)*(byte *)(lVar11 + 3 + lVar1));

        local_b8 = (int)(short)((ushort)*(byte *)(lVar11 + 4 + lVar1) * 0x100 +

                               (ushort)*(byte *)(lVar11 + 5 + lVar1));

        local_res18 = (int)(short)((ushort)*(byte *)(lVar11 + 6 + lVar1) * 0x100 +

                                  (ushort)*(byte *)(lVar11 + 7 + lVar1));

        local_ac = (int)(short)((ushort)*(byte *)(lVar11 + 9 + lVar1) +

                               (ushort)*(byte *)(lVar11 + 8 + lVar1) * 0x100);

      }

      iVar6 = 0;

      if (bVar18) {

        iVar6 = local_b0;

      }

      iVar7 = 0;

      if (bVar18) {

        iVar7 = local_b8;

      }

      iVar8 = 0;

      if (bVar18) {

        iVar8 = local_res18;

      }

      iVar9 = 0;

      if (bVar18) {

        iVar9 = local_ac;

      }

      dVar19 = (double)FUN_1402d0290((double)((float)iVar6 * param_3 + 0.0));

      dVar20 = (double)FUN_1402da530((double)((float)iVar9 * param_3 + 0.0));

      dVar21 = (double)FUN_1402da530((double)((float)iVar8 * param_3 + 0.0));

      iVar12 = (int)dVar21 - (int)dVar19;

      dVar21 = (double)FUN_1402d0290((double)((float)iVar7 * param_3 + 0.0));

      iVar16 = -((int)dVar21 + -(int)dVar20);

      iVar10 = 1;

      iVar2 = iVar4;

      if (iVar12 + 1 + iVar13 < param_5) {

        iVar2 = iVar3;

        iVar10 = iVar13;

      }

      iVar3 = iVar2;

      if (param_6 <= iVar16 + 1 + iVar3) {

        return -iVar17;

      }

      FUN_1400f2eb0(local_98,(longlong)iVar10 + param_4 + iVar3 * param_5,iVar12,iVar16,param_5,

                    param_3,param_3,0,0,iVar5);

      *psVar14 = (short)iVar12 + (short)iVar10;

      psVar14[1] = (short)iVar16 + (short)iVar3;

      iVar5 = iVar16 + 2 + iVar3;

      psVar14[-2] = (short)iVar10;

      iVar13 = iVar10 + 2 + iVar12;

      psVar14[-1] = (short)iVar3;

      if (iVar5 <= iVar4) {

        iVar5 = iVar4;

      }

      iVar4 = iVar5;

      iVar17 = iVar17 + 1;

      local_a0 = local_a0 + 1;

      *(float *)(psVar14 + 6) = (float)(int)sVar15 * param_3;

      *(float *)(psVar14 + 4) = (float)-(int)dVar20;

      *(float *)(psVar14 + 2) = (float)(int)dVar19;

      psVar14 = psVar14 + 10;

      local_res18 = iVar8;

      local_b8 = iVar7;

      local_b0 = iVar6;

      local_ac = iVar9;

    } while (local_a0 < param_8);

  }

  return iVar4;

}




