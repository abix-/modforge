// Address: 0x14016f910
// Ghidra name: FUN_14016f910
// ============ 0x14016f910 FUN_14016f910 (size=22) ============


void FUN_14016f910(longlong param_1)



{

  *(ulonglong *)(param_1 + 0x50) =

       *(ulonglong *)(param_1 + 0x50) | (ulonglong)(*(uint *)(param_1 + 0x48) & 0x81);

  FUN_140173190(param_1,0,0);

  return;

}




