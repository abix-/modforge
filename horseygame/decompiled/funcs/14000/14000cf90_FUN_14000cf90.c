// Address: 0x14000cf90
// Ghidra name: FUN_14000cf90
// ============ 0x14000cf90 FUN_14000cf90 (size=221) ============


undefined8 * FUN_14000cf90(longlong param_1,undefined8 param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  

  puVar3 = (undefined8 *)FUN_140012630(param_2,0x30);

  *puVar3 = b2ChainShape::vftable;

  puVar3[2] = 0;

  *(undefined4 *)(puVar3 + 3) = 0;

  *(undefined2 *)((longlong)puVar3 + 0x2c) = 0;

  *(undefined4 *)(puVar3 + 1) = 3;

  *(undefined4 *)((longlong)puVar3 + 0xc) = 0x3c23d70a;

  iVar1 = *(int *)(param_1 + 0x18);

  uVar2 = *(undefined8 *)(param_1 + 0x10);

  if (iVar1 < 2) {

    FID_conflict__assert

              (L"count >= 2",L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.cpp",0x31);

  }

  *(int *)(puVar3 + 3) = iVar1;

  uVar4 = _malloc_base((longlong)(iVar1 * 8));

  puVar3[2] = uVar4;

  FUN_1402f8e20(uVar4,uVar2,(longlong)*(int *)(puVar3 + 3) << 3);

  *(undefined2 *)((longlong)puVar3 + 0x2c) = 0;

  *(undefined8 *)((longlong)puVar3 + 0x1c) = *(undefined8 *)(param_1 + 0x1c);

  *(undefined8 *)((longlong)puVar3 + 0x24) = *(undefined8 *)(param_1 + 0x24);

  *(undefined1 *)((longlong)puVar3 + 0x2c) = *(undefined1 *)(param_1 + 0x2c);

  *(undefined1 *)((longlong)puVar3 + 0x2d) = *(undefined1 *)(param_1 + 0x2d);

  return puVar3;

}




