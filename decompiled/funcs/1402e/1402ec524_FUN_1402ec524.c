// Address: 0x1402ec524
// Ghidra name: FUN_1402ec524
// ============ 0x1402ec524 FUN_1402ec524 (size=127) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402ec524(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  code *pcVar1;

  

  if (DAT_1404240b8 != (code *)0xffffffffffffffff) {

    pcVar1 = DAT_1404240b8;

    if (DAT_1404240b8 == (code *)0x0) {

      pcVar1 = (code *)FUN_1402ec028(0x17,"MessageBoxW",&DAT_14038eaf8,"MessageBoxW");

      if (pcVar1 == (code *)0x0) goto LAB_1402ec59e;

    }

    (*pcVar1)(param_1,param_2,param_3,param_4);

    return;

  }

LAB_1402ec59e:

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




