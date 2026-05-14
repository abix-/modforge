// Address: 0x1401df5c0
// Ghidra name: FUN_1401df5c0
// ============ 0x1401df5c0 FUN_1401df5c0 (size=443) ============


undefined8 FUN_1401df5c0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong *plVar2;

  char *pcVar3;

  undefined4 uVar4;

  int iVar5;

  undefined8 uVar6;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  plVar2 = *(longlong **)(lVar1 + 0x10);

  if (*(longlong **)(lVar1 + 0x90) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0x90) + 0x10))();

    *(undefined8 *)(lVar1 + 0x90) = 0;

  }

  if (param_2 == 0) {

    (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x128))

              (*(longlong **)(lVar1 + 0x10),0,*(undefined8 *)(lVar1 + 0x88));

    return 1;

  }

  pcVar3 = *(char **)(param_2 + 0x138);

  if (pcVar3 == (char *)0x0) {

    uVar6 = FUN_14012e850("Texture is not currently available");

    return uVar6;

  }

  if ((*pcVar3 != '\0') && (*(longlong *)(pcVar3 + 0x20) != 0)) {

    if (*(longlong *)(pcVar3 + 0x18) == 0) {

      uVar4 = FUN_1401e0110(*(undefined4 *)(pcVar3 + 0x10));

      iVar5 = (**(code **)(*plVar2 + 0xb8))

                        (plVar2,*(undefined4 *)(pcVar3 + 4),*(undefined4 *)(pcVar3 + 8),1,

                         *(undefined4 *)(pcVar3 + 0xc),uVar4,0,pcVar3 + 0x18,0);

      if (iVar5 < 0) {

        uVar6 = FUN_1401df290("CreateTexture(D3DPOOL_DEFAULT)",iVar5);

        return uVar6;

      }

    }

    iVar5 = (**(code **)(*plVar2 + 0xf8))

                      (plVar2,*(undefined8 *)(pcVar3 + 0x20),*(undefined8 *)(pcVar3 + 0x18));

    if (iVar5 < 0) {

      uVar6 = FUN_1401df290("UpdateTexture()",iVar5);

      return uVar6;

    }

    *pcVar3 = '\0';

  }

  iVar5 = (**(code **)(**(longlong **)(pcVar3 + 0x18) + 0x90))

                    (*(longlong **)(pcVar3 + 0x18),0,lVar1 + 0x90);

  if (iVar5 < 0) {

    uVar6 = FUN_1401df290("GetSurfaceLevel()",iVar5);

  }

  else {

    iVar5 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x128))

                      (*(longlong **)(lVar1 + 0x10),0,*(undefined8 *)(lVar1 + 0x90));

    if (iVar5 < 0) {

      uVar6 = FUN_1401df290("SetRenderTarget()",iVar5);

    }

    else {

      uVar6 = 1;

    }

  }

  return uVar6;

}




