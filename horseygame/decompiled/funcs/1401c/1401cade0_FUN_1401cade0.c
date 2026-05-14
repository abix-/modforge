// Address: 0x1401cade0
// Ghidra name: FUN_1401cade0
// ============ 0x1401cade0 FUN_1401cade0 (size=80) ============


void FUN_1401cade0(longlong *param_1)



{

  undefined4 *puVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  longlong lVar6;

  longlong lVar7;

  

  lVar2 = *param_1;

  if (lVar2 != 0) {

    FUN_140179b40(*(undefined8 *)(lVar2 + 0x20));

    uVar4 = *(undefined4 *)((longlong)param_1 + 4);

    lVar6 = param_1[1];

    uVar5 = *(undefined4 *)((longlong)param_1 + 0xc);

    lVar3 = *(longlong *)(lVar2 + 0x18);

    lVar7 = (ulonglong)*(uint *)(lVar2 + 0x14) * 0x20;

    puVar1 = (undefined4 *)(lVar7 + lVar3);

    *puVar1 = (int)*param_1;

    puVar1[1] = uVar4;

    puVar1[2] = (int)lVar6;

    puVar1[3] = uVar5;

    uVar4 = *(undefined4 *)((longlong)param_1 + 0x14);

    lVar6 = param_1[3];

    uVar5 = *(undefined4 *)((longlong)param_1 + 0x1c);

    puVar1 = (undefined4 *)(lVar7 + 0x10 + lVar3);

    *puVar1 = (int)param_1[2];

    puVar1[1] = uVar4;

    puVar1[2] = (int)lVar6;

    puVar1[3] = uVar5;

    *(int *)(lVar2 + 0x14) = *(int *)(lVar2 + 0x14) + 1;

    FUN_140179b60(*(undefined8 *)(lVar2 + 0x20));

  }

  return;

}




