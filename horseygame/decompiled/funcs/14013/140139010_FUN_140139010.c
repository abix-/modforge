// Address: 0x140139010
// Ghidra name: FUN_140139010
// ============ 0x140139010 FUN_140139010 (size=5) ============


undefined4 FUN_140139010(undefined4 *param_1,undefined4 param_2)



{

  undefined4 uVar1;

  

  LOCK();

  uVar1 = *param_1;

  *param_1 = param_2;

  UNLOCK();

  return uVar1;

}




