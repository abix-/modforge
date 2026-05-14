// Address: 0x1401f5090
// Ghidra name: FUN_1401f5090
// ============ 0x1401f5090 FUN_1401f5090 (size=834) ============


undefined8 FUN_1401f5090(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  

  FUN_140155450(param_1,param_3);

  if ((*(int *)(param_1 + 0x41) != 0x120005a0) && (*(int *)(param_1 + 0x41) != 0x12000500)) {

    uVar4 = FUN_14012e850("Unsupported output colorspace");

    return uVar4;

  }

  lVar5 = FUN_1401841a0(1,0x2988);

  if (lVar5 != 0) {

    *(undefined8 *)(lVar5 + 0x292c) = 0x3f800000;

    *(undefined8 *)(lVar5 + 0x2934) = 0;

    *(undefined8 *)(lVar5 + 0x293c) = 0x3f80000000000000;

    *(undefined8 *)(lVar5 + 0x2944) = 0;

    *(undefined4 *)(lVar5 + 0x294c) = 0;

    *(undefined4 *)(lVar5 + 0x2950) = 0;

    *(undefined4 *)(lVar5 + 0x2954) = 0x3f800000;

    *(undefined4 *)(lVar5 + 0x2958) = 0;

    *(undefined4 *)(lVar5 + 0x295c) = 0;

    *(undefined4 *)(lVar5 + 0x2960) = 0;

    *(undefined4 *)(lVar5 + 0x2964) = 0;

    *(undefined4 *)(lVar5 + 0x2968) = 0x3f800000;

    *(undefined8 *)(lVar5 + 0x296c) = 0;

    *(undefined8 *)(lVar5 + 0x2974) = 0;

    uVar2 = FUN_1401746e0();

    *(undefined4 *)(lVar5 + 0x6f0) = uVar2;

    cVar1 = FUN_1401745f0(param_3,uVar2);

    if (cVar1 == '\0') {

      FUN_1401841e0(lVar5);

    }

    else {

      param_1[0x5c] = lVar5;

      *param_1 = &LAB_1402000c0;

      param_1[2] = FUN_1401feff0;

      param_1[0xe] = FUN_1401f72b0;

      param_1[0xf] = FUN_1401ff330;

      param_1[0x10] = FUN_1401f99c0;

      param_1[3] = FUN_1401f8a10;

      param_1[0x12] = FUN_1401ff390;

      param_1[0x13] = FUN_1401ff8e0;

      param_1[0x14] = FUN_1401ff7b0;

      param_1[0x15] = FUN_1401fd130;

      param_1[0x16] = FUN_1401ff0c0;

      param_1[0x17] = FUN_1401fecc0;

      param_1[4] = FUN_140018e60;

      param_1[5] = FUN_140018e60;

      param_1[6] = FUN_1401e2950;

      param_1[7] = FUN_1401e2950;

      param_1[0xb] = FUN_1401fd220;

      param_1[0xc] = FUN_1401fabc0;

      param_1[0xd] = FUN_1401fded0;

      param_1[0x18] = FUN_1401fdb30;

      param_1[0x1f] = FUN_1401f5770;

      param_1[0x19] = FUN_1401fd680;

      param_1[0x1a] = FUN_1401f9a50;

      param_1[0x1b] = FUN_1401f9a00;

      param_1[0x1c] = &LAB_1401fedb0;

      FUN_1401fabc0(param_1);

      param_1[0x20] = PTR_s_vulkan_1403e4c38;

      FUN_14014b7f0(param_1,0x16362004);

      FUN_14014b7f0(param_1,0x16762004);

      FUN_14014b7f0(param_1,0x16772004);

      FUN_14014b7f0(param_1,0x1a204008);

      FUN_14014b7f0(param_1,0x13000801);

      uVar2 = FUN_14014f090(param_1);

      FUN_140175360(uVar2,"SDL.renderer.max_texture_size",0x4000);

      param_1[0x23] = param_2;

      iVar3 = FUN_1401f6770(param_1,param_3);

      if ((iVar3 == 0) && (iVar3 = FUN_1401f8fa0(param_1), iVar3 == 0)) {

        if (*(char *)(lVar5 + 0x2872) != '\0') {

          FUN_14014b7f0(param_1,0x32315659);

          FUN_14014b7f0(param_1,0x56555949);

          FUN_14014b7f0(param_1,0x3231564e);

          FUN_14014b7f0(param_1,0x3132564e);

          FUN_14014b7f0(param_1,0x30313050);

        }

        return 1;

      }

    }

  }

  return 0;

}




