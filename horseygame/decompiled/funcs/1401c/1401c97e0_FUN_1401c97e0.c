// Address: 0x1401c97e0
// Ghidra name: FUN_1401c97e0
// ============ 0x1401c97e0 FUN_1401c97e0 (size=1105) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401c97e0(longlong param_1)



{

  longlong *plVar1;

  ulonglong uVar2;

  uint uVar3;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  ulonglong uVar4;

  

  uVar2 = 0;

  uVar4 = uVar2;

  if (*(int *)(param_1 + 0x138) != 0) {

    do {

      FUN_1401c95c0(**(undefined8 **)(uVar4 * 8 + *(longlong *)(param_1 + 0x130)));

      FUN_1401841e0(*(undefined8 *)(*(longlong *)(param_1 + 0x130) + uVar4 * 8));

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_1 + 0x138));

  }

  if (*(longlong *)(param_1 + 0x160) != 0) {

    FUN_1401c9c60();

    *(undefined8 *)(param_1 + 0x160) = 0;

  }

  if (*(longlong *)(param_1 + 0x168) != 0) {

    FUN_1401c9c60();

    *(undefined8 *)(param_1 + 0x168) = 0;

  }

  if (*(longlong *)(param_1 + 0x170) != 0) {

    FUN_1401c9c60();

    *(undefined8 *)(param_1 + 0x170) = 0;

  }

  if (*(longlong *)(param_1 + 0x178) != 0) {

    FUN_1401c9c60();

    *(undefined8 *)(param_1 + 0x178) = 0;

  }

  if (*(longlong *)(param_1 + 0x188) != 0) {

    uVar4 = uVar2;

    if (*(int *)(param_1 + 0x184) != 0) {

      do {

        if (*(longlong *)(uVar4 * 8 + *(longlong *)(param_1 + 0x188)) != 0) {

          FUN_1401c9730();

          *(undefined8 *)(uVar4 * 8 + *(longlong *)(param_1 + 0x188)) = 0;

        }

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

      } while (uVar3 < *(uint *)(param_1 + 0x184));

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x188));

  }

  if (*(longlong *)(param_1 + 400) != 0) {

    FUN_140179b30();

    *(undefined8 *)(param_1 + 400) = 0;

  }

  if (*(longlong *)(param_1 + 0x1a0) != 0) {

    uVar4 = uVar2;

    if (*(int *)(param_1 + 0x19c) != 0) {

      do {

        if (*(longlong *)(uVar4 * 8 + *(longlong *)(param_1 + 0x1a0)) != 0) {

          FUN_1401c9730();

          *(undefined8 *)(uVar4 * 8 + *(longlong *)(param_1 + 0x1a0)) = 0;

        }

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

      } while (uVar3 < *(uint *)(param_1 + 0x19c));

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x1a0));

  }

  if (*(longlong *)(param_1 + 0x1a8) != 0) {

    FUN_140179b30();

    *(undefined8 *)(param_1 + 0x1a8) = 0;

  }

  uVar4 = uVar2;

  if (*(int *)(param_1 + 0x118) != 0) {

    do {

      if (*(longlong *)(uVar4 * 8 + *(longlong *)(param_1 + 0x110)) != 0) {

        FUN_1401c9630();

        *(undefined8 *)(uVar4 * 8 + *(longlong *)(param_1 + 0x110)) = 0;

      }

      uVar3 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_1 + 0x118));

  }

  if (*(int *)(param_1 + 0x158) != 0) {

    do {

      if (*(longlong *)(uVar2 * 8 + *(longlong *)(param_1 + 0x150)) != 0) {

        FUN_1401c9760();

        *(undefined8 *)(uVar2 * 8 + *(longlong *)(param_1 + 0x150)) = 0;

      }

      uVar3 = (int)uVar2 + 1;

      uVar2 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_1 + 0x158));

  }

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x110));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x120));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x130));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x140));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x150));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x1b0));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x1c0));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x1d0));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x1e0));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x1f0));

  FUN_1401747e0(*(undefined4 *)(param_1 + 0xa0));

  if (*(longlong **)(param_1 + 0xa8) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0xa8) + 0x10))();

    *(undefined8 *)(param_1 + 0xa8) = 0;

  }

  if (*(longlong **)(param_1 + 0xb0) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0xb0) + 0x10))();

    *(undefined8 *)(param_1 + 0xb0) = 0;

  }

  if (*(longlong **)(param_1 + 0xb8) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0xb8) + 0x10))();

    *(undefined8 *)(param_1 + 0xb8) = 0;

  }

  if (*(longlong **)(param_1 + 0x90) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0x90) + 0x10))();

    *(undefined8 *)(param_1 + 0x90) = 0;

  }

  if (*(longlong **)(param_1 + 0x70) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0x70) + 0x10))();

    *(undefined8 *)(param_1 + 0x70) = 0;

  }

  if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();

    *(undefined8 *)(param_1 + 0x20) = 0;

  }

  if (*(longlong **)(param_1 + 0x10) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0x10) + 0x10))();

    *(undefined8 *)(param_1 + 0x10) = 0;

  }

  plVar1 = *(longlong **)(param_1 + 8);

  if (plVar1 != (longlong *)0x0) {

    local_18 = _DAT_1403492b8;

    uStack_14 = _UNK_1403492bc;

    uStack_10 = _UNK_1403492c0;

    uStack_c = _UNK_1403492c4;

    (**(code **)(*plVar1 + 0x18))(plVar1,&local_18,3);

    (**(code **)(**(longlong **)(param_1 + 8) + 0x10))();

    *(undefined8 *)(param_1 + 8) = 0;

  }

  if (*(longlong *)(param_1 + 0x68) != 0) {

    FUN_140188670();

    *(undefined8 *)(param_1 + 0x68) = 0;

  }

  if (*(longlong *)(param_1 + 0x28) != 0) {

    FUN_140188670();

    *(undefined8 *)(param_1 + 0x28) = 0;

  }

  if (*(longlong *)(param_1 + 0x30) != 0) {

    FUN_140188670();

    *(undefined8 *)(param_1 + 0x30) = 0;

  }

  if (*(longlong *)(param_1 + 0x38) != 0) {

    FUN_140188670();

    *(undefined8 *)(param_1 + 0x38) = 0;

  }

  *(undefined8 *)(param_1 + 0x78) = 0;

  if (*(longlong *)(param_1 + 0x88) != 0) {

    FUN_140197710();

  }

  FUN_140179b30(*(undefined8 *)(param_1 + 0x200));

  FUN_140179b30(*(undefined8 *)(param_1 + 0x208));

  FUN_140179b30(*(undefined8 *)(param_1 + 0x210));

  FUN_140179b30(*(undefined8 *)(param_1 + 0x218));

  FUN_140179b30(*(undefined8 *)(param_1 + 0x220));

  FUN_140179b30(*(undefined8 *)(param_1 + 0x228));

  FUN_1401841e0(*(undefined8 *)(param_1 + 0x80));

  FUN_1401841e0(param_1);

  return;

}




