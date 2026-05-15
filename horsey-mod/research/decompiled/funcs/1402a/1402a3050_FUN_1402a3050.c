// Address: 0x1402a3050
// Ghidra name: FUN_1402a3050
// ============ 0x1402a3050 FUN_1402a3050 (size=277) ============


void FUN_1402a3050(longlong param_1)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  uint uVar5;

  ulonglong uVar6;

  uint *puVar7;

  

  uVar4 = (ulonglong)*(int *)(param_1 + 0x3c);

  uVar6 = (ulonglong)*(int *)(param_1 + 0x38);

  uVar1 = (ulonglong)((longlong)*(int *)(param_1 + 0x14) << 0x10) / uVar4;

  uVar2 = (ulonglong)((longlong)*(int *)(param_1 + 0x10) << 0x10) / uVar6;

  uVar3 = uVar1 >> 1;

  if (*(int *)(param_1 + 0x3c) != 0) {

    do {

      puVar7 = *(uint **)(param_1 + 0x30);

      *(int *)(param_1 + 0x3c) = (int)uVar4 + -1;

      uVar4 = uVar2 >> 1;

      if ((int)uVar6 != 0) {

        do {

          uVar5 = *(uint *)((longlong)*(int *)(param_1 + 0x18) * (uVar3 >> 0x10) +

                            (uVar4 >> 0x10) * 4 + *(longlong *)(param_1 + 8));

          *puVar7 = (uVar5 >> 8 & 0xff | (uVar5 & 0xff) << 8) << 8 | uVar5 >> 0x10 & 0xff |

                    uVar5 & 0xff000000;

          uVar5 = (int)uVar6 - 1;

          uVar6 = (ulonglong)uVar5;

          uVar4 = uVar4 + uVar2;

          puVar7 = puVar7 + 1;

        } while (uVar5 != 0);

        uVar6 = (ulonglong)*(uint *)(param_1 + 0x38);

      }

      uVar3 = uVar3 + uVar1;

      *(longlong *)(param_1 + 0x30) =

           *(longlong *)(param_1 + 0x30) + (longlong)*(int *)(param_1 + 0x40);

      uVar4 = (ulonglong)*(uint *)(param_1 + 0x3c);

    } while (*(uint *)(param_1 + 0x3c) != 0);

  }

  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;

  return;

}




