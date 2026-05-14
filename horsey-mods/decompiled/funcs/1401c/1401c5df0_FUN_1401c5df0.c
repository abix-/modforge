// Address: 0x1401c5df0
// Ghidra name: FUN_1401c5df0
// ============ 0x1401c5df0 FUN_1401c5df0 (size=148) ============


undefined8 FUN_1401c5df0(longlong param_1,int param_2,undefined4 *param_3)



{

  undefined4 *puVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  char cVar7;

  longlong lVar8;

  

  lVar2 = *(longlong *)(param_1 + 0x160 + (longlong)param_2 * 8);

  FUN_140179b40(*(undefined8 *)(lVar2 + 0x20));

  if (*(int *)(lVar2 + 0x14) == 0) {

    cVar7 = FUN_1401c9e50(param_1,lVar2);

    if (cVar7 == '\0') {

      FUN_140179b60(*(undefined8 *)(lVar2 + 0x20));

      return 0;

    }

  }

  lVar3 = *(longlong *)(lVar2 + 0x18);

  lVar8 = (ulonglong)(*(int *)(lVar2 + 0x14) - 1) * 0x20;

  puVar1 = (undefined4 *)(lVar8 + lVar3);

  uVar4 = puVar1[1];

  uVar5 = puVar1[2];

  uVar6 = puVar1[3];

  *param_3 = *puVar1;

  param_3[1] = uVar4;

  param_3[2] = uVar5;

  param_3[3] = uVar6;

  puVar1 = (undefined4 *)(lVar8 + 0x10 + lVar3);

  uVar4 = puVar1[1];

  uVar5 = puVar1[2];

  uVar6 = puVar1[3];

  param_3[4] = *puVar1;

  param_3[5] = uVar4;

  param_3[6] = uVar5;

  param_3[7] = uVar6;

  *(int *)(lVar2 + 0x14) = *(int *)(lVar2 + 0x14) + -1;

  FUN_140179b60(*(undefined8 *)(lVar2 + 0x20));

  return 1;

}




