// Address: 0x14004a210
// Ghidra name: FUN_14004a210
// ============ 0x14004a210 FUN_14004a210 (size=52) ============


void FUN_14004a210(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = _malloc_base(param_1 + 0x10);

  if (lVar1 == 0) {

    return;

  }

  *(byte *)((lVar1 + 0x10U & 0xfffffffffffffff0) - 1) = '\x10' - ((byte)lVar1 & 0xf);

  return;

}




