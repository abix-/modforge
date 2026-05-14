// Address: 0x1401f72b0
// Ghidra name: FUN_1401f72b0
// ============ 0x1401f72b0 FUN_1401f72b0 (size=268) ============


uint FUN_1401f72b0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  char cVar3;

  undefined4 uVar4;

  int iVar5;

  uint uVar6;

  longlong lVar7;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  lVar7 = FUN_1401841a0(1,0x28);

  uVar6 = (uint)lVar7;

  if (lVar7 != 0) {

    *(longlong *)(param_2 + 0x10) = lVar7;

    local_18 = *(undefined4 *)(lVar1 + 0x296c);

    uStack_14 = *(undefined4 *)(lVar1 + 0x2970);

    uStack_10 = *(undefined4 *)(lVar1 + 0x2974);

    uStack_c = *(undefined4 *)(lVar1 + 0x2978);

    uVar4 = FUN_1401f54b0(0x16762004,*(undefined4 *)(param_1 + 0x208));

    iVar5 = FUN_1401f6000(lVar1,0,0x100,1,uVar4,7,&local_18,0,lVar7);

    if (iVar5 == 0) {

      return 1;

    }

    cVar3 = FUN_140142940("SDL_RENDER_VULKAN_DEBUG",0);

    if (cVar3 != '\0') {

      uVar2 = FUN_140241280(iVar5);

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(6,"%s: %s","VULKAN_AllocateImage()",uVar2);

    }

    uVar2 = FUN_140241280(iVar5);

    uVar6 = FUN_14012e850("%s: %s","VULKAN_AllocateImage()",uVar2);

  }

  return uVar6 & 0xffffff00;

}




