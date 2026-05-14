// Address: 0x14017a370
// Ghidra name: FUN_14017a370
// ============ 0x14017a370 FUN_14017a370 (size=37) ============


undefined * FUN_14017a370(int param_1)



{

  uint uVar1;

  

  uVar1 = param_1 >> 0x18 & 0xf;

  if ((uVar1 != 0) && (uVar1 != 1)) {

    if (uVar1 != 2) {

      return (undefined *)0x0;

    }

    return &DAT_1403361e0;

  }

  return &DAT_1403361a0;

}




