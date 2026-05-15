// Address: 0x1402e0650
// Ghidra name: process_string_specifier
// ============ 0x1402e0650 process_string_specifier (size=137) ============


/* Library Function - Single Match

    private: bool __cdecl __crt_stdio_input::input_processor<char,class

   __crt_stdio_input::string_input_adapter<char> >::process_string_specifier(enum

   __crt_stdio_input::conversion_mode) __ptr64

   

   Library: Visual Studio 2019 Release */



bool __thiscall

__crt_stdio_input::input_processor<char,__crt_stdio_input::string_input_adapter<char>_>::

process_string_specifier

          (input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *this,

          conversion_mode param_1)



{

  undefined1 uVar1;

  int iVar2;

  longlong lVar3;

  

  if (param_1 == 1) {

    iVar2 = FUN_1402dfea0(this + 8,*(undefined8 *)(this + 0x78));

    lVar3 = *(longlong *)(this + 0x18);

    if ((lVar3 != *(longlong *)(this + 8)) &&

       ((lVar3 != *(longlong *)(this + 0x10) || (iVar2 != -1)))) {

      *(longlong *)(this + 0x18) = lVar3 + -1;

    }

  }

  lVar3 = FUN_1402e0120(this + 0x20);

  if (lVar3 == 1) {

    uVar1 = FUN_1402dfb1c(this,param_1,0);

  }

  else if (lVar3 == 2) {

    uVar1 = FUN_1402dfcc0(this,param_1,0);

  }

  else {

    uVar1 = 0;

  }

  return (bool)uVar1;

}




