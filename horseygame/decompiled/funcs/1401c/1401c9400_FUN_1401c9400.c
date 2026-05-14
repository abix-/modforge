// Address: 0x1401c9400
// Ghidra name: FUN_1401c9400
// ============ 0x1401c9400 FUN_1401c9400 (size=205) ============


void FUN_1401c9400(undefined8 param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  longlong *plVar3;

  undefined8 uVar4;

  uint uVar5;

  ulonglong uVar6;

  uint *puVar7;

  

  uVar6 = 0;

  if (*(int *)(param_2 + 0x3c) != 0) {

    do {

      lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + uVar6 * 8);

      iVar2 = FUN_140138fe0(lVar1 + 0x48);

      if (iVar2 == 0) {

        *(longlong *)(param_2 + 0x28) = lVar1;

        return;

      }

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

    } while (uVar5 < *(uint *)(param_2 + 0x3c));

  }

  puVar7 = (uint *)(param_2 + 0x3c);

  plVar3 = (longlong *)FUN_1401c8b30(param_1,param_2,0,*(undefined8 *)(param_2 + 0x48));

  if (plVar3 != (longlong *)0x0) {

    if (*(uint *)(param_2 + 0x38) <= *(int *)(param_2 + 0x3c) + 1U) {

      uVar5 = *(uint *)(param_2 + 0x38) * 2;

      *(uint *)(param_2 + 0x38) = uVar5;

      uVar4 = FUN_140184230(*(undefined8 *)(param_2 + 0x30),(ulonglong)uVar5 << 3);

      *(undefined8 *)(param_2 + 0x30) = uVar4;

    }

    *(longlong **)(*(longlong *)(param_2 + 0x30) + (ulonglong)*puVar7 * 8) = plVar3;

    *plVar3 = param_2;

    *(uint *)(plVar3 + 1) = *puVar7;

    *puVar7 = *puVar7 + 1;

    *(longlong **)(param_2 + 0x28) = plVar3;

  }

  return;

}




