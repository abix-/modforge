// Address: 0x1401e20f0
// Ghidra name: FUN_1401e20f0
// ============ 0x1401e20f0 FUN_1401e20f0 (size=84) ============


void FUN_1401e20f0(undefined8 param_1,longlong param_2)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)(param_2 + 0x10);

  if (plVar1 != (longlong *)0x0) {

    if ((longlong *)*plVar1 != (longlong *)0x0) {

      (**(code **)(*(longlong *)*plVar1 + 0x10))();

      *plVar1 = 0;

    }

    if ((longlong *)plVar1[1] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[1] + 0x10))();

      plVar1[1] = 0;

    }

    FUN_1401841e0(plVar1);

    return;

  }

  return;

}




