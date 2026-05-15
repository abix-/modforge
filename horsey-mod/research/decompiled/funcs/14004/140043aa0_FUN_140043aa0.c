// Address: 0x140043aa0
// Ghidra name: FUN_140043aa0
// ============ 0x140043aa0 FUN_140043aa0 (size=437) ============


void FUN_140043aa0(void)



{

  longlong lVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined8 *puVar4;

  uint uVar5;

  ulonglong uVar7;

  ulonglong uVar6;

  

  if (DAT_1403ea2a8 != 0) {

    *(undefined1 *)(DAT_1403ea2a8 + 0xd0) = 0;

    SDL_DestroyAudioStream(*(undefined8 *)(DAT_1403ea2a8 + 0xd8));

    SDL_DestroyMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

    uVar6 = 0;

    for (lVar1 = *(longlong *)(DAT_1403ea2a8 + 0xa0); lVar1 != 0;

        lVar1 = *(longlong *)(lVar1 + 0x30)) {

      if (*(longlong *)(lVar1 + 0x28) != 0) {

        *(undefined4 *)(*(longlong *)(lVar1 + 0x28) + 0xc) = 0;

      }

    }

    puVar4 = *(undefined8 **)(DAT_1403ea2a8 + 0x98);

    while (puVar4 != (undefined8 *)0x0) {

      puVar2 = (undefined8 *)*puVar4;

      thunk_FUN_1402e9a80(puVar4);

      puVar4 = puVar2;

    }

    uVar7 = uVar6;

    if (0 < *(int *)(DAT_1403ea2a8 + 0x6c)) {

      do {

        lVar1 = *(longlong *)(uVar7 + *(longlong *)(DAT_1403ea2a8 + 0x70));

        lVar3 = *(longlong *)(lVar1 + 0x10);

        if (lVar3 != 0) {

          thunk_FUN_1402e9a80(lVar3 - (ulonglong)*(byte *)(lVar3 + -1));

        }

        thunk_FUN_1402e9a80(lVar1);

        uVar5 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar5;

        uVar7 = uVar7 + 8;

      } while ((int)uVar5 < *(int *)(DAT_1403ea2a8 + 0x6c));

    }

    thunk_FUN_1402e9a80(*(undefined8 *)(DAT_1403ea2a8 + 0x70));

    lVar1 = *(longlong *)(DAT_1403ea2a8 + 0xb8);

    if (lVar1 != 0) {

      thunk_FUN_1402e9a80(lVar1 - (ulonglong)*(byte *)(lVar1 + -1));

    }

    lVar1 = *(longlong *)(DAT_1403ea2a8 + 0xc0);

    if (lVar1 != 0) {

      thunk_FUN_1402e9a80(lVar1 - (ulonglong)*(byte *)(lVar1 + -1));

    }

    lVar1 = *(longlong *)(DAT_1403ea2a8 + 200);

    if (lVar1 != 0) {

      thunk_FUN_1402e9a80(lVar1 - (ulonglong)*(byte *)(lVar1 + -1));

    }

    thunk_FUN_1402e9a80(*(undefined8 *)(DAT_1403ea2a8 + 0x88));

    thunk_FUN_1402e9a80(DAT_1403ea2a8);

    DAT_1403ea2a8 = 0;

  }

  return;

}




