// Address: 0x140199630
// Ghidra name: FUN_140199630
// ============ 0x140199630 FUN_140199630 (size=394) ============


LRESULT FUN_140199630(HWND param_1,UINT param_2,ulonglong param_3,longlong param_4)



{

  char cVar1;

  int iVar2;

  PNOTIFYICONDATAW lpData;

  LRESULT LVar3;

  longlong lVar4;

  

  lpData = (PNOTIFYICONDATAW)GetWindowLongPtrW(param_1,-0x15);

  if (lpData == (PNOTIFYICONDATAW)0x0) {

LAB_140199668:

    LVar3 = DefWindowProcW(param_1,param_2,param_3,param_4);

  }

  else {

    if (DAT_1403fcd30 == 0) {

      DAT_1403fcd30 = RegisterWindowMessageW(L"TaskbarCreated");

    }

    if (param_2 == DAT_1403fcd30) {

      Shell_NotifyIconW(0,lpData);

      Shell_NotifyIconW(4,lpData);

    }

    if (param_2 == 0x1a) {

      if ((param_3 == 0) && (param_4 != 0)) {

        iVar2 = FUN_14012fbc0(param_4,L"ImmersiveColorSet");

        if (iVar2 == 0) {

          FUN_1401a9fe0(param_1);

        }

      }

    }

    else if (param_2 == 0x111) {

      lVar4 = FUN_140199910(lpData,param_3 & 0xffff);

      if (lVar4 != 0) {

        if ((*(byte *)(lVar4 + 0x1010) & 2) != 0) {

          cVar1 = FUN_140198d00(lVar4);

          FUN_140199410(lVar4,cVar1 == '\0');

        }

        if (*(code **)(lVar4 + 0x1018) != (code *)0x0) {

          (**(code **)(lVar4 + 0x1018))(*(undefined8 *)(lVar4 + 0x1020),lVar4);

        }

      }

    }

    else {

      if (param_2 != 0x401) goto LAB_140199668;

      if (((short)param_4 == 0x7b) || ((short)param_4 == 0x202)) {

        SetForegroundWindow(param_1);

        if (*(undefined8 **)(lpData[5].szTip + 0x38) != (undefined8 *)0x0) {

          TrackPopupMenu((HMENU)**(undefined8 **)(lpData[5].szTip + 0x38),0x28,(int)(short)param_3,

                         (int)(short)(param_3 >> 0x10),0,param_1,(RECT *)0x0);

        }

      }

    }

    LVar3 = 0;

  }

  return LVar3;

}




