// Address: 0x140007dd0
// Ghidra name: FUN_140007dd0
// ============ 0x140007dd0 FUN_140007dd0 (size=321) ============


void FUN_140007dd0(longlong param_1,longlong param_2,undefined8 param_3)



{

  float fVar1;

  longlong lVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  longlong lVar6;

  float *pfVar7;

  float fVar8;

  longlong lVar9;

  

  if (*(int *)(param_1 + 0x30) != 0) {

    FID_conflict__assert

              (L"m_proxyCount == 0",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2Fixture.cpp",0x7c);

  }

  iVar4 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();

  *(int *)(param_1 + 0x30) = iVar4;

  fVar3 = DAT_14039ca24;

  fVar8 = 0.0;

  if (0 < iVar4) {

    lVar9 = 0;

    do {

      pfVar7 = (float *)(*(longlong *)(param_1 + 0x28) + lVar9);

      (**(code **)(**(longlong **)(param_1 + 0x18) + 0x28))

                (*(longlong **)(param_1 + 0x18),pfVar7,param_3,fVar8);

      fVar5 = (float)FUN_1400153e0(param_2);

      fVar1 = pfVar7[1];

      lVar2 = *(longlong *)(param_2 + 8);

      lVar6 = (longlong)(int)fVar5;

      *(float *)(lVar2 + lVar6 * 0x28) = *pfVar7 - fVar3;

      *(float *)(lVar2 + 4 + lVar6 * 0x28) = fVar1 - fVar3;

      fVar1 = pfVar7[3];

      lVar2 = *(longlong *)(param_2 + 8);

      *(float *)(lVar2 + 8 + lVar6 * 0x28) = pfVar7[2] + fVar3;

      *(float *)(lVar2 + 0xc + lVar6 * 0x28) = fVar1 + fVar3;

      *(float **)(*(longlong *)(param_2 + 8) + 0x10 + lVar6 * 0x28) = pfVar7;

      *(undefined4 *)(*(longlong *)(param_2 + 8) + 0x24 + lVar6 * 0x28) = 0;

      FUN_1400155f0(param_2,fVar5);

      *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 1;

      FUN_1400125b0(param_2,fVar5);

      pfVar7[6] = fVar8;

      lVar9 = lVar9 + 0x20;

      fVar8 = (float)((int)fVar8 + 1);

      pfVar7[7] = fVar5;

      *(longlong *)(pfVar7 + 4) = param_1;

    } while ((int)fVar8 < *(int *)(param_1 + 0x30));

  }

  return;

}




