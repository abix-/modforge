// Address: 0x1401426c0
// Ghidra name: FUN_1401426c0
// ============ 0x1401426c0 FUN_1401426c0 (size=89) ============


ulonglong FUN_1401426c0(char param_1)



{

  char cVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = FUN_140138fe0(&DAT_1403fbf40);

  if (((int)uVar3 == 0) && (param_1 != '\0')) {

    uVar2 = FUN_1401746e0();

    uVar3 = (ulonglong)uVar2;

    cVar1 = FUN_140138fc0(&DAT_1403fbf40,0,uVar2);

    if (cVar1 == '\0') {

      FUN_1401747e0(uVar3);

      uVar3 = FUN_140138fe0(&DAT_1403fbf40);

      return uVar3;

    }

  }

  return uVar3;

}




