// Address: 0x1402e8c00
// Ghidra name: FUN_1402e8c00
// ============ 0x1402e8c00 FUN_1402e8c00 (size=29) ============


uint FUN_1402e8c00(void)



{

  uint uVar1;

  

  uVar1 = MXCSR;

  MXCSR = MXCSR & 0xffffffc0;

  return uVar1 & 0x3f;

}




