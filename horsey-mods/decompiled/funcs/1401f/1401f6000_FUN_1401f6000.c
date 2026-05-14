// Address: 0x1401f6000
// Ghidra name: FUN_1401f6000
// ============ 0x1401f6000 FUN_1401f6000 (size=1138) ============


int FUN_1401f6000(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,undefined4 param_6,undefined4 *param_7,longlong param_8,

                 undefined8 *param_9)



{

  undefined4 uVar1;

  undefined8 *puVar2;

  char cVar3;

  int iVar4;

  undefined4 uVar5;

  longlong lVar6;

  undefined8 uVar7;

  undefined8 in_stack_fffffffffffffeb8;

  undefined4 *puVar8;

  undefined4 uVar9;

  undefined8 local_128;

  undefined8 uStack_120;

  undefined8 local_118;

  undefined4 uStack_110;

  undefined4 uStack_10c;

  undefined4 local_108;

  undefined4 uStack_104;

  undefined8 uStack_100;

  undefined8 local_f8;

  undefined4 uStack_f0;

  undefined4 uStack_ec;

  undefined4 uStack_e8;

  undefined4 uStack_e4;

  undefined8 uStack_e0;

  undefined8 local_d8;

  undefined4 local_c8;

  undefined4 local_c4;

  undefined8 *puStack_c0;

  undefined4 uStack_b8;

  undefined4 local_b4;

  undefined8 local_b0;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined4 uStack_9c;

  undefined4 uStack_98;

  undefined4 uStack_94;

  undefined8 local_90;

  undefined8 local_88;

  undefined8 local_80;

  undefined4 local_78;

  undefined8 local_74;

  undefined4 local_6c;

  undefined8 local_68;

  undefined4 local_60;

  undefined4 local_5c;

  undefined8 local_58;

  undefined8 uStack_50;

  ulonglong local_48;

  undefined8 local_40;

  undefined8 uStack_38;

  longlong local_30;

  

  puVar2 = param_9;

  uVar1 = param_5;

  uVar9 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);

  local_30 = 0;

  *param_9 = 0;

  param_9[1] = 0;

  param_9[2] = 0;

  param_9[3] = 0;

  param_9[4] = 0;

  *(undefined4 *)((longlong)param_9 + 0x24) = param_5;

  local_40 = 0;

  uStack_38 = 0;

  lVar6 = FUN_140174c40(param_2,"SDL.texture.create.vulkan.texture",0);

  puVar2[1] = lVar6;

  if (lVar6 == 0) {

    *(undefined1 *)puVar2 = 1;

    uStack_120 = 0;

    local_d8 = 0;

    uStack_e4 = 0;

    uStack_e0 = 0;

    uStack_ec = 0;

    uStack_e8 = 0;

    local_128 = 0xe;

    local_118 = 0x100000000;

    _uStack_110 = CONCAT44(param_3,uVar1);

    _local_108 = CONCAT44(1,param_4);

    uStack_100 = 0x100000001;

    local_f8 = 1;

    uStack_f0 = param_6;

    iVar4 = (*DAT_1403fcf70)(*(undefined8 *)(param_1 + 0x660),&local_128,0,puVar2 + 1);

    if (iVar4 != 0) {

      FUN_1401f9930(param_1,puVar2);

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 == '\0') {

        uVar7 = FUN_140241280(iVar4);

        FUN_14012e850("%s: %s","vkCreateImage()",uVar7);

        return iVar4;

      }

      uVar7 = FUN_140241280(iVar4);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateImage()",uVar7);

    }

    local_58 = 0;

    uStack_50 = 0;

    local_48 = 0;

    (*DAT_1403fd058)(*(undefined8 *)(param_1 + 0x660),puVar2[1],&local_58);

    puVar8 = &param_5;

    param_5 = 0;

    cVar3 = FUN_1401f9e70(param_1,local_48 & 0xffffffff,0,1,puVar8);

    uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);

    if (cVar3 == '\0') {

      FUN_1401f9930(param_1,puVar2);

      return -0xd;

    }

    local_68 = local_58;

    local_60 = param_5;

    local_74 = 0;

    local_6c = 0;

    local_5c = 0;

    local_78 = 5;

    iVar4 = (*DAT_1403fceb0)(*(undefined8 *)(param_1 + 0x660),&local_78,0,puVar2 + 3);

    if (iVar4 != 0) {

      FUN_1401f9930(param_1,puVar2);

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 == '\0') {

        uVar7 = FUN_140241280(iVar4);

        FUN_14012e850("%s: %s","vkAllocateMemory()",uVar7);

        return iVar4;

      }

      uVar7 = FUN_140241280(iVar4);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkAllocateMemory()",uVar7);

    }

    iVar4 = (*DAT_1403fcec8)(*(undefined8 *)(param_1 + 0x660),puVar2[1],puVar2[3],0);

    if (iVar4 != 0) {

      FUN_1401f9930(param_1,puVar2);

      cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar3 == '\0') {

        uVar7 = FUN_140241280(iVar4);

        FUN_14012e850("%s: %s","vkBindImageMemory()",uVar7);

        return iVar4;

      }

      uVar7 = FUN_140241280(iVar4);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkBindImageMemory()",uVar7);

    }

  }

  else {

    uVar5 = FUN_140174c40(param_2,"SDL.texture.create.vulkan.layout",5);

    *(undefined4 *)(puVar2 + 4) = uVar5;

  }

  if (*(int *)(puVar2 + 4) != 5) {

    FUN_1401f9dc0(param_1);

    FUN_1401fd560(param_1,0,0x20,0x80,CONCAT44(uVar9,0x80),5,puVar2[1],puVar2 + 4);

  }

  local_b0 = puVar2[1];

  local_c4 = 0;

  puStack_c0 = (undefined8 *)0x0;

  uStack_b8 = 0;

  local_b4 = 0;

  local_a0 = *param_7;

  uStack_9c = param_7[1];

  uStack_98 = param_7[2];

  uStack_94 = param_7[3];

  local_80 = 1;

  local_c8 = 0xf;

  local_a8 = 1;

  local_a4 = uVar1;

  local_90 = 1;

  local_88 = 1;

  if (param_8 != 0) {

    local_30 = param_8;

    puStack_c0 = &local_40;

    local_40 = CONCAT44(local_40._4_4_,0x3b9d2b61);

  }

  iVar4 = (*DAT_1403fcf78)(*(undefined8 *)(param_1 + 0x660),&local_c8,0,puVar2 + 2);

  if (iVar4 == 0) {

    iVar4 = 0;

  }

  else {

    FUN_1401f9930(param_1,puVar2);

    cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar3 != '\0') {

      uVar7 = FUN_140241280(iVar4);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateImageView()",uVar7);

    }

    uVar7 = FUN_140241280(iVar4);

    FUN_14012e850("%s: %s","vkCreateImageView()",uVar7);

  }

  return iVar4;

}




