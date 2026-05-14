// Address: 0x14020f3e0
// Ghidra name: FUN_14020f3e0
// ============ 0x14020f3e0 FUN_14020f3e0 (size=172) ============


LRESULT FUN_14020f3e0(HWND param_1,UINT param_2,UINT_PTR param_3,longlong param_4)



{

  LRESULT LVar1;

  

  if (param_2 == 0x113) {

    if (1 < param_3 - 0x4b0) goto LAB_14020f452;

    KillTimer(param_1,param_3);

    FUN_14020f650();

  }

  else {

    if (param_2 != 0x219) {

LAB_14020f452:

      LVar1 = CallWindowProcW(FUN_14020b770,param_1,param_2,param_3,param_4);

      return LVar1;

    }

    if (((param_3 == 0x8000) || (param_3 == 0x8004)) && (*(int *)(param_4 + 4) == 5)) {

      SetTimer(param_1,0x4b0,300,(TIMERPROC)0x0);

      SetTimer(param_1,0x4b1,2000,(TIMERPROC)0x0);

      return 1;

    }

  }

  return 1;

}




