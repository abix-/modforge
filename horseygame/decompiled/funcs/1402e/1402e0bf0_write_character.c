// Address: 0x1402e0bf0
// Ghidra name: write_character
// ============ 0x1402e0bf0 write_character (size=150) ============


/* Library Function - Single Match

    private: bool __cdecl __crt_stdio_input::input_processor<char,class

   __crt_stdio_input::string_input_adapter<char> >::write_character(wchar_t __unaligned * __ptr64

   const,unsigned __int64,wchar_t __unaligned * __ptr64 & __ptr64,unsigned __int64 & __ptr64,char)

   __ptr64

   

   Library: Visual Studio 2019 Release */



bool __thiscall

__crt_stdio_input::input_processor<char,__crt_stdio_input::string_input_adapter<char>_>::

write_character(input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *this,

               wchar_t *param_1,__uint64 param_2,wchar_t **param_3,__uint64 *param_4,char param_5)



{

  undefined1 *puVar1;

  char cVar2;

  ushort *puVar3;

  undefined2 local_res8 [4];

  undefined1 uStack0000000000000031;

  

  cVar2 = param_5;

  uStack0000000000000031 = 0;

  puVar3 = __pctype_func();

  if ((short)puVar3[(byte)cVar2] < 0) {

    puVar1 = *(undefined1 **)(this + 0x18);

    if (puVar1 == *(undefined1 **)(this + 0x10)) {

      uStack0000000000000031 = 0xff;

    }

    else {

      uStack0000000000000031 = *puVar1;

      *(undefined1 **)(this + 0x18) = puVar1 + 1;

    }

  }

  local_res8[0] = 0x3f;

  FUN_1402f00bc(local_res8,&param_5,(longlong)*(int *)(**(longlong **)(this + 0x78) + 8));

  **param_3 = (short)cVar2;

  *param_3 = *param_3 + 1;

  *param_4 = *param_4 - 1;

  return true;

}




