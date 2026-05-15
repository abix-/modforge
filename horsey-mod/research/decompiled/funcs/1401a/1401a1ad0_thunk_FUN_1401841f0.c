// Address: 0x1401a1ad0
// Ghidra name: thunk_FUN_1401841f0
// ============ 0x1401a1ad0 thunk_FUN_1401841f0 (size=5) ============


longlong thunk_FUN_1401841f0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = 1;

  if (param_1 != 0) {

    lVar1 = param_1;

  }

  lVar1 = (*(code *)PTR__malloc_base_1403e3978)(lVar1);

  if (lVar1 == 0) {

    FUN_14012e770();

  }

  return lVar1;

}




