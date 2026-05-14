// Address: 0x1401b8730
// Ghidra name: FUN_1401b8730
// ============ 0x1401b8730 FUN_1401b8730 (size=222) ============


void FUN_1401b8730(undefined8 param_1,undefined8 param_2,longlong param_3)



{

  longlong lVar1;

  int iVar2;

  longlong *plVar3;

  undefined8 uVar4;

  uint uVar5;

  ulonglong uVar6;

  uint *puVar7;

  

  uVar6 = 0;

  if (*(int *)(param_3 + 0x34) != 0) {

    do {

      lVar1 = *(longlong *)(*(longlong *)(param_3 + 0x38) + uVar6 * 8);

      iVar2 = FUN_140138fe0(lVar1 + 0x54);

      if (iVar2 == 0) {

        *(longlong *)(param_3 + 0x28) = lVar1;

        return;

      }

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

    } while (uVar5 < *(uint *)(param_3 + 0x34));

  }

  puVar7 = (uint *)(param_3 + 0x34);

  plVar3 = (longlong *)FUN_1401b7d00(param_1,param_3);

  FUN_1401bd6c0(param_1,param_2,0,plVar3);

  if (plVar3 != (longlong *)0x0) {

    if (*(uint *)(param_3 + 0x30) <= *(int *)(param_3 + 0x34) + 1U) {

      uVar5 = *(uint *)(param_3 + 0x30) * 2;

      *(uint *)(param_3 + 0x30) = uVar5;

      uVar4 = FUN_140184230(*(undefined8 *)(param_3 + 0x38),(ulonglong)uVar5 << 3);

      *(undefined8 *)(param_3 + 0x38) = uVar4;

    }

    *(longlong **)(*(longlong *)(param_3 + 0x38) + (ulonglong)*puVar7 * 8) = plVar3;

    *plVar3 = param_3;

    *(uint *)(plVar3 + 1) = *puVar7;

    *puVar7 = *puVar7 + 1;

    *(longlong **)(param_3 + 0x28) = plVar3;

  }

  return;

}




