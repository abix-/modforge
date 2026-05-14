// Address: 0x1401de490
// Ghidra name: FUN_1401de490
// ============ 0x1401de490 FUN_1401de490 (size=71) ============


undefined8 FUN_1401de490(undefined8 param_1,undefined1 *param_2)



{

  longlong *plVar1;

  

  if (*(longlong **)(param_2 + 0x18) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_2 + 0x18) + 0x10))();

    *(undefined8 *)(param_2 + 0x18) = 0;

  }

  plVar1 = *(longlong **)(param_2 + 0x20);

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0xa8))(plVar1,0);

    *param_2 = 1;

  }

  return 1;

}




