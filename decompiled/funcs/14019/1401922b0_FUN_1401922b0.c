// Address: 0x1401922b0
// Ghidra name: FUN_1401922b0
// ============ 0x1401922b0 FUN_1401922b0 (size=313) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401922b0(void)



{

  undefined4 local_28;

  undefined8 local_24;

  undefined4 local_1c;

  undefined4 uStack_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 local_c;

  

  DAT_1403fcbc0 = 1;

  DAT_1403fcbd0 = 0;

  DAT_1403fcbc4 = 1;

  DAT_1403fcbc8 = 0;

  DAT_1403fcbd8 = FUN_14017ffb0();

  _DAT_1403fcbe0 = 0;

  _DAT_1403fcbe8 = (undefined1 *)0x0;

  _DAT_1403fcbf0 = 0;

  DAT_1403fcbf8 = (HMODULE)0x0;

  _DAT_1403fcc00 = 0;

  uRam00000001403fcc08 = 0;

  _DAT_1403fcc10 = 0;

  uRam00000001403fcc18 = 0;

  DAT_1403fcc20 = (char *)0x0;

  uRam00000001403fcc28 = 0;

  DAT_1403fcbf8 = GetModuleHandleW((LPCWSTR)0x0);

  _DAT_1403fcbe0 = CONCAT44(DAT_1403fcbe0_4,0x50);

  DAT_1403fcc20 = "SDL_HIDAPI_DEVICE_DETECTION";

  _DAT_1403fcbe8 = &LAB_1401920f0;

  RegisterClassExA((WNDCLASSEXA *)&DAT_1403fcbe0);

  DAT_1403fcc30 =

       CreateWindowExA(0,"SDL_HIDAPI_DEVICE_DETECTION",(LPCSTR)0x0,0,0,0,0,0,

                       (HWND)0xfffffffffffffffd,(HMENU)0x0,(HINSTANCE)0x0,(LPVOID)0x0);

  local_24 = 5;

  local_c = 0;

  local_1c = _DAT_14033a348;

  uStack_18 = _UNK_14033a34c;

  uStack_14 = _UNK_14033a350;

  uStack_10 = _UNK_14033a354;

  local_28 = 0x20;

  DAT_1403fcc38 = RegisterDeviceNotificationW(DAT_1403fcc30,&local_28,4);

  DAT_1403fcbc8 = DAT_1403fcc38 != (HDEVNOTIFY)0x0;

  return;

}




