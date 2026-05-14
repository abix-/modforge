// Address: 0x14000c910
// Ghidra name: FUN_14000c910
// ============ 0x14000c910 FUN_14000c910 (size=133) ============


undefined8 * FUN_14000c910(longlong param_1,undefined8 param_2)



{

  undefined8 *puVar1;

  

  puVar1 = (undefined8 *)FUN_140012630(param_2,0x38);

  *puVar1 = b2EdgeShape::vftable;

  *(undefined4 *)(puVar1 + 1) = 1;

  *(undefined4 *)((longlong)puVar1 + 0xc) = 0x3c23d70a;

  *(undefined2 *)(puVar1 + 6) = 0;

  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_1 + 8);

  *(undefined4 *)((longlong)puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);

  puVar1[2] = *(undefined8 *)(param_1 + 0x10);

  puVar1[3] = *(undefined8 *)(param_1 + 0x18);

  puVar1[4] = *(undefined8 *)(param_1 + 0x20);

  puVar1[5] = *(undefined8 *)(param_1 + 0x28);

  *(undefined1 *)(puVar1 + 6) = *(undefined1 *)(param_1 + 0x30);

  *(undefined1 *)((longlong)puVar1 + 0x31) = *(undefined1 *)(param_1 + 0x31);

  return puVar1;

}




