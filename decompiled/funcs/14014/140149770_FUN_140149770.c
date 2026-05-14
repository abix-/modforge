// Address: 0x140149770
// Ghidra name: FUN_140149770
// ============ 0x140149770 FUN_140149770 (size=58) ============


void FUN_140149770(UINT param_1)



{

  if (param_1 != DAT_1403fc048) {

    if (DAT_1403fc048 != 0) {

      timeEndPeriod(DAT_1403fc048);

    }

    DAT_1403fc048 = param_1;

    if (param_1 != 0) {

                    /* WARNING: Could not recover jumptable at 0x00014014979d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      timeBeginPeriod(param_1);

      return;

    }

  }

  return;

}




