// Address: 0x14012df60
// Ghidra name: FUN_14012df60
// ============ 0x14012df60 FUN_14012df60 (size=144) ============


uint FUN_14012df60(uint param_1)



{

  uint *puVar1;

  uint uVar2;

  

  FUN_14012dec0();

  if ((-1 < (int)param_1) && (param_1 < 0x13)) {

    return (&DAT_1403fb530)[(int)param_1];

  }

  FUN_140179b40(DAT_1403fb510);

  puVar1 = DAT_1403fb520;

  if (((int)param_1 < 0) || (0x12 < param_1)) {

    for (; puVar1 != (uint *)0x0; puVar1 = *(uint **)(puVar1 + 2)) {

      if (*puVar1 == param_1) {

        uVar2 = puVar1[1];

        if (uVar2 != 0) goto LAB_14012dfdc;

        break;

      }

    }

    uVar2 = DAT_1403fb4f4;

  }

  else {

    uVar2 = (&DAT_1403fb530)[(int)param_1];

  }

LAB_14012dfdc:

  FUN_140179b60(DAT_1403fb510);

  return uVar2;

}




