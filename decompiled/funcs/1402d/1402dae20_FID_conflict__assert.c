// Address: 0x1402dae20
// Ghidra name: FID_conflict:_assert
// ============ 0x1402dae20 FID_conflict:_assert (size=115) ============


/* Library Function - Multiple Matches With Different Base Names

    _assert

    _wassert

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __cdecl FID_conflict__assert(wchar_t *_Message,wchar_t *_File,uint _Line)



{

  code *pcVar1;

  int iVar2;

  undefined8 unaff_retaddr;

  

  iVar2 = FUN_1402f0f80(3);

  if (iVar2 != 1) {

    if (iVar2 == 0) {

      iVar2 = FUN_1402e7d34();

      if (iVar2 == 1) goto LAB_1402dae84;

    }

    FUN_1402da6b8(_Message,_File,_Line,unaff_retaddr);

    return;

  }

LAB_1402dae84:

  FUN_1402dac78(_Message,_File,_Line);

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}




