// Address: 0x140279910
// Ghidra name: FUN_140279910
// ============ 0x140279910 FUN_140279910 (size=298) ============


void FUN_140279910(undefined8 param_1,undefined8 param_2,ushort *param_3,char param_4,ushort param_5

                  )



{

  ushort uVar1;

  ushort uVar2;

  ushort uVar3;

  ulonglong uVar4;

  ushort uVar5;

  float fVar6;

  

  uVar1 = param_3[2];

  uVar4 = 0;

  if (uVar1 == 0) {

    param_3[2] = param_5;

    return;

  }

  uVar5 = *param_3;

  if (param_5 < *param_3) {

    *param_3 = param_5;

    uVar5 = param_5;

  }

  uVar3 = param_3[1];

  if (param_3[1] < param_5) {

    param_3[1] = param_5;

    uVar3 = param_5;

  }

  uVar2 = param_3[3];

  if ((int)(uint)param_5 < (int)((uint)uVar1 - (uint)uVar2)) {

    fVar6 = ((float)(ushort)((uVar1 - uVar2) - param_5) / (float)(ushort)((uVar1 - uVar2) - uVar5))

            * DAT_14037dea8;

  }

  else {

    if ((uint)param_5 <= (uint)uVar2 + (uint)uVar1) goto LAB_140279a00;

    fVar6 = ((float)(ushort)(param_5 - (uVar1 + uVar2)) / (float)(ushort)(uVar3 - (uVar1 + uVar2)))

            * DAT_1403053f0;

  }

  uVar4 = (ulonglong)(uint)(int)fVar6;

LAB_140279a00:

  if (((param_4 - 1U & 0xfd) == 0) && ((ushort)uVar4 != 0)) {

    uVar4 = CONCAT62((int6)(uVar4 >> 0x10),~(ushort)uVar4);

  }

  FUN_14015aab0(param_1,param_2,param_4,uVar4);

  return;

}




