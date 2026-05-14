// Address: 0x1401b8810
// Ghidra name: FUN_1401b8810
// ============ 0x1401b8810 FUN_1401b8810 (size=270) ============


void FUN_1401b8810(longlong param_1,longlong param_2,uint param_3)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  uint uVar5;

  ulonglong uVar6;

  

  lVar1 = *(longlong *)(*(longlong *)(param_2 + 8) + (ulonglong)param_3 * 8);

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  uVar3 = *(uint *)(param_1 + 0x930);

  uVar4 = 0;

  if (uVar3 != 0) {

    lVar2 = *(longlong *)(param_1 + 0x928);

    uVar6 = uVar4;

    do {

      if (lVar1 == *(longlong *)(lVar2 + uVar6 * 8)) {

        *(undefined8 *)(lVar2 + uVar6 * 8) = *(undefined8 *)(lVar2 + (ulonglong)(uVar3 - 1) * 8);

        *(int *)(param_1 + 0x930) = *(int *)(param_1 + 0x930) + -1;

        break;

      }

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

    } while (uVar5 < uVar3);

  }

  if (*(int *)(lVar1 + 0x30) != 0) {

    do {

      FUN_1401bcb70(param_1,*(undefined8 *)(*(longlong *)(lVar1 + 0x28) + uVar4 * 8));

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(lVar1 + 0x30));

  }

  FUN_1401841e0(*(undefined8 *)(lVar1 + 0x28));

  FUN_1401841e0(*(undefined8 *)(lVar1 + 0x18));

  (**(code **)(param_1 + 0xc08))(*(undefined8 *)(param_1 + 0x570),*(undefined8 *)(lVar1 + 8),0);

  FUN_140179b30(*(undefined8 *)(lVar1 + 0x58));

  FUN_1401841e0(lVar1);

  uVar3 = *(int *)(param_2 + 0x10) - 1;

  if (param_3 != uVar3) {

    *(undefined8 *)(*(longlong *)(param_2 + 8) + (ulonglong)param_3 * 8) =

         *(undefined8 *)(*(longlong *)(param_2 + 8) + (ulonglong)uVar3 * 8);

  }

  *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + -1;

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  return;

}




