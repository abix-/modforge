// Address: 0x14012e680
// Ghidra name: FUN_14012e680
// ============ 0x14012e680 FUN_14012e680 (size=138) ============


void FUN_14012e680(uint param_1,uint param_2)



{

  uint *puVar1;

  

  FUN_14012dec0();

  FUN_140179b40(DAT_1403fb510);

  puVar1 = DAT_1403fb520;

  if (((int)param_1 < 0) || (0x12 < param_1)) {

    for (; puVar1 != (uint *)0x0; puVar1 = *(uint **)(puVar1 + 2)) {

      if (*puVar1 == param_1) goto LAB_14012e6f1;

    }

    puVar1 = (uint *)FUN_1401841f0(0x10);

    if (puVar1 != (uint *)0x0) {

      *(uint **)(puVar1 + 2) = DAT_1403fb520;

      *puVar1 = param_1;

      DAT_1403fb520 = puVar1;

LAB_14012e6f1:

      puVar1[1] = param_2;

    }

  }

  else {

    (&DAT_1403fb530)[(int)param_1] = param_2;

  }

  FUN_140179b60(DAT_1403fb510);

  return;

}




