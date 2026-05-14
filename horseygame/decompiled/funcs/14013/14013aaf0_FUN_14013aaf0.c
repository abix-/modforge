// Address: 0x14013aaf0
// Ghidra name: FUN_14013aaf0
// ============ 0x14013aaf0 FUN_14013aaf0 (size=122) ============


longlong FUN_14013aaf0(char param_1)



{

  char cVar1;

  longlong lVar2;

  

  lVar2 = FUN_1401638b0(&DAT_1403fb69c);

  if (lVar2 != 0) {

    return lVar2;

  }

  if ((param_1 != '\0') && (lVar2 = FUN_1401841a0(1,0x10), lVar2 != 0)) {

    cVar1 = FUN_140163ac0(&DAT_1403fb69c,lVar2,FUN_140139240);

    if (cVar1 != '\0') {

      return lVar2;

    }

    FUN_1401841e0(lVar2);

  }

  return 0;

}




