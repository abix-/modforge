// Address: 0x1402c5170
// Ghidra name: FUN_1402c5170
// ============ 0x1402c5170 FUN_1402c5170 (size=311) ============


void FUN_1402c5170(void)



{

  longlong lVar1;

  char cVar2;

  

  cVar2 = FUN_140163cb0(&DAT_1403fdea0);

  if (cVar2 == '\0') {

    return;

  }

  FUN_140179b40(DAT_1403fdeb8);

  lVar1 = DAT_1403fdf50;

  while (DAT_1403fdf50 = lVar1, lVar1 != 0) {

    if (*(longlong *)(lVar1 + 0x80) != 0) {

      *(undefined8 *)(*(longlong *)(lVar1 + 0x80) + 0x78) = *(undefined8 *)(lVar1 + 0x78);

    }

    *(undefined8 *)(*(longlong *)(lVar1 + 0x78) + 0x80) = *(undefined8 *)(lVar1 + 0x80);

    *(undefined8 *)(lVar1 + 0x80) = 0;

    *(undefined8 *)(lVar1 + 0x78) = 0;

    *(undefined4 *)(lVar1 + 0x38) = 2;

    FUN_1402c4c90(lVar1);

    lVar1 = DAT_1403fdf50;

  }

  DAT_1403fdec0 = 1;

  FUN_140160220(DAT_1403fdf58);

  while (0 < DAT_1403fdf64) {

    FUN_140163d40(DAT_1403fdf58,DAT_1403fdeb8);

  }

  FUN_140179b60(DAT_1403fdeb8);

  FUN_140179b30(DAT_1403fdeb8);

  DAT_1403fdeb8 = 0;

  FUN_140160350(DAT_1403fdf58);

  DAT_1403fdf58 = 0;

  DAT_1403fdf6c = 0;

  DAT_1403fdf68 = 0;

  DAT_1403fdf64 = 0;

  DAT_1403fdf60 = 0;

  DAT_1403fdec0 = 0;

  FUN_140163ab0(&DAT_1403fdea0,0);

  return;

}




