// Address: 0x14015c250
// Ghidra name: FUN_14015c250
// ============ 0x14015c250 FUN_14015c250 (size=78) ============


uint FUN_14015c250(char param_1,char param_2)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = FUN_140138fb0(&DAT_1403fc198,1);

  uVar2 = 2;

  if (param_2 != '\0') {

    uVar2 = 0;

  }

  return iVar1 * 4 + 4U | (uint)(param_1 == '\0') | uVar2;

}




