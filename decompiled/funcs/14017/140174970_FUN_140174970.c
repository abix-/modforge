// Address: 0x140174970
// Ghidra name: FUN_140174970
// ============ 0x140174970 FUN_140174970 (size=103) ============


void FUN_140174970(undefined8 param_1,int *param_2,undefined8 param_3,char param_4)



{

  if (param_2 != (int *)0x0) {

    if (*param_2 == 1) {

      if ((*(code **)(param_2 + 6) != (code *)0x0) && (param_4 != '\0')) {

        (**(code **)(param_2 + 6))(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 2));

      }

    }

    else if (*param_2 == 2) {

      FUN_1401841e0(*(undefined8 *)(param_2 + 2));

    }

    FUN_1401841e0(*(undefined8 *)(param_2 + 4));

  }

  FUN_1401841e0(param_1);

  FUN_1401841e0(param_2);

  return;

}




