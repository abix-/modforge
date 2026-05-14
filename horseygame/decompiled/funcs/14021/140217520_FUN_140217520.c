// Address: 0x140217520
// Ghidra name: FUN_140217520
// ============ 0x140217520 FUN_140217520 (size=34) ============


longlong FUN_140217520(void)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  

  if (DAT_1403fdb28 == '\0') {

    if (DAT_1403e5308 != -1) {

                    /* WARNING: Could not recover jumptable at 0x000140217538. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      lVar3 = TlsGetValue();

      return lVar3;

    }

    return 0;

  }

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




