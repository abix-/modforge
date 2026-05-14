// Address: 0x140272050
// Ghidra name: FUN_140272050
// ============ 0x140272050 FUN_140272050 (size=92) ============


void FUN_140272050(longlong param_1,int param_2)



{

  undefined1 auVar1 [16];

  longlong lVar2;

  

  if (param_2 < 0) {

    param_2 = 0;

  }

  else {

    auVar1._8_8_ = 0;

    auVar1._0_8_ = (longlong)param_2;

    lVar2 = SUB168(ZEXT816(0x2492492492492493) * auVar1,8);

    param_2 = param_2 + (int)(((ulonglong)(param_2 - lVar2) >> 1) + lVar2 >> 2) * -7;

  }

  lVar2 = (longlong)param_2 * 3;

  *(undefined1 *)(param_1 + 2) = (&DAT_14037f208)[lVar2];

  *(undefined1 *)(param_1 + 3) = (&DAT_14037f209)[lVar2];

  *(undefined1 *)(param_1 + 4) = (&DAT_14037f20a)[lVar2];

  return;

}




