// Address: 0x140132210
// Ghidra name: FUN_140132210
// ============ 0x140132210 FUN_140132210 (size=262) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140132210(void)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  if (DAT_1403fb5d0 != 0) {

    FUN_14017cab0(DAT_1403fb628);

    FUN_140139010(&DAT_1403fb654,1);

    lVar2 = DAT_1403fb640;

    uVar3 = DAT_1403fb630;

    DAT_1403fb630 = 0;

    DAT_1403fb640 = 0;

    FUN_140139010(&DAT_1403fb650,0);

    FUN_14017cae0(DAT_1403fb628);

    while (lVar2 != 0) {

      lVar1 = *(longlong *)(lVar2 + 8);

      FUN_1401841e0(lVar2);

      lVar2 = lVar1;

    }

    FUN_1401aafa0(uVar3);

    (*DAT_1403fb618)();

    FUN_14017ca90(DAT_1403fb628);

    DAT_1403fb5d0 = 0;

    _DAT_1403fb5d8 = 0;

    _DAT_1403fb650 = 0;

    DAT_1403fb5e0 = 0;

    DAT_1403fb5e8 = 0;

    DAT_1403fb5f0 = 0;

    DAT_1403fb5f8 = 0;

    DAT_1403fb600 = 0;

    DAT_1403fb608 = 0;

    DAT_1403fb610 = 0;

    DAT_1403fb618 = (code *)0x0;

    _DAT_1403fb620 = 0;

    DAT_1403fb628 = 0;

    DAT_1403fb630 = 0;

    _DAT_1403fb638 = 0;

    DAT_1403fb640 = 0;

    DAT_1403fb648 = 0;

  }

  return;

}




