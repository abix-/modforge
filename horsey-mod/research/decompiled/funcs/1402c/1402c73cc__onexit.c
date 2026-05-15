// Address: 0x1402c73cc
// Ghidra name: _onexit
// ============ 0x1402c73cc _onexit (size=58) ============


/* Library Function - Single Match

    _onexit

   

   Library: Visual Studio 2019 Release */



_onexit_t __cdecl _onexit(_onexit_t _Func)



{

  int iVar1;

  _onexit_t p_Var2;

  

  if (DAT_1403fe640 == -1) {

    iVar1 = FUN_1402e7af8();

  }

  else {

    iVar1 = _register_onexit_function(&DAT_1403fe640);

  }

  p_Var2 = (_onexit_t)0x0;

  if (iVar1 == 0) {

    p_Var2 = _Func;

  }

  return p_Var2;

}




