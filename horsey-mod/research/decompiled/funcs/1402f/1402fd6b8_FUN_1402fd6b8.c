// Address: 0x1402fd6b8
// Ghidra name: FUN_1402fd6b8
// ============ 0x1402fd6b8 FUN_1402fd6b8 (size=41) ============


void FUN_1402fd6b8(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {

    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;

    FUN_140030810(*(undefined8 *)(param_2 + 200));

  }

  return;

}




