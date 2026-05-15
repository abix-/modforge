// Address: 0x1402f67d0
// Ghidra name: FUN_1402f67d0
// ============ 0x1402f67d0 FUN_1402f67d0 (size=85) ============


uint FUN_1402f67d0(void)



{

  uint uVar1;

  

  uVar1 = (((MXCSR & 0x3f) >> 2 & 8 | MXCSR & 0x10) >> 2 | MXCSR & 8) >> 1 |

          ((MXCSR & 2) << 3 | MXCSR & 4) * 2 | (MXCSR & 1) << 4;

  return uVar1 << 0x18 | uVar1;

}




