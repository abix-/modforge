// Address: 0x1402c4cf0
// Ghidra name: FUN_1402c4cf0
// ============ 0x1402c4cf0 FUN_1402c4cf0 (size=280) ============


undefined8 FUN_1402c4cf0(void)



{

  longlong lVar1;

  undefined8 uVar2;

  char cVar3;

  

  FUN_140179b40(DAT_1403fdeb8);

  lVar1 = DAT_1403fdf50;

  do {

    while( true ) {

      DAT_1403fdf50 = lVar1;

      if (DAT_1403fdec0 != '\0') goto LAB_1402c4d7a;

      if (lVar1 == 0) break;

      if (*(longlong *)(lVar1 + 0x80) != 0) {

        *(undefined8 *)(*(longlong *)(lVar1 + 0x80) + 0x78) = *(undefined8 *)(lVar1 + 0x78);

      }

      *(undefined8 *)(*(longlong *)(lVar1 + 0x78) + 0x80) = *(undefined8 *)(lVar1 + 0x80);

      uVar2 = DAT_1403fdeb8;

      *(undefined8 *)(lVar1 + 0x80) = 0;

      *(undefined8 *)(lVar1 + 0x78) = 0;

      FUN_140179b60(uVar2);

      FUN_1402c52b0(lVar1);

      FUN_140179b40(DAT_1403fdeb8);

      lVar1 = DAT_1403fdf50;

    }

    DAT_1403fdf68 = DAT_1403fdf68 + 1;

    cVar3 = FUN_140163d20(DAT_1403fdf58,DAT_1403fdeb8,30000);

    DAT_1403fdf68 = DAT_1403fdf68 + -1;

    lVar1 = DAT_1403fdf50;

  } while ((cVar3 != '\0') || (DAT_1403fdf68 == 0));

LAB_1402c4d7a:

  DAT_1403fdf64 = DAT_1403fdf64 + -1;

  if (DAT_1403fdec0 != '\0') {

    FUN_140160220(DAT_1403fdf58);

  }

  FUN_140179b60(DAT_1403fdeb8);

  return 0;

}




