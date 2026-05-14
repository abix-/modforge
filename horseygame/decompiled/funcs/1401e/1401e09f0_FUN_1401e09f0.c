// Address: 0x1401e09f0
// Ghidra name: FUN_1401e09f0
// ============ 0x1401e09f0 FUN_1401e09f0 (size=187) ============


void FUN_1401e09f0(longlong param_1,int param_2,ulonglong param_3)



{

  undefined8 uVar1;

  

  param_3 = param_3 & 0xffffffff;

  if (param_2 == *(int *)(param_3 * 4 + 100 + param_1)) {

    return;

  }

  if (param_2 == 0) {

LAB_1401e0a2d:

    (**(code **)(**(longlong **)(param_1 + 0x10) + 0x228))

              (*(longlong **)(param_1 + 0x10),param_3,6,1);

    uVar1 = 1;

  }

  else {

    if (param_2 != 1) {

      if (param_2 != 2) goto LAB_1401e0a6b;

      goto LAB_1401e0a2d;

    }

    (**(code **)(**(longlong **)(param_1 + 0x10) + 0x228))

              (*(longlong **)(param_1 + 0x10),param_3,6,2);

    uVar1 = 2;

  }

  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x228))

            (*(longlong **)(param_1 + 0x10),param_3,5,uVar1);

LAB_1401e0a6b:

  *(int *)(param_3 * 4 + 100 + param_1) = param_2;

  return;

}




