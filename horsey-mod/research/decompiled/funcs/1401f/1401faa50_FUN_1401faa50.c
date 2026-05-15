// Address: 0x1401faa50
// Ghidra name: FUN_1401faa50
// ============ 0x1401faa50 FUN_1401faa50 (size=362) ============


undefined8 FUN_1401faa50(undefined8 param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  longlong lVar4;

  uint uVar5;

  uint local_res18 [4];

  

  iVar2 = (*DAT_1403fd0d0)(0,local_res18,0);

  if (iVar2 == 0) {

    if (local_res18[0] != 0) {

      lVar4 = FUN_1401841a0(local_res18[0],0x104);

      iVar2 = (*DAT_1403fd0d0)(0,local_res18,lVar4);

      if (iVar2 == 0) {

        uVar5 = 0;

        if (local_res18[0] != 0) {

          do {

            iVar2 = strcmp((char *)((ulonglong)uVar5 * 0x104 + lVar4),param_2);

            if (iVar2 == 0) {

              FUN_1401841e0(lVar4);

              return 1;

            }

            uVar5 = uVar5 + 1;

          } while (uVar5 < local_res18[0]);

        }

      }

      else {

        cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

        if (cVar1 != '\0') {

          uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

          FUN_14012e0b0(6,"%s: %s","vkEnumerateInstanceExtensionProperties()",uVar3);

        }

        uVar3 = FUN_140241280(iVar2);

        FUN_14012e850("%s: %s","vkEnumerateInstanceExtensionProperties()",uVar3);

      }

      FUN_1401841e0(lVar4);

    }

    return 0;

  }

  cVar1 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

  if (cVar1 == '\0') {

    uVar3 = FUN_140241280(iVar2);

    FUN_14012e850("%s: %s","vkEnumerateInstanceExtensionProperties()",uVar3);

    return 0;

  }

  uVar3 = FUN_140241280(iVar2);

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(6,"%s: %s","vkEnumerateInstanceExtensionProperties()",uVar3);

}




