// Address: 0x140007ca0
// Ghidra name: FUN_140007ca0
// ============ 0x140007ca0 FUN_140007ca0 (size=302) ============


void FUN_140007ca0(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  int iVar2;

  ulonglong uVar3;

  

  if (*(int *)(param_1 + 0x30) != 0) {

    FID_conflict__assert

              (L"m_proxyCount == 0",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2Fixture.cpp",0x48);

  }

  iVar2 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();

  FUN_140012800(param_2,*(undefined8 *)(param_1 + 0x28),iVar2 << 5);

  puVar1 = *(undefined8 **)(param_1 + 0x18);

  *(undefined8 *)(param_1 + 0x28) = 0;

  iVar2 = *(int *)(puVar1 + 1);

  if (iVar2 == 0) {

    (**(code **)*puVar1)(puVar1,0);

    uVar3 = (ulonglong)DAT_1403ff958;

  }

  else if (iVar2 == 1) {

    (**(code **)*puVar1)(puVar1,0);

    uVar3 = (ulonglong)DAT_1403ff978;

  }

  else if (iVar2 == 2) {

    (**(code **)*puVar1)(puVar1,0);

    uVar3 = (ulonglong)DAT_1403ff9e0;

  }

  else {

    if (iVar2 != 3) {

      FID_conflict__assert(L"false",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2Fixture.cpp",0x73);

      goto LAB_140007daf;

    }

    (**(code **)*puVar1)(puVar1,0);

    uVar3 = (ulonglong)DAT_1403ff970;

  }

  if (0xd < (uint)uVar3) {

    FID_conflict__assert

              (L"0 <= index && index < b2_blockSizes",

               L"C:\\dev\\Box2d2\\Box2D\\Common\\b2BlockAllocator.cpp",0xad);

  }

  *puVar1 = *(undefined8 *)(param_2 + 0x10 + uVar3 * 8);

  *(undefined8 **)(param_2 + uVar3 * 8 + 0x10) = puVar1;

LAB_140007daf:

  *(undefined8 *)(param_1 + 0x18) = 0;

  return;

}




