// Address: 0x1401341d0
// Ghidra name: FUN_1401341d0
// ============ 0x1401341d0 FUN_1401341d0 (size=127) ============


ulonglong FUN_1401341d0(longlong *param_1)



{

  code *pcVar1;

  ulonglong uVar2;

  

  if (param_1 == (longlong *)0x0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return uVar2 & 0xffffffffffffff00;

  }

  if ((*(char *)(*param_1 + 0x2ac) != '\0') && ((char)param_1[0x21] != '\0')) {

    do {

      uVar2 = FUN_14017f2a0(&DAT_1403e1128,"SDL_CancelGPUCommandBuffer_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0xd61);

    } while ((int)uVar2 == 0);

    if ((int)uVar2 != 1) {

      return uVar2 & 0xffffffffffffff00;

    }

    pcVar1 = (code *)swi(3);

    uVar2 = (*pcVar1)();

    return uVar2;

  }

                    /* WARNING: Could not recover jumptable at 0x00014013424c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  uVar2 = (**(code **)(*param_1 + 0x260))();

  return uVar2;

}




