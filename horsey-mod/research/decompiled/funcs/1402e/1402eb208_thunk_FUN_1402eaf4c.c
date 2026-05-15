// Address: 0x1402eb208
// Ghidra name: thunk_FUN_1402eaf4c
// ============ 0x1402eb208 thunk_FUN_1402eaf4c (size=5) ============


longlong thunk_FUN_1402eaf4c(uint param_1,LARGE_INTEGER param_2,DWORD param_3,longlong param_4)



{

  byte *pbVar1;

  BOOL BVar2;

  DWORD DVar3;

  HANDLE hFile;

  LARGE_INTEGER aLStack_18 [2];

  

  hFile = (HANDLE)FUN_1402f4f90(param_1);

  if (hFile == (HANDLE)0xffffffffffffffff) {

    *(undefined1 *)(param_4 + 0x30) = 1;

    *(undefined4 *)(param_4 + 0x2c) = 9;

  }

  else {

    aLStack_18[0].QuadPart = 0;

    BVar2 = SetFilePointerEx(hFile,param_2,aLStack_18,param_3);

    if (BVar2 == 0) {

      DVar3 = GetLastError();

      FUN_1402e6868(DVar3,param_4);

    }

    else if (aLStack_18[0].QuadPart != -1) {

      pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + 0x38 +

                       (ulonglong)(param_1 & 0x3f) * 0x48);

      *pbVar1 = *pbVar1 & 0xfd;

      return (longlong)aLStack_18[0].s;

    }

  }

  return -1;

}




