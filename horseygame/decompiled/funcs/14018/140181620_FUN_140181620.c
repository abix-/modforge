// Address: 0x140181620
// Ghidra name: FUN_140181620
// ============ 0x140181620 FUN_140181620 (size=408) ============


undefined8 FUN_140181620(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  undefined1 uVar4;

  int iVar5;

  UINT UVar6;

  undefined8 uVar7;

  undefined4 extraout_var;

  char *pcVar8;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  iVar5 = FUN_1401a9610();

  if (iVar5 < 0) {

    pcVar8 = "CoInitialize() failed: 0x%.8x, using fallback drag-n-drop functionality";

  }

  else {

    *(undefined1 *)(lVar1 + 4) = 1;

    iVar5 = OleInitialize((LPVOID)0x0);

    if (-1 < iVar5) {

      *(undefined1 *)(lVar1 + 5) = 1;

      goto LAB_140181670;

    }

    pcVar8 = "OleInitialize() failed: 0x%.8x, using fallback drag-n-drop functionality";

  }

  FUN_14012e0e0(5,pcVar8,iVar5);

LAB_140181670:

  FUN_1401814d0(param_1);

  cVar3 = FUN_140142940("SDL_WINDOWS_GAMEINPUT",0);

  if (cVar3 != '\0') {

    FUN_140221fc0(param_1);

  }

  uVar7 = FUN_140226f00(param_1);

  if ((char)uVar7 == '\0') {

    return uVar7;

  }

  lVar2 = *(longlong *)(param_1 + 0x680);

  uVar4 = FUN_140142940("SDL_WINDOWS_DETECT_DEVICE_HOTPLUG",1);

  *(undefined1 *)(lVar2 + 0xf9) = uVar4;

  FUN_1402258b0(param_1);

  FUN_140228380(param_1);

  FUN_1402205c0();

  FUN_1401427d0("SDL_WINDOWS_RAW_KEYBOARD",FUN_1401811b0,param_1);

  FUN_1401427d0("SDL_WINDOWS_RAW_KEYBOARD_EXCLUDE_HOTKEYS",FUN_140181210,param_1);

  FUN_1401427d0("SDL_WINDOWS_RAW_KEYBOARD_INPUTSINK",FUN_1401811e0,param_1);

  FUN_1401427d0("SDL_WINDOWS_ENABLE_MESSAGELOOP",FUN_140181190,0);

  FUN_1401427d0("SDL_WINDOWS_ENABLE_MENU_MNEMONICS",FUN_140181170,0);

  FUN_1401427d0("SDL_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN",FUN_140181150,0);

  UVar6 = RegisterWindowMessageA("_SDL_WAKEUP");

  *(UINT *)(lVar1 + 0x388) = UVar6;

  iVar5 = FUN_1401a9910();

  if (iVar5 != 0) {

    UVar6 = RegisterWindowMessageA("TaskbarButtonCreated");

    *(UINT *)(lVar1 + 0x38c) = UVar6;

    return CONCAT71((int7)(CONCAT44(extraout_var,UVar6) >> 8),1);

  }

  *(undefined4 *)(lVar1 + 0x38c) = 0;

  return 1;

}




