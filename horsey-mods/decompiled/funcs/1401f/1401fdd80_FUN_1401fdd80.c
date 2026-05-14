// Address: 0x1401fdd80
// Ghidra name: FUN_1401fdd80
// ============ 0x1401fdd80 FUN_1401fdd80 (size=326) ============


void FUN_1401fdd80(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  uint uVar4;

  uint uVar5;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  (*DAT_1403fd090)(*(undefined8 *)(param_1 + 0x698),0);

  uVar2 = (ulonglong)*(uint *)(param_1 + 0x690);

  uVar3 = 0;

  uVar1 = uVar3;

  if (*(int *)(*(longlong *)(param_1 + 0x2848) + uVar2 * 4) != 0) {

    do {

      (*DAT_1403fd0a0)(*(undefined8 *)(param_1 + 0x660),

                       *(undefined8 *)

                        (*(longlong *)(*(longlong *)(param_1 + 0x2840) + uVar2 * 8) + uVar1 * 8),0);

      uVar4 = (int)uVar1 + 1;

      uVar2 = (ulonglong)*(uint *)(param_1 + 0x690);

      uVar1 = (ulonglong)uVar4;

    } while (uVar4 < *(uint *)(*(longlong *)(param_1 + 0x2848) +

                              (ulonglong)*(uint *)(param_1 + 0x690) * 4));

  }

  uStack_20 = 0;

  local_28 = 0x2a;

  uStack_10 = 0;

  local_18 = 0;

  (*DAT_1403fceb8)(*(undefined8 *)(param_1 + 0x698),&local_28);

  uVar1 = (ulonglong)*(uint *)(param_1 + 0x690);

  *(undefined8 *)(param_1 + 0x2868) = 0;

  *(undefined4 *)(param_1 + 0x297c) = 0;

  *(undefined1 *)(param_1 + 0x2980) = 0;

  *(undefined1 *)(param_1 + 0x2900) = 1;

  *(undefined8 *)(param_1 + 0x2850) = 0;

  *(undefined4 *)(param_1 + 0x27fc) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x27f8) = 0;

  if (*(int *)(*(longlong *)(param_1 + 0x27e0) + uVar1 * 4) < 1) {

    *(undefined4 *)(*(longlong *)(param_1 + 0x27e0) + uVar1 * 4) = 0;

    return;

  }

  do {

    FUN_1401f98d0(param_1,(longlong)(int)uVar3 * 0x20 +

                          *(longlong *)(*(longlong *)(param_1 + 0x27d8) + uVar1 * 8));

    uVar4 = *(uint *)(param_1 + 0x690);

    uVar5 = (int)uVar3 + 1;

    uVar3 = (ulonglong)uVar5;

    uVar1 = (ulonglong)uVar4;

  } while ((int)uVar5 < *(int *)(*(longlong *)(param_1 + 0x27e0) + (ulonglong)uVar4 * 4));

  *(undefined4 *)(*(longlong *)(param_1 + 0x27e0) + (ulonglong)uVar4 * 4) = 0;

  return;

}




