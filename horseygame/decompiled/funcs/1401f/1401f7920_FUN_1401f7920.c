// Address: 0x1401f7920
// Ghidra name: FUN_1401f7920
// ============ 0x1401f7920 FUN_1401f7920 (size=170) ============


undefined8 FUN_1401f7920(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  undefined8 local_res8 [4];

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  

  local_res8[0] = 0;

  uStack_20 = 0;

  local_28 = 9;

  local_18 = 0;

  iVar2 = (*DAT_1403fcf98)(*(undefined8 *)(param_1 + 0x660),&local_28,0,local_res8);

  if (iVar2 == 0) {

    return local_res8[0];

  }

  cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar1 != '\0') {

    uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,"%s: %s","vkCreateSemaphore()",uVar3);

  }

  uVar3 = FUN_140241280(iVar2);

  FUN_14012e850("%s: %s","vkCreateSemaphore()",uVar3);

  return 0;

}




