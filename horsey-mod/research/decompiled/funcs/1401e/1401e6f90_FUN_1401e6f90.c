// Address: 0x1401e6f90
// Ghidra name: FUN_1401e6f90
// ============ 0x1401e6f90 FUN_1401e6f90 (size=670) ============


int FUN_1401e6f90(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  undefined8 uVar5;

  longlong *local_res8;

  uint local_res10 [2];

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined8 local_48;

  undefined4 local_40;

  undefined4 local_3c;

  uint local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_res8 = (longlong *)0x0;

  local_30 = 0;

  if (*(int *)(param_1 + 0x208) == 0x12000500) {

    local_50 = 10;

    *(undefined4 *)(lVar1 + 0x60) = 10;

  }

  else if (*(int *)(param_1 + 0x208) == 0x12002600) {

    local_50 = 0x18;

    *(undefined4 *)(lVar1 + 0x60) = 0x18;

  }

  else {

    local_50 = 0x57;

    *(undefined4 *)(lVar1 + 0x60) = 0x57;

  }

  local_48 = 1;

  local_4c = 0;

  local_40 = 0x20;

  local_3c = 2;

  local_58 = param_2;

  local_54 = param_3;

  iVar2 = FUN_1401a9950();

  local_34 = 3;

  local_2c = 0x840;

  local_38 = (uint)(iVar2 != 0);

  uVar3 = FUN_14016ea50(*(undefined8 *)(param_1 + 0x118));

  lVar4 = FUN_140174d30(uVar3,"SDL.window.win32.hwnd",0);

  if (lVar4 == 0) {

    FUN_14012e850("Couldn\'t get window handle");

    iVar2 = -0x7fffbffb;

  }

  else {

    iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x78))

                      (*(longlong **)(lVar1 + 0x10),*(undefined8 *)(lVar1 + 0x40),lVar4,&local_58,0,

                       0,&local_res8);

    if (iVar2 < 0) {

      FUN_1401a9ef0("IDXGIFactory2::CreateSwapChainForHwnd",iVar2);

    }

    else {

      (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x40))(*(longlong **)(lVar1 + 0x10),lVar4,1);

      iVar2 = (**(code **)*local_res8)(local_res8,&DAT_14034bbd0,lVar1 + 0x28);

      if (iVar2 < 0) {

        FUN_1401a9ef0("IDXGISwapChain1::QueryInterface",iVar2);

      }

      else {

        iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0xf8))(*(longlong **)(lVar1 + 0x28),1);

        if (iVar2 < 0) {

          FUN_1401a9ef0("IDXGISwapChain4::SetMaximumFrameLatency",iVar2);

        }

        else {

          *(undefined4 *)(lVar1 + 0x50) = local_34;

          *(undefined4 *)(lVar1 + 0x54) = local_2c;

          local_res10[0] = 0;

          uVar5 = 1;

          if ((*(int *)(param_1 + 0x208) != 0x12000500) &&

             (uVar5 = 0xc, *(int *)(param_1 + 0x208) != 0x12002600)) {

            uVar5 = 0;

          }

          iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x128))

                            (*(longlong **)(lVar1 + 0x28),uVar5,local_res10);

          if ((iVar2 < 0) || ((local_res10[0] & 1) == 0)) {

            FUN_14012e850("Unsupported output colorspace");

            iVar2 = -0x7785fffc;

          }

          else {

            iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x130))

                              (*(longlong **)(lVar1 + 0x28),uVar5);

            if (iVar2 < 0) {

              FUN_1401a9ef0("IDXGISwapChain3::SetColorSpace1",iVar2);

              goto LAB_1401e71e7;

            }

          }

          uVar5 = *(undefined8 *)(lVar1 + 0x28);

          uVar3 = FUN_14014f090(param_1);

          FUN_140175480(uVar3,"SDL.renderer.d3d12.swap_chain",uVar5);

        }

      }

    }

  }

LAB_1401e71e7:

  if (local_res8 != (longlong *)0x0) {

    (**(code **)(*local_res8 + 0x10))();

  }

  return iVar2;

}




