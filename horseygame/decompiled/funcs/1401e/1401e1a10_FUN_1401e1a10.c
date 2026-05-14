// Address: 0x1401e1a10
// Ghidra name: FUN_1401e1a10
// ============ 0x1401e1a10 FUN_1401e1a10 (size=1122) ============


undefined8 FUN_1401e1a10(longlong param_1,int *param_2,undefined4 param_3)



{

  int iVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  uint *puVar7;

  longlong lVar8;

  int local_88;

  undefined8 uStack_84;

  undefined4 uStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_74;

  int local_70;

  undefined8 uStack_6c;

  undefined4 uStack_64;

  undefined8 local_60;

  uint local_58;

  uint local_54;

  undefined4 local_50;

  undefined4 local_4c;

  int local_48;

  undefined8 local_44;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  iVar4 = FUN_1401e5c00(*param_2,*(undefined4 *)(param_1 + 0x208));

  if (*(longlong *)(lVar2 + 0x20) == 0) {

    uVar6 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar6;

  }

  if (iVar4 == 0) {

    uVar6 = FUN_14012e850("%s, An unsupported SDL pixel format (0x%x) was specified",

                          "D3D11_CreateTexture");

    return uVar6;

  }

  puVar7 = (uint *)FUN_1401841a0(1,0x90);

  if (puVar7 == (uint *)0x0) {

    return 0;

  }

  local_58 = param_2[1];

  local_54 = param_2[2];

  *(uint **)(param_2 + 0x4e) = puVar7;

  iVar1 = *param_2;

  local_50 = 1;

  local_4c = 1;

  local_44 = 1;

  local_30 = 0;

  if (((iVar1 == 0x3231564e) || (iVar1 == 0x3132564e)) || (iVar1 == 0x30313050)) {

    local_58 = local_58 + 1 & 0xfffffffe;

    local_54 = local_54 + 1 & 0xfffffffe;

  }

  *puVar7 = local_58;

  puVar7[1] = local_54;

  if (param_2[9] == 1) {

    local_3c = 2;

    local_34 = 0x10000;

LAB_1401e1b3e:

    local_38 = 8;

  }

  else {

    local_3c = 0;

    local_34 = 0;

    local_38 = 0x28;

    if (param_2[9] != 2) goto LAB_1401e1b3e;

  }

  local_48 = iVar4;

  cVar3 = FUN_1401e56e0(param_3,"SDL.texture.create.d3d11.texture",puVar7 + 2);

  if (cVar3 == '\0') {

    return 0;

  }

  if ((*(longlong *)(puVar7 + 2) == 0) &&

     (iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x28))

                        (*(longlong **)(lVar2 + 0x20),&local_58,0,puVar7 + 2), iVar4 < 0))

  goto LAB_1401e1c69;

  uVar6 = *(undefined8 *)(puVar7 + 2);

  uVar5 = FUN_14014f530(param_2);

  FUN_140175480(uVar5,"SDL.texture.d3d11.texture",uVar6);

  if ((*param_2 == 0x32315659) || (*param_2 == 0x56555949)) {

    *(undefined1 *)(puVar7 + 0xe) = 1;

    local_58 = local_58 + 1 >> 1;

    local_54 = local_54 + 1 >> 1;

    cVar3 = FUN_1401e56e0(param_3,"SDL.texture.create.d3d11.texture_u",puVar7 + 0x10);

    if (cVar3 == '\0') {

      return 0;

    }

    if ((*(longlong *)(puVar7 + 0x10) == 0) &&

       (iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x28))

                          (*(longlong **)(lVar2 + 0x20),&local_58,0,puVar7 + 0x10), iVar4 < 0)) {

LAB_1401e1c69:

      uVar6 = FUN_1401a9ef0("ID3D11Device1::CreateTexture2D",iVar4);

      return uVar6;

    }

    uVar6 = *(undefined8 *)(puVar7 + 0x10);

    uVar5 = FUN_14014f530(param_2);

    FUN_140175480(uVar5,"SDL.texture.d3d11.texture_u",uVar6);

    cVar3 = FUN_1401e56e0(param_3,"SDL.texture.create.d3d11.texture_v",puVar7 + 0x14);

    if (cVar3 == '\0') {

      return 0;

    }

    if ((*(longlong *)(puVar7 + 0x14) == 0) &&

       (iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x28))

                          (*(longlong **)(lVar2 + 0x20),&local_58,0,puVar7 + 0x14), iVar4 < 0))

    goto LAB_1401e1c69;

    uVar6 = *(undefined8 *)(puVar7 + 0x14);

    uVar5 = FUN_14014f530(param_2);

    FUN_140175480(uVar5,"SDL.texture.d3d11.texture_v",uVar6);

    lVar8 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],8);

    *(longlong *)(puVar7 + 0xc) = lVar8;

    if (lVar8 == 0) goto LAB_1401e1cf9;

  }

  iVar4 = *param_2;

  if (((iVar4 == 0x3231564e) || (iVar4 == 0x3132564e)) || (iVar4 == 0x30313050)) {

    *(undefined1 *)(puVar7 + 0x18) = 1;

    uVar5 = 8;

    if (*param_2 == 0x30313050) {

      uVar5 = 10;

    }

    lVar8 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],uVar5);

    *(longlong *)(puVar7 + 0xc) = lVar8;

    if (lVar8 == 0) {

LAB_1401e1cf9:

      uVar6 = FUN_14012e850("Unsupported YUV colorspace");

      return uVar6;

    }

  }

  local_60 = 0;

  local_70 = FUN_1401e5b50(*param_2,*(undefined4 *)(param_1 + 0x208));

  uStack_64 = local_50;

  uStack_6c = 4;

  iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x38))

                    (*(longlong **)(lVar2 + 0x20),*(undefined8 *)(puVar7 + 2),&local_70,puVar7 + 4);

  if ((-1 < iVar4) &&

     (((char)puVar7[0xe] == '\0' ||

      ((iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x38))

                          (*(longlong **)(lVar2 + 0x20),*(undefined8 *)(puVar7 + 0x10),&local_70,

                           puVar7 + 0x12), -1 < iVar4 &&

       (iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x38))

                          (*(longlong **)(lVar2 + 0x20),*(undefined8 *)(puVar7 + 0x14),&local_70,

                           puVar7 + 0x16), -1 < iVar4)))))) {

    if ((char)puVar7[0x18] != '\0') {

      iVar4 = *param_2;

      uStack_78 = (undefined4)local_60;

      uStack_74 = (undefined4)((ulonglong)local_60 >> 0x20);

      local_88 = local_70;

      uStack_84 = uStack_6c;

      uStack_7c = uStack_64;

      if ((iVar4 == 0x3231564e) || (iVar4 == 0x3132564e)) {

        local_88 = 0x31;

      }

      else if (iVar4 == 0x30313050) {

        local_88 = 0x23;

      }

      iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x38))

                        (*(longlong **)(lVar2 + 0x20),*(undefined8 *)(puVar7 + 2),&local_88,

                         puVar7 + 0x1a);

      if (iVar4 < 0) goto LAB_1401e1dee;

    }

    if ((*(byte *)(param_2 + 9) & 2) != 0) {

      uStack_7c = 0;

      uStack_78 = 0;

      local_88 = local_48;

      uStack_84 = 4;

      iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x48))

                        (*(longlong **)(lVar2 + 0x20),*(undefined8 *)(puVar7 + 2),&local_88,

                         puVar7 + 6);

      if (iVar4 < 0) {

        uVar6 = FUN_1401a9ef0("ID3D11Device1::CreateRenderTargetView",iVar4);

        return uVar6;

      }

    }

    return 1;

  }

LAB_1401e1dee:

  uVar6 = FUN_1401a9ef0("ID3D11Device1::CreateShaderResourceView",iVar4);

  return uVar6;

}




