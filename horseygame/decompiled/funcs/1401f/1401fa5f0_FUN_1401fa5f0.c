// Address: 0x1401fa5f0
// Ghidra name: FUN_1401fa5f0
// ============ 0x1401fa5f0 FUN_1401fa5f0 (size=508) ============


undefined8 FUN_1401fa5f0(longlong param_1,int param_2,int param_3,int param_4,int param_5)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  undefined8 uVar6;

  undefined4 local_58;

  undefined8 local_54;

  undefined8 local_4c;

  undefined8 local_44;

  undefined4 local_3c;

  undefined8 local_38;

  undefined8 local_30;

  undefined4 local_28;

  undefined4 local_24;

  undefined8 local_20;

  undefined4 local_18;

  undefined4 local_14;

  undefined8 local_10;

  

  uVar5 = 0;

  iVar3 = 0;

  if (param_2 != 0x13000801) {

    iVar3 = param_3;

  }

  uVar4 = uVar5;

  if (param_4 == 2) {

    uVar4 = 2;

  }

  if (param_5 == 2) {

    uVar5 = 4;

  }

  lVar1 = param_1 + (iVar3 == 0 | uVar4 | uVar5) * 8;

  if (*(longlong *)(lVar1 + 0x2800) == 0) {

    local_54 = 0;

    local_4c = 0;

    local_44 = 0;

    local_38 = 0;

    local_20 = 0;

    local_10 = 0;

    local_58 = 0x1f;

    local_3c = 0;

    local_30 = 2;

    local_28 = 0;

    local_24 = 0x3f800000;

    local_18 = 0;

    local_14 = 0x447a0000;

    if (iVar3 != 0) {

      if ((iVar3 != 1) && (iVar3 != 2)) {

        FUN_14012e850("Unknown scale mode: %d",iVar3);

        return 0;

      }

      local_44 = 0x100000001;

    }

    if (param_4 == 1) {

      local_38 = 2;

    }

    else if (param_4 != 2) {

      FUN_14012e850("Unknown texture address mode: %d",param_4);

      return 0;

    }

    if (param_5 == 1) {

      local_38 = CONCAT44(2,(undefined4)local_38);

    }

    else if (param_5 != 2) {

      FUN_14012e850("Unknown texture address mode: %d",param_5);

      return 0;

    }

    iVar3 = (*DAT_1403fcf90)(*(undefined8 *)(param_1 + 0x660),&local_58,0,lVar1 + 0x2800);

    if (iVar3 != 0) {

      cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar2 == '\0') {

        uVar6 = FUN_140241280(iVar3);

        FUN_14012e850("%s: %s","vkCreateSampler()",uVar6);

        return 0;

      }

      uVar6 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkCreateSampler()",uVar6);

    }

  }

  return *(undefined8 *)(lVar1 + 0x2800);

}




