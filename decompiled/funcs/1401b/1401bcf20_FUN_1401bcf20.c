// Address: 0x1401bcf20
// Ghidra name: FUN_1401bcf20
// ============ 0x1401bcf20 FUN_1401bcf20 (size=149) ============


void FUN_1401bcf20(longlong param_1,longlong *param_2)



{

  uint uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  

  if (*(uint *)(param_1 + 0x844) <= *(int *)(param_1 + 0x840) + 1U) {

    uVar1 = *(uint *)(param_1 + 0x844) * 2;

    *(uint *)(param_1 + 0x844) = uVar1;

    uVar2 = FUN_140184230(*(undefined8 *)(param_1 + 0x838),(ulonglong)uVar1 << 3);

    *(undefined8 *)(param_1 + 0x838) = uVar2;

  }

  *(longlong **)(*(longlong *)(param_1 + 0x838) + (ulonglong)*(uint *)(param_1 + 0x840) * 8) =

       param_2;

  uVar1 = 0;

  *(int *)(param_1 + 0x840) = *(int *)(param_1 + 0x840) + 1;

  if ((int)param_2[1] != 0) {

    do {

      uVar3 = (ulonglong)uVar1;

      uVar1 = uVar1 + 1;

      *(undefined4 *)(uVar3 * 0x20 + 0x1c + *param_2) = 0;

    } while (uVar1 < *(uint *)(param_2 + 1));

  }

  return;

}




