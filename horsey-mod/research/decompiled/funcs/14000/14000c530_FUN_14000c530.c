// Address: 0x14000c530
// Ghidra name: FUN_14000c530
// ============ 0x14000c530 FUN_14000c530 (size=73) ============


void FUN_14000c530(longlong param_1,undefined8 param_2)



{

  undefined8 *puVar1;

  

  puVar1 = (undefined8 *)FUN_140012630(param_2,0x18);

  *puVar1 = b2CircleShape::vftable;

  puVar1[1] = 0;

  puVar1[2] = 0;

  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_1 + 8);

  *(undefined4 *)((longlong)puVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);

  puVar1[2] = *(undefined8 *)(param_1 + 0x10);

  return;

}




