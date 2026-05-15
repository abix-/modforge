// Address: 0x14022afa0
// Ghidra name: FUN_14022afa0
// ============ 0x14022afa0 FUN_14022afa0 (size=994) ============


undefined8 FUN_14022afa0(longlong param_1,longlong param_2,undefined4 param_3)



{

  longlong lVar1;

  char cVar2;

  uint uVar3;

  DWORD dwExStyle;

  int iPixelFormat;

  BOOL BVar4;

  undefined8 uVar5;

  HWND hWnd;

  HRGN ho;

  HWND pHVar6;

  HDC hdc;

  int local_res8 [2];

  int local_res20 [2];

  undefined8 in_stack_ffffffffffffff78;

  undefined4 uVar7;

  int local_68;

  int local_64;

  undefined1 local_60 [8];

  undefined8 uStack_58;

  ulonglong local_50;

  undefined8 uStack_48;

  undefined8 local_40;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x680);

  uVar5 = FUN_140174d30(param_3,"sdl2-compat.external_window",0);

  hWnd = (HWND)FUN_140174d30(param_3,"SDL.window.create.win32.hwnd",uVar5);

  pHVar6 = (HWND)0x0;

  if (hWnd == (HWND)0x0) {

    if ((*(ulonglong *)(param_2 + 0x48) >> 0x11 & 1) == 0) {

      if (*(longlong *)(param_2 + 0x1a8) != 0) {

        pHVar6 = *(HWND *)(*(longlong *)(*(longlong *)(param_2 + 0x1a8) + 0x188) + 8);

      }

    }

    else {

      uVar7 = 0;

      pHVar6 = CreateWindowExW(0,DAT_1403fcb80,L"",0x6000000,0,0,0x20,0x20,(HWND)0x0,(HMENU)0x0,

                               DAT_1403fcb90,(LPVOID)0x0);

    }

    uVar3 = FUN_140229ea0(param_2);

    dwExStyle = FUN_140229f50(param_2);

    FUN_14022ade0(param_2,0);

    FUN_14022a9d0(param_2,uVar3 | 0x6000000,dwExStyle,0,&local_64,&local_68,local_res20,local_res8,

                  CONCAT44(uVar7,2));

    hWnd = CreateWindowExW(dwExStyle,DAT_1403fcb80,L"",uVar3 | 0x6000000,local_64,local_68,

                           local_res20[0],local_res8[0],pHVar6,(HMENU)0x0,DAT_1403fcb90,(LPVOID)0x0)

    ;

    if (hWnd == (HWND)0x0) {

      uVar5 = FUN_1401a9ed0("Couldn\'t create window");

      return uVar5;

    }

    FUN_1401a9fe0(hWnd);

    FUN_14018d5d0(param_1,hWnd);

    cVar2 = FUN_14022a1e0(param_1,param_2,hWnd,pHVar6);

    if (cVar2 == '\0') {

      DestroyWindow(hWnd);

      if (pHVar6 == (HWND)0x0) {

        return 0;

      }

      DestroyWindow(pHVar6);

      return 0;

    }

    FUN_140225b30(param_1,param_2);

    SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,0x237);

    if ((*(ulonglong *)(param_2 + 0x48) & 0x40) != 0) {

      *(ulonglong *)(param_2 + 0x48) = *(ulonglong *)(param_2 + 0x48) & 0xfffffffffffffff7;

      ShowWindow(hWnd,7);

    }

  }

  else {

    *(ulonglong *)(param_2 + 0x48) = *(ulonglong *)(param_2 + 0x48) | 0x800;

    cVar2 = FUN_14022a1e0(param_1,param_2,hWnd,0);

    if (cVar2 == '\0') {

      return 0;

    }

  }

  if (((*(uint *)(param_2 + 0x48) >> 0x1e & 1) != 0) && (*(longlong *)(lVar1 + 0x58) != 0)) {

    ho = CreateRectRgn(-1,-1,0,0);

    local_60._0_2_ = 3;

    local_60._2_2_ = 0;

    local_60._4_4_ = 1;

    local_50 = local_50 & 0xffffffff00000000;

    uStack_58 = ho;

    (**(code **)(lVar1 + 0x58))(hWnd,local_60);

    DeleteObject(ho);

  }

  pHVar6 = (HWND)FUN_140174d30(param_3,"SDL.window.create.win32.pixel_format_hwnd",0);

  if (pHVar6 == (HWND)0x0) {

    if ((*(byte *)(param_2 + 0x48) & 2) != 0) {

      if (((*(int *)(param_1 + 0x3f0) == 4) ||

          (cVar2 = FUN_140142940("SDL_VIDEO_FORCE_EGL",0), cVar2 != '\0')) &&

         ((*(longlong *)(param_1 + 0x688) == 0 || (cVar2 = FUN_140223940(param_1), cVar2 != '\0'))))

      {

        cVar2 = FUN_140228d80(param_1,param_2);

      }

      else {

        cVar2 = FUN_140223580(param_1,param_2);

      }

      if (cVar2 == '\0') {

        thunk_FUN_140229bb0(param_1,param_2);

        return 0;

      }

    }

  }

  else {

    hdc = GetDC(pHVar6);

    iPixelFormat = GetPixelFormat(hdc);

    local_40._0_4_ = 0;

    local_40._4_4_ = 0;

    local_60._0_2_ = 0;

    local_60._2_2_ = 0;

    local_60._4_4_ = 0;

    uStack_58._0_1_ = '\0';

    uStack_58._1_1_ = '\0';

    uStack_58._2_1_ = '\0';

    uStack_58._3_1_ = '\0';

    uStack_58._4_1_ = '\0';

    uStack_58._5_1_ = '\0';

    uStack_58._6_1_ = '\0';

    uStack_58._7_1_ = '\0';

    local_50._0_1_ = '\0';

    local_50._1_1_ = '\0';

    local_50._2_1_ = '\0';

    local_50._3_1_ = '\0';

    local_50._4_1_ = '\0';

    local_50._5_1_ = '\0';

    local_50._6_1_ = '\0';

    local_50._7_1_ = '\0';

    uStack_48._0_1_ = '\0';

    uStack_48._1_1_ = '\0';

    uStack_48._2_1_ = '\0';

    uStack_48._3_1_ = '\0';

    uStack_48._4_4_ = 0;

    DescribePixelFormat(hdc,iPixelFormat,0x28,(LPPIXELFORMATDESCRIPTOR)local_60);

    ReleaseDC(pHVar6,hdc);

    BVar4 = SetPixelFormat(*(HDC *)(*(longlong *)(param_2 + 0x188) + 0x18),iPixelFormat,

                           (PIXELFORMATDESCRIPTOR *)local_60);

    if (BVar4 == 0) {

      thunk_FUN_140229bb0(param_1,param_2);

      uVar5 = FUN_1401a9ed0("SetPixelFormat()");

      return uVar5;

    }

  }

  return 1;

}




