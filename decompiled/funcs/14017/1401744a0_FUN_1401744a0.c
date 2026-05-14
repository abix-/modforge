// Address: 0x1401744a0
// Ghidra name: FUN_1401744a0
// ============ 0x1401744a0 FUN_1401744a0 (size=232) ============


undefined1 FUN_1401744a0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,int *param_4)



{

  undefined8 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined8 uVar5;

  char cVar6;

  longlong lVar7;

  undefined8 *puVar8;

  longlong lVar9;

  

  if (*(longlong *)(param_4 + 6) != 0) {

    return 1;

  }

  puVar1 = (undefined8 *)*param_1;

  lVar7 = FUN_14012f0d0(param_3);

  if (lVar7 != 0) {

    puVar8 = (undefined8 *)FUN_1401841f0(0x28);

    if (puVar8 == (undefined8 *)0x0) {

      FUN_1401841e0(lVar7);

    }

    else {

      uVar5 = *(undefined8 *)(param_4 + 2);

      *puVar8 = *(undefined8 *)param_4;

      puVar8[1] = uVar5;

      iVar2 = param_4[5];

      iVar3 = param_4[6];

      iVar4 = param_4[7];

      *(int *)(puVar8 + 2) = param_4[4];

      *(int *)((longlong)puVar8 + 0x14) = iVar2;

      *(int *)(puVar8 + 3) = iVar3;

      *(int *)((longlong)puVar8 + 0x1c) = iVar4;

      puVar8[4] = *(undefined8 *)(param_4 + 8);

      if (*param_4 == 2) {

        lVar9 = FUN_14012f0d0(*(undefined8 *)(param_4 + 2));

        puVar8[1] = lVar9;

        if (lVar9 == 0) {

          FUN_1401841e0(lVar7);

          FUN_1401841e0(puVar8);

          goto LAB_140174567;

        }

      }

      cVar6 = FUN_1401ab100(*puVar1,lVar7,puVar8,1);

      if (cVar6 != '\0') {

        return 1;

      }

      FUN_140174970(lVar7,puVar8,0,0);

    }

  }

LAB_140174567:

  *(undefined1 *)(param_1 + 1) = 0;

  return 1;

}




