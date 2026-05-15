// Address: 0x1402d1dfc
// Ghidra name: is_wide_character_specifier<wchar_t>
// ============ 0x1402d1dfc is_wide_character_specifier<wchar_t> (size=62) ============


/* Library Function - Single Match

    bool __cdecl __crt_stdio_output::is_wide_character_specifier<wchar_t>(unsigned

   __int64,wchar_t,enum __crt_stdio_output::length_modifier)

   

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual

   Studio 2019 Release */



bool __cdecl

__crt_stdio_output::is_wide_character_specifier<wchar_t>

          (__uint64 param_1,wchar_t param_2,length_modifier param_3)



{

  bool bVar1;

  

  if (param_3 == 2) {

    bVar1 = false;

  }

  else {

    if (((param_3 == 3) || (param_3 == 0xc)) || (param_3 == 0xd)) {

      return true;

    }

    bVar1 = (param_1 & 4) != 0;

    if ((param_2 + L'ﾝ' & 0xffefU) != 0) {

      return (param_1 & 4) == 0;

    }

  }

  return bVar1;

}




