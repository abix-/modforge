// Address: 0x1402842c0
// Ghidra name: FUN_1402842c0
// ============ 0x1402842c0 FUN_1402842c0 (size=211) ============


undefined4 FUN_1402842c0(undefined8 *param_1,undefined4 param_2)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  byte bVar4;

  uint uVar5;

  ulonglong uVar6;

  int iVar7;

  ulonglong uVar8;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined4 local_10;

  

  pfVar3 = (float *)&local_38;

  *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)((longlong)param_1 + 0x2c) * 4) = param_2;

  bVar4 = *(byte *)((longlong)param_1 + 0x2d);

  uVar5 = *(byte *)((longlong)param_1 + 0x2c) + 1;

  *(char *)((longlong)param_1 + 0x2c) = (char)uVar5 + (char)(uVar5 / 0xb) * -0xb;

  if (bVar4 < 0xb) {

    bVar4 = bVar4 + 1;

    *(byte *)((longlong)param_1 + 0x2d) = bVar4;

  }

  local_10 = *(undefined4 *)(param_1 + 5);

  local_38 = *param_1;

  uStack_30 = param_1[1];

  local_18 = param_1[4];

  local_28 = param_1[2];

  uStack_20 = param_1[3];

  if (0 < (int)(bVar4 - 1)) {

    iVar7 = 1;

    uVar8 = (ulonglong)(bVar4 - 1);

    do {

      if (iVar7 < (int)(uint)bVar4) {

        uVar6 = (ulonglong)((uint)bVar4 - iVar7);

        pfVar2 = pfVar3;

        do {

          pfVar2 = pfVar2 + 1;

          fVar1 = *pfVar3;

          if (*pfVar2 < fVar1) {

            *pfVar3 = *pfVar2;

            *pfVar2 = fVar1;

          }

          uVar6 = uVar6 - 1;

        } while (uVar6 != 0);

      }

      pfVar3 = pfVar3 + 1;

      iVar7 = iVar7 + 1;

      uVar8 = uVar8 - 1;

    } while (uVar8 != 0);

  }

  return *(undefined4 *)((longlong)&local_38 + (ulonglong)(bVar4 >> 1) * 4);

}




