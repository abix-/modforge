// Address: 0x140110e70
// Ghidra name: _Med3_unchecked<>
// ============ 0x140110e70 _Med3_unchecked<> (size=122) ============


/* Library Function - Multiple Matches With Same Base Name

    void __cdecl std::_Med3_unchecked<struct REFMINIPDB2 * __ptr64 * __ptr64,bool (__cdecl*)(struct

   REFMINIPDB2 const * __ptr64,struct REFMINIPDB2 const * __ptr64)>(struct REFMINIPDB2 * __ptr64 *

   __ptr64,struct REFMINIPDB2 * __ptr64 * __ptr64,struct REFMINIPDB2 * __ptr64 * __ptr64,bool

   (__cdecl*)(struct REFMINIPDB2 const * __ptr64,struct REFMINIPDB2 const * __ptr64))

    void __cdecl std::_Med3_unchecked<struct SYMTYPE * __ptr64 * __ptr64,bool (__cdecl*)(struct

   SYMTYPE * __ptr64,struct SYMTYPE * __ptr64)>(struct SYMTYPE * __ptr64 * __ptr64,struct SYMTYPE *

   __ptr64 * __ptr64,struct SYMTYPE * __ptr64 * __ptr64,bool (__cdecl*)(struct SYMTYPE *

   __ptr64,struct SYMTYPE * __ptr64))

   

   Library: Visual Studio 2019 Release */



void _Med3_unchecked<>(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,code *param_4)



{

  undefined8 uVar1;

  char cVar2;

  

  cVar2 = (*param_4)(*param_2,*param_1);

  if (cVar2 != '\0') {

    uVar1 = *param_2;

    *param_2 = *param_1;

    *param_1 = uVar1;

  }

  cVar2 = (*param_4)(*param_3,*param_2);

  if (cVar2 != '\0') {

    uVar1 = *param_3;

    *param_3 = *param_2;

    *param_2 = uVar1;

    cVar2 = (*param_4)(uVar1,*param_1);

    if (cVar2 != '\0') {

      uVar1 = *param_2;

      *param_2 = *param_1;

      *param_1 = uVar1;

    }

  }

  return;

}




