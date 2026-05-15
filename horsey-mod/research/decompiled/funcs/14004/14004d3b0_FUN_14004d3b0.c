// Address: 0x14004d3b0
// Ghidra name: FUN_14004d3b0
// ============ 0x14004d3b0 FUN_14004d3b0 (size=851) ============


void FUN_14004d3b0(int param_1,longlong param_2,int param_3,longlong param_4,int param_5)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

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

  float fVar20;

  float fVar21;

  float fVar22;

  

  fVar1 = *(float *)(param_4 + ((longlong)param_5 >> 3) * 4);

  pfVar3 = (float *)(param_2 + (longlong)param_3 * 4);

  pfVar2 = pfVar3 + -(longlong)(param_1 << 4);

  if (pfVar2 < pfVar3) {

    fVar4 = (float)((uint)fVar1 ^ DAT_14039cac0);

    do {

      fVar5 = *pfVar3 - pfVar3[-8];

      fVar16 = *pfVar3 + pfVar3[-8];

      fVar9 = pfVar3[-2] - pfVar3[-10];

      fVar21 = pfVar3[-10] + pfVar3[-2];

      fVar6 = pfVar3[-1] - pfVar3[-9];

      fVar20 = pfVar3[-9] + pfVar3[-1];

      fVar17 = pfVar3[-5] - pfVar3[-0xd];

      fVar15 = pfVar3[-0xd] + pfVar3[-5];

      fVar10 = pfVar3[-3] - pfVar3[-0xb];

      fVar18 = pfVar3[-0xb] + pfVar3[-3];

      fVar11 = (fVar10 - fVar9) * fVar1;

      fVar9 = (fVar10 + fVar9) * fVar1;

      fVar8 = pfVar3[-6] - pfVar3[-0xe];

      fVar13 = pfVar3[-0xe] + pfVar3[-6];

      fVar12 = pfVar3[-4] + pfVar3[-0xc];

      fVar19 = pfVar3[-7] - pfVar3[-0xf];

      fVar14 = pfVar3[-0xf] + pfVar3[-7];

      fVar7 = fVar16 - fVar12;

      fVar22 = (float)((uint)(pfVar3[-4] - pfVar3[-0xc]) ^ DAT_14039cac0);

      fVar10 = fVar13 + fVar21;

      fVar12 = fVar12 + fVar16;

      fVar21 = fVar21 - fVar13;

      fVar16 = (fVar19 - fVar8) * fVar1;

      fVar13 = fVar18 - fVar14;

      fVar8 = (fVar19 + fVar8) * fVar4;

      fVar14 = fVar14 + fVar18;

      *pfVar3 = fVar10 + fVar12;

      pfVar3[-2] = fVar12 - fVar10;

      pfVar3[-4] = fVar13 + fVar7;

      pfVar3[-6] = fVar7 - fVar13;

      fVar13 = fVar20 - fVar15;

      fVar15 = fVar15 + fVar20;

      pfVar3[-1] = fVar14 + fVar15;

      pfVar3[-3] = fVar15 - fVar14;

      fVar10 = fVar16 + fVar9;

      fVar9 = fVar9 - fVar16;

      pfVar3[-5] = fVar13 - fVar21;

      pfVar3[-7] = fVar13 + fVar21;

      fVar13 = fVar5 - fVar17;

      fVar17 = fVar17 + fVar5;

      fVar5 = fVar11 - fVar8;

      fVar8 = fVar8 + fVar11;

      pfVar3[-8] = fVar10 + fVar17;

      pfVar3[-10] = fVar17 - fVar10;

      pfVar3[-0xc] = fVar5 + fVar13;

      pfVar3[-0xe] = fVar13 - fVar5;

      fVar5 = fVar6 - fVar22;

      fVar22 = fVar22 + fVar6;

      pfVar3[-9] = fVar8 + fVar22;

      pfVar3[-0xb] = fVar22 - fVar8;

      pfVar3[-0xd] = fVar5 - fVar9;

      pfVar3[-0xf] = fVar5 + fVar9;

      pfVar3 = pfVar3 + -0x10;

    } while (pfVar2 < pfVar3);

  }

  return;

}




