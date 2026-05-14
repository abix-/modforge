// Address: 0x140286470
// Ghidra name: FUN_140286470
// ============ 0x140286470 FUN_140286470 (size=157) ============


void FUN_140286470(longlong param_1)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0xc60);

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0x58))();

    *(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0xc60) = 0;

  }

  if (*(longlong *)(*(longlong *)(param_1 + 0x148) + 0xc58) != 0) {

    FUN_1402861d0();

    *(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0xc58) = 0;

  }

  (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x40))();

  (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x10))();

  *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0xc50) = 0;

  return;

}




