// Address: 0x1401aa810
// Ghidra name: FUN_1401aa810
// ============ 0x1401aa810 FUN_1401aa810 (size=50) ============


int FUN_1401aa810(void)



{

  int iVar1;

  

  iVar1 = FUN_140138fb0(&DAT_1403fcd90,1);

  iVar1 = iVar1 + 1;

  if (iVar1 == 0) {

    iVar1 = FUN_140138fb0(&DAT_1403fcd90,1);

    iVar1 = iVar1 + 1;

  }

  return iVar1;

}




