// Address: 0x1402118e0
// Ghidra name: FUN_1402118e0
// ============ 0x1402118e0 FUN_1402118e0 (size=417) ============


void FUN_1402118e0(longlong param_1,longlong param_2,int param_3)



{

  uint *puVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint *puVar5;

  longlong lVar6;

  longlong lVar7;

  longlong lVar8;

  

  lVar7 = (longlong)param_3;

  param_2 = param_2 - param_1;

  lVar8 = 0;

  if (3 < lVar7) {

    lVar6 = (lVar7 - 4U >> 2) + 1;

    lVar8 = lVar6 * 4;

    puVar5 = (uint *)(param_1 + 4);

    do {

      iVar2 = *(int *)(param_2 + -4 + (longlong)puVar5);

      puVar1 = puVar5 + 4;

      uVar3 = iVar2 + 0xf800000;

      uVar4 = iVar2 + 0x40800000;

      uVar4 = (int)(uVar4 ^ uVar3) >> 0x1f & uVar4;

      puVar5[-1] = (int)uVar4 >> 0x1f ^ (int)(float)(uVar3 - uVar4);

      iVar2 = *(int *)(param_2 + -0x10 + (longlong)puVar1);

      uVar3 = iVar2 + 0xf800000;

      uVar4 = iVar2 + 0x40800000;

      uVar4 = (int)(uVar4 ^ uVar3) >> 0x1f & uVar4;

      *puVar5 = (int)uVar4 >> 0x1f ^ (int)(float)(uVar3 - uVar4);

      iVar2 = *(int *)(param_2 + -0xc + (longlong)puVar1);

      uVar3 = iVar2 + 0xf800000;

      uVar4 = iVar2 + 0x40800000;

      uVar4 = (int)(uVar4 ^ uVar3) >> 0x1f & uVar4;

      puVar5[1] = (int)uVar4 >> 0x1f ^ (int)(float)(uVar3 - uVar4);

      iVar2 = *(int *)(param_2 + -8 + (longlong)puVar1);

      uVar3 = iVar2 + 0xf800000;

      uVar4 = iVar2 + 0x40800000;

      uVar4 = (int)(uVar4 ^ uVar3) >> 0x1f & uVar4;

      puVar5[2] = (int)uVar4 >> 0x1f ^ (int)(float)(uVar3 - uVar4);

      lVar6 = lVar6 + -1;

      puVar5 = puVar1;

    } while (lVar6 != 0);

  }

  if (lVar8 < lVar7) {

    lVar7 = lVar7 - lVar8;

    puVar5 = (uint *)(param_1 + lVar8 * 4);

    do {

      uVar3 = *(int *)(param_2 + (longlong)puVar5) + 0xf800000;

      uVar4 = *(int *)(param_2 + (longlong)puVar5) + 0x40800000;

      uVar4 = (int)(uVar4 ^ uVar3) >> 0x1f & uVar4;

      *puVar5 = (int)uVar4 >> 0x1f ^ (int)(float)(uVar3 - uVar4);

      lVar7 = lVar7 + -1;

      puVar5 = puVar5 + 1;

    } while (lVar7 != 0);

  }

  return;

}




