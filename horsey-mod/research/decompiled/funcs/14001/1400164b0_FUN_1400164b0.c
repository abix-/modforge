// Address: 0x1400164b0
// Ghidra name: FUN_1400164b0
// ============ 0x1400164b0 FUN_1400164b0 (size=854) ============


void FUN_1400164b0(float *param_1,float *param_2,longlong param_3,float *param_4,longlong param_5,

                  float *param_6)



{

  float fVar1;

  byte bVar2;

  byte bVar3;

  ushort uVar4;

  float *pfVar5;

  byte *pbVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  int local_res8;

  

  if (3 < *(ushort *)(param_2 + 1)) {

    FID_conflict__assert

              (L"cache->count <= 3",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.cpp",0x66);

  }

  uVar4 = *(ushort *)(param_2 + 1);

  fVar7 = (float)(uint)uVar4;

  param_1[0x1b] = (float)(uint)uVar4;

  local_res8 = 0;

  if ((float)(uint)uVar4 != 0.0) {

    pfVar5 = param_1 + 5;

    pbVar6 = (byte *)((longlong)param_2 + 9);

    do {

      bVar2 = pbVar6[-3];

      bVar3 = *pbVar6;

      pfVar5[2] = (float)(uint)bVar2;

      pfVar5[3] = (float)(uint)bVar3;

      if (*(int *)(param_3 + 0x18) <= (int)(uint)bVar2) {

        FID_conflict__assert

                  (L"0 <= index && index < m_count",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.h",0x67);

      }

      fVar7 = *(float *)(*(longlong *)(param_3 + 0x10) + (ulonglong)bVar2 * 8);

      fVar8 = *(float *)(*(longlong *)(param_3 + 0x10) + 4 + (ulonglong)bVar2 * 8);

      fVar11 = pfVar5[3];

      if (((int)fVar11 < 0) || (*(int *)(param_5 + 0x18) <= (int)fVar11)) {

        FID_conflict__assert

                  (L"0 <= index && index < m_count",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.h",0x67);

      }

      pbVar6 = pbVar6 + 1;

      fVar1 = *(float *)(*(longlong *)(param_5 + 0x10) + (longlong)(int)fVar11 * 8);

      local_res8 = local_res8 + 1;

      fVar11 = *(float *)(*(longlong *)(param_5 + 0x10) + 4 + (longlong)(int)fVar11 * 8);

      fVar9 = (param_4[3] * fVar7 - param_4[2] * fVar8) + *param_4;

      fVar10 = param_4[3] * fVar8 + param_4[2] * fVar7 + param_4[1];

      pfVar5[-5] = fVar9;

      pfVar5[-4] = fVar10;

      fVar7 = (param_6[3] * fVar1 - fVar11 * param_6[2]) + *param_6;

      fVar8 = param_6[3] * fVar11 + fVar1 * param_6[2] + param_6[1];

      pfVar5[-3] = fVar7;

      pfVar5[1] = 0.0;

      pfVar5[-2] = fVar8;

      pfVar5[-1] = fVar7 - fVar9;

      *pfVar5 = fVar8 - fVar10;

      pfVar5 = pfVar5 + 9;

      fVar7 = param_1[0x1b];

    } while (local_res8 < (int)fVar7);

  }

  if (1 < (int)fVar7) {

    fVar7 = *param_2;

    fVar8 = (float)FUN_140016810(param_1);

    if (((fVar8 < fVar7 * DAT_14039ca34) || (fVar7 + fVar7 < fVar8)) || (fVar8 < DAT_14039c9f0)) {

      param_1[0x1b] = 0.0;

    }

  }

  if (param_1[0x1b] == 0.0) {

    param_1[7] = 0.0;

    param_1[8] = 0.0;

    if (*(int *)(param_3 + 0x18) < 1) {

      FID_conflict__assert

                (L"0 <= index && index < m_count",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.h"

                 ,0x67);

    }

    fVar7 = **(float **)(param_3 + 0x10);

    fVar8 = (*(float **)(param_3 + 0x10))[1];

    if (*(int *)(param_5 + 0x18) < 1) {

      FID_conflict__assert

                (L"0 <= index && index < m_count",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.h"

                 ,0x67);

    }

    fVar11 = **(float **)(param_5 + 0x10);

    fVar1 = (*(float **)(param_5 + 0x10))[1];

    fVar9 = (param_4[3] * fVar7 - param_4[2] * fVar8) + *param_4;

    fVar8 = param_4[3] * fVar8 + param_4[2] * fVar7 + param_4[1];

    *param_1 = fVar9;

    param_1[1] = fVar8;

    fVar7 = (fVar11 * param_6[3] - fVar1 * param_6[2]) + *param_6;

    fVar11 = fVar11 * param_6[2] + fVar1 * param_6[3] + param_6[1];

    param_1[2] = fVar7;

    param_1[3] = fVar11;

    param_1[4] = fVar7 - fVar9;

    param_1[5] = fVar11 - fVar8;

    param_1[0x1b] = 1.4013e-45;

  }

  return;

}




