// Address: 0x140180570
// Ghidra name: FUN_140180570
// ============ 0x140180570 FUN_140180570 (size=1958) ============


longlong FUN_140180570(void)



{

  char cVar1;

  undefined4 uVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 uVar6;

  code *pcVar7;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  

  FUN_14018ba10(0,0,0);

  lVar3 = FUN_1401841a0(1,0x6a8);

  if (lVar3 != 0) {

    lVar4 = FUN_1401841a0(1,0x398);

    if (lVar4 != 0) {

      *(longlong *)(lVar3 + 0x680) = lVar4;

      uVar2 = FUN_140181430();

      *(undefined4 *)(lVar3 + 0x398) = uVar2;

      lVar5 = FUN_1401885b0("USER32.DLL");

      *(longlong *)(lVar4 + 0x10) = lVar5;

      if (lVar5 == 0) {

        FUN_14012e710();

      }

      else {

        uVar6 = FUN_140188550(lVar5,"CloseTouchInputHandle");

        *(undefined8 *)(lVar4 + 0x30) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetTouchInputInfo");

        *(undefined8 *)(lVar4 + 0x38) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"RegisterTouchWindow");

        *(undefined8 *)(lVar4 + 0x40) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"SetProcessDPIAware");

        *(undefined8 *)(lVar4 + 0x88) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"SetProcessDpiAwarenessContext");

        *(undefined8 *)(lVar4 + 0x90) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"SetThreadDpiAwarenessContext");

        *(undefined8 *)(lVar4 + 0x98) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetThreadDpiAwarenessContext");

        *(undefined8 *)(lVar4 + 0xa0) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetAwarenessFromDpiAwarenessContext");

        *(undefined8 *)(lVar4 + 0xa8) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"EnableNonClientDpiScaling");

        *(undefined8 *)(lVar4 + 0xb0) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"AdjustWindowRectExForDpi");

        *(undefined8 *)(lVar4 + 0xb8) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetDpiForWindow");

        *(undefined8 *)(lVar4 + 0xc0) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"AreDpiAwarenessContextsEqual");

        *(undefined8 *)(lVar4 + 200) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"IsValidDpiAwarenessContext");

        *(undefined8 *)(lVar4 + 0xd0) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetDisplayConfigBufferSizes");

        *(undefined8 *)(lVar4 + 0x18) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"QueryDisplayConfig");

        *(undefined8 *)(lVar4 + 0x20) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"DisplayConfigGetDeviceInfo");

        *(undefined8 *)(lVar4 + 0x28) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetPointerType");

        *(undefined8 *)(lVar4 + 0x68) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetPointerPenInfo");

        *(undefined8 *)(lVar4 + 0x70) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x10),"GetPointerDeviceRects");

        *(undefined8 *)(lVar4 + 0x78) = uVar6;

      }

      lVar5 = FUN_1401885b0("SHCORE.DLL");

      *(longlong *)(lVar4 + 0x80) = lVar5;

      if (lVar5 == 0) {

        FUN_14012e710();

      }

      else {

        uVar6 = FUN_140188550(lVar5,"GetDpiForMonitor");

        *(undefined8 *)(lVar4 + 0xd8) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x80),"SetProcessDpiAwareness");

        *(undefined8 *)(lVar4 + 0xe0) = uVar6;

      }

      lVar5 = FUN_1401885b0("DWMAPI.DLL");

      *(longlong *)(lVar4 + 0x48) = lVar5;

      if (lVar5 == 0) {

        FUN_14012e710();

      }

      else {

        uVar6 = FUN_140188550(lVar5,"DwmFlush");

        *(undefined8 *)(lVar4 + 0x50) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x48),"DwmEnableBlurBehindWindow");

        *(undefined8 *)(lVar4 + 0x58) = uVar6;

        uVar6 = FUN_140188550(*(undefined8 *)(lVar4 + 0x48),"DwmSetWindowAttribute");

        *(undefined8 *)(lVar4 + 0x60) = uVar6;

      }

      lVar5 = FUN_1401885b0("DXGI.DLL");

      *(longlong *)(lVar4 + 0xe8) = lVar5;

      if (lVar5 != 0) {

        pcVar7 = (code *)FUN_140188550(lVar5,"CreateDXGIFactory");

        if (pcVar7 != (code *)0x0) {

          local_18 = 0x7b7166ec;

          local_14 = 0x44ae21c7;

          local_10 = 0xaec91ab2;

          local_c = 0x69e31a32;

          (*pcVar7)(&local_18,lVar4 + 0xf0);

        }

      }

      *(code **)(lVar3 + 8) = FUN_140181620;

      *(code **)(lVar3 + 0x10) = FUN_1401817c0;

      *(code **)(lVar3 + 0x20) = FUN_140226f30;

      *(code **)(lVar3 + 0x28) = FUN_1402262e0;

      *(code **)(lVar3 + 0x30) = FUN_1402268d0;

      *(code **)(lVar3 + 0x38) = FUN_140226500;

      *(code **)(lVar3 + 0x40) = FUN_140227060;

      *(code **)(lVar3 + 0x250) = FUN_14018d180;

      *(code **)(lVar3 + 0x240) = FUN_14018d9c0;

      *(undefined1 **)(lVar3 + 0x248) = &LAB_14018d680;

      *(code **)(lVar3 + 600) = FUN_1401815e0;

      *(code **)(lVar3 + 0x48) = FUN_14022afa0;

      *(code **)(lVar3 + 0x50) = FUN_14022c5e0;

      *(code **)(lVar3 + 0x58) = FUN_14022bff0;

      *(code **)(lVar3 + 0x60) = FUN_14022c3b0;

      *(undefined1 **)(lVar3 + 0x68) = &LAB_14022c5a0;

      *(code **)(lVar3 + 0x88) = FUN_14022b430;

      *(code **)(lVar3 + 0x98) = FUN_14022b5f0;

      *(code **)(lVar3 + 0xa0) = FUN_14022c260;

      *(code **)(lVar3 + 0xb8) = FUN_14022c640;

      *(code **)(lVar3 + 0xc0) = FUN_14022b700;

      *(code **)(lVar3 + 200) = FUN_14022b8d0;

      *(code **)(lVar3 + 0xd0) = FUN_14022b770;

      *(undefined1 **)(lVar3 + 0xd8) = &LAB_14022b870;

      *(code **)(lVar3 + 0xe0) = FUN_14022ba80;

      *(code **)(lVar3 + 0xe8) = FUN_14022bb30;

      *(code **)(lVar3 + 0xf0) = FUN_14022c540;

      *(code **)(lVar3 + 0xf8) = FUN_14022bb20;

      *(code **)(lVar3 + 0x100) = FUN_14022bcb0;

      *(code **)(lVar3 + 0xa8) = FUN_14022c340;

      *(code **)(lVar3 + 0xb0) = FUN_14022c1f0;

      *(code **)(lVar3 + 0x108) = FUN_14022b550;

      *(code **)(lVar3 + 0x118) = FUN_14022c240;

      *(code **)(lVar3 + 0x120) = FUN_14022c240;

      *(code **)(lVar3 + 0x128) = FUN_14022c1c0;

      *(code **)(lVar3 + 0x130) = thunk_FUN_140229bb0;

      *(code **)(lVar3 + 0x138) = FUN_14022ccc0;

      *(code **)(lVar3 + 0x150) = FUN_14022cfc0;

      *(code **)(lVar3 + 0x158) = FUN_14022cf70;

      *(undefined1 **)(lVar3 + 0x160) = &LAB_14022b890;

      *(code **)(lVar3 + 0x2f8) = FUN_140018e60;

      *(undefined8 *)(lVar3 + 0x1c8) = 0;

      *(code **)(lVar3 + 0x300) = FUN_14022a680;

      *(code **)(lVar3 + 0x170) = FUN_14022b3a0;

      *(code **)(lVar3 + 0x178) = FUN_14022ac50;

      *(code **)(lVar3 + 0x308) = FUN_14022c7a0;

      *(code **)(lVar3 + 0x180) = FUN_14022bbc0;

      *(code **)(lVar3 + 0x168) = FUN_140223b20;

      *(code **)(lVar3 + 0x1a0) = FUN_140223210;

      *(code **)(lVar3 + 0x1a8) = FUN_140222e00;

      *(code **)(lVar3 + 0x1b0) = FUN_140223900;

      *(code **)(lVar3 + 0x1b8) = FUN_140222a60;

      *(code **)(lVar3 + 0x1c0) = FUN_140223390;

      *(code **)(lVar3 + 0x1d0) = FUN_140223420;

      *(code **)(lVar3 + 0x1d8) = FUN_140222e50;

      *(code **)(lVar3 + 0x1e0) = FUN_1402238d0;

      *(code **)(lVar3 + 0x1e8) = FUN_140222de0;

      cVar1 = FUN_140142940("SDL_VIDEO_FORCE_EGL",0);

      if (cVar1 != '\0') {

        *(code **)(lVar3 + 0x1a0) = FUN_140228c50;

        *(code **)(lVar3 + 0x1a8) = FUN_140219030;

        *(code **)(lVar3 + 0x1b0) = FUN_14021a5f0;

        *(code **)(lVar3 + 0x1b8) = FUN_140228b00;

        *(code **)(lVar3 + 0x1c0) = FUN_140228d60;

        *(code **)(lVar3 + 0x1d0) = FUN_14021a4f0;

        *(undefined1 **)(lVar3 + 0x1d8) = &LAB_1402190e0;

        *(undefined1 **)(lVar3 + 0x1e0) = &LAB_140228e50;

        *(undefined1 **)(lVar3 + 0x1e8) = &LAB_140228c30;

        *(undefined1 **)(lVar3 + 0x1c8) = &LAB_140228c40;

      }

      *(undefined4 *)(lVar3 + 0x394) = 6;

      *(code **)(lVar3 + 0x1f8) = FUN_14022d7d0;

      *(code **)(lVar3 + 0x200) = FUN_14022d990;

      *(undefined1 **)(lVar3 + 0x208) = &LAB_14022d720;

      *(code **)(lVar3 + 0x210) = FUN_14022d620;

      *(undefined1 **)(lVar3 + 0x218) = &LAB_14022d700;

      *(code **)(lVar3 + 0x220) = FUN_14022d740;

      *(code **)(lVar3 + 0x260) = FUN_140225ac0;

      *(code **)(lVar3 + 0x268) = FUN_140225b30;

      *(code **)(lVar3 + 0x270) = FUN_140225c30;

      *(code **)(lVar3 + 0x278) = FUN_1402254c0;

      *(code **)(lVar3 + 0x2a8) = FUN_140221270;

      *(code **)(lVar3 + 0x2b0) = FUN_140220e80;

      *(code **)(lVar3 + 0x2b8) = FUN_140221160;

      *(code **)(lVar3 + 0x6a0) = FUN_140181390;

      return lVar3;

    }

  }

  FUN_14018bc10();

  FUN_1401841e0(lVar3);

  return 0;

}




