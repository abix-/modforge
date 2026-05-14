// Address: 0x140199470
// Ghidra name: FUN_140199470
// ============ 0x140199470 FUN_140199470 (size=159) ============


void FUN_140199470(undefined8 *param_1,undefined8 param_2)



{

  BOOL BVar1;

  LPWSTR pWVar2;

  MENUITEMINFOW local_58;

  

  if (param_1 != (undefined8 *)0x0) {

    FUN_14012ef10(param_1 + 2,0x1000,&DAT_14039bf30,param_2);

    pWVar2 = (LPWSTR)FUN_1401997c0(param_2);

    if (pWVar2 != (LPWSTR)0x0) {

      local_58.cbSize = 0x50;

      local_58.fMask = 0x40;

      local_58.dwTypeData = pWVar2;

      local_58.cch = FUN_14012fd40(pWVar2);

      BVar1 = SetMenuItemInfoW(*(HMENU *)*param_1,*(UINT *)(param_1 + 1),0,&local_58);

      if (BVar1 == 0) {

        FUN_14012e850("Couldn\'t update tray entry label");

      }

      FUN_1401841e0(pWVar2);

    }

  }

  return;

}




