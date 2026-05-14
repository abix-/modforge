// Address: 0x1402c4f80
// Ghidra name: FUN_1402c4f80
// ============ 0x1402c4f80 FUN_1402c4f80 (size=137) ============


void FUN_1402c4f80(longlong param_1)



{

  FUN_140179b40(DAT_1403fdeb8);

  if (DAT_1403fdec0 != '\0') {

    *(undefined4 *)(param_1 + 0x38) = 2;

    FUN_1402c4c90(param_1);

    FUN_140179b60(DAT_1403fdeb8);

    return;

  }

  *(undefined **)(param_1 + 0x78) = &DAT_1403fded0;

  *(longlong *)(param_1 + 0x80) = DAT_1403fdf50;

  if (DAT_1403fdf50 != 0) {

    *(longlong *)(DAT_1403fdf50 + 0x78) = param_1;

  }

  DAT_1403fdf50 = param_1;

  FUN_1402c4e10();

  FUN_140160220(DAT_1403fdf58);

  FUN_140179b60(DAT_1403fdeb8);

  return;

}




