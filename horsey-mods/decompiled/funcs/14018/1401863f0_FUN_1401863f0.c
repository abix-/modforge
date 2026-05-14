// Address: 0x1401863f0
// Ghidra name: FUN_1401863f0
// ============ 0x1401863f0 FUN_1401863f0 (size=229) ============


longlong FUN_1401863f0(undefined8 param_1,undefined4 *param_2)



{

  undefined4 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  longlong lVar5;

  longlong lVar6;

  undefined4 *puVar7;

  longlong lVar8;

  int iVar9;

  int iVar10;

  

  if (param_2 != (undefined4 *)0x0) {

    *param_2 = 0;

  }

  FUN_140186540();

  lVar5 = FUN_140186240(param_1);

  if (lVar5 != 0) {

    lVar6 = FUN_1401841f0((longlong)*(int *)(lVar5 + 0xc) * 0x20 + 8);

    if (lVar6 != 0) {

      iVar9 = *(int *)(lVar5 + 0xc);

      iVar10 = 0;

      puVar7 = (undefined4 *)(lVar6 + ((longlong)iVar9 + 1) * 8);

      if (0 < iVar9) {

        lVar8 = 0;

        do {

          *(undefined4 **)(lVar8 + lVar6) = puVar7;

          iVar10 = iVar10 + 1;

          puVar1 = *(undefined4 **)(lVar8 + *(longlong *)(lVar5 + 0x18));

          uVar2 = puVar1[1];

          uVar3 = puVar1[2];

          uVar4 = puVar1[3];

          *puVar7 = *puVar1;

          puVar7[1] = uVar2;

          puVar7[2] = uVar3;

          puVar7[3] = uVar4;

          *(undefined8 *)(puVar7 + 4) = *(undefined8 *)(puVar1 + 4);

          puVar7 = puVar7 + 6;

          iVar9 = *(int *)(lVar5 + 0xc);

          lVar8 = lVar8 + 8;

        } while (iVar10 < iVar9);

      }

      *(undefined8 *)(lVar6 + (longlong)iVar9 * 8) = 0;

      if (param_2 != (undefined4 *)0x0) {

        *param_2 = *(undefined4 *)(lVar5 + 0xc);

      }

      FUN_140186c50();

      return lVar6;

    }

  }

  FUN_140186c50();

  return 0;

}




