// Address: 0x14012dae0
// Ghidra name: FUN_14012dae0
// ============ 0x14012dae0 FUN_14012dae0 (size=193) ============


undefined4 FUN_14012dae0(char *param_1,undefined8 param_2,uint *param_3)



{

  int iVar1;

  uint uVar2;

  undefined **ppuVar3;

  

  iVar1 = FUN_140190340((int)*param_1);

  if (iVar1 != 0) {

    uVar2 = thunk_FUN_1402d89dc(param_1);

    *param_3 = uVar2;

    return 1;

  }

  if (*param_1 != '*') {

    uVar2 = 0;

    ppuVar3 = &PTR_DAT_140314210;

    do {

      iVar1 = FUN_14012f260(param_1,*ppuVar3,param_2);

      if (iVar1 == 0) {

        *param_3 = uVar2;

        return 1;

      }

      uVar2 = uVar2 + 1;

      ppuVar3 = ppuVar3 + 1;

    } while (uVar2 < 10);

    return 0;

  }

  *param_3 = 0xffffffff;

  return 1;

}




