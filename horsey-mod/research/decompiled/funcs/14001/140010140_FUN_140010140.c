// Address: 0x140010140
// Ghidra name: FUN_140010140
// ============ 0x140010140 FUN_140010140 (size=248) ============


void FUN_140010140(longlong param_1,undefined8 *param_2)



{

  longlong lVar1;

  longlong lVar2;

  float fVar3;

  float fVar4;

  

  if ((*(byte *)(*(longlong *)(param_1 + 0x58) + 0x19298) & 2) != 0) {

    FID_conflict__assert

              (L"m_world->IsLocked() == false",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2Body.cpp",0x1c7

              );

  }

  lVar2 = *(longlong *)(param_1 + 0x58);

  if ((*(byte *)(lVar2 + 0x19298) & 2) == 0) {

    lVar1 = *(longlong *)(param_1 + 0x70);

    *(undefined8 *)(param_1 + 0xc) = *param_2;

    fVar3 = (*(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x1c) -

            *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x20)) + *(float *)(param_1 + 0xc);

    fVar4 = *(float *)(param_1 + 0x1c) * *(float *)(param_1 + 0x14) +

            *(float *)(param_1 + 0x18) * *(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x10);

    *(float *)(param_1 + 0x2c) = fVar3;

    *(float *)(param_1 + 0x24) = fVar3;

    *(float *)(param_1 + 0x30) = fVar4;

    *(float *)(param_1 + 0x28) = fVar4;

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {

      FUN_140008030(lVar1,lVar2 + 0x192a0,param_1 + 0xc,param_1 + 0xc);

    }

    lVar2 = *(longlong *)(param_1 + 0x58) + 0x192a0;

    FUN_1400117d0(lVar2,lVar2);

  }

  return;

}




