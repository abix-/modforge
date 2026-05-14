// Address: 0x1400210d0
// Ghidra name: FUN_1400210d0
// ============ 0x1400210d0 FUN_1400210d0 (size=1148) ============


void FUN_1400210d0(undefined8 *param_1,longlong param_2,float *param_3,longlong param_4,

                  float *param_5)



{

  float fVar1;

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

  

  *(undefined4 *)((longlong)param_1 + 0x3c) = 0;

  fVar11 = *(float *)(param_2 + 0xc) + *(float *)(param_4 + 0xc);

  fVar8 = *(float *)(param_2 + 0x18);

  fVar4 = *(float *)(param_2 + 0x1c);

  fVar5 = ((param_5[3] * *(float *)(param_4 + 0x10) - param_5[2] * *(float *)(param_4 + 0x14)) +

          *param_5) - *param_3;

  fVar6 = (param_5[2] * *(float *)(param_4 + 0x10) + param_5[3] * *(float *)(param_4 + 0x14) +

          param_5[1]) - param_3[1];

  fVar1 = *(float *)(param_2 + 0x10);

  fVar9 = fVar8 - fVar1;

  fVar2 = *(float *)(param_2 + 0x14);

  fVar12 = param_3[2] * fVar6 + param_3[3] * fVar5;

  fVar10 = param_3[3] * fVar6 - param_3[2] * fVar5;

  fVar7 = fVar4 - fVar2;

  fVar6 = fVar12 - fVar1;

  fVar13 = fVar10 - fVar2;

  fVar5 = (fVar4 - fVar10) * fVar7 + (fVar8 - fVar12) * fVar9;

  fVar14 = fVar13 * fVar7 + fVar6 * fVar9;

  if (0.0 < fVar14) {

    if (0.0 < fVar5) {

      fVar15 = fVar9 * fVar9 + fVar7 * fVar7;

      if (fVar15 <= 0.0) {

        FID_conflict__assert

                  (L"den > 0.0f",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2CollideEdge.cpp",0x7f);

      }

      fVar3 = DAT_14039ca44;

      fVar15 = DAT_14039ca44 / fVar15;

      fVar12 = fVar12 - (fVar8 * fVar14 + fVar1 * fVar5) * fVar15;

      fVar10 = fVar10 - (fVar4 * fVar14 + fVar2 * fVar5) * fVar15;

      if (fVar11 * fVar11 < fVar10 * fVar10 + fVar12 * fVar12) {

        return;

      }

      fVar8 = (float)((uint)fVar7 ^ DAT_14039cac0);

      if ((float)((uint)fVar7 ^ DAT_14039cac0) * fVar6 + fVar9 * fVar13 < 0.0) {

        fVar9 = (float)((uint)fVar9 ^ DAT_14039cac0);

        fVar8 = fVar7;

      }

      fVar4 = fVar9 * fVar9 + fVar8 * fVar8;

      if (fVar4 < 0.0) {

        fVar4 = (float)FUN_1402cdfa0(fVar4);

      }

      else {

        fVar4 = SQRT(fVar4);

      }

      if (DAT_14039c9f0 <= fVar4) {

        fVar8 = fVar8 * (fVar3 / fVar4);

        fVar9 = fVar9 * (fVar3 / fVar4);

      }

      *(float *)(param_1 + 5) = fVar8;

      *(float *)((longlong)param_1 + 0x2c) = fVar9;

      *(float *)(param_1 + 6) = fVar1;

      *(float *)((longlong)param_1 + 0x34) = fVar2;

      *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

      *(undefined4 *)(param_1 + 7) = 1;

      *(undefined4 *)(param_1 + 2) = 0x10000;

      *param_1 = *(undefined8 *)(param_4 + 0x10);

      return;

    }

    fVar12 = fVar12 - fVar8;

    fVar10 = fVar10 - fVar4;

    if (fVar11 * fVar11 < fVar10 * fVar10 + fVar12 * fVar12) {

      return;

    }

    if ((*(char *)(param_2 + 0x31) != '\0') &&

       (0.0 < (*(float *)(param_2 + 0x2c) - fVar4) * fVar10 +

              (*(float *)(param_2 + 0x28) - fVar8) * fVar12)) {

      return;

    }

    *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

    *(undefined4 *)(param_1 + 7) = 0;

    param_1[5] = 0;

    *(float *)(param_1 + 6) = fVar8;

    *(float *)((longlong)param_1 + 0x34) = fVar4;

    param_5._0_1_ = 1;

  }

  else {

    if (fVar11 * fVar11 < fVar13 * fVar13 + fVar6 * fVar6) {

      return;

    }

    if ((*(char *)(param_2 + 0x30) != '\0') &&

       (0.0 < (fVar2 - *(float *)(param_2 + 0x24)) * (fVar2 - fVar10) +

              (fVar1 - *(float *)(param_2 + 0x20)) * (fVar1 - fVar12))) {

      return;

    }

    *(undefined4 *)((longlong)param_1 + 0x3c) = 1;

    *(undefined4 *)(param_1 + 7) = 0;

    param_1[5] = 0;

    *(float *)(param_1 + 6) = fVar1;

    *(float *)((longlong)param_1 + 0x34) = fVar2;

    param_5._0_1_ = 0;

  }

  *(uint *)(param_1 + 2) = (uint)(byte)param_5;

  *param_1 = *(undefined8 *)(param_4 + 0x10);

  return;

}




