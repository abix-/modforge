// Address: 0x1400c4fa0
// Ghidra name: FUN_1400c4fa0
// ============ 0x1400c4fa0 FUN_1400c4fa0 (size=283) ============


undefined8 * FUN_1400c4fa0(undefined8 *param_1)



{

  BOOL BVar1;

  size_t sVar2;

  tagOFNA local_1b8;

  CHAR local_118 [272];

  

  FUN_1402f94c0(local_118,0,0x105);

  local_1b8.dwReserved = 0;

  local_1b8.FlagsEx = 0;

  local_1b8.lpstrFile = local_118;

  local_1b8.lStructSize = 0x98;

  local_1b8._4_4_ = 0;

  local_1b8.hInstance = (HINSTANCE)0x0;

  local_1b8.lpstrFilter = "WAV Files (*.wav)";

  local_1b8.lpstrCustomFilter = (LPSTR)0x0;

  local_1b8.hwndOwner = (HWND)0x0;

  local_1b8.lpstrInitialDir = (LPCSTR)0x0;

  local_1b8.lpstrTitle = "Select a File";

  local_1b8.lpstrDefExt = (LPCSTR)0x0;

  local_1b8.nMaxFile = 0x104;

  local_1b8._60_4_ = 0;

  local_1b8.lpstrFileTitle = (LPSTR)0x0;

  local_1b8.nMaxFileTitle = 0;

  local_1b8._76_4_ = 0;

  local_1b8.nMaxCustFilter = 0;

  local_1b8.nFilterIndex = 1;

  local_1b8.lCustData = 0;

  local_1b8.lpfnHook = (LPOFNHOOKPROC)0x0;

  local_1b8.Flags = 0x1808;

  local_1b8.nFileOffset = 0;

  local_1b8.nFileExtension = 0;

  local_1b8.lpTemplateName = (LPCSTR)0x0;

  local_1b8.pvReserved = (void *)0x0;

  BVar1 = GetOpenFileNameA(&local_1b8);

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  if (BVar1 == 0) {

    param_1[3] = 0xf;

    *(undefined1 *)param_1 = 0;

  }

  else {

    param_1[3] = 0;

    sVar2 = strlen(local_118);

    FUN_140027e30(param_1,local_118,sVar2);

  }

  return param_1;

}




