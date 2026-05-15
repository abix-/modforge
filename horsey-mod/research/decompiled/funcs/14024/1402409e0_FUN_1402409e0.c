// Address: 0x1402409e0
// Ghidra name: FUN_1402409e0
// ============ 0x1402409e0 FUN_1402409e0 (size=679) ============


longlong * FUN_1402409e0(void)



{

  char cVar1;

  longlong *plVar2;

  longlong lVar3;

  longlong *plVar4;

  int iVar5;

  

  plVar2 = (longlong *)FUN_1401841a0(1,0x1a0);

  if (plVar2 == (longlong *)0x0) {

    return (longlong *)0x0;

  }

  cVar1 = FUN_14016c0c0("GL_ARB_texture_non_power_of_two");

  if ((cVar1 == '\0') &&

     ((cVar1 = FUN_14016c0c0("GL_ARB_texture_rectangle"), cVar1 != '\0' ||

      (cVar1 = FUN_14016c0c0("GL_EXT_texture_rectangle"), cVar1 != '\0')))) {

    *(undefined1 *)(plVar2 + 0x10) = 1;

  }

  cVar1 = FUN_14016c0c0("GL_ARB_shader_objects");

  if ((((cVar1 != '\0') && (cVar1 = FUN_14016c0c0("GL_ARB_shading_language_100"), cVar1 != '\0')) &&

      (cVar1 = FUN_14016c0c0("GL_ARB_vertex_shader"), cVar1 != '\0')) &&

     (cVar1 = FUN_14016c0c0("GL_ARB_fragment_shader"), cVar1 != '\0')) {

    lVar3 = FUN_14016c730("glGetError");

    *plVar2 = lVar3;

    lVar3 = FUN_14016c730("glAttachObjectARB");

    plVar2[1] = lVar3;

    lVar3 = FUN_14016c730("glCompileShaderARB");

    plVar2[2] = lVar3;

    lVar3 = FUN_14016c730("glCreateProgramObjectARB");

    plVar2[3] = lVar3;

    lVar3 = FUN_14016c730("glCreateShaderObjectARB");

    plVar2[4] = lVar3;

    lVar3 = FUN_14016c730("glDeleteObjectARB");

    plVar2[5] = lVar3;

    lVar3 = FUN_14016c730("glGetInfoLogARB");

    plVar2[6] = lVar3;

    lVar3 = FUN_14016c730("glGetObjectParameterivARB");

    plVar2[7] = lVar3;

    lVar3 = FUN_14016c730("glGetUniformLocationARB");

    plVar2[8] = lVar3;

    lVar3 = FUN_14016c730("glLinkProgramARB");

    plVar2[9] = lVar3;

    lVar3 = FUN_14016c730("glShaderSourceARB");

    plVar2[10] = lVar3;

    lVar3 = FUN_14016c730("glUniform1iARB");

    plVar2[0xb] = lVar3;

    lVar3 = FUN_14016c730("glUniform1fARB");

    plVar2[0xc] = lVar3;

    lVar3 = FUN_14016c730("glUniform3fARB");

    plVar2[0xd] = lVar3;

    lVar3 = FUN_14016c730("glUniform4fARB");

    plVar2[0xe] = lVar3;

    lVar3 = FUN_14016c730("glUseProgramObjectARB");

    plVar2[0xf] = lVar3;

    if (((((*plVar2 != 0) && (plVar2[1] != 0)) &&

         ((plVar2[2] != 0 && ((plVar2[3] != 0 && (plVar2[4] != 0)))))) &&

        ((plVar2[5] != 0 &&

         ((((plVar2[6] != 0 && (plVar2[7] != 0)) && (plVar2[8] != 0)) &&

          ((plVar2[9] != 0 && (plVar2[10] != 0)))))))) &&

       (((plVar2[0xb] != 0 && ((plVar2[0xc] != 0 && (plVar2[0xd] != 0)))) && (lVar3 != 0)))) {

      iVar5 = 0;

      plVar4 = plVar2;

      do {

        cVar1 = FUN_140240810(plVar2,iVar5,(longlong)plVar4 + 0x84);

        if (cVar1 == '\0') {

          FUN_140240980(plVar2,(longlong)plVar4 + 0x84);

        }

        iVar5 = iVar5 + 1;

        plVar4 = (longlong *)((longlong)plVar4 + 0xc);

      } while (iVar5 < 0xe);

      return plVar2;

    }

  }

  FUN_1401841e0(plVar2);

  return (longlong *)0x0;

}




