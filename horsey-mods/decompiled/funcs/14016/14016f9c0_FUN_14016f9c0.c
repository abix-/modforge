// Address: 0x14016f9c0
// Ghidra name: FUN_14016f9c0
// ============ 0x14016f9c0 FUN_14016f9c0 (size=117) ============


void FUN_14016f9c0(longlong param_1)



{

  longlong lVar1;

  

  FUN_14016a310();

  FUN_14016a520(param_1);

  FUN_14016a570(param_1);

  if (((*(uint *)(param_1 + 0x48) >> 0x1e & 1) != 0) && (*(longlong *)(DAT_1403fc410 + 0x168) != 0))

  {

    lVar1 = FUN_140174d30(*(undefined4 *)(param_1 + 0x178),"SDL.window.shape",0);

    if (lVar1 != 0) {

                    /* WARNING: Could not recover jumptable at 0x00014016fa2c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(DAT_1403fc410 + 0x168))

                (DAT_1403fc410,param_1,lVar1,*(code **)(DAT_1403fc410 + 0x168));

      return;

    }

  }

  return;

}




