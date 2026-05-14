// Address: 0x140216050
// Ghidra name: FUN_140216050
// ============ 0x140216050 FUN_140216050 (size=189) ============


void FUN_140216050(longlong param_1)



{

  longlong *plVar1;

  

  if (*(longlong *)(param_1 + 200) != 0) {

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 8);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x90))();

      (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 8) + 0x10))();

    }

    if ((longlong *)**(longlong **)(param_1 + 200) != (longlong *)0x0) {

      (**(code **)(*(longlong *)**(longlong **)(param_1 + 200) + 0x10))();

    }

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x18);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x50))();

      (**(code **)(**(longlong **)(*(longlong *)(param_1 + 200) + 0x18) + 0x10))();

    }

    plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x10);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x10))();

    }

    FUN_1401841e0(*(undefined8 *)(param_1 + 200));

    *(undefined8 *)(param_1 + 200) = 0;

  }

  return;

}




