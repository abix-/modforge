// Address: 0x140223210
// Ghidra name: FUN_140223210
// ============ 0x140223210 FUN_140223210 (size=369) ============


undefined8 FUN_140223210(longlong param_1,char *param_2)



{

  char *pcVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  

  if (param_2 == (char *)0x0) {

    pcVar1 = (char *)FUN_140142960("SDL_OPENGL_LIBRARY");

    param_2 = "OPENGL32.DLL";

    if (pcVar1 != (char *)0x0) {

      param_2 = pcVar1;

    }

  }

  lVar2 = FUN_1401885b0(param_2);

  *(longlong *)(param_1 + 0x518) = lVar2;

  if (lVar2 != 0) {

    FUN_14012f1a0(param_1 + 0x418,param_2,0x100);

    lVar2 = FUN_1401841a0(1,0x58);

    *(longlong *)(param_1 + 0x688) = lVar2;

    if (lVar2 != 0) {

      uVar4 = *(undefined8 *)(param_1 + 0x518);

      uVar3 = FUN_140188550(uVar4,"wglGetProcAddress");

      *(undefined8 *)(lVar2 + 0x10) = uVar3;

      lVar2 = *(longlong *)(param_1 + 0x688);

      uVar3 = FUN_140188550(uVar4,"wglCreateContext");

      *(undefined8 *)(lVar2 + 0x18) = uVar3;

      lVar2 = *(longlong *)(param_1 + 0x688);

      uVar3 = FUN_140188550(uVar4,"wglDeleteContext");

      *(undefined8 *)(lVar2 + 0x20) = uVar3;

      lVar2 = *(longlong *)(param_1 + 0x688);

      uVar3 = FUN_140188550(uVar4,"wglMakeCurrent");

      *(undefined8 *)(lVar2 + 0x28) = uVar3;

      lVar2 = *(longlong *)(param_1 + 0x688);

      uVar4 = FUN_140188550(uVar4,"wglShareLists");

      *(undefined8 *)(lVar2 + 0x30) = uVar4;

      lVar2 = *(longlong *)(param_1 + 0x688);

      if ((((*(longlong *)(lVar2 + 0x10) != 0) && (*(longlong *)(lVar2 + 0x18) != 0)) &&

          (*(longlong *)(lVar2 + 0x20) != 0)) && (*(longlong *)(lVar2 + 0x28) != 0)) {

        *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + 1;

        FUN_140222e90(param_1);

        *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + -1;

        return 1;

      }

      uVar4 = FUN_14012e850("Could not retrieve OpenGL functions");

      return uVar4;

    }

  }

  return 0;

}




