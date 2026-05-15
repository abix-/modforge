// Address: 0x14000d3c0
// Ghidra name: FUN_14000d3c0
// ============ 0x14000d3c0 FUN_14000d3c0 (size=285) ============


undefined8 * FUN_14000d3c0(longlong param_1,undefined8 param_2)



{

  undefined8 *puVar1;

  

  puVar1 = (undefined8 *)FUN_140012630(param_2,0xa0);

  *puVar1 = b2PolygonShape::vftable;

  *(undefined4 *)(puVar1 + 0x13) = 0;

  *(undefined4 *)((longlong)puVar1 + 0x14) = 0;

  *(undefined4 *)(puVar1 + 1) = 2;

  *(undefined8 *)((longlong)puVar1 + 0xc) = 0x3c23d70a;

  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_1 + 8);

  *(undefined4 *)((longlong)puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);

  puVar1[2] = *(undefined8 *)(param_1 + 0x10);

  puVar1[3] = *(undefined8 *)(param_1 + 0x18);

  puVar1[4] = *(undefined8 *)(param_1 + 0x20);

  puVar1[5] = *(undefined8 *)(param_1 + 0x28);

  puVar1[6] = *(undefined8 *)(param_1 + 0x30);

  puVar1[7] = *(undefined8 *)(param_1 + 0x38);

  puVar1[8] = *(undefined8 *)(param_1 + 0x40);

  puVar1[9] = *(undefined8 *)(param_1 + 0x48);

  puVar1[10] = *(undefined8 *)(param_1 + 0x50);

  puVar1[0xb] = *(undefined8 *)(param_1 + 0x58);

  puVar1[0xc] = *(undefined8 *)(param_1 + 0x60);

  puVar1[0xd] = *(undefined8 *)(param_1 + 0x68);

  puVar1[0xe] = *(undefined8 *)(param_1 + 0x70);

  puVar1[0xf] = *(undefined8 *)(param_1 + 0x78);

  puVar1[0x10] = *(undefined8 *)(param_1 + 0x80);

  puVar1[0x11] = *(undefined8 *)(param_1 + 0x88);

  puVar1[0x12] = *(undefined8 *)(param_1 + 0x90);

  *(undefined4 *)(puVar1 + 0x13) = *(undefined4 *)(param_1 + 0x98);

  return puVar1;

}




