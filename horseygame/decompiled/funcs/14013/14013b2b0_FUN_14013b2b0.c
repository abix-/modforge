// Address: 0x14013b2b0
// Ghidra name: FUN_14013b2b0
// ============ 0x14013b2b0 FUN_14013b2b0 (size=46) ============


int FUN_14013b2b0(int param_1)



{

  uint uVar1;

  

  if (0 < param_1) {

    uVar1 = FUN_140138fb0(&DAT_1403fb698,param_1);

    if (uVar1 < 0x8000) {

      return uVar1 + 0x8000;

    }

  }

  return 0;

}




