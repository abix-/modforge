// Address: 0x1401a2fa0
// Ghidra name: FUN_1401a2fa0
// ============ 0x1401a2fa0 FUN_1401a2fa0 (size=328) ============


undefined8 FUN_1401a2fa0(longlong *param_1)



{

  byte *pbVar1;

  uint uVar2;

  undefined8 uVar3;

  longlong lVar4;

  byte bVar5;

  byte *pbVar6;

  ulonglong uVar7;

  int iVar8;

  uint uVar9;

  byte local_res8 [8];

  

  uVar2 = *(uint *)(param_1 + 2);

  uVar9 = uVar2 & 7;

  if (uVar9 != 0) {

    if ((int)uVar2 < (int)uVar9) {

      FUN_14019f170();

    }

    *(uint *)(param_1 + 3) = *(uint *)(param_1 + 3) >> ((byte)uVar9 & 0x1f);

    *(uint *)(param_1 + 2) = (int)param_1[2] - uVar9;

    uVar2 = *(uint *)(param_1 + 2);

  }

  iVar8 = 0;

  if (0 < (int)uVar2) {

    uVar9 = *(uint *)(param_1 + 3);

    pbVar6 = local_res8;

    do {

      bVar5 = (byte)uVar9;

      uVar9 = uVar9 >> 8;

      uVar2 = uVar2 - 8;

      *pbVar6 = bVar5;

      pbVar6 = pbVar6 + 1;

      iVar8 = iVar8 + 1;

      *(uint *)(param_1 + 3) = uVar9;

    } while (0 < (int)uVar2);

    *(uint *)(param_1 + 2) = uVar2;

  }

  if (-1 < (int)uVar2) {

    lVar4 = (longlong)iVar8;

    if (lVar4 < 4) {

      pbVar6 = (byte *)param_1[1];

      do {

        pbVar1 = (byte *)*param_1;

        if (pbVar1 < pbVar6) {

          bVar5 = *pbVar1;

          *param_1 = (longlong)(pbVar1 + 1);

        }

        else {

          bVar5 = 0;

        }

        local_res8[lVar4] = bVar5;

        lVar4 = lVar4 + 1;

      } while (lVar4 < 4);

    }

    uVar2 = (uint)local_res8[1] * 0x100 + (uint)local_res8[0];

    if ((uint)local_res8[3] * 0x100 + (uint)local_res8[2] == (uVar2 ^ 0xffff)) {

      uVar7 = (ulonglong)uVar2;

      if ((ulonglong)param_1[1] < *param_1 + uVar7) {

        uVar3 = FUN_14019f050("Corrupt PNG");

        return uVar3;

      }

      if ((ulonglong)param_1[6] < param_1[4] + (ulonglong)uVar2) {

        uVar3 = FUN_1401a5050(param_1);

        if ((int)uVar3 == 0) {

          return uVar3;

        }

      }

      FUN_1402f8e20(param_1[4],*param_1,uVar7);

      *param_1 = *param_1 + uVar7;

      param_1[4] = param_1[4] + uVar7;

      return 1;

    }

  }

  uVar3 = FUN_14019f050("Corrupt PNG");

  return uVar3;

}




