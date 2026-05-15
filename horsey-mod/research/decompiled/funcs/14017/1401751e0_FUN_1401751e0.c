// Address: 0x1401751e0
// Ghidra name: FUN_1401751e0
// ============ 0x1401751e0 FUN_1401751e0 (size=150) ============


void FUN_1401751e0(void)



{

  undefined8 uVar1;

  char cVar2;

  int iVar3;

  

  cVar2 = FUN_140163cb0(&DAT_1403fc438);

  if (cVar2 == '\0') {

    return;

  }

  do {

    iVar3 = FUN_140138fe0(&DAT_1403fc45c);

    cVar2 = FUN_140138fc0(&DAT_1403fc45c,iVar3,0);

  } while (cVar2 == '\0');

  if (iVar3 != 0) {

    FUN_1401747e0(iVar3);

  }

  uVar1 = DAT_1403fc450;

  DAT_1403fc450 = 0;

  FUN_1401ab210(uVar1,FUN_1401745b0,0);

  FUN_1401aafa0(uVar1);

  FUN_140163ab0(&DAT_1403fc438,0);

  return;

}




