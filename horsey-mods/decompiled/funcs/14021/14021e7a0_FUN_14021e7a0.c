// Address: 0x14021e7a0
// Ghidra name: FUN_14021e7a0
// ============ 0x14021e7a0 FUN_14021e7a0 (size=86) ============


bool FUN_14021e7a0(char *param_1)



{

  int iVar1;

  size_t sVar2;

  

  sVar2 = strlen(param_1);

  if (sVar2 < 4) {

    return false;

  }

  iVar1 = FUN_14012ef60(param_1 + (sVar2 - 4),&DAT_1403559cc);

  if (iVar1 != 0) {

    iVar1 = FUN_14012ef60(param_1 + (sVar2 - 4),&DAT_1403559d4);

    return iVar1 == 0;

  }

  return true;

}




