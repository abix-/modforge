// Address: 0x1402630c0
// Ghidra name: FUN_1402630c0
// ============ 0x1402630c0 FUN_1402630c0 (size=87) ============


int FUN_1402630c0(uint *param_1)



{

  uint uVar1;

  uint uVar2;

  

  uVar1 = *param_1;

  if (((uVar1 == 0) || ((uVar1 & 0xf0000000) == 0x10000000)) &&

     ((uVar2 = uVar1 & 0xf000000, uVar2 == 0x1000000 ||

      (((uVar2 == 0xc000000 || (uVar2 == 0x2000000)) || (uVar2 == 0x3000000)))))) {

    return -2;

  }

  if (uVar1 == 0x16372004) {

    return 1;

  }

  return (param_1[5] != 0) - 1;

}




