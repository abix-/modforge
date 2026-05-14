// Address: 0x1401cc240
// Ghidra name: FUN_1401cc240
// ============ 0x1401cc240 FUN_1401cc240 (size=174) ============


undefined8 FUN_1401cc240(longlong param_1,undefined4 param_2)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  ulonglong uVar4;

  uint uVar5;

  ulonglong uVar6;

  

  cVar2 = FUN_1401cd410();

  if (cVar2 == '\0') {

LAB_1401cc2d7:

    uVar3 = 0;

  }

  else {

    uVar4 = 0;

    uVar6 = uVar4;

    if (*(int *)(param_1 + 0x148) == 0) {

      *(undefined4 *)(param_1 + 0xa4) = param_2;

    }

    else {

      do {

        FUN_1401c9cd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x140) + uVar6 * 8));

        uVar5 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar5;

      } while (uVar5 < *(uint *)(param_1 + 0x148));

      *(undefined4 *)(param_1 + 0xa4) = param_2;

      if (*(uint *)(param_1 + 0x148) != 0) {

        while( true ) {

          lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x140) + uVar4 * 8);

          cVar2 = FUN_1401c8780(param_1,lVar1,*(undefined4 *)(lVar1 + 0x24),

                                *(undefined4 *)(lVar1 + 0x20));

          if (cVar2 == '\0') break;

          uVar5 = (int)uVar4 + 1;

          uVar4 = (ulonglong)uVar5;

          if (*(uint *)(param_1 + 0x148) <= uVar5) {

            return 1;

          }

        }

        goto LAB_1401cc2d7;

      }

    }

    uVar3 = 1;

  }

  return uVar3;

}




