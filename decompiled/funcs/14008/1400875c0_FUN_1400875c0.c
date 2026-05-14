// Address: 0x1400875c0
// Ghidra name: FUN_1400875c0
// ============ 0x1400875c0 FUN_1400875c0 (size=244) ============


void FUN_1400875c0(undefined4 *param_1,float param_2,float param_3,float param_4,undefined4 param_5,

                  char param_6)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = (longlong)param_6;

  lVar2 = lVar1 * 0x118;

  FUN_140072640(param_5);

  FUN_1400734c0(*param_1);

  FUN_140072100(*param_1,(float)(int)*(char *)(lVar2 + 0x26 + (longlong)param_1) * param_4 + param_2

                ,(float)(int)*(char *)(lVar2 + 0x27 + (longlong)param_1) * param_4 + param_3,

                (float)(int)*(char *)(param_1 + lVar1 * 0x46 + 9) * param_4,

                (float)(int)*(char *)(lVar2 + 0x25 + (longlong)param_1) * param_4,

                param_1[lVar1 * 0x46 + 4],param_1[lVar1 * 0x46 + 5],param_1[lVar1 * 0x46 + 6],

                param_1[lVar1 * 0x46 + 7]);

  return;

}




