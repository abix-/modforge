// Address: 0x140137a30
// Ghidra name: FUN_140137a30
// ============ 0x140137a30 FUN_140137a30 (size=139) ============


void FUN_140137a30(longlong *param_1,longlong param_2)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140319a7c);

    return;

  }

  if ((*(char *)(*param_1 + 0x2ac) == '\0') || (*(char *)((longlong)param_1 + 0x109) == '\0')) {

                    /* WARNING: Could not recover jumptable at 0x000140137ab8. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x58))();

    return;

  }

  do {

    iVar2 = FUN_14017f2a0(&DAT_1403dfda8,"SDL_InsertGPUDebugLabel_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x5c8);

  } while (iVar2 == 0);

  if (iVar2 == 1) {

    pcVar1 = (code *)swi(3);

    (*pcVar1)();

    return;

  }

  return;

}




