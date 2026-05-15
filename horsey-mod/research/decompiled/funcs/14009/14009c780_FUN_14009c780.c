// Address: 0x14009c780
// Ghidra name: FUN_14009c780
// ============ 0x14009c780 FUN_14009c780 (size=17) ============


void FUN_14009c780(longlong param_1,undefined8 param_2)



{

  if (*(longlong *)(param_1 + 8) == 0) {

    *(undefined8 *)(param_1 + 8) = param_2;

    return;

  }

  *(undefined8 *)(param_1 + 0x10) = param_2;

  return;

}




