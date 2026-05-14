// Address: 0x1402e8c20
// Ghidra name: FUN_1402e8c20
// ============ 0x1402e8c20 FUN_1402e8c20 (size=90) ============


uint FUN_1402e8c20(uint param_1,uint param_2)



{

  uint uVar1;

  

  uVar1 = MXCSR;

  MXCSR = (~param_2 | 0xffff807f) & MXCSR | param_1 & param_2;

  if ((DAT_1403e8e9c != '\0') && ((MXCSR & 0x40) != 0)) {

    return uVar1;

  }

  MXCSR = MXCSR & 0xffffffbf;

  return uVar1;

}




