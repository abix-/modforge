// Address: 0x14014bff0
// Ghidra name: FUN_14014bff0
// ============ 0x14014bff0 FUN_14014bff0 (size=1718) ============


longlong FUN_14014bff0(ulonglong param_1)



{

  undefined1 uVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  char *pcVar8;

  undefined8 uVar9;

  size_t sVar10;

  longlong lVar11;

  undefined8 *puVar12;

  ulonglong uVar13;

  char *pcVar14;

  longlong lVar15;

  size_t sVar16;

  char *pcVar17;

  char *local_res10;

  

  lVar5 = FUN_140174d30(param_1,"SDL.renderer.create.window",0);

  lVar6 = FUN_140174d30(param_1 & 0xffffffff,"SDL.renderer.create.surface",0);

  local_res10 = (char *)FUN_140174e70(param_1 & 0xffffffff,"SDL.renderer.create.name",0);

  if (lVar5 == 0) {

    if ((lVar6 == 0) &&

       ((local_res10 == (char *)0x0 || (iVar3 = strcmp(local_res10,"gpu"), iVar3 != 0)))) {

      FUN_14012e850("Parameter \'%s\' is invalid","window");

      return 0;

    }

  }

  else {

    if (lVar6 != 0) {

      FUN_14012e850("A renderer can\'t target both a window and surface");

      return 0;

    }

    cVar2 = FUN_140174210(lVar5);

    if (cVar2 != '\0') {

      FUN_14012e850("Surface already associated with window");

      return 0;

    }

    lVar7 = FUN_14014f110(lVar5);

    if (lVar7 != 0) {

      FUN_14012e850("Renderer already associated with window");

      return 0;

    }

  }

  lVar7 = FUN_1401841a0(1,0x2f0);

  if (lVar7 == 0) {

    return 0;

  }

  FUN_1401aa9d0(lVar7,2,1);

  pcVar8 = (char *)FUN_140142960("SDL_RENDER_VSYNC");

  if ((pcVar8 != (char *)0x0) && (*pcVar8 != '\0')) {

    uVar1 = FUN_140142940("SDL_RENDER_VSYNC",1);

    FUN_140175360(param_1 & 0xffffffff,"SDL.renderer.create.present_vsync",uVar1);

  }

  if (lVar6 == 0) {

    cVar2 = '\0';

    pcVar8 = (char *)0x0;

    if (((local_res10 == (char *)0x0) &&

        (local_res10 = (char *)FUN_140142960("SDL_RENDER_DRIVER"), local_res10 == (char *)0x0)) ||

       (pcVar17 = local_res10, *local_res10 == '\0')) {

      if (PTR_PTR_1403e1d60 != (undefined *)0x0) {

        lVar11 = 0;

        puVar12 = (undefined8 *)PTR_PTR_1403e1d60;

        do {

          cVar2 = (*(code *)*puVar12)(lVar7,lVar5,param_1 & 0xffffffff);

          if (cVar2 != '\0') break;

          FUN_14014da10(lVar7);

          FUN_1402f94c0(lVar7,0,0x2f0);

          puVar12 = (undefined8 *)(&PTR_PTR_1403e1d68)[lVar11];

          lVar11 = lVar11 + 1;

        } while (puVar12 != (undefined8 *)0x0);

        goto LAB_14014c305;

      }

    }

    else {

      while ((*pcVar17 != '\0' && (cVar2 == '\0'))) {

        lVar11 = thunk_FUN_1402c9190(pcVar17,0x2c);

        if (lVar11 == 0) {

          sVar16 = strlen(pcVar17);

        }

        else {

          sVar16 = lVar11 - (longlong)pcVar17;

        }

        lVar15 = 0;

        puVar12 = (undefined8 *)PTR_PTR_1403e1d60;

        while (puVar12 != (undefined8 *)0x0) {

          sVar10 = strlen((char *)puVar12[1]);

          if ((sVar16 == sVar10) && (iVar3 = FUN_14012f260(puVar12[1],pcVar17,sVar16), iVar3 == 0))

          {

            if (pcVar8 != (char *)0x0) {

              FUN_1401841e0(pcVar8);

              pcVar8 = (char *)0x0;

            }

            cVar2 = (*(code *)*puVar12)(lVar7,lVar5,(int)param_1);

            if (cVar2 != '\0') break;

            uVar9 = FUN_14012e730();

            pcVar8 = (char *)FUN_14012f0d0(uVar9);

            FUN_14012e2e0(6,"Couldn\'t create renderer %s: %s\n",puVar12[1],pcVar8);

            FUN_14014da10(lVar7);

            FUN_1402f94c0(lVar7,0,0x2f0);

          }

          lVar15 = lVar15 + 1;

          puVar12 = (undefined8 *)(&PTR_PTR_1403e1d60)[lVar15];

        }

        if ((lVar11 == 0) || (pcVar17 = (char *)(lVar11 + 1), (char *)(lVar11 + 1) == (char *)0x0))

        break;

      }

LAB_14014c305:

      if (cVar2 != '\0') {

        FUN_1401aa7a0("render",*(undefined8 *)(lVar7 + 0x100));

        FUN_1401841e0(pcVar8);

        *(longlong *)(lVar7 + 0x118) = lVar5;

        uVar9 = FUN_140179a30();

        *(undefined8 *)(lVar7 + 0x1f8) = uVar9;

        goto LAB_14014c344;

      }

    }

    if (local_res10 == (char *)0x0) {

      FUN_14012e850("Couldn\'t find matching render driver");

    }

    else {

      pcVar14 = "%s";

      pcVar17 = pcVar8;

      if (pcVar8 == (char *)0x0) {

        pcVar14 = "%s not available";

        pcVar17 = local_res10;

      }

      FUN_14012e850(pcVar14,pcVar17);

    }

    FUN_1401841e0(pcVar8);

LAB_14014c683:

    FUN_14014db70(lVar7);

    return 0;

  }

  cVar2 = FUN_140200370(lVar7,lVar6,param_1 & 0xffffffff);

  if (cVar2 == '\0') goto LAB_14014c683;

  *(longlong *)(lVar7 + 0x118) = lVar5;

  uVar9 = FUN_140179a30();

  *(undefined8 *)(lVar7 + 0x1f8) = uVar9;

  *(undefined4 *)(lVar7 + 0x140) = *(undefined4 *)(lVar6 + 8);

  *(undefined4 *)(lVar7 + 0x144) = *(undefined4 *)(lVar6 + 0xc);

LAB_14014c344:

  lVar11 = lVar7 + 0x140;

  *(undefined8 *)(lVar7 + 0x150) = 0xffffffffffffffff;

  *(undefined4 *)(lVar7 + 0x18c) = 0x3f800000;

  *(undefined4 *)(lVar7 + 400) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x1c0) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x1c4) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x1d0) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x1d4) = 0x3f800000;

  *(longlong *)(lVar7 + 0x138) = lVar11;

  *(undefined4 *)(lVar7 + 0x1d8) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x1dc) = 0x3f800000;

  FUN_140156e80(lVar7,lVar11);

  FUN_140156de0(lVar7,lVar11);

  FUN_140156d10(lVar7);

  lVar11 = FUN_1401aaee0(0,0,FUN_1401ab0a0,&LAB_1401aa9c0,&LAB_1401aafe0,0);

  *(longlong *)(lVar7 + 0x200) = lVar11;

  if (lVar11 == 0) goto LAB_14014c683;

  *(undefined4 *)(lVar7 + 600) = 1;

  if (*(char *)(lVar7 + 0x114) == '\0') {

    uVar4 = FUN_14014e570();

  }

  else {

    uVar4 = 1;

  }

  *(undefined4 *)(lVar7 + 0x1e0) = uVar4;

  *(undefined4 *)(lVar7 + 0x1e4) = 1;

  *(undefined4 *)(lVar7 + 0x20c) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x210) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x214) = 0x3f800000;

  *(undefined4 *)(lVar7 + 0x218) = 0x3f800000;

  if (lVar5 == 0) {

LAB_14014c510:

    uVar4 = FUN_14014f090(lVar7);

    FUN_140175500(uVar4,"SDL.renderer.name",*(undefined8 *)(lVar7 + 0x100));

    if (lVar5 == 0) goto LAB_14014c545;

  }

  else {

    uVar13 = FUN_14016e130(lVar5);

    if ((uVar13 >> 0x1e & 1) != 0) {

      *(undefined1 *)(lVar7 + 0x2b0) = 1;

    }

    uVar13 = FUN_14016e130(lVar5);

    if ((uVar13 & 0x48) == 0) goto LAB_14014c510;

    *(undefined1 *)(lVar7 + 0x120) = 1;

    uVar4 = FUN_14014f090(lVar7);

    FUN_140175500(uVar4,"SDL.renderer.name",*(undefined8 *)(lVar7 + 0x100));

  }

  FUN_140175480(uVar4,"SDL.renderer.window",lVar5);

