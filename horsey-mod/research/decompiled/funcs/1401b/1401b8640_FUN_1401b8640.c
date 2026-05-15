// Address: 0x1401b8640
// Ghidra name: FUN_1401b8640
// ============ 0x1401b8640 FUN_1401b8640 (size=225) ============


void FUN_1401b8640(undefined8 param_1,longlong *param_2)



{

  int iVar1;

  undefined8 *puVar2;

  longlong lVar3;

  uint uVar4;

  ulonglong uVar5;

  uint *puVar6;

  

  uVar5 = 0;

  if (*(int *)((longlong)param_2 + 0x14) != 0) {

    do {

      lVar3 = *(longlong *)(param_2[1] + uVar5 * 8);

      iVar1 = FUN_140138fe0(lVar3 + 0x30);

      if (iVar1 == 0) {

        *param_2 = lVar3;

        return;

      }

      uVar4 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar4;

    } while (uVar4 < *(uint *)((longlong)param_2 + 0x14));

  }

  puVar6 = (uint *)((longlong)param_2 + 0x14);

  lVar3 = *param_2;

  puVar2 = (undefined8 *)

           FUN_1401b5a30(param_1,*(undefined8 *)(lVar3 + 0x28),*(undefined4 *)(lVar3 + 0x24),

                         *(undefined4 *)(lVar3 + 0x20),(char)param_2[3],param_2[4]);

  if (puVar2 != (undefined8 *)0x0) {

    if (*(uint *)(param_2 + 2) <= *(int *)((longlong)param_2 + 0x14) + 1U) {

      uVar4 = *(uint *)(param_2 + 2) * 2;

      *(uint *)(param_2 + 2) = uVar4;

      lVar3 = FUN_140184230(param_2[1],(ulonglong)uVar4 << 3);

      param_2[1] = lVar3;

    }

    *(undefined8 **)(param_2[1] + (ulonglong)*puVar6 * 8) = puVar2;

    *puVar2 = param_2;

    *(uint *)(puVar2 + 1) = *puVar6;

    *puVar6 = *puVar6 + 1;

    *param_2 = (longlong)puVar2;

  }

  return;

}




