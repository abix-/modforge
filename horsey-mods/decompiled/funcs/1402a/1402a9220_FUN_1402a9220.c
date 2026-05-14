// Address: 0x1402a9220
// Ghidra name: FUN_1402a9220
// ============ 0x1402a9220 FUN_1402a9220 (size=203) ============


void FUN_1402a9220(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined4 *puVar4;

  uint uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  

  uVar7 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar6 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar7;

  uVar2 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar6;

  uVar3 = uVar1 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar4 = *(undefined4 **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar7 + -1;

      uVar7 = uVar2 >> 1;

      if ((int)uVar6 != 0) {

        do {

          *puVar4 = *(undefined4 *)

                     ((longlong)*(int *)(param_1 + 0x18) * (uVar3 >> 0x10) + (uVar7 >> 0x10) * 4 +

                     *(longlong *)(param_1 + 8));

          uVar5 = (int)uVar6 - 1;

          uVar6 = (ulonglong)uVar5;

          puVar4 = puVar4 + 1;

          uVar7 = uVar7 + uVar2;

        } while (uVar5 != 0);

        uVar6 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar3 = uVar3 + uVar1;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar7 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




