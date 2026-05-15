// Address: 0x14021ee30
// Ghidra name: FUN_14021ee30
// ============ 0x14021ee30 FUN_14021ee30 (size=77) ============


undefined4 FUN_14021ee30(undefined8 *param_1)



{

  char cVar1;

  int iVar2;

  

  if (param_1 == (undefined8 *)0x0) {

    return 1;

  }

  cVar1 = FUN_140179b50(*param_1);

  if (cVar1 != '\0') {

    iVar2 = FUN_140138fe0(param_1 + 3);

    if (iVar2 < 1) {

      FUN_140138fb0((longlong)param_1 + 0x1c,1);

      return 1;

    }

    FUN_140179b60(*param_1);

  }

  return 0;

}




