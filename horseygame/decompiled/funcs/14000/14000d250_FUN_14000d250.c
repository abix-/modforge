// Address: 0x14000d250
// Ghidra name: FUN_14000d250
// ============ 0x14000d250 FUN_14000d250 (size=304) ============


void FUN_14000d250(longlong param_1,float *param_2,float *param_3,int param_4)



{

  float fVar1;

  float fVar2;

  longlong lVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  if (*(int *)(param_1 + 0x18) <= param_4) {

    FID_conflict__assert

              (L"childIndex < m_count",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.cpp",0x94);

  }

  fVar9 = param_3[2];

  fVar5 = param_3[3];

  lVar3 = *(longlong *)(param_1 + 0x10);

  iVar4 = 0;

  if (param_4 + 1 != *(int *)(param_1 + 0x18)) {

    iVar4 = param_4 + 1;

  }

  fVar7 = *(float *)(lVar3 + 4 + (longlong)param_4 * 8);

  fVar6 = *(float *)(lVar3 + (longlong)param_4 * 8);

  fVar1 = *(float *)(lVar3 + 4 + (longlong)iVar4 * 8);

  fVar2 = *(float *)(lVar3 + (longlong)iVar4 * 8);

  fVar8 = fVar7 * fVar5 + fVar6 * fVar9 + param_3[1];

  fVar7 = (fVar6 * fVar5 - fVar7 * fVar9) + *param_3;

  fVar6 = fVar1 * fVar5 + fVar2 * fVar9 + param_3[1];

  fVar5 = (fVar2 * fVar5 - fVar1 * fVar9) + *param_3;

  fVar9 = fVar8;

  if (fVar8 <= fVar6) {

    fVar9 = fVar6;

  }

  if (fVar6 <= fVar8) {

    fVar8 = fVar6;

  }

  fVar6 = fVar7;

  if (fVar7 <= fVar5) {

    fVar6 = fVar5;

  }

  param_2[3] = fVar9;

  if (fVar5 <= fVar7) {

    fVar7 = fVar5;

  }

  param_2[1] = fVar8;

  param_2[2] = fVar6;

  *param_2 = fVar7;

  return;

}




