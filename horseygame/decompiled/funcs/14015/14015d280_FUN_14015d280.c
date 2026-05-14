// Address: 0x14015d280
// Ghidra name: FUN_14015d280
// ============ 0x14015d280 FUN_14015d280 (size=81) ============


undefined8 FUN_14015d280(longlong param_1)



{

  char cVar1;

  

  FUN_14015f420();

  cVar1 = FUN_14015ef90(param_1);

  while (cVar1 != '\0') {

    cVar1 = (**(code **)(param_1 + 0x18))(param_1);

    if (cVar1 == '\0') {

      FUN_14015d5d0(param_1);

    }

    cVar1 = FUN_14015ef90(param_1);

  }

  FUN_14015f430(param_1);

  return 0;

}




