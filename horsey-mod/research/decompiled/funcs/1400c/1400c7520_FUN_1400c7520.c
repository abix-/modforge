// Address: 0x1400c7520
// Ghidra name: FUN_1400c7520
// ============ 0x1400c7520 FUN_1400c7520 (size=55) ============


longlong FUN_1400c7520(int param_1)



{

  if (param_1 == -1) {

    FUN_1400c4340("accessing record -1");

    return DAT_1403f34e0;

  }

  return (longlong)param_1 * 0x88 + DAT_1403f34e0;

}




