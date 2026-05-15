// Address: 0x1401adbb0
// Ghidra name: FUN_1401adbb0
// ============ 0x1401adbb0 FUN_1401adbb0 (size=205) ============


undefined8 FUN_1401adbb0(longlong param_1,uint param_2,longlong param_3,undefined8 *param_4)



{

  int iVar1;

  undefined8 uVar2;

  uint uVar3;

  ulonglong uVar5;

  ulonglong uVar4;

  

  if (*(int *)(param_1 + 0x244) == 0) {

    return 1;

  }

  uVar5 = 0;

  if (param_2 == 0) {

    uVar5 = 0;

LAB_1401adc59:

    uVar2 = 0;

    *param_4 = *(undefined8 *)(*(longlong *)(param_1 + 0x248) + uVar5 * 8);

  }

  else {

    do {

      uVar4 = 0;

      while( true ) {

        iVar1 = strcmp(*(char **)(*(longlong *)(param_1 + 0x248) + uVar5 * 8),

                       (char *)(uVar4 * 0x104 + param_3));

        if (iVar1 == 0) break;

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

        if (param_2 <= uVar3) goto LAB_1401adc59;

      }

      uVar3 = (int)uVar5 + 1;

      uVar5 = (ulonglong)uVar3;

    } while (uVar3 < *(uint *)(param_1 + 0x244));

    uVar2 = 1;

  }

  return uVar2;

}




