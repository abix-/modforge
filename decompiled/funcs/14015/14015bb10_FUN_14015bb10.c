// Address: 0x14015bb10
// Ghidra name: FUN_14015bb10
// ============ 0x14015bb10 FUN_14015bb10 (size=131) ============


void FUN_14015bb10(void)



{

  undefined8 uVar1;

  int iVar2;

  

  DAT_1403fc064 = DAT_1403fc064 + -1;

  if ((DAT_1403fc068 == '\0') && (DAT_1403fc064 == 0)) {

    iVar2 = FUN_140138fe0(&DAT_1403fc060);

    uVar1 = DAT_1403fc058;

    if (iVar2 == 0) {

      FUN_140179b40(DAT_1403fc058);

      FUN_140179b60(DAT_1403fc058);

      DAT_1403fc058 = 0;

      FUN_140179b60(uVar1);

      FUN_140179b30(uVar1);

      return;

    }

  }

  FUN_140179b60(DAT_1403fc058);

  return;

}




