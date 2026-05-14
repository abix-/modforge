// Address: 0x1401fd680
// Ghidra name: FUN_1401fd680
// ============ 0x1401fd680 FUN_1401fd680 (size=1186) ============


undefined8 FUN_1401fd680(longlong param_1)



{

  longlong *plVar1;

  longlong *plVar2;

  uint uVar3;

  longlong lVar4;

  longlong lVar5;

  char cVar6;

  int iVar7;

  undefined8 uVar8;

  undefined4 *puVar9;

  ulonglong uVar10;

  char *pcVar11;

  undefined4 local_res8 [2];

  undefined4 local_b8;

  undefined8 local_b4;

  longlong local_ac;

  undefined4 local_a4;

  longlong *plStack_a0;

  undefined4 uStack_98;

  undefined4 local_94;

  undefined4 local_90;

  undefined4 local_8c;

  longlong *local_88;

  int local_80;

  undefined4 local_7c;

  undefined8 *local_78;

  undefined4 local_68;

  undefined8 local_64;

  undefined4 local_5c;

  undefined8 local_58;

  longlong local_50;

  undefined8 local_48;

  longlong local_40;

  uint *local_38;

  undefined8 local_30;

  

  lVar4 = *(longlong *)(param_1 + 0x2e0);

  if (*(longlong *)(lVar4 + 0x660) == 0) {

    uVar8 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar8;

  }

  plVar1 = (longlong *)(lVar4 + 0x698);

  if (*plVar1 == 0) {

    return 1;

  }

  uVar10 = (ulonglong)*(uint *)(lVar4 + 0x28c8);

  *(undefined8 *)(lVar4 + 0x2868) = 0;

  *(undefined1 *)(lVar4 + 0x2928) = 1;

  FUN_1401fd560(lVar4,0x100,0x180,0x400,0x400,0x3b9acdea,

                *(undefined8 *)(*(longlong *)(lVar4 + 0x2898) + uVar10 * 8),

                *(longlong *)(lVar4 + 0x28a8) + uVar10 * 4);

  (*DAT_1403fd038)(*plVar1);

  iVar7 = (*DAT_1403fd0a8)(*(undefined8 *)(lVar4 + 0x660),1,

                           *(longlong *)(lVar4 + 0x6a0) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8);

  if (iVar7 != 0) {

    cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar6 != '\0') {

      uVar8 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkResetFences()",uVar8);

    }

    uVar8 = FUN_140241280(iVar7);

    FUN_14012e850("%s: %s","vkResetFences()",uVar8);

    return 0;

  }

  uVar3 = *(uint *)(lVar4 + 0x28e0);

  plVar2 = (longlong *)(lVar4 + 0x28c0);

  lVar5 = *plVar2;

  local_res8[0] = 0x10000;

  local_b4 = 0;

  local_ac = 0;

  local_a4 = 0;

  plStack_a0 = (longlong *)0x0;

  uStack_98 = 0;

  local_94 = 0;

  local_8c = 0;

  local_7c = 0;

  local_b8 = 4;

  if (uVar3 == 0) {

    if (lVar5 != 0) {

      puVar9 = local_res8;

      uVar10 = 1;

      goto LAB_1401fd87c;

    }

  }

  else {

    uVar10 = (ulonglong)((lVar5 != 0) + uVar3);

    if (lVar5 != 0) {

      *(longlong *)(*(longlong *)(lVar4 + 0x28d8) + (ulonglong)uVar3 * 8) = lVar5;

      *(undefined4 *)(*(longlong *)(lVar4 + 0x28d0) + (ulonglong)*(uint *)(lVar4 + 0x28e0) * 4) =

           0x10000;

    }

    plVar2 = *(longlong **)(lVar4 + 0x28d8);

    puVar9 = *(undefined4 **)(lVar4 + 0x28d0);

    *(undefined4 *)(lVar4 + 0x28e0) = 0;

LAB_1401fd87c:

    local_ac = uVar10 << 0x20;

    uStack_98 = SUB84(puVar9,0);

    local_94 = (undefined4)((ulonglong)puVar9 >> 0x20);

    plStack_a0 = plVar2;

  }

  uVar3 = *(uint *)(lVar4 + 0x28f0);

  local_90 = 1;

  local_78 = (undefined8 *)(*(longlong *)(lVar4 + 0x28b8) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8)

  ;

  if (uVar3 == 0) {

    local_80 = 1;

  }

  else {

    local_80 = uVar3 + 1;

    *(undefined8 *)(*(longlong *)(lVar4 + 0x28e8) + (ulonglong)uVar3 * 8) = *local_78;

    local_78 = *(undefined8 **)(lVar4 + 0x28e8);

    *(undefined4 *)(lVar4 + 0x28f0) = 0;

  }

  local_88 = plVar1;

  iVar7 = (*DAT_1403fd088)(*(undefined8 *)(lVar4 + 0x650),1,&local_b8,

                           *(undefined8 *)

                            (*(longlong *)(lVar4 + 0x6a0) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8)

                          );

  if (iVar7 == 0) {

    *(undefined8 *)(lVar4 + 0x698) = 0;

    *(undefined8 *)(lVar4 + 0x28c0) = 0;

    local_64 = 0;

    local_50 = *(longlong *)(lVar4 + 0x28b8) + (ulonglong)*(uint *)(lVar4 + 0x690) * 8;

    local_5c = 0;

    local_40 = lVar4 + 0x678;

    local_58 = 1;

    local_48 = 1;

    local_30 = 0;

    local_68 = 0x3b9acde9;

    local_38 = (uint *)(lVar4 + 0x28c8);

    iVar7 = (*DAT_1403fd080)(*(undefined8 *)(lVar4 + 0x658));

    if ((((iVar7 != 0) && (iVar7 != -0x3b9acdec)) && (iVar7 != -1000000000)) &&

       (iVar7 != 0x3b9acdeb)) {

      cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar6 != '\0') {

        uVar8 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkQueuePresentKHR()",uVar8);

      }

      uVar8 = FUN_140241280(iVar7);

      FUN_14012e850("%s: %s","vkQueuePresentKHR()",uVar8);

      return 0;

    }

    uVar10 = (ulonglong)(*(int *)(lVar4 + 0x690) + 1) % (ulonglong)*(uint *)(lVar4 + 0x2894);

    *(int *)(lVar4 + 0x690) = (int)uVar10;

    iVar7 = (*DAT_1403fd0c0)(*(undefined8 *)(lVar4 + 0x660),1,

                             *(longlong *)(lVar4 + 0x6a0) + uVar10 * 8,1,0xffffffffffffffff);

    if (iVar7 == 0) {

      FUN_1401f5580(param_1);

      return 1;

    }

    if (iVar7 != -4) {

      cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar6 != '\0') {

        uVar8 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(6,"%s: %s","vkWaitForFences()",uVar8);

      }

      uVar8 = FUN_140241280(iVar7);

      pcVar11 = "vkWaitForFences()";

      goto LAB_1401fdade;

    }

  }

  else if (iVar7 != -4) {

    cVar6 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar6 != '\0') {

      uVar8 = FUN_140241280(iVar7);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkQueueSubmit()",uVar8);

    }

    uVar8 = FUN_140241280(iVar7);

    pcVar11 = "vkQueueSubmit()";

LAB_1401fdade:

    FUN_14012e850("%s: %s",pcVar11,uVar8);

    return 0;

  }

  cVar6 = FUN_1401fa960(param_1);

  if (cVar6 == '\0') {

    return 0;

  }

  FUN_14012e850("Present failed, device lost");

  return 0;

}




