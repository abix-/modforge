// Address: 0x140139320
// Ghidra name: FUN_140139320
// ============ 0x140139320 FUN_140139320 (size=203) ============


void FUN_140139320(int *param_1)



{

  longlong *plVar1;

  longlong lVar2;

  

  FUN_14013ba20();

  lVar2 = *(longlong *)(param_1 + 0x22);

  plVar1 = (longlong *)(param_1 + 0x24);

  if (lVar2 != 0) {

    *(longlong *)(lVar2 + 0x90) = *plVar1;

  }

  if (*plVar1 != 0) {

    *(longlong *)(*plVar1 + 0x88) = *(longlong *)(param_1 + 0x22);

  }

  if (param_1 == DAT_1403fbeb8) {

    DAT_1403fbeb8 = (int *)*plVar1;

  }

  if (param_1 == DAT_1403fbec0) {

    DAT_1403fbec0 = *(int **)(param_1 + 0x22);

  }

  if (*param_1 == 0x7f00) {

    FUN_140138fb0(&DAT_1403fb690,0xffffffff);

  }

  *(int **)(param_1 + 0x24) = DAT_1403fbec8;

  DAT_1403fbec8 = param_1;

  FUN_140138fb0(&DAT_1403fbeac,0xffffffff);

  return;

}




