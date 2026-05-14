// Address: 0x1402ccc14
// Ghidra name: __except_validate_context_record
// ============ 0x1402ccc14 __except_validate_context_record (size=55) ============


/* Library Function - Single Match

    __except_validate_context_record

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



void __except_validate_context_record(longlong param_1)



{

  code *pcVar1;

  

  if ((code *)PTR__guard_check_icall_140302c58 != _guard_check_icall) {

    if ((*(ulonglong *)(param_1 + 0x98) < *(ulonglong *)((longlong)Self + 0x10)) ||

       (*(ulonglong *)((longlong)Self + 8) < *(ulonglong *)(param_1 + 0x98))) {

      pcVar1 = (code *)swi(0x29);

      (*pcVar1)(0xd);

    }

  }

  return;

}




