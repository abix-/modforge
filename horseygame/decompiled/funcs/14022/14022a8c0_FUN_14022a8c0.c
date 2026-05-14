// Address: 0x14022a8c0
// Ghidra name: FUN_14022a8c0
// ============ 0x14022a8c0 FUN_14022a8c0 (size=272) ============


undefined8 FUN_14022a8c0(HWND param_1,LPRECT param_2,int param_3)



{

  char cVar1;

  uint dwStyle;

  DWORD dwExStyle;

  int iVar2;

  BOOL BVar3;

  longlong lVar4;

  HMENU pHVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  

  lVar4 = FUN_14016dcf0();

  uVar7 = 0;

  uVar8 = uVar7;

  if (lVar4 != 0) {

    uVar8 = *(ulonglong *)(lVar4 + 0x680);

  }

  dwStyle = GetWindowLongW(param_1,-0x10);

  dwExStyle = GetWindowLongW(param_1,-0x14);

  if ((dwStyle >> 0x1e & 1) == 0) {

    pHVar5 = GetMenu(param_1);

    uVar7 = (ulonglong)(pHVar5 != (HMENU)0x0);

  }

  cVar1 = FUN_140181590(lVar4);

  if (cVar1 == '\0') {

    BVar3 = AdjustWindowRectEx(param_2,dwStyle,(BOOL)uVar7,dwExStyle);

    if (BVar3 == 0) {

      uVar6 = FUN_1401a9ed0("AdjustWindowRectEx()");

      return uVar6;

    }

  }

  else {

    if (param_3 == 0) {

      if (*(code **)(uVar8 + 0xc0) == (code *)0x0) {

        param_3 = 0x60;

      }

      else {

        param_3 = (**(code **)(uVar8 + 0xc0))(param_1);

      }

    }

    iVar2 = (**(code **)(uVar8 + 0xb8))(param_2,dwStyle,uVar7,dwExStyle,param_3);

    if (iVar2 == 0) {

      uVar6 = FUN_1401a9ed0("AdjustWindowRectExForDpi()");

      return uVar6;

    }

  }

  return 1;

}




