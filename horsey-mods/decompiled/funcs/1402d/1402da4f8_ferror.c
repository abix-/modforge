// Address: 0x1402da4f8
// Ghidra name: ferror
// ============ 0x1402da4f8 ferror (size=44) ============


/* Library Function - Single Match

    ferror

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl ferror(FILE *_File)



{

  uint uVar1;

  undefined4 *puVar2;

  

  if (_File == (FILE *)0x0) {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    uVar1 = 0;

  }

  else {

    uVar1 = *(uint *)((longlong)&_File->_base + 4) >> 4 & 1;

  }

  return uVar1;

}




