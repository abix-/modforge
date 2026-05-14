// Address: 0x1401c31e0
// Ghidra name: FUN_1401c31e0
// ============ 0x1401c31e0 FUN_1401c31e0 (size=307) ============


void FUN_1401c31e0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  *(longlong *)(param_1 + 0x1d0) = param_2;

  (**(code **)(**(longlong **)(param_1 + 0x120) + 200))

            (*(longlong **)(param_1 + 0x120),*(undefined8 *)(param_2 + 0x20));

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0xf0))

            (*(longlong **)(param_1 + 0x120),**(undefined8 **)(param_2 + 0x28));

  (**(code **)(**(longlong **)(param_1 + 0x120) + 0xa0))

            (*(longlong **)(param_1 + 0x120),

             *(undefined4 *)(&DAT_1403e4a00 + (longlong)*(int *)(param_2 + 0x30) * 4));

  *(undefined4 *)(param_1 + 0x211) = 0x1010101;

  uVar5 = 0;

  *(undefined4 *)(param_1 + 0x218) = 0x1010101;

  *(undefined2 *)(param_1 + 0x215) = 0x101;

  *(undefined2 *)(param_1 + 0x21c) = 0x101;

  *(undefined1 *)(param_1 + 0x217) = 1;

  *(undefined1 *)(param_1 + 0x21e) = 1;

  uVar4 = uVar5;

  if (*(int *)(param_2 + 0xc) != 0) {

    do {

      lVar1 = param_1 + uVar4 * 8;

      if (*(longlong *)(lVar1 + 0x470) == 0) {

        uVar2 = FUN_1401c5990(param_1);

        *(undefined8 *)(lVar1 + 0x470) = uVar2;

      }

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_2 + 0xc));

  }

  if (*(int *)(param_2 + 0x1c) != 0) {

    do {

      lVar1 = param_1 + uVar5 * 8;

      if (*(longlong *)(lVar1 + 0x610) == 0) {

        uVar2 = FUN_1401c5990(param_1);

        *(undefined8 *)(lVar1 + 0x610) = uVar2;

      }

      uVar3 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_2 + 0x1c));

  }

  FUN_1401cb7c0(param_1,param_2);

  return;

}




