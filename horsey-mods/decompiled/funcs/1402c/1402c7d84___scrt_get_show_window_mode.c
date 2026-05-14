// Address: 0x1402c7d84
// Ghidra name: __scrt_get_show_window_mode
// ============ 0x1402c7d84 __scrt_get_show_window_mode (size=58) ============


/* Library Function - Single Match

    __scrt_get_show_window_mode

   

   Library: Visual Studio 2019 Release */



WORD __scrt_get_show_window_mode(void)



{

  WORD WVar1;

  _STARTUPINFOW local_78;

  

  FUN_1402f94c0(&local_78,0,0x68);

  GetStartupInfoW(&local_78);

  WVar1 = 10;

  if (((byte)local_78.dwFlags & 1) != 0) {

    WVar1 = local_78.wShowWindow;

  }

  return WVar1;

}




