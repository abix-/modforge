// Address: 0x14019eb10
// Ghidra name: FUN_14019eb10
// ============ 0x14019eb10 FUN_14019eb10 (size=235) ============


void FUN_14019eb10(undefined8 *param_1)



{

  byte bVar1;

  int *piVar2;

  byte bVar3;

  byte *pbVar4;

  uint uVar5;

  uint uVar6;

  ulonglong uVar7;

  byte bVar8;

  

  piVar2 = (int *)*param_1;

  pbVar4 = (byte *)param_1[3];

  uVar5 = piVar2[1] * *piVar2;

  if (uVar5 != 0) {

    if (piVar2[3] == 3) {

      uVar7 = (ulonglong)uVar5;

      do {

        bVar1 = *pbVar4;

        *pbVar4 = pbVar4[2];

        pbVar4[2] = bVar1;

        pbVar4 = pbVar4 + 3;

        uVar7 = uVar7 - 1;

      } while (uVar7 != 0);

      return;

    }

    if (DAT_1403fcd38 != 0) {

      uVar7 = (ulonglong)uVar5;

      do {

        bVar1 = pbVar4[3];

        bVar8 = *pbVar4;

        bVar3 = pbVar4[2];

        if (bVar1 != 0) {

          uVar5 = (uint)bVar1;

          uVar6 = (uint)(bVar1 >> 1);

          pbVar4[1] = (byte)(((uint)pbVar4[1] * 0xff + uVar6) / uVar5);

          bVar8 = (byte)(((uint)bVar8 * 0xff + uVar6) / uVar5);

          bVar3 = (byte)(((uint)bVar3 * 0xff + uVar6) / uVar5);

        }

        *pbVar4 = bVar3;

        pbVar4[2] = bVar8;

        pbVar4 = pbVar4 + 4;

        uVar7 = uVar7 - 1;

      } while (uVar7 != 0);

      return;

    }

    uVar7 = (ulonglong)uVar5;

    do {

      bVar1 = *pbVar4;

      *pbVar4 = pbVar4[2];

      pbVar4[2] = bVar1;

      pbVar4 = pbVar4 + 4;

      uVar7 = uVar7 - 1;

    } while (uVar7 != 0);

  }

  return;

}




