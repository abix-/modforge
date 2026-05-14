// Address: 0x140080b80
// Ghidra name: FUN_140080b80
// ============ 0x140080b80 FUN_140080b80 (size=47) ============


float FUN_140080b80(longlong param_1)



{

  if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x1c) == 1) {

    return DAT_14030374c * *(float *)(param_1 + 0xa8);

  }

  return DAT_14039ca44 * *(float *)(param_1 + 0xa8);

}




