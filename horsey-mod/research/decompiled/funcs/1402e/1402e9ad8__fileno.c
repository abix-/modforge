// Address: 0x1402e9ad8
// Ghidra name: _fileno
// ============ 0x1402e9ad8 _fileno (size=39) ============


/* Library Function - Single Match

    _fileno

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl _fileno(FILE *_File)



{

  int iVar1;

  undefined4 *puVar2;

  

  if (_File == (FILE *)0x0) {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    iVar1 = -1;

  }

  else {

    iVar1 = _File->_flag;

  }

  return iVar1;

}




