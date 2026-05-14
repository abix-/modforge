// Address: 0x14029fd70
// Ghidra name: FUN_14029fd70
// ============ 0x14029fd70 FUN_14029fd70 (size=139) ============


void FUN_14029fd70(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  if (*param_1 == 1) {

    FUN_1402a1fa0(param_2,param_3,param_4,param_1[2]);

  }

  else if (*param_1 == 2) {

    if (*(longlong *)(param_1 + 4) != 0) {

      FUN_140179fa0(param_2,param_3,param_4);

    }

    FUN_1402a1f50(param_2,param_3,param_4,param_1[2],param_1[3]);

  }

  return;

}




