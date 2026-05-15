// Address: 0x1401efd60
// Ghidra name: FUN_1401efd60
// ============ 0x1401efd60 FUN_1401efd60 (size=1460) ============


undefined8 FUN_1401efd60(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  bool bVar1;

  char cVar2;

  undefined4 uVar3;

  ulonglong uVar4;

  longlong *plVar5;

  longlong lVar6;

  undefined8 uVar7;

  uint local_res8 [2];

  int local_res20 [2];

  int local_38;

  undefined4 local_34;

  undefined4 local_30 [2];

  

  local_38 = 0;

  local_res20[0] = 0;

  local_34 = 0;

  bVar1 = false;

  FUN_140155450(param_1,param_3);

  if (*(int *)(param_1 + 0x41) != 0x120005a0) {

    FUN_14012e850("Unsupported output colorspace");

    return 0;

  }

  cVar2 = FUN_14016c230(0x14,&local_38);

  if (cVar2 == '\0') {

    return 0;

  }

  cVar2 = FUN_14016c230(0x11,local_res20);

  if (cVar2 == '\0') {

    return 0;

  }

  cVar2 = FUN_14016c230(0x12,&local_34);

  if (cVar2 == '\0') {

    return 0;

  }

  FUN_140172f40(param_2);

  uVar4 = FUN_14016e130(param_2);

  if ((((uVar4 & 2) == 0) || (local_38 != 4)) || (local_res20[0] < 2)) {

    bVar1 = true;

    FUN_14016cbb0(0x14,4);

    FUN_14016cbb0(0x11,2);

    FUN_14016cbb0(0x12,0);

    cVar2 = FUN_14016fb00(param_2,uVar4 & 0xffffffffcfffffff | 2);

    if (cVar2 == '\0') goto LAB_1401f0299;

  }

  plVar5 = (longlong *)FUN_1401841a0(1,0x318);

  if (plVar5 != (longlong *)0x0) {

    param_1[0x5c] = plVar5;

    FUN_1401f1620(param_1);

    param_1[0x23] = param_2;

    *param_1 = &LAB_1401f4640;

    param_1[2] = FUN_1401f3c70;

    param_1[0xe] = FUN_1401f08f0;

    param_1[0xf] = FUN_1401f3f00;

    param_1[0x10] = FUN_1401f1350;

    param_1[3] = FUN_1401f0a40;

    param_1[0x12] = FUN_1401f3fd0;

    param_1[0x13] = FUN_1401f4450;

    param_1[0x14] = FUN_1401f42e0;

    param_1[0x15] = &LAB_1401f22d0;

    param_1[0x16] = FUN_1401f3ec0;

    param_1[0x17] = FUN_1401f3bd0;

    param_1[4] = FUN_140018e60;

    param_1[5] = FUN_140018e60;

    param_1[6] = FUN_1401f2560;

    param_1[7] = FUN_1401f2350;

    param_1[0xb] = FUN_1401f2740;

    param_1[0xc] = FUN_1401f1620;

    param_1[0xd] = FUN_1401f32b0;

    param_1[0x18] = FUN_1401f3190;

    param_1[0x19] = &LAB_1401f3180;

    param_1[0x1a] = FUN_1401f14c0;

    param_1[0x1b] = FUN_1401f1390;

    param_1[0x1c] = FUN_1401ee960;

    param_1[0x20] = PTR_s_opengles2_1403e4be8;

    FUN_14016cbb0(0x16,0);

    lVar6 = FUN_14016bdf0(param_2);

    *plVar5 = lVar6;

    if (((lVar6 != 0) && (cVar2 = FUN_14016c930(param_2,lVar6), cVar2 != '\0')) &&

       ((cVar2 = FUN_1401f1670(plVar5), cVar2 != '\0' &&

        (cVar2 = FUN_1401f0890(plVar5), cVar2 != '\0')))) {

      cVar2 = FUN_14016c230(0x13,local_res8);

      if ((cVar2 != '\0') && ((local_res8[0] & 1) != 0)) {

        *(undefined1 *)(plVar5 + 1) = 1;

      }

      local_res8[0] = 0;

      (*(code *)plVar5[0x1a])(0xd33,local_res8);

      lVar6 = (longlong)(int)local_res8[0];

      uVar3 = FUN_14014f090(param_1);

      FUN_140175360(uVar3,"SDL.renderer.max_texture_size",lVar6);

      plVar5[0x3b] = 0;

      (*(code *)plVar5[0x1a])(0x8ca6,local_30);

      *(undefined4 *)(plVar5 + 0x3c) = local_30[0];

      FUN_14014b7f0(param_1,0x16362004);

      FUN_14014b7f0(param_1,0x16762004);

      FUN_14014b7f0(param_1,0x16161804);

      FUN_14014b7f0(param_1,0x16561804);

      FUN_14014b7f0(param_1,0x13000801);

      FUN_14014b7f0(param_1,0x32315659);

      FUN_14014b7f0(param_1,0x56555949);

      FUN_14014b7f0(param_1,0x3231564e);

      FUN_14014b7f0(param_1,0x3132564e);

      cVar2 = FUN_14016c0c0("GL_OES_EGL_image_external");

      if (cVar2 == '\0') {

LAB_1401f014e:

        cVar2 = FUN_14016c0c0("GL_EXT_blend_minmax");

        if (cVar2 != '\0') {

          *(undefined1 *)((longlong)plVar5 + 10) = 1;

        }

        if ((local_res20[0] < 3) &&

           (cVar2 = FUN_14016c0c0("GL_ARB_texture_non_power_of_two"), cVar2 == '\0')) {

          *(undefined1 *)((longlong)param_1 + 0x115) = 1;

        }

        cVar2 = FUN_14016c0c0("GL_EXT_sRGB_write_control");

        if (cVar2 != '\0') {

          (*(code *)plVar5[0x10])(0x8db9);

        }

        (*(code *)plVar5[0x10])(0xb71);

        (*(code *)plVar5[0x10])(0xb44);

        (*(code *)plVar5[2])(0x84c0);

        (*(code *)plVar5[0x20])(0xd05,1);

        (*(code *)plVar5[0x20])(0xcf5,1);

        (*(code *)plVar5[0x14])(0);

        (*(code *)plVar5[0x14])(1);

        (*(code *)plVar5[0x11])(2);

        (*(code *)plVar5[9])(DAT_14039ca44,DAT_14039ca44,DAT_14039ca44,DAT_14039ca44);

        *(undefined4 *)((longlong)plVar5 + 0x2a4) = 0x3f800000;

        *(undefined4 *)(plVar5 + 0x55) = 0x3f800000;

        *(undefined4 *)((longlong)plVar5 + 0x2ac) = 0x3f800000;

        *(undefined4 *)(plVar5 + 0x56) = 0x3f800000;

        *(undefined4 *)(plVar5 + 0x60) = 0xbf800000;

        *(undefined4 *)((longlong)plVar5 + 0x30c) = 0x3f800000;

        FUN_1401f4660(&DAT_14039bcb9,param_1,"SDL_render_gles2.c",0x9bf,"GLES2_CreateRenderer");

        return 1;

      }

      *(undefined1 *)((longlong)plVar5 + 9) = 1;

      cVar2 = FUN_1401f06c0(plVar5,0x15,0x8b30);

      if (cVar2 != '\0') {

        FUN_14014b7f0(param_1,0x2053454f);

        goto LAB_1401f014e;

      }

    }

  }

  if (!bVar1) {

    return 0;

  }

LAB_1401f0299:

  uVar7 = FUN_14012e730();

  uVar7 = FUN_14012f0d0(uVar7);

  FUN_14016cbb0(0x14,local_38);

  FUN_14016cbb0(0x11,local_res20[0]);

  FUN_14016cbb0(0x12,local_34);

  FUN_14016fc90(param_2,uVar4);

  FUN_14012e850(&DAT_14039bf30,uVar7);

  FUN_1401841e0(uVar7);

  return 0;

}




