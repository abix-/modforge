// Address: 0x140028410
// Ghidra name: FUN_140028410
// ============ 0x140028410 FUN_140028410 (size=36) ============


void FUN_140028410(longlong *param_1)



{

  longlong *plVar1;

  

  plVar1 = *(longlong **)((longlong)*(int *)(*(longlong *)*param_1 + 4) + 0x48 + *param_1);

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0x10))();

  }

  return;

}




