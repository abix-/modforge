// Address: 0x1401635f0
// Ghidra name: FUN_1401635f0
// ============ 0x1401635f0 FUN_1401635f0 (size=94) ============


longlong FUN_1401635f0(void)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar2 = FUN_14017ffb0();

  lVar3 = 0;

  FUN_140179b40(DAT_1403fc348);

  plVar1 = DAT_1403fc350;

  do {

    if (plVar1 == (longlong *)0x0) {

LAB_140163634:

      FUN_140179b60(DAT_1403fc348);

      return lVar3;

    }

    if (*plVar1 == lVar2) {

      lVar3 = plVar1[1];

      goto LAB_140163634;

    }

    plVar1 = (longlong *)plVar1[2];

  } while( true );

}




