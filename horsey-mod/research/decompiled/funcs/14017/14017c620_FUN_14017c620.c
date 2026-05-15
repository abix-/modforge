// Address: 0x14017c620
// Ghidra name: FUN_14017c620
// ============ 0x14017c620 FUN_14017c620 (size=77) ============


longlong FUN_14017c620(longlong param_1)



{

  longlong lVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","process");

    return 0;

  }

  lVar1 = FUN_140174d30(*(undefined4 *)(param_1 + 8),"SDL.process.stdout",0);

  if (lVar1 == 0) {

    FUN_14012e850("Process not created with standard output available");

    lVar1 = 0;

  }

  return lVar1;

}




