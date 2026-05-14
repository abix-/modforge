// Address: 0x1402e7db0
// Ghidra name: FUN_1402e7db0
// ============ 0x1402e7db0 FUN_1402e7db0 (size=36) ============


void FUN_1402e7db0(ulonglong param_1)



{

  byte bVar1;

  

  bVar1 = 0x40 - ((byte)DAT_1403e8b00 & 0x3f) & 0x3f;

  DAT_1403ff130 = (param_1 >> bVar1 | param_1 << 0x40 - bVar1) ^ DAT_1403e8b00;

  return;

}




