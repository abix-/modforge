// Address: 0x1402fff5d
// Ghidra name: FUN_1402fff5d
// ============ 0x1402fff5d FUN_1402fff5d (size=44) ============


undefined4 FUN_1402fff5d(undefined8 *param_1,longlong param_2)



{

  int iVar1;

  

  *(undefined8 **)(param_2 + 0x28) = param_1;

  iVar1 = *(int *)*param_1;

  *(int *)(param_2 + 0x24) = iVar1;

  *(uint *)(param_2 + 0x20) = (uint)(iVar1 == -0x1f928c9d);

  return *(undefined4 *)(param_2 + 0x20);

}




