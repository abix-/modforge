// Address: 0x1402e8080
// Ghidra name: FUN_1402e8080
// ============ 0x1402e8080 FUN_1402e8080 (size=12) ============


undefined4 FUN_1402e8080(void)



{

  undefined4 uVar1;

  

  uVar1 = DAT_1403ff13c;

  LOCK();

  DAT_1403ff13c = 1;

  UNLOCK();

  return uVar1;

}




