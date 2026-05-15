// Address: 0x1401dd680
// Ghidra name: FUN_1401dd680
// ============ 0x1401dd680 FUN_1401dd680 (size=67) ============


void FUN_1401dd680(longlong param_1)



{

  if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();

    *(undefined8 *)(param_1 + 0x18) = 0;

  }

  if (*(longlong **)(param_1 + 0x20) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();

    *(undefined8 *)(param_1 + 0x20) = 0;

  }

  return;

}




