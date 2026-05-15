// Address: 0x140287940
// Ghidra name: FUN_140287940
// ============ 0x140287940 FUN_140287940 (size=62) ============


void FUN_140287940(undefined8 param_1,undefined2 *param_2)



{

  int iVar1;

  

  iVar1 = (**(code **)(**(longlong **)(*(longlong *)(param_2 + 0x24) + 0x50) + 0x58))();

  if (iVar1 < 0) {

    FUN_1402878d0("Removing effect from the device",iVar1);

  }

  FUN_140288830(*(undefined8 *)(param_2 + 0x24),*param_2);

  return;

}




