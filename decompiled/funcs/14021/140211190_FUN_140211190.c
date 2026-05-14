// Address: 0x140211190
// Ghidra name: FUN_140211190
// ============ 0x140211190 FUN_140211190 (size=225) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140211190(undefined8 param_1,undefined8 param_2,undefined4 param_3,int param_4)



{

  if (param_4 < 0x8021) {

    if (param_4 == 0x8020) {

                    /* WARNING: Could not recover jumptable at 0x000140211201. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fd428)();

      return;

    }

    if (param_4 == 8) {

                    /* WARNING: Could not recover jumptable at 0x0001402111f0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*_DAT_1403fd418)();

      return;

    }

    if (param_4 == 0x8008) {

                    /* WARNING: Could not recover jumptable at 0x0001402111df. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*_DAT_1403fd410)();

      return;

    }

    if (param_4 == 0x8010) {

                    /* WARNING: Could not recover jumptable at 0x0001402111ce. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fd420)();

      return;

    }

  }

  else if (param_4 == 0x9010) {

    (*DAT_1403fd420)();

    (*DAT_1403fd430)(param_1,param_1,param_3);

  }

  else {

    if (param_4 == 0x9020) {

      (*DAT_1403fd428)();

                    /* WARNING: Could not recover jumptable at 0x00014021124a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fd438)(param_1,param_1,param_3);

      return;

    }

    if (param_4 == 0x9120) {

                    /* WARNING: Could not recover jumptable at 0x00014021122a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fd438)();

      return;

    }

  }

  return;

}




