// Address: 0x14017c5d0
// Ghidra name: FUN_14017c5d0
// ============ 0x14017c5d0 FUN_14017c5d0 (size=77) ============


longlong FUN_14017c5d0(longlong param_1)



{

  longlong lVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","process");

    return 0;

  }

  lVar1 = FUN_140174d30(*(undefined4 *)(param_1 + 8),"SDL.process.stdin",0);

  if (lVar1 == 0) {

    FUN_14012e850("Process not created with standard input available");

    lVar1 = 0;

  }

  return lVar1;

}




