// Address: 0x1402235f0
// Ghidra name: FUN_1402235f0
// ============ 0x1402235f0 FUN_1402235f0 (size=736) ============


undefined8 FUN_1402235f0(longlong param_1,longlong param_2)



{

  HDC hdc;

  longlong lVar1;

  char cVar2;

  byte bVar3;

  int iVar4;

  undefined4 uVar5;

  uint format;

  BOOL BVar6;

  char *_Str1;

  undefined8 uVar7;

  undefined4 extraout_var;

  undefined4 *puVar8;

  undefined4 *puVar9;

  undefined4 local_res8 [2];

  PIXELFORMATDESCRIPTOR local_138;

  undefined4 local_108;

  undefined4 local_104;

  undefined4 local_100;

  undefined4 local_fc;

  undefined4 local_f8;

  undefined4 local_f4;

  undefined4 local_f0;

  undefined4 local_ec;

  undefined4 local_e8;

  int local_e4;

  undefined4 local_e0 [2];

  uint local_d8 [52];

  

  hdc = *(HDC *)(*(longlong *)(param_2 + 0x188) + 0x18);

  local_res8[0] = 0;

  FUN_140223490(param_1,&local_138);

  local_fc = *(undefined4 *)(param_1 + 0x3a0);

  local_f4 = *(undefined4 *)(param_1 + 0x3a4);

  local_ec = *(undefined4 *)(param_1 + 0x3a8);

  iVar4 = *(int *)(param_1 + 0x3ac);

  local_108 = 0x2001;

  local_104 = 1;

  local_100 = 0x2015;

  local_f8 = 0x2017;

  local_f0 = 0x2019;

  if (iVar4 != 0) {

    local_e8 = 0x201b;

    local_e4 = iVar4;

  }

  uVar5 = *(undefined4 *)(param_1 + 0x3bc);

  puVar8 = &local_e8;

  if (iVar4 != 0) {

    puVar8 = local_e0;

  }

  *puVar8 = 0x2011;

  puVar8[1] = uVar5;

  puVar8[3] = *(undefined4 *)(param_1 + 0x3b0);

  iVar4 = *(int *)(param_1 + 0x3b8);

  puVar8[2] = 0x2022;

  puVar9 = puVar8 + 4;

  if (iVar4 != 0) {

    *puVar9 = 0x2023;

    puVar8[5] = iVar4;

    puVar9 = puVar8 + 6;

  }

  iVar4 = *(int *)(param_1 + 0x3c0);

  if (iVar4 != 0) {

    *puVar9 = 0x201e;

    puVar9[1] = iVar4;

    puVar9 = puVar9 + 2;

  }

  iVar4 = *(int *)(param_1 + 0x3c4);

  if (iVar4 != 0) {

    *puVar9 = 0x201f;

    puVar9[1] = iVar4;

    puVar9 = puVar9 + 2;

  }

  iVar4 = *(int *)(param_1 + 0x3c8);

  if (iVar4 != 0) {

    *puVar9 = 0x2020;

    puVar9[1] = iVar4;

    puVar9 = puVar9 + 2;

  }

  iVar4 = *(int *)(param_1 + 0x3cc);

  if (iVar4 != 0) {

    *puVar9 = 0x2021;

    puVar9[1] = iVar4;

    puVar9 = puVar9 + 2;

  }

  if (*(int *)(param_1 + 0x3d0) != 0) {

    *puVar9 = 0x2012;

    puVar9[1] = 1;

    puVar9 = puVar9 + 2;

  }

  iVar4 = *(int *)(param_1 + 0x3d4);

  if (iVar4 != 0) {

    *puVar9 = 0x2041;

    puVar9[1] = iVar4;

    puVar9 = puVar9 + 2;

  }

  iVar4 = *(int *)(param_1 + 0x3d8);

  if (iVar4 != 0) {

    *puVar9 = 0x2042;

    puVar9[1] = iVar4;

    puVar9 = puVar9 + 2;

  }

  lVar1 = *(longlong *)(param_1 + 0x688);

  if ((*(char *)(lVar1 + 5) != '\0') && (*(int *)(param_1 + 0x3dc) != 0)) {

    *puVar9 = 0x2013;

    puVar9[1] = 0x21a0;

    puVar9 = puVar9 + 2;

  }

  if (*(char *)(lVar1 + 7) != '\0') {

    _Str1 = (char *)FUN_140142960("SDL_OPENGL_FORCE_SRGB_FRAMEBUFFER");

    if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {

      if (*(int *)(param_1 + 0x400) != 0) {

        *puVar9 = 0x20a9;

        puVar9[1] = 1;

        goto LAB_140223802;

      }

    }

    else {

      iVar4 = strcmp(_Str1,"skip");

      if (iVar4 != 0) {

        *puVar9 = 0x20a9;

        cVar2 = FUN_1401429e0(_Str1,0);

        puVar9[1] = (uint)(cVar2 != '\0');

LAB_140223802:

        puVar9 = puVar9 + 2;

      }

    }

  }

  iVar4 = *(int *)(param_1 + 0x3e0);

  *puVar9 = 0x2003;

  uVar5 = 0x2027;

  if (iVar4 == 0) {

    uVar5 = 0x2025;

  }

  puVar9[1] = uVar5;

  puVar9[2] = 0;

  format = FUN_140222880(param_1,&local_108,local_res8);

  if (format == 0) {

    if (*(int *)(param_1 + 0x3e0) < 0) {

      puVar9[1] = 0x2025;

      format = FUN_140222880(param_1,&local_108,local_res8);

      puVar9[1] = 0x2027;

      if (format != 0) goto LAB_140223893;

    }

    bVar3 = FUN_140222630(param_1,hdc,&local_138);

    format = (uint)bVar3;

    if (bVar3 == 0) {

      uVar7 = FUN_14012e850("No matching GL pixel format available");

      return uVar7;

    }

  }

LAB_140223893:

  BVar6 = SetPixelFormat(hdc,format,&local_138);

  if (BVar6 == 0) {

    uVar7 = FUN_1401a9ed0("SetPixelFormat()");

  }

  else {

    uVar7 = CONCAT71((int7)(CONCAT44(extraout_var,BVar6) >> 8),1);

  }

  return uVar7;

}




