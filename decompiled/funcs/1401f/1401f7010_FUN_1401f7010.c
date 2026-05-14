// Address: 0x1401f7010
// Ghidra name: FUN_1401f7010
// ============ 0x1401f7010 FUN_1401f7010 (size=666) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_1401f7010(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                 int param_5,longlong param_6,longlong param_7,longlong param_8)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  char *pcVar5;

  uint uVar6;

  ulonglong uVar7;

  undefined4 local_res8;

  undefined4 local_resc;

  undefined4 local_148;

  undefined4 local_144;

  undefined4 local_140;

  undefined4 local_13c;

  undefined4 local_138;

  undefined4 local_134;

  undefined4 local_130;

  undefined4 local_128;

  undefined4 local_124;

  undefined4 local_120;

  undefined8 local_11c;

  undefined8 uStack_114;

  undefined4 local_10c;

  undefined4 local_108;

  undefined4 local_f8;

  undefined8 local_f4;

  undefined8 local_ec;

  undefined4 local_e4;

  undefined4 *local_e0;

  undefined8 local_d8;

  undefined8 *local_d0;

  undefined8 local_c8;

  undefined4 *local_c0;

  undefined8 local_b8;

  undefined8 local_b0;

  undefined8 local_a8;

  undefined8 local_a0;

  undefined4 local_98;

  undefined4 local_94;

  longlong local_90;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  undefined4 local_7c;

  undefined8 local_78;

  undefined8 local_70;

  undefined8 local_68;

  undefined8 local_60;

  undefined4 *local_58;

  undefined8 local_50;

  undefined8 local_48;

  undefined8 local_40;

  undefined8 local_38;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_58 = &local_res8;

  uVar7 = 0;

  local_e0 = &local_128;

  local_d0 = &local_78;

  local_10c = 2;

  local_c0 = &local_148;

  local_108 = 2;

  local_11c = _DAT_14034a8b0;

  uStack_114 = _UNK_14034a8b8;

  local_120 = 1;

  local_128 = 0;

  local_res8 = 0;

  local_resc = 2;

  local_70 = 0;

  local_60 = 1;

  local_40 = 0;

  local_78 = 0;

  local_68 = 0;

  local_50 = 0;

  local_48 = 0;

  local_38 = 0;

  local_148 = 0xffffffff;

  local_144 = 0;

  local_140 = 0x400;

  local_13c = 0x400;

  local_138 = 0x100;

  local_134 = 0x180;

  local_130 = 1;

  local_f4 = 0;

  local_ec = 0;

  local_d8 = 1;

  local_c8 = 1;

  local_f8 = 0x26;

  local_e4 = 1;

  local_124 = param_4;

  iVar3 = (*DAT_1403fcf88)(*(undefined8 *)(lVar1 + 0x660),&local_f8,0,param_8);

  if (iVar3 == 0) {

    local_11c = CONCAT44(local_11c._4_4_,1);

    iVar3 = (*DAT_1403fcf88)(*(undefined8 *)(lVar1 + 0x660),&local_f8,0,param_8 + 8);

    if (iVar3 == 0) {

      local_b8 = 0x25;

      local_a8 = 0;

      local_94 = 0;

      local_7c = 0;

      local_b0 = 0;

      local_a0 = *(undefined8 *)(lVar1 + 0x700);

      local_98 = 1;

      local_80 = 1;

      local_88 = param_2;

      local_84 = param_3;

      if (0 < param_5) {

        do {

          local_90 = uVar7 * 8 + param_6;

          iVar3 = (*DAT_1403fcf60)(*(undefined8 *)(lVar1 + 0x660),&local_b8,0,uVar7 * 8 + param_7);

          if (iVar3 != 0) {

            cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

            if (cVar2 != '\0') {

              uVar4 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

              FUN_14012e0b0(6,"%s: %s","vkCreateFramebuffer()",uVar4);

            }

            uVar4 = FUN_140241280(iVar3);

            pcVar5 = "vkCreateFramebuffer()";

            goto LAB_1401f7181;

          }

          uVar6 = (int)uVar7 + 1;

          uVar7 = (ulonglong)uVar6;

        } while ((int)uVar6 < param_5);

      }

      return 0;

    }

  }

  cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar2 != '\0') {

    uVar4 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,"%s: %s","vkCreateRenderPass()",uVar4);

  }

  uVar4 = FUN_140241280(iVar3);

  pcVar5 = "vkCreateRenderPass()";

LAB_1401f7181:

  FUN_14012e850("%s: %s",pcVar5,uVar4);

  return iVar3;

}




