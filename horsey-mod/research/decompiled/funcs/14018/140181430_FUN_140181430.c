// Address: 0x140181430
// Ghidra name: FUN_140181430
// ============ 0x140181430 FUN_140181430 (size=160) ============


undefined4 FUN_140181430(void)



{

  LSTATUS LVar1;

  undefined4 uVar2;

  int local_res8 [2];

  DWORD local_res10 [2];

  DWORD local_res18 [2];

  HKEY local_res20;

  

  local_res18[0] = 4;

  local_res8[0] = -1;

  local_res10[0] = 4;

  uVar2 = 1;

  LVar1 = RegOpenKeyExW((HKEY)0xffffffff80000001,

                        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",0,

                        0x20019,&local_res20);

  if (LVar1 == 0) {

    LVar1 = RegQueryValueExW(local_res20,L"AppsUseLightTheme",(LPDWORD)0x0,local_res18,

                             (LPBYTE)local_res8,local_res10);

    if (LVar1 == 0) {

      uVar2 = 1;

      if (local_res8[0] == 0) {

        uVar2 = 2;

      }

    }

    RegCloseKey(local_res20);

  }

  return uVar2;

}




