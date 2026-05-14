// Address: 0x14021ed80
// Ghidra name: FUN_14021ed80
// ============ 0x14021ed80 FUN_14021ed80 (size=98) ============


void FUN_14021ed80(undefined8 *param_1)



{

  int iVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    FUN_140179b40(*param_1);

    iVar1 = FUN_140138fe0(param_1 + 3);

    while (0 < iVar1) {

      FUN_140163d40(param_1[1],*param_1);

      iVar1 = FUN_140138fe0(param_1 + 3);

    }

    FUN_140138fb0((longlong)param_1 + 0x1c,1);

  }

  return;

}




