// Address: 0x140156820
// Ghidra name: FUN_140156820
// ============ 0x140156820 FUN_140156820 (size=59) ============


void FUN_140156820(longlong param_1)



{

  if (*(longlong *)(param_1 + 0x1f0) != 0) {

    *(float *)(param_1 + 0x218) =

         *(float *)(*(longlong *)(param_1 + 0x1f0) + 0x1c) * *(float *)(param_1 + 0x214);

    return;

  }

  *(float *)(param_1 + 0x218) = *(float *)(param_1 + 0x20c) * *(float *)(param_1 + 0x214);

  return;

}




