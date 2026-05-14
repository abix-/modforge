// Address: 0x1402ec938
// Ghidra name: FUN_1402ec938
// ============ 0x1402ec938 FUN_1402ec938 (size=67) ============


void FUN_1402ec938(void)



{

  char cVar1;

  int local_res8 [8];

  

  if (DAT_1403ff62c == 0) {

    local_res8[0] = 1;

    cVar1 = FUN_1402f0e08();

    if (cVar1 == '\0') {

      FUN_1402ec238(local_res8);

    }

    DAT_1403ff62c = (local_res8[0] == 1) + 1;

    LOCK();

    UNLOCK();

  }

  return;

}




