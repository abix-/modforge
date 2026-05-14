// Address: 0x14018b180
// Ghidra name: FUN_14018b180
// ============ 0x14018b180 FUN_14018b180 (size=13) ============


undefined4 FUN_14018b180(int *param_1)



{

  int iVar1;

  

  LOCK();

  iVar1 = *param_1;

  *param_1 = 1;

  UNLOCK();

  return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 0);

}




