// Address: 0x14012e5e0
// Ghidra name: FUN_14012e5e0
// ============ 0x14012e5e0 FUN_14012e5e0 (size=154) ============


undefined8 FUN_14012e5e0(int param_1,char *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  if (6 < param_1 - 1U) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","priority");

    return uVar2;

  }

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    param_2 = "";

  }

  lVar1 = FUN_14012f0d0(param_2);

  if (lVar1 == 0) {

    return 0;

  }

  FUN_140179b40(DAT_1403fb518);

  if ((&DAT_1403fb580)[param_1] != 0) {

    FUN_1401841e0();

  }

  uVar2 = DAT_1403fb518;

  (&DAT_1403fb580)[param_1] = lVar1;

  FUN_140179b60(uVar2);

  return 1;

}




