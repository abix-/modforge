// Address: 0x1401dfa70
// Ghidra name: FUN_1401dfa70
// ============ 0x1401dfa70 FUN_1401dfa70 (size=245) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



ulonglong FUN_1401dfa70(longlong param_1,longlong param_2,int param_3,longlong param_4)



{

  undefined1 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  longlong lVar5;

  ulonglong uVar6;

  longlong lVar7;

  undefined1 *puVar8;

  undefined8 auStack_50 [5];

  int aiStack_28 [4];

  longlong local_18;

  int local_10 [2];

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  lVar7 = (longlong)param_3;

  uVar3 = *(undefined8 *)(param_2 + 0x10);

  uVar6 = lVar7 * 4 + 0xf;

  if (uVar6 <= (ulonglong)(lVar7 * 4)) {

    uVar6 = 0xffffffffffffff0;

  }

  auStack_50[0] = 0x1401dfac6;

  lVar5 = -(uVar6 & 0xfffffffffffffff0);

  puVar1 = &stack0xfffffffffffffff8 + lVar5;

  if (puVar1 == (undefined1 *)0x0) {

    uVar6 = uVar6 & 0xffffffffffffff00;

  }

  else {

    if (0 < param_3) {

      puVar8 = (undefined1 *)(param_4 + 1);

      do {

        *(uint *)(puVar8 + 4 + (longlong)(puVar1 + (-5 - param_4))) =

             CONCAT31(CONCAT21(CONCAT11(puVar8[2],puVar8[-1]),*puVar8),puVar8[1]);

        lVar7 = lVar7 + -1;

        puVar8 = puVar8 + 4;

      } while (lVar7 != 0);

    }

    uVar4 = *(undefined8 *)(lVar2 + 0x10);

    *(int *)((longlong)local_10 + lVar5) = param_3 * 4;

    *(undefined1 **)((longlong)&local_18 + lVar5) = puVar1;

    *(undefined4 *)((longlong)aiStack_28 + lVar5 + 8) = 1;

    *(int *)((longlong)aiStack_28 + lVar5) = param_3;

    *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401dfb50;

    uVar6 = FUN_1401dfd20(uVar4,uVar3,0,0);

  }

  return uVar6;

}




