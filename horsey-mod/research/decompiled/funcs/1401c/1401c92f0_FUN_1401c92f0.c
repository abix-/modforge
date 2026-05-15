// Address: 0x1401c92f0
// Ghidra name: FUN_1401c92f0
// ============ 0x1401c92f0 FUN_1401c92f0 (size=262) ============


void FUN_1401c92f0(longlong param_1,undefined4 *param_2)



{

  longlong lVar1;

  int iVar2;

  undefined8 *puVar3;

  undefined8 uVar4;

  uint uVar5;

  ulonglong uVar6;

  uint *puVar7;

  

  uVar6 = 0;

  if (param_2[9] != 0) {

    do {

      lVar1 = *(longlong *)(*(longlong *)(param_2 + 6) + uVar6 * 8);

      iVar2 = FUN_140138fe0(lVar1 + 0x88);

      if (iVar2 == 0) {

        *(longlong *)(param_2 + 4) = lVar1;

        return;

      }

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

    } while (uVar5 < (uint)param_2[9]);

  }

  puVar7 = param_2 + 9;

  puVar3 = (undefined8 *)

           FUN_1401c7580(param_1,*param_2,param_2[1],param_2[2],*(undefined8 *)(param_2 + 0x18));

  if (puVar3 != (undefined8 *)0x0) {

    if ((uint)param_2[8] <= param_2[9] + 1) {

      uVar5 = param_2[8] * 2;

      param_2[8] = uVar5;

      uVar4 = FUN_140184230(*(undefined8 *)(param_2 + 6),(ulonglong)uVar5 << 3);

      *(undefined8 *)(param_2 + 6) = uVar4;

    }

    *(undefined8 **)(*(longlong *)(param_2 + 6) + (ulonglong)*puVar7 * 8) = puVar3;

    *puVar3 = param_2;

    *(uint *)(puVar3 + 1) = *puVar7;

    *puVar7 = *puVar7 + 1;

    *(undefined8 **)(param_2 + 4) = puVar3;

    if ((*(char *)(param_1 + 0x98) != '\0') && (*(longlong *)(param_2 + 0x18) != 0)) {

      FUN_1401cb3d0(param_1,puVar3[2]);

    }

  }

  return;

}




