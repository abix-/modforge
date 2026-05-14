// Address: 0x14026cdf0
// Ghidra name: FUN_14026cdf0
// ============ 0x14026cdf0 FUN_14026cdf0 (size=83) ============


void FUN_14026cdf0(longlong param_1,int param_2)



{

  *(int *)(param_1 + 0x30) = param_2;

  if (param_2 == 0) {

    *(undefined1 *)(param_1 + 0x34) = 0;

  }

  else {

    if (param_2 == 1) {

      FUN_14026cd00();

      *(undefined1 *)(param_1 + 0x34) = 1;

      FUN_14026d2c0(param_1);

      return;

    }

    if (param_2 == 2) {

      FUN_14026cd00();

      FUN_14026d2c0(param_1);

      return;

    }

  }

  FUN_14026d2c0(param_1);

  return;

}




