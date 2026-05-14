// Address: 0x1402112a0
// Ghidra name: FUN_1402112a0
// ============ 0x1402112a0 FUN_1402112a0 (size=212) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1402112a0(undefined8 param_1,undefined8 param_2,ulonglong param_3,int param_4)



{

  ulonglong uVar1;

  

  uVar1 = param_3 & 0xffffffff;

  if (param_4 < 0x8021) {

    uVar1 = param_3;

    if (param_4 == 0x8020) {

LAB_140211343:

                    /* WARNING: Could not recover jumptable at 0x00014021134d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*_DAT_1403fd408)(param_1,param_2,uVar1);

      return;

    }

    if (param_4 == 8) {

                    /* WARNING: Could not recover jumptable at 0x000140211304. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*_DAT_1403fd3f8)();

      return;

    }

    if (param_4 == 0x8008) {

                    /* WARNING: Could not recover jumptable at 0x0001402112f3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*_DAT_1403fd3f0)();

      return;

    }

    if (param_4 == 0x8010) {

                    /* WARNING: Could not recover jumptable at 0x0001402112e2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fd400)();

      return;

    }

  }

  else if (param_4 == 0x9010) {

    (*DAT_1403fd430)();

    (*DAT_1403fd400)(param_1,param_1,uVar1);

  }

  else {

    if (param_4 == 0x9020) {

      (*DAT_1403fd438)();

      param_2 = param_1;

      goto LAB_140211343;

    }

    if (param_4 == 0x9120) {

                    /* WARNING: Could not recover jumptable at 0x00014021132d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (*DAT_1403fd438)();

      return;

    }

  }

  return;

}




