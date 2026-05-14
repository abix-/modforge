// Address: 0x14021f8d0
// Ghidra name: FUN_14021f8d0
// ============ 0x14021f8d0 FUN_14021f8d0 (size=433) ============


bool FUN_14021f8d0(HWND param_1,int param_2,ulonglong param_3,longlong param_4)



{

  char cVar1;

  LONG_PTR LVar2;

  HWND wParam;

  int local_18;

  undefined4 uStack_14;

  

  if (param_2 == 7) {

    LVar2 = GetWindowLongPtrW(param_1,-0x15);

    if (LVar2 != 0) {

      cVar1 = FUN_14021f890(LVar2,1,&local_18);

      return cVar1 == '\0';

    }

    param_3 = 0x34;

  }

  else if (param_2 == 0x110) {

    if (param_4 != 0) {

      SetWindowLongPtrW(param_1,-0x15,param_4);

      cVar1 = FUN_14021f890(param_4,1,&local_18);

      if (cVar1 == '\0') {

        SetFocus(param_1);

        return false;

      }

      wParam = GetDlgItem(param_1,local_18 + 100);

      if (wParam == (HWND)0x0) {

        EndDialog(param_1,0x35);

      }

      PostMessageW(param_1,0x28,(WPARAM)wParam,1);

      return false;

    }

    param_3 = 0x32;

  }

  else {

    if (param_2 != 0x111) {

      return false;

    }

    LVar2 = GetWindowLongPtrW(param_1,-0x15);

    if (LVar2 == 0) {

      param_3 = 0x33;

    }

    else if (param_3 == 1) {

      cVar1 = FUN_14021f890(LVar2,1,&local_18);

      if (cVar1 == '\0') {

        return true;

      }

      param_3 = CONCAT44(uStack_14,local_18) + 100;

    }

    else if (param_3 == 2) {

      cVar1 = FUN_14021f890(LVar2,2,&local_18);

      if (cVar1 == '\0') {

        param_3 = 0x14;

      }

      else {

        param_3 = CONCAT44(uStack_14,local_18) + 100;

      }

    }

    else {

      if (param_3 < 100) {

        return true;

      }

      if (*(int *)(LVar2 + 0x20) <= (int)param_3 + -100) {

        return true;

      }

    }

  }

  EndDialog(param_1,param_3);

  return true;

}




