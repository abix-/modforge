// Address: 0x1401ca4b0
// Ghidra name: FUN_1401ca4b0
// ============ 0x1401ca4b0 FUN_1401ca4b0 (size=50) ============


bool FUN_1401ca4b0(void *param_1,ulonglong param_2)



{

  int iVar1;

  

  if ((3 < param_2) && (param_1 != (void *)0x0)) {

    iVar1 = memcmp(param_1,&DAT_1403494ac,4);

    return iVar1 == 0;

  }

  return false;

}




