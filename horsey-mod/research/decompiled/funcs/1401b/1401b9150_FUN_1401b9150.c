// Address: 0x1401b9150
// Ghidra name: FUN_1401b9150
// ============ 0x1401b9150 FUN_1401b9150 (size=175) ============


void FUN_1401b9150(longlong param_1,longlong *param_2)



{

  longlong lVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  ulonglong uVar5;

  

  uVar3 = 0;

  if ((int)param_2[1] != 0) {

    do {

      lVar1 = *param_2;

      uVar5 = 0;

      lVar2 = (ulonglong)uVar3 * 0x20;

      if (*(int *)(lVar2 + lVar1) != 0) {

        do {

          (**(code **)(param_1 + 0xb80))

                    (*(undefined8 *)(param_1 + 0x570),

                     *(undefined8 *)(*(longlong *)(lVar2 + 8 + lVar1) + uVar5 * 8),0);

          lVar1 = *param_2;

          uVar4 = (int)uVar5 + 1;

          uVar5 = (ulonglong)uVar4;

        } while (uVar4 < *(uint *)(lVar1 + lVar2));

      }

      FUN_1401841e0(*(undefined8 *)(lVar2 + 0x10 + lVar1));

      FUN_1401841e0(*(undefined8 *)(lVar2 + 8 + *param_2));

      uVar3 = uVar3 + 1;

    } while (uVar3 < *(uint *)(param_2 + 1));

  }

  FUN_1401841e0(*param_2);

  FUN_1401841e0(param_2);

  return;

}




