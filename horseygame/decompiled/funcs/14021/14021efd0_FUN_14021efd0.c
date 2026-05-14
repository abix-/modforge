// Address: 0x14021efd0
// Ghidra name: FUN_14021efd0
// ============ 0x14021efd0 FUN_14021efd0 (size=149) ============


void FUN_14021efd0(undefined8 param_1)



{

  longlong lVar1;

  char cVar2;

  longlong *plVar3;

  ulonglong uVar4;

  int iVar5;

  ulonglong uVar6;

  

  FUN_1401aa9d0(param_1,0xb,0);

  DAT_1403fdba0 = DAT_1403fdba0 + -1;

  if ((0 < DAT_1403fdba0) ||

     (cVar2 = FUN_140142940("SDL_QUIT_ON_LAST_WINDOW_CLOSE",1), cVar2 == '\0')) {

    return;

  }

  uVar4 = 0;

  iVar5 = 0;

  plVar3 = (longlong *)FUN_14016f010(0);

  if (plVar3 != (longlong *)0x0) {

    uVar6 = uVar4;

    for (lVar1 = *plVar3; lVar1 != 0; lVar1 = plVar3[lVar1]) {

      if ((*(longlong *)(lVar1 + 0x1a8) == 0) && ((*(byte *)(lVar1 + 0x48) & 8) == 0)) {

        uVar6 = (ulonglong)((int)uVar6 + 1);

      }

      iVar5 = (int)uVar6;

      lVar1 = uVar4 + 1;

      uVar4 = uVar4 + 1;

    }

    FUN_1401841e0();

    if (iVar5 != 0) {

      return;

    }

  }

  FUN_1401ce0e0();

  return;

}




