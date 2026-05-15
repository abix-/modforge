// Address: 0x14018b130
// Ghidra name: FUN_14018b130
// ============ 0x14018b130 FUN_14018b130 (size=65) ============


void FUN_14018b130(void)



{

  char cVar1;

  int iVar2;

  

  iVar2 = 0;

  cVar1 = FUN_14018b180();

  while (cVar1 == '\0') {

    if (iVar2 < 0x20) {

      iVar2 = iVar2 + 1;

    }

    else {

      FUN_1401492f0(0);

    }

    cVar1 = FUN_14018b180();

  }

  return;

}




