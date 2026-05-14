// Address: 0x140005e10
// Ghidra name: FUN_140005e10
// ============ 0x140005e10 FUN_140005e10 (size=158) ============


longlong FUN_140005e10(longlong param_1,undefined8 param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  

  if ((*(byte *)(param_1 + 0x19298) & 2) != 0) {

    FID_conflict__assert

              (L"IsLocked() == false",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2World.cpp",0x6d);

  }

  if ((*(byte *)(param_1 + 0x19298) & 2) != 0) {

    return 0;

  }

  uVar1 = FUN_140012630(param_1,0xb8);

  lVar2 = FUN_14000f8d0(uVar1,param_2,param_1);

  *(undefined8 *)(lVar2 + 0x60) = 0;

  *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(param_1 + 0x19320);

  if (*(longlong *)(param_1 + 0x19320) != 0) {

    *(longlong *)(*(longlong *)(param_1 + 0x19320) + 0x60) = lVar2;

  }

  *(int *)(param_1 + 0x19330) = *(int *)(param_1 + 0x19330) + 1;

  *(longlong *)(param_1 + 0x19320) = lVar2;

  return lVar2;

}




