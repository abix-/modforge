// Address: 0x14012c810
// Ghidra name: thunk_FUN_14012c940
// ============ 0x14012c810 thunk_FUN_14012c940 (size=5) ============


bool thunk_FUN_14012c940(undefined8 param_1,undefined4 *param_2)



{

  longlong lVar1;

  undefined4 auStackX_10 [6];

  

  auStackX_10[0] = 0;

  lVar1 = FUN_14012c730(param_1,auStackX_10,4);

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = auStackX_10[0];

  }

  return lVar1 == 4;

}




