// Address: 0x1401c0cd0
// Ghidra name: FUN_1401c0cd0
// ============ 0x1401c0cd0 FUN_1401c0cd0 (size=1012) ============


undefined8 FUN_1401c0cd0(undefined8 param_1,undefined4 param_2)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  char cVar4;

  char cVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  code *pcVar9;

  char *pcVar10;

  code *local_res20;

  longlong *local_a8;

  longlong *local_a0;

  longlong *local_98;

  longlong *local_90;

  longlong *local_88;

  undefined8 local_80;

  undefined8 uStack_78;

  undefined8 local_70;

  undefined8 uStack_68;

  undefined8 local_60;

  undefined8 uStack_58;

  undefined8 local_50;

  undefined4 local_48;

  

  bVar1 = false;

  cVar3 = FUN_1401749e0(param_2,"SDL.gpu.device.create.d3d12.allowtier1resourcebinding",0);

  cVar4 = FUN_1401749e0(param_2,"SDL.gpu.device.create.shaders.dxbc",0);

  cVar5 = FUN_1401749e0(param_2,"SDL.gpu.device.create.shaders.dxil",0);

  bVar2 = false;

  if ((cVar4 != '\0') || (cVar5 != '\0')) {

    lVar7 = FUN_1401885b0("d3d12.dll");

    if (lVar7 != 0) {

      local_res20 = (code *)FUN_140188550(lVar7,"D3D12CreateDevice");

      if (local_res20 == (code *)0x0) {

        FUN_14012e2e0(9,"D3D12: Could not find function D3D12CreateDevice in d3d12.dll");

        FUN_140188670(lVar7);

        return 0;

      }

      lVar8 = FUN_1401885b0("dxgi.dll");

      if (lVar8 != 0) {

        pcVar9 = (code *)FUN_140188550(lVar8,"CreateDXGIFactory1");

        if (pcVar9 == (code *)0x0) {

          FUN_14012e2e0(9,"D3D12: Could not find function CreateDXGIFactory1 in dxgi.dll");

          FUN_140188670(lVar8);

          return 0;

        }

        iVar6 = (*pcVar9)(&DAT_140349228,&local_a8);

        if (iVar6 < 0) {

          pcVar10 = "D3D12: Could not create DXGIFactory";

        }

        else {

          iVar6 = (**(code **)*local_a8)(local_a8,&DAT_140349238,&local_88);

          if (-1 < iVar6) {

            (**(code **)(*local_88 + 0x10))();

            iVar6 = (**(code **)*local_a8)(local_a8,&DAT_140349258,&local_90);

            if (iVar6 < 0) {

              iVar6 = (**(code **)(*local_a8 + 0x60))(local_a8,0,&local_a0);

            }

            else {

              iVar6 = (**(code **)(*local_90 + 0xe8))(local_90,0,2,&DAT_140349268,&local_a0);

              (**(code **)(*local_90 + 0x10))();

            }

            if (iVar6 < 0) {

              FUN_14012e2e0(9,"D3D12: Failed to find adapter for D3D12Device");

              (**(code **)(*local_a8 + 0x10))();

              FUN_140188670(lVar7);

              FUN_140188670(lVar8);

              return 0;

            }

            if (((cVar3 == '\0') || (cVar5 != '\0')) || (iVar6 = FUN_1401a9900(), iVar6 == 0)) {

              iVar6 = (*local_res20)(local_a0,0xb000,&DAT_1403492c8,&local_98);

              if (-1 < iVar6) {

                if (cVar3 == '\0') {

                  local_80 = 0;

                  uStack_78 = 0;

                  local_50 = 0;

                  local_70 = 0;

                  uStack_68 = 0;

                  local_48 = 0;

                  local_60 = 0;

                  uStack_58 = 0;

                  iVar6 = (**(code **)(*local_98 + 0x68))(local_98,0,&local_80,0x3c);

                  if (-1 < iVar6) {

                    bVar1 = false;

                    if (1 < (int)local_70) {

                      bVar1 = true;

                    }

                  }

                }

                if (cVar5 != '\0') {

                  local_res20 = (code *)CONCAT44(local_res20._4_4_,0x60);

                  iVar6 = (**(code **)(*local_98 + 0x68))(local_98,7,&local_res20,4);

                  if (-1 < iVar6) {

                    bVar2 = false;

                    if (0x5f < (int)local_res20) {

                      bVar2 = true;

                    }

                  }

                }

                (**(code **)(*local_98 + 0x10))();

              }

              (**(code **)(*local_a0 + 0x10))();

              (**(code **)(*local_a8 + 0x10))();

              FUN_140188670(lVar7);

              FUN_140188670(lVar8);

              if ((!bVar1) && (cVar3 == '\0')) {

                FUN_14012e2e0(9,"D3D12: Tier 2 Resource Binding is not supported");

                return 0;

              }

              if ((!bVar2) && (cVar4 == '\0')) {

                FUN_14012e2e0(9,"D3D12: DXIL is not supported and DXBC is not being provided");

                return 0;

              }

              if (iVar6 < 0) {

                FUN_14012e2e0(9,"D3D12: Could not create D3D12Device with feature level 11_0");

                return 0;

              }

            }

            else {

              (**(code **)(*local_a0 + 0x10))();

              (**(code **)(*local_a8 + 0x10))();

              FUN_140188670(lVar7);

              FUN_140188670(lVar8);

            }

            return 1;

          }

          (**(code **)(*local_a8 + 0x10))();

          pcVar10 = "D3D12: Failed to find DXGI1.4 support, required for DX12";

        }

        FUN_14012e2e0(9,pcVar10);

        FUN_140188670(lVar7);

        FUN_140188670(lVar8);

        return 0;

      }

      FUN_14012e2e0(9,"D3D12: Could not find dxgi.dll");

      return 0;

    }

    FUN_14012e2e0(9,"D3D12: Could not find d3d12.dll");

  }

  return 0;

}




