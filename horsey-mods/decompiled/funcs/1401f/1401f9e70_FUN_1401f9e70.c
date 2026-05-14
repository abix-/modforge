// Address: 0x1401f9e70
// Ghidra name: FUN_1401f9e70
// ============ 0x1401f9e70 FUN_1401f9e70 (size=197) ============


ulonglong FUN_1401f9e70(longlong param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5)



{

  uint uVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  ulonglong uVar5;

  uint *puVar6;

  

  uVar1 = *(uint *)(param_1 + 0x368);

  uVar5 = 0;

  if (uVar1 != 0) {

    do {

      if (((param_2 >> ((uint)uVar5 & 0x1f) & 1) != 0) &&

         (*(uint *)(param_1 + 0x36c + uVar5 * 8) == (param_4 | param_3))) goto LAB_1401f9edc;

      uVar3 = (uint)uVar5 + 1;

      uVar5 = (ulonglong)uVar3;

    } while (uVar3 < uVar1);

  }

  uVar5 = 0;

  if (uVar1 != 0) {

    uVar3 = 1;

    puVar6 = (uint *)(param_1 + 0x36c);

    do {

      if (((param_2 & uVar3) != 0) && ((*puVar6 & param_3) == param_3)) goto LAB_1401f9f27;

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

      uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);

      puVar6 = puVar6 + 2;

    } while (uVar4 < uVar1);

  }

LAB_1401f9edc:

  if (uVar1 <= (uint)uVar5) {

    cVar2 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar2 != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,&DAT_14039bf30,"Unable to find memory type for allocation");

    }

    uVar5 = FUN_14012e850(&DAT_14039bf30,"Unable to find memory type for allocation");

    return uVar5 & 0xffffffffffffff00;

  }

LAB_1401f9f27:

  *param_5 = (int)uVar5;

  return CONCAT71((int7)(uVar5 >> 8),1);

}




