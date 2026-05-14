// Address: 0x1401ac4c0
// Ghidra name: FUN_1401ac4c0
// ============ 0x1401ac4c0 FUN_1401ac4c0 (size=96) ============


void FUN_1401ac4c0(longlong param_1)



{

  longlong *plVar1;

  

  if ((param_1 != 0) && (*(longlong **)(param_1 + 0x1d0) != (longlong *)0x0)) {

    plVar1 = (longlong *)**(longlong **)(param_1 + 0x1d0);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x10))();

    }

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x1d0) + 8);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x10))();

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 0x1d0));

    *(undefined8 *)(param_1 + 0x1d0) = 0;

  }

  return;

}




