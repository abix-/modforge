// Address: 0x1401e8a10
// Ghidra name: FUN_1401e8a10
// ============ 0x1401e8a10 FUN_1401e8a10 (size=496) ============


undefined8 FUN_1401e8a10(longlong param_1)



{

  longlong lVar1;

  ulonglong uVar2;

  char cVar3;

  int iVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (*(longlong *)(lVar1 + 0x30) == 0) {

    uVar6 = FUN_14012e850("Device lost and couldn\'t be recovered");

    return uVar6;

  }

  FUN_1401ea070(lVar1,*(undefined8 *)(lVar1 + 0xb0 + (longlong)*(int *)(lVar1 + 200) * 8),4,0);

  (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x48))();

  (**(code **)(**(longlong **)(lVar1 + 0x40) + 0x50))(*(longlong **)(lVar1 + 0x40),1,lVar1 + 0x48);

  iVar4 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x40))

                    (*(longlong **)(lVar1 + 0x28),*(undefined4 *)(lVar1 + 0x58),

                     *(undefined4 *)(lVar1 + 0x5c));

  if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x7785fff6)) {

    if (iVar4 == -0x7785fffb) {

      cVar3 = FUN_1401e81e0(param_1);

      if (cVar3 != '\0') {

        FUN_14012e850("Present failed, device lost");

        return 0;

      }

    }

    else {

      if (iVar4 == -0x7785ffff) {

        FUN_1401e7960(param_1);

        FUN_1401a9ef0("IDXGISwapChain::Present",0x887a0001);

        return 0;

      }

      FUN_1401a9ef0("IDXGISwapChain::Present",iVar4);

    }

    return 0;

  }

  (**(code **)(**(longlong **)(lVar1 + 0x40) + 0x70))

            (*(longlong **)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0xd0),

             *(undefined8 *)(lVar1 + 0xc0));

  uVar2 = *(ulonglong *)(lVar1 + 0xc0);

  uVar7 = (**(code **)(**(longlong **)(lVar1 + 0xd0) + 0x40))();

  if (uVar7 < uVar2) {

    (**(code **)(**(longlong **)(lVar1 + 0xd0) + 0x48))

              (*(longlong **)(lVar1 + 0xd0),*(undefined8 *)(lVar1 + 0xc0),

               *(undefined8 *)(lVar1 + 0xd8));

    WaitForSingleObjectEx(*(HANDLE *)(lVar1 + 0xd8),0xffffffff,0);

  }

  *(longlong *)(lVar1 + 0xc0) = *(longlong *)(lVar1 + 0xc0) + 1;

  uVar5 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x120))();

  *(undefined4 *)(lVar1 + 200) = uVar5;

  FUN_1401e8fd0(lVar1);

  FUN_1401ea070(lVar1,*(undefined8 *)(lVar1 + 0xb0 + (longlong)*(int *)(lVar1 + 200) * 8),0,4);

  return 1;

}




