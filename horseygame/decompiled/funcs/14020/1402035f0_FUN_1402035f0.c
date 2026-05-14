// Address: 0x1402035f0
// Ghidra name: FUN_1402035f0
// ============ 0x1402035f0 FUN_1402035f0 (size=1102) ============


ulonglong FUN_1402035f0(longlong param_1,uint *param_2,undefined4 param_3)



{

  uint uVar1;

  int iVar2;

  undefined4 uVar3;

  undefined1 *puVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  longlong lVar7;

  uint uVar8;

  int iVar9;

  longlong lVar10;

  bool bVar11;

  undefined4 local_58;

  int local_54;

  undefined4 local_50;

  uint local_4c;

  uint local_48;

  undefined4 local_44;

  undefined8 local_40;

  undefined4 local_38;

  

  lVar7 = *(longlong *)(param_1 + 0x2e0);

  puVar4 = (undefined1 *)FUN_1401841a0(1,0x68);

  uVar6 = 0;

  if (puVar4 == (undefined1 *)0x0) goto LAB_1402037bf;

  uVar1 = *param_2;

  uVar8 = 2;

  *(undefined1 **)(param_2 + 0x4e) = puVar4;

  if ((int)uVar1 < 0x3231564f) {

    if ((uVar1 == 0x3231564e) || (uVar1 == 0x13000801)) goto LAB_14020368b;

    if (uVar1 != 0x30313050) {

      bVar11 = uVar1 == 0x3132564e;

      goto LAB_140203680;

    }

    iVar2 = 5;

  }

  else {

    if (uVar1 != 0x32315659) {

      bVar11 = uVar1 == 0x56555949;

LAB_140203680:

      if (!bVar11) {

        iVar2 = FUN_1401378d0();

        goto LAB_14020368d;

      }

    }

LAB_14020368b:

    iVar2 = 2;

  }

LAB_14020368d:

  if (*(int *)(param_1 + 0x208) == 0x12000500) {

    if (iVar2 == 4) {

      iVar2 = 0x34;

    }

    else {

      if (iVar2 != 0xc) goto LAB_1402036f6;

      iVar2 = 0x35;

    }

  }

  else {

LAB_1402036f6:

    if (iVar2 == 0) {

      uVar5 = FUN_14017af90(*param_2);

      uVar6 = FUN_14012e850("Texture format %s not supported by SDL_GPU",uVar5);

      return uVar6;

    }

  }

  *(int *)(puVar4 + 0x10) = iVar2;

  if (param_2[9] == 1) {

    uVar1 = *param_2;

    if ((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) {

      uVar8 = uVar1 & 0xff;

    }

    else if ((((uVar1 != 0x32595559) && (uVar1 != 0x59565955)) && (uVar1 != 0x55595659)) &&

            (uVar1 != 0x30313050)) {

      uVar8 = 1;

    }

    iVar9 = uVar8 * param_2[1];

    *(int *)(puVar4 + 0x20) = iVar9;

    uVar1 = param_2[2];

    uVar8 = *param_2;

    lVar10 = (longlong)(int)uVar1 * (longlong)iVar9;

    if ((uVar8 == 0x32315659) || (uVar8 == 0x56555949)) {

      lVar10 = lVar10 + ((iVar9 + 1) / 2) * ((int)(uVar1 + 1) / 2) * 2;

    }

    if (((uVar8 == 0x3231564e) || (uVar8 == 0x3132564e)) || (uVar8 == 0x30313050)) {

      lVar10 = lVar10 + ((iVar9 + 1) / 2) * ((int)(uVar1 + 1) / 2) * 2;

    }

    lVar10 = FUN_1401841a0(1,lVar10);

    *(longlong *)(puVar4 + 0x18) = lVar10;

    if (lVar10 == 0) {

      uVar6 = FUN_1401841e0(puVar4);

      goto LAB_1402037bf;

    }

  }

  local_58 = 0;

  iVar9 = 3;

  local_50 = 3;

  local_44 = 1;

  if (param_2[9] != 2) {

    local_50 = 1;

  }

  local_40 = 1;

  local_4c = param_2[1];

  local_48 = param_2[2];

  local_54 = iVar2;

  local_38 = param_3;

  lVar10 = FUN_140174d30(param_3,"SDL.texture.create.gpu.texture",0);

  *(longlong *)(puVar4 + 8) = lVar10;

  if (lVar10 == 0) {

    lVar10 = FUN_1401355b0(*(undefined8 *)(lVar7 + 8),&local_58);

    *(longlong *)(puVar4 + 8) = lVar10;

    uVar6 = 0;

    if (lVar10 == 0) goto LAB_1402037bf;

  }

  else {

    *puVar4 = 1;

  }

  uVar3 = FUN_14014f530(param_2);

  FUN_140175480(uVar3,"SDL.texture.gpu.texture",*(undefined8 *)(puVar4 + 8));

  if ((*param_2 == 0x32315659) || (*param_2 == 0x56555949)) {

    puVar4[0x40] = 1;

    local_4c = local_4c + 1 >> 1;

    local_48 = local_48 + 1 >> 1;

    lVar10 = FUN_140174d30(param_3,"SDL.texture.create.gpu.texture_u",0);

    *(longlong *)(puVar4 + 0x48) = lVar10;

    if (lVar10 == 0) {

      lVar10 = FUN_1401355b0(*(undefined8 *)(lVar7 + 8),&local_58);

      *(longlong *)(puVar4 + 0x48) = lVar10;

      uVar6 = 0;

      if (lVar10 == 0) goto LAB_1402037bf;

    }

    else {

      puVar4[0x41] = 1;

    }

    FUN_140175480(uVar3,"SDL.texture.gpu.texture_u",lVar10);

    lVar10 = FUN_140174d30(param_3,"SDL.texture.create.gpu.texture_v",0);

    *(longlong *)(puVar4 + 0x50) = lVar10;

    if (lVar10 == 0) {

      lVar10 = FUN_1401355b0(*(undefined8 *)(lVar7 + 8),&local_58);

      *(longlong *)(puVar4 + 0x50) = lVar10;

      uVar6 = 0;

      if (lVar10 == 0) goto LAB_1402037bf;

    }

    else {

      puVar4[0x42] = 1;

    }

    FUN_140175480(uVar3,"SDL.texture.gpu.texture_v",*(undefined8 *)(puVar4 + 0x48));

    lVar10 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],8);

    *(longlong *)(puVar4 + 0x38) = lVar10;

    if (lVar10 != 0) goto LAB_140203970;

LAB_14020395f:

    uVar6 = FUN_14012e850("Unsupported YUV colorspace");

  }

  else {

LAB_140203970:

    uVar1 = *param_2;

    if (((uVar1 == 0x3231564e) || (uVar1 == 0x3132564e)) || (uVar1 == 0x30313050)) {

      puVar4[0x58] = 1;

      lVar10 = FUN_140174d30(param_3,"SDL.texture.create.gpu.texture_uv",0);

      *(longlong *)(puVar4 + 0x60) = lVar10;

      if (lVar10 == 0) {

        local_4c = local_4c + 1 >> 1;

        local_48 = local_48 + 1 >> 1;

        if (*param_2 == 0x30313050) {

          iVar9 = 6;

        }

        local_54 = iVar9;

        lVar10 = FUN_1401355b0(*(undefined8 *)(lVar7 + 8),&local_58);

        *(longlong *)(puVar4 + 0x60) = lVar10;

        uVar6 = 0;

        if (lVar10 == 0) {

LAB_1402037bf:

          return uVar6 & 0xffffffffffffff00;

        }

      }

      else {

        puVar4[0x59] = 1;

      }

      FUN_140175480(uVar3,"SDL.texture.gpu.texture_uv",lVar10);

      uVar3 = 8;

      if (*param_2 == 0x30313050) {

        uVar3 = 10;

      }

      lVar7 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],uVar3);

      *(longlong *)(puVar4 + 0x38) = lVar7;

      if (lVar7 == 0) goto LAB_14020395f;

    }

    uVar6 = 1;

  }

  return uVar6;

}




