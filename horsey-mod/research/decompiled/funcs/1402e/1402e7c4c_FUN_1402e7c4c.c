// Address: 0x1402e7c4c
// Ghidra name: FUN_1402e7c4c
// ============ 0x1402e7c4c FUN_1402e7c4c (size=64) ============


undefined8 FUN_1402e7c4c(void)



{

  int iVar1;

  

  LOCK();

  iVar1 = *DAT_1403ff760;

  *DAT_1403ff760 = *DAT_1403ff760 + -1;

  UNLOCK();

  if ((iVar1 == 1) && (DAT_1403ff760 != (int *)&DAT_1403e91a0)) {

    FUN_1402e9a80();

    DAT_1403ff760 = (int *)&DAT_1403e91a0;

  }

  return 1;

}




