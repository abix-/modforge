// Address: 0x14014b600
// Ghidra name: FUN_14014b600
// ============ 0x14014b600 FUN_14014b600 (size=484) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined1 FUN_14014b600(longlong param_1,longlong param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined1 uVar4;

  ulonglong uVar5;

  undefined1 *puVar6;

  float *pfVar7;

  float *pfVar8;

  longlong lVar9;

  undefined1 *puVar10;

  ulonglong uVar11;

  longlong lVar12;

  ulonglong uVar13;

  undefined1 auStack_38 [32];

  

  puVar10 = auStack_38;

  uVar13 = (ulonglong)param_3;

  if (param_3 < 1) {

    uVar4 = 1;

  }

  else {

    uVar11 = uVar13 * 0x10;

    if (uVar11 < 0x80) {

      uVar5 = uVar11 + 0xf;

      if (uVar5 <= uVar11) {

        uVar5 = 0xffffffffffffff0;

      }

      puVar10 = auStack_38 + -(uVar5 & 0xfffffffffffffff0);

      puVar6 = &stack0xffffffffffffffe8 + -(uVar5 & 0xfffffffffffffff0);

    }

    else {

      puVar6 = (undefined1 *)FUN_1401841f0(uVar11);

    }

    if (puVar6 == (undefined1 *)0x0) {

      uVar4 = 0;

    }

    else {

      lVar9 = 0;

      fVar1 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x90);

      fVar2 = *(float *)(*(longlong *)(param_1 + 0x138) + 0x94);

      if (3 < uVar13) {

        lVar12 = (uVar13 - 4 >> 2) + 1;

        lVar9 = lVar12 * 4;

        pfVar7 = (float *)(puVar6 + 8);

        pfVar8 = (float *)(param_2 + 8);

        do {

          pfVar7[-2] = fVar1 * pfVar8[-2];

          fVar3 = pfVar8[-1];

          *pfVar7 = fVar1;

          pfVar7[1] = fVar2;

          pfVar7[-1] = fVar2 * fVar3;

          pfVar7[2] = fVar1 * *pfVar8;

          fVar3 = pfVar8[1];

          pfVar7[4] = fVar1;

          pfVar7[5] = fVar2;

          pfVar7[3] = fVar2 * fVar3;

          pfVar7[6] = fVar1 * pfVar8[2];

          fVar3 = pfVar8[3];

          pfVar7[8] = fVar1;

          pfVar7[9] = fVar2;

          pfVar7[7] = fVar2 * fVar3;

          pfVar7[10] = fVar1 * pfVar8[4];

          fVar3 = pfVar8[5];

          pfVar7[0xc] = fVar1;

          pfVar7[0xd] = fVar2;

          pfVar7[0xb] = fVar2 * fVar3;

          lVar12 = lVar12 + -1;

          pfVar7 = pfVar7 + 0x10;

          pfVar8 = pfVar8 + 8;

        } while (lVar12 != 0);

      }

      if (lVar9 < (longlong)uVar13) {

        pfVar7 = (float *)(puVar6 + lVar9 * 0x10 + 8);

        do {

          pfVar7[-2] = fVar1 * *(float *)(param_2 + lVar9 * 8);

          fVar3 = *(float *)(param_2 + 4 + lVar9 * 8);

          lVar9 = lVar9 + 1;

          *pfVar7 = fVar1;

          pfVar7[1] = fVar2;

          pfVar7[-1] = fVar2 * fVar3;

          pfVar7 = pfVar7 + 4;

        } while (lVar9 < (longlong)uVar13);

      }

      *(undefined8 *)(puVar10 + -8) = 0x14014b7b4;

      uVar4 = FUN_14014a7b0(param_1,puVar6,param_3);

      if (0x7f < uVar11) {

        *(undefined8 *)(puVar10 + -8) = 0x14014b7c8;

        FUN_1401841e0(puVar6);

      }

    }

  }

  return uVar4;

}




