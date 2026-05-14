// Address: 0x14013b580
// Ghidra name: FUN_14013b580
// ============ 0x14013b580 FUN_14013b580 (size=75) ============


void FUN_14013b580(void)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_14016dcf0();

  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x248) != 0)) {

    lVar2 = FUN_140139020(lVar1 + 800,0);

    if (lVar2 != 0) {

                    /* WARNING: Could not recover jumptable at 0x00014013b5c2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(lVar1 + 0x248))(lVar1,lVar2,*(code **)(lVar1 + 0x248));

      return;

    }

  }

  return;

}




