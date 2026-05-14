// Address: 0x140028290
// Ghidra name: FUN_140028290
// ============ 0x140028290 FUN_140028290 (size=122) ============


undefined8 * FUN_140028290(undefined8 *param_1,longlong *param_2)



{

  longlong *plVar1;

  bool bVar2;

  

  *param_1 = param_2;

  plVar1 = *(longlong **)((longlong)*(int *)(*param_2 + 4) + 0x48 + (longlong)param_2);

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 8))();

  }

  if (*(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) == 0) {

    plVar1 = *(longlong **)((longlong)*(int *)(*param_2 + 4) + 0x50 + (longlong)param_2);

    if ((plVar1 == (longlong *)0x0) || (plVar1 == param_2)) {

      bVar2 = true;

    }

    else {

      FUN_140028440();

      bVar2 = *(int *)((longlong)*(int *)(*param_2 + 4) + 0x10 + (longlong)param_2) == 0;

    }

  }

  else {

    bVar2 = false;

  }

  *(bool *)(param_1 + 1) = bVar2;

  return param_1;

}




