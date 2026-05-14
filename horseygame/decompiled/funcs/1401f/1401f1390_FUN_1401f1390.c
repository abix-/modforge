// Address: 0x1401f1390
// Ghidra name: FUN_1401f1390
// ============ 0x1401f1390 FUN_1401f1390 (size=295) ============


void FUN_1401f1390(longlong param_1)



{

  longlong *plVar1;

  undefined4 *puVar2;

  longlong lVar3;

  undefined4 *puVar4;

  longlong lVar5;

  int *piVar6;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  if (plVar1 != (longlong *)0x0) {

    FUN_1401f0320();

    piVar6 = (int *)((longlong)plVar1 + 0x1e4);

    lVar5 = 0x16;

    do {

      if (*piVar6 != 0) {

        (*(code *)plVar1[0xe])();

      }

      piVar6 = piVar6 + 1;

      lVar5 = lVar5 + -1;

    } while (lVar5 != 0);

    puVar4 = (undefined4 *)plVar1[0x49];

    while (puVar4 != (undefined4 *)0x0) {

      puVar2 = *(undefined4 **)(puVar4 + 0x20);

      (*(code *)plVar1[0xd])(*puVar4);

      FUN_1401841e0(*(undefined8 *)(puVar4 + 0x1c));

      FUN_1401841e0(puVar4);

      puVar4 = puVar2;

    }

    if (*plVar1 != 0) {

      lVar5 = plVar1[0x3b];

      while (lVar5 != 0) {

        lVar3 = *(longlong *)(lVar5 + 0x10);

        (*(code *)plVar1[0x33])(1,lVar5 + 8);

        FUN_1401f4660(&DAT_14039bcb9,param_1,"SDL_render_gles2.c",0x69b,"GLES2_DestroyRenderer");

        FUN_1401841e0(plVar1[0x3b]);

        plVar1[0x3b] = lVar3;

        lVar5 = lVar3;

      }

      FUN_14016c050(*plVar1);

    }

    FUN_1401841e0(plVar1);

  }

  return;

}




