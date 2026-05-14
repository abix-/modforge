// Address: 0x140146490
// Ghidra name: FUN_140146490
// ============ 0x140146490 FUN_140146490 (size=187) ============


byte FUN_140146490(longlong param_1,int param_2)



{

  char cVar1;

  byte bVar2;

  byte bVar3;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    bVar2 = FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return bVar2;

  }

  if (*(longlong *)(param_1 + 0x18) == 0) {

    return 1;

  }

  if (param_2 == 1) {

    bVar2 = FUN_140146210(param_1);

    return bVar2;

  }

  if (param_2 != 2) {

    if (param_2 != 3) {

      bVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140331efc);

      return bVar2;

    }

    bVar2 = FUN_140146210(param_1);

    bVar3 = FUN_140146380(param_1);

    return bVar3 & bVar2 & 1;

  }

  bVar2 = FUN_140146380(param_1);

  return bVar2;

}




