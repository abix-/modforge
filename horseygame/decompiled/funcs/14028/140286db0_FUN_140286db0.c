// Address: 0x140286db0
// Ghidra name: FUN_140286db0
// ============ 0x140286db0 FUN_140286db0 (size=153) ============


void FUN_140286db0(longlong param_1)



{

  int iVar1;

  

  iVar1 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 200))();

  if ((iVar1 == -0x7ff8ffe2) || (iVar1 == -0x7ff8fff4)) {

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 200))();

  }

  if (*(char *)(*(longlong *)(param_1 + 0x148) + 0x45) != '\0') {

    FUN_140287230(param_1);

    *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x45) = 0;

    return;

  }

  if (*(char *)(*(longlong *)(param_1 + 0x148) + 0x44) != '\0') {

    FUN_140287050();

    return;

  }

  FUN_140287230(param_1);

  return;

}




