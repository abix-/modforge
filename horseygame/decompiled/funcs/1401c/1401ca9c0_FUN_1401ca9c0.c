// Address: 0x1401ca9c0
// Ghidra name: FUN_1401ca9c0
// ============ 0x1401ca9c0 FUN_1401ca9c0 (size=407) ============


void FUN_1401ca9c0(longlong param_1,int param_2,ulonglong param_3,undefined8 param_4,

                  undefined4 param_5)



{

  int iVar1;

  longlong *plVar2;

  

  if (param_2 == 0) {

    plVar2 = *(longlong **)(param_1 + 0x470 + (param_3 & 0xffffffff) * 8);

    if (plVar2 == (longlong *)0x0) {

      plVar2 = (longlong *)FUN_1401c5990();

      *(longlong **)(param_1 + 0x470 + (param_3 & 0xffffffff) * 8) = plVar2;

    }

  }

  else if (param_2 == 1) {

    plVar2 = *(longlong **)(param_1 + 0x610 + (param_3 & 0xffffffff) * 8);

    if (plVar2 == (longlong *)0x0) {

      plVar2 = (longlong *)FUN_1401c5990();

      *(longlong **)(param_1 + 0x610 + (param_3 & 0xffffffff) * 8) = plVar2;

    }

  }

  else {

    if (param_2 != 2) goto LAB_1401cab33;

    plVar2 = *(longlong **)(param_1 + 0x940 + (param_3 & 0xffffffff) * 8);

    if (plVar2 == (longlong *)0x0) {

      plVar2 = (longlong *)FUN_1401c5990();

      *(longlong **)(param_1 + 0x940 + (param_3 & 0xffffffff) * 8) = plVar2;

    }

  }

  param_3 = param_3 & 0xffffffff;

  iVar1 = FUN_1401c5ab0(param_5,0x100);

  if (0x7fff < (uint)((int)plVar2[1] + iVar1)) {

    (**(code **)(**(longlong **)(*plVar2 + 0x10) + 0x48))(*(longlong **)(*plVar2 + 0x10),0,0);

    *(undefined8 *)(*plVar2 + 0x80) = 0;

    plVar2 = (longlong *)FUN_1401c5990(param_1);

    plVar2[1] = 0;

    if (param_2 == 0) {

      *(longlong **)(param_1 + 0x470 + param_3 * 8) = plVar2;

    }

    else if (param_2 == 1) {

      *(longlong **)(param_1 + 0x610 + param_3 * 8) = plVar2;

    }

    else {

      if (param_2 != 2) {

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"Unrecognized shader stage!");

      }

      *(longlong **)(param_1 + 0x940 + param_3 * 8) = plVar2;

    }

  }

  *(uint *)((longlong)plVar2 + 0xc) = *(uint *)(plVar2 + 1);

  FUN_1402f8e20((ulonglong)*(uint *)(plVar2 + 1) + *(longlong *)(*plVar2 + 0x80),param_4,param_5);

  *(int *)(plVar2 + 1) = (int)plVar2[1] + iVar1;

  if (param_2 == 0) {

    *(undefined1 *)(param_3 + 0x214 + param_1) = 1;

  }

  else if (param_2 == 1) {

    *(undefined1 *)(param_3 + 0x21b + param_1) = 1;

  }

  else {

    if (param_2 != 2) {

LAB_1401cab33:

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,"Unrecognized shader stage!");

    }

    *(undefined1 *)(param_3 + 0x222 + param_1) = 1;

  }

  return;

}




