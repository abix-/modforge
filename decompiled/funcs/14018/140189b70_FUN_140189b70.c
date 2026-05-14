// Address: 0x140189b70
// Ghidra name: FUN_140189b70
// ============ 0x140189b70 FUN_140189b70 (size=302) ============


undefined8 FUN_140189b70(longlong param_1,longlong *param_2,undefined4 *param_3)



{

  undefined1 *puVar1;

  undefined1 uVar2;

  undefined1 uVar3;

  ulonglong uVar4;

  int iVar5;

  undefined8 uVar6;

  longlong lVar7;

  undefined1 *puVar8;

  undefined1 *puVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  undefined1 *puVar12;

  ulonglong local_res8;

  

  local_res8 = *(ulonglong *)(param_1 + 0x58);

  iVar5 = FUN_14018a0b0(&local_res8,*(undefined2 *)(param_1 + 0x24));

  uVar11 = local_res8;

  if (iVar5 != 0) {

    uVar6 = FUN_14012e850("WAVE file too big");

    return uVar6;

  }

  iVar5 = FUN_14018a0b0(&local_res8,4);

  uVar4 = local_res8;

  if (iVar5 != 0) {

    uVar6 = FUN_14012e850("WAVE file too big");

    return uVar6;

  }

  if (local_res8 < 0x100000000) {

    uVar10 = 1;

    if (local_res8 != 0) {

      uVar10 = local_res8;

    }

    lVar7 = FUN_140184230(*(undefined8 *)(param_1 + 0x10),uVar10);

    uVar6 = 0;

    if (lVar7 != 0) {

      puVar8 = (undefined1 *)0x0;

      *(undefined8 *)(param_1 + 0x10) = 0;

      *(undefined8 *)(param_1 + 0x18) = 0;

      *param_2 = lVar7;

      *param_3 = (int)uVar4;

      if (uVar11 != 0) {

        puVar12 = (undefined1 *)(lVar7 + uVar11 * 3 + -2);

        puVar9 = (undefined1 *)(uVar11 * 4 + -3 + lVar7);

        do {

          puVar1 = puVar12 + -1;

          puVar8 = puVar9 + -4;

          uVar2 = *puVar12;

          uVar3 = puVar12[1];

          puVar12 = puVar12 + -3;

          *puVar9 = *puVar1;

          puVar9[1] = uVar2;

          puVar9[2] = uVar3;

          puVar9[-1] = 0;

          uVar11 = uVar11 - 1;

          puVar9 = puVar8;

        } while (uVar11 != 0);

      }

      uVar6 = CONCAT71((int7)((ulonglong)puVar8 >> 8),1);

    }

  }

  else {

    uVar6 = FUN_14012e850("WAVE file too big");

  }

  return uVar6;

}




