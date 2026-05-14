// Address: 0x140137da0
// Ghidra name: FUN_140137da0
// ============ 0x140137da0 FUN_140137da0 (size=173) ============


void FUN_140137da0(longlong *param_1,uint param_2,longlong param_3)



{

  code *pcVar1;

  int iVar2;

  

  if (param_1 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","command_buffer");

    return;

  }

  if (param_3 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14030ebdc);

    return;

  }

  if (3 < param_2) {

    FUN_14012e850("slot_index exceeds MAX_UNIFORM_BUFFERS_PER_STAGE");

    return;

  }

  if ((*(char *)(*param_1 + 0x2ac) != '\0') && (*(char *)((longlong)param_1 + 0x109) != '\0')) {

    do {

      iVar2 = FUN_14017f2a0(&DAT_1403dfe38,"SDL_PushGPUVertexUniformData_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x6a7);

    } while (iVar2 == 0);

    if (iVar2 != 1) {

      return;

    }

    pcVar1 = (code *)swi(3);

    (*pcVar1)();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x000140137e4a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x118))();

  return;

}




