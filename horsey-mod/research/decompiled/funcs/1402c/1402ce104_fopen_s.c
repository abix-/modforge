// Address: 0x1402ce104
// Ghidra name: fopen_s
// ============ 0x1402ce104 fopen_s (size=88) ============


/* Library Function - Single Match

    fopen_s

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



errno_t __cdecl fopen_s(FILE **_File,char *_Filename,char *_Mode)



{

  undefined4 *puVar1;

  _iobuf *p_Var2;

  errno_t *peVar3;

  errno_t eVar4;

  

  eVar4 = 0;

  if (_File == (FILE **)0x0) {

    puVar1 = (undefined4 *)FUN_1402e68b0();

    eVar4 = 0x16;

    *puVar1 = 0x16;

    FUN_1402cd454();

  }

  else {

    p_Var2 = common_fsopen<char>(_Filename,_Mode,0x80);

    *_File = p_Var2;

    if (p_Var2 == (_iobuf *)0x0) {

      peVar3 = (errno_t *)FUN_1402e68b0();

      eVar4 = *peVar3;

    }

  }

  return eVar4;

}




