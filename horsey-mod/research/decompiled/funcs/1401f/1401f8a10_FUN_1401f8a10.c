// Address: 0x1401f8a10
// Ghidra name: FUN_1401f8a10
// ============ 0x1401f8a10 FUN_1401f8a10 (size=1320) ============


undefined8 FUN_1401f8a10(longlong param_1,int *param_2,undefined4 param_3)



{

  longlong lVar1;

  undefined8 uVar2;

  char cVar3;

  uint uVar4;

  int iVar5;

  undefined4 uVar6;

  undefined8 uVar7;

  longlong lVar8;

  uint uVar9;

  undefined4 uVar10;

  char *pcVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  undefined8 in_stack_fffffffffffffed0;

  undefined8 local_108;

  undefined8 uStack_100;

  undefined8 local_f8;

  uint uStack_f0;

  undefined4 uStack_ec;

  undefined4 uStack_e8;

  undefined4 uStack_e4;

  undefined4 uStack_e0;

  undefined4 uStack_dc;

  undefined4 local_d8;

  undefined4 uStack_d4;

  undefined4 uStack_d0;

  undefined4 uStack_cc;

  undefined4 local_c8;

  undefined4 uStack_c4;

  undefined4 uStack_c0;

  undefined4 uStack_bc;

  undefined8 local_b8;

  undefined8 local_a8;

  undefined4 *local_a0;

  undefined8 local_98;

  undefined8 local_90;

  undefined4 local_88;

  undefined4 local_84;

  undefined8 local_80;

  undefined4 local_78;

  undefined4 local_74;

  undefined8 local_70;

  undefined4 local_68;

  undefined4 local_64;

  undefined8 local_60;

  

  uVar6 = (undefined4)((ulonglong)in_stack_fffffffffffffed0 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar4 = FUN_1401f54b0(*param_2,*(undefined4 *)(param_1 + 0x208));

  uVar14 = param_2[1];

  uVar12 = param_2[2];

  uVar7 = *(undefined8 *)(lVar1 + 0x296c);

  uVar2 = *(undefined8 *)(lVar1 + 0x2974);

  if (*(longlong *)(lVar1 + 0x660) == 0) {

    uVar7 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar7;

  }

  if (uVar4 == 0) {

    uVar7 = FUN_14012e850("%s, An unsupported SDL pixel format (0x%x) was specified",

                          "VULKAN_CreateTexture");

    return uVar7;

  }

  lVar8 = FUN_1401841a0(1,0x98);

  if (lVar8 == 0) {

    return 0;

  }

  iVar5 = *param_2;

  *(longlong *)(param_2 + 0x4e) = lVar8;

  if ((((iVar5 == 0x32315659) || (iVar5 == 0x56555949)) || (iVar5 == 0x3231564e)) ||

     ((iVar5 == 0x3132564e || (iVar5 == 0x30313050)))) {

    if (*(char *)(lVar1 + 0x2872) == '\0') {

      uVar7 = FUN_14012e850(

                           "YUV textures require a Vulkan device that supports VK_KHR_sampler_ycbcr_conversion"

                           );

      return uVar7;

    }

    uVar9 = param_2[6];

    uVar14 = uVar14 + 1 & 0xfffffffe;

    uVar13 = uVar9 & 0x1f;

    uVar12 = uVar12 + 1 & 0xfffffffe;

    uStack_100 = 0;

    local_108 = 0x3b9d2b60;

    uStack_f0 = 0;

    uStack_ec = 0;

    local_f8 = (ulonglong)uVar4;

    uStack_e8 = 0;

    uStack_e4 = 0;

    uStack_e0 = 0;

    uStack_dc = 0;

    local_d8 = 0;

    uStack_d4 = 0;

    uStack_d0 = 0;

    uStack_cc = 0;

    if (uVar13 == 1) {

LAB_1401f8bbf:

      local_f8 = CONCAT44(2,uVar4);

LAB_1401f8bc7:

      uStack_ec = 0;

      uStack_e4 = 0;

      if ((iVar5 == 0x32315659) || (iVar5 == 0x3132564e)) {

        uStack_ec = 5;

        uStack_e4 = 3;

      }

    }

    else {

      if (uVar13 != 2) {

        if ((uVar13 == 5) || (uVar13 == 6)) goto LAB_1401f8bb5;

        if (uVar13 != 9) {

          uVar7 = FUN_14012e850("Unsupported Ycbcr colorspace: %d",uVar13);

          return uVar7;

        }

        local_f8 = CONCAT44(4,uVar4);

        goto LAB_1401f8bc7;

      }

      if (iVar5 != 0x30313050) {

        if (0x240 < uVar12) goto LAB_1401f8bbf;

LAB_1401f8bb5:

        local_f8 = CONCAT44(3,uVar4);

        goto LAB_1401f8bc7;

      }

      local_f8 = CONCAT44(4,uVar4);

      uStack_ec = 0;

      uStack_e4 = 0;

    }

    uStack_e0 = 0;

    uStack_e8 = 0;

    uStack_f0 = (uint)(((int)uVar9 >> 0x18 & 0xfU) == 1);

    uVar9 = (int)uVar9 >> 0x14 & 0xf;

    if (uVar9 == 0) {

LAB_1401f8c34:

      uStack_dc = 1;

LAB_1401f8c3c:

      local_d8 = 1;

    }

    else {

      if (uVar9 == 1) {

        uStack_dc = 0;

        goto LAB_1401f8c3c;

      }

      if ((uVar9 == 2) || (uVar9 != 3)) goto LAB_1401f8c34;

      uStack_dc = 0;

      local_d8 = 0;

    }

    uStack_d4 = 1;

    uStack_d0 = 0;

    iVar5 = (*DAT_1403fd180)(*(undefined8 *)(lVar1 + 0x660),&local_108,0,lVar8 + 0x78);

    if (iVar5 != 0) {

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 != '\0') {

        uVar7 = FUN_140241280(iVar5);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkCreateSamplerYcbcrConversionKHR()",uVar7);

      }

      uVar7 = FUN_140241280(iVar5);

      pcVar11 = "vkCreateSamplerYcbcrConversionKHR()";

      goto LAB_1401f8cb3;

    }

    local_b8 = *(undefined8 *)(lVar8 + 0x78);

    local_a0 = &local_c8;

    local_a8 = 0x1f;

    local_98 = 0;

    local_70 = 0;

    local_60 = 0;

    local_90 = 0;

    local_88 = 2;

    local_84 = 2;

    local_80 = 2;

    local_78 = 0;

    local_74 = 0x3f800000;

    local_68 = 0;

    local_64 = 0x447a0000;

    uStack_c4 = 0;

    uStack_c0 = 0;

    uStack_bc = 0;

    local_c8 = 0x3b9d2b61;

    iVar5 = (*DAT_1403fcf90)(*(undefined8 *)(lVar1 + 0x660),&local_a8,0,lVar8 + 0x80);

    if (iVar5 != 0) {

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 != '\0') {

        uVar7 = FUN_140241280(iVar5);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkCreateSampler()",uVar7);

      }

      uVar7 = FUN_140241280(iVar5);

      pcVar11 = "vkCreateSampler()";

      goto LAB_1401f8cb3;

    }

    iVar5 = FUN_1401f6570(lVar1,*(undefined8 *)(lVar8 + 0x80),lVar8 + 0x88,lVar8 + 0x90);

    if (iVar5 != 0) {

      return 0;

    }

  }

  *(uint *)(lVar8 + 0x70) = uVar14;

  *(uint *)(lVar8 + 0x74) = uVar12;

  local_c8 = (undefined4)uVar7;

  uStack_c4 = (undefined4)((ulonglong)uVar7 >> 0x20);

  uStack_c0 = (undefined4)uVar2;

  uStack_bc = (undefined4)((ulonglong)uVar2 >> 0x20);

  uVar10 = 0x17;

  if (param_2[9] != 2) {

    uVar10 = 7;

  }

  iVar5 = FUN_1401f6000(lVar1,param_3,uVar14,uVar12,uVar4,CONCAT44(uVar6,uVar10),&local_c8,

                        *(undefined8 *)(lVar8 + 0x78),lVar8);

  if (iVar5 == 0) {

    uVar6 = FUN_14014f530(param_2);

    FUN_140175360(uVar6,"SDL.texture.vulkan.texture",*(undefined8 *)(lVar8 + 8));

    if ((param_2[9] != 2) ||

       (iVar5 = FUN_1401f7010(param_1,param_2[1],param_2[2],uVar4,1,lVar8 + 0x10,lVar8 + 0x38,

                              lVar8 + 0x28), iVar5 == 0)) {

      return 1;

    }

    cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar3 != '\0') {

      uVar7 = FUN_140241280(iVar5);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","VULKAN_CreateFramebuffersAndRenderPasses()",uVar7);

    }

    uVar7 = FUN_140241280(iVar5);

    pcVar11 = "VULKAN_CreateFramebuffersAndRenderPasses()";

  }

  else {

    cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar3 != '\0') {

      uVar7 = FUN_140241280(iVar5);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","VULKAN_AllocateImage()",uVar7);

    }

    uVar7 = FUN_140241280(iVar5);

    pcVar11 = "VULKAN_AllocateImage()";

  }

LAB_1401f8cb3:

  FUN_14012e850("%s: %s",pcVar11,uVar7);

  return 0;

}




