// Address: 0x14013e010
// Ghidra name: FUN_14013e010
// ============ 0x14013e010 FUN_14013e010 (size=292) ============


undefined8 * FUN_14013e010(undefined8 *param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  undefined8 *puVar2;

  int iVar3;

  longlong lVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined8 uVar8;

  char cVar9;

  undefined8 *puVar10;

  undefined8 *puVar11;

  int iVar12;

  longlong lVar13;

  undefined8 *puVar14;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  FUN_140159d30();

  if (param_1 != (undefined8 *)0x0) {

    if (DAT_1403e3d60 != '\0') {

      cVar9 = FUN_1401aa7c0(param_1);

      if (cVar9 == '\0') goto LAB_14013e10f;

    }

    cVar9 = FUN_1401596f0(*param_1);

    if (cVar9 != '\0') {

      iVar3 = *(int *)(param_1 + 5);

      puVar10 = (undefined8 *)FUN_1401841f0((longlong)iVar3 * 0x28 + 8);

      if (puVar10 != (undefined8 *)0x0) {

        iVar12 = 0;

        puVar11 = puVar10 + (longlong)iVar3 + 1;

        if (0 < *(int *)(param_1 + 5)) {

          lVar13 = 0;

          puVar14 = puVar10;

          do {

            *puVar14 = puVar11;

            puVar14 = puVar14 + 1;

            lVar4 = param_1[6];

            iVar12 = iVar12 + 1;

            puVar1 = (undefined4 *)(lVar13 + lVar4);

            uVar5 = puVar1[1];

            uVar6 = puVar1[2];

            uVar7 = puVar1[3];

            *(undefined4 *)puVar11 = *puVar1;

            *(undefined4 *)((longlong)puVar11 + 4) = uVar5;

            *(undefined4 *)(puVar11 + 1) = uVar6;

            *(undefined4 *)((longlong)puVar11 + 0xc) = uVar7;

            puVar2 = (undefined8 *)(lVar13 + 0x10 + lVar4);

            uVar8 = puVar2[1];

            puVar11[2] = *puVar2;

            puVar11[3] = uVar8;

            puVar11 = puVar11 + 4;

            lVar13 = lVar13 + 0x20;

          } while (iVar12 < *(int *)(param_1 + 5));

        }

        puVar10[iVar12] = 0;

        if (param_2 != (undefined4 *)0x0) {

          *param_2 = *(undefined4 *)(param_1 + 5);

        }

      }

      FUN_14015bb10();

      return puVar10;

    }

  }

LAB_14013e10f:

  FUN_14012e850("Parameter \'%s\' is invalid","gamepad");

  FUN_14015bb10();

  return (undefined8 *)0x0;

}




