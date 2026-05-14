// Address: 0x14008f130
// Ghidra name: FUN_14008f130
// ============ 0x14008f130 FUN_14008f130 (size=459) ============


void FUN_14008f130(longlong param_1)



{

  longlong *plVar1;

  undefined8 uVar2;

  longlong lVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  longlong *plVar6;

  longlong lVar7;

  longlong local_28 [3];

  ulonglong local_10;

  

  *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;

  FUN_1400ca260();

  FUN_1400ceb60(param_1);

  if ((*(int *)(param_1 + 0x250) == 0) && (*(int *)(param_1 + 0x25c) == 0x3c)) {

    FUN_1400d1c40(param_1,*(undefined8 *)(param_1 + 0x148),"Welcome to %s");

    uVar2 = *(undefined8 *)(param_1 + 0x148);

    if (*(int *)(param_1 + 0x268) == 0) {

      FUN_1400d1c40(param_1,uVar2,"And I\'m all outta rides. Yeehaw!");

    }

    else {

      FUN_1400cf970(param_1);

      FUN_1400d1c40(param_1,uVar2,"I\'m %s and these are my rides");

    }

  }

  if ((*(int *)(param_1 + 0xe0) == 0) ||

     ((*(int *)(param_1 + 0x250) == 1 && (*(int *)(param_1 + 0x25c) == 0x3c)))) {

    if (*(longlong *)(param_1 + 0x148) != 0) {

      FUN_1400cf970(param_1);

      plVar6 = (longlong *)FUN_14008d760(local_28,"%s\'s Rides");

      plVar1 = (longlong *)(param_1 + 0x18);

      if (plVar1 != plVar6) {

        if (0xf < *(ulonglong *)(param_1 + 0x30)) {

          lVar3 = *plVar1;

          lVar7 = lVar3;

          if ((0xfff < *(ulonglong *)(param_1 + 0x30) + 1) &&

             (lVar7 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar7) - 8U)) goto LAB_14008f2e3;

          FUN_1402c7088(lVar7);

        }

        *(undefined8 *)(param_1 + 0x28) = 0;

        *(undefined8 *)(param_1 + 0x30) = 0xf;

        *(undefined1 *)plVar1 = 0;

        uVar4 = *(undefined4 *)((longlong)plVar6 + 4);

        lVar3 = plVar6[1];

        uVar5 = *(undefined4 *)((longlong)plVar6 + 0xc);

        *(int *)plVar1 = (int)*plVar6;

        *(undefined4 *)(param_1 + 0x1c) = uVar4;

        *(int *)(param_1 + 0x20) = (int)lVar3;

        *(undefined4 *)(param_1 + 0x24) = uVar5;

        lVar3 = plVar6[3];

        *(longlong *)(param_1 + 0x28) = plVar6[2];

        *(longlong *)(param_1 + 0x30) = lVar3;

        plVar6[2] = 0;

        plVar6[3] = 0xf;

        *(undefined1 *)plVar6 = 0;

      }

      if (0xf < local_10) {

        if ((0xfff < local_10 + 1) && (0x1f < (local_28[0] - *(longlong *)(local_28[0] + -8)) - 8U))

        {

LAB_14008f2e3:

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088();

      }

    }

    FUN_1400cdae0(param_1);

  }

  return;

}




