// Address: 0x14019b200
// Ghidra name: FUN_14019b200
// ============ 0x14019b200 FUN_14019b200 (size=131) ============


undefined8 FUN_14019b200(longlong param_1,char param_2)



{

  char cVar1;

  undefined8 uVar2;

  

  uVar2 = 0;

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403141a4);

    return 0;

  }

  cVar1 = FUN_14019b180();

  if (cVar1 == '\0') {

    FUN_14012e850("File is not a PNG file");

  }

  else {

    uVar2 = FUN_14019b2c0(param_1);

  }

  if (param_2 != '\0') {

    FUN_14012bd50(param_1);

  }

  return uVar2;

}




