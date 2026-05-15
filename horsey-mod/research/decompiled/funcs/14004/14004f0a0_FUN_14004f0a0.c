// Address: 0x14004f0a0
// Ghidra name: FUN_14004f0a0
// ============ 0x14004f0a0 FUN_14004f0a0 (size=173) ============


void FUN_14004f0a0(undefined8 *param_1)



{

  SDL_LockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

  param_1[6] = *(undefined8 *)(DAT_1403ea2a8 + 0xa0);

  param_1[7] = 0;

  if (*(longlong *)(DAT_1403ea2a8 + 0xa0) != 0) {

    *(undefined8 **)(*(longlong *)(DAT_1403ea2a8 + 0xa0) + 0x38) = param_1;

  }

  *(undefined8 **)(DAT_1403ea2a8 + 0xa0) = param_1;

  *(int *)(param_1[5] + 0xc) = *(int *)(param_1[5] + 0xc) + 1;

  *(undefined1 *)((longlong)param_1 + 9) = 1;

  *param_1 = *(undefined8 *)(DAT_1403ea2a8 + 0x78);

  *(longlong *)(DAT_1403ea2a8 + 0x78) = *(longlong *)(DAT_1403ea2a8 + 0x78) + 1;

  FUN_14004a250(DAT_1403ea2a8 + 0x80,*param_1,param_1);

  SDL_UnlockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

  return;

}




