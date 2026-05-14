// Address: 0x1401796b0
// Ghidra name: FUN_1401796b0
// ============ 0x1401796b0 FUN_1401796b0 (size=205) ============


undefined8 FUN_1401796b0(LPCSTR param_1)



{

  bool bVar1;

  DWORD DVar2;

  DWORD DVar3;

  LPSTR lpBuffer;

  undefined8 uVar4;

  

  lpBuffer = (LPSTR)0x0;

  if ((param_1 != (LPCSTR)0x0) && (*param_1 != '\0')) {

    SetLastError(0);

    DVar2 = GetEnvironmentVariableA(param_1,(LPSTR)0x0,0);

    if (DVar2 != 0) {

      do {

        lpBuffer = (LPSTR)FUN_140184230(lpBuffer,DVar2);

        if (lpBuffer == (LPSTR)0x0) {

          return 0;

        }

        SetLastError(0);

        DVar3 = GetEnvironmentVariableA(param_1,lpBuffer,DVar2);

        bVar1 = DVar2 < DVar3;

        DVar2 = DVar3;

      } while (bVar1);

    }

    DVar2 = GetLastError();

    if (DVar2 == 0) {

      if (lpBuffer != (LPSTR)0x0) {

        uVar4 = FUN_1401aa890(lpBuffer);

        FUN_1401841e0(lpBuffer);

        return uVar4;

      }

      return 0;

    }

    FUN_1401841e0(lpBuffer);

  }

  return 0;

}




