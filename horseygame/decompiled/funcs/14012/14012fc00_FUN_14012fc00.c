// Address: 0x14012fc00
// Ghidra name: FUN_14012fc00
// ============ 0x14012fc00 FUN_14012fc00 (size=80) ============


longlong FUN_14012fc00(undefined8 param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = FUN_14012fd40();

  lVar1 = lVar1 * 2 + 2;

  lVar2 = FUN_1401841f0(lVar1);

  if (lVar2 != 0) {

    FUN_1402f8e20(lVar2,param_1,lVar1);

  }

  return lVar2;

}




