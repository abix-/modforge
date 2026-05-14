// Address: 0x1402e03e8
// Ghidra name: process_floating_point_specifier
// ============ 0x1402e03e8 process_floating_point_specifier (size=110) ============


/* Library Function - Single Match

    private: bool __cdecl __crt_stdio_input::input_processor<char,class

   __crt_stdio_input::string_input_adapter<char> >::process_floating_point_specifier(void) __ptr64

   

   Library: Visual Studio 2019 Release */



bool __thiscall

__crt_stdio_input::input_processor<char,__crt_stdio_input::string_input_adapter<char>_>::

process_floating_point_specifier

          (input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *this)



{

  undefined1 uVar1;

  int iVar2;

  longlong lVar3;

  

  iVar2 = FUN_1402dfea0(this + 8,*(undefined8 *)(this + 0x78));

  lVar3 = *(longlong *)(this + 0x18);

  if ((lVar3 != *(longlong *)(this + 8)) && ((lVar3 != *(longlong *)(this + 0x10) || (iVar2 != -1)))

     ) {

    *(longlong *)(this + 0x18) = lVar3 + -1;

  }

  lVar3 = FUN_1402e0120(this + 0x20);

  if (lVar3 == 4) {

    uVar1 = FUN_1402df9d0(this);

  }

  else if (lVar3 == 8) {

    uVar1 = FUN_1402dfa74(this);

  }

  else {

    uVar1 = 0;

  }

  return (bool)uVar1;

}




