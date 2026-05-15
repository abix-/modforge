// Address: 0x14021ac90
// Ghidra name: FUN_14021ac90
// ============ 0x14021ac90 FUN_14021ac90 (size=48) ============


int FUN_14021ac90(void)



{

  longlong lVar1;

  int iVar2;

  

  iVar2 = 0;

  lVar1 = DAT_1403fdb58;

  while( true ) {

    if (lVar1 == 0) {

      return -1;

    }

    if (*(int *)(lVar1 + 0x46c) == 2) break;

    lVar1 = *(longlong *)(lVar1 + 0x490);

    iVar2 = iVar2 + 1;

  }

  return iVar2;

}




