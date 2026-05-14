// Address: 0x1401e7c30
// Ghidra name: FUN_1401e7c30
// ============ 0x1401e7c30 FUN_1401e7c30 (size=77) ============


void FUN_1401e7c30(undefined8 param_1,longlong param_2)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)(param_2 + 0x10);

  if (plVar1 != (longlong *)0x0) {

    if ((longlong *)*plVar1 != (longlong *)0x0) {

      (**(code **)(*(longlong *)*plVar1 + 0x10))();

      *plVar1 = 0;

    }

    FUN_1401e7e30(param_1,plVar1[3]);

    FUN_1401841e0(plVar1);

  }

  return;

}




