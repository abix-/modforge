// Address: 0x14021a9a0
// Ghidra name: FUN_14021a9a0
// ============ 0x14021a9a0 FUN_14021a9a0 (size=108) ============


ulonglong FUN_14021a9a0(char param_1)



{

  char cVar1;

  uint uVar2;

  ulonglong uVar3;

  

  if (param_1 != '\0') {

    FUN_14013b130();

  }

  FUN_14021a810();

  uVar3 = FUN_140138fe0(&DAT_1403fdb48);

  if ((int)uVar3 == 0) {

    uVar2 = (*DAT_1403fdb38)(DAT_1403fdb50);

    uVar3 = (ulonglong)uVar2;

    cVar1 = FUN_140138fc0(&DAT_1403fdb48,0,uVar2);

    if (cVar1 == '\0') {

      uVar3 = FUN_140138fe0(&DAT_1403fdb48);

      return uVar3;

    }

  }

  return uVar3;

}




