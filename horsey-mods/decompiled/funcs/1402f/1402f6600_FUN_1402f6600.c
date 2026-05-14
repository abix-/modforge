// Address: 0x1402f6600
// Ghidra name: FUN_1402f6600
// ============ 0x1402f6600 FUN_1402f6600 (size=76) ============


undefined8 FUN_1402f6600(uint *param_1,uint param_2)



{

  uint uVar1;

  uint uVar2;

  

  if ((param_2 & 0x1f) == 0) {

    *param_1 = 0;

    return 0;

  }

  uVar1 = FUN_1402f67d0();

  uVar2 = FUN_1402f67c0(param_2 & 0x1f);

  *param_1 = uVar2 & uVar1;

  return 0;

}




