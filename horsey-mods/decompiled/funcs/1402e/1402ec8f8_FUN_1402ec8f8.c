// Address: 0x1402ec8f8
// Ghidra name: FUN_1402ec8f8
// ============ 0x1402ec8f8 FUN_1402ec8f8 (size=63) ============


void FUN_1402ec8f8(void)



{

  char cVar1;

  int local_res8 [8];

  

  if (DAT_1403ff628 == 0) {

    local_res8[0] = 0;

    cVar1 = FUN_1402f0e08();

    if (cVar1 == '\0') {

      FUN_1402ec294(local_res8);

    }

    DAT_1403ff628 = (local_res8[0] == 1) + 1;

    LOCK();

    UNLOCK();

  }

  return;

}




