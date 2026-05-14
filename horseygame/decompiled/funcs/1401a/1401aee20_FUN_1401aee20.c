// Address: 0x1401aee20
// Ghidra name: FUN_1401aee20
// ============ 0x1401aee20 FUN_1401aee20 (size=253) ============


void FUN_1401aee20(longlong param_1,longlong param_2)



{

  undefined8 uVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  (**(code **)(*(longlong *)(param_1 + 0x110) + 0xa30))

            (*(undefined8 *)(param_1 + 0x118),0,*(undefined8 *)(param_2 + 0x20));

  *(longlong *)(param_1 + 0x160) = param_2;

  FUN_1401bd9f0(param_1,param_2);

  lVar2 = *(longlong *)(param_2 + 0x30);

  uVar5 = 0;

  uVar4 = uVar5;

  if (*(int *)(lVar2 + 0x34) != 0) {

    do {

      lVar2 = param_1 + uVar4 * 8;

      if (*(longlong *)(lVar2 + 0x9a0) == 0) {

        uVar1 = FUN_1401b2970(param_1);

        *(undefined8 *)(lVar2 + 0x9a0) = uVar1;

      }

      lVar2 = *(longlong *)(param_2 + 0x30);

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(lVar2 + 0x34));

  }

  if (*(int *)(lVar2 + 0x44) != 0) {

    do {

      lVar2 = param_1 + uVar5 * 8;

      if (*(longlong *)(lVar2 + 0x9c0) == 0) {

        uVar1 = FUN_1401b2970(param_1);

        *(undefined8 *)(lVar2 + 0x9c0) = uVar1;

      }

      uVar3 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(*(longlong *)(param_2 + 0x30) + 0x44));

  }

  *(undefined2 *)(param_1 + 0x248) = 0x101;

  *(undefined2 *)(param_1 + 0x24b) = 0x101;

  *(undefined1 *)(param_1 + 0x24a) = 1;

  *(undefined1 *)(param_1 + 0x24d) = 1;

  return;

}




