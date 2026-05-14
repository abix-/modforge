// Address: 0x1400447e0
// Ghidra name: FUN_1400447e0
// ============ 0x1400447e0 FUN_1400447e0 (size=284) ============


void FUN_1400447e0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (DAT_1403ea2a8 != 0) {

    SDL_LockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

    if (*(int *)(param_1 + 0xc) == 0) {

      lVar1 = *(longlong *)(param_1 + 0x10);

      if (lVar1 != 0) {

        thunk_FUN_1402e9a80(lVar1 - (ulonglong)*(byte *)(lVar1 + -1));

      }

      thunk_FUN_1402e9a80(param_1);

    }

    else {

      if (*(int *)(DAT_1403ea2a8 + 0x6c) == *(int *)(DAT_1403ea2a8 + 0x68)) {

        iVar2 = *(int *)(DAT_1403ea2a8 + 0x68) * 2;

        uVar3 = _malloc_base((longlong)iVar2);

        FUN_1402f8e20(uVar3,*(undefined8 *)(DAT_1403ea2a8 + 0x70),

                      (longlong)*(int *)(DAT_1403ea2a8 + 0x6c) << 3);

        thunk_FUN_1402e9a80(*(undefined8 *)(DAT_1403ea2a8 + 0x70));

        *(undefined8 *)(DAT_1403ea2a8 + 0x70) = uVar3;

        *(int *)(DAT_1403ea2a8 + 0x68) = iVar2;

      }

      *(longlong *)

       (*(longlong *)(DAT_1403ea2a8 + 0x70) + (longlong)*(int *)(DAT_1403ea2a8 + 0x6c) * 8) =

           param_1;

      *(int *)(DAT_1403ea2a8 + 0x6c) = *(int *)(DAT_1403ea2a8 + 0x6c) + 1;

    }

    SDL_UnlockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

    return;

  }

  lVar1 = *(longlong *)(param_1 + 0x10);

  if (lVar1 != 0) {

    thunk_FUN_1402e9a80(lVar1 - (ulonglong)*(byte *)(lVar1 + -1));

  }

  thunk_FUN_1402e9a80(param_1);

  return;

}




