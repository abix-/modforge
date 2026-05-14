// Address: 0x140163e10
// Ghidra name: FUN_140163e10
// ============ 0x140163e10 FUN_140163e10 (size=45) ============


int FUN_140163e10(uint param_1,int param_2,uint param_3,int param_4)



{

  uint uVar1;

  uint uVar2;

  

  uVar2 = param_3 >> 3 & 0x1f;

  uVar1 = param_1 >> 3 & 0x1f;

  if (uVar2 < uVar1) {

    uVar2 = uVar1;

  }

  uVar1 = 4;

  if (4 < uVar2) {

    uVar1 = uVar2;

  }

  if (param_4 < param_2) {

    param_4 = param_2;

  }

  return uVar1 * param_4;

}




