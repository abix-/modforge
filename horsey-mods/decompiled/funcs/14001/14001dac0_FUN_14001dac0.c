// Address: 0x14001dac0
// Ghidra name: FUN_14001dac0
// ============ 0x14001dac0 FUN_14001dac0 (size=290) ============


undefined8 *

FUN_14001dac0(longlong param_1,undefined4 param_2,longlong param_3,undefined4 param_4,

             undefined8 param_5)



{

  undefined8 *puVar1;

  float fVar2;

  

  puVar1 = (undefined8 *)FUN_140012630(param_5,200);

  *puVar1 = b2Contact::vftable;

  *(undefined8 *)((longlong)puVar1 + 0xb4) = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[7] = 0;

  puVar1[4] = 0;

  puVar1[9] = 0;

  puVar1[10] = 0;

  puVar1[0xb] = 0;

  puVar1[8] = 0;

  *(undefined4 *)(puVar1 + 1) = 4;

  puVar1[0xc] = param_1;

  puVar1[0xd] = param_3;

  *(undefined4 *)(puVar1 + 0xe) = param_2;

  *(undefined4 *)((longlong)puVar1 + 0x74) = param_4;

  fVar2 = *(float *)(param_1 + 0x20);

  if (*(float *)(param_3 + 0x20) <= *(float *)(param_1 + 0x20)) {

    fVar2 = *(float *)(param_3 + 0x20);

  }

  *(float *)(puVar1 + 0x18) = fVar2;

  fVar2 = *(float *)(param_1 + 0x24);

  if (*(float *)(param_1 + 0x24) <= *(float *)(param_3 + 0x24)) {

    fVar2 = *(float *)(param_3 + 0x24);

  }

  *puVar1 = b2ChainAndCircleContact::vftable;

  *(float *)((longlong)puVar1 + 0xc4) = fVar2;

  if (*(int *)(*(longlong *)(param_1 + 0x18) + 8) != 3) {

    FID_conflict__assert

              (L"m_fixtureA->GetType() == b2Shape::e_chain",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Contacts\\b2ChainAndCircleContact.cpp",0x2b);

  }

  if (*(int *)(*(longlong *)(puVar1[0xd] + 0x18) + 8) != 0) {

    FID_conflict__assert

              (L"m_fixtureB->GetType() == b2Shape::e_circle",

               L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\Contacts\\b2ChainAndCircleContact.cpp",0x2c);

  }

  return puVar1;

}




