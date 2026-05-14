// Address: 0x14003f2c0
// Ghidra name: FUN_14003f2c0
// ============ 0x14003f2c0 FUN_14003f2c0 (size=95) ============


void FUN_14003f2c0(int param_1)



{

  float fVar1;

  

  if ((DAT_1403ea292 == '\0') && (DAT_1403ea293 != '\0')) {

    fVar1 = 0.0;

    if (0.0 <= (float)param_1 * DAT_14039ca0c) {

      fVar1 = (float)param_1 * DAT_14039ca0c;

    }

    *(float *)(DAT_1403ea2a8 + 0xc) = fVar1;

    if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

      *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) = fVar1;

    }

    if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

      *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) = fVar1;

    }

  }

  return;

}




