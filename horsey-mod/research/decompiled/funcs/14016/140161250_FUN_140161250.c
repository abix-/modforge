// Address: 0x140161250
// Ghidra name: FUN_140161250
// ============ 0x140161250 FUN_140161250 (size=42) ============


int FUN_140161250(int param_1)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  piVar2 = DAT_1403fc330;

  if (0 < DAT_1403fc328) {

    do {

      if (param_1 == *piVar2) {

        return iVar1;

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < DAT_1403fc328);

  }

  return -1;

}




