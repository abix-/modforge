// Address: 0x1402f59ac
// Ghidra name: common_sopen_dispatch<>
// ============ 0x1402f59ac common_sopen_dispatch<> (size=195) ============


/* Library Function - Multiple Matches With Same Base Name

    int __cdecl common_sopen_dispatch<char>(char const * __ptr64 const,int,int,int,int * __ptr64

   const,int)

    int __cdecl common_sopen_dispatch<wchar_t>(wchar_t const * __ptr64 const,int,int,int,int *

   __ptr64 const,int)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int common_sopen_dispatch<>

              (longlong param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint *param_5,

              int param_6)



{

  byte *pbVar1;

  int iVar2;

  undefined4 *puVar3;

  int local_18;

  int local_14;

  

  if (((param_5 == (uint *)0x0) || (*param_5 = 0xffffffff, param_1 == 0)) ||

     ((param_6 != 0 && ((param_4 & 0xfffffe7f) != 0)))) {

    puVar3 = (undefined4 *)FUN_1402e68b0();

    *puVar3 = 0x16;

    FUN_1402cd454();

    iVar2 = 0x16;

  }

  else {

    local_18 = 0;

    local_14 = 0;

    iVar2 = FUN_1402f5fc8(&local_18,param_5,param_1,param_2,param_3,param_4,param_6);

    if (local_18 != 0) {

      if (iVar2 != 0) {

        pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)*param_5 >> 6] + 0x38 +

                         (ulonglong)(*param_5 & 0x3f) * 0x48);

        *pbVar1 = *pbVar1 & 0xfe;

      }

      local_14 = iVar2;

      __acrt_lowio_unlock_fh(*param_5);

    }

    if (iVar2 != 0) {

      *param_5 = 0xffffffff;

    }

  }

  return iVar2;

}




