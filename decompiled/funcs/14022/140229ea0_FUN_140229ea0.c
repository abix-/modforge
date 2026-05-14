// Address: 0x140229ea0
// Ghidra name: FUN_140229ea0
// ============ 0x140229ea0 FUN_140229ea0 (size=173) ============


uint FUN_140229ea0(longlong param_1)



{

  ulonglong uVar1;

  char cVar2;

  uint uVar3;

  

  uVar1 = *(ulonglong *)(param_1 + 0x48);

  if ((uVar1 & 0xc0000) != 0) {

    return 0x80000000;

  }

  if ((uVar1 & 1) == 0) {

    if ((uVar1 & 0x10) == 0) {

      uVar3 = 0xca0000;

    }

    else {

      cVar2 = FUN_140142940("SDL_BORDERLESS_WINDOWED_STYLE",1);

      uVar3 = 0x80ca0000;

      if (cVar2 == '\0') {

        uVar3 = 0x80020000;

      }

    }

    if (((*(ulonglong *)(param_1 + 0x48) & 0x20) != 0) &&

       (((*(ulonglong *)(param_1 + 0x48) & 0x10) == 0 ||

        (cVar2 = FUN_140142940("SDL_BORDERLESS_RESIZABLE_STYLE",1), cVar2 != '\0')))) {

      uVar3 = uVar3 | 0x50000;

    }

    if ((*(longlong *)(param_1 + 0x188) != 0) &&

       (*(char *)(*(longlong *)(param_1 + 0x188) + 0x6b) != '\0')) {

      uVar3 = uVar3 | 0x10000;

    }

    if ((*(byte *)(param_1 + 0x48) & 0x40) != 0) {

      uVar3 = uVar3 | 0x20000000;

    }

    return uVar3;

  }

  return 0x80020000;

}




