// Address: 0x140010010
// Ghidra name: FUN_140010010
// ============ 0x140010010 FUN_140010010 (size=301) ============


void FUN_140010010(longlong param_1,undefined8 *param_2,undefined8 param_3)



{

  longlong lVar1;

  longlong lVar2;

  undefined4 uVar3;

  float fVar4;

  float fVar5;

  

  if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {

    FID_conflict__assert

              (L"m_world->IsLocked() == false",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2Body.cpp",0x1ad

              );

  }

  if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) == 0) {

    uVar3 = FUN_1402cdc50(param_3);

    *(undefined4 *)(param_1 + 0x14) = uVar3;

    uVar3 = FUN_1402cfda0(param_3);

    *(undefined4 *)(param_1 + 0x18) = uVar3;

    lVar2 = *(longlong *)(param_1 + 0x70);

    lVar1 = *(longlong *)(param_1 + 0x58);

    *(undefined8 *)(param_1 + 0xc) = *param_2;

    fVar4 = (*(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x1c) -

            *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x20)) + *(float *)(param_1 + 0xc);

    fVar5 = *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x14) +

            *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x10);

    *(int *)(param_1 + 0x38) = (int)param_3;

    *(int *)(param_1 + 0x34) = (int)param_3;

    *(float *)(param_1 + 0x2c) = fVar4;

    *(float *)(param_1 + 0x24) = fVar4;

    *(float *)(param_1 + 0x30) = fVar5;

    *(float *)(param_1 + 0x28) = fVar5;

    for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 8)) {

      FUN_140008030(lVar2,lVar1 + 0x192a0,param_1 + 0xc,param_1 + 0xc);

    }

    lVar2 = *(longlong *)(param_1 + 0x58) + 0x192a0;

    FUN_1400117d0(lVar2,lVar2);

  }

  return;

}




