// Address: 0x14020fb30
// Ghidra name: FUN_14020fb30
// ============ 0x14020fb30 FUN_14020fb30 (size=83) ============


undefined8 FUN_14020fb30(longlong param_1,ushort param_2,ushort param_3)



{

  undefined8 *puVar1;

  

  puVar1 = *(undefined8 **)(param_1 + 0x148);

  *(float *)((longlong)puVar1 + 0xc) = (float)param_2 / DAT_14030ec38;

  *(float *)(puVar1 + 2) = (float)param_3 / DAT_14030ec38;

  (**(code **)(**(longlong **)*puVar1 + 0x50))(*(longlong **)*puVar1,(longlong)puVar1 + 0xc);

  return 1;

}




