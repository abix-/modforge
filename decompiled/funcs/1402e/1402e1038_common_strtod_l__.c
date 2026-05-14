// Address: 0x1402e1038
// Ghidra name: common_strtod_l<>
// ============ 0x1402e1038 common_strtod_l<> (size=165) ============


/* Library Function - Multiple Matches With Same Base Name

    double __cdecl common_strtod_l<double,char>(char const * __ptr64 const,char * __ptr64 * __ptr64

   const,struct __crt_locale_pointers * __ptr64 const)

    double __cdecl common_strtod_l<double,wchar_t>(wchar_t const * __ptr64 const,wchar_t * __ptr64 *

   __ptr64 const,struct __crt_locale_pointers * __ptr64 const)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 common_strtod_l<>(longlong param_1,longlong *param_2,__crt_locale_pointers *param_3)



{

  int iVar1;

  undefined4 *puVar2;

  undefined8 local_res8;

  longlong local_38;

  longlong *local_30;

  longlong local_28;

  undefined1 local_20 [16];

  char local_10;

  

  if (param_2 != (longlong *)0x0) {

    *param_2 = param_1;

  }

  if (param_1 == 0) {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    local_res8 = 0;

  }

  else {

    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_28,param_3);

    local_res8 = 0;

    if (param_2 != (longlong *)0x0) {

      *param_2 = param_1;

    }

    local_38 = param_1;

    local_30 = param_2;

    iVar1 = parse_floating_point<>(local_20,&local_38,&local_res8);

    if (iVar1 - 2U < 2) {

      puVar2 = (undefined4 *)FUN_1402e68b0();

      *puVar2 = 0x22;

    }

    if (local_10 != '\0') {

      *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;

    }

  }

  return local_res8;

}




