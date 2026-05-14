// Address: 0x140169f50
// Ghidra name: FUN_140169f50
// ============ 0x140169f50 FUN_140169f50 (size=354) ============


undefined8 FUN_140169f50(undefined4 *param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  undefined4 *puVar2;

  uint uVar3;

  int iVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  uint uVar8;

  ulonglong uVar9;

  longlong lVar10;

  ulonglong uVar11;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined8 local_18;

  

  uStack_30 = param_2[1];

  local_28 = *(undefined4 *)(param_2 + 2);

  uStack_24 = *(undefined4 *)((longlong)param_2 + 0x14);

  uStack_20 = *(undefined4 *)(param_2 + 3);

  uStack_1c = *(undefined4 *)((longlong)param_2 + 0x1c);

  local_38 = CONCAT44((int)((ulonglong)*param_2 >> 0x20),*param_1);

  local_18 = param_2[4];

  FUN_14016bc10(&local_38);

  uVar3 = param_1[5];

  uVar11 = (ulonglong)uVar3;

  uVar9 = 0;

  lVar5 = *(longlong *)(param_1 + 6);

  if (0 < (int)uVar3) {

    do {

      iVar4 = FUN_140174340(&local_38,lVar5 + uVar9 * 0x28);

      if (iVar4 == 0) {

        return 0;

      }

      uVar8 = (int)uVar9 + 1;

      uVar9 = (ulonglong)uVar8;

    } while ((int)uVar8 < (int)uVar3);

  }

  if (uVar3 == param_1[4]) {

    lVar5 = FUN_1401841f0((longlong)(int)(param_1[4] + 0x20) * 0x28);

    if (lVar5 == 0) {

      return 0;

    }

    if (*(longlong *)(param_1 + 6) != 0) {

      FUN_1402f8e20(lVar5,*(longlong *)(param_1 + 6),(longlong)(int)uVar3 * 0x28);

      if (0 < (int)uVar3) {

        lVar7 = lVar5;

        lVar10 = *(longlong *)(param_1 + 0x12);

        do {

          lVar6 = lVar7;

          if (lVar10 != (*(longlong *)(param_1 + 6) - lVar5) + lVar7) {

            lVar6 = lVar10;

          }

          lVar7 = lVar7 + 0x28;

          uVar11 = uVar11 - 1;

          lVar10 = lVar6;

        } while (uVar11 != 0);

        *(longlong *)(param_1 + 0x12) = lVar6;

      }

      FUN_1401841e0(*(undefined8 *)(param_1 + 6));

    }

    param_1[4] = param_1[4] + 0x20;

    *(longlong *)(param_1 + 6) = lVar5;

  }

  lVar7 = (longlong)(int)param_1[5];

  param_1[5] = param_1[5] + 1;

  puVar1 = (undefined8 *)(lVar5 + lVar7 * 0x28);

  *puVar1 = local_38;

  puVar1[1] = uStack_30;

  puVar2 = (undefined4 *)(lVar5 + 0x10 + lVar7 * 0x28);

  *puVar2 = local_28;

  puVar2[1] = uStack_24;

  puVar2[2] = uStack_20;

  puVar2[3] = uStack_1c;

  *(undefined8 *)(lVar5 + 0x20 + lVar7 * 0x28) = local_18;

  FUN_140190720(*(undefined8 *)(param_1 + 6),(longlong)(int)param_1[5],0x28,FUN_140174340);

  return 1;

}




