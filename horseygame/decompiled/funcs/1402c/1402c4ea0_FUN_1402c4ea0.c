// Address: 0x1402c4ea0
// Ghidra name: FUN_1402c4ea0
// ============ 0x1402c4ea0 FUN_1402c4ea0 (size=212) ============


undefined8 FUN_1402c4ea0(void)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  cVar1 = FUN_140163c40(&DAT_1403fdea0);

  if (cVar1 != '\0') {

    iVar2 = FUN_14017fc50();

    DAT_1403fdf60 = iVar2 * 2 + 1;

    if (DAT_1403fdf60 < 1) {

      DAT_1403fdf60 = 1;

    }

    else if (8 < DAT_1403fdf60) {

      DAT_1403fdf60 = 8;

    }

    DAT_1403fdeb8 = FUN_140179a30();

    if (((DAT_1403fdeb8 == 0) || (DAT_1403fdf58 = FUN_140160230(), DAT_1403fdf58 == 0)) ||

       (cVar1 = FUN_1402c4e10(), cVar1 == '\0')) {

      uVar3 = 0;

      if (DAT_1403fdf58 != 0) {

        FUN_140160350(DAT_1403fdf58);

        DAT_1403fdf58 = 0;

      }

      if (DAT_1403fdeb8 != 0) {

        FUN_140179b30();

        DAT_1403fdeb8 = 0;

      }

    }

    else {

      uVar3 = 1;

    }

    FUN_140163ab0(&DAT_1403fdea0,uVar3);

    return uVar3;

  }

  return 1;

}




