// Address: 0x14027b010
// Ghidra name: FUN_14027b010
// ============ 0x14027b010 FUN_14027b010 (size=105) ============


bool FUN_14027b010(undefined8 param_1,char param_2,char param_3)



{

  int iVar1;

  byte bVar2;

  uint uVar3;

  undefined2 local_18;

  undefined1 local_16;

  char local_15;

  undefined8 local_14;

  

  local_18 = 0;

  local_16 = 8;

  bVar2 = param_2 + 6;

  local_14 = 0;

  if (param_3 == '\0') {

    bVar2 = 0;

  }

  uVar3 = bVar2 / 7;

  local_15 = bVar2 + (char)((bVar2 - uVar3 >> 1) + uVar3 >> 3) * -0xe + '@';

  iVar1 = FUN_140195730(param_1,&local_18,0xc);

  return iVar1 == 0xc;

}




