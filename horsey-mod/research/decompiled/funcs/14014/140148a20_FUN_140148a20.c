// Address: 0x140148a20
// Ghidra name: FUN_140148a20
// ============ 0x140148a20 FUN_140148a20 (size=24) ============


void FUN_140148a20(uint *param_1)



{

  uint uVar1;

  

  uVar1 = *param_1;

  if (((uVar1 & 4) == 0) && ((param_1[0xc] & 4) == 0)) {

    *param_1 = uVar1 & 0xfffffffd;

    return;

  }

  *param_1 = uVar1 | 2;

  return;

}




