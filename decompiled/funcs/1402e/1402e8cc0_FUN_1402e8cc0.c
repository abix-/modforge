// Address: 0x1402e8cc0
// Ghidra name: FUN_1402e8cc0
// ============ 0x1402e8cc0 FUN_1402e8cc0 (size=29) ============


void FUN_1402e8cc0(uint param_1)



{

  if ((param_1 & 0x3f) != 0) {

    MXCSR = MXCSR | param_1 & 0x3f;

  }

  return;

}




