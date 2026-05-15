// Address: 0x14020f770
// Ghidra name: FUN_14020f770
// ============ 0x14020f770 FUN_14020f770 (size=101) ============


void FUN_14020f770(void)



{

  if (DAT_1403fd3b0 != (longlong *)0x0) {

    if (DAT_1403fd3b8 != 0) {

      (**(code **)(*DAT_1403fd3b0 + 0x68))(DAT_1403fd3b0,DAT_1403fd3b8,10000);

      DAT_1403fd3b8 = 0;

    }

    while (0 < DAT_1403fd3a8) {

      FUN_140210810(0);

    }

    FUN_140289330();

    DAT_1403fd3b0 = (longlong *)0x0;

  }

  return;

}




