// Address: 0x1401bf8b0
// Ghidra name: FUN_1401bf8b0
// ============ 0x1401bf8b0 FUN_1401bf8b0 (size=363) ============


void FUN_1401bf8b0(undefined8 *param_1,longlong param_2)



{

  uint uVar1;

  longlong lVar2;

  undefined4 uVar3;

  longlong lVar4;

  uint uVar5;

  ulonglong uVar6;

  

  lVar4 = FUN_1401baca0(param_2);

  if (lVar4 != 0) {

    if (*(undefined8 **)(lVar4 + 8) != param_1) {

      FUN_14012e850("Window not claimed by this device");

      return;

    }

    if (1 < *(int *)(lVar4 + 0x10)) {

      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + -1;

      return;

    }

    FUN_1401c0880(param_1);

    if (*(longlong *)(lVar4 + 0x90) != 0) {

      FUN_1401bf630(param_1);

    }

    if (*(longlong *)(lVar4 + 0x98) != 0) {

      FUN_1401bf630(param_1);

    }

    if (*(longlong *)(lVar4 + 0xa0) != 0) {

      FUN_1401bf630(param_1);

    }

    FUN_1401b9340(param_1,lVar4);

    (*(code *)param_1[0x134])(*param_1,*(undefined8 *)(lVar4 + 0x28),0);

    uVar6 = 0;

    *(undefined8 *)(lVar4 + 0x28) = 0;

    FUN_140179b40(param_1[0x122]);

    uVar1 = *(uint *)(param_1 + 0xf7);

    if (uVar1 != 0) {

      lVar2 = param_1[0xf6];

      do {

        if (**(longlong **)(lVar2 + uVar6 * 8) == param_2) {

          *(undefined8 *)(lVar2 + uVar6 * 8) = *(undefined8 *)(lVar2 + (ulonglong)(uVar1 - 1) * 8);

          *(int *)(param_1 + 0xf7) = *(int *)(param_1 + 0xf7) + -1;

          break;

        }

        uVar5 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar5;

      } while (uVar5 < uVar1);

    }

    FUN_140179b60(param_1[0x122]);

    FUN_1401841e0(lVar4);

    uVar3 = FUN_14016ea50(param_2);

    FUN_1401745e0(uVar3,"SDL.internal.gpu.vulkan.data");

    FUN_1401cda70(1,FUN_1401bbb00,param_2);

  }

  return;

}




