// Address: 0x14000f610
// Ghidra name: FUN_14000f610
// ============ 0x14000f610 FUN_14000f610 (size=637) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



void FUN_14000f610(longlong param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  uint *puVar6;

  uint uVar7;

  uint *puVar8;

  int iVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  undefined1 auStack_f8 [32];

  uint local_d8 [16];

  ulonglong local_98;

  

  uVar5 = DAT_14039cac0;

  local_98 = DAT_1403e8b00 ^ (ulonglong)auStack_f8;

  uVar7 = *(uint *)(param_1 + 0x98);

  uVar11 = (ulonglong)uVar7;

  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ DAT_14039cac0;

  fVar4 = DAT_14039ca80;

  fVar3 = DAT_14039ca44;

  fVar2 = DAT_14039c9f0;

  fVar1 = DAT_14039c9ec;

  if (0 < (int)uVar7) {

    puVar6 = (uint *)(param_1 + 0x14 + (longlong)(int)uVar7 * 8);

    puVar8 = local_d8 + 1;

    do {

      uVar7 = *puVar6;

      puVar8[-1] = puVar6[-1] ^ uVar5;

      puVar6 = puVar6 + -2;

      *puVar8 = uVar7;

      uVar11 = uVar11 - 1;

      puVar8 = puVar8 + 2;

    } while (uVar11 != 0);

    uVar12 = 0;

    puVar6 = local_d8;

    uVar11 = uVar12;

    do {

      uVar7 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar7;

      *(undefined8 *)((param_1 - (longlong)local_d8) + 0x18 + (longlong)puVar6) =

           *(undefined8 *)puVar6;

      puVar6 = puVar6 + 2;

      iVar9 = *(int *)(param_1 + 0x98);

    } while ((int)uVar7 < iVar9);

    uVar11 = uVar12;

    uVar10 = uVar12;

    if (0 < iVar9) {

      do {

        uVar7 = (int)uVar11 + 1;

        uVar11 = uVar10 + 1;

        if (iVar9 <= (int)uVar7) {

          uVar11 = uVar12;

        }

        fVar14 = *(float *)(param_1 + 0x18 + uVar11 * 8) - *(float *)(param_1 + 0x18 + uVar10 * 8);

        fVar15 = *(float *)(param_1 + 0x1c + uVar11 * 8) - *(float *)(param_1 + 0x1c + uVar10 * 8);

        if (fVar14 * fVar14 + fVar15 * fVar15 <= fVar1) {

          FID_conflict__assert

                    (L"edge.LengthSquared() > 1.192092896e-07F * 1.192092896e-07F",

                     L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2PolygonShape.cpp",0x23d);

        }

        *(float *)(param_1 + 0x58 + uVar10 * 8) = fVar15;

        *(float *)(param_1 + 0x5c + uVar10 * 8) = fVar14 * fVar4;

        fVar14 = *(float *)(param_1 + 0x5c + uVar10 * 8);

        fVar13 = fVar14 * fVar14 + fVar15 * fVar15;

        if (fVar13 < 0.0) {

          fVar13 = (float)FUN_1402cdfa0(fVar13);

        }

        else {

          fVar13 = SQRT(fVar13);

        }

        if (fVar2 <= fVar13) {

          *(float *)(param_1 + 0x58 + uVar10 * 8) = (fVar3 / fVar13) * fVar15;

          *(float *)(param_1 + 0x5c + uVar10 * 8) = (fVar3 / fVar13) * fVar14;

        }

        iVar9 = *(int *)(param_1 + 0x98);

        uVar11 = (ulonglong)uVar7;

        uVar10 = uVar10 + 1;

      } while ((int)uVar7 < iVar9);

    }

  }

  return;

}




