// Address: 0x140163140
// Ghidra name: FUN_140163140
// ============ 0x140163140 FUN_140163140 (size=83) ============


void FUN_140163140(undefined4 param_1,undefined4 param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_1401611a0();

  if (*(code **)(lVar1 + 0x38) != (code *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x000140163176. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(lVar1 + 0x38))(param_1,param_2);

    return;

  }

  FUN_14012e850("That operation is not supported");

  return;

}




