// Address: 0x1401a40b0
// Ghidra name: FUN_1401a40b0
// ============ 0x1401a40b0 FUN_1401a40b0 (size=841) ============


undefined8 FUN_1401a40b0(longlong *param_1)



{

  int iVar1;

  byte *pbVar2;

  int iVar3;

  undefined8 uVar4;

  uint *puVar5;

  byte bVar6;

  byte bVar7;

  uint uVar8;

  int iVar9;

  longlong lVar10;

  longlong *plVar11;

  

  iVar3 = FUN_14019f260(*param_1);

  lVar10 = *param_1;

  pbVar2 = *(byte **)(lVar10 + 0xc0);

  if (pbVar2 < *(byte **)(lVar10 + 200)) {

    bVar6 = *pbVar2;

    *(byte **)(lVar10 + 0xc0) = pbVar2 + 1;

  }

  else if (*(int *)(lVar10 + 0x30) == 0) {

    bVar6 = 0;

  }

  else {

    FUN_1401a4400(lVar10);

    bVar6 = **(byte **)(lVar10 + 0xc0);

    *(byte **)(lVar10 + 0xc0) = *(byte **)(lVar10 + 0xc0) + 1;

  }

  uVar8 = (uint)bVar6;

  *(uint *)((longlong)param_1 + 0x4854) = uVar8;

  if (((3 < uVar8 - 1) ||

      ((uint)bVar6 != *(uint *)(*param_1 + 8) && (int)*(uint *)(*param_1 + 8) <= (int)uVar8)) ||

     (iVar3 != (uint)bVar6 * 2 + 6)) {

    uVar4 = FUN_14019f050("Corrupt JPEG");

    return uVar4;

  }

  iVar3 = 0;

  if (bVar6 != 0) {

    plVar11 = param_1 + 0x90b;

    do {

      lVar10 = *param_1;

      pbVar2 = *(byte **)(lVar10 + 0xc0);

      if (pbVar2 < *(byte **)(lVar10 + 200)) {

        bVar6 = *pbVar2;

        *(byte **)(lVar10 + 0xc0) = pbVar2 + 1;

      }

      else if (*(int *)(lVar10 + 0x30) == 0) {

        bVar6 = 0;

      }

      else {

        FUN_1401a4400(lVar10);

        bVar6 = **(byte **)(lVar10 + 0xc0);

        *(byte **)(lVar10 + 0xc0) = *(byte **)(lVar10 + 0xc0) + 1;

      }

      lVar10 = *param_1;

      pbVar2 = *(byte **)(lVar10 + 0xc0);

      if (pbVar2 < *(byte **)(lVar10 + 200)) {

        bVar7 = *pbVar2;

        *(byte **)(lVar10 + 0xc0) = pbVar2 + 1;

      }

      else if (*(int *)(lVar10 + 0x30) == 0) {

        bVar7 = 0;

      }

      else {

        FUN_1401a4400(lVar10);

        bVar7 = **(byte **)(lVar10 + 0xc0);

        *(byte **)(lVar10 + 0xc0) = *(byte **)(lVar10 + 0xc0) + 1;

      }

      iVar9 = 0;

      lVar10 = 0;

      iVar1 = *(int *)(*param_1 + 8);

      if (0 < iVar1) {

        puVar5 = (uint *)(param_1 + 0x8d4);

        do {

          if (*puVar5 == (uint)bVar6) goto LAB_1401a4235;

          iVar9 = iVar9 + 1;

          lVar10 = lVar10 + 1;

          puVar5 = puVar5 + 0x18;

        } while (iVar9 < iVar1);

      }

      if (iVar9 == iVar1) {

        return 0;

      }

LAB_1401a4235:

      *(uint *)(param_1 + lVar10 * 0xc + 0x8d6) = (uint)(bVar7 >> 4);

      if ((3 < bVar7 >> 4) ||

         (*(uint *)(lVar10 * 0x60 + 0x46b4 + (longlong)param_1) = bVar7 & 0xf, 3 < (bVar7 & 0xf)))

      goto LAB_1401a43b6;

      *(int *)plVar11 = iVar9;

      iVar3 = iVar3 + 1;

      plVar11 = (longlong *)((longlong)plVar11 + 4);

    } while (iVar3 < *(int *)((longlong)param_1 + 0x4854));

  }

  lVar10 = *param_1;

  pbVar2 = *(byte **)(lVar10 + 0xc0);

  if (pbVar2 < *(byte **)(lVar10 + 200)) {

    bVar6 = *pbVar2;

    *(byte **)(lVar10 + 0xc0) = pbVar2 + 1;

  }

  else if (*(int *)(lVar10 + 0x30) == 0) {

    bVar6 = 0;

  }

  else {

    FUN_1401a4400(lVar10);

    bVar6 = **(byte **)(lVar10 + 0xc0);

    *(byte **)(lVar10 + 0xc0) = *(byte **)(lVar10 + 0xc0) + 1;

  }

  lVar10 = *param_1;

  *(uint *)((longlong)param_1 + 0x4834) = (uint)bVar6;

  pbVar2 = *(byte **)(lVar10 + 0xc0);

  if (pbVar2 < *(byte **)(lVar10 + 200)) {

    bVar6 = *pbVar2;

    *(byte **)(lVar10 + 0xc0) = pbVar2 + 1;

  }

  else if (*(int *)(lVar10 + 0x30) == 0) {

    bVar6 = 0;

  }

  else {

    FUN_1401a4400(lVar10);

    bVar6 = **(byte **)(lVar10 + 0xc0);

    *(byte **)(lVar10 + 0xc0) = *(byte **)(lVar10 + 0xc0) + 1;

  }

  lVar10 = *param_1;

  *(uint *)(param_1 + 0x907) = (uint)bVar6;

  pbVar2 = *(byte **)(lVar10 + 0xc0);

  if (pbVar2 < *(byte **)(lVar10 + 200)) {

    bVar6 = *pbVar2;

    *(byte **)(lVar10 + 0xc0) = pbVar2 + 1;

  }

  else if (*(int *)(lVar10 + 0x30) == 0) {

    bVar6 = 0;

  }

  else {

    FUN_1401a4400(lVar10);

    bVar6 = **(byte **)(lVar10 + 0xc0);

    *(byte **)(lVar10 + 0xc0) = *(byte **)(lVar10 + 0xc0) + 1;

  }

  iVar3 = *(int *)((longlong)param_1 + 0x4834);

  bVar7 = bVar6 >> 4;

  *(uint *)((longlong)param_1 + 0x483c) = (uint)bVar7;

  *(uint *)(param_1 + 0x908) = bVar6 & 0xf;

  if ((int)param_1[0x906] == 0) {

    if (((iVar3 == 0) && (bVar7 == 0)) && ((bVar6 & 0xf) == 0)) {

      *(undefined4 *)(param_1 + 0x907) = 0x3f;

      return 1;

    }

  }

  else if ((((iVar3 < 0x40) && ((int)param_1[0x907] < 0x40)) && (iVar3 <= (int)param_1[0x907])) &&

          ((bVar7 < 0xe && ((bVar6 & 0xf) < 0xe)))) {

    return 1;

  }

LAB_1401a43b6:

  uVar4 = FUN_14019f050("Corrupt JPEG");

  return uVar4;

}




