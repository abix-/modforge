// Address: 0x1401501b0
// Ghidra name: FUN_1401501b0
// ============ 0x1401501b0 FUN_1401501b0 (size=699) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined1 FUN_1401501b0(longlong param_1,longlong param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  undefined1 uVar5;

  ulonglong uVar6;

  undefined1 *puVar7;

  float *pfVar8;

  longlong lVar9;

  longlong lVar10;

  undefined1 *puVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  undefined1 auStack_38 [32];

  

  puVar11 = auStack_38;

  uVar12 = (ulonglong)param_3;

  if ((param_1 == 0) || ((DAT_1403e3d60 != '\0' && (cVar4 = FUN_1401aa7c0(), cVar4 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

  }

  else if (*(char *)(param_1 + 0x2d8) == '\0') {

    if (param_2 == 0) {

      uVar5 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_RenderFillRects(): rects");

      return uVar5;

    }

    if (param_3 < 1) {

      return 1;

    }

    uVar13 = uVar12 * 0x10;

    if (uVar13 < 0x80) {

      uVar6 = uVar13 + 0xf;

      if (uVar6 <= uVar13) {

        uVar6 = 0xffffffffffffff0;

      }

      puVar11 = auStack_38 + -(uVar6 & 0xfffffffffffffff0);

      puVar7 = &stack0xffffffffffffffe8 + -(uVar6 & 0xfffffffffffffff0);

    }

    else {

      puVar7 = (undefined1 *)FUN_1401841f0(uVar13);

    }

    if (puVar7 != (undefined1 *)0x0) {

      lVar10 = 0;

      param_2 = param_2 - (longlong)puVar7;

      fVar2 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x90);

      fVar3 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x94);

      if (3 < uVar12) {

        lVar9 = (uVar12 - 4 >> 2) + 1;

        lVar10 = lVar9 * 4;

        pfVar8 = (float *)(puVar7 + 4);

        do {

          pfVar1 = pfVar8 + 0x10;

          pfVar8[-1] = fVar2 * *(float *)(param_2 + -0x44 + (longlong)pfVar1);

          *pfVar8 = fVar3 * *(float *)(param_2 + -0x40 + (longlong)pfVar1);

          pfVar8[1] = fVar2 * *(float *)(param_2 + -0x3c + (longlong)pfVar1);

          pfVar8[2] = fVar3 * *(float *)(param_2 + -0x38 + (longlong)pfVar1);

          pfVar8[3] = fVar2 * *(float *)(param_2 + -0x34 + (longlong)pfVar1);

          pfVar8[4] = fVar3 * *(float *)(param_2 + -0x30 + (longlong)pfVar1);

          pfVar8[5] = fVar2 * *(float *)(param_2 + -0x2c + (longlong)pfVar1);

          pfVar8[6] = fVar3 * *(float *)(param_2 + -0x28 + (longlong)pfVar1);

          pfVar8[7] = fVar2 * *(float *)(param_2 + -0x24 + (longlong)pfVar1);

          pfVar8[8] = fVar3 * *(float *)(param_2 + -0x20 + (longlong)pfVar1);

          pfVar8[9] = fVar2 * *(float *)(param_2 + -0x1c + (longlong)pfVar1);

          pfVar8[10] = fVar3 * *(float *)(param_2 + -0x18 + (longlong)pfVar1);

          pfVar8[0xb] = fVar2 * *(float *)(param_2 + -0x14 + (longlong)pfVar1);

          pfVar8[0xc] = fVar3 * *(float *)(param_2 + -0x10 + (longlong)pfVar1);

          pfVar8[0xd] = fVar2 * *(float *)(param_2 + -0xc + (longlong)pfVar1);

          pfVar8[0xe] = fVar3 * *(float *)(param_2 + -8 + (longlong)pfVar1);

          lVar9 = lVar9 + -1;

          pfVar8 = pfVar1;

        } while (lVar9 != 0);

      }

      if (lVar10 < (longlong)uVar12) {

        lVar9 = uVar12 - lVar10;

        pfVar8 = (float *)(puVar7 + lVar10 * 0x10 + 4);

        do {

          pfVar1 = pfVar8 + 4;

          pfVar8[-1] = fVar2 * *(float *)(param_2 + -0x14 + (longlong)pfVar1);

          *pfVar8 = fVar3 * *(float *)(param_2 + -0x10 + (longlong)pfVar1);

          pfVar8[1] = fVar2 * *(float *)(param_2 + -0xc + (longlong)pfVar1);

          pfVar8[2] = fVar3 * *(float *)(param_2 + -8 + (longlong)pfVar1);

          lVar9 = lVar9 + -1;

          pfVar8 = pfVar1;

        } while (lVar9 != 0);

      }

      *(undefined8 *)(puVar11 + -8) = 0x140150424;

      uVar5 = FUN_14014a7b0(param_1,puVar7,param_3);

      if (0x7f < uVar13) {

        *(undefined8 *)(puVar11 + -8) = 0x140150438;

        FUN_1401841e0(puVar7);

      }

      return uVar5;

    }

  }

  else {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

  }

  return 0;

}




