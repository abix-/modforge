// Address: 0x1402ff368
// Ghidra name: FUN_1402ff368
// ============ 0x1402ff368 FUN_1402ff368 (size=41) ============


void FUN_1402ff368(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {

    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;

    FUN_140030810(*(undefined8 *)(param_2 + 0xe8));

  }

  return;

}




