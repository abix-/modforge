// Address: 0x1400ef4c0
// Ghidra name: FUN_1400ef4c0
// ============ 0x1400ef4c0 FUN_1400ef4c0 (size=992) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400ef4c0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  undefined1 *puVar3;

  byte bVar4;

  undefined1 uVar5;

  int iVar6;

  uint uVar7;

  byte *pbVar8;

  uint uVar9;

  uint uVar10;

  ulonglong uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  ulonglong uVar15;

  int iVar16;

  uint local_res8;

  uint local_res20;

  ulonglong local_40;

  

  pbVar8 = *(byte **)(param_1 + 0xb8);

  if (pbVar8 < *(byte **)(param_1 + 0xc0)) {

    bVar4 = *pbVar8;

    *(byte **)(param_1 + 0xb8) = pbVar8 + 1;

  }

  else if (*(int *)(param_1 + 0x30) == 0) {

    bVar4 = 0;

  }

  else {

    FUN_1400ed820();

    bVar4 = **(byte **)(param_1 + 0xb8);

    *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

  }

  uVar15 = 1;

  local_res20 = 1;

  local_res8 = 0;

  uVar7 = 1 << (bVar4 & 0x1f);

  iVar2 = bVar4 + 1;

  iVar16 = 0;

  uVar10 = (1 << ((byte)iVar2 & 0x1f)) - 1;

  iVar6 = 0;

  if (0 < 1 << (bVar4 & 0x1f)) {

    puVar3 = (undefined1 *)(param_2 + 0x826);

    do {

      *puVar3 = (char)iVar6;

      puVar3[1] = (char)iVar6;

      iVar6 = iVar6 + 1;

      *(undefined2 *)(puVar3 + -2) = 0xffff;

      puVar3 = puVar3 + 4;

    } while (iVar6 < (int)uVar7);

  }

  uVar13 = 0xffffffff;

  uVar11 = (ulonglong)(int)(uVar7 + 2);

  uVar9 = 0;

  iVar6 = iVar2;

  local_40 = uVar11;

  while( true ) {

    while( true ) {

      for (; iVar16 < iVar6; iVar16 = iVar16 + 8) {

        if (uVar9 == 0) {

          pbVar8 = *(byte **)(param_1 + 0xb8);

          if (*(byte **)(param_1 + 0xc0) <= pbVar8) {

            if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400ef887;

            FUN_1400ed820(param_1);

            pbVar8 = *(byte **)(param_1 + 0xb8);

          }

          bVar4 = *pbVar8;

          *(byte **)(param_1 + 0xb8) = pbVar8 + 1;

          uVar9 = (uint)bVar4;

          if (bVar4 == 0) goto LAB_1400ef887;

        }

        pbVar8 = *(byte **)(param_1 + 0xb8);

        uVar9 = uVar9 - 1;

        if (pbVar8 < *(byte **)(param_1 + 0xc0)) {

          bVar4 = *pbVar8;

          *(byte **)(param_1 + 0xb8) = pbVar8 + 1;

          uVar12 = (uint)bVar4;

        }

        else if (*(int *)(param_1 + 0x30) == 0) {

          uVar12 = 0;

        }

        else {

          FUN_1400ed820(param_1);

          bVar4 = **(byte **)(param_1 + 0xb8);

          *(byte **)(param_1 + 0xb8) = *(byte **)(param_1 + 0xb8) + 1;

          uVar12 = (uint)bVar4;

        }

        uVar15 = (ulonglong)local_res20;

        bVar4 = (byte)iVar16;

        local_res8 = local_res8 | uVar12 << (bVar4 & 0x1f);

      }

      uVar12 = (int)local_res8 >> ((byte)iVar6 & 0x1f);

      uVar14 = local_res8 & uVar10;

      iVar16 = iVar16 - iVar6;

      local_res8 = uVar12;

      if (uVar14 != uVar7) break;

      local_40 = (longlong)(int)uVar7 + 2;

      uVar11 = (ulonglong)(uVar7 + 2);

      uVar10 = (1 << ((byte)iVar2 & 0x1f)) - 1;

      uVar13 = 0xffffffff;

      uVar15 = 0;

      local_res20 = 0;

      iVar6 = iVar2;

    }

    if (uVar14 == uVar7 + 1) {

      if ((*(longlong *)(param_1 + 0x10) == 0) ||

         (iVar2 = *(int *)(param_1 + 0xc0) - *(int *)(param_1 + 0xb8), (int)uVar9 <= iVar2)) {

        *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + (longlong)(int)uVar9;

      }

      else {

        *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

        (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),uVar9 - iVar2);

      }

      goto LAB_1400ef800;

    }

    uVar12 = (uint)uVar11;

    if ((int)uVar12 < (int)uVar14) break;

    if ((int)uVar15 != 0) {

      _DAT_1403f4c40 = "no clear code";

      return 0;

    }

    if ((int)uVar13 < 0) {

      if (uVar14 == uVar12) break;

    }

    else {

      lVar1 = local_40 * 4;

      uVar12 = uVar12 + 1;

      uVar11 = (ulonglong)uVar12;

      local_40 = local_40 + 1;

      if (0x1000 < (int)uVar12) {

        _DAT_1403f4c40 = "too many codes";

        return 0;

      }

      *(short *)(lVar1 + 0x824 + param_2) = (short)uVar13;

      uVar5 = *(undefined1 *)(param_2 + 0x826 + (longlong)(int)uVar13 * 4);

      *(undefined1 *)(lVar1 + 0x826 + param_2) = uVar5;

      if (uVar14 != uVar12) {

        uVar5 = *(undefined1 *)(param_2 + 0x826 + (longlong)(int)uVar14 * 4);

      }

      *(undefined1 *)(lVar1 + 0x827 + param_2) = uVar5;

    }

    uVar13 = uVar14;

    FUN_1400ef110(param_2,uVar14 & 0xffff);

    if (((uVar10 & (uint)uVar11) == 0) && ((int)(uint)uVar11 < 0x1000)) {

      iVar6 = iVar6 + 1;

      uVar10 = (1 << ((byte)iVar6 & 0x1f)) - 1;

    }

  }

  _DAT_1403f4c40 = "illegal code in raster";

  return 0;

LAB_1400ef800:

  pbVar8 = *(byte **)(param_1 + 0xb8);

  if (pbVar8 < *(byte **)(param_1 + 0xc0)) {

    bVar4 = *pbVar8;

  }

  else {

    if (*(int *)(param_1 + 0x30) == 0) {

LAB_1400ef887:

      return *(undefined8 *)(param_2 + 8);

    }

    FUN_1400ed820(param_1);

    pbVar8 = *(byte **)(param_1 + 0xb8);

    bVar4 = *pbVar8;

  }

  pbVar8 = pbVar8 + 1;

  *(byte **)(param_1 + 0xb8) = pbVar8;

  if (bVar4 == 0) goto LAB_1400ef887;

  if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ef877:

    *(byte **)(param_1 + 0xb8) = pbVar8 + bVar4;

  }

  else {

    iVar2 = *(int *)(param_1 + 0xc0) - (int)pbVar8;

    if ((int)(uint)bVar4 <= iVar2) goto LAB_1400ef877;

    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),(uint)bVar4 - iVar2);

  }

  goto LAB_1400ef800;

}




