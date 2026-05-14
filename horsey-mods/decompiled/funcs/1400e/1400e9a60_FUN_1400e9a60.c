// Address: 0x1400e9a60
// Ghidra name: FUN_1400e9a60
// ============ 0x1400e9a60 FUN_1400e9a60 (size=1826) ============


void FUN_1400e9a60(longlong param_1,int param_2,longlong param_3,longlong param_4)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  byte *pbVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  int iVar13;

  short *psVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  int iVar18;

  int iVar19;

  longlong local_168;

  undefined1 *local_160;

  longlong local_158;

  int local_148 [6];

  int local_130 [2];

  int local_128 [8];

  int local_108 [8];

  int local_e8 [8];

  int local_c8 [8];

  int local_a8 [8];

  int local_88 [8];

  int local_68 [10];

  

  pbVar9 = (byte *)(param_4 + 0x30);

  local_158 = 4;

  psVar14 = (short *)(param_3 + 0x20);

  piVar1 = local_128;

  do {

    if ((((psVar14[-8] == 0) && (*psVar14 == 0)) && (psVar14[8] == 0)) &&

       (((psVar14[0x10] == 0 && (psVar14[0x18] == 0)) &&

        ((psVar14[0x20] == 0 && (psVar14[0x28] == 0)))))) {

      iVar4 = (int)psVar14[-0x10] * (uint)pbVar9[-0x30] * 4;

      piVar1[0x30] = iVar4;

      piVar1[0x28] = iVar4;

      piVar1[8] = iVar4;

      *piVar1 = iVar4;

      piVar1[-8] = iVar4;

      iVar2 = iVar4;

      iVar6 = iVar4;

    }

    else {

      iVar5 = ((int)psVar14[0x20] * (uint)*pbVar9 + (uint)pbVar9[-0x20] * (int)*psVar14) * 0x8a9;

      iVar10 = iVar5 + (int)psVar14[0x20] * (uint)*pbVar9 * -0x1d8f;

      iVar5 = iVar5 + (uint)pbVar9[-0x20] * (int)*psVar14 * 0xc3f;

      iVar6 = (int)psVar14[0x28] * (uint)pbVar9[8];

      iVar15 = (uint)pbVar9[-8] * (int)psVar14[0x18];

      iVar19 = (uint)pbVar9[-0x18] * (int)psVar14[8];

      iVar12 = (uint)pbVar9[-0x28] * (int)psVar14[-8];

      iVar17 = ((uint)pbVar9[-0x10] * (int)psVar14[0x10] + (int)psVar14[-0x10] * (uint)pbVar9[-0x30]

               ) * 0x1000;

      iVar18 = ((int)psVar14[-0x10] * (uint)pbVar9[-0x30] - (uint)pbVar9[-0x10] * (int)psVar14[0x10]

               ) * 0x1000;

      iVar8 = (iVar19 + iVar6) * -0x1f62;

      iVar7 = (iVar12 + iVar15 + iVar19 + iVar6) * 0x12d0;

      iVar16 = iVar7 + (iVar12 + iVar6) * -0xe65;

      iVar7 = iVar7 + (iVar19 + iVar15) * -0x2901;

      iVar4 = (iVar12 + iVar15) * -0x63d;

      iVar2 = iVar5 + 0x200 + iVar17;

      iVar13 = iVar19 * 0x312a + iVar8 + iVar7;

      iVar19 = iVar12 * 0x1805 + iVar4 + iVar16;

      iVar7 = iVar7 + iVar15 * 0x20da + iVar4;

      iVar15 = (iVar17 - iVar5) + 0x200;

      iVar4 = iVar10 + 0x200 + iVar18;

      iVar16 = iVar16 + iVar6 * 0x4c7 + iVar8;

      iVar5 = (iVar18 - iVar10) + 0x200;

      piVar1[-8] = iVar2 + iVar19 >> 10;

      *piVar1 = iVar4 + iVar13 >> 10;

      piVar1[0x30] = iVar2 - iVar19 >> 10;

      piVar1[0x28] = iVar4 - iVar13 >> 10;

      iVar6 = iVar15 + iVar16 >> 10;

      iVar2 = iVar5 - iVar7 >> 10;

      iVar4 = iVar15 - iVar16 >> 10;

      piVar1[8] = iVar7 + iVar5 >> 10;

    }

    piVar1[0x18] = iVar4;

    piVar1[0x20] = iVar2;

    piVar1[0x10] = iVar6;

    if ((((psVar14[-7] == 0) && (psVar14[1] == 0)) &&

        ((psVar14[9] == 0 &&

         (((psVar14[0x11] == 0 && (psVar14[0x19] == 0)) && (psVar14[0x21] == 0)))))) &&

       (psVar14[0x29] == 0)) {

      iVar4 = (uint)pbVar9[-0x2f] * (int)psVar14[-0xf] * 4;

      piVar1[0x31] = iVar4;

      piVar1[0x29] = iVar4;

      piVar1[9] = iVar4;

      piVar1[1] = iVar4;

      piVar1[-7] = iVar4;

      iVar2 = iVar4;

      iVar6 = iVar4;

    }

    else {

      iVar5 = ((int)psVar14[0x21] * (uint)pbVar9[1] + (uint)pbVar9[-0x1f] * (int)psVar14[1]) * 0x8a9

      ;

      iVar10 = iVar5 + (int)psVar14[0x21] * (uint)pbVar9[1] * -0x1d8f;

      iVar5 = iVar5 + (uint)pbVar9[-0x1f] * (int)psVar14[1] * 0xc3f;

      iVar6 = (int)psVar14[0x29] * (uint)pbVar9[9];

      iVar15 = (uint)pbVar9[-7] * (int)psVar14[0x19];

      iVar19 = (uint)pbVar9[-0x17] * (int)psVar14[9];

      iVar12 = (uint)pbVar9[-0x27] * (int)psVar14[-7];

      iVar17 = ((uint)pbVar9[-0xf] * (int)psVar14[0x11] + (uint)pbVar9[-0x2f] * (int)psVar14[-0xf])

               * 0x1000;

      iVar18 = ((uint)pbVar9[-0x2f] * (int)psVar14[-0xf] - (uint)pbVar9[-0xf] * (int)psVar14[0x11])

               * 0x1000;

      iVar8 = (iVar19 + iVar6) * -0x1f62;

      iVar7 = (iVar12 + iVar15 + iVar19 + iVar6) * 0x12d0;

      iVar16 = iVar7 + (iVar12 + iVar6) * -0xe65;

      iVar7 = iVar7 + (iVar19 + iVar15) * -0x2901;

      iVar4 = (iVar12 + iVar15) * -0x63d;

      iVar2 = iVar5 + 0x200 + iVar17;

      iVar13 = iVar19 * 0x312a + iVar8 + iVar7;

      iVar19 = iVar12 * 0x1805 + iVar4 + iVar16;

      iVar7 = iVar7 + iVar15 * 0x20da + iVar4;

      iVar15 = (iVar17 - iVar5) + 0x200;

      iVar4 = iVar10 + 0x200 + iVar18;

      iVar16 = iVar16 + iVar6 * 0x4c7 + iVar8;

      iVar5 = (iVar18 - iVar10) + 0x200;

      piVar1[-7] = iVar2 + iVar19 >> 10;

      piVar1[1] = iVar4 + iVar13 >> 10;

      piVar1[0x31] = iVar2 - iVar19 >> 10;

      piVar1[0x29] = iVar4 - iVar13 >> 10;

      iVar6 = iVar15 + iVar16 >> 10;

      iVar2 = iVar5 - iVar7 >> 10;

      iVar4 = iVar15 - iVar16 >> 10;

      piVar1[9] = iVar7 + iVar5 >> 10;

    }

    piVar1[0x19] = iVar4;

    pbVar9 = pbVar9 + 2;

    piVar1[0x21] = iVar2;

    psVar14 = psVar14 + 2;

    piVar1[0x11] = iVar6;

    piVar1 = piVar1 + 2;

    local_158 = local_158 + -1;

  } while (local_158 != 0);

  piVar1 = local_130;

  local_160 = (undefined1 *)(param_1 + 1);

  local_168 = 8;

  do {

    iVar4 = piVar1[1];

    iVar2 = piVar1[-1];

    iVar6 = piVar1[-3];

    iVar5 = (piVar1[-4] + *piVar1) * 0x8a9;

    iVar19 = iVar5 + *piVar1 * -0x1d8f;

    iVar7 = piVar1[-5];

    iVar5 = piVar1[-4] * 0xc3f + iVar5;

    iVar13 = (iVar6 + iVar4) * -0x1f62;

    iVar17 = (piVar1[-6] + piVar1[-2]) * 0x1000;

    iVar15 = (piVar1[-6] - piVar1[-2]) * 0x1000;

    iVar18 = (iVar17 - iVar5) + 0x1010000;

    iVar16 = (iVar15 - iVar19) + 0x1010000;

    iVar8 = (iVar7 + iVar2 + iVar6 + iVar4) * 0x12d0;

    iVar10 = iVar8 + (iVar7 + iVar4) * -0xe65;

    iVar15 = iVar15 + iVar19 + 0x1010000;

    iVar8 = iVar8 + (iVar6 + iVar2) * -0x2901;

    iVar19 = (iVar7 + iVar2) * -0x63d;

    iVar12 = iVar6 * 0x312a + iVar13 + iVar8;

    iVar8 = iVar2 * 0x20da + iVar19 + iVar8;

    iVar6 = iVar7 * 0x1805 + iVar19 + iVar10;

    iVar2 = iVar5 + iVar17 + 0x1010000;

    iVar10 = iVar4 * 0x4c7 + iVar13 + iVar10;

    uVar11 = iVar2 + iVar6 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    uVar3 = iVar2 - iVar6 >> 0x11;

    local_160[-1] = (char)uVar11;

    if (0xff < uVar3) {

      if ((int)uVar3 < 0) {

        uVar3 = 0;

      }

      else if (0xff < (int)uVar3) {

        uVar3 = 0xff;

      }

    }

    local_160[6] = (char)uVar3;

    uVar11 = iVar15 + iVar12 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    *local_160 = (char)uVar11;

    uVar11 = iVar15 - iVar12 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_160[5] = (char)uVar11;

    uVar11 = iVar16 + iVar8 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_160[1] = (char)uVar11;

    uVar11 = iVar16 - iVar8 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_160[4] = (char)uVar11;

    uVar11 = iVar10 + iVar18 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    local_160[2] = (char)uVar11;

    uVar11 = iVar18 - iVar10 >> 0x11;

    if (0xff < uVar11) {

      if ((int)uVar11 < 0) {

        uVar11 = 0;

      }

      else if (0xff < (int)uVar11) {

        uVar11 = 0xff;

      }

    }

    piVar1 = piVar1 + 8;

    local_160[3] = (char)uVar11;

    local_160 = local_160 + param_2;

    local_168 = local_168 + -1;

  } while (local_168 != 0);

  return;

}




