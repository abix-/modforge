// Address: 0x140179780
// Ghidra name: FUN_140179780
// ============ 0x140179780 FUN_140179780 (size=160) ============


undefined8 FUN_140179780(LPCSTR param_1,LPCSTR param_2,int param_3)



{

  DWORD DVar1;

  BOOL BVar2;

  longlong lVar3;

  

  if ((param_1 != (LPCSTR)0x0) && (*param_1 != '\0')) {

    lVar3 = thunk_FUN_1402c9190(param_1,0x3d);

    if (lVar3 != 0) {

      return 0xffffffff;

    }

    if (param_2 == (LPCSTR)0x0) {

      return 0xffffffff;

    }

    if (DAT_1403fc4f8 != 0) {

      FUN_1401794a0(DAT_1403fc4f8,param_1,param_2,param_3 != 0);

    }

    if ((param_3 == 0) && (DVar1 = GetEnvironmentVariableA(param_1,(LPSTR)0x0,0), DVar1 != 0)) {

      return 0;

    }

    BVar2 = SetEnvironmentVariableA(param_1,param_2);

    if (BVar2 != 0) {

      return 0;

    }

  }

  return 0xffffffff;

}




