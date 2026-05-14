// Address: 0x1401968f0
// Ghidra name: FUN_1401968f0
// ============ 0x1401968f0 FUN_1401968f0 (size=100) ============


undefined8 FUN_1401968f0(void)



{

  undefined8 uVar1;

  longlong *in_stack_00000040;

  

  uVar1 = *(undefined8 *)(*in_stack_00000040 + 0x20);

  *(undefined8 *)(*in_stack_00000040 + 0x20) = 0;

  FUN_140196850();

  *(undefined8 *)(*(longlong *)(*in_stack_00000040 + 0x20) + 0x20) = uVar1;

  return *(undefined8 *)(*in_stack_00000040 + 0x20);

}




