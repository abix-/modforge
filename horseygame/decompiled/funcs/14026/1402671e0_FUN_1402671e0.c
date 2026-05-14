// Address: 0x1402671e0
// Ghidra name: FUN_1402671e0
// ============ 0x1402671e0 FUN_1402671e0 (size=173) ============


void FUN_1402671e0(undefined8 *param_1)



{

  ulonglong uVar1;

  uint uVar2;

  ulonglong uVar3;

  

  FUN_1401841e0(param_1[10]);

  if (param_1[0xb] != 0) {

    uVar1 = 0;

    uVar3 = uVar1;

    if (*(char *)((longlong)param_1 + 9) != '\0') {

      do {

        FUN_1401841e0(*(undefined8 *)(param_1[0xb] + uVar1));

        uVar1 = uVar1 + 8;

        uVar2 = (int)uVar3 + 1;

        uVar3 = (ulonglong)uVar2;

      } while ((int)uVar2 < (int)(uint)*(byte *)((longlong)param_1 + 9));

    }

    FUN_1401841e0(param_1[0xb]);

  }

  FUN_1401841e0(param_1[0xc]);

  FUN_1401841e0(param_1[0xd]);

  FUN_1401841e0(param_1[0x10]);

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  return;

}




