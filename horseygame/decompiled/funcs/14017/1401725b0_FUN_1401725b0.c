// Address: 0x1401725b0
// Ghidra name: FUN_1401725b0
// ============ 0x1401725b0 FUN_1401725b0 (size=122) ============


undefined4 FUN_1401725b0(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  char *pcVar4;

  

  if (((*(byte *)(param_1 + 0x48) & 1) != 0) && (*(char *)(param_1 + 0x10f) == '\0')) {

    pcVar4 = (char *)FUN_140142960("SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS");

    if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {

      iVar2 = FUN_14012ef60(pcVar4,&DAT_1403350d4);

      if (iVar2 != 0) {

        uVar3 = FUN_140142940("SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS",0);

        return uVar3;

      }

    }

    if (*(char *)(param_1 + 0x5d) != '\0') {

      cVar1 = FUN_14016f5c0(DAT_1403fc410);

      if (cVar1 == '\0') {

        return 1;

      }

    }

  }

  return 0;

}




