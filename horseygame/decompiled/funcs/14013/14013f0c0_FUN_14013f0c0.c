// Address: 0x14013f0c0
// Ghidra name: FUN_14013f0c0
// ============ 0x14013f0c0 FUN_14013f0c0 (size=110) ============


uint FUN_14013f0c0(char *param_1)



{

  int iVar1;

  uint uVar2;

  undefined **ppuVar3;

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    if ((*param_1 - 0x2bU & 0xfd) == 0) {

      param_1 = param_1 + 1;

    }

    uVar2 = 0;

    ppuVar3 = &PTR_s_unknown_1403e1c00;

    do {

      iVar1 = FUN_14012ef60(param_1,*ppuVar3);

      if (iVar1 == 0) {

        return uVar2;

      }

      uVar2 = uVar2 + 1;

      ppuVar3 = ppuVar3 + 1;

    } while (uVar2 < 0xc);

  }

  return 0;

}




