// Address: 0x1401f58a0
// Ghidra name: FUN_1401f58a0
// ============ 0x1401f58a0 FUN_1401f58a0 (size=779) ============


int FUN_1401f58a0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,

                 undefined4 param_5,undefined8 *param_6)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  undefined4 local_res18 [4];

  undefined4 *puVar4;

  undefined8 local_98;

  undefined8 uStack_90;

  ulonglong local_88;

  undefined4 local_80;

  undefined8 local_7c;

  undefined4 local_74;

  undefined8 local_70;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined8 local_5c;

  undefined8 uStack_54;

  undefined4 local_4c;

  undefined8 local_48;

  undefined4 local_40;

  undefined8 local_3c;

  undefined8 uStack_34;

  undefined4 local_2c;

  

  local_60 = 0xc;

  local_4c = 0;

  local_5c = 0;

  uStack_54 = 0;

  local_2c = 0;

  local_3c = 0;

  uStack_34 = 0;

  local_48 = param_2;

  local_40 = param_3;

  iVar2 = (*DAT_1403fcf38)(*(undefined8 *)(param_1 + 0x660),&local_60,0,param_6 + 1);

  if (iVar2 == 0) {

    local_98 = 0;

    uStack_90 = 0;

    local_88 = 0;

    (*DAT_1403fd050)(*(undefined8 *)(param_1 + 0x660),param_6[1],&local_98);

    puVar4 = local_res18;

    local_res18[0] = 0;

    cVar1 = FUN_1401f9e70(param_1,local_88 & 0xffffffff,param_4,param_5,puVar4);

    if (cVar1 == '\0') {

      FUN_1401f98d0(param_1,param_6);

      iVar2 = -0xd;

    }

    else {

      local_70 = local_98;

      local_68 = local_res18[0];

      local_7c = 0;

      local_74 = 0;

      local_64 = 0;

      local_80 = 5;

      iVar2 = (*DAT_1403fceb0)(*(undefined8 *)(param_1 + 0x660),&local_80,0,param_6);

      if (iVar2 == 0) {

        iVar2 = (*DAT_1403fcec0)(*(undefined8 *)(param_1 + 0x660),param_6[1],*param_6,0);

        if (iVar2 == 0) {

          iVar2 = (*DAT_1403fd078)(*(undefined8 *)(param_1 + 0x660),*param_6,0,param_2,

                                   (ulonglong)puVar4 & 0xffffffff00000000,param_6 + 3);

          if (iVar2 == 0) {

            param_6[2] = param_2;

            iVar2 = 0;

          }

          else {

            FUN_1401f98d0(param_1,param_6);

            cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

            if (cVar1 != '\0') {

              uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

              FUN_14012e0b0(6,"%s: %s","vkMapMemory()",uVar3);

            }

            uVar3 = FUN_140241280(iVar2);

            FUN_14012e850("%s: %s","vkMapMemory()",uVar3);

          }

        }

        else {

          FUN_1401f98d0(param_1,param_6);

          cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

          if (cVar1 != '\0') {

            uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

            FUN_14012e0b0(6,"%s: %s","vkBindBufferMemory()",uVar3);

          }

          uVar3 = FUN_140241280(iVar2);

          FUN_14012e850("%s: %s","vkBindBufferMemory()",uVar3);

        }

      }

      else {

        FUN_1401f98d0(param_1,param_6);

        cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

        if (cVar1 != '\0') {

          uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(6,"%s: %s","vkAllocateMemory()",uVar3);

        }

        uVar3 = FUN_140241280(iVar2);

        FUN_14012e850("%s: %s","vkAllocateMemory()",uVar3);

      }

    }

  }

  else {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 != '\0') {

      uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateBuffer()",uVar3);

    }

    uVar3 = FUN_140241280(iVar2);

    FUN_14012e850("%s: %s","vkCreateBuffer()",uVar3);

  }

  return iVar2;

}




