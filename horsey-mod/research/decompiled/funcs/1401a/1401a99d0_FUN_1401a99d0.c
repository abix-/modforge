// Address: 0x1401a99d0
// Ghidra name: FUN_1401a99d0
// ============ 0x1401a99d0 FUN_1401a99d0 (size=89) ============


undefined4 FUN_1401a99d0(void)



{

  int iVar1;

  

  if (DAT_1403fcd6d != '\0') {

    return DAT_1403fcd7c;

  }

  iVar1 = FUN_1401a9990();

  if ((iVar1 == 0) && (iVar1 = FUN_1401925a0(5,1,0), iVar1 != 0)) {

    DAT_1403fcd6d = 1;

    DAT_1403fcd7c = 1;

    return 1;

  }

  DAT_1403fcd7c = 0;

  DAT_1403fcd6d = 1;

  return 0;

}




