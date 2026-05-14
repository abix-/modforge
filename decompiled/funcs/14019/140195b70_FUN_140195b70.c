// Address: 0x140195b70
// Ghidra name: FUN_140195b70
// ============ 0x140195b70 FUN_140195b70 (size=151) ============


LPWSTR FUN_140195b70(LPCSTR param_1)



{

  int cchWideChar;

  LPWSTR lpWideCharStr;

  

  lpWideCharStr = (LPWSTR)0x0;

  cchWideChar = MultiByteToWideChar(0xfde9,8,param_1,-1,(LPWSTR)0x0,0);

  if (cchWideChar != 0) {

    lpWideCharStr = (LPWSTR)FUN_1401841a0((longlong)cchWideChar,2);

    if (lpWideCharStr == (LPWSTR)0x0) {

      return (LPWSTR)0x0;

    }

    MultiByteToWideChar(0xfde9,8,param_1,-1,lpWideCharStr,cchWideChar);

  }

  return lpWideCharStr;

}




