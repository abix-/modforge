// Address: 0x140221c70
// Ghidra name: FUN_140221c70
// ============ 0x140221c70 FUN_140221c70 (size=276) ============


undefined1 FUN_140221c70(longlong param_1,longlong *param_2)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  longlong lVar5;

  int *piVar6;

  int iVar7;

  undefined1 uVar8;

  

  uVar8 = 0;

  uVar3 = (**(code **)(*param_2 + 0x18))(param_2);

  FUN_140179b40(*(undefined8 *)(param_1 + 0x28));

  iVar7 = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    puVar4 = *(undefined8 **)(param_1 + 0x18);

    do {

      puVar1 = (undefined8 *)*puVar4;

      if ((puVar1 != (undefined8 *)0x0) && ((longlong *)*puVar1 == param_2)) {

        *(undefined1 *)((longlong)puVar1 + 0x1d) = 0;

        uVar8 = 1;

        goto LAB_140221d61;

      }

      iVar7 = iVar7 + 1;

      puVar4 = puVar4 + 1;

    } while (iVar7 < *(int *)(param_1 + 0x10));

  }

  piVar6 = (int *)(param_1 + 0x10);

  puVar4 = (undefined8 *)FUN_1401841a0(1,0x30);

  if (puVar4 != (undefined8 *)0x0) {

    lVar5 = FUN_140184230(*(undefined8 *)(param_1 + 0x18),(longlong)*(int *)(param_1 + 0x10) * 8 + 8

                         );

    if (lVar5 == 0) {

      FUN_1401841e0(puVar4);

    }

    else {

      (**(code **)(*param_2 + 8))(param_2);

      *puVar4 = param_2;

      uVar2 = FUN_1401aa810();

      *(undefined4 *)(puVar4 + 3) = uVar2;

      uVar8 = 1;

      puVar4[1] = uVar3;

      *(longlong *)(param_1 + 0x18) = lVar5;

      *(undefined8 **)(lVar5 + (longlong)*piVar6 * 8) = puVar4;

      *piVar6 = *piVar6 + 1;

    }

  }

LAB_140221d61:

  FUN_140179b60(*(undefined8 *)(param_1 + 0x28));

  return uVar8;

}




