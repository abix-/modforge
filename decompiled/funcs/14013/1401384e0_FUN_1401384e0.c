// Address: 0x1401384e0
// Ghidra name: FUN_1401384e0
// ============ 0x1401384e0 FUN_1401384e0 (size=145) ============


void FUN_1401384e0(undefined8 *param_1,longlong param_2)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","viewport");

    return;

  }

  lVar1 = *(longlong *)*param_1;

  if ((*(char *)(lVar1 + 0x2ac) == '\0') || (*(char *)(param_1 + 1) != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x00014013856e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0xb8))((longlong *)*param_1);

    return;

  }

  do {

    iVar3 = FUN_14017f2a0(&DAT_1403e0198,"SDL_SetGPUViewport_REAL",

                          "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x791);

  } while (iVar3 == 0);

  if (iVar3 == 1) {

    pcVar2 = (code *)swi(3);

    (*pcVar2)();

    return;

  }

  return;

}




