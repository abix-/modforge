// Address: 0x140202720
// Ghidra name: FUN_140202720
// ============ 0x140202720 FUN_140202720 (size=1396) ============


undefined8 FUN_140202720(longlong param_1,longlong param_2,undefined4 param_3)



{

  undefined1 uVar1;

  undefined1 uVar2;

  char cVar3;

  undefined4 uVar4;

  undefined8 uVar5;

  undefined1 *puVar6;

  longlong lVar7;

  ulonglong uVar8;

  undefined8 uVar9;

  undefined4 local_res8 [2];

  undefined4 local_res20 [2];

  

  FUN_140155450(param_1,param_3);

  if ((*(int *)(param_1 + 0x208) != 0x120005a0) && (*(int *)(param_1 + 0x208) != 0x12000500)) {

    uVar5 = FUN_14012e850("Unsupported output colorspace");

    return uVar5;

  }

  puVar6 = (undefined1 *)FUN_1401841a0(1,0x158);

  if (puVar6 != (undefined1 *)0x0) {

    *(undefined1 **)(param_1 + 0x2e0) = puVar6;

    *(code **)(param_1 + 0x10) = FUN_140204a00;

    *(longlong *)(param_1 + 0x118) = param_2;

    *(code **)(param_1 + 0x70) = FUN_140203540;

    *(code **)(param_1 + 0x78) = FUN_140204b80;

    *(code **)(param_1 + 0x80) = FUN_140203a40;

    *(code **)(param_1 + 0x18) = FUN_1402035f0;

    *(code **)(param_1 + 0x90) = FUN_140204cb0;

    *(code **)(param_1 + 0x98) = FUN_140205350;

    *(code **)(param_1 + 0xa0) = FUN_1402051e0;

    *(undefined1 **)(param_1 + 0xa8) = &LAB_140203ca0;

    *(code **)(param_1 + 0xb0) = FUN_140204ae0;

    *(undefined1 **)(param_1 + 0xb8) = &LAB_140204930;

    *(code **)(param_1 + 0x20) = FUN_140018e60;

    *(code **)(param_1 + 0x28) = FUN_140018e60;

    *(code **)(param_1 + 0x30) = FUN_140203d20;

    *(code **)(param_1 + 0x38) = FUN_140203d20;

    *(code **)(param_1 + 0x58) = FUN_140203f70;

    *(undefined1 **)(param_1 + 0x60) = &LAB_140203c90;

    *(code **)(param_1 + 0x68) = FUN_1402045a0;

    *(code **)(param_1 + 0xc0) = FUN_140204280;

    *(code **)(param_1 + 200) = FUN_140204140;

    *(code **)(param_1 + 0xd0) = FUN_140203be0;

    *(code **)(param_1 + 0xd8) = FUN_140203a80;

    *(code **)(param_1 + 0xe0) = FUN_140204950;

    *(undefined **)(param_1 + 0x100) = PTR_DAT_1403e4c88;

    lVar7 = FUN_140174d30(param_3,"SDL.renderer.create.gpu.device",0);

    *(longlong *)(puVar6 + 8) = lVar7;

    if (lVar7 == 0) {

      uVar1 = FUN_1401749e0(param_3,"SDL.gpu.device.create.debugmode",0);

      uVar2 = FUN_1401749e0(param_3,"SDL.gpu.device.create.preferlowpower",0);

      uVar1 = FUN_140142940("SDL_RENDER_GPU_DEBUG",uVar1);

      uVar2 = FUN_140142940("SDL_RENDER_GPU_LOW_POWER",uVar2);

      FUN_140175280(param_3,"SDL.gpu.device.create.debugmode",uVar1);

      FUN_140175280(param_3,"SDL.gpu.device.create.preferlowpower",uVar2);

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.name");

      if ((cVar3 == '\0') && (uVar8 = FUN_14016e130(param_2), (uVar8 >> 0x1c & 1) != 0)) {

        FUN_140175500(param_3,"SDL.gpu.device.create.name","vulkan");

      }

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.d3d12.allowtier1resourcebinding");

      if (cVar3 == '\0') {

        FUN_140175280(param_3,"SDL.gpu.device.create.d3d12.allowtier1resourcebinding",1);

      }

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.feature.clip_distance");

      if (cVar3 == '\0') {

        FUN_140175280(param_3,"SDL.gpu.device.create.feature.clip_distance",0);

      }

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.feature.depth_clamping");

      if (cVar3 == '\0') {

        FUN_140175280(param_3,"SDL.gpu.device.create.feature.depth_clamping",0);

      }

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.feature.indirect_draw_first_instance");

      if (cVar3 == '\0') {

        FUN_140175280(param_3,"SDL.gpu.device.create.feature.indirect_draw_first_instance",0);

      }

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.feature.anisotropy");

      if (cVar3 == '\0') {

        FUN_140175280(param_3,"SDL.gpu.device.create.feature.anisotropy",0);

      }

      cVar3 = FUN_140174fc0(param_3,"SDL.gpu.device.create.metal.allowmacfamily1");

      if (cVar3 == '\0') {

        FUN_140175280(param_3,"SDL.gpu.device.create.metal.allowmacfamily1",0);

      }

      FUN_140263230(param_3);

      lVar7 = FUN_140134880(param_3);

      *(longlong *)(puVar6 + 8) = lVar7;

      if (lVar7 == 0) {

        return 0;

      }

    }

    else {

      *puVar6 = 1;

    }

    cVar3 = FUN_140263320(puVar6 + 0x10,lVar7);

    if (((cVar3 != '\0') &&

        (cVar3 = FUN_1402635a0(puVar6 + 0x50,*(undefined8 *)(puVar6 + 8)), cVar3 != '\0')) &&

       (cVar3 = FUN_140205680(puVar6,0x10000), cVar3 != '\0')) {

      if (param_2 == 0) {

LAB_140202b7f:

        FUN_14014b7f0(param_1,0x16362004);

        FUN_14014b7f0(param_1,0x16762004);

        FUN_14014b7f0(param_1,0x16161804);

        FUN_14014b7f0(param_1,0x16561804);

        FUN_14014b7f0(param_1,0x16772004);

        FUN_14014b7f0(param_1,0x1a204008);

        FUN_14014b7f0(param_1,0x13000801);

        FUN_14014b7f0(param_1,0x32315659);

        FUN_14014b7f0(param_1,0x56555949);

        FUN_14014b7f0(param_1,0x3231564e);

        FUN_14014b7f0(param_1,0x3132564e);

        FUN_14014b7f0(param_1,0x30313050);

        uVar4 = FUN_14014f090(param_1);

        FUN_140175360(uVar4,"SDL.renderer.max_texture_size",0x4000);

        *(undefined4 *)(puVar6 + 0xf8) = 0;

        *(undefined4 *)(puVar6 + 0xfc) = 0x3f800000;

        uVar9 = FUN_140132770(*(undefined8 *)(puVar6 + 8));

        uVar5 = *(undefined8 *)(puVar6 + 8);

        *(undefined8 *)(puVar6 + 0xa0) = uVar9;

        uVar4 = FUN_14014f090(param_1);

        FUN_140175480(uVar4,"SDL.renderer.gpu.device",uVar5);

        return 1;

      }

      cVar3 = FUN_140134250(*(undefined8 *)(puVar6 + 8),param_2);

      if (cVar3 != '\0') {

        if (*(int *)(param_1 + 0x208) == 0x12000500) {

          *(undefined4 *)(puVar6 + 0x70) = 2;

        }

        else if (*(int *)(param_1 + 0x208) == 0x12002600) {

          *(undefined4 *)(puVar6 + 0x70) = 3;

        }

        else {

          *(undefined4 *)(puVar6 + 0x70) = 0;

        }

        *(undefined4 *)(puVar6 + 0x74) = 0;

        uVar4 = FUN_140174c40(param_3,"SDL.renderer.create.present_vsync",0);

        FUN_140202f30(*(undefined8 *)(puVar6 + 8),param_2,uVar4,puVar6 + 0x74);

        FUN_140138370(*(undefined8 *)(puVar6 + 8),param_2,*(undefined4 *)(puVar6 + 0x70),

                      *(undefined4 *)(puVar6 + 0x74));

        FUN_140138070(*(undefined8 *)(puVar6 + 8),1);

        FUN_14016ebe0(param_2,local_res20,local_res8);

        uVar4 = FUN_140137880(*(undefined8 *)(puVar6 + 8),param_2);

        cVar3 = FUN_140202fc0(puVar6,local_res20[0],local_res8[0],uVar4);

        if (cVar3 != '\0') goto LAB_140202b7f;

      }

    }

  }

  return 0;

}




