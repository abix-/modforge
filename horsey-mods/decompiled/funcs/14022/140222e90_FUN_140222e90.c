// Address: 0x140222e90
// Ghidra name: FUN_140222e90
// ============ 0x140222e90 FUN_140222e90 (size=885) ============


void FUN_140222e90(longlong param_1)



{

  longlong lVar1;

  undefined1 *puVar2;

  char cVar3;

  undefined1 uVar4;

  int format;

  HWND hWnd;

  HDC hdc;

  longlong lVar5;

  code *pcVar6;

  undefined8 uVar7;

  undefined8 uVar8;

  PIXELFORMATDESCRIPTOR local_48;

  

  if (*(longlong *)(param_1 + 0x688) != 0) {

    uVar7 = 0;

    hWnd = CreateWindowExW(0,DAT_1403fcb80,DAT_1403fcb80,0x88000000,0,0,10,10,(HWND)0x0,(HMENU)0x0,

                           DAT_1403fcb90,(LPVOID)0x0);

    if (hWnd != (HWND)0x0) {

      FUN_14018d5d0(param_1,hWnd);

      hdc = GetDC(hWnd);

      FUN_140223490(param_1,&local_48);

      format = ChoosePixelFormat(hdc,&local_48);

      SetPixelFormat(hdc,format,&local_48);

      lVar5 = (**(code **)(*(longlong *)(param_1 + 0x688) + 0x18))(hdc);

      if (lVar5 != 0) {

        (**(code **)(*(longlong *)(param_1 + 0x688) + 0x28))(hdc,lVar5);

        pcVar6 = (code *)(**(code **)(*(longlong *)(param_1 + 0x688) + 0x10))

                                   ("wglGetExtensionsStringARB");

        if (pcVar6 != (code *)0x0) {

          uVar7 = (*pcVar6)(hdc);

        }

        **(undefined1 **)(param_1 + 0x688) = 0;

        cVar3 = FUN_140222590("WGL_ARB_pixel_format",uVar7);

        if (cVar3 != '\0') {

          lVar1 = *(longlong *)(param_1 + 0x688);

          uVar8 = FUN_140222e00(param_1,"wglChoosePixelFormatARB");

          *(undefined8 *)(lVar1 + 0x38) = uVar8;

          lVar1 = *(longlong *)(param_1 + 0x688);

          uVar8 = FUN_140222e00(param_1,"wglGetPixelFormatAttribivARB");

          *(undefined8 *)(lVar1 + 0x40) = uVar8;

          puVar2 = *(undefined1 **)(param_1 + 0x688);

          if ((*(longlong *)(puVar2 + 0x38) != 0) && (*(longlong *)(puVar2 + 0x40) != 0)) {

            *puVar2 = 1;

          }

        }

        *(undefined1 *)(*(longlong *)(param_1 + 0x688) + 1) = 0;

        cVar3 = FUN_140222590("WGL_EXT_swap_control",uVar7);

        if (cVar3 == '\0') {

          *(undefined8 *)(*(longlong *)(param_1 + 0x688) + 0x48) = 0;

          *(undefined8 *)(*(longlong *)(param_1 + 0x688) + 0x50) = 0;

        }

        else {

          lVar1 = *(longlong *)(param_1 + 0x688);

          uVar8 = FUN_140222e00(param_1,"wglSwapIntervalEXT");

          *(undefined8 *)(lVar1 + 0x48) = uVar8;

          lVar1 = *(longlong *)(param_1 + 0x688);

          uVar8 = FUN_140222e00(param_1,"wglGetSwapIntervalEXT");

          *(undefined8 *)(lVar1 + 0x50) = uVar8;

          cVar3 = FUN_140222590("WGL_EXT_swap_control_tear",uVar7);

          if (cVar3 != '\0') {

            *(undefined1 *)(*(longlong *)(param_1 + 0x688) + 1) = 1;

          }

        }

        lVar1 = *(longlong *)(param_1 + 0x688);

        uVar4 = FUN_140222590("WGL_EXT_create_context_es2_profile",uVar7);

        *(undefined1 *)(lVar1 + 6) = uVar4;

        lVar1 = *(longlong *)(param_1 + 0x688);

        if (*(char *)(lVar1 + 6) != '\0') {

          FUN_14016bfb0(lVar1 + 8,lVar1 + 0xc);

        }

        cVar3 = FUN_140222590("WGL_ARB_context_flush_control",uVar7);

        if (cVar3 != '\0') {

          *(undefined1 *)(*(longlong *)(param_1 + 0x688) + 2) = 1;

        }

        cVar3 = FUN_140222590("WGL_ARB_create_context_robustness",uVar7);

        if (cVar3 != '\0') {

          *(undefined1 *)(*(longlong *)(param_1 + 0x688) + 3) = 1;

        }

        cVar3 = FUN_140222590("WGL_ARB_create_context_no_error",uVar7);

        if (cVar3 != '\0') {

          *(undefined1 *)(*(longlong *)(param_1 + 0x688) + 4) = 1;

        }

        cVar3 = FUN_140222590("WGL_ARB_framebuffer_sRGB",uVar7);

        if ((cVar3 != '\0') ||

           (cVar3 = FUN_140222590("WGL_EXT_framebuffer_sRGB",uVar7), cVar3 != '\0')) {

          *(undefined1 *)(*(longlong *)(param_1 + 0x688) + 7) = 1;

        }

        lVar1 = *(longlong *)(param_1 + 0x688);

        uVar4 = FUN_140222590("WGL_ARB_pixel_format_float",uVar7);

        *(undefined1 *)(lVar1 + 5) = uVar4;

        (**(code **)(*(longlong *)(param_1 + 0x688) + 0x28))(hdc,0);

        (**(code **)(*(longlong *)(param_1 + 0x688) + 0x20))(lVar5);

        ReleaseDC(hWnd,hdc);

        DestroyWindow(hWnd);

        FUN_14018d5d0(param_1,hWnd);

      }

    }

  }

  return;

}




