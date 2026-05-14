// Address: 0x14014a7b0
// Ghidra name: FUN_14014a7b0
// ============ 0x14014a7b0 FUN_14014a7b0 (size=1242) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



ulonglong FUN_14014a7b0(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  longlong lVar5;

  code *pcVar6;

  byte bVar7;

  uint uVar8;

  undefined4 *puVar9;

  ulonglong uVar10;

  float *pfVar11;

  ulonglong uVar12;

  int *piVar13;

  undefined8 uVar14;

  int *piVar15;

  undefined1 *puVar16;

  ulonglong uVar17;

  int iVar18;

  ulonglong uVar19;

  float *pfVar20;

  int iVar21;

  int iVar22;

  undefined1 auStack_d8 [128];

  float local_58;

  int local_54;

  float *local_50;

  ulonglong local_48;

  undefined4 *local_40;

  

  puVar16 = auStack_d8;

  lVar5 = *(longlong *)(param_1 + 0x40);

  bVar7 = 0;

  uVar14 = 7;

  if (lVar5 == 0) {

    uVar14 = 10;

  }

  puVar9 = (undefined4 *)FUN_14014a430(param_1,uVar14,0);

  if (puVar9 == (undefined4 *)0x0) goto LAB_14014ac46;

  local_40 = puVar9;

  if (lVar5 != 0) {

    uVar17 = (**(code **)(param_1 + 0x40))(param_1,puVar9,param_2,param_3);

    if ((char)uVar17 != '\0') {

      return uVar17;

    }

    *puVar9 = 0;

    return uVar17;

  }

  uVar17 = (longlong)(param_3 * 8) * 4;

  local_48 = uVar17;

  if (uVar17 < 0x80) {

    uVar10 = uVar17 + 0xf;

    if (uVar10 <= uVar17) {

      uVar10 = 0xffffffffffffff0;

    }

    puVar16 = auStack_d8 + -(uVar10 & 0xfffffffffffffff0);

    pfVar11 = (float *)((longlong)&local_58 + -(uVar10 & 0xfffffffffffffff0));

  }

  else {

    pfVar11 = (float *)FUN_1401841f0(uVar17);

  }

  local_58 = (float)(param_3 * 6);

  uVar10 = (longlong)(int)local_58 * 4;

  local_50 = pfVar11;

  if (uVar10 < 0x80) {

    uVar12 = uVar10 + 0xf;

    if (uVar12 <= uVar10) {

      uVar12 = 0xffffffffffffff0;

    }

    *(undefined8 *)(puVar16 + -8) = 0x14014a89c;

    piVar13 = (int *)(puVar16 + -(uVar12 & 0xfffffffffffffff0) + 0x80);

    puVar16 = puVar16 + -(uVar12 & 0xfffffffffffffff0);

  }

  else {

    *(undefined8 *)(puVar16 + -8) = 0x14014a8b1;

    piVar13 = (int *)FUN_1401841f0(uVar10);

  }

  if ((pfVar11 != (float *)0x0) && (piVar13 != (int *)0x0)) {

    local_54 = param_3 * 4;

    uVar12 = 0;

    uVar8 = 0;

    iVar21 = 0;

    piVar15 = piVar13;

    if (param_3 < 4) {

      uVar19 = uVar12;

      if (0 < param_3) goto LAB_14014ab10;

    }

    else {

      pfVar20 = (float *)(param_2 + 8);

      uVar8 = (param_3 - 4U >> 2) + 1;

      iVar18 = 2;

      uVar17 = (ulonglong)uVar8;

      iVar21 = uVar8 * 4;

      uVar19 = (ulonglong)uVar8 * 4;

      do {

        fVar1 = pfVar20[-2];

        fVar2 = pfVar20[-1];

        fVar3 = *pfVar20;

        fVar4 = pfVar20[1];

        *pfVar11 = fVar1;

        pfVar11[1] = fVar2;

        pfVar11[3] = fVar2;

        pfVar11[2] = fVar1 + fVar3;

        pfVar11[4] = fVar1 + fVar3;

        pfVar11[5] = fVar2 + fVar4;

        pfVar11[7] = fVar2 + fVar4;

        pfVar11[6] = fVar1;

        iVar22 = (int)uVar12;

        *piVar15 = iVar22;

        piVar15[1] = iVar18 + -1;

        piVar15[5] = iVar18 + 1;

        piVar15[2] = iVar18;

        piVar15[3] = iVar22;

        piVar15[4] = iVar18;

        fVar1 = pfVar20[2];

        fVar2 = pfVar20[3];

        fVar3 = pfVar20[4];

        fVar4 = pfVar20[5];

        pfVar11[8] = fVar1;

        pfVar11[9] = fVar2;

        pfVar11[10] = fVar1 + fVar3;

        pfVar11[0xc] = fVar1 + fVar3;

        pfVar11[0xd] = fVar2 + fVar4;

        pfVar11[0xf] = fVar2 + fVar4;

        pfVar11[0xb] = fVar2;

        pfVar11[0xe] = fVar1;

        piVar15[6] = iVar18 + 2;

        piVar15[7] = iVar18 + 3;

        piVar15[8] = iVar18 + 4;

        piVar15[10] = iVar18 + 4;

        piVar15[0xb] = iVar18 + 5;

        piVar15[9] = iVar18 + 2;

        fVar1 = pfVar20[6];

        fVar2 = pfVar20[7];

        fVar3 = pfVar20[8];

        fVar4 = pfVar20[9];

        pfVar11[0x10] = fVar1;

        pfVar11[0x11] = fVar2;

        pfVar11[0x12] = fVar1 + fVar3;

        pfVar11[0x14] = fVar1 + fVar3;

        pfVar11[0x15] = fVar2 + fVar4;

        pfVar11[0x17] = fVar2 + fVar4;

        pfVar11[0x13] = fVar2;

        pfVar11[0x16] = fVar1;

        piVar15[0xc] = iVar18 + 6;

        piVar15[0xd] = iVar18 + 7;

        piVar15[0xe] = iVar18 + 8;

        piVar15[0x10] = iVar18 + 8;

        piVar15[0x11] = iVar18 + 9;

        piVar15[0xf] = iVar18 + 6;

        fVar1 = pfVar20[10];

        fVar2 = pfVar20[0xb];

        fVar3 = pfVar20[0xc];

        fVar4 = pfVar20[0xd];

        pfVar11[0x18] = fVar1;

        pfVar11[0x19] = fVar2;

        pfVar11[0x1a] = fVar1 + fVar3;

        pfVar11[0x1c] = fVar1 + fVar3;

        pfVar11[0x1b] = fVar2;

        pfVar11[0x1d] = fVar2 + fVar4;

        pfVar11[0x1e] = fVar1;

        pfVar11[0x1f] = fVar2 + fVar4;

        pfVar20 = pfVar20 + 0x10;

        piVar15[0x12] = iVar18 + 10;

        pfVar11 = pfVar11 + 0x20;

        piVar15[0x13] = iVar18 + 0xb;

        uVar8 = iVar22 + 0x10;

        uVar12 = (ulonglong)uVar8;

        piVar15[0x15] = iVar18 + 10;

        piVar15[0x14] = iVar18 + 0xc;

        piVar15[0x16] = iVar18 + 0xc;

        piVar15[0x17] = iVar18 + 0xd;

        iVar18 = iVar18 + 0x10;

        piVar15 = piVar15 + 0x18;

        uVar17 = uVar17 - 1;

      } while (uVar17 != 0);

      uVar17 = local_48;

      if (iVar21 < param_3) {

LAB_14014ab10:

        iVar18 = uVar8 + 2;

        pfVar20 = (float *)(uVar19 * 0x10 + param_2 + 8);

        uVar12 = (ulonglong)(uint)(param_3 - iVar21);

        do {

          fVar1 = pfVar20[-2];

          iVar21 = iVar18 + -2;

          fVar2 = pfVar20[-1];

          fVar3 = *pfVar20;

          fVar4 = pfVar20[1];

          *pfVar11 = fVar1;

          pfVar20 = pfVar20 + 4;

          pfVar11[1] = fVar2;

          pfVar11[3] = fVar2;

          pfVar11[2] = fVar1 + fVar3;

          pfVar11[4] = fVar1 + fVar3;

          pfVar11[5] = fVar2 + fVar4;

          pfVar11[7] = fVar2 + fVar4;

          pfVar11[6] = fVar1;

          pfVar11 = pfVar11 + 8;

          *piVar15 = iVar21;

          piVar15[1] = iVar18 + -1;

          iVar22 = iVar18 + 1;

          piVar15[2] = iVar18;

          piVar15[4] = iVar18;

          iVar18 = iVar18 + 4;

          piVar15[5] = iVar22;

          piVar15[3] = iVar21;

          piVar15 = piVar15 + 6;

          uVar12 = uVar12 - 1;

        } while (uVar12 != 0);

      }

    }

    puVar9 = local_40;

    pfVar11 = local_50;

    fVar1 = local_58;

    pcVar6 = *(code **)(param_1 + 0x58);

    *(undefined4 *)(puVar16 + 0x70) = DAT_14039ca44;

    *(undefined4 *)(puVar16 + 0x68) = DAT_14039ca44;

    *(undefined4 *)(puVar16 + 0x60) = 4;

    *(float *)(puVar16 + 0x58) = fVar1;

    iVar21 = local_54;

    *(int **)(puVar16 + 0x50) = piVar13;

    *(int *)(puVar16 + 0x48) = iVar21;

    *(undefined4 *)(puVar16 + 0x40) = 0;

    *(undefined8 *)(puVar16 + 0x38) = 0;

    *(undefined4 *)(puVar16 + 0x30) = 0;

    *(longlong *)(puVar16 + 0x28) = param_1 + 0x21c;

    *(undefined4 *)(puVar16 + 0x20) = 8;

    *(undefined8 *)(puVar16 + -8) = 0x14014ac16;

    bVar7 = (*pcVar6)(param_1,puVar9,0,pfVar11);

    pfVar11 = local_50;

    if (bVar7 == 0) {

      *puVar9 = 0;

    }

  }

  if (0x7f < uVar17) {

    *(undefined8 *)(puVar16 + -8) = 0x14014ac35;

    FUN_1401841e0(pfVar11);

  }

  if (0x7f < uVar10) {

    *(undefined8 *)(puVar16 + -8) = 0x14014ac46;

    FUN_1401841e0(piVar13);

  }

LAB_14014ac46:

  return (ulonglong)bVar7;

}




