// Address: 0x14019f670
// Ghidra name: FUN_14019f670
// ============ 0x14019f670 FUN_14019f670 (size=1601) ============


void FUN_14019f670(longlong param_1,int param_2,longlong param_3)



{

  short *psVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  int iVar18;

  undefined1 *local_168;

  longlong local_160;

  longlong local_158;

  int local_130 [2];

  int local_128 [17];

  int local_e4 [8];

  int local_c4 [8];

  int local_a4 [25];

  

  piVar10 = local_128;

  local_160 = 4;

  psVar1 = (short *)(param_3 + 0x20);

  do {

    iVar7 = (int)psVar1[-8];

    if ((((psVar1[-8] == 0) && (*psVar1 == 0)) && (psVar1[8] == 0)) &&

       (((psVar1[0x10] == 0 && (psVar1[0x18] == 0)) && ((psVar1[0x20] == 0 && (psVar1[0x28] == 0))))

       )) {

      iVar2 = (int)psVar1[-0x10] << 2;

      piVar10[0x30] = iVar2;

      piVar10[0x28] = iVar2;

      piVar10[8] = iVar2;

      *piVar10 = iVar2;

      piVar10[-8] = iVar2;

      iVar3 = iVar2;

      iVar6 = iVar2;

    }

    else {

      iVar15 = (int)psVar1[8];

      iVar2 = (int)psVar1[0x28];

      iVar5 = (int)psVar1[0x18];

      iVar3 = ((int)psVar1[0x20] + (int)*psVar1) * 0x8a9;

      iVar13 = iVar3 + psVar1[0x20] * -0x1d8f;

      iVar3 = *psVar1 * 0xc3f + iVar3;

      iVar16 = ((int)psVar1[-0x10] - (int)psVar1[0x10]) * 0x1000;

      iVar8 = (iVar7 + iVar5 + iVar15 + iVar2) * 0x12d0;

      iVar9 = (iVar15 + iVar2) * -0x1f62;

      iVar17 = ((int)psVar1[0x10] + (int)psVar1[-0x10]) * 0x1000;

      iVar18 = iVar8 + (iVar7 + iVar2) * -0xe65;

      iVar8 = iVar8 + (iVar15 + iVar5) * -0x2901;

      iVar6 = (iVar7 + iVar5) * -0x63d;

      iVar12 = iVar7 * 0x1805 + iVar6 + iVar18;

      iVar18 = iVar18 + iVar2 * 0x4c7 + iVar9;

      iVar7 = iVar13 + 0x200 + iVar16;

      iVar14 = iVar3 + 0x200 + iVar17;

      iVar9 = iVar15 * 0x312a + iVar9 + iVar8;

      iVar8 = iVar5 * 0x20da + iVar6 + iVar8;

      iVar6 = (iVar16 - iVar13) + 0x200;

      iVar5 = (iVar17 - iVar3) + 0x200;

      piVar10[-8] = iVar14 + iVar12 >> 10;

      *piVar10 = iVar7 + iVar9 >> 10;

      piVar10[8] = iVar6 + iVar8 >> 10;

      iVar2 = iVar18 + iVar5 >> 10;

      iVar3 = iVar6 - iVar8 >> 10;

      iVar6 = iVar5 - iVar18 >> 10;

      piVar10[0x30] = iVar14 - iVar12 >> 10;

      piVar10[0x28] = iVar7 - iVar9 >> 10;

    }

    piVar10[0x18] = iVar6;

    piVar10[0x20] = iVar3;

    piVar10[0x10] = iVar2;

    iVar7 = (int)psVar1[-7];

    if ((((psVar1[-7] == 0) && (psVar1[1] == 0)) &&

        ((psVar1[9] == 0 && (((psVar1[0x11] == 0 && (psVar1[0x19] == 0)) && (psVar1[0x21] == 0))))))

       && (psVar1[0x29] == 0)) {

      iVar2 = (int)psVar1[-0xf] << 2;

      piVar10[0x31] = iVar2;

      piVar10[0x29] = iVar2;

      piVar10[9] = iVar2;

      piVar10[1] = iVar2;

      piVar10[-7] = iVar2;

      iVar3 = iVar2;

      iVar6 = iVar2;

    }

    else {

      iVar15 = (int)psVar1[9];

      iVar2 = (int)psVar1[0x29];

      iVar5 = (int)psVar1[0x19];

      iVar3 = ((int)psVar1[0x21] + (int)psVar1[1]) * 0x8a9;

      iVar13 = iVar3 + psVar1[0x21] * -0x1d8f;

      iVar3 = psVar1[1] * 0xc3f + iVar3;

      iVar16 = ((int)psVar1[-0xf] - (int)psVar1[0x11]) * 0x1000;

      iVar8 = (iVar7 + iVar5 + iVar15 + iVar2) * 0x12d0;

      iVar9 = (iVar15 + iVar2) * -0x1f62;

      iVar17 = ((int)psVar1[0x11] + (int)psVar1[-0xf]) * 0x1000;

      iVar18 = iVar8 + (iVar7 + iVar2) * -0xe65;

      iVar8 = iVar8 + (iVar15 + iVar5) * -0x2901;

      iVar6 = (iVar7 + iVar5) * -0x63d;

      iVar12 = iVar7 * 0x1805 + iVar6 + iVar18;

      iVar18 = iVar18 + iVar2 * 0x4c7 + iVar9;

      iVar7 = iVar13 + 0x200 + iVar16;

      iVar14 = iVar3 + 0x200 + iVar17;

      iVar9 = iVar15 * 0x312a + iVar9 + iVar8;

      iVar8 = iVar5 * 0x20da + iVar6 + iVar8;

      iVar6 = (iVar16 - iVar13) + 0x200;

      iVar5 = (iVar17 - iVar3) + 0x200;

      piVar10[-7] = iVar14 + iVar12 >> 10;

      piVar10[1] = iVar7 + iVar9 >> 10;

      piVar10[9] = iVar6 + iVar8 >> 10;

      iVar2 = iVar18 + iVar5 >> 10;

      iVar3 = iVar6 - iVar8 >> 10;

      iVar6 = iVar5 - iVar18 >> 10;

      piVar10[0x31] = iVar14 - iVar12 >> 10;

      piVar10[0x29] = iVar7 - iVar9 >> 10;

    }

    piVar10[0x19] = iVar6;

    psVar1 = psVar1 + 2;

    piVar10[0x21] = iVar3;

    piVar10[0x11] = iVar2;

    piVar10 = piVar10 + 2;

    local_160 = local_160 + -1;

  } while (local_160 != 0);

  piVar10 = local_130;

  local_168 = (undefined1 *)(param_1 + 1);

  local_158 = 8;

  do {

    iVar7 = piVar10[1];

    iVar3 = piVar10[-1];

    iVar6 = piVar10[-3];

    iVar5 = (piVar10[-4] + *piVar10) * 0x8a9;

    iVar18 = iVar5 + *piVar10 * -0x1d8f;

    iVar2 = piVar10[-5];

    iVar5 = piVar10[-4] * 0xc3f + iVar5;

    iVar13 = (iVar6 + iVar7) * -0x1f62;

    iVar16 = (piVar10[-6] + piVar10[-2]) * 0x1000;

    iVar14 = (piVar10[-6] - piVar10[-2]) * 0x1000;

    iVar17 = (iVar16 - iVar5) + 0x1010000;

    iVar15 = (iVar14 - iVar18) + 0x1010000;

    iVar8 = (iVar2 + iVar3 + iVar6 + iVar7) * 0x12d0;

    iVar9 = iVar8 + (iVar2 + iVar7) * -0xe65;

    iVar14 = iVar14 + iVar18 + 0x1010000;

    iVar8 = iVar8 + (iVar6 + iVar3) * -0x2901;

    iVar18 = (iVar2 + iVar3) * -0x63d;

    iVar12 = iVar6 * 0x312a + iVar13 + iVar8;

    iVar8 = iVar3 * 0x20da + iVar18 + iVar8;

    iVar6 = iVar2 * 0x1805 + iVar18 + iVar9;

    iVar3 = iVar5 + iVar16 + 0x1010000;

    iVar9 = iVar7 * 0x4c7 + iVar13 + iVar9;

    uVar11 = iVar6 + iVar3 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    uVar4 = iVar3 - iVar6 >> 0x11;

    local_168[-1] = (char)uVar11;

    if (0xff < uVar4) {

      if ((int)uVar4 < 0) {

        uVar4 = 0;

      }

      else if (0xff < (int)uVar4) {

        uVar4 = 0xff;

      }

    }

    local_168[6] = (char)uVar4;

    uVar11 = iVar14 + iVar12 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    *local_168 = (char)uVar11;

    uVar11 = iVar14 - iVar12 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_168[5] = (char)uVar11;

    uVar11 = iVar15 + iVar8 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_168[1] = (char)uVar11;

    uVar11 = iVar15 - iVar8 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_168[4] = (char)uVar11;

    uVar11 = iVar9 + iVar17 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_168[2] = (char)uVar11;

    uVar11 = iVar17 - iVar9 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    piVar10 = piVar10 + 8;

    local_168[3] = (char)uVar11;

    local_168 = local_168 + param_2;

    local_158 = local_158 + -1;

  } while (local_158 != 0);

  return;

}




