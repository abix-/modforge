// Address: 0x1401f6570
// Ghidra name: FUN_1401f6570
// ============ 0x1401f6570 FUN_1401f6570 (size=502) ============


int FUN_1401f6570(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  longlong local_res10;

  undefined8 local_c8;

  undefined4 local_c0;

  undefined4 local_b8;

  undefined4 local_b4;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined8 local_a8;

  undefined4 local_a0;

  undefined4 local_9c;

  undefined4 local_98;

  undefined4 local_94;

  longlong *local_90;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  undefined4 local_7c;

  longlong *local_78;

  undefined4 local_68;

  undefined8 local_64;

  undefined8 local_5c;

  undefined4 local_54;

  undefined4 *local_50;

  undefined4 local_48;

  undefined8 local_44;

  undefined8 uStack_3c;

  undefined4 local_34;

  undefined8 local_30;

  undefined8 local_28;

  undefined8 *local_20;

  

  local_68 = 0x20;

  local_64 = 0;

  local_5c = 0;

  local_b8 = 0;

  local_b0 = 1;

  local_90 = &local_res10;

  if (param_2 == 0) {

    local_90 = (longlong *)0x0;

  }

  local_b4 = 6;

  local_50 = &local_b8;

  local_ac = 0x10;

  local_a8 = 0;

  local_a0 = 1;

  local_98 = 1;

  local_9c = 1;

  local_94 = 0x10;

  local_88 = 2;

  local_80 = 1;

  local_84 = 1;

  local_7c = 0x10;

  local_54 = 3;

  local_res10 = param_2;

  local_78 = local_90;

  iVar2 = (*DAT_1403fcf50)(*(undefined8 *)(param_1 + 0x660),&local_68,0,param_3);

  if (iVar2 == 0) {

    local_20 = &local_c8;

    local_28 = 1;

    local_c0 = 0x80;

    local_c8 = 1;

    local_44 = 0;

    uStack_3c = 0;

    local_48 = 0x1e;

    local_34 = 1;

    local_30 = param_3;

    iVar2 = (*DAT_1403fcf80)(*(undefined8 *)(param_1 + 0x660),&local_48,0,param_4);

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar1 != '\0') {

        uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkCreatePipelineLayout()",uVar3);

      }

      uVar3 = FUN_140241280(iVar2);

      FUN_14012e850("%s: %s","vkCreatePipelineLayout()",uVar3);

    }

  }

  else {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

      uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateDescriptorSetLayout()",uVar3);

    }

    uVar3 = FUN_140241280(iVar2);

    FUN_14012e850("%s: %s","vkCreateDescriptorSetLayout()",uVar3);

  }

  return iVar2;

}




