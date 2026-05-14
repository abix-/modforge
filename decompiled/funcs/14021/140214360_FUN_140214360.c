// Address: 0x140214360
// Ghidra name: FUN_140214360
// ============ 0x140214360 FUN_140214360 (size=110) ============


longlong FUN_140214360(longlong param_1,ulonglong param_2,longlong param_3)



{

  undefined1 auVar1 [16];

  longlong lVar2;

  longlong lVar3;

  int iVar4;

  

  if (((longlong)param_2 < 1) ||

     (auVar1._8_8_ = 0, auVar1._0_8_ = param_2,

     param_1 <= SUB168((ZEXT816(0) << 0x40 | ZEXT816(0x7fffffffffffffff)) / auVar1,0))) {

    lVar3 = (param_3 - param_2) + 0x100000000;

    param_1 = param_1 * param_2;

    if ((lVar3 < 1) ||

       (param_1 - (0x7fffffffffffffff - lVar3) == 0 || param_1 < 0x7fffffffffffffff - lVar3)) {

      iVar4 = (int)((ulonglong)(param_1 + lVar3) >> 0x20);

      lVar2 = 0;

      if (iVar4 != 0 && -1 < param_1 + lVar3) {

        lVar2 = (longlong)iVar4;

      }

      return lVar2;

    }

  }

  return 0x7fffffff;

}




