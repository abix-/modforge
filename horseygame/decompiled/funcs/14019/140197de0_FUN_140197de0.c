// Address: 0x140197de0
// Ghidra name: FUN_140197de0
// ============ 0x140197de0 FUN_140197de0 (size=137) ============


undefined * FUN_140197de0(char *param_1,undefined1 *param_2)



{

  int iVar1;

  uint uVar2;

  undefined **ppuVar3;

  

  ppuVar3 = &PTR_DAT_14033aea0;

  uVar2 = 0;

  do {

    iVar1 = strcmp(param_1,*ppuVar3);

    if (iVar1 == 0) {

      *param_2 = (&DAT_14033aeb0)[(longlong)(int)uVar2 * 0x18];

      return (&PTR_DAT_14033aea8)[(longlong)(int)uVar2 * 3];

    }

    uVar2 = uVar2 + 1;

    ppuVar3 = ppuVar3 + 3;

  } while (uVar2 < 4);

  *param_2 = 0;

  return (undefined *)0x0;

}




