// Address: 0x14030119c
// Ghidra name: ~_Init_atexit
// ============ 0x14030119c ~_Init_atexit (size=62) ============


/* Library Function - Single Match

    public: __cdecl _Init_atexit::~_Init_atexit(void) __ptr64

   

   Library: Visual Studio 2019 Release */



void __thiscall _Init_atexit::~_Init_atexit(_Init_atexit *this)



{

  longlong lVar1;

  PVOID pvVar2;

  

  while (DAT_1403e8ab8 < 10) {

    lVar1 = DAT_1403e8ab8 * 8;

    DAT_1403e8ab8 = DAT_1403e8ab8 + 1;

    pvVar2 = DecodePointer(*(PVOID *)(&DAT_1403fe4c0 + lVar1));

    if (pvVar2 != (PVOID)0x0) {

      (*(code *)PTR__guard_dispatch_icall_140302c68)();

    }

  }

  return;

}




