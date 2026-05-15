// Address: 0x1401f98d0
// Ghidra name: FUN_1401f98d0
// ============ 0x1401f98d0 FUN_1401f98d0 (size=90) ============


void FUN_1401f98d0(longlong param_1,longlong *param_2)



{

  if (param_2[1] != 0) {

    (*DAT_1403fcfb0)(*(undefined8 *)(param_1 + 0x660),param_2[1],0);

    param_2[1] = 0;

  }

  if (*param_2 != 0) {

    (*DAT_1403fd048)(*(undefined8 *)(param_1 + 0x660),*param_2,0);

  }

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  param_2[3] = 0;

  return;

}




