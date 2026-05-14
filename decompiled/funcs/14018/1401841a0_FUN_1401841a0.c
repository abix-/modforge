// Address: 0x1401841a0
// Ghidra name: FUN_1401841a0
// ============ 0x1401841a0 FUN_1401841a0 (size=51) ============


longlong FUN_1401841a0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  if ((param_1 == 0) || (param_2 == 0)) {

    param_1 = 1;

  }

  lVar1 = (*(code *)PTR__calloc_base_1403e3980)(param_1);

  if (lVar1 == 0) {

    FUN_14012e770();

  }

  return lVar1;

}




