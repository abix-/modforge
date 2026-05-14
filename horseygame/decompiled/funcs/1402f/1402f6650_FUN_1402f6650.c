// Address: 0x1402f6650
// Ghidra name: FUN_1402f6650
// ============ 0x1402f6650 FUN_1402f6650 (size=126) ============


bool FUN_1402f6650(uint *param_1,uint param_2)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  

  if ((param_2 & 0x1f) != 0) {

    uVar1 = FUN_1402f67c0(param_2 & 0x1f);

    uVar2 = FUN_1402f67c0(0x3f);

    uVar4 = *param_1;

    uVar3 = FUN_1402f67d0();

    uVar1 = uVar3 & ~uVar1 | uVar2 & uVar4 & uVar1;

    FUN_1402f6960(uVar1);

    uVar1 = uVar1 & 0x1f;

    uVar4 = FUN_1402f8510(uVar1);

    return uVar4 != uVar1;

  }

  return false;

}




