// Address: 0x14014cfa0
// Ghidra name: FUN_14014cfa0
// ============ 0x14014cfa0 FUN_14014cfa0 (size=2119) ============


uint * FUN_14014cfa0(longlong param_1,undefined4 param_2)



{

  char cVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  undefined4 uVar7;

  int iVar8;

  uint uVar9;

  longlong lVar10;

  uint *puVar11;

  undefined8 uVar12;

  uint uVar13;

  longlong lVar14;

  bool bVar15;

  undefined4 extraout_XMM0_Da;

  

  uVar2 = FUN_140174c40(param_2,"SDL.texture.create.format",0);

  uVar3 = FUN_140174c40(param_2,"SDL.texture.create.access",0);

  uVar4 = FUN_140174c40(param_2,"SDL.texture.create.width",0);

  uVar5 = FUN_140174c40(param_2,"SDL.texture.create.height",0);

  lVar10 = FUN_140174d30(param_2,"SDL.texture.create.palette",0);

  if ((param_1 == 0) ||

     ((uVar13 = 2, DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return (uint *)0x0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return (uint *)0x0;

  }

  if (((uVar2 == 0) && (uVar2 = **(uint **)(param_1 + 0x108), uVar2 == 0)) ||

     ((uVar2 & 0xf0000000) == 0x10000000)) {

    uVar6 = uVar2 & 0xff;

LAB_14014d0bb:

    if (uVar6 == 0) {

      FUN_14012e850("Invalid texture format");

      return (uint *)0x0;

    }

    if (((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) &&

       (((uVar6 = uVar2 & 0xf000000, uVar6 == 0x1000000 ||

         (((uVar6 == 0xc000000 || (uVar6 == 0x2000000)) || (uVar6 == 0x3000000)))) && (uVar3 == 2)))

       ) {

      FUN_14012e850("Palettized textures can\'t be render targets");

      return (uint *)0x0;

    }

  }

  else if (((uVar2 == 0x32595559) || (uVar2 == 0x59565955)) ||

          ((uVar2 == 0x55595659 || (uVar2 == 0x30313050)))) {

    uVar6 = 2;

    goto LAB_14014d0bb;

  }

  if (((int)uVar4 < 1) || ((int)uVar5 < 1)) {

    FUN_14012e850("Texture dimensions can\'t be 0");

    return (uint *)0x0;

  }

  uVar7 = FUN_14014f090(param_1);

  iVar8 = FUN_140174c40(uVar7,"SDL.renderer.max_texture_size",0);

  if ((iVar8 != 0) && ((iVar8 < (int)uVar4 || (iVar8 < (int)uVar5)))) {

    FUN_14012e850("Texture dimensions are limited to %dx%d",iVar8,iVar8);

    return (uint *)0x0;

  }

  iVar8 = FUN_14017a4b0(uVar2);

  puVar11 = (uint *)FUN_1401841a0(1,0x150);

  if (puVar11 == (uint *)0x0) {

LAB_14014d79f:

    puVar11 = (uint *)0x0;

  }

  else {

    puVar11[3] = 1;

    FUN_1401aa9d0(puVar11,3,1);

    uVar6 = FUN_140174c40(param_2,"SDL.texture.create.colorspace",(longlong)iVar8);

    puVar11[6] = uVar6;

    puVar11[9] = uVar3;

    *puVar11 = uVar2;

    puVar11[1] = uVar4;

    puVar11[2] = uVar5;

    puVar11[0xc] = 0x3f800000;

    puVar11[0xd] = 0x3f800000;

    puVar11[0xe] = 0x3f800000;

    puVar11[0xf] = 0x3f800000;

    if (uVar2 == 0) {

LAB_14014d238:

      if (((uVar2 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_14014d267:

        if (uVar2 != 0) goto LAB_14014d26b;

        goto LAB_14014d279;

      }

LAB_14014d244:

      uVar6 = uVar2 & 0xf00000;

      if ((((uVar6 != 0x300000) && (uVar6 != 0x400000)) && (uVar6 != 0x700000)) &&

         (uVar6 != 0x800000)) goto LAB_14014d267;

LAB_14014d2ba:

      uVar6 = 1;

    }

    else {

      if ((uVar2 & 0xf0000000) == 0x10000000) {

        if ((uVar2 & 0xf000000) != 0x4000000) goto LAB_14014d238;

        goto LAB_14014d244;

      }

LAB_14014d26b:

      if ((uVar2 & 0xf0000000) == 0x10000000) {

LAB_14014d279:

        if ((((uVar2 & 0xf000000) == 0x7000000) ||

            (((uVar2 & 0xf000000) + 0xf8000000 & 0xfcffffff) == 0)) &&

           (((uVar6 = uVar2 & 0xf00000, uVar6 == 0x300000 ||

             ((uVar6 == 0x200000 || (uVar6 == 0x600000)))) || (uVar6 == 0x500000))))

        goto LAB_14014d2ba;

      }

      uVar6 = 0;

    }

    puVar11[10] = uVar6;

    puVar11[0xb] = *(uint *)(param_1 + 0x1e4);

    puVar11[0x10] = uVar4;

    puVar11[0x11] = uVar5;

    puVar11[0x14] = 0xffffffff;

    puVar11[0x15] = 0xffffffff;

    puVar11[0x23] = 0x3f800000;

    puVar11[0x24] = 0x3f800000;

    puVar11[0x30] = 0x3f800000;

    puVar11[0x31] = 0x3f800000;

    puVar11[0x34] = 0x3f800000;

    puVar11[0x35] = 0x3f800000;

    *(longlong *)(puVar11 + 4) = param_1;

    *(undefined8 *)(puVar11 + 0x52) = *(undefined8 *)(param_1 + 0x1e8);

    if (*(longlong *)(param_1 + 0x1e8) != 0) {

      *(uint **)(*(longlong *)(param_1 + 0x1e8) + 0x140) = puVar11;

    }

    *(uint **)(param_1 + 0x1e8) = puVar11;

    FUN_140156e80(param_1,puVar11 + 0x10);

    FUN_140156de0(param_1,puVar11 + 0x10);

    uVar7 = FUN_140146560(puVar11[6]);

    uVar6 = FUN_140174af0(param_2,"SDL.texture.create.SDR_white_point",uVar7);

    puVar11[7] = uVar6;

    uVar7 = FUN_140146550(puVar11[6]);

    uVar6 = FUN_140174af0(param_2,"SDL.texture.create.HDR_headroom",uVar7);

    puVar11[8] = uVar6;

    if (((uVar3 == 2) && (uVar2 != 0)) && ((uVar2 & 0xf0000000) != 0x10000000)) {

      uVar7 = FUN_1401746e0();

      iVar8 = **(int **)(param_1 + 0x108);

LAB_14014d3fb:

      if ((uVar2 == 0x47504a4d) && (iVar8 == 0x3231564e)) {

        lVar14 = 0x220004c6;

      }

      else {

        uVar9 = FUN_14017a4b0(iVar8);

        uVar6 = puVar11[6];

        lVar14 = (longlong)(int)uVar6;

        if ((((int)(uVar6 ^ uVar9) >> 0x1c & 0xfU) != 0) || (((uVar6 ^ uVar9) & 0x3e0) != 0)) {

          lVar14 = (longlong)(int)uVar9;

        }

      }

      FUN_140175360(uVar7,"SDL.texture.create.colorspace",lVar14);

      FUN_140175360(uVar7,"SDL.texture.create.format",(longlong)iVar8);

      uVar6 = *puVar11;

      if (((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) &&

         ((uVar6 = uVar6 & 0xf000000, uVar6 == 0x1000000 ||

          (((uVar6 == 0xc000000 || (uVar6 == 0x2000000)) || (uVar6 == 0x3000000)))))) {

        lVar14 = 1;

      }

      else {

        lVar14 = (longlong)(int)puVar11[9];

      }

      FUN_140175360(uVar7,"SDL.texture.create.access",lVar14);

      FUN_140175360(uVar7,"SDL.texture.create.width",(longlong)(int)puVar11[1]);

      FUN_140175360(uVar7,"SDL.texture.create.height",(longlong)(int)puVar11[2]);

      uVar12 = FUN_14014cfa0(param_1,uVar7);

      *(undefined8 *)(puVar11 + 0x3e) = uVar12;

      FUN_1401747e0(uVar7);

      if (*(longlong *)(puVar11 + 0x3e) == 0) goto LAB_14014d797;

      uVar7 = FUN_14014f530();

      FUN_140175480(uVar7,"SDL.internal.texture.parent",puVar11);

      *(undefined8 *)(*(longlong *)(puVar11 + 0x3e) + 0x148) = *(undefined8 *)(puVar11 + 0x52);

      lVar14 = *(longlong *)(*(longlong *)(puVar11 + 0x3e) + 0x148);

      if (lVar14 != 0) {

        *(longlong *)(lVar14 + 0x140) = *(longlong *)(puVar11 + 0x3e);

      }

      lVar14 = *(longlong *)(*(longlong *)(puVar11 + 0x3e) + 0x140);

      *(longlong *)(puVar11 + 0x50) = lVar14;

      if (lVar14 != 0) {

        *(uint **)(lVar14 + 0x148) = puVar11;

      }

      *(uint **)(*(longlong *)(puVar11 + 0x3e) + 0x140) = puVar11;

      *(undefined8 *)(puVar11 + 0x52) = *(undefined8 *)(puVar11 + 0x3e);

      *(uint **)(param_1 + 0x1e8) = puVar11;

      FUN_1401553b0(*(undefined8 *)(puVar11 + 0x3e),puVar11[0xb]);

      uVar6 = *puVar11;

      if (uVar6 != 0x47504a4d) {

        if (uVar6 == 0) {

LAB_14014d6fe:

          uVar9 = uVar6 & 0xf000000;

          if (((uVar9 != 0xc000000) && (uVar9 != 0x2000000)) && (uVar9 != 0x3000000)) {

            if (uVar3 == 1) {

              if ((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) {

                uVar13 = uVar2 & 0xff;

              }

              else if ((((uVar2 != 0x32595559) && (uVar2 != 0x59565955)) && (uVar2 != 0x55595659))

                      && (uVar2 != 0x30313050)) {

                uVar13 = 1;

              }

              uVar2 = uVar13 * uVar4 + 3 & 0xfffffffc;

              puVar11[0x44] = uVar2;

              lVar14 = FUN_1401841a0(1,(longlong)(int)uVar2 * (longlong)(int)uVar5);

              *(longlong *)(puVar11 + 0x42) = lVar14;

              goto LAB_14014d5f7;

            }

            goto LAB_14014d600;

          }

LAB_14014d5e2:

          lVar14 = FUN_140145e60(uVar4,uVar5,uVar6);

          *(longlong *)(puVar11 + 0x3c) = lVar14;

        }

        else {

          if (((byte)((int)uVar6 >> 0x1c) & 0xf) == 1) {

            if ((uVar6 & 0xf000000) != 0x1000000) goto LAB_14014d6fe;

            goto LAB_14014d5e2;

          }

          lVar14 = FUN_140205bd0(uVar6,puVar11[6],uVar4,uVar5);

          *(longlong *)(puVar11 + 0x40) = lVar14;

        }

LAB_14014d5f7:

        bVar15 = lVar14 == 0;

        goto LAB_14014d5fa;

      }

    }

    else {

      cVar1 = FUN_14014a400(param_1,uVar2);

      if (cVar1 == '\0') {

        uVar7 = FUN_1401746e0();

        iVar8 = FUN_140149de0(param_1,uVar2);

        goto LAB_14014d3fb;

      }

      cVar1 = (**(code **)(param_1 + 0x18))(extraout_XMM0_Da,puVar11,param_2);

      bVar15 = cVar1 == '\0';

LAB_14014d5fa:

      if (bVar15) {

LAB_14014d797:

        FUN_14014dd50(puVar11);

        goto LAB_14014d79f;

      }

    }

LAB_14014d600:

    uVar2 = *puVar11;

    if (((uVar2 == 0) || ((uVar2 & 0xf0000000) == 0x10000000)) &&

       ((((uVar2 = uVar2 & 0xf000000, uVar2 == 0x1000000 ||

          ((uVar2 == 0xc000000 || (uVar2 == 0x2000000)))) || (uVar2 == 0x3000000)) && (lVar10 != 0))

       )) {

      FUN_140155130(puVar11,lVar10);

    }

    uVar7 = FUN_14014f530(puVar11);

    FUN_140175360(uVar7,"SDL.texture.colorspace",(longlong)(int)puVar11[6]);

    FUN_140175360(uVar7,"SDL.texture.format",(longlong)(int)*puVar11);

    FUN_140175360(uVar7,"SDL.texture.access",(longlong)(int)puVar11[9]);

    FUN_140175360(uVar7,"SDL.texture.width",(longlong)(int)puVar11[1]);

    FUN_140175360(uVar7,"SDL.texture.height",(longlong)(int)puVar11[2]);

    FUN_1401752f0(uVar7,"SDL.texture.SDR_white_point",puVar11[7]);

    if (0.0 < (float)puVar11[8]) {

      FUN_1401752f0(uVar7,"SDL.texture.HDR_headroom");

    }

  }

  return puVar11;

}




