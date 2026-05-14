// Address: 0x14012fc50
// Ghidra name: FUN_14012fc50
// ============ 0x14012fc50 FUN_14012fc50 (size=113) ============


longlong FUN_14012fc50(longlong param_1,undefined8 param_2,ulonglong param_3)



{

  ulonglong uVar1;

  longlong lVar2;

  

  uVar1 = FUN_14012fd40();

  lVar2 = FUN_14012fd40(param_2);

  if (uVar1 < param_3) {

    FUN_14012fcd0(param_1 + uVar1 * 2,param_2,param_3 - uVar1);

  }

  return lVar2 + uVar1;

}




