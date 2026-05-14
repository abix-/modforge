// Address: 0x14000d4e0
// Ghidra name: FUN_14000d4e0
// ============ 0x14000d4e0 FUN_14000d4e0 (size=365) ============


void FUN_14000d4e0(longlong param_1,uint param_2,uint param_3,undefined8 *param_4,undefined4 param_5

                  )



{

  float fVar1;

  undefined8 uVar2;

  float *pfVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  uint uVar7;

  uint uVar8;

  float local_38;

  float fStack_34;

  

  *(undefined4 *)(param_1 + 0x98) = 4;

  uVar8 = param_2 ^ DAT_14039cac0;

  iVar4 = 0;

  *(uint *)(param_1 + 0x18) = uVar8;

  uVar7 = param_3 ^ DAT_14039cac0;

  *(uint *)(param_1 + 0x1c) = uVar7;

  *(uint *)(param_1 + 0x24) = uVar7;

  *(uint *)(param_1 + 0x30) = uVar8;

  *(uint *)(param_1 + 0x20) = param_2;

  *(uint *)(param_1 + 0x28) = param_2;

  *(uint *)(param_1 + 0x2c) = param_3;

  *(uint *)(param_1 + 0x34) = param_3;

  *(undefined4 *)(param_1 + 0x58) = 0;

  *(undefined4 *)(param_1 + 0x5c) = 0xbf800000;

  *(undefined8 *)(param_1 + 0x60) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x68) = 0;

  *(undefined4 *)(param_1 + 0x6c) = 0x3f800000;

  *(undefined4 *)(param_1 + 0x70) = 0xbf800000;

  *(undefined4 *)(param_1 + 0x74) = 0;

  *(undefined8 *)(param_1 + 0x10) = *param_4;

  uVar2 = *param_4;

  fVar5 = (float)FUN_1402cdc50(param_5);

  fVar6 = (float)FUN_1402cfda0(param_5);

  if (0 < *(int *)(param_1 + 0x98)) {

    fStack_34 = (float)((ulonglong)uVar2 >> 0x20);

    pfVar3 = (float *)(param_1 + 0x5c);

    local_38 = (float)uVar2;

    do {

      iVar4 = iVar4 + 1;

      fVar1 = pfVar3[-0x11];

      pfVar3[-0x11] = (fVar1 * fVar6 - pfVar3[-0x10] * fVar5) + local_38;

      pfVar3[-0x10] = fVar1 * fVar5 + pfVar3[-0x10] * fVar6 + fStack_34;

      fVar1 = pfVar3[-1];

      pfVar3[-1] = fVar1 * fVar6 - *pfVar3 * fVar5;

      *pfVar3 = fVar1 * fVar5 + *pfVar3 * fVar6;

      pfVar3 = pfVar3 + 2;

    } while (iVar4 < *(int *)(param_1 + 0x98));

  }

  return;

}




