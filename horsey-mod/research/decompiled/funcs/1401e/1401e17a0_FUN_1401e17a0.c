// Address: 0x1401e17a0
// Ghidra name: FUN_1401e17a0
// ============ 0x1401e17a0 FUN_1401e17a0 (size=624) ============


int FUN_1401e17a0(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  int iVar4;

  undefined4 uVar5;

  int iVar6;

  int iVar7;

  ulonglong uVar8;

  longlong lVar9;

  longlong *local_res8;

  uint local_res10 [2];

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined8 local_58;

  undefined4 local_50;

  undefined4 local_4c;

  uint local_48;

  undefined4 uStack_44;

  undefined4 local_40;

  undefined4 local_3c;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  local_res8 = (longlong *)0x0;

  local_40 = 0;

  if (*(int *)(param_1 + 0x208) == 0x12000500) {

    local_60 = 10;

  }

  else {

    local_60 = 0x18;

    if (*(int *)(param_1 + 0x208) != 0x12002600) {

      local_60 = 0x57;

    }

  }

  local_5c = 0;

  local_58 = 1;

  local_50 = 0x20;

  local_4c = 2;

  local_68 = param_2;

  local_64 = param_3;

  iVar4 = FUN_1401a9950();

  _local_48 = CONCAT44(uStack_44,(uint)(iVar4 != 0));

  uVar8 = FUN_14016e130(*(undefined8 *)(param_1 + 0x118));

  if ((uVar8 >> 0x1e & 1) == 0) {

    uStack_44 = 3;

  }

  else {

    local_48 = 0;

    uStack_44 = 0;

  }

  local_3c = *(undefined4 *)(lVar2 + 0x3c);

  uVar5 = FUN_14016ea50(*(undefined8 *)(param_1 + 0x118));

  lVar9 = FUN_140174d30(uVar5,"SDL.window.win32.hwnd",0);

  if (lVar9 == 0) {

    FUN_14012e850("Couldn\'t get window handle");

    iVar4 = -0x7fffbffb;

  }

  else {

    puVar1 = (undefined8 *)(lVar2 + 0x30);

    iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x10) + 0x78))

                      (*(longlong **)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x20),lVar9,&local_68,0,

                       0,puVar1);

    if (iVar4 < 0) {

      FUN_1401a9ef0("IDXGIFactory2::CreateSwapChainForHwnd",iVar4);

    }

    else {

      (**(code **)(**(longlong **)(lVar2 + 0x10) + 0x40))(*(longlong **)(lVar2 + 0x10),lVar9,1);

      *(undefined4 *)(lVar2 + 0x38) = uStack_44;

      iVar6 = (*(code *)**(undefined8 **)*puVar1)((undefined8 *)*puVar1,&DAT_14034b418,&local_res8);

      if (-1 < iVar6) {

        local_res10[0] = 0;

        iVar6 = 1;

        if ((*(int *)(param_1 + 0x208) != 0x12000500) &&

           (iVar6 = 0xc, *(int *)(param_1 + 0x208) != 0x12002600)) {

          iVar6 = 0;

        }

        iVar7 = (**(code **)(*local_res8 + 0x128))(local_res8,iVar6,local_res10);

        if ((iVar7 < 0) || ((local_res10[0] & 1) == 0)) {

          if (iVar6 != 1) {

            FUN_14012e850("Unsupported output colorspace");

            iVar4 = -0x7785fffc;

          }

        }

        else {

          iVar4 = (**(code **)(*local_res8 + 0x130))(local_res8,iVar6);

          if (iVar4 < 0) {

            FUN_1401a9ef0("IDXGISwapChain3::SetColorSpace1",iVar4);

            goto LAB_1401e19c9;

          }

        }

      }

      uVar3 = *puVar1;

      uVar5 = FUN_14014f090(param_1);

      FUN_140175480(uVar5,"SDL.renderer.d3d11.swap_chain",uVar3);

    }

  }

LAB_1401e19c9:

  if (local_res8 != (longlong *)0x0) {

    (**(code **)(*local_res8 + 0x10))();

  }

  return iVar4;

}




