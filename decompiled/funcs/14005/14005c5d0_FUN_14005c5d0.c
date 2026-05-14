// Address: 0x14005c5d0
// Ghidra name: FUN_14005c5d0
// ============ 0x14005c5d0 FUN_14005c5d0 (size=320) ============


void FUN_14005c5d0(longlong param_1)



{

  int iVar1;

  undefined4 uVar2;

  size_t sVar3;

  uint uVar4;

  undefined **ppuVar5;

  bool bVar6;

  undefined8 in_stack_ffffffffffffffb8;

  undefined4 uVar7;

  longlong local_38 [6];

  

  *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;

  FUN_1400ca260();

  FUN_1400ceb60(param_1);

  uVar2 = DAT_140303758;

  iVar1 = *(int *)(param_1 + 0x250);

  bVar6 = false;

  if (iVar1 == 0x3c) {

    uVar4 = 0;

    ppuVar5 = &PTR_s_Welcome_weary_traveler_1403d4c70;

    do {

      uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);

      local_38[0] = 0;

      local_38[1] = 0;

      local_38[2] = 0;

      local_38[3] = 0;

      sVar3 = strlen(*ppuVar5);

      FUN_140027e30(local_38,*ppuVar5,sVar3);

      in_stack_ffffffffffffffb8 = CONCAT44(uVar7,uVar2);

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 0x148),local_38,0,in_stack_ffffffffffffffb8);

      if (0xf < (ulonglong)local_38[3]) {

        if (0xfff < local_38[3] + 1U) {

          if (0x1f < (local_38[0] - *(longlong *)(local_38[0] + -8)) - 8U) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      uVar4 = uVar4 + 1;

      ppuVar5 = ppuVar5 + 1;

    } while (uVar4 < 0x11);

    iVar1 = *(int *)(param_1 + 0x250);

    bVar6 = iVar1 == 0x3c;

  }

  if ((!bVar6 && 0x3b < iVar1) && (*(int *)(param_1 + 0x1f8) == 0)) {

    *(undefined1 *)(param_1 + 0x254) = 1;

  }

  if (*(int *)(param_1 + 0xe0) == 0) {

    FUN_1400cdae0(param_1);

  }

  return;

}




