// Address: 0x1402ff838
// Ghidra name: FUN_1402ff838
// ============ 0x1402ff838 FUN_1402ff838 (size=47) ============


void FUN_1402ff838(undefined8 param_1,longlong param_2)



{

  if ((*(uint *)(param_2 + 0x210) & 1) != 0) {

    *(uint *)(param_2 + 0x210) = *(uint *)(param_2 + 0x210) & 0xfffffffe;

    FUN_140027900(param_2 + 0x148);

  }

  return;

}




