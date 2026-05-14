// Address: 0x1402fc714
// Ghidra name: FUN_1402fc714
// ============ 0x1402fc714 FUN_1402fc714 (size=41) ============


void FUN_1402fc714(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x30) & 1) != 0) {

    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffe;

    FUN_140087f60(*(undefined8 *)(param_2 + 0x108));

  }

  return;

}




