// Address: 0x1401538c0
// Ghidra name: FUN_1401538c0
// ============ 0x1401538c0 FUN_1401538c0 (size=39) ============


undefined4 FUN_1401538c0(longlong param_1)



{

  int iVar1;

  

  if (*(longlong *)(param_1 + 0x1f0) != 0) {

    iVar1 = *(int *)(*(longlong *)(param_1 + 0x1f0) + 0x18);

    return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 0x12000500);

  }

  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x208) >> 8),

                  *(int *)(param_1 + 0x208) == 0x12000500);

}




