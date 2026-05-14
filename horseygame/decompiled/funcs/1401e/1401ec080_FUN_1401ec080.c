// Address: 0x1401ec080
// Ghidra name: FUN_1401ec080
// ============ 0x1401ec080 FUN_1401ec080 (size=2094) ============


ulonglong FUN_1401ec080(longlong param_1,uint *param_2,undefined4 param_3)



{

  int *piVar1;

  undefined4 uVar2;

  longlong lVar3;

  float fVar4;

  char cVar5;

  uint uVar6;

  undefined4 uVar7;

  int iVar8;

  ulonglong uVar9;

  undefined8 uVar10;

  int *piVar11;

  int iVar12;

  uint uVar13;

  longlong lVar14;

  float fVar15;

  int local_res20 [2];

  undefined8 in_stack_ffffffffffffff68;

  undefined4 uVar16;

  int local_68;

  undefined4 local_64;

  uint local_60;

  

  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  uVar2 = *(undefined4 *)(lVar3 + 0x28);

  FUN_1401ebd30();

  uVar10 = 0;

  *(undefined1 *)(lVar3 + 0x265) = 1;

  *(undefined8 *)(lVar3 + 0x218) = 0;

  if ((param_2[9] == 2) && (*(char *)(lVar3 + 0x2e) == '\0')) {

    uVar9 = FUN_14012e850("Render targets not supported by OpenGL");

    return uVar9;

  }

  uVar9 = (ulonglong)*param_2;

  cVar5 = FUN_1401efcd0(uVar9,&local_64,&local_68,local_res20);

  if (cVar5 == '\0') {

    uVar10 = FUN_14017af90(uVar9 & 0xffffffff);

    uVar9 = FUN_14012e850("Texture format %s not supported by OpenGL",uVar10);

    return uVar9;

  }

  piVar11 = (int *)FUN_1401841a0(1,0x80);

  uVar9 = 0;

  if (piVar11 == (int *)0x0) goto LAB_1401ec338;

  if (param_2[9] == 1) {

    uVar6 = *param_2;

    if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

      uVar6 = uVar6 & 0xff;

    }

    else if ((((uVar6 == 0x32595559) || (uVar6 == 0x59565955)) || (uVar6 == 0x55595659)) ||

            (uVar6 == 0x30313050)) {

      uVar6 = 2;

    }

    else {

      uVar6 = 1;

    }

    iVar12 = uVar6 * param_2[1];

    piVar11[0x10] = iVar12;

    uVar6 = param_2[2];

    uVar13 = *param_2;

    lVar14 = (longlong)(int)uVar6 * (longlong)iVar12;

    if ((uVar13 == 0x32315659) || (uVar13 == 0x56555949)) {

      lVar14 = lVar14 + ((iVar12 + 1) / 2) * ((int)(uVar6 + 1) / 2) * 2;

    }

    if ((uVar13 == 0x3231564e) || (uVar13 == 0x3132564e)) {

      lVar14 = lVar14 + ((iVar12 + 1) / 2) * ((int)(uVar6 + 1) / 2) * 2;

    }

    lVar14 = FUN_1401841a0(1,lVar14);

    *(longlong *)(piVar11 + 0xe) = lVar14;

    if (lVar14 != 0) goto LAB_1401ec256;

LAB_1401ec330:

    uVar9 = FUN_1401841e0(piVar11);

LAB_1401ec338:

    return uVar9 & 0xffffffffffffff00;

  }

