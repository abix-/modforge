// Address: 0x140173170
// Ghidra name: FUN_140173170
// ============ 0x140173170 FUN_140173170 (size=32) ============


void FUN_140173170(longlong param_1)



{

  if (*(int *)(param_1 + 0x14) == 0) {

    if (*(code **)(DAT_1403fc410 + 0x38) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00014017318c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(DAT_1403fc410 + 0x38))(DAT_1403fc410,param_1);

      return;

    }

  }

  return;

}




