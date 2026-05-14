// Address: 0x14017c8f0
// Ghidra name: FUN_14017c8f0
// ============ 0x14017c8f0 FUN_14017c8f0 (size=55) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14017c8f0(longlong param_1)



{

  longlong lVar1;

  

  lVar1 = FUN_14017ffb0();

  if (*(longlong *)(param_1 + 8) == lVar1) {

    *(undefined8 *)(param_1 + 8) = 0;

                    /* WARNING: Could not recover jumptable at 0x00014017c914. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*_DAT_1403fc590)();

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x00014017c920. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*_DAT_1403fc578)(param_1);

  return;

}




