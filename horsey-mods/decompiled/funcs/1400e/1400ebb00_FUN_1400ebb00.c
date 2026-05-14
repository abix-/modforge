// Address: 0x1400ebb00
// Ghidra name: FUN_1400ebb00
// ============ 0x1400ebb00 FUN_1400ebb00 (size=450) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400ebb00(longlong *param_1)



{

  byte *pbVar1;

  uint uVar2;

  uint uVar3;

  longlong lVar4;

  byte bVar5;

  byte *pbVar6;

  ulonglong uVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  byte local_res8 [8];

  

  uVar10 = *(uint *)(param_1 + 2);

  iVar8 = 0;

  uVar11 = uVar10 & 7;

  if (uVar11 != 0) {

    if ((int)uVar10 < (int)uVar11) {

      uVar3 = *(uint *)((longlong)param_1 + 0x14);

      uVar9 = uVar10;

      do {

        uVar9 = uVar9 + 8;

        pbVar6 = (byte *)*param_1;

        if (pbVar6 < (byte *)param_1[1]) {

          bVar5 = *pbVar6;

          *param_1 = (longlong)(pbVar6 + 1);

          uVar2 = (uint)bVar5;

        }

        else {

          uVar2 = 0;

        }

        *(uint *)(param_1 + 2) = uVar9;

        uVar3 = uVar2 << ((byte)uVar10 & 0x1f) | uVar3;

        uVar10 = uVar10 + 8;

        *(uint *)((longlong)param_1 + 0x14) = uVar3;

      } while ((int)uVar9 < 0x19);

      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) >> (sbyte)uVar11;

      uVar10 = uVar9 - uVar11;

      *(uint *)(param_1 + 2) = uVar10;

    }

    else {

      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) >> (sbyte)uVar11;

      uVar10 = uVar10 - uVar11;

      *(uint *)(param_1 + 2) = uVar10;

    }

  }

  if (0 < (int)uVar10) {

    uVar11 = *(uint *)((longlong)param_1 + 0x14);

    pbVar6 = local_res8;

    do {

      bVar5 = (byte)uVar11;

      uVar11 = uVar11 >> 8;

      iVar8 = iVar8 + 1;

      *pbVar6 = bVar5;

      pbVar6 = pbVar6 + 1;

      uVar10 = uVar10 - 8;

      *(uint *)((longlong)param_1 + 0x14) = uVar11;

    } while (0 < (int)uVar10);

    *(uint *)(param_1 + 2) = uVar10;

  }

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

  uVar10 = (uint)local_res8[1] * 0x100 + (uint)local_res8[0];

  if ((uint)local_res8[3] * 0x100 + (uint)local_res8[2] == (uVar10 ^ 0xffff)) {

    uVar7 = (ulonglong)uVar10;

    if ((ulonglong)param_1[1] < *param_1 + uVar7) {

      _DAT_1403f4c40 = "read past buffer";

      return 0;

    }

    if ((param_1[3] + uVar7 <= (ulonglong)param_1[5]) ||

       (iVar8 = FUN_1400e8a20(param_1), iVar8 != 0)) {

      FUN_1402f8e20(param_1[3],*param_1,uVar7);

      *param_1 = *param_1 + uVar7;

      param_1[3] = param_1[3] + uVar7;

      return 1;

    }

  }

  else {

    _DAT_1403f4c40 = "zlib corrupt";

  }

  return 0;

}




