// Address: 0x1401d3710
// Ghidra name: FUN_1401d3710
// ============ 0x1401d3710 FUN_1401d3710 (size=253) ============


void FUN_1401d3710(longlong param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,

                  int *param_7,int *param_8,int *param_9)



{

  int iVar1;

  

  iVar1 = -*(int *)(param_1 + 0x10);

  if (param_5 == 0) {

    iVar1 = *(int *)(param_1 + 0x10);

  }

  if (param_4 != 0) {

    param_2 = -param_2;

  }

  if (param_3 == 0) {

    *param_6 = param_2;

    *param_7 = iVar1 - param_2 * *(int *)(param_1 + 8);

    *param_9 = 1;

    *param_8 = 1;

  }

  else if (param_3 == 1) {

    *param_6 = -iVar1;

    *param_7 = param_2 - -iVar1 * *(int *)(param_1 + 0xc);

    *param_8 = 1;

    *param_9 = -1;

  }

  else if (param_3 == 2) {

    *param_6 = -param_2;

    *param_7 = -(-param_2 * *(int *)(param_1 + 8) + iVar1);

    *param_9 = -1;

    *param_8 = -1;

  }

  else {

    *param_6 = iVar1;

    *param_7 = -(iVar1 * *(int *)(param_1 + 0xc) + param_2);

    *param_8 = -1;

    *param_9 = 1;

  }

  if (param_4 != 0) {

    *param_8 = -*param_8;

  }

  if (param_5 != 0) {

    *param_9 = -*param_9;

  }

  return;

}




