// Address: 0x140157130
// Ghidra name: FUN_140157130
// ============ 0x140157130 FUN_140157130 (size=206) ============


int FUN_140157130(int param_1,int param_2,longlong param_3,longlong param_4,int param_5,

                 longlong param_6,int param_7,longlong param_8,int param_9)



{

  int iVar1;

  

  if ((*(float *)(param_1 * param_5 + param_4) != *(float *)(param_2 * param_5 + param_4)) ||

     (*(float *)((longlong)(param_1 * param_5) + 4 + param_4) !=

      *(float *)((longlong)(param_2 * param_5) + 4 + param_4))) {

    return param_2;

  }

  if (param_3 != 0) {

    if (*(float *)(param_1 * param_9 + param_8) != *(float *)(param_2 * param_9 + param_8)) {

      return param_2;

    }

    if (*(float *)((longlong)(param_1 * param_9) + 4 + param_8) !=

        *(float *)((longlong)(param_2 * param_9) + 4 + param_8)) {

      return param_2;

    }

  }

  iVar1 = memcmp((void *)(param_1 * param_7 + param_6),(void *)(param_2 * param_7 + param_6),0x10);

  if (iVar1 != 0) {

    param_1 = param_2;

  }

  return param_1;

}




