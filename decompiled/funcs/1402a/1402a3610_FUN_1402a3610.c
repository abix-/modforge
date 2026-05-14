// Address: 0x1402a3610
// Ghidra name: FUN_1402a3610
// ============ 0x1402a3610 FUN_1402a3610 (size=230) ============


void FUN_1402a3610(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  uint uVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  uint *puVar7;

  

  uVar6 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar5 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar6;

  uVar2 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar5;

  uVar3 = uVar1 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar7 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar6 + -1;

      uVar6 = uVar2 >> 1;

      if ((int)uVar5 != 0) {

        do {

          uVar4 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar3 >> 0x10) +

                            (uVar6 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          *puVar7 = uVar4 >> 8 | uVar4 << 0x18;

          uVar4 = (int)uVar5 - 1;

          uVar5 = (ulonglong)uVar4;

          puVar7 = puVar7 + 1;

          uVar6 = uVar6 + uVar2;

        } while (uVar4 != 0);

        uVar5 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar3 = uVar3 + uVar1;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar6 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




