// Address: 0x14017a3a0
// Ghidra name: FUN_14017a3a0
// ============ 0x14017a3a0 FUN_14017a3a0 (size=37) ============


undefined * FUN_14017a3a0(int param_1)



{

  uint uVar1;

  

  uVar1 = param_1 >> 0x18 & 0xf;

  if ((uVar1 != 0) && (uVar1 != 1)) {

    if (uVar1 != 2) {

      return (undefined *)0x0;

    }

    return &DAT_1403360e0;

  }

  return &DAT_1403360a0;

}




