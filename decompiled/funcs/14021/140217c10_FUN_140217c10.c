// Address: 0x140217c10
// Ghidra name: FUN_140217c10
// ============ 0x140217c10 FUN_140217c10 (size=217) ============


undefined8 *

FUN_140217c10(longlong param_1,undefined8 *param_2,longlong param_3,undefined8 param_4,

             undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)



{

  undefined8 *puVar1;

  

  puVar1 = (undefined8 *)FUN_140217610(param_1 + 0x28);

  if (puVar1 != (undefined8 *)0x0) {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    puVar1[6] = 0;

    puVar1[7] = 0;

    puVar1[8] = 0;

    puVar1[9] = 0;

    puVar1[10] = 0;

    puVar1[0xb] = 0;

    puVar1[0xc] = 0;

    puVar1[0xd] = 0;

    puVar1[0xe] = 0;

    if (param_3 != 0) {

      FUN_1402f8e20(puVar1 + 0xb,param_3,(longlong)*(int *)((longlong)param_2 + 4) << 2);

      puVar1[2] = puVar1 + 0xb;

    }

    *puVar1 = *param_2;

    *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(param_2 + 1);

    puVar1[5] = param_8;

    puVar1[6] = param_7;

    puVar1[9] = param_5;

    puVar1[10] = param_6;

    puVar1[7] = param_4;

    puVar1[8] = 0;

  }

  return puVar1;

}




