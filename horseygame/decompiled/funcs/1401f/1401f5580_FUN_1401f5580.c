// Address: 0x1401f5580
// Ghidra name: FUN_1401f5580
// ============ 0x1401f5580 FUN_1401f5580 (size=312) ============


int FUN_1401f5580(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  *(undefined8 *)(lVar1 + 0x28c0) = 0;

  iVar3 = (*DAT_1403fce98)(*(undefined8 *)(lVar1 + 0x660),*(undefined8 *)(lVar1 + 0x678),

                           0xffffffffffffffff,

                           *(undefined8 *)

                            (*(longlong *)(lVar1 + 0x28b0) + (ulonglong)*(uint *)(lVar1 + 0x690) * 8

                            ),0,lVar1 + 0x28c8);

  if ((iVar3 == -0x3b9acdec) || (iVar3 == -1000000000)) {

    if ((*(byte *)(*(longlong *)(param_1 + 0x118) + 0x48) & 0x40) == 0) {

      iVar3 = FUN_1401f8fa0(param_1);

    }

    return iVar3;

  }

  if ((iVar3 != 0x3b9acdeb) && (iVar3 != 0)) {

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

      uVar4 = FUN_140241280(iVar3);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkAcquireNextImageKHR()",uVar4);

    }

    uVar4 = FUN_140241280(iVar3);

    FUN_14012e850("%s: %s","vkAcquireNextImageKHR()",uVar4);

    return iVar3;

  }

  *(undefined8 *)(lVar1 + 0x28c0) =

       *(undefined8 *)(*(longlong *)(lVar1 + 0x28b0) + (ulonglong)*(uint *)(lVar1 + 0x690) * 8);

  return iVar3;

}




