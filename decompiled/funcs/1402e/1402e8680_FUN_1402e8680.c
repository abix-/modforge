// Address: 0x1402e8680
// Ghidra name: FUN_1402e8680
// ============ 0x1402e8680 FUN_1402e8680 (size=65) ============


void FUN_1402e8680(void)



{

  PVOID pvVar1;

  longlong lVar2;

  

  if (DAT_1403e8d20 == 0xffffffff) {

    pvVar1 = (PVOID)0x0;

  }

  else {

    pvVar1 = FlsGetValue(DAT_1403e8d20);

  }

  if (pvVar1 != (PVOID)0xffffffffffffffff) {

    if (pvVar1 == (PVOID)0x0) {

      lVar2 = FUN_1402e8544();

      if (lVar2 == 0) goto LAB_1402e86bc;

    }

    return;

  }

LAB_1402e86bc:

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




