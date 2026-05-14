// Address: 0x1401817c0
// Ghidra name: FUN_1401817c0
// ============ 0x1401817c0 FUN_1401817c0 (size=283) ============


void FUN_1401817c0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  FUN_140142b00("SDL_WINDOWS_RAW_KEYBOARD",FUN_1401811b0,param_1);

  FUN_140142b00("SDL_WINDOWS_RAW_KEYBOARD_EXCLUDE_HOTKEYS",FUN_140181210,param_1);

  FUN_140142b00("SDL_WINDOWS_RAW_KEYBOARD_INPUTSINK",FUN_1401811e0,param_1);

  FUN_140142b00("SDL_WINDOWS_ENABLE_MESSAGELOOP",FUN_140181190,0);

  FUN_140142b00("SDL_WINDOWS_ENABLE_MENU_MNEMONICS",FUN_140181170,0);

  FUN_140142b00("SDL_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN",FUN_140181150,0);

  FUN_14022d520(param_1,0);

  FUN_14022d440(param_1,0);

  FUN_1402220f0(param_1);

  _guard_check_icall(param_1);

  FUN_140220870();

  FUN_140225980(param_1);

  FUN_140228430(param_1);

  if (*(longlong **)(lVar1 + 0x390) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0x390) + 0x10))();

    *(undefined8 *)(lVar1 + 0x390) = 0;

  }

  if (*(char *)(lVar1 + 5) != '\0') {

    OleUninitialize();

    *(undefined1 *)(lVar1 + 5) = 0;

  }

  if (*(char *)(lVar1 + 4) != '\0') {

    CoUninitialize();

    *(undefined1 *)(lVar1 + 4) = 0;

  }

  return;

}




