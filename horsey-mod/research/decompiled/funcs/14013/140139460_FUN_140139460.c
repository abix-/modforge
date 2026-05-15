// Address: 0x140139460
// Ghidra name: FUN_140139460
// ============ 0x140139460 FUN_140139460 (size=96) ============


void FUN_140139460(void)



{

  int iVar1;

  char *in_R9;

  

  if ((in_R9 != (char *)0x0) && (*in_R9 != '\0')) {

    iVar1 = thunk_FUN_1402d89dc(in_R9);

    if (-1 < iVar1) {

      iVar1 = thunk_FUN_1402d89dc(in_R9);

      if (3 < iVar1) {

        DAT_1403fbed0 = 3;

        return;

      }

      DAT_1403fbed0 = thunk_FUN_1402d89dc(in_R9);

      return;

    }

  }

  DAT_1403fbed0 = 0;

  return;

}




