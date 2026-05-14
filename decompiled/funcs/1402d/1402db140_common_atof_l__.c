// Address: 0x1402db140
// Ghidra name: common_atof_l<>
// ============ 0x1402db140 common_atof_l<> (size=116) ============


/* Library Function - Multiple Matches With Same Base Name

    double __cdecl common_atof_l<char>(char const * __ptr64 const,struct __crt_locale_pointers *

   __ptr64 const)

    double __cdecl common_atof_l<wchar_t>(wchar_t const * __ptr64 const,struct __crt_locale_pointers

   * __ptr64 const)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 common_atof_l<>(longlong param_1,__crt_locale_pointers *param_2)



{

  undefined4 *puVar1;

  undefined8 local_res8 [4];

  longlong local_38 [2];

  longlong local_28;

  undefined1 local_20 [16];

  char local_10;

  

  if (param_1 == 0) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    *puVar1 = 0x16;

    FUN_1402cd454();

    local_res8[0] = 0;

  }

  else {

    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_28,param_2);

    local_38[1] = 0;

    local_res8[0] = 0;

    local_38[0] = param_1;

    parse_floating_point<>(local_20,local_38,local_res8);

    if (local_10 != '\0') {

      *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;

    }

  }

  return local_res8[0];

}




