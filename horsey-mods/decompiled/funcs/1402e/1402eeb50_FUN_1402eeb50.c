// Address: 0x1402eeb50
// Ghidra name: FUN_1402eeb50
// ============ 0x1402eeb50 FUN_1402eeb50 (size=136) ============


bool FUN_1402eeb50(longlong *param_1)



{

  bool bVar1;

  BOOL BVar2;

  HANDLE hFile;

  LARGE_INTEGER local_res8;

  LARGE_INTEGER local_res10 [3];

  

  if ((*(uint *)((longlong)param_1 + 0x14) >> 3 & 1) == 0) {

    if ((((*(uint *)((longlong)param_1 + 0x14) & 0xc0) == 0) || (*param_1 != param_1[1])) &&

       (hFile = (HANDLE)FUN_1402f4f90((int)param_1[3]), hFile != (HANDLE)0xffffffffffffffff)) {

      local_res10[0].QuadPart = 0;

      BVar2 = SetFilePointerEx(hFile,(LARGE_INTEGER)0x0,local_res10,1);

      if (BVar2 != 0) {

        local_res8.QuadPart = 0;

        BVar2 = GetFileSizeEx(hFile,&local_res8);

        if (BVar2 != 0) {

          return local_res10[0].QuadPart == local_res8.QuadPart;

        }

      }

    }

    bVar1 = false;

  }

  else {

    bVar1 = true;

  }

  return bVar1;

}




