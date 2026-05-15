// Address: 0x1401e6200
// Ghidra name: FUN_1401e6200
// ============ 0x1401e6200 FUN_1401e6200 (size=2348) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_1401e6200(longlong param_1)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  HMODULE hModule;

  longlong lVar5;

  code *pcVar6;

  code *pcVar7;

  INT_PTR IVar8;

  longlong *plVar9;

  ulonglong uVar10;

  longlong *plVar11;

  uint uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  FARPROC *ppFVar15;

  longlong *local_res8;

  code *local_res10;

  FARPROC local_res18;

  int local_res20;

  longlong *local_108;

  undefined4 local_100;

  undefined4 local_fc;

  undefined8 local_f8;

  undefined8 local_e8;

  undefined4 uStack_e0;

  undefined4 uStack_dc;

  longlong *local_d8;

  longlong local_d0;

  longlong local_c8;

  undefined8 local_c0;

  undefined8 uStack_b8;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  longlong **pplStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  uVar10 = 0;

  local_108 = (longlong *)0x0;

  local_d8 = plVar1;

  cVar2 = FUN_140142940("SDL_RENDER_DIRECT3D11_DEBUG",0);

  hModule = GetModuleHandleW(L"kernel32.dll");

  if ((hModule != (HMODULE)0x0) &&

     (local_res18 = GetProcAddress(hModule,"CreateEventExW"), local_res18 != (FARPROC)0x0)) {

    lVar5 = FUN_1401885b0("dxgi.dll");

    *plVar1 = lVar5;

    if ((lVar5 != 0) &&

       (pcVar6 = (code *)FUN_140188550(lVar5,"CreateDXGIFactory2"), pcVar6 != (code *)0x0)) {

      lVar5 = FUN_1401885b0("D3D12.dll");

      plVar1[1] = lVar5;

      if ((lVar5 != 0) &&

         (local_res10 = (code *)FUN_140188550(lVar5,"D3D12CreateDevice"), local_res10 != (code *)0x0

         )) {

        uVar13 = uVar10;

        if (cVar2 == '\0') {

LAB_1401e640b:

          iVar3 = (*pcVar6)(uVar13,&DAT_14034bba0,plVar1 + 2);

          if (iVar3 < 0) {

            FUN_1401a9ef0("CreateDXGIFactory",iVar3);

          }

          else {

            iVar3 = (**(code **)(*(longlong *)plVar1[2] + 0xe8))

                              ((longlong *)plVar1[2],0,2,&DAT_14034bbb0,plVar1 + 3);

            if (iVar3 < 0) {

              FUN_1401a9ef0("IDXGIFactory6::EnumAdapterByGPUPreference",iVar3);

            }

            else {

              iVar3 = (*local_res10)(plVar1[3],0xb000,&DAT_14034bbc0,&local_108);

              if (iVar3 < 0) {

                FUN_1401a9ef0("D3D12CreateDevice",iVar3);

              }

              else {

                if (cVar2 != '\0') {

                  local_res10 = (code *)0x0;

                  local_res8 = (longlong *)CONCAT44(local_res8._4_4_,3);

                  iVar3 = (**(code **)*local_108)(local_108,&DAT_14034bc90,&local_res10);

                  if (iVar3 < 0) {

                    FUN_1401a9ef0("ID3D12Device to ID3D12InfoQueue",iVar3);

                    goto LAB_1401e6add;

                  }

                  pplStack_60 = &local_res8;

                  local_68 = 1;

                  local_a8 = 0;

                  uStack_a0 = 0;

                  local_98 = 0;

                  uStack_90 = 0;

                  local_88 = 0;

                  uStack_80 = 0;

                  local_78 = 0;

                  uStack_70 = 0;

                  local_58 = 0;

                  uStack_50 = 0;

                  (**(code **)(*(longlong *)local_res10 + 0x88))(local_res10,&local_a8);

                  (**(code **)(*(longlong *)local_res10 + 0xf8))(local_res10,1,1);

                  (**(code **)(*(longlong *)local_res10 + 0xf8))(local_res10,0,1);

                  if (local_res10 != (code *)0x0) {

                    (**(code **)(*(longlong *)local_res10 + 0x10))();

                  }

                }

                iVar3 = (**(code **)*local_108)(local_108,&DAT_14034bbc0,plVar1 + 6);

                if (iVar3 < 0) {

                  FUN_1401a9ef0("ID3D12Device to ID3D12Device1",iVar3);

                }

                else {

                  local_c0 = 0;

                  uStack_b8 = 0;

                  iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x40))

                                    ((longlong *)plVar1[6],&local_c0,&DAT_14034bc10,plVar1 + 8);

                  if (iVar3 < 0) {

                    FUN_1401a9ef0("ID3D12Device::CreateCommandQueue",iVar3);

                  }

                  else {

                    local_f8 = 0;

                    local_fc = 2;

                    local_100 = 2;

                    iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x70))

                                      ((longlong *)plVar1[6],&local_100,&DAT_14034bc20,plVar1 + 0xd)

                    ;

                    if (iVar3 < 0) {

                      FUN_1401a9ef0("ID3D12Device::CreateDescriptorHeap [rtv]",iVar3);

                    }

                    else {

                      uVar4 = (**(code **)(*local_108 + 0x78))(local_108,2);

                      *(undefined4 *)(plVar1 + 0xe) = uVar4;

                      local_fc = 0x4000;

                      iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x70))

                                        ((longlong *)plVar1[6],&local_100,&DAT_14034bc20,

                                         plVar1 + 0xf);

                      if (iVar3 < 0) {

                        FUN_1401a9ef0("ID3D12Device::CreateDescriptorHeap [texture rtv]",iVar3);

                      }

                      else {

                        local_f8 = 1;

                        local_fc = 0x4000;

                        local_100 = 0;

                        iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x70))

                                          ((longlong *)plVar1[6],&local_100,&DAT_14034bc20,

                                           plVar1 + 0x10);

                        if (iVar3 < 0) {

                          FUN_1401a9ef0("ID3D12Device::CreateDescriptorHeap  [srv]",iVar3);

                        }

                        else {

                          local_d0 = plVar1[0x10];

                          uVar4 = (**(code **)(*local_108 + 0x78))(local_108,0);

                          *(undefined4 *)(plVar1 + 0x11) = uVar4;

                          local_f8 = 1;

                          local_fc = 8;

                          local_100 = 1;

                          iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x70))

                                            ((longlong *)plVar1[6],&local_100,&DAT_14034bc20,

                                             plVar1 + 0x12);

                          if (iVar3 < 0) {

                            FUN_1401a9ef0("ID3D12Device::CreateDescriptorHeap  [sampler]",iVar3);

                          }

                          else {

                            local_c8 = plVar1[0x12];

                            uVar4 = (**(code **)(*local_108 + 0x78))(local_108,1);

                            *(undefined4 *)(plVar1 + 0x13) = uVar4;

                            uVar13 = uVar10;

                            do {

                              iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x48))

                                                ((longlong *)plVar1[6],0,&DAT_14034bc30,

                                                 plVar1 + uVar13 + 0x14);

                              if (iVar3 < 0) {

                                FUN_1401a9ef0("ID3D12Device::CreateCommandAllocator",iVar3);

                                goto LAB_1401e6add;

                              }

                              uVar12 = (int)uVar13 + 1;

                              uVar13 = (ulonglong)uVar12;

                            } while ((int)uVar12 < 2);

                            iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x60))

                                              ((longlong *)plVar1[6],0,0,plVar1[0x14],0,

                                               &DAT_14034bc40,plVar1 + 9);

                            if (iVar3 < 0) {

                              FUN_1401a9ef0("ID3D12Device::CreateCommandList",iVar3);

                            }

                            else {

                              plVar9 = (longlong *)plVar1[9];

                              (**(code **)(*plVar9 + 0xe0))(plVar9,2,&local_d0);

                              iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x120))

                                                ((longlong *)plVar1[6],plVar1[0x18],0,&DAT_14034bc50

                                                 ,plVar1 + 0x1a);

                              if (iVar3 < 0) {

                                FUN_1401a9ef0("ID3D12Device::CreateFence",iVar3);

                              }

                              else {

                                plVar1[0x18] = plVar1[0x18] + 1;

                                IVar8 = (*local_res18)(0,0,0,0x100002);

                                plVar1[0x1b] = IVar8;

                                uVar13 = uVar10;

                                if (IVar8 == 0) {

                                  FUN_1401a9ef0("CreateEventEx",iVar3);

                                }

                                else {

                                  do {

                                    FUN_140240630(uVar13,&local_e8);

                                    iVar3 = (**(code **)(*(longlong *)plVar1[6] + 0x80))

                                                      ((longlong *)plVar1[6],0,local_e8,

                                                       CONCAT44(uStack_dc,uStack_e0),&DAT_14034bc70,

                                                       plVar1 + uVar13 + 0x1c);

                                    local_res20 = iVar3;

                                    if (iVar3 < 0) {

                                      FUN_1401a9ef0("ID3D12Device::CreateRootSignature",iVar3);

                                      goto LAB_1401e6add;

                                    }

                                    uVar12 = (int)uVar13 + 1;

                                    uVar13 = (ulonglong)uVar12;

                                  } while ((int)uVar12 < 3);

                                  local_res10 = (code *)CONCAT44(local_res10._4_4_,1);

                                  local_res18 = (FARPROC)CONCAT44(local_res18._4_4_,0x57);

                                  uVar13 = uVar10;

                                  do {

                                    local_e8 = &local_res10;

                                    local_res8 = (longlong *)

                                                 ((ulonglong)local_res8 & 0xffffffff00000000);

                                    do {

                                      uVar4 = *(undefined4 *)local_e8;

                                      iVar3 = 1;

                                      do {

                                        ppFVar15 = &local_res18;

                                        uVar14 = uVar10;

                                        do {

                                          lVar5 = FUN_1401e6cf0(param_1,uVar13,uVar4,iVar3,

                                                                *(undefined4 *)ppFVar15);

                                          plVar1 = local_d8;

                                          if (lVar5 == 0) goto LAB_1401e6ad8;

                                          uVar12 = (int)uVar14 + 1;

                                          uVar14 = (ulonglong)uVar12;

                                          ppFVar15 = (FARPROC *)((longlong)ppFVar15 + 4);

                                        } while (uVar12 == 0);

                                        iVar3 = iVar3 + 1;

                                      } while (iVar3 < 4);

                                      iVar3 = (int)local_res8 + 1;

                                      local_e8 = (code **)((longlong)local_e8 + 4);

                                      local_res8 = (longlong *)CONCAT44(local_res8._4_4_,iVar3);

                                    } while (iVar3 == 0);

                                    uVar12 = (int)uVar13 + 1;

                                    uVar13 = (ulonglong)uVar12;

                                  } while ((int)uVar12 < 3);

                                  lVar5 = 0x100;

                                  uVar13 = uVar10;

                                  do {

                                    FUN_1401e7830(plVar1,uVar13,0x10000);

                                    uVar13 = uVar13 + 1;

                                    lVar5 = lVar5 + -1;

                                  } while (lVar5 != 0);

                                  (**(code **)(*(longlong *)plVar1[0x12] + 0x48))

                                            ((longlong *)plVar1[0x12],plVar1 + 0x422);

                                  uVar12 = *(uint *)(plVar1 + 0x13);

                                  lVar5 = plVar1[0x422];

                                  plVar1[0x423] = lVar5 + (ulonglong)uVar12;

                                  plVar1[0x424] = (ulonglong)(uVar12 * 2) + lVar5;

                                  plVar1[0x425] = (ulonglong)(uVar12 * 3) + lVar5;

                                  plVar1[0x426] = (ulonglong)(uVar12 * 4) + lVar5;

                                  plVar1[0x427] = (ulonglong)(uVar12 * 5) + lVar5;

                                  plVar9 = plVar1 + 0x44e;

                                  plVar1[0x428] = (ulonglong)(uVar12 * 6) + lVar5;

                                  plVar11 = plVar1 + 0x44f;

                                  plVar1[0x429] = (ulonglong)(uVar12 * 7) + lVar5;

                                  uVar13 = uVar10;

                                  do {

                                    plVar9[-1] = uVar10;

                                    if ((int)uVar13 != 0x3fff) {

                                      *plVar9 = (longlong)plVar11;

                                    }

                                    uVar12 = (int)uVar13 + 1;

                                    uVar13 = (ulonglong)uVar12;

                                    uVar10 = uVar10 + 1;

                                    plVar11 = plVar11 + 2;

                                    plVar9 = plVar9 + 2;

                                  } while ((int)uVar12 < 0x4000);

                                  plVar1[0x44c] = (longlong)(plVar1 + 0x44d);

                                  uVar4 = FUN_14014f090(param_1);

                                  FUN_140175480(uVar4,"SDL.renderer.d3d12.device",plVar1[6]);

                                  FUN_140175480(uVar4,"SDL.renderer.d3d12.command_queue",plVar1[8]);

                                  iVar3 = local_res20;

                                }

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

              }

            }

          }

          goto LAB_1401e6add;

        }

        pcVar7 = (code *)FUN_140188550(plVar1[1],"D3D12GetDebugInterface");

        if (pcVar7 != (code *)0x0) {

          iVar3 = (*pcVar7)(&DAT_14034bc00,plVar1 + 7);

          if (-1 < iVar3) {

            (**(code **)(*(longlong *)plVar1[7] + 0x18))();

          }

          local_res8 = (longlong *)0x0;

          pcVar7 = (code *)FUN_140188550(*plVar1,"DXGIGetDebugInterface1");

          if (pcVar7 != (code *)0x0) {

            iVar3 = (*pcVar7)(0,&DAT_14034bbe0,plVar1 + 4);

            if (iVar3 < 0) {

              FUN_1401a9ef0("DXGIGetDebugInterface1",iVar3);

              goto LAB_1401e6add;

            }

            iVar3 = (*pcVar7)(0,&DAT_14034bbf0,&local_res8);

            if (iVar3 < 0) {

              FUN_1401a9ef0("DXGIGetDebugInterface1",iVar3);

              goto LAB_1401e6add;

            }

            local_e8 = (code **)CONCAT44(_UNK_14034bca4,_DAT_14034bca0);

            uStack_e0 = _UNK_14034bca8;

            uStack_dc = _UNK_14034bcac;

            (**(code **)(*local_res8 + 0x108))(local_res8,&local_e8,1);

            local_e8 = (code **)CONCAT44(_UNK_14034bca4,_DAT_14034bca0);

            uStack_e0 = _UNK_14034bca8;

            uStack_dc = _UNK_14034bcac;

            (**(code **)(*local_res8 + 0x108))(local_res8,&local_e8,0,1);

            if (local_res8 != (longlong *)0x0) {

              (**(code **)(*local_res8 + 0x10))();

            }

            uVar13 = 1;

            goto LAB_1401e640b;

          }

        }

      }

    }

  }

LAB_1401e6ad8:

  iVar3 = -0x7fffbffb;

LAB_1401e6add:

  if (local_108 != (longlong *)0x0) {

    (**(code **)(*local_108 + 0x10))();

  }

  return iVar3;

}




