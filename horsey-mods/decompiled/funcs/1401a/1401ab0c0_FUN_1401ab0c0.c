// Address: 0x1401ab0c0
// Ghidra name: FUN_1401ab0c0
// ============ 0x1401ab0c0 FUN_1401ab0c0 (size=63) ============


uint FUN_1401ab0c0(undefined8 param_1,char *param_2)



{

  char cVar1;

  size_t sVar2;

  uint uVar3;

  

  uVar3 = 0x1505;

  for (sVar2 = strlen(param_2); sVar2 != 0; sVar2 = sVar2 - 1) {

    cVar1 = *param_2;

    param_2 = param_2 + 1;

    uVar3 = uVar3 * 0x21 ^ (int)cVar1;

  }

  return uVar3;

}




