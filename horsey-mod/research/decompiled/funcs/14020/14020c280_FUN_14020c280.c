// Address: 0x14020c280
// Ghidra name: FUN_14020c280
// ============ 0x14020c280 FUN_14020c280 (size=48) ============


void FUN_14020c280(longlong param_1)



{

  _guard_check_icall();

  if (*(longlong *)(param_1 + 0x148) != 0) {

    *(undefined8 *)(*(longlong *)(param_1 + 0x148) + 0x100) = 0;

    *(undefined8 *)(param_1 + 0x148) = 0;

  }

  return;

}




