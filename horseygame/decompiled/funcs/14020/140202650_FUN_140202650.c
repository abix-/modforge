// Address: 0x140202650
// Ghidra name: FUN_140202650
// ============ 0x140202650 FUN_140202650 (size=198) ============


void FUN_140202650(undefined8 param_1,longlong *param_2)



{

  int *piVar1;

  code *pcVar2;

  int iVar3;

  int *piVar4;

  int local_18;

  int local_14;

  int local_10;

  int local_c;

  

  if ((char)param_2[2] != '\0') {

    piVar4 = (int *)*param_2;

    piVar1 = (int *)param_2[1];

    do {

      if (piVar4 != (int *)0x0) goto LAB_1402026af;

      iVar3 = FUN_14017f2a0(&DAT_1403e4c50,"SetDrawState",

                            "C:\\dev\\SDL-3.4.4\\src\\render\\software\\SDL_render_sw.c",0x2ae);

    } while (iVar3 == 0);

    if (iVar3 == 1) {

      pcVar2 = (code *)swi(3);

      (*pcVar2)();

      return;

    }

LAB_1402026af:

    if ((piVar1 == (int *)0x0) || (piVar4 == (int *)0x0)) {

      piVar4 = (int *)*param_2;

    }

    else {

      local_18 = *piVar4 + *piVar1;

      local_14 = piVar1[1] + piVar4[1];

      local_10 = piVar1[2];

      local_c = piVar1[3];

      FUN_140185790(piVar4,&local_18,&local_18);

      piVar4 = &local_18;

    }

    FUN_1401485c0(param_1,piVar4);

    *(undefined1 *)(param_2 + 2) = 0;

  }

  return;

}




