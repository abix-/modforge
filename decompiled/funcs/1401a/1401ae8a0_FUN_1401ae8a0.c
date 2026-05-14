// Address: 0x1401ae8a0
// Ghidra name: FUN_1401ae8a0
// ============ 0x1401ae8a0 FUN_1401ae8a0 (size=167) ============


void FUN_1401ae8a0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  uint uVar3;

  ulonglong uVar4;

  

  (**(code **)(*(longlong *)(param_1 + 0x110) + 0xa30))

            (*(undefined8 *)(param_1 + 0x118),1,*(undefined8 *)(param_2 + 0x20));

  *(longlong *)(param_1 + 0x158) = param_2;

  FUN_1401bd890(param_1,param_2);

  uVar4 = 0;

  if (*(int *)(*(longlong *)(param_2 + 0x28) + 0x34) != 0) {

    do {

      lVar1 = param_1 + uVar4 * 8;

      if (*(longlong *)(lVar1 + 0x9e0) == 0) {

        uVar2 = FUN_1401b2970(param_1);

        *(undefined8 *)(lVar1 + 0x9e0) = uVar2;

      }

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(*(longlong *)(param_2 + 0x28) + 0x34));

  }

  *(undefined4 *)(param_1 + 0x24e) = 0x1010101;

  return;

}




