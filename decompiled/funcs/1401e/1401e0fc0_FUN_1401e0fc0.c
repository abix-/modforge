// Address: 0x1401e0fc0
// Ghidra name: FUN_1401e0fc0
// ============ 0x1401e0fc0 FUN_1401e0fc0 (size=1678) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_1401e0fc0(longlong param_1)



{

  longlong *plVar1;

  uint uVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  undefined4 uVar6;

  longlong lVar7;

  code *pcVar8;

  code *pcVar9;

  code *pcVar10;

  code *pcVar11;

  ulonglong uVar12;

  uint uVar13;

  undefined8 uVar14;

  longlong *local_res10;

  longlong *local_res18;

  longlong *local_res20;

  longlong *local_c8;

  longlong *local_c0;

  longlong *local_b8;

  undefined4 local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  undefined4 local_a4;

  undefined4 local_a0;

  undefined8 local_9c;

  undefined4 local_94;

  undefined8 local_90;

  undefined8 local_88;

  undefined4 local_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  undefined4 uStack_6c;

  undefined8 local_68;

  undefined4 local_60;

  undefined8 local_5c;

  undefined4 local_54;

  

  uVar14 = 0;

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  pcVar9 = (code *)0x0;

  local_c0 = (longlong *)0x0;

  local_res20 = (longlong *)0x0;

  local_res18 = (longlong *)0x0;

  local_c8 = (longlong *)0x0;

  local_b8 = (longlong *)0x0;

  local_b0 = 0xb100;

  local_ac = 0xb000;

  cVar3 = FUN_140142940("SDL_RENDER_DIRECT3D11_DEBUG",0);

  lVar7 = FUN_1401885b0("dxgi.dll");

  *plVar1 = lVar7;

  if (lVar7 == 0) {

    iVar5 = -0x7fffbffb;

  }

  else {

    pcVar8 = (code *)FUN_140188550(lVar7,"CreateDXGIFactory2");

    if ((pcVar8 == (code *)0x0) &&

       (pcVar9 = (code *)FUN_140188550(*plVar1,"CreateDXGIFactory"), pcVar9 == (code *)0x0)) {

      iVar5 = -0x7fffbffb;

    }

    else {

      lVar7 = FUN_1401885b0("d3d11.dll");

      plVar1[1] = lVar7;

      if (lVar7 == 0) {

        iVar5 = -0x7fffbffb;

      }

      else {

        pcVar10 = (code *)FUN_140188550(lVar7,"D3D11CreateDevice");

        if (pcVar10 == (code *)0x0) {

          iVar5 = -0x7fffbffb;

        }

        else {

          if (cVar3 != '\0') {

            local_res10 = (longlong *)0x0;

            pcVar11 = (code *)FUN_140188550(*plVar1,"DXGIGetDebugInterface1");

            if (pcVar11 == (code *)0x0) {

              iVar5 = -0x7fffbffb;

              goto LAB_1401e15bf;

            }

            iVar5 = (*pcVar11)(0,&DAT_14034b428,plVar1 + 3);

            if (iVar5 < 0) {

              FUN_1401a9ef0("DXGIGetDebugInterface1",iVar5);

              goto LAB_1401e15bf;

            }

            iVar5 = (*pcVar11)(0,&DAT_14034b438,&local_res10);

            if (iVar5 < 0) {

              FUN_1401a9ef0("DXGIGetDebugInterface1",iVar5);

              goto LAB_1401e15bf;

            }

            local_78 = _DAT_14034b448;

            uStack_74 = _UNK_14034b44c;

            uStack_70 = _UNK_14034b450;

            uStack_6c = _UNK_14034b454;

            (**(code **)(*local_res10 + 0x108))(local_res10,&local_78,1);

            local_78 = _DAT_14034b448;

            uStack_74 = _UNK_14034b44c;

            uStack_70 = _UNK_14034b450;

            uStack_6c = _UNK_14034b454;

            (**(code **)(*local_res10 + 0x108))(local_res10,&local_78,0,1);

            if (local_res10 != (longlong *)0x0) {

              (**(code **)(*local_res10 + 0x10))();

            }

            uVar14 = 1;

          }

          if (pcVar8 == (code *)0x0) {

            iVar5 = (*pcVar9)(&DAT_14034b3c8,plVar1 + 2);

          }

          else {

            iVar5 = (*pcVar8)(uVar14,&DAT_14034b3c8,plVar1 + 2);

          }

          if (iVar5 < 0) {

            FUN_1401a9ef0("CreateDXGIFactory",iVar5);

          }

          else {

            *(undefined4 *)((longlong)plVar1 + 0x3c) = 0;

            uVar12 = FUN_14016e130(*(undefined8 *)(param_1 + 0x118));

            if (((uVar12 >> 0x1e & 1) == 0) &&

               (iVar5 = (*(code *)**(undefined8 **)plVar1[2])

                                  ((undefined8 *)plVar1[2],&DAT_14034b3b8,&local_c0), -1 < iVar5)) {

              local_res10 = (longlong *)((ulonglong)local_res10 & 0xffffffff00000000);

              iVar5 = (**(code **)(*local_c0 + 0xe0))(local_c0,0,&local_res10,4);

              if ((-1 < iVar5) && ((int)local_res10 != 0)) {

                *(undefined4 *)((longlong)plVar1 + 0x3c) = 0x800;

              }

              (**(code **)(*local_c0 + 0x10))();

            }

            cVar4 = FUN_140142940("SDL_RENDER_DIRECT3D11_WARP",0);

            if (cVar4 == '\0') {

              uVar14 = 0;

              iVar5 = (**(code **)(*(longlong *)plVar1[2] + 0x38))

                                ((longlong *)plVar1[2],0,&local_res20);

              if (iVar5 < 0) {

                FUN_1401a9ef0("EnumAdapters",iVar5);

                goto LAB_1401e15bf;

              }

            }

            else {

              uVar14 = 5;

            }

            uVar13 = 0x22;

            if (cVar3 == '\0') {

              uVar13 = 0x20;

            }

            cVar3 = FUN_140142940("SDL_RENDER_DIRECT3D_THREADSAFE",0);

            uVar2 = uVar13 | 1;

            if (cVar3 != '\0') {

              uVar2 = uVar13;

            }

            iVar5 = (*pcVar10)(local_res20,uVar14,0,uVar2,&local_b0,2,7,&local_res18,plVar1 + 0x2b,

                               &local_c8);

            if (iVar5 < 0) {

              FUN_1401a9ef0("D3D11CreateDevice",iVar5);

            }

            else {

              iVar5 = (**(code **)*local_res18)(local_res18,&DAT_14034b3f8,plVar1 + 4);

              if (iVar5 < 0) {

                FUN_1401a9ef0("ID3D11Device to ID3D11Device1",iVar5);

              }

              else {

                iVar5 = (**(code **)*local_c8)(local_c8,&DAT_14034b408,plVar1 + 5);

                if (iVar5 < 0) {

                  FUN_1401a9ef0("ID3D11DeviceContext to ID3D11DeviceContext1",iVar5);

                }

                else {

                  iVar5 = (**(code **)*local_res18)(local_res18,&DAT_14034b3d8,&local_b8);

                  if (iVar5 < 0) {

                    FUN_1401a9ef0("ID3D11Device to IDXGIDevice1",iVar5);

                  }

                  else {

                    iVar5 = (**(code **)(*local_b8 + 0x60))(local_b8,1);

                    if (iVar5 < 0) {

                      FUN_1401a9ef0("IDXGIDevice1::SetMaximumFrameLatency",iVar5);

                    }

                    else {

                      uVar6 = FUN_14014f090(param_1);

                      FUN_140175360(uVar6,"SDL.renderer.max_texture_size",0x4000);

                      cVar3 = FUN_1402404e0(plVar1[4],plVar1 + 0x1c,plVar1 + 0xb);

                      if (cVar3 != '\0') {

                        local_5c = 0;

                        local_54 = 0;

                        local_68 = 0x80;

                        local_60 = 4;

                        iVar5 = (**(code **)(*(longlong *)plVar1[4] + 0x18))

                                          ((longlong *)plVar1[4],&local_68,0,plVar1 + 0x3e);

                        if (iVar5 < 0) {

                          FUN_1401a9ef0("ID3D11Device1::CreateBuffer [vertex shader constants]",

                                        iVar5);

                        }

                        else {

                          local_a4 = 1;

                          local_88 = 0;

                          local_9c = 0;

                          local_a0 = 0;

                          local_94 = 0;

                          local_90 = 1;

                          local_a8 = 3;

                          iVar5 = (**(code **)(*(longlong *)plVar1[4] + 0xb0))

                                            ((longlong *)plVar1[4],&local_a8,plVar1 + 0x2c);

                          if (iVar5 < 0) {

                            FUN_1401a9ef0("ID3D11Device1::CreateRasterizerState [main rasterizer]",

                                          iVar5);

                          }

                          else {

                            local_90 = CONCAT44(1,(undefined4)local_90);

                            iVar5 = (**(code **)(*(longlong *)plVar1[4] + 0xb0))

                                              ((longlong *)plVar1[4],&local_a8,plVar1 + 0x2d);

                            if (iVar5 < 0) {

                              FUN_1401a9ef0("ID3D11Device1::CreateRasterizerState [clipped rasterizer]"

                                            ,iVar5);

                            }

                            else {

                              lVar7 = FUN_1401e0e10(param_1,1);

                              if (lVar7 != 0) {

                                (**(code **)(*(longlong *)plVar1[5] + 0x88))

                                          ((longlong *)plVar1[5],plVar1[0xb]);

                                (**(code **)(*(longlong *)plVar1[5] + 0x58))

                                          ((longlong *)plVar1[5],plVar1[0x1c],0,0);

                                (**(code **)(*(longlong *)plVar1[5] + 0x38))

                                          ((longlong *)plVar1[5],0,1,plVar1 + 0x3e);

                                lVar7 = plVar1[4];

                                uVar6 = FUN_14014f090(param_1);

                                FUN_140175480(uVar6,"SDL.renderer.d3d11.device",lVar7);

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

      }

    }

  }

LAB_1401e15bf:

  if (local_res20 != (longlong *)0x0) {

    (**(code **)(*local_res20 + 0x10))();

    local_res20 = (longlong *)0x0;

  }

  if (local_res18 != (longlong *)0x0) {

    (**(code **)(*local_res18 + 0x10))();

    local_res18 = (longlong *)0x0;

  }

  if (local_c8 != (longlong *)0x0) {

    (**(code **)(*local_c8 + 0x10))();

    local_c8 = (longlong *)0x0;

  }

  if (local_b8 != (longlong *)0x0) {

    (**(code **)(*local_b8 + 0x10))();

  }

  return iVar5;

}




