// Address: 0x1401bcb70
// Ghidra name: FUN_1401bcb70
// ============ 0x1401bcb70 FUN_1401bcb70 (size=246) ============


void FUN_1401bcb70(longlong param_1,longlong *param_2)



{

  uint uVar1;

  longlong lVar2;

  uint uVar3;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  if ((char)((longlong *)*param_2)[7] != '\0') {

    lVar2 = *(longlong *)*param_2;

    if ((1 < *(uint *)(lVar2 + 0x20)) &&

       (uVar3 = *(uint *)((longlong)param_2 + 0x1c), uVar1 = uVar3,

       uVar3 < *(uint *)(lVar2 + 0x20) - 1)) {

      do {

        *(undefined8 *)((ulonglong)uVar3 * 8 + *(longlong *)(lVar2 + 0x18)) =

             *(undefined8 *)(*(longlong *)(lVar2 + 0x18) + (ulonglong)(uVar1 + 1) * 8);

        *(uint *)(*(longlong *)(*(longlong *)(*(longlong *)*param_2 + 0x18) + (ulonglong)uVar3 * 8)

                 + 0x1c) = uVar3;

        uVar3 = uVar3 + 1;

        lVar2 = *(longlong *)*param_2;

        uVar1 = uVar1 + 1;

      } while (uVar3 < *(int *)(lVar2 + 0x20) - 1U);

    }

    *(int *)(lVar2 + 0x20) = *(int *)(lVar2 + 0x20) + -1;

  }

  uVar3 = *(uint *)(*param_2 + 0x30);

  if (1 < uVar3) {

    uVar3 = uVar3 - 1;

    if (*(uint *)(param_2 + 3) != uVar3) {

      lVar2 = *(longlong *)(*param_2 + 0x28);

      *(undefined8 *)(lVar2 + (ulonglong)*(uint *)(param_2 + 3) * 8) =

           *(undefined8 *)(lVar2 + (ulonglong)uVar3 * 8);

      *(uint *)(*(longlong *)

                 (*(longlong *)(*param_2 + 0x28) + (ulonglong)*(uint *)(param_2 + 3) * 8) + 0x18) =

           *(uint *)(param_2 + 3);

    }

  }

  *(int *)(*param_2 + 0x30) = *(int *)(*param_2 + 0x30) + -1;

  *(longlong *)(*param_2 + 0x40) = *(longlong *)(*param_2 + 0x40) - param_2[2];

  FUN_1401841e0(param_2);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  return;

}




