// Address: 0x14020de30
// Ghidra name: FUN_14020de30
// ============ 0x14020de30 FUN_14020de30 (size=930) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Type propagation algorithm not settling */



void FUN_14020de30(longlong param_1)



{

  double dVar1;

  char cVar2;

  undefined4 uVar3;

  longlong *plVar4;

  code *pcVar5;

  double dVar6;

  undefined1 uVar7;

  int iVar8;

  uint uVar9;

  ulonglong uVar10;

  double *pdVar11;

  uint uVar12;

  int iVar13;

  ulonglong uVar14;

  double *pdVar15;

  undefined1 *puVar16;

  undefined1 *puVar17;

  undefined1 *puVar18;

  double *pdVar19;

  double *pdVar20;

  double *pdVar21;

  uint uVar22;

  float fVar23;

  uint local_res8 [2];

  uint local_res10 [2];

  uint local_res18 [2];

  longlong local_res20;

  undefined1 auStack_b8 [64];

  longlong *local_78 [7];

  

  puVar16 = auStack_b8;

  plVar4 = *(longlong **)(param_1 + 0x148);

  uVar14 = 0xff;

  if (*(int *)(param_1 + 0x70) < 0xff) {

    uVar14 = (ulonglong)*(uint *)(param_1 + 0x70);

  }

  pdVar20 = (double *)0x0;

  iVar13 = 0;

  local_res8[0] = (uint)uVar14;

  local_res18[0] = 0xff;

  if (*(int *)(param_1 + 0x60) < 0xff) {

    local_res18[0] = *(uint *)(param_1 + 0x60);

  }

  uVar22 = 0xff;

  if (*(int *)(param_1 + 0x44) < 0xff) {

    uVar22 = *(uint *)(param_1 + 0x44);

  }

  pdVar15 = pdVar20;

  if (local_res8[0] != 0) {

    uVar10 = uVar14 + 0xf;

    if (uVar10 <= uVar14) {

      uVar10 = 0xffffffffffffff0;

    }

    puVar16 = auStack_b8 + -(uVar10 & 0xfffffffffffffff0);

    pdVar15 = (double *)((longlong)local_78 + -(uVar10 & 0xfffffffffffffff0));

  }

  puVar17 = puVar16;

  pdVar21 = pdVar20;

  local_78[0] = plVar4;

  if (local_res18[0] != 0) {

    uVar10 = (ulonglong)local_res18[0] * 4 + 0xf;

    if (uVar10 <= (ulonglong)local_res18[0] * 4) {

      uVar10 = 0xffffffffffffff0;

    }

    *(undefined8 *)(puVar16 + -8) = 0x14020deec;

    puVar17 = puVar16 + -(uVar10 & 0xfffffffffffffff0);

    pdVar21 = (double *)(puVar16 + -(uVar10 & 0xfffffffffffffff0) + 0x40);

  }

  puVar18 = puVar17;

  pdVar19 = pdVar20;

  if (uVar22 != 0) {

    uVar10 = (ulonglong)uVar22 * 8 + 0xf;

    if (uVar10 <= (ulonglong)uVar22 * 8) {

      uVar10 = 0xffffffffffffff0;

    }

    *(undefined8 *)(puVar17 + -8) = 0x14020df18;

    puVar18 = puVar17 + -(uVar10 & 0xfffffffffffffff0);

    pdVar19 = (double *)(puVar17 + -(uVar10 & 0xfffffffffffffff0) + 0x40);

  }

  plVar4 = (longlong *)*plVar4;

  pcVar5 = *(code **)(*plVar4 + 0x68);

  *(longlong **)(puVar18 + 0x38) = &local_res20;

  *(double **)(puVar18 + 0x30) = pdVar19;

  *(uint *)(puVar18 + 0x28) = uVar22;

  *(double **)(puVar18 + 0x20) = pdVar21;

  *(undefined8 *)(puVar18 + -8) = 0x14020df50;

  local_res10[0] = uVar22;

  iVar8 = (*pcVar5)(plVar4,uVar14,pdVar15,local_res18[0]);

  if ((-1 < iVar8) && ((local_res20 == 0 || (local_res20 != local_78[0][8])))) {

    local_78[0][8] = local_res20;

    pdVar11 = pdVar20;

    if (uVar22 == 0) {

LAB_14020dfa3:

      *(undefined8 *)(puVar18 + -8) = 0x14020dfa8;

      local_res20 = FUN_140149300();

      uVar9 = local_res8[0];

      pdVar11 = pdVar20;

      if (local_res8[0] != 0) {

        do {

          cVar2 = *(char *)pdVar15;

          *(undefined8 *)(puVar18 + -8) = 0x14020dfdb;

          FUN_14015ad00(local_res20,param_1,(ulonglong)pdVar11 & 0xff,cVar2 != '\0');

          uVar12 = (int)pdVar11 + 1;

          pdVar15 = (double *)((longlong)pdVar15 + 1);

          pdVar11 = (double *)(ulonglong)uVar12;

          uVar22 = local_res10[0];

        } while (uVar12 < uVar9);

      }

      uVar9 = local_res18[0];

      pdVar15 = pdVar20;

      if (local_res18[0] != 0) {

        do {

          uVar3 = *(undefined4 *)pdVar21;

          *(undefined8 *)(puVar18 + -8) = 0x14020e009;

          uVar7 = FUN_14020e410(uVar3);

          *(undefined8 *)(puVar18 + -8) = 0x14020e020;

          FUN_14015ae90(local_res20,param_1,(ulonglong)pdVar15 & 0xff,uVar7);

          uVar12 = (int)pdVar15 + 1;

          pdVar15 = (double *)(ulonglong)uVar12;

          pdVar21 = (double *)((longlong)pdVar21 + 4);

        } while (uVar12 < uVar9);

      }

      dVar6 = DAT_140350300;

      pdVar15 = pdVar20;

      if (uVar22 != 0) {

        do {

          dVar1 = *pdVar19;

          *(undefined8 *)(puVar18 + -8) = 0x14020e069;

          FUN_14015aab0(local_res20,param_1,(ulonglong)pdVar15 & 0xff,

                        CONCAT62(0xffff,-0x8000 - (short)(int)(dVar1 * dVar6)));

          uVar9 = (int)pdVar15 + 1;

          pdVar19 = pdVar19 + 1;

          pdVar15 = (double *)(ulonglong)uVar9;

        } while (uVar9 < uVar22);

      }

    }

    else {

      do {

        if (pdVar19[(longlong)pdVar11] != 0.0) goto LAB_14020dfa3;

        uVar9 = (int)pdVar11 + 1;

        pdVar11 = (double *)(ulonglong)uVar9;

      } while (uVar9 < uVar22);

      *(undefined8 *)(puVar18 + -8) = 0x14020df9e;

      FUN_14015a3a0(param_1);

    }

  }

  plVar4 = (longlong *)local_78[0][2];

  if (plVar4 != (longlong *)0x0) {

    local_78[0] = (longlong *)0x0;

    pcVar5 = *(code **)(*plVar4 + 0x30);

    *(undefined8 *)(puVar18 + -8) = 0x14020e097;

    iVar8 = (*pcVar5)(plVar4,local_78);

    plVar4 = local_78[0];

    if ((-1 < iVar8) && (local_78[0] != (longlong *)0x0)) {

      local_res8[0] = 0;

      local_res10[0] = 0;

      pcVar5 = *(code **)(*local_78[0] + 0x50);

      *(undefined8 *)(puVar18 + -8) = 0x14020e0cb;

      iVar8 = (*pcVar5)(plVar4,local_res18);

      plVar4 = local_78[0];

      if (-1 < iVar8) {

        if (local_res18[0] == 0) {

          pdVar20 = (double *)0x2;

        }

        else if (local_res18[0] == 1) {

          pdVar20 = (double *)0x1;

        }

        else if (local_res18[0] == 2) {

          pdVar20 = (double *)0x4;

        }

        else if (local_res18[0] == 3) {

          pdVar20 = (double *)0x3;

        }

      }

      pcVar5 = *(code **)(*local_78[0] + 0x40);

      *(undefined8 *)(puVar18 + -8) = 0x14020e114;

      iVar8 = (*pcVar5)(plVar4,local_78 + 1);

      plVar4 = local_78[1];

      if (-1 < iVar8) {

        pcVar5 = *(code **)(*local_78[1] + 0x30);

        *(undefined8 *)(puVar18 + -8) = 0x14020e12d;

        (*pcVar5)(plVar4,local_res8);

        pcVar5 = *(code **)(*local_78[1] + 0x10);

        *(undefined8 *)(puVar18 + -8) = 0x14020e13a;

        (*pcVar5)();

      }

      plVar4 = local_78[0];

      pcVar5 = *(code **)(*local_78[0] + 0x48);

      *(undefined8 *)(puVar18 + -8) = 0x14020e14c;

      iVar8 = (*pcVar5)(plVar4,local_78 + 2);

      plVar4 = local_78[2];

      if (-1 < iVar8) {

        pcVar5 = *(code **)(*local_78[2] + 0x30);

        *(undefined8 *)(puVar18 + -8) = 0x14020e165;

        (*pcVar5)(plVar4,local_res10);

        pcVar5 = *(code **)(*local_78[2] + 0x10);

        *(undefined8 *)(puVar18 + -8) = 0x14020e172;

        (*pcVar5)();

      }

      if (0 < (int)local_res8[0]) {

        *(undefined8 *)(puVar18 + -8) = 0x14020e19f;

        fVar23 = (float)thunk_FUN_1402e1d00(((float)(int)local_res10[0] / (float)(int)local_res8[0])

                                            * DAT_14039ca5c);

        iVar13 = (int)fVar23;

      }

      *(undefined8 *)(puVar18 + -8) = 0x14020e1b0;

      FUN_14015af40(param_1,pdVar20,iVar13);

      pcVar5 = *(code **)(*local_78[0] + 0x10);

      *(undefined8 *)(puVar18 + -8) = 0x14020e1bd;

      (*pcVar5)();

    }

  }

  return;

}




