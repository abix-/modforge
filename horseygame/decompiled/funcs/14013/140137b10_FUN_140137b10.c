// Address: 0x140137b10
// Ghidra name: FUN_140137b10
// ============ 0x140137b10 FUN_140137b10 (size=122) ============


void FUN_140137b10(longlong *param_1)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return;

  }

  if ((*(char *)(*param_1 + 0x2ac) != '\0') && (*(char *)((longlong)param_1 + 0x109) != '\0')) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403dfe08,"SDL_PopGPUDebugGroup_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x5ef);

    } while (iVar2 == 0);

    if (iVar2 != 1) {

      return;

    }

    pcVar1 = (code *)swi(3);

    (*pcVar1)();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x000140137b87. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x68))();

  return;

}




