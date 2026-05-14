// Address: 0x140146e50
// Ghidra name: FUN_140146e50
// ============ 0x140146e50 FUN_140146e50 (size=153) ============


undefined8 FUN_140146e50(longlong param_1,char param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return 0;

  }

  cVar1 = FUN_1401873d0();

  if (cVar1 != '\0') {

    uVar2 = FUN_140187450(param_1,param_2);

    return uVar2;

  }

  cVar1 = FUN_14019b180(param_1);

  if (cVar1 != '\0') {

    uVar2 = FUN_14019b200(param_1,param_2);

    return uVar2;

  }

  if (param_2 != '\0') {

    FUN_14012bd50(param_1);

  }

  FUN_14012e850("Unsupported image format");

  return 0;

}




