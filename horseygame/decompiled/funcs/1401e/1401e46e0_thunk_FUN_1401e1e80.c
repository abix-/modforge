// Address: 0x1401e46e0
// Ghidra name: thunk_FUN_1401e1e80
// ============ 0x1401e46e0 thunk_FUN_1401e1e80 (size=5) ============


int thunk_FUN_1401e1e80(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  undefined4 uVar3;

  int iVar4;

  undefined4 auStackX_8 [2];

  undefined4 auStackX_10 [2];

  longlong *aplStackX_18 [2];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  aplStackX_18[0] = (longlong *)0x0;

  FUN_1401e3370();

  FUN_14016ebe0(*(undefined8 *)(param_1 + 0x118),auStackX_10,auStackX_8);

  uVar3 = FUN_14000c580();

  *(undefined4 *)(lVar1 + 0x1f8) = uVar3;

  iVar4 = FUN_1401e2710(uVar3);

  uVar3 = auStackX_10[0];

  if (iVar4 != 0) {

    auStackX_10[0] = auStackX_8[0];

    auStackX_8[0] = uVar3;

  }

  plVar2 = *(longlong **)(lVar1 + 0x30);

  if (plVar2 == (longlong *)0x0) {

    iVar4 = FUN_1401e17a0(param_1);

    if ((iVar4 < 0) || (*(longlong *)(lVar1 + 0x30) == 0)) goto LAB_1401e2010;

  }

  else {

    iVar4 = (**(code **)(*plVar2 + 0x68))

                      (plVar2,0,auStackX_10[0],auStackX_8[0],0,*(undefined4 *)(lVar1 + 0x3c));

    if (iVar4 < 0) {

      FUN_1401a9ef0("IDXGISwapChain::ResizeBuffers",iVar4);

      goto LAB_1401e2010;

    }

  }

  FUN_1401e4740(param_1);

  iVar4 = FUN_1401a9950();

  if (((iVar4 == 0) || (*(int *)(lVar1 + 0x38) != 3)) ||

     (iVar4 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0xd8))

                        (*(longlong **)(lVar1 + 0x30),*(undefined4 *)(lVar1 + 0x1f8)), -1 < iVar4))

  {

    iVar4 = (**(code **)(**(longlong **)(lVar1 + 0x30) + 0x48))

                      (*(longlong **)(lVar1 + 0x30),0,&DAT_14034b3e8,aplStackX_18);

    if (iVar4 < 0) {

      FUN_1401a9ef0("IDXGISwapChain::GetBuffer [back-buffer]",iVar4);

    }

    else {

      iVar4 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x48))

                        (*(longlong **)(lVar1 + 0x20),aplStackX_18[0],0,lVar1 + 0x48);

      if (iVar4 < 0) {

        FUN_1401a9ef0("ID3D11Device::CreateRenderTargetView",iVar4);

      }

      else {

        (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x108))

                  (*(longlong **)(lVar1 + 0x28),1,lVar1 + 0x48,0);

        *(undefined1 *)(lVar1 + 0x448) = 1;

      }

    }

  }

  else {

    FUN_1401a9ef0("IDXGISwapChain1::SetRotation",iVar4);

  }

LAB_1401e2010:

  if (aplStackX_18[0] != (longlong *)0x0) {

    (**(code **)(*aplStackX_18[0] + 0x10))();

  }

  return iVar4;

}




