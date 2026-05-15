// Address: 0x140203a40
// Ghidra name: FUN_140203a40
// ============ 0x140203a40 FUN_140203a40 (size=53) ============


void FUN_140203a40(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  

  puVar1 = *(undefined8 **)(param_2 + 0x10);

  if (puVar1 != (undefined8 *)0x0) {

    FUN_140137fd0(*(undefined8 *)(*(longlong *)(param_1 + 0x2e0) + 8),*puVar1);

    FUN_1401841e0(puVar1);

    return;

  }

  return;

}




