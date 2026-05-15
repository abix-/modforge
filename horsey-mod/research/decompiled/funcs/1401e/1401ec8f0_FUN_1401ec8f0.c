// Address: 0x1401ec8f0
// Ghidra name: FUN_1401ec8f0
// ============ 0x1401ec8f0 FUN_1401ec8f0 (size=241) ============


void FUN_1401ec8f0(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  code *pcVar4;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  if (plVar1 != (longlong *)0x0) {

    if (*plVar1 != 0) {

      FUN_1401ebd30();

    }

    FUN_1401ebed0(param_1);

    if (*(char *)((longlong)plVar1 + 9) != '\0') {

      pcVar4 = (code *)FUN_14016c730("glDebugMessageCallbackARB");

      (*pcVar4)(plVar1[3],plVar1[4]);

    }

    if (plVar1[0x3f] != 0) {

      FUN_140240c90();

    }

    if (*plVar1 != 0) {

      lVar3 = plVar1[6];

      while (lVar3 != 0) {

        lVar2 = *(longlong *)(lVar3 + 0x10);

        (*(code *)plVar1[0x3b])(1,lVar3 + 8);

        FUN_1401ebd90(&DAT_14039bcb9,param_1,"SDL_render_gl.c",0x6c7,"GL_DestroyRenderer");

        FUN_1401841e0(plVar1[6]);

        plVar1[6] = lVar2;

        lVar3 = lVar2;

      }

      FUN_14016c050(*plVar1);

    }

    FUN_1401841e0(plVar1);

  }

  return;

}




