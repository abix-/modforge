// Address: 0x1401959b0
// Ghidra name: FUN_1401959b0
// ============ 0x1401959b0 FUN_1401959b0 (size=263) ============


int FUN_1401959b0(undefined8 *param_1,DWORD param_2,char *param_3,longlong param_4)



{

  BOOL BVar1;

  DWORD DVar2;

  DWORD local_res18 [2];

  _OVERLAPPED local_28;

  

  local_res18[0] = 0;

  local_28.Internal = 0;

  local_28.InternalHigh = 0;

  local_28.u.Pointer = (PVOID)0x0;

  local_28.hEvent = (HANDLE)0x0;

  if ((param_3 == (char *)0x0) || (param_4 == 0)) {

    FUN_140196b60(0,L"Zero buffer/length");

  }

  else {

    FUN_140196b60(0,0);

    BVar1 = DeviceIoControl((HANDLE)*param_1,param_2,param_3,(DWORD)param_4,param_3,(DWORD)param_4,

                            local_res18,&local_28);

    if ((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 != 0x3e5)) {

      FUN_140196c00(param_1,L"Get Input/Feature Report DeviceIoControl");

    }

    else {

      BVar1 = GetOverlappedResult((HANDLE)*param_1,&local_28,local_res18,1);

      if (BVar1 != 0) {

        if (*param_3 != '\0') {

          return local_res18[0];

        }

        return local_res18[0] + 1;

      }

      FUN_140196c00(param_1,L"Get Input/Feature Report GetOverLappedResult");

    }

  }

  return -1;

}




