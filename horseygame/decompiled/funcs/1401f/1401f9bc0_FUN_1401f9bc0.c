// Address: 0x1401f9bc0
// Ghidra name: FUN_1401f9bc0
// ============ 0x1401f9bc0 FUN_1401f9bc0 (size=435) ============


ulonglong FUN_1401f9bc0(longlong param_1,int param_2,undefined8 *param_3)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  longlong lVar5;

  uint uVar6;

  longlong lVar7;

  byte bVar8;

  byte bVar9;

  uint local_res8 [2];

  

  bVar8 = 1;

  iVar2 = (*DAT_1403fd0f8)(*(undefined8 *)(param_1 + 0x28),0,local_res8,0);

  if (iVar2 != 0) {

    cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar1 == '\0') {

      uVar3 = FUN_140241280(iVar2);

      uVar4 = FUN_14012e850("%s: %s","vkEnumerateDeviceExtensionProperties()",uVar3);

      return uVar4 & 0xffffffffffffff00;

    }

    uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(6,"%s: %s","vkEnumerateDeviceExtensionProperties()",uVar3);

  }

  bVar9 = bVar8;

  if (local_res8[0] != 0) {

    lVar5 = FUN_1401841a0(local_res8[0],0x104);

    iVar2 = (*DAT_1403fd0f8)(*(undefined8 *)(param_1 + 0x28),0,local_res8,lVar5);

    if (iVar2 != 0) {

      cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

      if (cVar1 == '\0') {

        uVar3 = FUN_140241280(iVar2);

        FUN_14012e850("%s: %s","vkEnumerateDeviceExtensionProperties()",uVar3);

        uVar4 = FUN_1401841e0(lVar5);

        return uVar4 & 0xffffffffffffff00;

      }

      uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","vkEnumerateDeviceExtensionProperties()",uVar3);

    }

    if (0 < param_2) {

      lVar7 = 0;

      do {

        bVar9 = 0;

        if (bVar8 == 0) break;

        bVar9 = 0;

        uVar4 = 0;

        if (local_res8[0] != 0) {

          do {

            iVar2 = strcmp((char *)(uVar4 * 0x104 + lVar5),(char *)*param_3);

            if (iVar2 == 0) {

              bVar9 = 1;

              break;

            }

            uVar6 = (int)uVar4 + 1;

            uVar4 = (ulonglong)uVar6;

          } while (uVar6 < local_res8[0]);

        }

        bVar8 = bVar8 & bVar9;

        lVar7 = lVar7 + 1;

        param_3 = param_3 + 1;

        bVar9 = bVar8;

      } while (lVar7 < param_2);

    }

    FUN_1401841e0(lVar5);

  }

  return (ulonglong)bVar9;

}




