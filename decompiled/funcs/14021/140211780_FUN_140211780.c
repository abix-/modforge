// Address: 0x140211780
// Ghidra name: FUN_140211780
// ============ 0x140211780 FUN_140211780 (size=346) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140211780(uint *param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float *pfVar20;

  uint *puVar21;

  int iVar22;

  ulonglong uVar23;

  uint uVar24;

  float fVar26;

  ulonglong uVar25;

  

  fVar19 = _UNK_14035397c;

  fVar18 = _UNK_140353978;

  fVar2 = _UNK_140353974;

  fVar17 = _DAT_140353970;

  uVar23 = 0;

  uVar24 = 0;

  if (0xf < param_3) {

    puVar21 = param_1;

    uVar25 = uVar23;

    if (((ulonglong)param_1 & 0xf) != 0) {

      do {

        fVar26 = *(float *)(uVar23 + param_2) * fVar17;

        uVar24 = (int)uVar25 + 1;

        uVar25 = (ulonglong)uVar24;

        uVar23 = (longlong)(int)uVar24 * 4;

        *puVar21 = -(uint)(fVar17 <= fVar26) ^ (int)fVar26;

        puVar21 = puVar21 + 1;

      } while (((int)param_1 + (int)uVar23 & 0xfU) != 0);

    }

    uVar24 = (uint)uVar25;

    iVar22 = uVar24 + 0x10;

    if (iVar22 <= param_3) {

      pfVar20 = (float *)(param_2 + ((longlong)(int)uVar24 + 8) * 4);

      do {

        pfVar1 = pfVar20 + -8;

        fVar26 = pfVar20[-7];

        fVar3 = pfVar20[-6];

        fVar4 = pfVar20[-5];

        uVar24 = (int)uVar25 + 0x10;

        uVar25 = (ulonglong)uVar24;

        iVar22 = iVar22 + 0x10;

        fVar5 = pfVar20[-4];

        fVar6 = pfVar20[-3];

        fVar7 = pfVar20[-2];

        fVar8 = pfVar20[-1];

        fVar9 = *pfVar20;

        fVar10 = pfVar20[1];

        fVar11 = pfVar20[2];

        fVar12 = pfVar20[3];

        fVar13 = pfVar20[4];

        fVar14 = pfVar20[5];

        fVar15 = pfVar20[6];

        fVar16 = pfVar20[7];

        pfVar20 = pfVar20 + 0x10;

        puVar21 = (uint *)((longlong)param_1 + (-0x60 - param_2) + (longlong)pfVar20);

        *puVar21 = -(uint)(fVar17 <= *pfVar1 * fVar17) ^ (int)(*pfVar1 * fVar17);

        puVar21[1] = -(uint)(fVar2 <= fVar26 * fVar2) ^ (int)(fVar26 * fVar2);

        puVar21[2] = -(uint)(fVar18 <= fVar3 * fVar18) ^ (int)(fVar3 * fVar18);

        puVar21[3] = -(uint)(fVar19 <= fVar4 * fVar19) ^ (int)(fVar4 * fVar19);

        puVar21 = (uint *)((longlong)param_1 + (-0x50 - param_2) + (longlong)pfVar20);

        *puVar21 = -(uint)(fVar17 <= fVar5 * fVar17) ^ (int)(fVar5 * fVar17);

        puVar21[1] = -(uint)(fVar2 <= fVar6 * fVar2) ^ (int)(fVar6 * fVar2);

        puVar21[2] = -(uint)(fVar18 <= fVar7 * fVar18) ^ (int)(fVar7 * fVar18);

        puVar21[3] = -(uint)(fVar19 <= fVar8 * fVar19) ^ (int)(fVar8 * fVar19);

        puVar21 = (uint *)((longlong)param_1 + (-0x40 - param_2) + (longlong)pfVar20);

        *puVar21 = -(uint)(fVar17 <= fVar9 * fVar17) ^ (int)(fVar9 * fVar17);

        puVar21[1] = -(uint)(fVar2 <= fVar10 * fVar2) ^ (int)(fVar10 * fVar2);

        puVar21[2] = -(uint)(fVar18 <= fVar11 * fVar18) ^ (int)(fVar11 * fVar18);

        puVar21[3] = -(uint)(fVar19 <= fVar12 * fVar19) ^ (int)(fVar12 * fVar19);

        puVar21 = (uint *)((longlong)param_1 + (-0x30 - param_2) + (longlong)pfVar20);

        *puVar21 = -(uint)(fVar17 <= fVar13 * fVar17) ^ (int)(fVar13 * fVar17);

        puVar21[1] = -(uint)(fVar2 <= fVar14 * fVar2) ^ (int)(fVar14 * fVar2);

        puVar21[2] = -(uint)(fVar18 <= fVar15 * fVar18) ^ (int)(fVar15 * fVar18);

        puVar21[3] = -(uint)(fVar19 <= fVar16 * fVar19) ^ (int)(fVar16 * fVar19);

      } while (iVar22 <= param_3);

    }

  }

  if ((int)uVar24 < param_3) {

    uVar23 = (ulonglong)(param_3 - uVar24);

    pfVar20 = (float *)(param_2 + (longlong)(int)uVar24 * 4);

    puVar21 = param_1 + (int)uVar24;

    do {

      fVar2 = *pfVar20;

      pfVar20 = pfVar20 + 1;

      *puVar21 = -(uint)(fVar17 <= fVar2 * fVar17) ^ (int)(fVar2 * fVar17);

      uVar23 = uVar23 - 1;

      puVar21 = puVar21 + 1;

    } while (uVar23 != 0);

  }

  return;

}




