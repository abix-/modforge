// Address: 0x140138240
// Ghidra name: FUN_140138240
// ============ 0x140138240 FUN_140138240 (size=145) ============


void FUN_140138240(undefined8 *param_1,longlong param_2)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","scissor");

    return;

  }

  lVar1 = *(longlong *)*param_1;

  if ((*(char *)(lVar1 + 0x2ac) == '\0') || (*(char *)(param_1 + 1) != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x0001401382ce. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0xc0))((longlong *)*param_1);

    return;

  }

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403e01c8,"SDL_SetGPUScissor_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x7a7);

  } while (iVar3 == 0);

  if (iVar3 == 1) {

    pcVar2 = (code *)swi(3);

    (*pcVar2)();

    return;

  }

  return;

}




