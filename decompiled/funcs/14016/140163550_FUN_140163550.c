// Address: 0x140163550
// Ghidra name: FUN_140163550
// ============ 0x140163550 FUN_140163550 (size=102) ============


void FUN_140163550(longlong param_1)



{

  char cVar1;

  int iVar2;

  

  cVar1 = FUN_140163df0();

  if (cVar1 != '\0') {

    cVar1 = FUN_140138fc0(param_1 + 0x14,1,2);

    if (cVar1 != '\0') {

      FUN_1401aa9d0(param_1,10,0);

      FUN_140180050(param_1);

      return;

    }

    iVar2 = FUN_1401639a0(param_1);

    if (iVar2 == 3) {

      FUN_140163d80(param_1,0);

      return;

    }

  }

  return;

}




