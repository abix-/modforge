// Address: 0x1402ff39d
// Ghidra name: FUN_1402ff39d
// ============ 0x1402ff39d FUN_1402ff39d (size=41) ============


void FUN_1402ff39d(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x4c) & 1) != 0) {

    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffffe;

    FUN_140030810(*(undefined8 *)(param_2 + 0xf8));

  }

  return;

}




