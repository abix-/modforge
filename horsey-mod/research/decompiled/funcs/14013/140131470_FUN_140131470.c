// Address: 0x140131470
// Ghidra name: FUN_140131470
// ============ 0x140131470 FUN_140131470 (size=217) ============


void FUN_140131470(longlong param_1,char param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int local_18 [2];

  int *local_10;

  

  if (param_1 != 0) {

    local_10 = (int *)0x0;

    iVar3 = -1;

    if (param_2 != '\0') {

      iVar3 = 1;

    }

    FUN_140130b40();

    piVar2 = local_18;

    if (*(int *)(param_1 + 0x1cc) != iVar3) {

      *(int *)(param_1 + 0x1cc) = iVar3;

      piVar1 = (int *)FUN_1401841f0();

      if (piVar1 != (int *)0x0) {

        *piVar1 = 0x1403 - (uint)(param_2 != '\0');

        piVar1[1] = *(int *)(param_1 + 0x6c);

        piVar1[2] = 0;

        piVar1[3] = 0;

        piVar2 = piVar1;

        local_10 = piVar1;

      }

    }

    FUN_140130b70(param_1);

    if (local_10 != (int *)0x0) {

      FUN_14017cab0(DAT_1403fb628);

      *(int **)(DAT_1403fb648 + 2) = local_10;

      DAT_1403fb648 = piVar2;

      FUN_14017cae0(DAT_1403fb628);

    }

  }

  return;

}




