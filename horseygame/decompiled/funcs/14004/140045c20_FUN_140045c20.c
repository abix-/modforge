// Address: 0x140045c20
// Ghidra name: FUN_140045c20
// ============ 0x140045c20 FUN_140045c20 (size=96) ============


void FUN_140045c20(void)



{

  longlong lVar1;

  longlong lVar2;

  

  SDL_LockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

  lVar2 = DAT_1403ea2a8;

  for (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0xa0); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x30))

  {

    if ((lVar1 != *(longlong *)(lVar2 + 0x58)) && (lVar1 != *(longlong *)(lVar2 + 0x60))) {

      *(undefined1 *)(lVar1 + 9) = 0;

      lVar2 = DAT_1403ea2a8;

    }

  }

  SDL_UnlockMutex(*(undefined8 *)(lVar2 + 0xe0));

  return;

}




