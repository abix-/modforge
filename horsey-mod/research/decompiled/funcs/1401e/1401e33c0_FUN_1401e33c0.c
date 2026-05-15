// Address: 0x1401e33c0
// Ghidra name: FUN_1401e33c0
// ============ 0x1401e33c0 FUN_1401e33c0 (size=251) ============


undefined8 FUN_1401e33c0(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(longlong *)(lVar1 + 0x20) == 0) {

    uVar4 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar4;

  }

  local_28 = 0;

  uStack_20 = 0;

  local_18 = 0;

  uStack_10 = 0;

  iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0xb0))

                    (*(longlong **)(lVar1 + 0x30),*(undefined4 *)(lVar1 + 0x40),

                     *(undefined4 *)(lVar1 + 0x44),&local_28);

  *(undefined8 *)(lVar1 + 0x200) = 0;

  if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7785fff6)) {

    if (iVar3 == -0x7785fffb) {

      cVar2 = FUN_1401e25f0(param_1);

      if (cVar2 != '\0') {

        FUN_14012e850("Present failed, device lost");

        return 0;

      }

    }

    else {

      if (iVar3 == -0x7785ffff) {

        FUN_1401e1e80(param_1);

        FUN_1401a9ef0("IDXGISwapChain::Present",0x887a0001);

        return 0;

      }

      FUN_1401a9ef0("IDXGISwapChain::Present",iVar3);

    }

    return 0;

  }

  return 1;

}




