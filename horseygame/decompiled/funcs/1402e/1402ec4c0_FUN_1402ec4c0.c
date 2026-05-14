// Address: 0x1402ec4c0
// Ghidra name: FUN_1402ec4c0
// ============ 0x1402ec4c0 FUN_1402ec4c0 (size=98) ============


/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */



void FUN_1402ec4c0(undefined8 param_1,undefined4 param_2)



{

  code *pcVar1;

  

  if (DAT_1404240a0 == (code *)0xffffffffffffffff) {

LAB_1402ec50f:

    FUN_1402f69d4(param_1);

  }

  else {

    pcVar1 = DAT_1404240a0;

    if (DAT_1404240a0 == (code *)0x0) {

      pcVar1 = (code *)FUN_1402ec028(0x14,"LocaleNameToLCID",&DAT_14038eac0,"LocaleNameToLCID");

      if (pcVar1 == (code *)0x0) goto LAB_1402ec50f;

    }

    (*pcVar1)(param_1,param_2);

  }

  return;

}




