// Address: 0x14008eb60
// Ghidra name: FUN_14008eb60
// ============ 0x14008eb60 FUN_14008eb60 (size=599) ============


void FUN_14008eb60(longlong param_1,longlong param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar4;

  longlong local_28 [3];

  ulonglong local_10;

  

  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  if (*(char *)(param_2 + 0x10) != '\0') {

    return;

  }

  if (*(int *)(param_2 + 8) != 3) {

    return;

  }

  iVar1 = *(int *)(param_2 + 0xc);

  if (iVar1 == 0x17) {

    uVar2 = FUN_140086330();

    uVar3 = FUN_140086310(1);

    uVar2 = FUN_14008d760(local_28,"Those %sRacing Stripes%s will be $%d",uVar3,uVar2,

                          CONCAT44(uVar4,0xfa));

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),uVar2,0,DAT_140303758);

    if (local_10 < 0x10) {

      return;

    }

    if ((0xfff < local_10 + 1) && (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else if (iVar1 == 0x18) {

    uVar2 = FUN_140086330();

    uVar3 = FUN_140086310(4);

    uVar2 = FUN_14008d760(local_28,"That %sSuspension Lift%s will be $%d",uVar3,uVar2,

                          CONCAT44(uVar4,0xfa));

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),uVar2,0,DAT_140303758);

    if (local_10 < 0x10) {

      return;

    }

    if ((0xfff < local_10 + 1) && (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  else {

    if (iVar1 != 0x19) {

      return;

    }

    uVar2 = FUN_140086330();

    uVar3 = FUN_140086310(3);

    uVar2 = FUN_14008d760(local_28,"That %sRam Bar%s will be $%d",uVar3,uVar2,CONCAT44(uVar4,0xfa));

    FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),uVar2,0,DAT_140303758);

    if (local_10 < 0x10) {

      return;

    }

    if ((0xfff < local_10 + 1) && (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

  }

  FUN_1402c7088();

  return;

}




