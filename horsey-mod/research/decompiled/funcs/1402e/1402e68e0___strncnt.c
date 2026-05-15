// Address: 0x1402e68e0
// Ghidra name: __strncnt
// ============ 0x1402e68e0 __strncnt (size=21) ============


/* Library Function - Single Match

    __strncnt

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



size_t __cdecl __strncnt(char *_String,size_t _Cnt)



{

  char cVar1;

  size_t sVar2;

  

  sVar2 = 0;

  cVar1 = *_String;

  while ((cVar1 != '\0' && (sVar2 != _Cnt))) {

    sVar2 = sVar2 + 1;

    cVar1 = _String[sVar2];

  }

  return sVar2;

}




