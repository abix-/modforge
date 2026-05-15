// Address: 0x140188550
// Ghidra name: FUN_140188550
// ============ 0x140188550 FUN_140188550 (size=85) ============


FARPROC FUN_140188550(HMODULE param_1,LPCSTR param_2)



{

  FARPROC pFVar1;

  undefined1 local_208 [512];

  

  pFVar1 = GetProcAddress(param_1,param_2);

  if (pFVar1 == (FARPROC)0x0) {

    FUN_14012ef10(local_208,0x200,"Failed loading %s",param_2);

    FUN_1401a9ed0(local_208);

  }

  return pFVar1;

}




