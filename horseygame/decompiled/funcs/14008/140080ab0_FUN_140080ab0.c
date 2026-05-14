// Address: 0x140080ab0
// Ghidra name: FUN_140080ab0
// ============ 0x140080ab0 FUN_140080ab0 (size=65) ============


float FUN_140080ab0(longlong param_1)



{

  longlong lVar1;

  float fVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x80);

  fVar2 = DAT_14039ca44;

  if ((*(uint *)(lVar1 + 600) & 0x800000) == 0) {

    fVar2 = 0.0;

  }

  return *(float *)(lVar1 + 0x158) + *(float *)(lVar1 + 0x158) +

         *(float *)(lVar1 + 0x148) + *(float *)(lVar1 + 0x148) + fVar2;

}




