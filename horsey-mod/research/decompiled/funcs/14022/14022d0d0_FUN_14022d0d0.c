// Address: 0x14022d0d0
// Ghidra name: FUN_14022d0d0
// ============ 0x14022d0d0 FUN_14022d0d0 (size=578) ============


undefined8 FUN_14022d0d0(char *param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  BOOL BVar5;

  DWORD DVar6;

  longlong lVar7;

  HWND hWnd;

  HANDLE hThread;

  longlong lVar8;

  longlong lVar9;

  undefined8 uVar10;

  UINT uiNumDevices;

  bool bVar11;

  RAWINPUTDEVICE local_48;

  ulonglong local_38;

  undefined8 uStack_30;

  

  lVar7 = FUN_14016dcf0();

  FUN_1401800c0("SDLRawInput");

  hWnd = CreateWindowExW(0,L"Message",(LPCWSTR)0x0,0,0,0,0,0,(HWND)0xfffffffffffffffd,(HMENU)0x0,

                         (HINSTANCE)0x0,(LPVOID)0x0);

  if (hWnd != (HWND)0x0) {

    uVar2 = *(uint *)(param_1 + 4);

    local_48.usUsagePage = 0;

    local_48.usUsage = 0;

    local_48.dwFlags = 0;

    local_48.hwndTarget = (HWND)0x0;

    local_38 = 0;

    uStack_30 = 0;

    bVar11 = (uVar2 & 1) != 0;

    if (bVar11) {

      local_48.usUsagePage = 1;

      local_48.usUsage = 2;

      local_48.dwFlags = 0;

      local_48.hwndTarget = hWnd;

    }

    uiNumDevices = (UINT)bVar11;

    if ((uVar2 & 2) != 0) {

      uVar4 = (uVar2 & 4) << 7;

      (&local_48)[bVar11].usUsagePage = 1;

      (&local_48)[bVar11].usUsage = 6;

      (&local_48)[bVar11].dwFlags = uVar4;

      if ((uVar2 & 8) != 0) {

        (&local_48)[bVar11].dwFlags = uVar4 | 0x100;

      }

      (&local_48)[bVar11].hwndTarget = hWnd;

      uiNumDevices = bVar11 + 1;

    }

    BVar5 = RegisterRawInputDevices(&local_48,uiNumDevices,0x10);

    if (BVar5 == 0) {

      DestroyWindow(hWnd);

    }

    else {

      hThread = GetCurrentThread();

      SetThreadPriority(hThread,0xf);

      SetEvent(*(HANDLE *)(param_1 + 8));

      lVar8 = FUN_140149300();

      cVar1 = *param_1;

      while ((cVar1 == '\0' &&

             ((DVar6 = GetQueueStatus(0x400), (DVar6 & 0x4000000) != 0 ||

              (DVar6 = MsgWaitForMultipleObjects(1,(HANDLE *)(param_1 + 0x10),0,0xffffffff,0x400),

              DVar6 == 1))))) {

        lVar9 = FUN_140149300();

        if ((ulonglong)(lVar9 - lVar8) < 0x1e848) {

          lVar9 = *(longlong *)(*(longlong *)(lVar7 + 0x680) + 0x118);

        }

        FUN_14018cfa0(lVar7,lVar9);

        lVar8 = FUN_140149300();

        cVar1 = *param_1;

      }

      iVar3 = *(int *)(*(longlong *)(lVar7 + 0x680) + 0x134);

      if (iVar3 != 0) {

        uVar10 = FUN_140183290();

        FUN_1401a8480(0,uVar10,iVar3);

        *(undefined4 *)(*(longlong *)(lVar7 + 0x680) + 0x134) = 0;

      }

      local_48._0_8_ = local_48._0_8_ | 0x100000000;

      local_38 = local_38 | 0x100000000;

      local_48.hwndTarget = (HWND)0x0;

      uStack_30 = 0;

      RegisterRawInputDevices(&local_48,uiNumDevices,0x10);

      DestroyWindow(hWnd);

    }

  }

  return 0;

}




