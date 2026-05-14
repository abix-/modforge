// Address: 0x14020e1e0
// Ghidra name: FUN_14020e1e0
// ============ 0x14020e1e0 FUN_14020e1e0 (size=148) ============


void FUN_14020e1e0(longlong param_1)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)(param_1 + 0x148);

  if (plVar1 != (longlong *)0x0) {

    if ((longlong *)*plVar1 != (longlong *)0x0) {

      (**(code **)(*(longlong *)*plVar1 + 0x10))();

    }

    if ((longlong *)plVar1[1] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[1] + 0x10))();

    }

    if ((longlong *)plVar1[2] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[2] + 0x10))();

    }

    if ((longlong *)plVar1[3] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[3] + 0x10))();

    }

    FUN_1401841e0(plVar1);

    *(undefined8 *)(param_1 + 0x148) = 0;

    return;

  }

  *(undefined8 *)(param_1 + 0x148) = 0;

  return;

}




