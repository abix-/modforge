// Address: 0x1401b2270
// Ghidra name: FUN_1401b2270
// ============ 0x1401b2270 FUN_1401b2270 (size=98) ============


undefined8 FUN_1401b2270(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  lVar1 = FUN_1401baca0(param_2);

  if (lVar1 != 0) {

    uVar2 = FUN_1401adc80(*(undefined4 *)(lVar1 + 0x14),*(undefined1 *)(lVar1 + 0x50));

    return uVar2;

  }

  if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Cannot get swapchain format, window has not been claimed!");

  }

  FUN_14012e850(&DAT_14039bf30,"Cannot get swapchain format, window has not been claimed!");

  return 0;

}




