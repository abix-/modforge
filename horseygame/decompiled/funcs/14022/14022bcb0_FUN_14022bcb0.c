// Address: 0x14022bcb0
// Ghidra name: FUN_14022bcb0
// ============ 0x14022bcb0 FUN_14022bcb0 (size=824) ============


undefined8 FUN_14022bcb0(undefined8 param_1,longlong param_2,longlong param_3,int param_4)



{

  longlong lVar1;

  longlong lVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  BOOL BVar6;

  uint uVar7;

  uint uVar8;

  HMENU pHVar9;

  int iVar10;

  HWND hWnd;

  int iVar11;

  HWND pHVar12;

  int local_res18 [2];

  int local_res20;

  int local_98;

  int local_94;

  int local_90 [2];

  LONG local_88;

  undefined4 local_84;

  undefined8 local_80;

  undefined8 uStack_78;

  undefined4 local_70;

  undefined4 local_6c;

  HWND local_68;

  tagMONITORINFO local_60;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  pHVar12 = (HWND)0x0;

  lVar2 = *(longlong *)(param_3 + 0x80);

  hWnd = pHVar12;

  if (lVar1 != 0) {

    hWnd = *(HWND *)(lVar1 + 8);

  }

  bVar4 = false;

  if (((*(byte *)(param_2 + 0x48) & 1) != 0) || (param_4 != 0)) {

    local_res20 = param_4;

    cVar5 = FUN_140172540();

    if ((cVar5 == '\0') ||

       (local_68 = (HWND)0xffffffffffffffff, (*(uint *)(param_2 + 0x48) >> 0x10 & 1) == 0)) {

      local_68 = (HWND)0xfffffffffffffffe;

    }

    local_60.rcMonitor.top = 0;

    local_60.rcMonitor.right = 0;

    local_60.cbSize = 0x28;

    local_60.rcMonitor.left = 0;

    local_60.rcMonitor.bottom = 0;

    local_60.rcWork.left = 0;

    local_60.rcWork.top = 0;

    local_60.rcWork.right = 0;

    local_60.rcWork.bottom = 0;

    local_60.dwFlags = 0;

    BVar6 = GetMonitorInfoW(*(HMONITOR *)(lVar2 + 0x40),&local_60);

    if (BVar6 == 0) {

      FUN_14012e850("GetMonitorInfo failed");

      return 0;

    }

    FUN_1401cda90(param_2,0x218 - (uint)(param_4 != 0),0,0);

    uVar7 = GetWindowLongW(hWnd,-0x10);

    uVar8 = FUN_140229ea0(param_2);

    uVar8 = uVar8 | uVar7 & 0x7f30ffff;

    local_88 = GetWindowLongW(hWnd,-0x14);

    if (local_res20 == 0) {

      FUN_14022cb80(param_1,hWnd,0);

      FUN_14022c870(param_1,hWnd,0xffffffff);

      if ((*(char *)(lVar1 + 0x69) == '\0') || (*(char *)(lVar1 + 0x6a) != '\0')) {

        bVar3 = false;

      }

      else {

        bVar3 = true;

        bVar4 = true;

        *(undefined1 *)(lVar1 + 0x6c) = 1;

      }

      if ((uVar8 >> 0x1e & 1) == 0) {

        pHVar9 = GetMenu(hWnd);

        pHVar12 = (HWND)(ulonglong)(pHVar9 != (HMENU)0x0);

      }

      FUN_14022a9d0(param_2,uVar8,local_88,pHVar12,&local_98,local_res18,&local_94,local_90,2);

      *(undefined1 *)(lVar1 + 0x69) = 0;

      if (bVar3) {

        local_70 = *(undefined4 *)(param_2 + 0x6c);

        local_6c = *(undefined4 *)(param_2 + 0x70);

        local_88 = *(LONG *)(param_2 + 0x7c);

        local_84 = *(undefined4 *)(param_2 + 0x80);

        iVar10 = FUN_14016d3d0(&local_88);

        iVar11 = FUN_14016d3d0(&local_70);

        if (iVar10 != iVar11) {

          local_80 = 0;

          uStack_78 = 0;

          FUN_14016d6c0(iVar11,&local_80);

          local_98 = (int)local_80;

          if (local_94 < (int)uStack_78) {

            local_98 = ((int)uStack_78 - local_94) / 2 + (int)local_80;

          }

          if (local_90[0] < uStack_78._4_4_) {

            local_res18[0] = (uStack_78._4_4_ - local_90[0]) / 2 + local_80._4_4_;

          }

          else {

            local_res18[0] = local_80._4_4_;

          }

        }

      }

    }

    else {

      iVar11 = local_60.rcMonitor.right - local_60.rcMonitor.left;

      iVar10 = local_60.rcMonitor.bottom - local_60.rcMonitor.top;

      local_98 = local_60.rcMonitor.left;

      local_res18[0] = local_60.rcMonitor.top;

      if ((uVar8 >> 0x18 & 1) != 0) {

        *(undefined1 *)(lVar1 + 0x69) = 1;

        uVar8 = uVar8 & 0xfeffffff;

      }

      FUN_14022cb80(param_1,hWnd,1);

      FUN_14022c870(param_1,hWnd,0xfffffffe);

      local_94 = iVar11;

      local_90[0] = iVar10;

    }

    SetWindowLongW(hWnd,-0x10,uVar8);

    *(undefined1 *)(lVar1 + 99) = 1;

    SetWindowPos(hWnd,local_68,local_98,local_res18[0],local_94,local_90[0],

                 *(uint *)(lVar1 + 0xd0) | 0x10);

    *(undefined1 *)(lVar1 + 99) = 0;

    *(undefined1 *)(lVar1 + 0x6c) = 0;

    if (bVar4) {

      FUN_14022b770(param_1,param_2);

    }

    if ((local_res20 == 0) && (*(longlong *)(lVar1 + 0x38) != 0)) {

      SendMessageW(hWnd,0x80,0,0);

      SendMessageW(hWnd,0x80,0,*(LPARAM *)(lVar1 + 0x38));

    }

  }

  return 1;

}




