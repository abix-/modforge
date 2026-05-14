// Address: 0x14000e3e0
// Ghidra name: FUN_14000e3e0
// ============ 0x14000e3e0 FUN_14000e3e0 (size=570) ============


ulonglong FUN_14000e3e0(longlong param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  ulonglong uVar3;

  float *extraout_RAX;

  int iVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  

  fVar1 = param_4[3];

  iVar4 = 0;

  fVar2 = param_4[2];

  iVar5 = -1;

  fVar10 = fVar2 * (param_3[1] - param_4[1]) + fVar1 * (*param_3 - *param_4);

  fVar11 = fVar1 * (param_3[1] - param_4[1]) - fVar2 * (*param_3 - *param_4);

  fVar9 = 0.0;

  if (*(int *)(param_1 + 0x98) < 1) {

LAB_14000e5a7:

    if (fVar9 <= param_3[4]) goto LAB_14000e5c6;

  }

  else {

    register0x00000020 = (BADSPACEBASE *)(param_1 + 0x1c);

    fVar8 = param_3[4];

    do {

      fVar7 = (*(float *)((longlong)register0x00000020 + -4) - fVar10) *

              *(float *)((longlong)register0x00000020 + 0x3c) +

              (*(float *)register0x00000020 - fVar11) *

              *(float *)((longlong)register0x00000020 + 0x40);

      fVar6 = *(float *)((longlong)register0x00000020 + 0x40) *

              (((param_3[3] - param_4[1]) * fVar1 - (param_3[2] - *param_4) * fVar2) - fVar11) +

              *(float *)((longlong)register0x00000020 + 0x3c) *

              (((param_3[3] - param_4[1]) * fVar2 + (param_3[2] - *param_4) * fVar1) - fVar10);

      if (fVar6 == 0.0) {

        if (fVar7 < 0.0) goto LAB_14000e522;

      }

      else if ((0.0 <= fVar6) || (fVar6 * fVar9 <= fVar7)) {

        if ((0.0 < fVar6) && (fVar7 < fVar6 * fVar8)) {

          fVar8 = fVar7 / fVar6;

        }

      }

      else {

        fVar9 = fVar7 / fVar6;

        iVar5 = iVar4;

      }

      if (fVar8 < fVar9) goto LAB_14000e522;

      iVar4 = iVar4 + 1;

      register0x00000020 = (BADSPACEBASE *)((longlong)register0x00000020 + 8);

    } while (iVar4 < *(int *)(param_1 + 0x98));

    if (0.0 <= fVar9) goto LAB_14000e5a7;

  }

  FID_conflict__assert

            (L"0.0f <= lower && lower <= input.maxFraction",

             L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2PolygonShape.cpp",0x163);

  register0x00000020 = (BADSPACEBASE *)extraout_RAX;

LAB_14000e5c6:

  if (iVar5 < 0) {

LAB_14000e522:

    uVar3 = (ulonglong)register0x00000020 & 0xffffffffffffff00;

  }

  else {

    param_2[2] = fVar9;

    fVar1 = param_4[3];

    fVar2 = param_4[2];

    fVar9 = *(float *)(param_1 + 0x58 + (longlong)iVar5 * 8);

    fVar10 = *(float *)(param_1 + 0x5c + (longlong)iVar5 * 8);

    uVar3 = CONCAT71((int7)(int3)((uint)iVar5 >> 8),1);

    *param_2 = fVar1 * fVar9 - fVar2 * fVar10;

    param_2[1] = fVar9 * fVar2 + fVar1 * fVar10;

  }

  return uVar3;

}




