// Address: 0x1401f0a40
// Ghidra name: FUN_1401f0a40
// ============ 0x1401f0a40 FUN_1401f0a40 (size=2313) ============


ulonglong FUN_1401f0a40(longlong param_1,uint *param_2,undefined4 param_3)



{

  longlong lVar1;

  float fVar2;

  char cVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  int *piVar6;

  ulonglong uVar7;

  undefined8 uVar8;

  uint uVar9;

  int iVar10;

  char cVar11;

  int iVar12;

  uint *puVar13;

  longlong lVar14;

  int iVar15;

  uint *puVar16;

  int local_res8;

  uint *local_res10;

  uint *local_res20;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401f0320();

  uVar8 = 0;

  *(undefined8 *)(lVar1 + 0x278) = 0;

  uVar9 = *param_2;

  if ((int)uVar9 < 0x20534550) {

    if (uVar9 == 0x2053454f) {

      if (*(char *)(lVar1 + 9) == '\0') goto LAB_1401f0b56;

      iVar12 = 0;

      iVar10 = 0;

      goto LAB_1401f0b8d;

    }

    if (uVar9 == 0x13000801) goto LAB_1401f0b6f;

    if (((uVar9 != 0x16161804) && (uVar9 != 0x16362004)) &&

       ((uVar9 != 0x16561804 && (uVar9 != 0x16762004)))) goto LAB_1401f0b56;

    iVar15 = 0x1908;

    local_res8 = 0x1401;

  }

  else {

    if ((((uVar9 != 0x3132564e) && (uVar9 != 0x3231564e)) && (uVar9 != 0x32315659)) &&

       (uVar9 != 0x56555949)) {

LAB_1401f0b56:

      uVar7 = FUN_14012e850("Texture format not supported");

      return uVar7;

    }

LAB_1401f0b6f:

    iVar12 = 0x1401;

    iVar15 = 0x1909;

    local_res8 = 0x1401;

    iVar10 = 0x1909;

    if (uVar9 == 0x2053454f) {

LAB_1401f0b8d:

      iVar15 = iVar10;

      local_res8 = iVar12;

      if (param_2[9] != 0) {

        uVar7 = FUN_14012e850("Unsupported texture access for SDL_PIXELFORMAT_EXTERNAL_OES");

        return uVar7;

      }

    }

  }

  piVar6 = (int *)FUN_1401841a0(1);

  uVar7 = 0;

  if (piVar6 == (int *)0x0) goto LAB_1401f0c9b;

  *piVar6 = 0;

  uVar9 = *param_2;

  piVar6[3] = iVar15;

  iVar10 = 0xde1;

  if (uVar9 == 0x2053454f) {

    iVar10 = 0x8d65;

  }

  piVar6[4] = local_res8;

  piVar6[2] = iVar10;

  if ((*param_2 == 0x56555949) || (*param_2 == 0x32315659)) {

    cVar3 = '\x01';

  }

  else {

    cVar3 = '\0';

  }

  *(char *)(piVar6 + 9) = cVar3;

  if ((*param_2 == 0x3231564e) || (*param_2 == 0x3132564e)) {

    cVar11 = '\x01';

  }

  else {

    cVar11 = '\0';

  }

  *(char *)((longlong)piVar6 + 0x25) = cVar11;

  piVar6[0x12] = param_2[0xb];

  piVar6[0x13] = 1;

  piVar6[0x14] = 1;

  if (param_2[9] == 1) {

    uVar9 = *param_2;

    if ((uVar9 == 0) || ((uVar9 & 0xf0000000) == 0x10000000)) {

      uVar9 = uVar9 & 0xff;

    }

    else if ((((uVar9 == 0x32595559) || (uVar9 == 0x59565955)) || (uVar9 == 0x55595659)) ||

            (uVar9 == 0x30313050)) {

      uVar9 = 2;

    }

    else {

      uVar9 = 1;

    }

    iVar10 = uVar9 * param_2[1];

    piVar6[8] = iVar10;

    lVar14 = (longlong)(int)param_2[2] * (longlong)iVar10;

    if ((cVar3 != '\0') || (cVar11 != '\0')) {

      lVar14 = lVar14 + ((iVar10 + 1) / 2) * ((int)(param_2[2] + 1) / 2) * 2;

    }

    lVar14 = FUN_1401841a0(1,lVar14);

    *(longlong *)(piVar6 + 6) = lVar14;

    if (lVar14 != 0) goto LAB_1401f0cbd;

  }

  else {

LAB_1401f0cbd:

    puVar16 = param_2 + 1;

    puVar13 = param_2 + 2;

    uVar5 = 1;

    FUN_1401f4660(&DAT_14039bcb9,param_1,"SDL_render_gles2.c",0x73a,"GLES2_CreateTexture");

    fVar2 = DAT_14039ca44;

    piVar6[0xe] = (int)(DAT_14039ca44 / (float)(int)*puVar16);

    piVar6[0xf] = (int)(fVar2 / (float)(int)*puVar13);

    piVar6[0x10] = (int)(float)(int)*puVar16;

    piVar6[0x11] = (int)(float)(int)*puVar13;

    if ((char)piVar6[9] == '\0') {

      if (*(char *)((longlong)piVar6 + 0x25) != '\0') {

        iVar10 = FUN_140174c40(param_3,"SDL.texture.create.opengles2.texture_uv",0);

        piVar6[0xc] = iVar10;

        if (iVar10 == 0) {

          (**(code **)(lVar1 + 0xb8))(1,piVar6 + 0xc);

          uVar5 = 1;

          cVar3 = FUN_1401f4660("glGenTexures()",param_1,"SDL_render_gles2.c",0x77c,

                                "GLES2_CreateTexture");

          if (cVar3 == '\0') goto LAB_1401f0daa;

        }

        else {

          piVar6[0xd] = 1;

        }

        (**(code **)(lVar1 + 0x10))(0x84c1);

        (**(code **)(lVar1 + 0x28))(piVar6[2],piVar6[0xc]);

        (**(code **)(lVar1 + 0x128))

                  (piVar6[2],0,0x190a,(int)(*puVar16 + 1) / 2,

                   CONCAT44(uVar5,(int)(*puVar13 + 1) / 2),0,0x190a,0x1401,0);

        uVar5 = 1;

        cVar3 = FUN_1401f4660("glTexImage2D()",param_1,"SDL_render_gles2.c",0x785,

                              "GLES2_CreateTexture");

        if (cVar3 == '\0') goto LAB_1401f0daa;

        FUN_1401f4ff0(lVar1,piVar6[2],*param_2,piVar6[0x12]);

        FUN_1401f4f90(lVar1,piVar6[2],piVar6[0x13],piVar6[0x14]);

        iVar10 = piVar6[0xc];

        uVar4 = FUN_14014f530(param_2);

        FUN_140175360(uVar4,"SDL.texture.opengles2.texture_uv",iVar10);

        lVar14 = FUN_14017b8d0(param_2[6],*puVar16,param_2[2],8);

joined_r0x0001401f11a9:

        if (lVar14 == 0) {

          FUN_1401841e0(*(undefined8 *)(piVar6 + 6));

          FUN_1401841e0(piVar6);

          uVar7 = FUN_14012e850("Unsupported YUV colorspace");

          return uVar7;

        }

      }

      iVar10 = FUN_140174c40(param_3,"SDL.texture.create.opengles2.texture",0);

      *piVar6 = iVar10;

      if (iVar10 == 0) {

        (**(code **)(lVar1 + 0xb8))(1,piVar6);

        uVar5 = 1;

        cVar3 = FUN_1401f4660("glGenTexures()",param_1,"SDL_render_gles2.c",0x79b,

                              "GLES2_CreateTexture");

        if (cVar3 == '\0') goto LAB_1401f0daa;

      }

      else {

        *(undefined1 *)(piVar6 + 1) = 1;

      }

      *(int **)(param_2 + 0x4e) = piVar6;

      (**(code **)(lVar1 + 0x10))(0x84c0);

      (**(code **)(lVar1 + 0x28))(piVar6[2],*piVar6);

      if (*param_2 == 0x2053454f) {

LAB_1401f12a0:

        FUN_1401f4ff0(lVar1,piVar6[2],*param_2,piVar6[0x12]);

        FUN_1401f4f90(lVar1,piVar6[2],piVar6[0x13],piVar6[0x14]);

        iVar10 = *piVar6;

        uVar5 = FUN_14014f530(param_2);

        FUN_140175360(uVar5,"SDL.texture.opengles2.texture",iVar10);

        iVar10 = piVar6[2];

        uVar5 = FUN_14014f530(param_2);

        FUN_140175360(uVar5,"SDL.texture.opengles2.target",iVar10);

        if (param_2[9] == 2) {

          uVar8 = FUN_1401f1590(*(undefined8 *)(param_1 + 0x2e0),param_2[1],param_2[2]);

        }

        *(undefined8 *)(piVar6 + 0x16) = uVar8;

        uVar7 = FUN_1401f4660(&DAT_14039bcb9,param_1,"SDL_render_gles2.c",0x7b5,

                              "GLES2_CreateTexture");

        return uVar7;

      }

      (**(code **)(lVar1 + 0x128))

                (piVar6[2],0,iVar15,param_2[1],CONCAT44(uVar5,param_2[2]),0,iVar15,local_res8,0);

      uVar7 = FUN_1401f4660("glTexImage2D()",param_1,"SDL_render_gles2.c",0x7a6,

                            "GLES2_CreateTexture");

      if ((char)uVar7 != '\0') goto LAB_1401f12a0;

      goto LAB_1401f0c9b;

    }

    iVar10 = FUN_140174c40(param_3,"SDL.texture.create.opengles2.texture_v",0);

    piVar6[10] = iVar10;

    if (iVar10 == 0) {

      (**(code **)(lVar1 + 0xb8))(1,piVar6 + 10);

      uVar5 = 1;

      cVar3 = FUN_1401f4660("glGenTexures()",param_1,"SDL_render_gles2.c",0x748,

                            "GLES2_CreateTexture");

      if (cVar3 != '\0') goto LAB_1401f0dd0;

    }

    else {

      piVar6[0xb] = 1;

LAB_1401f0dd0:

      (**(code **)(lVar1 + 0x10))(0x84c2);

      (**(code **)(lVar1 + 0x28))(piVar6[2],piVar6[10]);

      (**(code **)(lVar1 + 0x128))

                (piVar6[2],0,iVar15,(int)(*puVar16 + 1) / 2,CONCAT44(uVar5,(int)(*puVar13 + 1) / 2),

                 0,iVar15,local_res8,0);

      uVar5 = 1;

      cVar3 = FUN_1401f4660("glTexImage2D()",param_1,"SDL_render_gles2.c",0x751,

                            "GLES2_CreateTexture");

      if (cVar3 != '\0') {

        FUN_1401f4ff0(lVar1,piVar6[2],*param_2,piVar6[0x12]);

        FUN_1401f4f90(lVar1,piVar6[2],piVar6[0x13],piVar6[0x14]);

        iVar10 = piVar6[10];

        uVar4 = FUN_14014f530(param_2);

        FUN_140175360(uVar4,"SDL.texture.opengles2.texture_v",iVar10);

        iVar10 = FUN_140174c40(param_3,"SDL.texture.create.opengles2.texture_u",0);

        piVar6[0xc] = iVar10;

        if (iVar10 == 0) {

          (**(code **)(lVar1 + 0xb8))(1,piVar6 + 0xc);

          uVar5 = 1;

          cVar3 = FUN_1401f4660("glGenTexures()",param_1,"SDL_render_gles2.c",0x75f,

                                "GLES2_CreateTexture");

          if (cVar3 == '\0') goto LAB_1401f0daa;

        }

        else {

          piVar6[0xd] = 1;

        }

        local_res20 = param_2 + 1;

        local_res10 = param_2 + 2;

        (**(code **)(lVar1 + 0x10))(0x84c1);

        (**(code **)(lVar1 + 0x28))(piVar6[2],piVar6[0xc]);

        (**(code **)(lVar1 + 0x128))

                  (piVar6[2],0,iVar15,(int)(*local_res20 + 1) / 2,

                   CONCAT44(uVar5,(int)(*local_res10 + 1) / 2),0,iVar15,local_res8,0);

        uVar5 = 1;

        cVar3 = FUN_1401f4660("glTexImage2D()",param_1,"SDL_render_gles2.c",0x768,

                              "GLES2_CreateTexture");

        if (cVar3 != '\0') {

          FUN_1401f4ff0(lVar1,piVar6[2],*param_2,piVar6[0x12]);

          FUN_1401f4f90(lVar1,piVar6[2],piVar6[0x13],piVar6[0x14]);

          iVar10 = piVar6[0xc];

          uVar4 = FUN_14014f530(param_2);

          FUN_140175360(uVar4,"SDL.texture.opengles2.texture_u",iVar10);

          lVar14 = FUN_14017b8d0(param_2[6],*local_res20,*local_res10,8);

          goto joined_r0x0001401f11a9;

        }

      }

    }

LAB_1401f0daa:

    FUN_1401841e0(*(undefined8 *)(piVar6 + 6));

  }

  uVar7 = FUN_1401841e0(piVar6);

LAB_1401f0c9b:

  return uVar7 & 0xffffffffffffff00;

}




