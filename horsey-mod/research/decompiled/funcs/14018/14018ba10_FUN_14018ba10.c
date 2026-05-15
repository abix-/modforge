// Address: 0x14018ba10
// Ghidra name: FUN_14018ba10
// ============ 0x14018ba10 FUN_14018ba10 (size=486) ============


undefined8 FUN_14018ba10(char *param_1,UINT param_2,HMODULE param_3)



{

  ushort uVar1;

  ATOM AVar2;

  ulonglong uVar3;

  size_t sVar4;

  char *pcVar5;

  undefined6 extraout_var;

  undefined8 uVar6;

  WNDCLASSEXW local_a8;

  undefined8 local_58;

  WNDPROC pWStack_50;

  int local_48;

  int iStack_44;

  HMODULE pHStack_40;

  HICON local_38;

  HCURSOR pHStack_30;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  if (DAT_1403fcbbc == 0) {

    pcVar5 = "SDL_app";

    if (param_1 != (char *)0x0) {

      pcVar5 = param_1;

    }

    sVar4 = strlen(pcVar5);

    DAT_1403fcb80 = (LPCWSTR)FUN_140197820("UTF-16LE",&DAT_14039c6f0,pcVar5,sVar4 + 1);

    DAT_1403fcb88 = 0x1020;

    if (param_1 != (char *)0x0) {

      DAT_1403fcb88 = param_2;

    }

    if (param_3 == (HMODULE)0x0) {

      param_3 = GetModuleHandleW((LPCWSTR)0x0);

    }

    local_a8.lpfnWndProc = FUN_14018da20;

    local_a8.cbClsExtra = 0;

    local_a8.cbWndExtra = 0;

    local_a8.hIcon = (HICON)0x0;

    local_a8.hCursor = (HCURSOR)0x0;

    local_a8.hbrBackground = (HBRUSH)0x0;

    local_a8.lpszMenuName = (LPCWSTR)0x0;

    local_a8.hIconSm = (HICON)0x0;

    local_a8.cbSize = 0x50;

    DAT_1403fcb90 = param_3;

    local_a8.style = DAT_1403fcb88;

    local_a8.hInstance = param_3;

    local_a8.lpszClassName = DAT_1403fcb80;

    pcVar5 = (char *)FUN_140142960("SDL_WINDOWS_INTRESOURCE_ICON");

    if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {

      EnumResourceNamesW(DAT_1403fcb90,(LPCWSTR)0xe,FUN_14018d660,(LONG_PTR)&local_a8);

    }

    else {

      uVar1 = thunk_FUN_1402d89dc(pcVar5);

      local_a8.hIcon = LoadIconW(DAT_1403fcb90,(LPCWSTR)(ulonglong)uVar1);

      pcVar5 = (char *)FUN_140142960("SDL_WINDOWS_INTRESOURCE_ICON_SMALL");

      if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {

        uVar1 = thunk_FUN_1402d89dc(pcVar5);

        local_a8.hIconSm = LoadIconW(DAT_1403fcb90,(LPCWSTR)(ulonglong)uVar1);

      }

    }

    AVar2 = RegisterClassExW(&local_a8);

    uVar3 = CONCAT62(extraout_var,AVar2);

    if (AVar2 == 0) {

      local_58 = CONCAT44(local_a8.style,local_a8.cbSize);

      pWStack_50 = local_a8.lpfnWndProc;

      local_38 = local_a8.hIcon;

      pHStack_30 = local_a8.hCursor;

      local_48 = local_a8.cbClsExtra;

      iStack_44 = local_a8.cbWndExtra;

      pHStack_40 = local_a8.hInstance;

      local_18 = local_a8.lpszClassName._0_4_;

      uStack_14 = local_a8.lpszClassName._4_4_;

      uStack_10 = local_a8.hIconSm._0_4_;

      uStack_c = local_a8.hIconSm._4_4_;

      local_28 = local_a8.hbrBackground._0_4_;

      uStack_24 = local_a8.hbrBackground._4_4_;

      uStack_20 = local_a8.lpszMenuName._0_4_;

      uStack_1c = local_a8.lpszMenuName._4_4_;

      FUN_14018c570(&local_58);

      uVar6 = FUN_14012e850("Couldn\'t register application class");

      return uVar6;

    }

    DAT_1403fcbbc = 1;

  }

  else {

    DAT_1403fcbbc = DAT_1403fcbbc + 1;

    uVar3 = (ulonglong)DAT_1403fcbbc;

  }

  return CONCAT71((int7)(uVar3 >> 8),1);

}




