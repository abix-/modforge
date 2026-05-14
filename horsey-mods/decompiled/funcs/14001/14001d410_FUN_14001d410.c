// Address: 0x14001d410
// Ghidra name: FUN_14001d410
// ============ 0x14001d410 FUN_14001d410 (size=976) ============


void FUN_14001d410(longlong param_1,float *param_2)



{

  float fVar1;

  undefined4 uVar2;

  float fVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  uint uVar7;

  longlong lVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  

  lVar5 = *(longlong *)(param_1 + 0x68);

  lVar8 = (longlong)*(int *)(lVar5 + 8);

  *(int *)(param_1 + 0xb0) = *(int *)(lVar5 + 8);

  *(undefined8 *)(param_1 + 0xbc) = *(undefined8 *)(lVar5 + 0x1c);

  fVar13 = *(float *)(lVar5 + 0x94);

  *(float *)(param_1 + 0xc4) = fVar13;

  fVar14 = *(float *)(lVar5 + 0x9c);

  *(float *)(param_1 + 200) = fVar14;

  lVar6 = *(longlong *)(param_2 + 6);

  fVar1 = *(float *)(lVar6 + lVar8 * 0xc);

  uVar2 = *(undefined4 *)(lVar6 + 8 + lVar8 * 0xc);

  fVar3 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  lVar6 = *(longlong *)(param_2 + 8);

  fVar17 = *(float *)(lVar6 + lVar8 * 0xc);

  fVar18 = *(float *)(lVar6 + 4 + lVar8 * 0xc);

  fVar16 = *(float *)(lVar6 + 8 + lVar8 * 0xc);

  fVar9 = (float)FUN_1402cdc50(uVar2);

  fVar10 = (float)FUN_1402cfda0(uVar2);

  fVar11 = *(float *)(param_1 + 0x90) * DAT_14039ca54;

  fVar15 = *(float *)(lVar5 + 0x90);

  fVar12 = *param_2;

  fVar19 = fVar11 * fVar11 * fVar15 * fVar12;

  fVar15 = (fVar15 + fVar15) * *(float *)(param_1 + 0x94) * fVar11 + fVar19;

  if (fVar15 <= DAT_14039c9f0) {

    FID_conflict__assert

              (L"d + h * k > 1.192092896e-07F",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Joints\\b2MouseJoint.cpp",0x7d);

    fVar13 = *(float *)(param_1 + 0xc4);

    fVar14 = *(float *)(param_1 + 200);

  }

  fVar11 = DAT_14039ca44;

  fVar15 = fVar15 * fVar12;

  *(float *)(param_1 + 0xa8) = fVar15;

  if (fVar15 != 0.0) {

    fVar15 = fVar11 / fVar15;

    *(float *)(param_1 + 0xa8) = fVar15;

  }

  *(float *)(param_1 + 0x98) = fVar19 * fVar15;

  fVar19 = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0xbc);

  fVar12 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0xc0);

  fVar20 = fVar10 * fVar12 + fVar9 * fVar19;

  fVar10 = fVar10 * fVar19 - fVar9 * fVar12;

  *(float *)(param_1 + 0xb8) = fVar20;

  uVar7 = DAT_14039cac0;

  fVar12 = (float)((uint)fVar14 ^ DAT_14039cac0);

  *(float *)(param_1 + 0xb4) = fVar10;

  fVar12 = fVar12 * fVar10 * fVar20;

  fVar9 = fVar20 * fVar14 * fVar20 + fVar13 + fVar15;

  fVar15 = fVar14 * fVar10 * fVar10 + fVar13 + fVar15;

  fVar13 = fVar9 * fVar15 - fVar12 * fVar12;

  if (fVar13 != 0.0) {

    fVar13 = fVar11 / fVar13;

  }

  fVar12 = (float)((uint)fVar13 ^ uVar7) * fVar12;

  *(float *)(param_1 + 0xcc) = fVar15 * fVar13;

  *(float *)(param_1 + 0xd0) = fVar12;

  *(float *)(param_1 + 0xd4) = fVar12;

  *(float *)(param_1 + 0xd8) = fVar9 * fVar13;

  fVar16 = fVar16 * DAT_14039ca3c;

  *(float *)(param_1 + 0xdc) =

       ((fVar10 + fVar1) - *(float *)(param_1 + 0x88)) * *(float *)(param_1 + 0x98);

  *(float *)(param_1 + 0xe0) =

       *(float *)(param_1 + 0x98) * ((fVar3 + fVar20) - *(float *)(param_1 + 0x8c));

  if (*(char *)(param_2 + 5) == '\0') {

    *(undefined8 *)(param_1 + 0x9c) = 0;

  }

  else {

    fVar14 = param_2[2] * *(float *)(param_1 + 0xa0);

    fVar13 = param_2[2] * *(float *)(param_1 + 0x9c);

    *(float *)(param_1 + 0xa0) = fVar14;

    *(float *)(param_1 + 0x9c) = fVar13;

    fVar17 = fVar17 + fVar13 * *(float *)(param_1 + 0xc4);

    fVar18 = fVar18 + *(float *)(param_1 + 0xc4) * fVar14;

    fVar16 = fVar16 + (fVar14 * *(float *)(param_1 + 0xb4) - fVar13 * fVar20) *

                      *(float *)(param_1 + 200);

  }

  iVar4 = *(int *)(param_1 + 0xb0);

  lVar5 = *(longlong *)(param_2 + 8);

  *(float *)(lVar5 + (longlong)iVar4 * 0xc) = fVar17;

  *(float *)(lVar5 + 4 + (longlong)iVar4 * 0xc) = fVar18;

  *(float *)(*(longlong *)(param_2 + 8) + 8 + (longlong)*(int *)(param_1 + 0xb0) * 0xc) = fVar16;

  return;

}




