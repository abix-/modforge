// Address: 0x14014c790
// Ghidra name: FUN_14014c790
// ============ 0x14014c790 FUN_14014c790 (size=2056) ============


longlong FUN_14014c790(longlong param_1,longlong param_2)



{

  char cVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  undefined4 uVar6;

  int *piVar7;

  uint *puVar8;

  longlong lVar9;

  char cVar10;

  int iVar11;

  char *pcVar12;

  char cVar13;

  char cVar14;

  undefined4 uVar15;

  char local_res8 [8];

  

  if ((param_1 == 0) ||

     ((uVar5 = 2, DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(), cVar1 == '\0')))) {

    pcVar12 = "renderer";

LAB_14014cf80:

    FUN_14012e850("Parameter \'%s\' is invalid",pcVar12);

    return 0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return 0;

  }

  cVar1 = FUN_1401489c0(param_2);

  if (cVar1 == '\0') {

    pcVar12 = "SDL_CreateTextureFromSurface(): surface";

    goto LAB_14014cf80;

  }

  uVar3 = *(uint *)(param_2 + 4);

  if (uVar3 == 0) {

LAB_14014c83a:

    if (((uVar3 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_14014c879:

      if (uVar3 != 0) goto LAB_14014c87d;

      goto LAB_14014c88b;

    }

LAB_14014c846:

    uVar2 = uVar3 & 0xf00000;

    if ((((uVar2 != 0x300000) && (uVar2 != 0x400000)) && (uVar2 != 0x700000)) && (uVar2 != 0x800000)

       ) goto LAB_14014c879;

LAB_14014c97a:

    if (0 < *(int *)(param_1 + 0x110)) {

      uVar3 = *(uint *)(param_2 + 4);

      puVar8 = *(uint **)(param_1 + 0x108);

      lVar9 = 0;

      do {

        if (*puVar8 == uVar3) {

          if (uVar3 != 0) goto LAB_14014cddd;

          break;

        }

        lVar9 = lVar9 + 1;

        puVar8 = puVar8 + 1;

      } while (lVar9 < *(int *)(param_1 + 0x110));

    }

LAB_14014c9b1:

    uVar3 = *(uint *)(param_2 + 4);

    if (uVar3 != 0) goto LAB_14014c9bd;

  }

  else {

    if ((uVar3 & 0xf0000000) == 0x10000000) {

      if ((uVar3 & 0xf000000) != 0x4000000) goto LAB_14014c83a;

      goto LAB_14014c846;

    }

LAB_14014c87d:

    if ((uVar3 & 0xf0000000) == 0x10000000) {

LAB_14014c88b:

      uVar3 = *(uint *)(param_2 + 4) & 0xf000000;

      if (((uVar3 == 0x7000000) || ((uVar3 + 0xf8000000 & 0xfcffffff) == 0)) &&

         (((uVar3 = *(uint *)(param_2 + 4) & 0xf00000, uVar3 == 0x300000 ||

           ((uVar3 == 0x200000 || (uVar3 == 0x600000)))) || (uVar3 == 0x500000))))

      goto LAB_14014c97a;

    }

    cVar1 = FUN_140148960();

    if (cVar1 == '\0') goto LAB_14014c97a;

    if (*(int *)(param_2 + 4) != 0x16161804) {

      if ((*(int *)(param_2 + 4) == 0x16561804) && (0 < *(int *)(param_1 + 0x110))) {

        lVar9 = 0;

        piVar7 = *(int **)(param_1 + 0x108);

        uVar3 = 0x16762004;

        do {

          if (*piVar7 == 0x16762004) goto LAB_14014cddd;

          lVar9 = lVar9 + 1;

          piVar7 = piVar7 + 1;

        } while (lVar9 < *(int *)(param_1 + 0x110));

        uVar3 = *(uint *)(param_2 + 4);

        goto LAB_14014c9bd;

      }

      goto LAB_14014c9b1;

    }

    if (*(int *)(param_1 + 0x110) < 1) goto LAB_14014c9b1;

    lVar9 = 0;

    piVar7 = *(int **)(param_1 + 0x108);

    uVar3 = 0x16362004;

    do {

      if (*piVar7 == 0x16362004) goto LAB_14014cddd;

      lVar9 = lVar9 + 1;

      piVar7 = piVar7 + 1;

    } while (lVar9 < *(int *)(param_1 + 0x110));

    uVar3 = *(uint *)(param_2 + 4);

LAB_14014c9bd:

    if ((((uVar3 & 0xf0000000) == 0x10000000) && ((uVar3 & 0xf000000) == 0x6000000)) &&

       ((uVar3 & 0xf0000) == 0x70000)) {

      iVar11 = 0;

      if (0 < *(int *)(param_1 + 0x110)) {

        puVar8 = *(uint **)(param_1 + 0x108);

        do {

          uVar3 = *puVar8;

          if (((uVar3 != 0) && ((uVar3 & 0xf0000000) == 0x10000000)) &&

             (((uVar3 & 0xf000000) == 0x6000000 && ((uVar3 & 0xf0000) == 0x70000)))) {

            uVar3 = *(uint *)(*(longlong *)(param_1 + 0x108) + (longlong)iVar11 * 4);

            if (uVar3 != 0) goto LAB_14014cddd;

            break;

          }

          iVar11 = iVar11 + 1;

          puVar8 = puVar8 + 1;

        } while (iVar11 < *(int *)(param_1 + 0x110));

      }

    }

  }

  uVar3 = *(uint *)(param_2 + 4);

  if (uVar3 == 0) {

LAB_14014caa7:

    if ((uVar3 & 0xf000000) == 0xb000000) {

LAB_14014caaf:

      uVar3 = 0;

      if (0 < *(int *)(param_1 + 0x110)) {

        puVar8 = *(uint **)(param_1 + 0x108);

        do {

          uVar2 = *puVar8;

          if (((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) &&

             (((uVar2 & 0xf000000) == 0xa000000 || ((uVar2 & 0xf000000) == 0xb000000)))) {

            uVar3 = *(uint *)(*(longlong *)(param_1 + 0x108) + (ulonglong)uVar3 * 4);

            if (uVar3 != 0) goto LAB_14014cddd;

            break;

          }

          uVar3 = uVar3 + 1;

          puVar8 = puVar8 + 1;

        } while ((int)uVar3 < *(int *)(param_1 + 0x110));

      }

    }

  }

  else if (((int)uVar3 >> 0x1c & 0xfU) == 1) {

    if ((((uVar3 & 0xf000000) != 0x6000000) || ((uVar3 & 0xf0000) != 0x70000)) &&

       ((uVar3 & 0xf000000) != 0xa000000)) goto LAB_14014caa7;

    goto LAB_14014caaf;

  }

  uVar2 = *(uint *)(param_2 + 4);

  uVar3 = **(uint **)(param_1 + 0x108);

  if (uVar2 == 0) {

LAB_14014cb47:

    if (((uVar2 & 0xf000000) != 0x5000000) && ((uVar2 & 0xf000000) != 0x6000000)) {

LAB_14014cb83:

      if (uVar2 != 0) goto LAB_14014cb87;

      goto LAB_14014cb95;

    }

LAB_14014cb5d:

    uVar4 = uVar2 & 0xf00000;

    if ((uVar4 != 0x300000) && (((uVar4 != 0x400000 && (uVar4 != 0x700000)) && (uVar4 != 0x800000)))

       ) goto LAB_14014cb83;

LAB_14014cbe5:

    cVar1 = '\x01';

  }

  else {

    if ((uVar2 & 0xf0000000) == 0x10000000) {

      if ((uVar2 & 0xf000000) != 0x4000000) goto LAB_14014cb47;

      goto LAB_14014cb5d;

    }

LAB_14014cb87:

    if ((uVar2 & 0xf0000000) == 0x10000000) {

LAB_14014cb95:

      if ((((uVar2 & 0xf000000) == 0x7000000) ||

          (((uVar2 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

         (((uVar2 = uVar2 & 0xf00000, uVar2 == 0x300000 ||

           ((uVar2 == 0x200000 || (uVar2 == 0x600000)))) || (uVar2 == 0x500000))))

      goto LAB_14014cbe5;

    }

    cVar1 = FUN_140148960(param_2);

    if (cVar1 != '\0') goto LAB_14014cbe5;

    cVar1 = '\0';

  }

  cVar13 = '\x01';

  if ((*(longlong *)(param_2 + 0x48) != 0) &&

     (FUN_14017a120(*(longlong *)(param_2 + 0x48),local_res8), local_res8[0] == '\0')) {

    cVar1 = '\x01';

  }

  uVar2 = *(uint *)(param_2 + 4);

  if ((((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) &&

      ((uVar2 = uVar2 & 0xf000000, uVar2 == 0x1000000 ||

       (((uVar2 == 0xc000000 || (uVar2 == 0x2000000)) || (uVar2 == 0x3000000)))))) &&

     (cVar1 == '\0')) {

    cVar14 = '\x01';

  }

  else {

    cVar14 = '\0';

  }

  if ((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) {

    uVar5 = uVar3 & 0xff;

  }

  else if (((uVar3 != 0x32595559) && (uVar3 != 0x59565955)) &&

          ((uVar3 != 0x55595659 && (uVar3 != 0x30313050)))) {

    uVar5 = 1;

  }

  iVar11 = 0;

  if (0 < *(int *)(param_1 + 0x110)) {

    puVar8 = *(uint **)(param_1 + 0x108);

    do {

      uVar2 = *puVar8;

      if (((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) && ((uVar2 & 0xff) == uVar5)) {

        cVar10 = cVar13;

        if ((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) {

          if ((((uVar2 & 0xf000000) != 0x4000000) &&

              (((uVar2 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0)) ||

             ((((uVar4 = uVar2 & 0xf00000, uVar4 != 0x300000 && (uVar4 != 0x400000)) &&

               (uVar4 != 0x700000)) && (uVar4 != 0x800000)))) {

            if (uVar2 != 0) goto LAB_14014cd23;

            goto LAB_14014cd31;

          }

        }

        else {

LAB_14014cd23:

          if ((uVar2 & 0xf0000000) == 0x10000000) {

LAB_14014cd31:

            if ((((uVar2 & 0xf000000) == 0x7000000) ||

                (((uVar2 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

               ((uVar4 = uVar2 & 0xf00000, uVar4 == 0x300000 ||

                (((uVar4 == 0x200000 || (uVar4 == 0x600000)) || (uVar4 == 0x500000))))))

            goto LAB_14014cd74;

          }

          cVar10 = '\0';

        }

LAB_14014cd74:

        if (cVar10 == cVar1) {

          if (((uVar2 != 0) && ((uVar2 & 0xf0000000) != 0x10000000)) ||

             (((uVar2 = uVar2 & 0xf000000, cVar10 = cVar13, uVar2 != 0x1000000 &&

               ((uVar2 != 0xc000000 && (uVar2 != 0x2000000)))) && (uVar2 != 0x3000000)))) {

            cVar10 = '\0';

          }

          if (cVar10 == cVar14) {

            uVar3 = *(uint *)(*(longlong *)(param_1 + 0x108) + (longlong)iVar11 * 4);

            break;

          }

        }

      }

      iVar11 = iVar11 + 1;

      puVar8 = puVar8 + 1;

    } while (iVar11 < *(int *)(param_1 + 0x110));

  }

LAB_14014cddd:

  uVar5 = FUN_140146870(param_2);

  if ((uVar5 != 0x12000500) && (uVar2 = uVar5, (uVar5 & 0x3e0) != 0x200)) goto LAB_14014ce31;

  if (uVar3 == 0) {

LAB_14014cf1f:

    if ((uVar3 & 0xf000000) == 0xb000000) {

LAB_14014ce2c:

      uVar2 = 0x12000500;

      goto LAB_14014ce31;

    }

    if ((((uVar3 != 0) && ((uVar3 & 0xf0000000) == 0x10000000)) &&

        ((uVar3 & 0xf000000) == 0x6000000)) && ((uVar3 & 0xf0000) == 0x70000)) {

      uVar2 = 0x12002600;

      goto LAB_14014ce31;

    }

  }

  else if ((uVar3 & 0xf0000000) == 0x10000000) {

    if ((uVar3 & 0xf000000) != 0xa000000) goto LAB_14014cf1f;

    goto LAB_14014ce2c;

  }

  uVar2 = 0x120005a0;

LAB_14014ce31:

  uVar6 = FUN_1401746e0();

  FUN_140175360(uVar6,"SDL.texture.create.colorspace",(longlong)(int)uVar2);

  if (uVar5 == uVar2) {

    uVar15 = FUN_140146c10(param_2,uVar5);

    FUN_1401752f0(uVar6,"SDL.texture.create.SDR_white_point",uVar15);

  }

  uVar15 = FUN_1401468a0(param_2,uVar5);

  FUN_1401752f0(uVar6,"SDL.texture.create.HDR_headroom",uVar15);

  FUN_140175360(uVar6,"SDL.texture.create.format",(longlong)(int)uVar3);

  FUN_140175360(uVar6,"SDL.texture.create.access",0);

  FUN_140175360(uVar6,"SDL.texture.create.width",(longlong)*(int *)(param_2 + 8));

  FUN_140175360(uVar6,"SDL.texture.create.height",(longlong)*(int *)(param_2 + 0xc));

  lVar9 = FUN_14014cfa0(param_1,uVar6);

  FUN_1401747e0(uVar6);

  if (lVar9 == 0) {

    return 0;

  }

  cVar1 = FUN_140155990(lVar9,0,param_2);

  if (cVar1 != '\0') {

    return lVar9;

  }

  FUN_14014dd50(lVar9);

  return 0;

}