LAB_1401ec256:

  if (param_2[9] == 2) {

    uVar10 = FUN_1401ecaf0(lVar3,param_2[1],param_2[2]);

  }

  *(undefined8 *)(piVar11 + 0x1e) = uVar10;

  iVar12 = FUN_140174c40(param_3,"SDL.texture.create.opengl.texture",0);

  *piVar11 = iVar12;

  if (iVar12 == 0) {

    FUN_1401ebd90(&DAT_14039bcb9,param_1,"SDL_render_gl.c",0x26a,"GL_CreateTexture");

    (**(code **)(lVar3 + 0xd0))(1,piVar11);

    uVar16 = 1;

    cVar5 = FUN_1401ebd90("glGenTextures()",param_1,"SDL_render_gl.c",0x26c,"GL_CreateTexture");

    if (cVar5 == '\0') {

      FUN_1401841e0(*(undefined8 *)(piVar11 + 0xe));

      goto LAB_1401ec330;

    }

  }

  else {

    *(undefined1 *)(piVar11 + 1) = 1;

  }

  fVar4 = DAT_14039ca44;

  uVar6 = param_2[1];

  *(int **)(param_2 + 0x4e) = piVar11;

  if (*(char *)(lVar3 + 0x2c) == '\0') {

    if (*(char *)(lVar3 + 0x2d) == '\0') {

      uVar6 = FUN_1401aae20(uVar6);

      local_60 = FUN_1401aae20(param_2[2]);

      piVar11[2] = (int)((float)(int)param_2[1] / (float)(int)uVar6);

      fVar15 = (float)(int)param_2[2] / (float)(int)local_60;

    }

    else {

      local_60 = param_2[2];

      piVar11[2] = (int)(float)(int)uVar6;

      fVar15 = (float)(int)local_60;

    }

  }

  else {

    local_60 = param_2[2];

    piVar11[2] = 0x3f800000;

    fVar15 = fVar4;

  }

  uVar13 = local_60;

  piVar11[3] = (int)fVar15;

  uVar7 = FUN_14014f530(param_2);

  FUN_140175360(uVar7,"SDL.texture.opengl.texture",*piVar11);

  FUN_140175360(uVar7,"SDL.texture.opengl.target",uVar2);

  FUN_1401752f0(uVar7,"SDL.texture.opengl.tex_w");

  FUN_1401752f0(uVar7,"SDL.texture.opengl.tex_h");

  piVar11[4] = local_68;

  piVar11[5] = local_res20[0];

  piVar11[0x1a] = param_2[0xb];

  piVar11[0x1b] = 1;

  piVar11[0x1c] = 1;

  (**(code **)(lVar3 + 0xb8))(uVar2);

  (**(code **)(lVar3 + 0x40))(uVar2,*piVar11);

  (**(code **)(lVar3 + 0x180))

            (uVar2,0,local_64,uVar6,CONCAT44(uVar16,uVar13),0,local_68,local_res20[0],0);

  uVar16 = 1;

  uVar9 = FUN_1401ebd90("glTexImage2D()",param_1,"SDL_render_gl.c",0x2b0,"GL_CreateTexture");

  if ((char)uVar9 == '\0') goto LAB_1401ec338;

  FUN_1401efc00(lVar3,uVar2,*param_2,piVar11[0x1a]);

  FUN_1401efba0(lVar3,uVar2,piVar11[0x1b],piVar11[0x1c]);

  if ((*param_2 == 0x32315659) || (*param_2 == 0x56555949)) {

    *(undefined1 *)(piVar11 + 0x15) = 1;

    iVar12 = FUN_140174c40(param_3,"SDL.texture.create.opengl.texture_u",0);

    piVar11[0x16] = iVar12;

    if (iVar12 == 0) {

      (**(code **)(lVar3 + 0xd0))(1,piVar11 + 0x16);

    }

    else {

      *(undefined1 *)(piVar11 + 0x17) = 1;

    }

    iVar12 = FUN_140174c40(param_3,"SDL.texture.create.opengl.texture_v",0);

    piVar11[0x18] = iVar12;

    if (iVar12 == 0) {

      (**(code **)(lVar3 + 0xd0))(1,piVar11 + 0x18);

    }

    else {

      *(undefined1 *)(piVar11 + 0x19) = 1;

    }

    (**(code **)(lVar3 + 0x40))(uVar2,piVar11[0x16]);

    iVar12 = (int)(uVar13 + 1) / 2;

    iVar8 = (int)(uVar6 + 1) / 2;

    uVar10 = CONCAT44(uVar16,iVar12);

    (**(code **)(lVar3 + 0x180))(uVar2,0,local_64,iVar8,uVar10,0,local_68,local_res20[0],0);

    uVar16 = (undefined4)((ulonglong)uVar10 >> 0x20);

    FUN_1401efc00(lVar3,uVar2,*param_2,piVar11[0x1a]);

    FUN_1401efba0(lVar3,uVar2,piVar11[0x1b],piVar11[0x1c]);

    FUN_140175360(uVar7,"SDL.texture.opengl.texture_u",piVar11[0x16]);

    (**(code **)(lVar3 + 0x40))(uVar2,piVar11[0x18]);

    uVar10 = CONCAT44(uVar16,iVar12);

    (**(code **)(lVar3 + 0x180))(uVar2,0,local_64,iVar8,uVar10,0,local_68,local_res20[0],0);

    uVar16 = (undefined4)((ulonglong)uVar10 >> 0x20);

    FUN_1401efc00(lVar3,uVar2,*param_2,piVar11[0x1a]);

    FUN_1401efba0(lVar3,uVar2,piVar11[0x1b],piVar11[0x1c]);

    FUN_140175360(uVar7,"SDL.texture.opengl.texture_v",piVar11[0x18]);

    uVar13 = local_60;

  }

  if ((*param_2 == 0x3231564e) || (*param_2 == 0x3132564e)) {

    *(undefined1 *)((longlong)piVar11 + 0x55) = 1;

    iVar12 = FUN_140174c40(param_3,"SDL.texture.create.opengl.texture_uv",0);

    piVar11[0x16] = iVar12;

    if (iVar12 == 0) {

      (**(code **)(lVar3 + 0xd0))(1,piVar11 + 0x16);

    }

    else {

      *(undefined1 *)(piVar11 + 0x17) = 1;

    }

    (**(code **)(lVar3 + 0x40))(uVar2,piVar11[0x16]);

    (**(code **)(lVar3 + 0x180))

              (uVar2,0,0x190a,(int)(uVar6 + 1) / 2,CONCAT44(uVar16,(int)(uVar13 + 1) / 2),0,0x190a,

               0x1401,0);

    FUN_1401efc00(lVar3,uVar2,*param_2,piVar11[0x1a]);

    FUN_1401efba0(lVar3,uVar2,piVar11[0x1b],piVar11[0x1c]);

    FUN_140175360(uVar7,"SDL.texture.opengl.texture_uv",piVar11[0x16]);

  }

  piVar1 = piVar11 + 6;

  if (*param_2 == 0x13000801) {

    *piVar1 = 2;

  }

  else if ((*param_2 + 0xe9c9dffc & 0xffbfffff) == 0) {

    *piVar1 = 7;

  }

  else {

    *piVar1 = 5;

  }

  piVar11[7] = (int)(fVar4 / (float)(int)param_2[1]);

  piVar11[8] = (int)(fVar4 / (float)(int)param_2[2]);

  piVar11[9] = (int)(float)(int)param_2[1];

  piVar11[10] = (int)(float)(int)param_2[2];

  if ((char)piVar11[0x15] == '\0') {

    if (*(char *)((longlong)piVar11 + 0x55) == '\0') goto LAB_1401ec870;

    if (*param_2 == 0x3231564e) {

      cVar5 = FUN_140142940("SDL_RENDER_OPENGL_NV12_RG_SHADER",0);

      iVar12 = (cVar5 != '\0') + 10;

    }

    else {

      cVar5 = FUN_140142940("SDL_RENDER_OPENGL_NV12_RG_SHADER",0);

      iVar12 = 0xd;

      if (cVar5 == '\0') {

        iVar12 = 0xc;

      }

    }

  }

  else {

    iVar12 = 9;

  }

  *piVar1 = iVar12;

  lVar14 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],8);

  *(longlong *)(piVar11 + 0xc) = lVar14;

  if (lVar14 == 0) {

    uVar9 = FUN_14012e850("Unsupported YUV colorspace");

    return uVar9;

  }

LAB_1401ec870:

  (**(code **)(lVar3 + 0x98))(uVar2);

  uVar9 = FUN_1401ebd90(&DAT_14039bcb9,param_1,"SDL_render_gl.c",0x311,"GL_CreateTexture");

  return uVar9;

}




