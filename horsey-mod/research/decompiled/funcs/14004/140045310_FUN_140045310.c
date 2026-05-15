// Address: 0x140045310
// Ghidra name: FUN_140045310
// ============ 0x140045310 FUN_140045310 (size=62) ============


void FUN_140045310(float param_1)



{

  float fVar1;

  

  fVar1 = 0.0;

  if (0.0 <= param_1) {

    fVar1 = param_1;

  }

  *(float *)(DAT_1403ea2a8 + 0xc) = fVar1;

  if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

    *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) = fVar1;

  }

  if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

    *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) = fVar1;

  }

  return;

}




