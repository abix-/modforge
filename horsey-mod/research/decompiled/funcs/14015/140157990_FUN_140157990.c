// Address: 0x140157990
// Ghidra name: FUN_140157990
// ============ 0x140157990 FUN_140157990 (size=121) ============


void FUN_140157990(longlong *param_1)



{

  if (*param_1 != 0) {

    FUN_140142b00(*param_1,FUN_14015bf80,param_1);

  }

  if (param_1[3] != 0) {

    FUN_140142b00(param_1[3],FUN_14015bee0,param_1);

  }

  if (param_1[2] != 0) {

    FUN_1401841e0();

    param_1[2] = 0;

    param_1[1] = 0;

  }

  if (param_1[5] != 0) {

    FUN_1401841e0();

    param_1[5] = 0;

    param_1[4] = 0;

  }

  *(undefined1 *)(param_1 + 8) = 0;

  return;

}




