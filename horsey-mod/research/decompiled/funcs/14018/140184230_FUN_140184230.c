// Address: 0x140184230
// Ghidra name: FUN_140184230
// ============ 0x140184230 FUN_140184230 (size=49) ============


longlong FUN_140184230(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = 1;

  if (param_2 != 0) {

    lVar1 = param_2;

  }

  lVar1 = (*(code *)PTR__realloc_base_1403e3988)(param_1,lVar1);

  if (lVar1 == 0) {

    FUN_14012e770();

  }

  return lVar1;

}




