// Address: 0x14021ee80
// Ghidra name: FUN_14021ee80
// ============ 0x14021ee80 FUN_14021ee80 (size=138) ============


void FUN_14021ee80(undefined8 *param_1)



{

  int iVar1;

  

  if (param_1 != (undefined8 *)0x0) {

    FUN_140179b40(*param_1);

    iVar1 = FUN_140138fe0(param_1 + 3);

    if (0 < iVar1) {

      FUN_140138fb0(param_1 + 3,0xffffffff);

      FUN_140160220(param_1[1]);

      FUN_140179b60(*param_1);

      return;

    }

    iVar1 = FUN_140138fe0((longlong)param_1 + 0x1c);

    if (0 < iVar1) {

      FUN_140138fb0((longlong)param_1 + 0x1c,0xffffffff);

      FUN_140179b60(*param_1);

    }

    FUN_140179b60(*param_1);

  }

  return;

}




