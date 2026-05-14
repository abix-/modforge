// Address: 0x140174280
// Ghidra name: FUN_140174280
// ============ 0x140174280 FUN_140174280 (size=178) ============


ulonglong FUN_140174280(void)



{

  int iVar1;

  char *pcVar2;

  byte bVar3;

  

  if (*(char *)((longlong)DAT_1403fc410 + 0x319) != '\0') {

    return (ulonglong)DAT_1403fc410 & 0xffffffffffffff00;

  }

  pcVar2 = (char *)FUN_140142960("SDL_FRAMEBUFFER_ACCELERATION");

  bVar3 = 1;

  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {

    if (*pcVar2 != '0') {

      iVar1 = FUN_14012ef60(pcVar2,"false");

      if (iVar1 != 0) {

        iVar1 = FUN_14012ef60(pcVar2,"software");

        if (iVar1 != 0) goto LAB_140174324;

      }

    }

    return 0;

  }

  if (DAT_1403fc410[0x27] != 0) {

    iVar1 = strcmp((char *)*DAT_1403fc410,"windows");

    bVar3 = 1;

    if (iVar1 == 0) {

      bVar3 = 0;

    }

  }

LAB_140174324:

  return (ulonglong)bVar3;

}




