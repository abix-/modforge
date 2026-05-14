// Address: 0x1401c8780
// Ghidra name: FUN_1401c8780
// ============ 0x1401c8780 FUN_1401c8780 (size=931) ============


undefined8 FUN_1401c8780(undefined8 *param_1,undefined8 *param_2,int param_3,undefined4 param_4)



{

  undefined8 *puVar1;

  longlong lVar2;

  char cVar3;

  undefined4 uVar4;

  BOOL BVar5;

  int iVar6;

  HWND hWnd;

  uint uVar7;

  longlong lVar8;

  longlong *local_res8;

  undefined8 *local_res10;

  int local_res18;

  undefined4 local_res20;

  longlong *local_a8;

  longlong *local_a0;

  longlong local_98;

  undefined8 local_90;

  undefined8 local_88;

  undefined4 local_80;

  undefined8 local_78;

  undefined4 local_70;

  undefined4 local_6c;

  undefined8 local_68;

  undefined4 local_60;

  uint local_5c;

  undefined4 local_58;

  undefined8 local_54;

  uint local_4c;

  

  lVar8 = (longlong)param_3;

  local_res10 = param_2;

  local_res18 = param_3;

  local_res20 = param_4;

  uVar4 = FUN_14016ea50(*param_2);

  hWnd = (HWND)FUN_140174d30(uVar4,"SDL.window.win32.hwnd",0);

  local_5c = *(uint *)((longlong)param_1 + 0xa4);

  local_70 = *(undefined4 *)(&DAT_1403e4348 + lVar8 * 4);

  if (local_5c < 2) {

    local_5c = 2;

  }

  else if (3 < local_5c) {

    local_5c = 3;

  }

  *(uint *)(param_2 + 0x24) = local_5c;

  uVar7 = 0;

  local_78 = 0;

  local_68 = 1;

  local_60 = 0x20;

  local_4c = -(uint)(*(int *)(param_1 + 0xc) != 0) & 0x800;

  local_58 = 1;

  local_54 = 4;

  local_6c = 0;

  local_90 = 0;

  local_88 = 0;

  local_80 = 1;

  local_98 = lVar8;

  BVar5 = IsWindow(hWnd);

  if (BVar5 != 0) {

    iVar6 = (**(code **)(*(longlong *)param_1[2] + 0x78))

                      ((longlong *)param_1[2],param_1[0x12],hWnd,&local_78,&local_90,0,&local_a8);

    if (-1 < iVar6) {

      iVar6 = (**(code **)*local_a8)(local_a8,&DAT_140349288,&local_res8);

      (**(code **)(*local_a8 + 0x10))();

      if (iVar6 < 0) {

        FUN_1401cb240(param_1,"Could not create IDXGISwapChain3",iVar6);

        return 0;

      }

      if (param_3 != 0) {

        (**(code **)(*local_res8 + 0x130))(local_res8,*(undefined4 *)(&DAT_1403e4358 + lVar8 * 4));

      }

      iVar6 = (**(code **)(*local_res8 + 0x30))(local_res8,&DAT_140349228,&local_a0);

      if (iVar6 < 0) {

        FUN_14012e2e0(9,"Could not get swapchain parent! Error Code: (0x%08lX)",iVar6);

        (**(code **)(*local_res8 + 0x90))(local_res8,&local_78);

      }

      else {

        iVar6 = (**(code **)(*local_a0 + 0x40))(local_a0,hWnd,1);

        if (iVar6 < 0) {

          FUN_14012e2e0(9,"MakeWindowAssociation failed! Error Code: (0x%08lX)",iVar6);

        }

        (**(code **)(*local_a0 + 0x10))();

        (**(code **)(*local_res8 + 0x90))(local_res8,&local_78);

        lVar2 = local_98;

        if (-1 < iVar6) {

          param_2[3] = local_res8;

          *(undefined4 *)(param_2 + 4) = local_res20;

          *(undefined4 *)(param_2 + 5) = *(undefined4 *)(&DAT_1403e4358 + lVar8 * 4);

          *(undefined4 *)(param_2 + 0x28) = (undefined4)local_78;

          *(int *)((longlong)param_2 + 0x24) = param_3;

          *(undefined4 *)((longlong)param_2 + 0x2c) = 0;

          *(undefined4 *)((longlong)param_2 + 0x144) = local_78._4_4_;

          do {

            FUN_140137340(*param_1,uVar7,*(undefined4 *)(&DAT_1403e4338 + lVar2 * 4),param_1[0x18],

                          param_1[0x19],param_1[0x1a],param_1[0x1b],param_1[0x1c],param_1[0x1d],

                          param_1 + 0x20,param_1 + 0x21,(longlong)param_1 + 0x10c);

            iVar6 = local_res18;

            puVar1 = local_res10;

            uVar7 = uVar7 + 1;

          } while (uVar7 < 5);

          uVar7 = 0;

          if (*(int *)(local_res10 + 0x24) != 0) {

            do {

              cVar3 = FUN_1401ca1e0(param_1,local_res8,iVar6,uVar7,

                                    puVar1 + (ulonglong)uVar7 * 10 + 6);

              if (cVar3 == '\0') {

                (**(code **)(*local_res8 + 0x10))();

                return 0;

              }

              uVar7 = uVar7 + 1;

            } while (uVar7 < *(uint *)(puVar1 + 0x24));

          }

          return 1;

        }

      }

      FUN_1401cb240(param_1,"Failed to retrieve swapchain descriptor!",iVar6);

      return 0;

    }

    FUN_1401cb240(param_1,"Could not create swapchain",iVar6);

  }

  return 0;

}




