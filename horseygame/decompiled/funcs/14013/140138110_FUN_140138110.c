// Address: 0x140138110
// Ghidra name: FUN_140138110
// ============ 0x140138110 FUN_140138110 (size=136) ============


void FUN_140138110(undefined8 *param_1,undefined4 *param_2)



{

  longlong lVar1;

  code *pcVar2;

  int iVar3;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  if (param_1 == (undefined8 *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","render_pass");

    return;

  }

  lVar1 = *(longlong *)*param_1;

  if ((*(char *)(lVar1 + 0x2ac) == '\0') || (*(char *)(param_1 + 1) != '\0')) {

    local_18 = *param_2;

    uStack_14 = param_2[1];

    uStack_10 = param_2[2];

    uStack_c = param_2[3];

    (**(code **)(lVar1 + 200))((longlong *)*param_1,&local_18);

  }

  else {

    do {

      iVar3 = FUN_14017f2a0(&DAT_1403e01f8,"SDL_SetGPUBlendConstants_REAL",

                            "C:\\dev\\SDL-3.4.4\\src\\gpu\\SDL_gpu.c",0x7b9);

    } while (iVar3 == 0);

    if (iVar3 == 1) {

      pcVar2 = (code *)swi(3);

      (*pcVar2)();

      return;

    }

  }

  return;

}




