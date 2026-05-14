// Address: 0x1401324e0
// Ghidra name: FUN_1401324e0
// ============ 0x1401324e0 FUN_1401324e0 (size=99) ============


void FUN_1401324e0(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  iVar2 = FUN_140138fb0(param_1 + 0x14,0xffffffff);

  if (iVar2 == 1) {

    FUN_14017cab0(DAT_1403fb628);

    cVar1 = FUN_1401ab340(DAT_1403fb630,*(undefined4 *)(param_1 + 0x6c));

    if (cVar1 != '\0') {

      FUN_140138fb0(&DAT_1403fb650,0xffffffff);

    }

    FUN_14017cae0(DAT_1403fb628);

    return;

  }

  return;

}




