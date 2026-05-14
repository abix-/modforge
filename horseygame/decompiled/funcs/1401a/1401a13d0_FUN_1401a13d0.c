// Address: 0x1401a13d0
// Ghidra name: FUN_1401a13d0
// ============ 0x1401a13d0 FUN_1401a13d0 (size=175) ============


void FUN_1401a13d0(short *param_1,short *param_2)



{

  short *psVar1;

  short *psVar2;

  short *psVar3;

  short sVar4;

  short sVar5;

  short sVar6;

  short sVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short sVar11;

  short sVar12;

  short sVar13;

  short sVar14;

  short sVar15;

  short sVar16;

  short sVar17;

  short sVar18;

  short sVar19;

  short *psVar20;

  longlong lVar21;

  

  if ((param_1 <= param_2 + 0x3f) && (param_2 <= param_1 + 0x3f)) {

    lVar21 = 0x40;

    psVar20 = param_1;

    do {

      *psVar20 = *psVar20 * *(short *)(((longlong)param_2 - (longlong)param_1) + (longlong)psVar20);

      lVar21 = lVar21 + -1;

      psVar20 = psVar20 + 1;

    } while (lVar21 != 0);

    return;

  }

  lVar21 = 2;

  psVar20 = param_1 + 8;

  do {

    psVar2 = (short *)((longlong)param_2 + (-0x10 - (longlong)param_1) + (longlong)psVar20);

    sVar4 = psVar2[1];

    sVar5 = psVar2[2];

    sVar6 = psVar2[3];

    sVar7 = psVar2[4];

    sVar8 = psVar2[5];

    sVar9 = psVar2[6];

    sVar10 = psVar2[7];

    psVar1 = psVar20 + 0x20;

    psVar3 = (short *)((longlong)param_2 + (-0x40 - (longlong)param_1) + (longlong)psVar1);

    sVar11 = *psVar3;

    sVar12 = psVar3[1];

    sVar13 = psVar3[2];

    sVar14 = psVar3[3];

    sVar15 = psVar3[4];

    sVar16 = psVar3[5];

    sVar17 = psVar3[6];

    sVar18 = psVar3[7];

    psVar20[-8] = *psVar2 * psVar20[-8];

    psVar20[-7] = sVar4 * psVar20[-7];

    psVar20[-6] = sVar5 * psVar20[-6];

    psVar20[-5] = sVar6 * psVar20[-5];

    psVar20[-4] = sVar7 * psVar20[-4];

    psVar20[-3] = sVar8 * psVar20[-3];

    psVar20[-2] = sVar9 * psVar20[-2];

    psVar20[-1] = sVar10 * psVar20[-1];

    psVar2 = (short *)((longlong)param_2 + (-0x30 - (longlong)param_1) + (longlong)psVar1);

    sVar4 = *psVar2;

    sVar5 = psVar2[1];

    sVar6 = psVar2[2];

    sVar7 = psVar2[3];

    sVar8 = psVar2[4];

    sVar9 = psVar2[5];

    sVar10 = psVar2[6];

    sVar19 = psVar2[7];

    *psVar20 = *psVar20 * sVar11;

    psVar20[1] = psVar20[1] * sVar12;

    psVar20[2] = psVar20[2] * sVar13;

    psVar20[3] = psVar20[3] * sVar14;

    psVar20[4] = psVar20[4] * sVar15;

    psVar20[5] = psVar20[5] * sVar16;

    psVar20[6] = psVar20[6] * sVar17;

    psVar20[7] = psVar20[7] * sVar18;

    psVar20[8] = sVar4 * psVar20[8];

    psVar20[9] = sVar5 * psVar20[9];

    psVar20[10] = sVar6 * psVar20[10];

    psVar20[0xb] = sVar7 * psVar20[0xb];

    psVar20[0xc] = sVar8 * psVar20[0xc];

    psVar20[0xd] = sVar9 * psVar20[0xd];

    psVar20[0xe] = sVar10 * psVar20[0xe];

    psVar20[0xf] = sVar19 * psVar20[0xf];

    psVar2 = (short *)((longlong)param_2 + (-0x20 - (longlong)param_1) + (longlong)psVar1);

    sVar4 = psVar2[1];

    sVar5 = psVar2[2];

    sVar6 = psVar2[3];

    sVar7 = psVar2[4];

    sVar8 = psVar2[5];

    sVar9 = psVar2[6];

    sVar10 = psVar2[7];

    psVar20[0x10] = *psVar2 * psVar20[0x10];

    psVar20[0x11] = sVar4 * psVar20[0x11];

    psVar20[0x12] = sVar5 * psVar20[0x12];

    psVar20[0x13] = sVar6 * psVar20[0x13];

    psVar20[0x14] = sVar7 * psVar20[0x14];

    psVar20[0x15] = sVar8 * psVar20[0x15];

    psVar20[0x16] = sVar9 * psVar20[0x16];

    psVar20[0x17] = sVar10 * psVar20[0x17];

    lVar21 = lVar21 + -1;

    psVar20 = psVar1;

  } while (lVar21 != 0);

  return;

}




