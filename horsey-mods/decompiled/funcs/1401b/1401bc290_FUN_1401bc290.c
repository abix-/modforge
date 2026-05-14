// Address: 0x1401bc290
// Ghidra name: FUN_1401bc290
// ============ 0x1401bc290 FUN_1401bc290 (size=421) ============


void FUN_1401bc290(longlong param_1,int param_2,ulonglong param_3,undefined8 param_4,int param_5)



{

  uint uVar1;

  longlong *plVar2;

  uint uVar3;

  int iVar4;

  

  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x110) + 0x84c);

  uVar3 = param_5 + -1 + uVar1;

  iVar4 = uVar3 - uVar3 % uVar1;

  if (param_2 == 0) {

    plVar2 = *(longlong **)(param_1 + 0x9a0 + (param_3 & 0xffffffff) * 8);

    if (plVar2 == (longlong *)0x0) {

      plVar2 = (longlong *)FUN_1401b2970();

      *(longlong **)(param_1 + 0x9a0 + (param_3 & 0xffffffff) * 8) = plVar2;

    }

  }

  else if (param_2 == 1) {

    plVar2 = *(longlong **)(param_1 + 0x9c0 + (param_3 & 0xffffffff) * 8);

    if (plVar2 == (longlong *)0x0) {

      plVar2 = (longlong *)FUN_1401b2970();

      *(longlong **)(param_1 + 0x9c0 + (param_3 & 0xffffffff) * 8) = plVar2;

    }

  }

  else {

    if (param_2 != 2) goto LAB_1401bc405;

    plVar2 = *(longlong **)(param_1 + 0x9e0 + (param_3 & 0xffffffff) * 8);

    if (plVar2 == (longlong *)0x0) {

      plVar2 = (longlong *)FUN_1401b2970();

      *(longlong **)(param_1 + 0x9e0 + (param_3 & 0xffffffff) * 8) = plVar2;

    }

  }

  param_3 = param_3 & 0xffffffff;

  if (*(ulonglong *)(*plVar2 + 0x28) <=

      (ulonglong)(uint)(*(int *)((longlong)plVar2 + 0xc) + 0x1000 + iVar4)) {

    plVar2 = (longlong *)FUN_1401b2970(param_1);

    plVar2[1] = 0;

    if (param_2 == 0) {

      *(longlong **)(param_1 + 0x9a0 + param_3 * 8) = plVar2;

      *(undefined1 *)(param_1 + 0x249) = 1;

    }

    else if (param_2 == 1) {

      *(longlong **)(param_1 + 0x9c0 + param_3 * 8) = plVar2;

      *(undefined1 *)(param_1 + 0x24c) = 1;

    }

    else {

      if (param_2 != 2) goto LAB_1401bc405;

      *(longlong **)(param_1 + 0x9e0 + param_3 * 8) = plVar2;

      *(undefined1 *)(param_1 + 0x250) = 1;

    }

  }

  *(uint *)(plVar2 + 1) = *(uint *)((longlong)plVar2 + 0xc);

  FUN_1402f8e20(*(longlong *)(**(longlong **)(*plVar2 + 0x18) + 0x50) +

                (*(longlong **)(*plVar2 + 0x18))[3] + (ulonglong)*(uint *)((longlong)plVar2 + 0xc),

                param_4,param_5);

  *(int *)((longlong)plVar2 + 0xc) = *(int *)((longlong)plVar2 + 0xc) + iVar4;

  if (param_2 == 0) {

    *(undefined1 *)(param_1 + 0x24a) = 1;

  }

  else if (param_2 == 1) {

    *(undefined1 *)(param_1 + 0x24d) = 1;

  }

  else {

    if (param_2 != 2) {

LAB_1401bc405:

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Unrecognized shader stage!");

    }

    *(undefined1 *)(param_1 + 0x251) = 1;

  }

  return;

}




