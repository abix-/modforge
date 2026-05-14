// Address: 0x140174be0
// Ghidra name: FUN_140174be0
// ============ 0x140174be0 FUN_140174be0 (size=93) ============


ulonglong FUN_140174be0(void)



{

  char cVar1;

  uint uVar2;

  ulonglong uVar3;

  

  uVar3 = FUN_140138fe0(&DAT_1403fc45c);

  if ((int)uVar3 == 0) {

    uVar2 = FUN_1401746e0();

    uVar3 = (ulonglong)uVar2;

    cVar1 = FUN_140138fc0(&DAT_1403fc45c,0,uVar2);

    if (cVar1 == '\0') {

      FUN_1401747e0(uVar3);

      uVar3 = FUN_140138fe0(&DAT_1403fc45c);

      return uVar3;

    }

  }

  return uVar3;

}




