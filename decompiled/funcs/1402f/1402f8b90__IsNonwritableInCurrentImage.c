// Address: 0x1402f8b90
// Ghidra name: _IsNonwritableInCurrentImage
// ============ 0x1402f8b90 _IsNonwritableInCurrentImage (size=75) ============


/* Library Function - Single Match

    _IsNonwritableInCurrentImage

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



BOOL __cdecl _IsNonwritableInCurrentImage(PBYTE pTarget)



{

  int iVar1;

  uint uVar2;

  PIMAGE_SECTION_HEADER p_Var3;

  

  iVar1 = FUN_1402f8be0(&IMAGE_DOS_HEADER_140000000);

  uVar2 = 0;

  if (iVar1 != 0) {

    p_Var3 = _FindPESection((PBYTE)&IMAGE_DOS_HEADER_140000000,(DWORD_PTR)(pTarget + -0x140000000));

    uVar2 = 0;

    if (p_Var3 != (PIMAGE_SECTION_HEADER)0x0) {

      uVar2 = ~(p_Var3->Characteristics >> 0x1f) & 1;

    }

  }

  return uVar2;

}




