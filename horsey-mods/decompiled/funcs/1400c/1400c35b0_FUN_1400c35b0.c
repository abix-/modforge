// Address: 0x1400c35b0
// Ghidra name: FUN_1400c35b0
// ============ 0x1400c35b0 FUN_1400c35b0 (size=3356) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400c35b0(void)



{

  code *pcVar1;

  longlong lVar2;

  int iVar3;

  char cVar4;

  undefined4 uVar5;

  int iVar6;

  HANDLE pvVar7;

  size_t sVar8;

  longlong lVar9;

  undefined8 *******pppppppuVar10;

  undefined8 *puVar11;

  longlong lVar12;

  undefined8 uVar13;

  longlong lVar14;

  ulonglong uVar15;

  LPCSTR lpPathName;

  ulonglong uVar16;

  ulonglong uVar17;

  int local_298;

  int local_294;

  int local_290;

  int local_28c;

  undefined8 ******local_288;

  undefined8 uStack_280;

  ulonglong local_278;

  ulonglong uStack_270;

  int local_268;

  int local_264;

  int local_260;

  int local_25c;

  undefined8 ******local_258 [3];

  ulonglong local_240;

  undefined1 local_238 [256];

  char local_138 [272];

  

  cVar4 = SDL_Init(0x4020);

  if (cVar4 == '\0') {

    return 0xffffffffffffffff;

  }

  SDL_SetHint("SDL_RENDER_GPU_LOW_POWER",&DAT_14030df48);

  pvVar7 = GetCurrentProcess();

  K32GetModuleFileNameExA(pvVar7,0,local_138);

  sVar8 = strlen(local_138);

  FUN_140027f50(&DAT_1403da618,local_138,sVar8);

  puVar11 = &DAT_1403da618;

  if (0xf < DAT_1403da630) {

    puVar11 = DAT_1403da618;

  }

  iVar6 = -1;

  if (DAT_1403da628 != 0) {

    lVar9 = -1;

    if (DAT_1403da628 - 1 != -1) {

      lVar9 = DAT_1403da628 - 1;

    }

    lVar14 = lVar9 + 1 + (longlong)puVar11;

    lVar9 = thunk_FUN_1402c5c90(puVar11,lVar14,&DAT_14030df6c);

    iVar6 = -1;

    if (lVar9 != lVar14) {

      iVar6 = (int)lVar9 - (int)puVar11;

    }

  }

  uVar17 = (longlong)iVar6 + 1U;

  if (DAT_1403da628 < (longlong)iVar6 + 1U) {

    uVar17 = DAT_1403da628;

  }

  local_288 = (undefined8 *******)0x0;

  uStack_280 = 0;

  puVar11 = &DAT_1403da618;

  if (0xf < DAT_1403da630) {

    puVar11 = DAT_1403da618;

  }

  if (uVar17 < 0x8000000000000000) {

    uVar16 = 0xf;

    local_278 = uVar17;

    if (uVar17 < 0x10) {

      uStack_270 = 0xf;

      FUN_1402f8e20(&local_288,puVar11);

      *(undefined1 *)((longlong)&local_288 + uVar17) = 0;

    }

    else {

      uVar15 = uVar17 | 0xf;

      if (uVar15 < 0x8000000000000000) {

        if (uVar15 < 0x16) {

          uVar15 = 0x16;

        }

      }

      else {

        uVar15 = 0x7fffffffffffffff;

      }

      pppppppuVar10 = (undefined8 *******)FUN_1400285e0(uVar15 + 1);

      local_288 = pppppppuVar10;

      uStack_270 = uVar15;

      FUN_1402f8e20(pppppppuVar10,puVar11);

      *(undefined1 *)((longlong)pppppppuVar10 + uVar17) = 0;

    }

    FUN_1400c5580(&DAT_1403da618,&local_288);

    if (0xf < uStack_270) {

      if ((0xfff < uStack_270 + 1) &&

         (0x1f < (ulonglong)((longlong)local_288 + (-8 - (longlong)local_288[-1]))))

      goto LAB_1400c4288;

      FUN_1402c7088();

    }

    puVar11 = &DAT_1403da618;

    if (0xf < DAT_1403da630) {

      puVar11 = DAT_1403da618;

    }

    FUN_140027f50(&DAT_1403da658,puVar11,DAT_1403da628);

    FUN_140027810(&DAT_1403da618,&DAT_14030af24,5);

    lVar9 = DAT_1403da668;

    if (0x7fffffffffffffffU - DAT_1403da668 < 6) goto LAB_1400c4282;

    uVar17 = DAT_1403da668 + 6;

    pppppppuVar10 = &local_288;

    puVar11 = &DAT_1403da658;

    if (0xf < DAT_1403da670) {

      puVar11 = DAT_1403da658;

    }

    uVar15 = 0xf;

    local_288 = (undefined8 *******)0x0;

    uStack_280 = 0;

    if (0xf < uVar17) {

      uVar15 = uVar17 | 0xf;

      if (uVar15 < 0x8000000000000000) {

        if (uVar15 < 0x16) {

          uVar15 = 0x16;

        }

      }

      else {

        uVar15 = 0x7fffffffffffffff;

      }

      pppppppuVar10 = (undefined8 *******)FUN_1400285e0(uVar15 + 1);

      local_288 = pppppppuVar10;

    }

    local_278 = uVar17;

    uStack_270 = uVar15;

    FUN_1402f8e20(pppppppuVar10,puVar11);

    *(undefined4 *)(lVar9 + (longlong)pppppppuVar10) = DAT_14030df70;

    *(undefined2 *)(lVar9 + 4 + (longlong)pppppppuVar10) = DAT_14030df74;

    *(undefined1 *)((longlong)pppppppuVar10 + uVar17) = 0;

    FUN_1400c5580(&DAT_1403da678,&local_288);

    if (0xf < uStack_270) {

      if ((0xfff < uStack_270 + 1) &&

         (0x1f < (ulonglong)((longlong)local_288 + (-8 - (longlong)local_288[-1]))))

      goto LAB_1400c4288;

      FUN_1402c7088();

    }

    lVar9 = DAT_1403da668;

    if (4 < 0x7fffffffffffffffU - DAT_1403da668) {

      uVar17 = DAT_1403da668 + 5;

      pppppppuVar10 = &local_288;

      puVar11 = &DAT_1403da658;

      if (0xf < DAT_1403da670) {

        puVar11 = DAT_1403da658;

      }

      uVar15 = 0xf;

      local_288 = (undefined8 *******)0x0;

      uStack_280 = 0;

      if (0xf < uVar17) {

        uVar15 = uVar17 | 0xf;

        if (uVar15 < 0x8000000000000000) {

          if (uVar15 < 0x16) {

            uVar15 = 0x16;

          }

        }

        else {

          uVar15 = 0x7fffffffffffffff;

        }

        pppppppuVar10 = (undefined8 *******)FUN_1400285e0(uVar15 + 1);

        local_288 = pppppppuVar10;

      }

      local_278 = uVar17;

      uStack_270 = uVar15;

      FUN_1402f8e20(pppppppuVar10,puVar11);

      *(undefined4 *)((longlong)pppppppuVar10 + lVar9) = DAT_14030df78;

      *(undefined1 *)((longlong)pppppppuVar10 + lVar9 + 4) = DAT_14030df7c;

      *(undefined1 *)((longlong)pppppppuVar10 + uVar17) = 0;

      FUN_1400c5580(&DAT_1403da638,&local_288);

      if (0xf < uStack_270) {

        if ((0xfff < uStack_270 + 1) &&

           (0x1f < (ulonglong)((longlong)local_288 + (-8 - (longlong)local_288[-1])))) {

LAB_1400c4288:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

      lpPathName = (LPCSTR)&DAT_1403da638;

      if (0xf < DAT_1403da650) {

        lpPathName = DAT_1403da638;

      }

      CreateDirectoryA(lpPathName,(LPSECURITY_ATTRIBUTES)0x0);

      FUN_140076a10();

      SDL_GetDisplayUsableBounds(1,&local_298);

      if (DAT_1403d950c == '\0') {

        if (DAT_1403d9518 == 0) {

          iVar6 = 0xc80;

          iVar3 = 0x708;

          do {

            DAT_1403d951c = iVar3;

            DAT_1403d9518 = iVar6;

            if ((DAT_1403d9518 <= (local_290 * 8) / 10) && (DAT_1403d951c <= (local_28c * 8) / 10))

            break;

            iVar6 = DAT_1403d9518 + -0x140;

            iVar3 = DAT_1403d951c + -0xb4;

          } while (0xb3 < DAT_1403d951c + -0xb4);

        }

        DAT_1403d9518 = FUN_1400c5f50(DAT_1403d9518,0x140);

        DAT_1403d951c = FUN_1400c5f50(DAT_1403d951c,0xb4,local_28c);

        DAT_1403d9e60 = DAT_1403d9518;

        if (DAT_1403d9510 == -1) {

          DAT_1403d9510 = (local_290 / 2 - DAT_1403d9518 / 2) + local_298;

        }

        if (DAT_1403d9514 == -1) {

          DAT_1403d9514 = (local_28c / 2 - DAT_1403d951c / 2) + local_294;

        }

        DAT_1403d9e64 = DAT_1403d951c;

        DAT_1403d9510 = FUN_1400c5f50(DAT_1403d9510,local_298,local_290 - DAT_1403d9518);

        DAT_1403d9514 = FUN_1400c5f50(DAT_1403d9514,local_294,local_28c - DAT_1403d951c);

        uVar5 = SDL_CreateProperties();

        SDL_SetStringProperty(uVar5,"SDL.window.create.title","Horsey Game");

        SDL_SetNumberProperty(uVar5,"SDL.window.create.x",(longlong)DAT_1403d9510);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.y",(longlong)DAT_1403d9514);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.width",(longlong)DAT_1403d9518);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.height",(longlong)DAT_1403d951c);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.resizable",1);

        lVar9 = SDL_CreateWindowWithProperties(uVar5);

      }

      else {

        uVar5 = SDL_CreateProperties();

        SDL_SetStringProperty(uVar5,"SDL.window.create.title","Horsey Game");

        SDL_SetNumberProperty(uVar5,"SDL.window.create.x",(longlong)local_298);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.y",(longlong)local_294);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.width",(longlong)local_290);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.height",(longlong)local_28c);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.borderless",1);

        SDL_SetNumberProperty(uVar5,"SDL.window.create.resizable",1);

        lVar9 = SDL_CreateWindowWithProperties(uVar5);

        DAT_1403d9e60 = local_290;

        DAT_1403d9e64 = local_28c;

      }

      if (lVar9 == 0) {

        uVar13 = SDL_GetError();

        FUN_1400c4340("Could not create window: %s\n",uVar13);

        pcVar1 = (code *)swi(3);

        uVar13 = (*pcVar1)();

        return uVar13;

      }

      DAT_1403f3360 = SDL_GetWindowID(lVar9);

      SDL_SetWindowFullscreenMode(lVar9,0);

      DAT_1403f3398 = SDL_CreateRenderer(lVar9,0);

      SDL_SetRenderVSync(DAT_1403f3398,1);

      SDL_HideCursor();

      DAT_1403f3354 = '\0';

      iVar6 = SteamInternal_SteamAPI_Init("SteamUtils010",0);

      if (iVar6 == 0) {

        DAT_1403f3354 = '\x01';

        puVar11 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1403da6b0);

        (**(code **)(*(longlong *)*puVar11 + 0x50))((longlong *)*puVar11,3);

        puVar11 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1403da6b0);

        cVar4 = (**(code **)(*(longlong *)*puVar11 + 0x110))();

        DAT_1403d9e70 = cVar4 == '\0';

        puVar11 = (undefined8 *)SteamInternal_ContextInit(&PTR_FUN_1403da6c8);

        DAT_1403f3356 =

             (**(code **)(*(longlong *)*puVar11 + 0x78))((longlong *)*puVar11,local_238,0xff);

      }

      FUN_14008cc20();

      lVar14 = DAT_1403da668;

      if (DAT_1403f3357 != '\0') {

        if (0x7fffffffffffffffU - DAT_1403da668 < 9) {

                    /* WARNING: Subroutine does not return */

          FUN_140024130();

        }

        uVar17 = DAT_1403da668 + 9;

        pppppppuVar10 = &local_288;

        puVar11 = &DAT_1403da658;

        if (0xf < DAT_1403da670) {

          puVar11 = DAT_1403da658;

        }

        local_288 = (undefined8 *******)0x0;

        uStack_280 = 0;

        local_278 = 0;

        uStack_270 = 0;

        if (0xf < uVar17) {

          uVar16 = uVar17 | 0xf;

          if (uVar16 < 0x8000000000000000) {

            if (uVar16 < 0x16) {

              uVar16 = 0x16;

            }

          }

          else {

            uVar16 = 0x7fffffffffffffff;

          }

          pppppppuVar10 = (undefined8 *******)FUN_1400285e0(uVar16 + 1);

          local_288 = pppppppuVar10;

        }

        local_278 = uVar17;

        uStack_270 = uVar16;

        FUN_1402f8e20(pppppppuVar10,puVar11);

        *(undefined8 *)((longlong)pppppppuVar10 + lVar14) = s_files_txt_14030e078._0_8_;

        *(char *)((longlong)pppppppuVar10 + lVar14 + 8) = s_files_txt_14030e078[8];

        *(undefined1 *)((longlong)pppppppuVar10 + uVar17) = 0;

        pppppppuVar10 = &local_288;

        if (0xf < uStack_270) {

          pppppppuVar10 = (undefined8 *******)local_288;

        }

        lVar14 = FUN_1402ce0f8(pppppppuVar10,&DAT_14030e070);

        if (0xf < uStack_270) {

          if ((0xfff < uStack_270 + 1) &&

             (0x1f < (ulonglong)((longlong)local_288 + (-8 - (longlong)local_288[-1])))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

          FUN_1402c7088();

        }

        lVar2 = DAT_1403f3370;

        local_288 = (undefined8 ******)((ulonglong)local_288 & 0xffffffffffffff00);

        local_278 = _DAT_14039caa0;

        uStack_270 = _UNK_14039caa8;

        lVar12 = DAT_1403f3368;

        if (lVar14 != 0) {

          for (; lVar12 != lVar2; lVar12 = lVar12 + 0x20) {

            FUN_1400279c0(local_258,lVar12);

            pppppppuVar10 = local_258;

            if (0xf < local_240) {

              pppppppuVar10 = (undefined8 *******)local_258[0];

            }

            FUN_1402da324(pppppppuVar10,lVar14);

            FUN_1402da324(&DAT_14039bd10,lVar14);

            if (0xf < local_240) {

              if ((0xfff < local_240 + 1) &&

                 (0x1f < (ulonglong)((longlong)local_258[0] + (-8 - (longlong)local_258[0][-1])))) {

                    /* WARNING: Subroutine does not return */

                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

              }

              FUN_1402c7088();

            }

          }

        }

        FUN_1402ce288(lVar14);

      }

      DAT_1403da604 = 0;

      do {

        if (DAT_1403f3350 != '\0') {

          FUN_14009dd90();

          FUN_1400777c0();

          if (DAT_1403f3354 != '\0') {

            SteamAPI_Shutdown();

          }

          FUN_14008cf70();

          SDL_Quit();

          return 0;

        }

        lVar14 = SDL_GetTicksNS();

        if (DAT_1403f3354 != '\0') {

          SteamAPI_RunCallbacks();

        }

        cVar4 = SDL_PollEvent(local_238);

        while (cVar4 != '\0') {

          FUN_1400c5180(lVar9,local_238);

          cVar4 = SDL_PollEvent(local_238);

        }

        DAT_1403f3353 = 0;

        if ((DAT_1403f3354 == '\0') || (DAT_1403da698 == '\0')) {

          if ((DAT_1403f3351 != '\0') || (DAT_1403d952b != '\0')) {

            FUN_14008cc80();

            goto LAB_1400c4019;

          }

LAB_1400c4022:

          if (DAT_1403d952a != '\0') goto LAB_1400c402f;

        }

        else {

LAB_1400c4019:

          if (DAT_1403f3351 == '\0') goto LAB_1400c4022;

LAB_1400c402f:

          SDL_RenderPresent(DAT_1403f3398);

          if (DAT_1403f3352 == '\0') {

            if (DAT_1403f3358 != 0) {

              if (DAT_1403d950c != '\0') {

                SDL_SetWindowFullscreen(lVar9,0);

                DAT_1403d950c = '\0';

              }

              for (; (local_290 <= DAT_1403f3358 || (local_28c <= DAT_1403f335c));

                  DAT_1403f335c = DAT_1403f335c + -0xb4) {

                DAT_1403f3358 = DAT_1403f3358 + -0x140;

              }

              SDL_GetWindowBordersSize(lVar9,&local_260,&local_268,&local_25c,&local_264);

              DAT_1403d9510 = DAT_1403d9510 + (DAT_1403d9518 / 2 - DAT_1403f3358 / 2);

              DAT_1403d9514 = DAT_1403d9514 + (DAT_1403d951c / 2 - DAT_1403f335c / 2);

              DAT_1403d9510 =

                   FUN_1400c5f50(DAT_1403d9510,local_268,

                                 ((local_290 - local_268) - local_264) - DAT_1403f3358);

              DAT_1403d9514 =

                   FUN_1400c5f50(DAT_1403d9514,local_260,

                                 ((local_28c - local_260) - local_25c) - DAT_1403f335c);

              SDL_SetWindowSize(lVar9,DAT_1403f3358,DAT_1403f335c);

              SDL_SetWindowPosition(lVar9,DAT_1403d9510,DAT_1403d9514);

              DAT_1403d9e60 = DAT_1403f3358;

              DAT_1403d9e64 = DAT_1403f335c;

              DAT_1403d9518 = DAT_1403f3358;

              DAT_1403d951c = DAT_1403f335c;

              DAT_1403f3358 = 0;

            }

          }

          else {

            DAT_1403f3352 = '\0';

            cVar4 = SDL_SetWindowFullscreen(lVar9,DAT_1403d950c == '\0');

            if (cVar4 != '\0') {

              DAT_1403d950c = DAT_1403d950c == '\0';

            }

          }

        }

        lVar12 = SDL_GetTicksNS();

        if ((ulonglong)(lVar12 - lVar14) < 0xeac027) {

          SDL_DelayNS(0xeac027 - (lVar12 - lVar14));

        }

      } while( true );

    }

  }

LAB_1400c4282:

                    /* WARNING: Subroutine does not return */

  FUN_140024130();

}




