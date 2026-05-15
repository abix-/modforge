// Address: 0x1401553b0
// Ghidra name: FUN_1401553b0
// ============ 0x1401553b0 FUN_1401553b0 (size=155) ============


ulonglong FUN_1401553b0(longlong param_1,int param_2)



{

  longlong *plVar1;

  char cVar2;

  ulonglong uVar3;

  

  while (param_1 != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,3);

      if (cVar2 == '\0') break;

    }

    if (((param_2 != 0) && (param_2 != 1)) && (param_2 != 2)) {

      uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","scaleMode");

      return uVar3;

    }

    plVar1 = (longlong *)(param_1 + 0xf8);

    *(int *)(param_1 + 0x2c) = param_2;

    param_1 = *plVar1;

    if (*plVar1 == 0) {

      return 1;

    }

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","texture");

  return uVar3 & 0xffffffffffffff00;

}




