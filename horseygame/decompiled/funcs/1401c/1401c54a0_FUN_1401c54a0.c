// Address: 0x1401c54a0
// Ghidra name: FUN_1401c54a0
// ============ 0x1401c54a0 FUN_1401c54a0 (size=104) ============


undefined4 FUN_1401c54a0(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  

  lVar1 = FUN_1401c9f40(param_2);

  if (lVar1 != 0) {

    return *(undefined4 *)(lVar1 + 0x34 + (ulonglong)*(uint *)(lVar1 + 0x2c) * 0x50);

  }

  if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Cannot get swapchain format, window has not been claimed!");

  }

  FUN_14012e850(&DAT_14039bf30,"Cannot get swapchain format, window has not been claimed!");

  return 0;

}




