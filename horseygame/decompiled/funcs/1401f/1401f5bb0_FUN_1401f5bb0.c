// Address: 0x1401f5bb0
// Ghidra name: FUN_1401f5bb0
// ============ 0x1401f5bb0 FUN_1401f5bb0 (size=233) ============


undefined8 FUN_1401f5bb0(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  undefined8 local_res8 [4];

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined8 local_2c;

  undefined8 uStack_24;

  undefined4 local_1c;

  undefined8 local_18;

  undefined4 *local_10;

  

  local_44 = 0x1000;

  local_res8[0] = 0;

  local_48 = 0;

  local_10 = &local_48;

  local_3c = 0x1000;

  local_40 = 1;

  local_34 = 0x1000;

  local_38 = 6;

  local_2c = 0;

  uStack_24 = 0;

  local_18 = 3;

  local_30 = 0x21;

  local_1c = 0x1000;

  iVar2 = (*DAT_1403fcf48)(*(undefined8 *)(param_1 + 0x660),&local_30,0,local_res8);

  if (iVar2 == 0) {

    return local_res8[0];

  }

  cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar1 != '\0') {

    uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,"%s: %s","vkCreateDescrptorPool()",uVar3);

  }

  uVar3 = FUN_140241280(iVar2);

  FUN_14012e850("%s: %s","vkCreateDescrptorPool()",uVar3);

  return 0;

}




