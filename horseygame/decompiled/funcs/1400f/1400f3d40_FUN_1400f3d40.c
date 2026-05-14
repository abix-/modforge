// Address: 0x1400f3d40
// Ghidra name: FUN_1400f3d40
// ============ 0x1400f3d40 FUN_1400f3d40 (size=240) ============


int FUN_1400f3d40(longlong param_1,int param_2,int param_3,int param_4,undefined2 param_5,

                 undefined2 param_6,int param_7,int param_8,int param_9,int param_10)



{

  longlong lVar1;

  

  lVar1 = (longlong)param_2;

  if (param_4 != 0) {

    if (param_3 != 0) {

      *(undefined1 *)(param_1 + 8 + lVar1 * 10) = 3;

      *(undefined2 *)(param_1 + 4 + lVar1 * 10) = (undefined2)param_9;

      *(short *)(param_1 + lVar1 * 10) = (short)(param_7 + param_9 >> 1);

      *(undefined2 *)(param_1 + 6 + lVar1 * 10) = (undefined2)param_10;

      *(short *)(param_1 + 2 + lVar1 * 10) = (short)(param_8 + param_10 >> 1);

      param_2 = param_2 + 1;

    }

    lVar1 = (longlong)param_2;

    *(undefined2 *)(param_1 + lVar1 * 10) = param_5;

    *(undefined2 *)(param_1 + 2 + lVar1 * 10) = param_6;

    *(short *)(param_1 + 4 + lVar1 * 10) = (short)param_7;

    *(undefined1 *)(param_1 + 8 + lVar1 * 10) = 3;

    *(short *)(param_1 + 6 + lVar1 * 10) = (short)param_8;

    return param_2 + 1;

  }

  *(undefined2 *)(param_1 + lVar1 * 10) = param_5;

  *(undefined2 *)(param_1 + 2 + lVar1 * 10) = param_6;

  if (param_3 != 0) {

    *(undefined2 *)(param_1 + 4 + lVar1 * 10) = (undefined2)param_9;

    *(undefined2 *)(param_1 + 6 + lVar1 * 10) = (undefined2)param_10;

    *(undefined1 *)(param_1 + 8 + lVar1 * 10) = 3;

    return param_2 + 1;

  }

  *(undefined1 *)(param_1 + 8 + lVar1 * 10) = 2;

  *(undefined4 *)(param_1 + 4 + lVar1 * 10) = 0;

  return param_2 + 1;

}




