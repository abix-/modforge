// Address: 0x1402c5810
// Ghidra name: FUN_1402c5810
// ============ 0x1402c5810 FUN_1402c5810 (size=97) ============


ulonglong FUN_1402c5810(int *param_1,int param_2)



{

  uint uVar1;

  ulonglong uVar2;

  

  if (param_2 == 8) {

    FUN_1402c5450();

  }

  else if (param_2 != 9) {

    if (param_2 == 10) {

      *param_1 = *param_1 + 1;

      FUN_1402c58b0(param_1);

      return 1;

    }

    uVar1 = param_2 - 0xb;

    uVar2 = (ulonglong)uVar1;

    if (((uVar1 != 0) && (uVar1 == 1)) && (0 < *param_1)) {

      *param_1 = *param_1 + -1;

      FUN_1402c58b0();

      return uVar2 & 0xff;

    }

  }

  FUN_1402c58b0(param_1);

  return 1;

}




