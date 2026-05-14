// Address: 0x1401a22f0
// Ghidra name: FUN_1401a22f0
// ============ 0x1401a22f0 FUN_1401a22f0 (size=683) ============


undefined8 FUN_1401a22f0(ulonglong *param_1)



{

  undefined1 uVar1;

  ushort uVar2;

  ulonglong uVar3;

  int iVar4;

  uint uVar5;

  undefined8 uVar6;

  undefined1 *puVar7;

  undefined1 *puVar8;

  uint uVar9;

  ulonglong uVar10;

  int iVar11;

  

  puVar8 = (undefined1 *)param_1[4];

  while( true ) {

    while( true ) {

      if ((int)param_1[2] < 0x10) {

        if (*param_1 < param_1[1]) {

          FUN_14019f170(param_1);

        }

        else {

          if (*(int *)((longlong)param_1 + 0x14) != 0) goto LAB_1401a2556;

          *(undefined4 *)((longlong)param_1 + 0x14) = 1;

          *(int *)(param_1 + 2) = (int)param_1[2] + 0x10;

        }

      }

      uVar2 = *(ushort *)((longlong)param_1 + (ulonglong)((uint)param_1[3] & 0x1ff) * 2 + 0x3c);

      if (uVar2 == 0) {

        uVar9 = FUN_1401a5120(param_1,(longlong)param_1 + 0x3c);

      }

      else {

        *(uint *)(param_1 + 2) = (int)param_1[2] - (uint)(uVar2 >> 9);

        *(uint *)(param_1 + 3) = (uint)param_1[3] >> ((byte)(uVar2 >> 9) & 0x1f);

        uVar9 = uVar2 & 0x1ff;

      }

      if (0xff < (int)uVar9) break;

      if ((int)uVar9 < 0) goto LAB_1401a2556;

      if ((undefined1 *)param_1[6] <= puVar8) {

        iVar4 = FUN_1401a5050(param_1,puVar8,1);

        if (iVar4 == 0) {

          return 0;

        }

        puVar8 = (undefined1 *)param_1[4];

      }

      *puVar8 = (char)uVar9;

      puVar8 = puVar8 + 1;

    }

    if (uVar9 == 0x100) break;

    if (0x11d < (int)uVar9) goto LAB_1401a2556;

    iVar4 = *(int *)(&DAT_14033b06c + (longlong)(int)uVar9 * 4);

    uVar9 = *(uint *)("This function should be called on the main thread" +

                     (longlong)(int)uVar9 * 4 + 0xc);

    if (iVar4 != 0) {

      if ((int)param_1[2] < iVar4) {

        FUN_14019f170(param_1);

      }

      uVar10 = param_1[3];

      *(int *)(param_1 + 2) = (int)param_1[2] - iVar4;

      *(uint *)(param_1 + 3) = (uint)uVar10 >> ((byte)iVar4 & 0x1f);

      uVar9 = uVar9 + ((1 << ((byte)iVar4 & 0x1f)) - 1U & (uint)uVar10);

    }

    uVar10 = (ulonglong)uVar9;

    if ((int)param_1[2] < 0x10) {

      if (*param_1 < param_1[1]) {

        FUN_14019f170(param_1);

      }

      else {

        if (*(int *)((longlong)param_1 + 0x14) != 0) goto LAB_1401a2556;

        *(undefined4 *)((longlong)param_1 + 0x14) = 1;

        *(int *)(param_1 + 2) = (int)param_1[2] + 0x10;

      }

    }

    uVar2 = *(ushort *)((longlong)param_1 + (ulonglong)((uint)param_1[3] & 0x1ff) * 2 + 0x820);

    if (uVar2 == 0) {

      uVar5 = FUN_1401a5120(param_1,param_1 + 0x104);

    }

    else {

      *(uint *)(param_1 + 2) = (int)param_1[2] - (uint)(uVar2 >> 9);

      *(uint *)(param_1 + 3) = (uint)param_1[3] >> ((byte)(uVar2 >> 9) & 0x1f);

      uVar5 = uVar2 & 0x1ff;

    }

    if (0x1d < uVar5) goto LAB_1401a2556;

    iVar4 = *(int *)(&DAT_14033b570 + (longlong)(int)uVar5 * 4);

    iVar11 = *(int *)(&DAT_14033b4f0 + (longlong)(int)uVar5 * 4);

    if (iVar4 != 0) {

      if ((int)param_1[2] < iVar4) {

        FUN_14019f170(param_1);

      }

      uVar3 = param_1[3];

      *(int *)(param_1 + 2) = (int)param_1[2] - iVar4;

      *(uint *)(param_1 + 3) = (uint)uVar3 >> ((byte)iVar4 & 0x1f);

      iVar11 = iVar11 + ((1 << ((byte)iVar4 & 0x1f)) - 1U & (uint)uVar3);

    }

    if ((longlong)((longlong)puVar8 - param_1[5]) < (longlong)iVar11) goto LAB_1401a2556;

    if ((longlong)(param_1[6] - (longlong)puVar8) < (longlong)(int)uVar9) {

      iVar4 = FUN_1401a5050(param_1,puVar8,uVar10);

      if (iVar4 == 0) {

        return 0;

      }

      puVar8 = (undefined1 *)param_1[4];

    }

    puVar7 = puVar8 + -(longlong)iVar11;

    if (iVar11 == 1) {

      if (uVar9 != 0) {

        FUN_1402f94c0(puVar8,*puVar7,uVar10);

        puVar8 = puVar8 + uVar10;

      }

    }

    else {

      while (uVar9 != 0) {

        uVar1 = *puVar7;

        puVar7 = puVar7 + 1;

        *puVar8 = uVar1;

        puVar8 = puVar8 + 1;

        uVar9 = (int)uVar10 - 1;

        uVar10 = (ulonglong)uVar9;

      }

    }

  }

  param_1[4] = (ulonglong)puVar8;

  if ((*(int *)((longlong)param_1 + 0x14) == 0) || (0xf < (int)param_1[2])) {

    return 1;

  }

LAB_1401a2556:

  uVar6 = FUN_14019f050("Corrupt PNG");

  return uVar6;

}




