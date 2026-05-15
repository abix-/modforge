// Address: 0x1401bb6b0
// Ghidra name: FUN_1401bb6b0
// ============ 0x1401bb6b0 FUN_1401bb6b0 (size=154) ============


void FUN_1401bb6b0(longlong *param_1)



{

  uint uVar1;

  uint uVar2;

  longlong lVar3;

  ulonglong uVar4;

  

  uVar4 = 0;

  *(undefined1 *)(param_1 + 7) = 0;

  if ((int)param_1[6] != 0) {

    do {

      lVar3 = *param_1;

      if ((1 < *(uint *)(lVar3 + 0x20)) &&

         (uVar2 = *(uint *)(*(longlong *)(param_1[5] + uVar4 * 8) + 0x1c), uVar1 = uVar2,

         uVar2 < *(uint *)(lVar3 + 0x20) - 1)) {

        do {

          *(undefined8 *)((ulonglong)uVar2 * 8 + *(longlong *)(lVar3 + 0x18)) =

               *(undefined8 *)(*(longlong *)(lVar3 + 0x18) + (ulonglong)(uVar1 + 1) * 8);

          *(uint *)(*(longlong *)(*(longlong *)(*param_1 + 0x18) + (ulonglong)uVar2 * 8) + 0x1c) =

               uVar2;

          uVar2 = uVar2 + 1;

          lVar3 = *param_1;

          uVar1 = uVar1 + 1;

        } while (uVar2 < *(int *)(lVar3 + 0x20) - 1U);

      }

      *(int *)(lVar3 + 0x20) = *(int *)(lVar3 + 0x20) + -1;

      uVar2 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar2;

    } while (uVar2 < *(uint *)(param_1 + 6));

  }

  return;

}




