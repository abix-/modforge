// Address: 0x140274560
// Ghidra name: FUN_140274560
// ============ 0x140274560 FUN_140274560 (size=92) ============


void FUN_140274560(longlong param_1,int param_2)



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

  *(undefined1 *)(param_1 + 0x2c) = (&DAT_14037f290)[lVar2];

  *(undefined1 *)(param_1 + 0x2d) = (&DAT_14037f291)[lVar2];

  *(undefined1 *)(param_1 + 0x2e) = (&DAT_14037f292)[lVar2];

  return;

}




