// Address: 0x1401f6770
// Ghidra name: FUN_1401f6770
// ============ 0x1401f6770 FUN_1401f6770 (size=2196) ============


int FUN_1401f6770(longlong param_1,undefined4 param_2)



{

  uint uVar1;

  longlong *plVar2;

  char cVar3;

  char cVar4;

  undefined1 uVar5;

  undefined4 uVar6;

  int iVar7;

  longlong lVar8;

  undefined **ppuVar9;

  undefined8 uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  uint uVar13;

  char *local_res18 [2];

  undefined4 local_128;

  undefined4 uStack_124;

  undefined4 uStack_120;

  undefined4 uStack_11c;

  uint local_118;

  undefined4 uStack_114;

  undefined4 uStack_110;

  undefined4 uStack_10c;

  undefined4 local_108;

  undefined4 uStack_104;

  undefined4 uStack_100;

  undefined4 local_fc;

  undefined4 local_f8;

  undefined4 local_f4;

  undefined8 uStack_f0;

  undefined4 uStack_e8;

  undefined4 local_e4;

  undefined4 *local_e0;

  undefined8 local_d8;

  char **ppcStack_d0;

  ulonglong local_c8;

  undefined **ppuStack_c0;

  undefined8 local_b8;

  undefined4 local_a8;

  undefined8 local_a4;

  undefined4 local_9c;

  undefined4 local_98;

  undefined4 local_94;

  undefined4 local_88 [2];

  undefined8 local_80;

  longlong lStack_78;

  undefined8 local_70;

  undefined *puStack_68;

  undefined4 local_60;

  undefined8 local_58;

  longlong lStack_50;

  ulonglong local_48;

  undefined *puStack_40;

  

  plVar2 = *(longlong **)(param_1 + 0x2e0);

  cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  local_res18[0] = "VK_LAYER_KHRONOS_validation";

  cVar4 = FUN_140174130(0);

  if (cVar4 == '\0') {

    FUN_14012e080(6,"SDL_Vulkan_LoadLibrary failed");

    return -0xd;

  }

  lVar8 = FUN_1401740e0();

  if (lVar8 == 0) {

    FUN_14012e080(6,"vkGetInstanceProcAddr is NULL");

    return -0xd;

  }

  *plVar2 = lVar8;

  cVar4 = FUN_1401fc9a0(plVar2);

  if (cVar4 == '\0') {

    return -0xd;

  }

  *(undefined1 *)(plVar2 + 0x50e) = 0;

  if ((*(int *)(param_1 + 0x208) == 0x12000500) || (*(int *)(param_1 + 0x208) == 0x12002600)) {

    cVar4 = FUN_1401faa50(plVar2,"VK_EXT_swapchain_colorspace");

    *(char *)(plVar2 + 0x50e) = cVar4;

    if (cVar4 == '\0') {

      FUN_14012e850("Using HDR output but %s not supported","VK_EXT_swapchain_colorspace");

      return -0xd;

    }

  }

  uVar5 = FUN_1401faa50(plVar2,"VK_KHR_get_physical_device_properties2");

  *(undefined1 *)((longlong)plVar2 + 0x2871) = uVar5;

  lVar8 = FUN_140174d30(param_2,"SDL.renderer.create.vulkan.instance",0);

  uVar12 = 0;

  plVar2[1] = lVar8;

  if (lVar8 == 0) {

    local_f4 = 0;

    uStack_f0._0_4_ = 0;

    local_d8 = 0;

    ppcStack_d0 = (char **)0x0;

    local_e0 = &local_128;

    local_c8 = 0;

    ppuStack_c0 = (undefined **)0x0;

    uStack_124 = 0;

    uStack_120 = 0;

    uStack_11c = 0;

    local_118 = 0;

    uStack_f0._4_4_ = 0;

    uStack_e8 = 0;

    uStack_114 = 0;

    uStack_110 = 0;

    uStack_10c = 0;

    local_108 = 0;

    local_e4 = 0;

    uStack_104 = 0;

    uStack_100 = 0;

    local_128 = 0;

    local_fc = 0x400000;

    local_f8 = 1;

    lVar8 = FUN_140174040(&local_c8);

    ppuVar9 = (undefined **)FUN_1401841a0((uint)local_c8 + 2,8);

    uVar11 = uVar12;

    if ((uint)local_c8 != 0) {

      do {

        uVar13 = (int)uVar11 + 1;

        ppuVar9[uVar11] = *(undefined **)(uVar11 * 8 + lVar8);

        uVar11 = (ulonglong)uVar13;

      } while (uVar13 < (uint)local_c8);

    }

    uVar11 = local_c8 & 0xffffffff;

    if ((char)plVar2[0x50e] != '\0') {

      ppuVar9[uVar11] = "VK_EXT_swapchain_colorspace";

      uVar11 = (ulonglong)((uint)local_c8 + 1);

      local_c8 = CONCAT44(local_c8._4_4_,(uint)local_c8 + 1);

    }

    if (*(char *)((longlong)plVar2 + 0x2871) != '\0') {

      ppuVar9[uVar11] = "VK_KHR_get_physical_device_properties2";

      local_c8 = CONCAT44(local_c8._4_4_,(uint)local_c8 + 1);

    }

    ppuStack_c0 = ppuVar9;

    if ((cVar3 != '\0') && (cVar3 = FUN_1401fffa0(), cVar3 != '\0')) {

      ppcStack_d0 = local_res18;

      local_d8 = CONCAT44(local_d8._4_4_,1);

    }

    iVar7 = (*DAT_1403fd0c8)(&local_f8,0,plVar2 + 1);

    FUN_1401841e0(ppuVar9);

    if (iVar7 != 0) {

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 == '\0') {

        uVar10 = FUN_140241280(iVar7);

        FUN_14012e850("%s: %s","vkCreateInstance()",uVar10);

        return iVar7;

      }

      uVar10 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateInstance()",uVar10);

    }

  }

  else {

    *(undefined1 *)(plVar2 + 2) = 1;

  }

  cVar3 = FUN_1401fcae0(plVar2);

  if (cVar3 == '\0') {

LAB_1401f6fce:

    FUN_1401f9010(param_1);

    iVar7 = -0xd;

  }

  else {

    lVar8 = FUN_140174c40(param_2,"SDL.renderer.create.vulkan.surface",0);

    plVar2[3] = lVar8;

    if (lVar8 == 0) {

      cVar3 = FUN_140173eb0(*(undefined8 *)(param_1 + 0x118),plVar2[1],0,plVar2 + 3);

      if (cVar3 == '\0') goto LAB_1401f6fce;

    }

    else {

      *(undefined1 *)(plVar2 + 4) = 1;

    }

    lVar8 = FUN_140174d30(param_2,"SDL.renderer.create.vulkan.physical_device",0);

    plVar2[5] = lVar8;

    if (lVar8 == 0) {

      iVar7 = FUN_1401f9f40(plVar2);

      if (iVar7 != 0) goto LAB_1401f6fce;

    }

    else {

      (*DAT_1403fd120)(lVar8,plVar2 + 0x6d);

      (*DAT_1403fd110)(plVar2[5],plVar2 + 0xae);

    }

    cVar3 = FUN_140174fc0(param_2,"SDL.renderer.create.vulkan.graphics_queue_family_index");

    if (cVar3 != '\0') {

      uVar6 = FUN_140174c40(param_2,"SDL.renderer.create.vulkan.graphics_queue_family_index",0);

      *(undefined4 *)((longlong)plVar2 + 0x66c) = uVar6;

    }

    cVar3 = FUN_140174fc0(param_2,"SDL.renderer.create.vulkan.present_queue_family_index");

    if (cVar3 != '\0') {

      uVar6 = FUN_140174c40(param_2,"SDL.renderer.create.vulkan.present_queue_family_index",0);

      *(undefined4 *)(plVar2 + 0xce) = uVar6;

    }

    if ((*(char *)((longlong)plVar2 + 0x2871) != '\0') &&

       (cVar3 = FUN_1401f9bc0(plVar2,4,&PTR_s_VK_KHR_sampler_ycbcr_conversion_14034d530),

       cVar3 != '\0')) {

      *(undefined1 *)((longlong)plVar2 + 0x2872) = 1;

    }

    lVar8 = FUN_140174d30(param_2,"SDL.renderer.create.vulkan.device",0);

    plVar2[0xcc] = lVar8;

    if (lVar8 == 0) {

      cVar3 = *(char *)((longlong)plVar2 + 0x2872);

      local_60 = 0;

      uStack_114 = 0;

      local_e0 = local_88;

      local_f4 = 0;

      uStack_f0 = (undefined4 *)0x0;

      uStack_e8 = 0;

      local_d8 = 0;

      ppcStack_d0 = (char **)0x0;

      uVar13 = 1;

      if (cVar3 != '\0') {

        uVar13 = 5;

      }

      uVar1 = *(uint *)(plVar2 + 0xce);

      local_c8 = (ulonglong)uVar13;

      ppuStack_c0 = &PTR_s_VK_KHR_swapchain_14034d528;

      uVar13 = *(uint *)((longlong)plVar2 + 0x66c);

      local_f8 = 3;

      local_b8 = 0;

      local_88[0] = 2;

      local_70 = 1;

      puStack_68 = &DAT_14034d524;

      local_e4 = 1;

      local_80 = 0;

      lStack_78 = (ulonglong)uVar13 << 0x20;

      local_128 = 0;

      uStack_124 = 0;

      local_58 = 0;

      lStack_50 = 0;

      puStack_40 = (undefined *)0x0;

      if (uVar1 != uVar13) {

        local_60 = 2;

        lStack_50 = (ulonglong)uVar1 << 0x20;

        puStack_40 = &DAT_14034d524;

        local_e4 = 2;

      }

      local_48 = (ulonglong)(uVar1 != uVar13);

      if (cVar3 != '\0') {

        uStack_f0 = &local_128;

        local_128 = 0x3b9d2b64;

      }

      local_118 = (uint)(cVar3 != '\0');

      uStack_11c = 0;

      uStack_120 = 0;

      iVar7 = (*DAT_1403fd0e0)(plVar2[5],&local_f8,0);

      if (iVar7 == 0) goto LAB_1401f6b73;

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 != '\0') {

        uVar10 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkCreateDevice()",uVar10);

      }

      uVar10 = FUN_140241280(iVar7);

      FUN_14012e850("%s: %s","vkCreateDevice()",uVar10);

    }

    else {

      *(undefined1 *)(plVar2 + 0xcd) = 1;

LAB_1401f6b73:

      cVar3 = FUN_1401fad70(plVar2);

      if (cVar3 == '\0') goto LAB_1401f6fce;

      (*DAT_1403fd060)(plVar2[0xcc],*(undefined4 *)((longlong)plVar2 + 0x66c),0,plVar2 + 0xca);

      if (*(int *)((longlong)plVar2 + 0x66c) == (int)plVar2[0xce]) {

        plVar2[0xcb] = plVar2[0xca];

      }

      else {

        (*DAT_1403fd060)(plVar2[0xcc],(int)plVar2[0xce],0,plVar2 + 0xcb);

      }

      local_a4 = 0;

      local_9c = 0;

      local_a8 = 0x27;

      local_98 = 2;

      local_94 = *(undefined4 *)((longlong)plVar2 + 0x66c);

      iVar7 = (*DAT_1403fcf40)(plVar2[0xcc],&local_a8,0,plVar2 + 0xd0);

      if (iVar7 != 0) {

        FUN_1401f9010(param_1);

        cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

        if (cVar3 == '\0') {

          uVar10 = FUN_140241280(iVar7);

          FUN_14012e850("%s: %s","vkCreateCommandPool()",uVar10);

          return iVar7;

        }

        uVar10 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkCreateCommandPool()",uVar10);

      }

      iVar7 = FUN_1401fa7f0(plVar2);

      uVar11 = uVar12;

      if (iVar7 != 0) {

        FUN_1401f9010(param_1);

        return 0;

      }

      do {

        uStack_124 = 0;

        uStack_120 = 0;

        uStack_11c = 0;

        local_128 = 0x10;

        local_118 = 0;

        uStack_114 = 0;

        uStack_110 = 0;

        uStack_10c = 0;

        local_108 = 0;

        uStack_104 = 0;

        FUN_140241530(uVar11,&local_108,&uStack_110);

        iVar7 = (*DAT_1403fcfa0)(plVar2[0xcc],&local_128,0,plVar2 + uVar11 + 0xe3);

        if (iVar7 != 0) {

LAB_1401f6f6d:

          FUN_1401f9010(param_1);

          cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

          if (cVar3 == '\0') {

            uVar10 = FUN_140241280(iVar7);

            FUN_14012e850("%s: %s","vkCreateShaderModule()",uVar10);

            return iVar7;

          }

          uVar10 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(6,"%s: %s","vkCreateShaderModule()",uVar10);

        }

        FUN_140241510(uVar11,&local_108,&uStack_110);

        iVar7 = (*DAT_1403fcfa0)(plVar2[0xcc],&local_128,0,plVar2 + uVar11 + 0xe6);

        if (iVar7 != 0) goto LAB_1401f6f6d;

        uVar13 = (int)uVar11 + 1;

        uVar11 = (ulonglong)uVar13;

      } while (uVar13 < 3);

      iVar7 = FUN_1401f6570(plVar2,0,plVar2 + 0xe9,plVar2 + 0xea);

      if (iVar7 == 0) {

        lVar8 = 0x100;

        do {

          FUN_1401f8f40(plVar2,uVar12,0x10000);

          uVar12 = uVar12 + 1;

          lVar8 = lVar8 + -1;

        } while (lVar8 != 0);

        uVar6 = FUN_14014f090(param_1);

        FUN_140175480(uVar6,"SDL.renderer.vulkan.instance",plVar2[1]);

        FUN_140175360(uVar6,"SDL.renderer.vulkan.surface",plVar2[3]);

        FUN_140175480(uVar6,"SDL.renderer.vulkan.physical_device",plVar2[5]);

        FUN_140175480(uVar6,"SDL.renderer.vulkan.device",plVar2[0xcc]);

        FUN_140175360(uVar6,"SDL.renderer.vulkan.graphics_queue_family_index",

                      *(undefined4 *)((longlong)plVar2 + 0x66c));

        FUN_140175360(uVar6,"SDL.renderer.vulkan.present_queue_family_index",(int)plVar2[0xce]);

        return 0;

      }

    }

    FUN_1401f9010(param_1);

  }

  return iVar7;

}




