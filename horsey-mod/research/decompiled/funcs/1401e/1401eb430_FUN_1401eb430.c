// Address: 0x1401eb430
// Ghidra name: FUN_1401eb430
// ============ 0x1401eb430 FUN_1401eb430 (size=2292) ============


undefined8 FUN_1401eb430(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  undefined4 uVar6;

  ulonglong uVar7;

  longlong *plVar8;

  longlong lVar9;

  code *pcVar10;

  undefined1 *puVar11;

  char *pcVar12;

  undefined8 uVar13;

  uint local_res20 [2];

  int local_68;

  int local_64;

  int local_60 [2];

  undefined1 local_58 [32];

  

  local_68 = 0;

  local_64 = 0;

  iVar4 = 0;

  local_60[0] = 0;

  bVar2 = false;

  bVar1 = false;

  FUN_140155450(param_1,param_3);

  if (*(int *)(param_1 + 0x41) != 0x120005a0) {

    FUN_14012e850("Unsupported output colorspace");

    return 0;

  }

  cVar3 = FUN_14016c230(0x14,&local_68);

  if (cVar3 == '\0') {

    return 0;

  }

  cVar3 = FUN_14016c230(0x11,&local_64);

  if (cVar3 == '\0') {

    return 0;

  }

  cVar3 = FUN_14016c230(0x12,local_60);

  if (cVar3 == '\0') {

    return 0;

  }

  FUN_140172f40(param_2);

  uVar7 = FUN_14016e130(param_2);

  if (((((uVar7 & 2) == 0) || (local_68 == 4)) || (local_64 != 2)) || (local_60[0] != 1)) {

    bVar2 = true;

    FUN_14016cbb0(0x14,0);

    FUN_14016cbb0(0x11,2);

    FUN_14016cbb0(0x12,1);

    cVar3 = FUN_14016fb00(param_2,uVar7 & 0xffffffffcfffffff | 2);

    if (cVar3 == '\0') goto LAB_1401ebcae;

  }

  plVar8 = (longlong *)FUN_1401841a0(1,0x290);

  if (plVar8 != (longlong *)0x0) {

    param_1[0x5c] = plVar8;

    *param_1 = &LAB_1401ef3b0;

    param_1[2] = FUN_1401ee9c0;

    param_1[0xe] = FUN_1401ebf60;

    param_1[0xf] = FUN_1401eebd0;

    param_1[0x10] = FUN_1401ec8b0;

    param_1[3] = FUN_1401ec080;

    param_1[0x12] = FUN_1401eecc0;

    param_1[0x13] = FUN_1401ef1b0;

    param_1[0x14] = FUN_1401ef030;

    param_1[0x15] = &LAB_1401ed710;

    param_1[0x16] = FUN_1401eeb30;

    param_1[0x17] = FUN_1401ee8a0;

    param_1[4] = FUN_140018e60;

    param_1[5] = FUN_140018e60;

    param_1[6] = FUN_1401ed8f0;

    param_1[7] = FUN_1401ed790;

    param_1[0xb] = FUN_1401eda20;

    param_1[0xc] = FUN_1401ecc80;

    param_1[0xd] = FUN_1401ee270;

    param_1[0x18] = FUN_1401ee060;

    param_1[0x19] = FUN_1401ee040;

    param_1[0x1a] = FUN_1401ec9f0;

    param_1[0x1b] = FUN_1401ec8f0;

    param_1[0x1c] = FUN_1401ee960;

    FUN_1401ecc80(param_1);

    param_1[0x23] = param_2;

    param_1[0x20] = PTR_s_opengl_1403e4ba0;

    FUN_14016cbb0(0x16,0);

    lVar9 = FUN_14016bdf0(param_2);

    *plVar8 = lVar9;

    if (((lVar9 != 0) && (cVar3 = FUN_14016c930(param_2,lVar9), cVar3 != '\0')) &&

       (cVar3 = FUN_1401ecce0(plVar8), cVar3 != '\0')) {

      cVar3 = FUN_14016c230(0x13,local_res20);

      if ((cVar3 != '\0') && ((local_res20[0] & 1) != 0)) {

        *(undefined1 *)(plVar8 + 1) = 1;

      }

      if (((char)plVar8[1] != '\0') && (cVar3 = FUN_14016c0c0("GL_ARB_debug_output"), cVar3 != '\0')

         ) {

        pcVar10 = (code *)FUN_14016c730("glDebugMessageCallbackARB");

        *(undefined1 *)((longlong)plVar8 + 9) = 1;

        (*(code *)plVar8[0x1e])(0x8244,plVar8 + 3);

        (*(code *)plVar8[0x1e])(0x8245,plVar8 + 4);

        (*pcVar10)(FUN_1401ecb80,param_1);

        (*(code *)plVar8[0x17])(0x8242);

      }

      lVar9 = (*(code *)plVar8[0x1f])(0x1f02);

      iVar5 = 0;

      if (lVar9 != 0) {

        FUN_14012f1a0(local_58,lVar9,0x10);

        puVar11 = (undefined1 *)thunk_FUN_1402c9190(local_58,0x2e);

        iVar5 = 0;

        if (puVar11 != (undefined1 *)0x0) {

          iVar4 = thunk_FUN_1402d89dc(puVar11 + 1);

          *puVar11 = 0;

          iVar5 = thunk_FUN_1402d89dc(local_58);

        }

      }

      pcVar12 = (char *)FUN_140142960("GL_ARB_texture_non_power_of_two");

      if (((pcVar12 == (char *)0x0) || (*pcVar12 != '0')) &&

         ((1 < iVar5 || (cVar3 = FUN_14016c0c0("GL_ARB_texture_non_power_of_two"), cVar3 != '\0'))))

      {

        *(undefined1 *)((longlong)param_1 + 0x115) = 0;

        *(undefined4 *)(plVar8 + 5) = 0xde1;

        *(undefined1 *)((longlong)plVar8 + 0x2c) = 1;

LAB_1401eb852:

        uVar13 = 0xd33;

      }

      else {

        *(undefined1 *)((longlong)param_1 + 0x115) = 1;

        *(undefined4 *)(plVar8 + 5) = 0xde1;

        cVar3 = FUN_14016c0c0("GL_ARB_texture_rectangle");

        if ((cVar3 == '\0') && (cVar3 = FUN_14016c0c0("GL_EXT_texture_rectangle"), cVar3 == '\0'))

        goto LAB_1401eb852;

        *(undefined1 *)((longlong)plVar8 + 0x2d) = 1;

        uVar13 = 0x84f8;

        *(undefined4 *)(plVar8 + 5) = 0x84f5;

      }

      (*(code *)plVar8[0x1d])(uVar13,local_res20);

      uVar6 = FUN_14014f090(param_1);

      FUN_140175360(uVar6,"SDL.renderer.max_texture_size",(longlong)(int)local_res20[0]);

      cVar3 = FUN_14016c0c0("GL_ARB_multitexture");

      if (cVar3 != '\0') {

        lVar9 = FUN_14016c730("glActiveTextureARB");

        plVar8[0x38] = lVar9;

        if (lVar9 != 0) {

          *(undefined1 *)(plVar8 + 0x37) = 1;

          (*(code *)plVar8[0x1d])(0x84e2,plVar8 + 0x39);

        }

      }

      pcVar12 = (char *)FUN_140142960("GL_EXT_bgra");

      if (((pcVar12 == (char *)0x0) || (*pcVar12 != '0')) &&

         ((1 < iVar5 ||

          (((iVar5 == 1 && (1 < iVar4)) || (cVar3 = FUN_14016c0c0("GL_EXT_bgra"), cVar3 != '\0')))))

         ) {

        bVar1 = true;

        FUN_14014b7f0(param_1,0x16362004);

      }

      FUN_14014b7f0(param_1,0x16762004);

      lVar9 = FUN_1402409e0();

      plVar8[0x3f] = lVar9;

      pcVar12 = "DISABLED";

      if (lVar9 != 0) {

        pcVar12 = "ENABLED";

      }

      FUN_14012e0e0(6,"OpenGL shaders: %s",pcVar12);

      cVar3 = FUN_140240ee0(plVar8[0x3f],5);

      if (cVar3 == '\0') {

        FUN_14012e0e0(6,"OpenGL RGB shaders not supported");

      }

      else {

        if (bVar1) {

          FUN_14014b7f0(param_1,0x16161804);

        }

        FUN_14014b7f0(param_1,0x16561804);

      }

      cVar3 = FUN_140240ee0(plVar8[0x3f],6);

      if ((cVar3 == '\0') || (cVar3 = FUN_140240ee0(plVar8[0x3f],8), cVar3 == '\0')) {

        FUN_14012e0e0(6,"OpenGL PIXELART shaders not supported");

      }

      else {

        *(undefined1 *)((longlong)plVar8 + 10) = 1;

      }

      cVar3 = FUN_140240ee0(plVar8[0x3f],2);

      if ((((cVar3 == '\0') || (cVar3 = FUN_140240ee0(plVar8[0x3f],3), cVar3 == '\0')) ||

          ((*(char *)((longlong)plVar8 + 10) != '\0' &&

           (cVar3 = FUN_140240ee0(plVar8[0x3f],4), cVar3 == '\0')))) || ((int)plVar8[0x39] < 2)) {

        FUN_14012e0e0(6,"OpenGL palette shaders not supported");

      }

      else {

        FUN_14014b7f0(param_1,0x13000801);

      }

      cVar3 = FUN_140240ee0(plVar8[0x3f],9);

      if ((cVar3 == '\0') || ((int)plVar8[0x39] < 3)) {

        FUN_14012e0e0(6,"OpenGL YUV not supported");

      }

      else {

        FUN_14014b7f0(param_1,0x32315659);

        FUN_14014b7f0(param_1,0x56555949);

      }

      cVar3 = FUN_140240ee0(plVar8[0x3f],10);

      if ((((cVar3 == '\0') || (cVar3 = FUN_140240ee0(plVar8[0x3f],0xb), cVar3 == '\0')) ||

          (cVar3 = FUN_140240ee0(plVar8[0x3f],0xc), cVar3 == '\0')) ||

         ((cVar3 = FUN_140240ee0(plVar8[0x3f],0xd), cVar3 == '\0' || ((int)plVar8[0x39] < 2)))) {

        FUN_14012e0e0(6,"OpenGL NV12/NV21 not supported");

      }

      else {

        FUN_14014b7f0(param_1,0x3231564e);

        FUN_14014b7f0(param_1,0x3132564e);

      }

      cVar3 = FUN_14016c0c0("GL_EXT_framebuffer_object");

      if (cVar3 != '\0') {

        *(undefined1 *)((longlong)plVar8 + 0x2e) = 1;

        lVar9 = FUN_14016c730("glGenFramebuffersEXT");

        plVar8[0x3a] = lVar9;

        lVar9 = FUN_14016c730("glDeleteFramebuffersEXT");

        plVar8[0x3b] = lVar9;

        lVar9 = FUN_14016c730("glFramebufferTexture2DEXT");

        plVar8[0x3c] = lVar9;

        lVar9 = FUN_14016c730("glBindFramebufferEXT");

        plVar8[0x3d] = lVar9;

        lVar9 = FUN_14016c730("glCheckFramebufferStatusEXT");

        plVar8[0x3e] = lVar9;

        if (((2 < iVar5) || (cVar3 = FUN_14016c0c0("GL_EXT_framebuffer_sRGB"), cVar3 != '\0')) ||

           (cVar3 = FUN_14016c0c0("GL_ARB_framebuffer_sRGB"), cVar3 != '\0')) {

          (*(code *)plVar8[0x13])(0x8db9);

        }

        (*(code *)plVar8[0x22])(0x1700);

        (*(code *)plVar8[0x21])();

        (*(code *)plVar8[0x13])(0xb71);

        (*(code *)plVar8[0x13])(0xb44);

        (*(code *)plVar8[0x13])(0xc11);

        (*(code *)plVar8[0x13])((int)plVar8[5]);

        uVar6 = DAT_14039ca44;

        (*(code *)plVar8[0xc])(DAT_14039ca44,DAT_14039ca44,DAT_14039ca44,DAT_14039ca44);

        (*(code *)plVar8[0xe])(uVar6,uVar6,uVar6,uVar6);

        *(undefined4 *)((longlong)plVar8 + 0x26c) = 0x3f800000;

        *(undefined4 *)(plVar8 + 0x4e) = 0x3f800000;

        *(undefined4 *)((longlong)plVar8 + 0x274) = 0x3f800000;

        *(undefined4 *)(plVar8 + 0x4f) = 0x3f800000;

        *(undefined4 *)(plVar8 + 0x50) = 0x3f800000;

        *(undefined4 *)((longlong)plVar8 + 0x284) = 0x3f800000;

        *(undefined4 *)(plVar8 + 0x51) = 0x3f800000;

        *(undefined4 *)((longlong)plVar8 + 0x28c) = 0x3f800000;

        return 1;

      }

      FUN_14012e850("Can\'t create render targets, GL_EXT_framebuffer_object not available");

    }

  }

  if (!bVar2) {

    return 0;

  }

LAB_1401ebcae:

  uVar13 = FUN_14012e730();

  uVar13 = FUN_14012f0d0(uVar13);

  FUN_14016cbb0(0x14,local_68);

  FUN_14016cbb0(0x11,local_64);

  FUN_14016cbb0(0x12,local_60[0]);

  FUN_14016fc90(param_2,uVar7);

  FUN_14012e850(&DAT_14039bf30,uVar13);

  FUN_1401841e0(uVar13);

  return 0;

}




