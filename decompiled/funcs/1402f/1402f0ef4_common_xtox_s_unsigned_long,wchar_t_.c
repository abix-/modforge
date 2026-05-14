// Address: 0x1402f0ef4
// Ghidra name: common_xtox_s<unsigned_long,wchar_t>
// ============ 0x1402f0ef4 common_xtox_s<unsigned_long,wchar_t> (size=105) ============


/* Library Function - Single Match

    int __cdecl common_xtox_s<unsigned long,wchar_t>(unsigned long,wchar_t * __ptr64 const,unsigned

   __int64,unsigned int,bool)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl

common_xtox_s<unsigned_long,wchar_t>

          (ulong param_1,wchar_t *param_2,__uint64 param_3,uint param_4,bool param_5)



{

  int iVar1;

  int *piVar2;

  

  if ((param_2 != (wchar_t *)0x0) && (param_3 != 0)) {

    *param_2 = L'\0';

    if (param_3 <= (ulonglong)param_5 + 1) {

      piVar2 = (int *)FUN_1402e68b0();

      iVar1 = 0x22;

      goto LAB_1402f0f0e;

    }

    if (param_4 - 2 < 0x23) {

      iVar1 = FUN_1402f0e20(param_1);

      return iVar1;

    }

  }

  piVar2 = (int *)FUN_1402e68b0();

  iVar1 = 0x16;

LAB_1402f0f0e:

  *piVar2 = iVar1;

  FUN_1402cd454();

  return iVar1;

}




