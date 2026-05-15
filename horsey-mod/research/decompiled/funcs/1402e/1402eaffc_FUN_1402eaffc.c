// Address: 0x1402eaffc
// Ghidra name: FUN_1402eaffc
// ============ 0x1402eaffc FUN_1402eaffc (size=194) ============


undefined4 FUN_1402eaffc(HANDLE param_1,int param_2,DWORD param_3,longlong param_4)



{

  BOOL BVar1;

  DWORD DVar2;

  LARGE_INTEGER local_18;

  LARGE_INTEGER local_10;

  

  local_18.s.LowPart = 0;

  local_10.QuadPart = 0;

  local_18.s.HighPart = 0;

  BVar1 = SetFilePointerEx(param_1,(LARGE_INTEGER)0x0,&local_10,1);

  if (BVar1 != 0) {

    local_18.s.LowPart = 0;

    local_18.s.HighPart = 0;

    BVar1 = SetFilePointerEx(param_1,(LARGE_INTEGER)(longlong)param_2,&local_18,param_3);

    if (BVar1 != 0) {

      if (0x7fffffff < CONCAT44(local_18.s.HighPart,local_18.s.LowPart)) {

        SetFilePointerEx(param_1,local_10,(PLARGE_INTEGER)0x0,0);

        *(undefined1 *)(param_4 + 0x30) = 1;

        *(undefined4 *)(param_4 + 0x2c) = 0x16;

        return 0xffffffff;

      }

      return local_18.s.LowPart;

    }

  }

  DVar2 = GetLastError();

  FUN_1402e6868(DVar2,param_4);

  return 0xffffffff;

}




