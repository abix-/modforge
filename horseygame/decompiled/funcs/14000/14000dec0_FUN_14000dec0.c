// Address: 0x14000dec0
// Ghidra name: FUN_14000dec0
// ============ 0x14000dec0 FUN_14000dec0 (size=533) ============


void FUN_14000dec0(longlong param_1,undefined8 *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  undefined8 *puVar7;

  longlong lVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  undefined1 local_res8 [8];

  ulonglong uVar6;

  

  if (5 < param_3 - 3U) {

    FID_conflict__assert

              (L"3 <= count && count <= 8",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2PolygonShape.cpp",0xad);

  }

  uVar10 = 0;

  *(int *)(param_1 + 0x98) = param_3;

  if (0 < param_3) {

    lVar8 = param_1 - (longlong)param_2;

    uVar6 = uVar10;

    do {

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

      *(undefined8 *)((longlong)param_2 + lVar8 + 0x18) = *param_2;

      param_2 = param_2 + 1;

      param_3 = *(int *)(param_1 + 0x98);

    } while ((int)uVar5 < param_3);

  }

  fVar4 = DAT_14039ca80;

  fVar3 = DAT_14039ca44;

  fVar2 = DAT_14039c9f0;

  fVar1 = DAT_14039c9ec;

  uVar6 = uVar10;

  uVar9 = uVar10;

  if (0 < param_3) {

    do {

      uVar5 = (int)uVar6 + 1;

      uVar6 = uVar9 + 1;

      if (param_3 <= (int)uVar5) {

        uVar6 = uVar10;

      }

      fVar12 = *(float *)(param_1 + 0x18 + uVar6 * 8) - *(float *)(param_1 + 0x18 + uVar9 * 8);

      fVar13 = *(float *)(param_1 + 0x1c + uVar6 * 8) - *(float *)(param_1 + 0x1c + uVar9 * 8);

      if (fVar12 * fVar12 + fVar13 * fVar13 <= fVar1) {

        FID_conflict__assert

                  (L"edge.LengthSquared() > 1.192092896e-07F * 1.192092896e-07F",

                   L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2PolygonShape.cpp",0xbc);

      }

      *(float *)(param_1 + 0x58 + uVar9 * 8) = fVar13;

      *(float *)(param_1 + 0x5c + uVar9 * 8) = fVar12 * fVar4;

      fVar12 = *(float *)(param_1 + 0x5c + uVar9 * 8);

      fVar11 = fVar12 * fVar12 + fVar13 * fVar13;

      if (fVar11 < 0.0) {

        fVar11 = (float)FUN_1402cdfa0(fVar11);

      }

      else {

        fVar11 = SQRT(fVar11);

      }

      if (fVar2 <= fVar11) {

        *(float *)(param_1 + 0x58 + uVar9 * 8) = (fVar3 / fVar11) * fVar13;

        *(float *)(param_1 + 0x5c + uVar9 * 8) = (fVar3 / fVar11) * fVar12;

      }

      param_3 = *(int *)(param_1 + 0x98);

      uVar6 = (ulonglong)uVar5;

      uVar9 = uVar9 + 1;

    } while ((int)uVar5 < param_3);

  }

  puVar7 = (undefined8 *)FUN_14000d650(local_res8,param_1 + 0x18,param_3);

  *(undefined8 *)(param_1 + 0x10) = *puVar7;

  return;

}




