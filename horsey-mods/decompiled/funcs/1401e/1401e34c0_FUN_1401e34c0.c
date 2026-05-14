// Address: 0x1401e34c0
// Ghidra name: FUN_1401e34c0
// ============ 0x1401e34c0 FUN_1401e34c0 (size=569) ============


undefined8 FUN_1401e34c0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  longlong *plVar5;

  undefined4 uVar6;

  undefined8 uVar7;

  longlong *local_res8;

  longlong *local_res18 [2];

  ulonglong in_stack_ffffffffffffff38;

  ulonglong in_stack_ffffffffffffff40;

  undefined8 *puVar8;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined4 local_80;

  undefined4 local_78;

  undefined4 local_74;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined4 local_50;

  undefined8 local_44;

  undefined8 local_3c;

  undefined4 uVar9;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_res8 = (longlong *)0x0;

  local_res18[0] = (longlong *)0x0;

  uVar7 = 0;

  local_98 = 0;

  uStack_90 = 0;

  plVar5 = (longlong *)FUN_1401e22f0();

  if (plVar5 == (longlong *)0x0) {

    FUN_14012e850("%s, ID3D11DeviceContext::OMGetRenderTargets failed","D3D11_RenderReadPixels");

    uVar7 = 0;

  }

  else {

    (**(code **)(*plVar5 + 0x38))(plVar5,&local_res8);

    if (local_res8 == (longlong *)0x0) {

      FUN_14012e850("%s, ID3D11View::GetResource failed","D3D11_RenderReadPixels");

    }

    else {

      (**(code **)(*local_res8 + 0x50))(local_res8,&local_60);

      local_60 = *(undefined4 *)(param_2 + 8);

      local_5c = *(undefined4 *)(param_2 + 0xc);

      local_44 = 3;

      local_3c = 0x20000;

      iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x28))

                        (*(longlong **)(lVar1 + 0x20),&local_60,0,local_res18);

      if (iVar3 < 0) {

        FUN_1401a9ef0("ID3D11Device1::CreateTexture2D [create staging texture]",iVar3);

      }

      else {

        cVar2 = FUN_1401e24b0(param_1,param_2,&local_98,0);

        if (cVar2 != '\0') {

          local_78 = (undefined4)local_98;

          local_6c = (undefined4)uStack_90;

          local_74 = local_98._4_4_;

          local_68 = uStack_90._4_4_;

          local_70 = 0;

          local_64 = 1;

          in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;

          (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x170))

                    (*(longlong **)(lVar1 + 0x28),local_res18[0],0,0,in_stack_ffffffffffffff38,

                     in_stack_ffffffffffffff40 & 0xffffffff00000000,local_res8,0,&local_78);

          puVar8 = &local_88;

          iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x70))

                            (*(longlong **)(lVar1 + 0x28),local_res18[0],0,1,

                             in_stack_ffffffffffffff38 & 0xffffffff00000000,puVar8);

          uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);

          if (iVar3 < 0) {

            FUN_1401a9ef0("ID3D11DeviceContext1::Map [map staging texture]",iVar3);

          }

          else {

            if (*(longlong *)(param_1 + 0x1f0) == 0) {

              uVar6 = *(undefined4 *)(param_1 + 0x208);

            }

            else {

              uVar6 = *(undefined4 *)(*(longlong *)(param_1 + 0x1f0) + 0x18);

            }

            uVar4 = FUN_1401e2030(local_50);

            uVar7 = FUN_1401460c0(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),uVar4,

                                  uVar6,local_88,CONCAT44(uVar9,local_80));

            (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x78))

                      (*(longlong **)(lVar1 + 0x28),local_res18[0],0);

          }

        }

      }

    }

  }

  if (local_res8 != (longlong *)0x0) {

    (**(code **)(*local_res8 + 0x10))();

    local_res8 = (longlong *)0x0;

  }

  if (local_res18[0] != (longlong *)0x0) {

    (**(code **)(*local_res18[0] + 0x10))();

  }

  return uVar7;

}




