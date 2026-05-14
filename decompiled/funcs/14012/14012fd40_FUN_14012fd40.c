// Address: 0x14012fd40
// Ghidra name: FUN_14012fd40
// ============ 0x14012fd40 FUN_14012fd40 (size=30) ============


longlong FUN_14012fd40(short *param_1)



{

  short sVar1;

  longlong lVar2;

  

  lVar2 = 0;

  sVar1 = *param_1;

  while (sVar1 != 0) {

    param_1 = param_1 + 1;

    lVar2 = lVar2 + 1;

    sVar1 = *param_1;

  }

  return lVar2;

}




