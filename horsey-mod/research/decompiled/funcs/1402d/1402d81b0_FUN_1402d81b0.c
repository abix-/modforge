// Address: 0x1402d81b0
// Ghidra name: FUN_1402d81b0
// ============ 0x1402d81b0 FUN_1402d81b0 (size=451) ============


double FUN_1402d81b0(undefined8 param_1,int *param_2)



{

  longlong lVar1;

  undefined4 *puVar2;

  ulonglong uVar3;

  double dVar4;

  undefined1 in_XMM0 [16];

  

  dVar4 = in_XMM0._0_8_;

  if (param_2 == (int *)0x0) {

    puVar2 = (undefined4 *)FUN_1402e68b0();

    *puVar2 = 0x16;

    FUN_1402cd454();

    return 0.0;

  }

  if (((ulonglong)dVar4 & 0x7ff0000000000000) == 0x7ff0000000000000) {

    *param_2 = -1;

    if ((((longlong)dVar4 + 0x10000000000000U & 0x7fffffffffffffff) != 0) &&

       (((ulonglong)dVar4 & 0x7ff8000000000000) != 0x7ff8000000000000)) {

      FUN_1402e8c20(0x1f80,0xffc0);

      dVar4 = (double)FUN_1402eb2f0(8);

      return dVar4;

    }

  }

  else {

    if (dVar4 == 0.0) {

      *param_2 = 0;

      return dVar4;

    }

    if ((((ulonglong)dVar4 & 0x7ff0000000000000) == 0) &&

       (((ulonglong)dVar4 & 0xfffffffffffff) != 0)) {

      uVar3 = (ulonglong)dVar4 & 0xfffffffffffff;

      lVar1 = 0x3f;

      if (uVar3 != 0) {

        for (; uVar3 >> lVar1 == 0; lVar1 = lVar1 + -1) {

        }

      }

      uVar3 = uVar3 << (0x34U - (char)lVar1 & 0x3f) & 0xffefffffffffffff;

      *param_2 = (int)lVar1 + -0x431;

      if (dVar4 < 0.0) {

        uVar3 = uVar3 | 0x8000000000000000;

      }

      return (double)(uVar3 & 0xbfefffffffffffff | 0x3fe0000000000000);

    }

    dVar4 = (double)((ulonglong)dVar4 & 0xbfefffffffffffff | 0x3fe0000000000000);

    *param_2 = (in_XMM0._4_4_ >> 0x14 & 0x7ff) - 0x3fe;

  }

  return dVar4;

}




