// Address: 0x140133a70
// Ghidra name: FUN_140133a70
// ============ 0x140133a70 FUN_140133a70 (size=160) ============


void FUN_140133a70(undefined8 *param_1,undefined8 param_2,longlong param_3,int param_4)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  if ((param_3 == 0) && (param_4 != 0)) {

    FUN_14012e850("Parameter \'%s\' is invalid","bindings");

    return;

  }

  lVar1 = *(longlong *)*param_1;

  if ((*(char *)(lVar1 + 0x2ac) == '\0') || (*(char *)(param_1 + 1) != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x000140133b0d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0xd8))((longlong *)*param_1);

    return;

  }

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403e0258,"SDL_BindGPUVertexBuffers_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x7e3);

  } while (iVar3 == 0);

  if (iVar3 != 1) {

    return;

  }

  pcVar2 = (code *)swi(3);

  (*pcVar2)();

  return;

}




