// Address: 0x1401bcc70
// Ghidra name: FUN_1401bcc70
// ============ 0x1401bcc70 FUN_1401bcc70 (size=164) ============


void FUN_1401bcc70(longlong param_1,longlong *param_2)



{

  uint uVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8c0));

  uVar4 = 0;

  uVar1 = *(uint *)(*param_2 + 0x20);

  if (uVar1 != 0) {

    lVar2 = *(longlong *)(*param_2 + 0x18);

    do {

      if (*(longlong **)(lVar2 + uVar4 * 8) == param_2) {

        if ((uint)uVar4 != uVar1 - 1) {

          *(undefined8 *)(lVar2 + uVar4 * 8) = *(undefined8 *)(lVar2 + (ulonglong)(uVar1 - 1) * 8);

        }

        break;

      }

      uVar3 = (uint)uVar4 + 1;

      uVar4 = (ulonglong)uVar3;

    } while (uVar3 < uVar1);

  }

  *(longlong *)(*param_2 + 0x48) = *(longlong *)(*param_2 + 0x48) - param_2[2];

  *(int *)(*param_2 + 0x20) = *(int *)(*param_2 + 0x20) + -1;

  FUN_1401bb850(param_1,*param_2,param_2[1],param_2[2]);

  if (*(int *)(*param_2 + 0x20) == 0) {

    *(undefined1 *)(param_1 + 0x7a8) = 1;

  }

  FUN_1401841e0(param_2);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x8c0));

  return;

}




