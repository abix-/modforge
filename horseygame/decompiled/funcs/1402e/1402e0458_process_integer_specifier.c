// Address: 0x1402e0458
// Ghidra name: process_integer_specifier
// ============ 0x1402e0458 process_integer_specifier (size=182) ============


/* Library Function - Single Match

    private: bool __cdecl __crt_stdio_input::input_processor<char,class

   __crt_stdio_input::string_input_adapter<char> >::process_integer_specifier(unsigned int,bool)

   __ptr64

   

   Library: Visual Studio 2019 Release */



bool __thiscall

__crt_stdio_input::input_processor<char,__crt_stdio_input::string_input_adapter<char>_>::

process_integer_specifier

          (input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *this,uint param_1,

          bool param_2)



{

  input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *piVar1;

  longlong lVar2;

  undefined1 uVar3;

  int iVar4;

  undefined8 uVar5;

  char local_res8 [8];

  input_processor<char,__crt_stdio_input::string_input_adapter<char>_> *local_28;

  undefined8 local_20;

  undefined8 local_18;

  char *local_10;

  

  piVar1 = this + 8;

  iVar4 = FUN_1402dfea0(piVar1,*(undefined8 *)(this + 0x78));

  lVar2 = *(longlong *)(this + 0x18);

  if ((lVar2 != *(longlong *)piVar1) && ((lVar2 != *(longlong *)(this + 0x10) || (iVar4 != -1)))) {

    *(longlong *)(this + 0x18) = lVar2 + -1;

  }

  local_20 = *(undefined8 *)(this + 0x40);

  local_10 = local_res8;

  local_18 = 0;

  local_res8[0] = '\x01';

  local_28 = piVar1;

  uVar5 = FUN_1402df8d0(*(undefined8 *)(this + 0x78),&local_28,param_1,param_2);

  if (local_res8[0] == '\0') {

    uVar3 = 0;

  }

  else if (this[0x3a] == (input_processor<char,__crt_stdio_input::string_input_adapter<char>_>)0x0)

  {

    uVar3 = FUN_1402e0c88(this,uVar5);

  }

  else {

    uVar3 = 1;

  }

  return (bool)uVar3;

}




