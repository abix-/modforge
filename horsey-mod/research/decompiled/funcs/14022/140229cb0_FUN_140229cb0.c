// Address: 0x140229cb0
// Ghidra name: FUN_140229cb0
// ============ 0x140229cb0 FUN_140229cb0 (size=88) ============


undefined8 FUN_140229cb0(HWND param_1,LPRECT param_2)



{

  BOOL BVar1;

  

  BVar1 = GetClientRect(param_1,param_2);

  if (BVar1 != 0) {

    BVar1 = ClientToScreen(param_1,(LPPOINT)param_2);

    if (BVar1 != 0) {

      BVar1 = ClientToScreen(param_1,(LPPOINT)&param_2->right);

      if (BVar1 != 0) {

        return 1;

      }

    }

  }

  return 0;

}




