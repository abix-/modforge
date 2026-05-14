// Address: 0x1401dc800
// Ghidra name: FUN_1401dc800
// ============ 0x1401dc800 FUN_1401dc800 (size=1353) ============


undefined8 FUN_1401dc800(undefined8 *param_1,undefined8 param_2,undefined4 param_3)



{

  undefined8 *puVar1;

  uint uVar2;

  char cVar3;

  undefined4 uVar4;

  int iVar5;

  longlong lVar6;

  undefined8 uVar7;

  longlong lVar8;

  ulonglong uVar9;

  longlong lVar10;

  uint uVar11;

  uint uVar12;

  float fVar13;

  undefined4 local_res20 [2];

  undefined4 local_1a8 [2];

  longlong *local_1a0;

  undefined4 local_198;

  undefined4 uStack_194;

  undefined4 uStack_190;

  undefined4 uStack_18c;

  undefined8 local_188;

  undefined8 uStack_180;

  undefined8 local_178;

  undefined4 uStack_170;

  undefined8 uStack_16c;

  undefined4 uStack_164;

  undefined4 uStack_160;

  undefined4 uStack_15c;

  undefined1 local_158 [28];

  uint local_13c;

  uint local_138;

  uint local_11c;

  uint local_100;

  uint local_fc;

  uint local_c0;

  

  lVar10 = 0;

  uVar4 = FUN_14016ea50(param_2);

  lVar6 = FUN_140174d30(uVar4,"SDL.window.win32.hwnd",0);

  if (lVar6 == 0) {

    uVar7 = FUN_14012e850("Couldn\'t get window handle");

  }

  else {

    FUN_140155450(param_1,param_3);

    if (*(int *)(param_1 + 0x41) == 0x120005a0) {

      uVar12 = 1;

      lVar8 = FUN_1401841a0(1,0x1a0);

      uVar7 = 0;

      if (lVar8 != 0) {

        cVar3 = FUN_140180d20(lVar8,lVar8 + 8);

        if (cVar3 == '\0') {

          FUN_1401841e0(lVar8);

          uVar7 = FUN_14012e850("Unable to create Direct3D interface");

        }

        else {

          param_1[0x5c] = lVar8;

          *param_1 = &LAB_1401e0020;

          param_1[2] = FUN_1401df840;

          param_1[0xe] = FUN_1401dcf20;

          param_1[0xf] = FUN_1401dfa70;

          param_1[0x10] = FUN_1401dd2f0;

          param_1[3] = FUN_1401dd050;

          param_1[0x12] = FUN_1401dfb70;

          param_1[0x13] = FUN_1401dfec0;

          param_1[0x15] = FUN_1401dd9b0;

          param_1[0x16] = FUN_1401df920;

          param_1[0x17] = FUN_1401df580;

          param_1[4] = FUN_140018e60;

          param_1[5] = FUN_140018e60;

          param_1[6] = FUN_1401ddb50;

          param_1[7] = FUN_1401ddb50;

          param_1[0xb] = FUN_1401ddcc0;

          param_1[0xc] = FUN_1401dd960;

          param_1[0xd] = FUN_1401dead0;

          param_1[0x18] = FUN_1401de5a0;

          param_1[0x19] = FUN_1401de4e0;

          param_1[0x1a] = FUN_1401dd550;

          param_1[0x1b] = FUN_1401dd360;

          param_1[0x1c] = FUN_1401df780;

          FUN_1401dd960(param_1);

          param_1[0x20] = PTR_s_direct3d_1403e4b70;

          FUN_14014b7f0(param_1,0x16362004);

          FUN_14016ebe0(param_2,local_res20,local_1a8);

          uVar9 = FUN_14016e130(param_2);

          if ((uVar9 & 1) != 0) {

            lVar10 = FUN_14016e1f0(param_2);

          }

          local_198 = local_res20[0];

          uStack_194 = local_1a8[0];

          local_188 = 0;

          uStack_180 = 1;

          uStack_16c = 0;

          uStack_160 = 0;

          uStack_164 = 0;

          uStack_18c = 1;

          local_178 = lVar6;

          if (lVar10 == 0) {

            uStack_170 = 1;

            uStack_190 = 0;

          }

          else {

            uStack_170 = 0;

            uStack_190 = FUN_1401e0110(*(undefined4 *)(lVar10 + 4));

            fVar13 = (float)thunk_FUN_1402e33f0(*(undefined4 *)(lVar10 + 0x14));

            uStack_160 = (undefined4)(longlong)fVar13;

          }

          uStack_15c = 0x80000000;

          uVar4 = FUN_14016d540(param_2);

          uVar4 = FUN_140181010(uVar4);

          *(undefined4 *)(lVar8 + 0x18) = uVar4;

          iVar5 = (**(code **)(**(longlong **)(lVar8 + 8) + 0x70))

                            (*(longlong **)(lVar8 + 8),uVar4,1,local_158);

          if (iVar5 < 0) {

            uVar7 = FUN_1401df290("GetDeviceCaps()",iVar5);

          }

          else {

            uVar11 = 0x42;

            if ((local_13c & 0x10000) == 0) {

              uVar11 = 0x22;

            }

            if ((local_11c & 2) != 0) {

              if ((local_11c >> 8 & 1) == 0) {

                uVar7 = FUN_14012e850("Non-power-of-two textures are not supported");

                return uVar7;

              }

              *(undefined1 *)((longlong)param_1 + 0x115) = 1;

            }

            cVar3 = FUN_140142940("SDL_RENDER_DIRECT3D_THREADSAFE",0);

            puVar1 = (undefined8 *)(lVar8 + 0x10);

            uVar2 = uVar11 | 4;

            if (cVar3 == '\0') {

              uVar2 = uVar11;

            }

            iVar5 = (**(code **)(**(longlong **)(lVar8 + 8) + 0x80))

                              (*(longlong **)(lVar8 + 8),*(undefined4 *)(lVar8 + 0x18),1,local_178,

                               uVar2,&local_198,puVar1);

            if (iVar5 < 0) {

              uVar7 = FUN_1401df290("CreateDevice()",iVar5);

            }

            else {

              iVar5 = (**(code **)(*(longlong *)*puVar1 + 0x70))((longlong *)*puVar1,0,&local_1a0);

              if (iVar5 < 0) {

                uVar7 = FUN_1401df290("GetSwapChain()",iVar5);

              }

              else {

                iVar5 = (**(code **)(*local_1a0 + 0x48))(local_1a0,&local_198);

                if (iVar5 < 0) {

                  (**(code **)(*local_1a0 + 0x10))();

                  uVar7 = FUN_1401df290("GetPresentParameters()",iVar5);

                }

                else {

                  (**(code **)(*local_1a0 + 0x10))();

                  *(ulonglong *)(lVar8 + 0x20) = CONCAT44(uStack_194,local_198);

                  *(ulonglong *)(lVar8 + 0x28) = CONCAT44(uStack_18c,uStack_190);

                  *(undefined8 *)(lVar8 + 0x30) = local_188;

                  *(undefined8 *)(lVar8 + 0x38) = uStack_180;

                  *(undefined4 *)(lVar8 + 0x40) = (undefined4)local_178;

                  *(undefined4 *)(lVar8 + 0x44) = local_178._4_4_;

                  *(undefined4 *)(lVar8 + 0x48) = uStack_170;

                  *(undefined4 *)(lVar8 + 0x4c) = (undefined4)uStack_16c;

                  *(undefined4 *)(lVar8 + 0x50) = uStack_16c._4_4_;

                  *(undefined4 *)(lVar8 + 0x54) = uStack_164;

                  *(undefined4 *)(lVar8 + 0x58) = uStack_160;

                  *(undefined4 *)(lVar8 + 0x5c) = uStack_15c;

                  (**(code **)(*(longlong *)*puVar1 + 0x38))((longlong *)*puVar1,local_158);

                  if (local_100 < local_fc) {

                    local_fc = local_100;

                  }

                  uVar4 = FUN_14014f090(param_1);

                  FUN_140175360(uVar4,"SDL.renderer.max_texture_size",local_fc);

                  if ((local_138 & 0x20000) != 0) {

                    *(undefined1 *)(lVar8 + 0x62) = 1;

                  }

                  (**(code **)(*(longlong *)*puVar1 + 0x130))((longlong *)*puVar1,0,lVar8 + 0x88);

                  *(undefined8 *)(lVar8 + 0x90) = 0;

                  FUN_1401dd6d0(lVar8);

                  do {

                    iVar5 = FUN_140240470(*puVar1,uVar12,lVar8 + ((longlong)(int)uVar12 + 0x14) * 8)

                    ;

                    if (iVar5 < 0) {

                      FUN_1401df290("CreatePixelShader()",iVar5);

                    }

                    uVar12 = uVar12 + 1;

                  } while (uVar12 < 4);

                  if (((1 < local_c0) && (*(longlong *)(lVar8 + 0xa8) != 0)) &&

                     (*(longlong *)(lVar8 + 0xb0) != 0)) {

                    FUN_14014b7f0(param_1,0x13000801);

                  }

                  if ((2 < local_c0) && (*(longlong *)(lVar8 + 0xb8) != 0)) {

                    FUN_14014b7f0(param_1,0x32315659);

                    FUN_14014b7f0(param_1,0x56555949);

                  }

                  uVar7 = *puVar1;

                  uVar4 = FUN_14014f090(param_1);

                  FUN_140175480(uVar4,"SDL.renderer.d3d9.device",uVar7);

                  uVar7 = 1;

                }

              }

            }

          }

        }

      }

    }

    else {

      uVar7 = FUN_14012e850("Unsupported output colorspace");

    }

  }

  return uVar7;

}




