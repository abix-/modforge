// Address: 0x14013ddb0
// Ghidra name: FUN_14013ddb0
// ============ 0x14013ddb0 FUN_14013ddb0 (size=113) ============


uint FUN_14013ddb0(char *param_1)



{

  int iVar1;

  uint uVar2;

  undefined **ppuVar3;

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    if ((*param_1 - 0x2bU & 0xfd) == 0) {

      param_1 = param_1 + 1;

    }

    uVar2 = 0;

    ppuVar3 = &PTR_s_leftx_1403e1c60;

    do {

      iVar1 = FUN_14012ef60(param_1,*ppuVar3);

      if (iVar1 == 0) {

        return uVar2;

      }

      uVar2 = uVar2 + 1;

      ppuVar3 = ppuVar3 + 1;

    } while (uVar2 < 6);

  }

  return 0xffffffff;

}




