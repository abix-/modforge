// Address: 0x1402cf8b8
// Ghidra name: FUN_1402cf8b8
// ============ 0x1402cf8b8 FUN_1402cf8b8 (size=30) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402cf8b8(void)



{

  longlong lVar1;

  

  lVar1 = FUN_1402e8664();

  if (*(code **)(lVar1 + 0x18) != (code *)0x0) {

    (**(code **)(lVar1 + 0x18))();

  }

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