LAB_14014c545:

  if (lVar6 != 0) {

    FUN_140175480(uVar4,"SDL.renderer.surface",lVar6);

  }

  FUN_140175360(uVar4,"SDL.renderer.output_colorspace",(longlong)*(int *)(lVar7 + 0x208));

  FUN_140175280(uVar4,"SDL.renderer.texture_wrapping",*(char *)(lVar7 + 0x115) == '\0');

  if (lVar5 == 0) {

    FUN_140154e20(lVar7,0);

  }

  else {

    FUN_140156860();

    uVar4 = FUN_14016ea50(lVar5);

    FUN_140175480(uVar4,"SDL.internal.window.renderer",lVar7);

    FUN_14016a2a0(lVar5,lVar7);

    FUN_140154e20(lVar7,0);

    FUN_1401cd9b0(1,FUN_1401537c0,lVar7);

  }

  uVar9 = FUN_140174c40(param_1 & 0xffffffff,"SDL.renderer.create.present_vsync",0);

  FUN_140154cf0(lVar7,uVar9);

  FUN_14014ba40(lVar7,lVar5);

  FUN_14012e0e0(6,"Created renderer: %s",*(undefined8 *)(lVar7 + 0x100));

  *(longlong *)(lVar7 + 0x2e8) = DAT_1403fc050;

  DAT_1403fc050 = lVar7;

  FUN_14012e710();

  return lVar7;

}




