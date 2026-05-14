// Address: 0x1402de724
// Ghidra name: parse_floating_point<>
// ============ 0x1402de724 parse_floating_point<> (size=166) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* Library Function - Multiple Matches With Same Base Name

    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class

   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::console_input_adapter<char>

   >,float>(struct __crt_locale_pointers * __ptr64 const,class

   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::console_input_adapter<char>

   >,float * __ptr64 const)

    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class

   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::console_input_adapter<char>

   >,double>(struct __crt_locale_pointers * __ptr64 const,class

   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::console_input_adapter<char>

   >,double * __ptr64 const)

    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class

   __crt_strtox::input_adapter_character_source<class

   __crt_stdio_input::console_input_adapter<wchar_t> >,float>(struct __crt_locale_pointers * __ptr64

   const,class __crt_strtox::input_adapter_character_source<class

   __crt_stdio_input::console_input_adapter<wchar_t> >,float * __ptr64 const)

    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class

   __crt_strtox::input_adapter_character_source<class

   __crt_stdio_input::console_input_adapter<wchar_t> >,double>(struct __crt_locale_pointers *

   __ptr64 const,class __crt_strtox::input_adapter_character_source<class

   __crt_stdio_input::console_input_adapter<wchar_t> >,double * __ptr64 const)

     12 names - too many to list

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



undefined8 parse_floating_point<>(longlong param_1,longlong param_2,longlong param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  undefined8 uVar3;

  undefined1 auStack_348 [32];

  undefined1 local_328 [784];

  ulonglong local_18;

  

  local_18 = DAT_1403e8b00 ^ (ulonglong)auStack_348;

  if ((param_3 == 0) || (param_1 == 0)) {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    if ((*(undefined1 **)(param_2 + 0x18) != (undefined1 *)0x0) &&

       (*(longlong *)(param_2 + 0x10) == 0)) {

      **(undefined1 **)(param_2 + 0x18) = 0;

    }

    uVar3 = 1;

  }

  else {

    uVar1 = FUN_1402de7cc(param_1,param_2,local_328);

    uVar3 = FUN_1402dbc40(uVar1,local_328,param_3);

    if ((*(undefined1 **)(param_2 + 0x18) != (undefined1 *)0x0) &&

       (*(longlong *)(param_2 + 0x10) == 0)) {

      **(undefined1 **)(param_2 + 0x18) = 0;

    }

  }

  return uVar3;

}




