// Address: 0x1402ff33f
// Ghidra name: FUN_1402ff33f
// ============ 0x1402ff33f FUN_1402ff33f (size=41) ============


void FUN_1402ff33f(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x34) & 1) != 0) {

    *(uint *)(param_2 + 0x34) = *(uint *)(param_2 + 0x34) & 0xfffffffe;

    FUN_140030810(*(undefined8 *)(param_2 + 0x88));

  }

  return;

}




