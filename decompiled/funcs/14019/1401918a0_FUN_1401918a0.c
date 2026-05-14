// Address: 0x1401918a0
// Ghidra name: FUN_1401918a0
// ============ 0x1401918a0 FUN_1401918a0 (size=409) ============


ulonglong FUN_1401918a0(undefined8 *param_1,LPCVOID param_2,ulonglong param_3)



{

  BOOL BVar1;

  DWORD DVar2;

  ulonglong uVar3;

  LPCVOID pvVar4;

  DWORD local_res10 [2];

  

  local_res10[0] = 0;

  if ((param_2 == (LPCVOID)0x0) || (param_3 == 0)) {

    FUN_140196b60(param_1,L"Zero buffer/length");

    return 0xffffffff;

  }

  FUN_140196b60(param_1,0);

  if (*(int *)(param_1 + 0x12) != 0) {

    uVar3 = FUN_1401964a0(param_1,param_2,param_3);

    return uVar3;

  }

  if (param_3 < *(ushort *)((longlong)param_1 + 0xc)) {

    pvVar4 = (LPCVOID)param_1[2];

    if (pvVar4 == (LPCVOID)0x0) {

      pvVar4 = (LPCVOID)FUN_1401841f0();

      param_1[2] = pvVar4;

    }

    FUN_1402f8e20(pvVar4,param_2,param_3);

    FUN_1402f94c0((longlong)pvVar4 + param_3,0,*(ushort *)((longlong)param_1 + 0xc) - param_3);

    param_3 = (ulonglong)*(ushort *)((longlong)param_1 + 0xc);

    param_2 = pvVar4;

  }

  BVar1 = WriteFile((HANDLE)*param_1,param_2,(DWORD)param_3,local_res10,

                    (LPOVERLAPPED)(param_1 + 0xd));

  if (BVar1 == 0) {

    DVar2 = GetLastError();

    if (DVar2 != 0x3e5) {

      FUN_140196c00(param_1,L"WriteFile");

      return 0xffffffff;

    }

    DVar2 = WaitForSingleObject((HANDLE)param_1[0x10],1000);

    if (DVar2 != 0) {

      FUN_140196c00(param_1,L"hid_write/WaitForSingleObject");

      return 0xffffffff;

    }

    BVar1 = GetOverlappedResult((HANDLE)*param_1,(LPOVERLAPPED)(param_1 + 0xd),local_res10,0);

    if (BVar1 == 0) {

      FUN_140196c00(param_1,L"hid_write/GetOverlappedResult");

      return 0xffffffff;

    }

  }

  return (ulonglong)local_res10[0];

}




